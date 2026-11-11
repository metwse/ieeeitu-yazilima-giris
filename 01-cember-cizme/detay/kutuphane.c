#define _GNU_SOURCE

#include "../kutuphane.h"

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <pthread.h>
#include <unistd.h>

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


bool quit = false;


static Display *dpy;
static Screen *scr;
static Window w;


/* --- genel pencere ayarları --- */

/* Klavyedeki ESC tuşuyla ve titlebar'daki çarpı butonuyla uygulamayı kapatmak
 * için. */
static void *ev_loop_handler(void *unused)
{
	Atom wm_delete_win = XInternAtom(dpy, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(dpy, w, &wm_delete_win, 1);

	XSelectInput(dpy, w, KeyPressMask);

	while (!quit) {
		XEvent ev;
		XNextEvent(dpy, &ev);

		switch (ev.type) {
		case KeyPress:
			if (ev.xkey.keycode == 9) {
				fprintf(stderr, "Exitting due to ESC key.\n");
				quit = true;
			}
			break;

		case ClientMessage:
			if (ev.xclient.data.l[0] == wm_delete_win) {
				fprintf(stderr, "Window is closed!");
				quit = true;
			}
			break;
		}
	}

	return unused;
}

/* Dinlenecek X11 event'lerini ayarlayıp Map event'ini bekler. */
static pthread_t ev_init(void)
{
	pthread_t ev_loop;
	pthread_create(&ev_loop, NULL, ev_loop_handler, NULL);

	return ev_loop;
}

/* Pencere stil ve boyut ayarları. */
static void init_window(const char *wid)
{
	bool default_root = true;
	Window root = XRootWindowOfScreen(scr);

	/* Window ID verilmişse onun içinde aç. */
	if (wid != NULL) {
		default_root = false;
		root = strtol(wid, NULL, 0);
	}

	int x = XWidthOfScreen(scr) / 2 - WIDTH / 2;
	int y = XHeightOfScreen(scr) / 2 - HEIGHT / 2;

	Colormap border_color = XBlackPixelOfScreen(scr);
	Colormap background_color = XWhitePixelOfScreen(scr);

	w = XCreateSimpleWindow(dpy, root, x, y, WIDTH, HEIGHT, 1,
				border_color, background_color);

	if (default_root) {
		XSetNormalHints(dpy, w, &(XSizeHints) {
					.flags = PMinSize | PMaxSize,
					.min_width = WIDTH, .min_height = HEIGHT,
					.max_width = WIDTH, .max_height = HEIGHT,
				});
	}

	XMapWindow(dpy, w);
}


/* --- graphics context --- */

static GC gc;

/* Graphics context hazırlanması. */
static void init_gc(void)
{
	gc = XDefaultGCOfScreen(scr);
}

void circle(int x, int y, int r, unsigned char color)
{
	XSetFillStyle(dpy, gc, FillSolid);
	XSetForeground(dpy, gc, color * 0x010101);
	XFillArc(dpy, w, gc, x - r, y - r, r * 2, r * 2, 0, 360 * 64);
	XFlush(dpy);
}

void clear(void)
{
	XClearWindow(dpy, w);
}


/* --- extra --- */

void sleepf(double secs)
{
	usleep(secs * 1000000);
}


/* --- library init/deinit --- */

static pthread_t ev_loop;

__attribute__((constructor))
static void init_lib(int argc, char *argv[])
{
	XInitThreads();
	assert((dpy = XOpenDisplay(NULL)));
	scr = XDefaultScreenOfDisplay(dpy);

	init_window(argc == 2 ? argv[1] : NULL);
	init_gc();

	ev_loop = ev_init();
}

__attribute__((destructor))
static void destroy_lib(void)
{
	pthread_join(ev_loop, NULL);

	XCloseDisplay(dpy);
}
