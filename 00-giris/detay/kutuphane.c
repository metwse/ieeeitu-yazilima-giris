#include "../kutuphane.h"

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <pthread.h>

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>


static Display *dpy;
static Screen *scr;
static Window w;

Atom wm_delete_win;

/* Klavyedeki ESC tuşuyla ve titlebar'daki çarpı butonuyla uygulamayı kapatmak
 * için. */
static void *ev_loop_handler(void *unused)
{
	bool quit = false;
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
	wm_delete_win = XInternAtom(dpy, "WM_DELETE_WINDOW", False);

	XSetWMProtocols(dpy, w, &wm_delete_win, 1);
	XSelectInput(dpy, w, StructureNotifyMask | KeyPressMask | ExposureMask);

	while (true) {
		XEvent ev;
		XNextEvent(dpy, &ev);

		if (ev.type == MapNotify)
			break;
	}
	pthread_t ev_loop;
	pthread_create(&ev_loop, NULL, ev_loop_handler, NULL);

	return ev_loop;
}

/* Pencere stil ve boyut ayarları. */
static void init_window(void)
{
	Window root = XRootWindowOfScreen(scr);

	int x = XWidthOfScreen(scr) / 2 - WIDTH / 2;
	int y = XHeightOfScreen(scr) / 2 - HEIGHT / 2;

	Colormap border_color = XBlackPixelOfScreen(scr);
	Colormap background_color = XWhitePixelOfScreen(scr);

	w = XCreateSimpleWindow(dpy, root, x, y, WIDTH, HEIGHT, 1,
				border_color, background_color);

	XSetNormalHints(dpy, w, &(XSizeHints) {
				.flags = PMinSize | PMaxSize,
				.min_width = WIDTH, .min_height = HEIGHT,
				.max_width = WIDTH, .max_height = HEIGHT,
			});

	XMapWindow(dpy, w);
}

int main(void)
{
	assert((dpy = XOpenDisplay(NULL)));
	scr = XDefaultScreenOfDisplay(dpy);

	init_window();

	pthread_t ev_loop = ev_init();

	baslangic();

	pthread_join(ev_loop, NULL);

	XCloseDisplay(dpy);
}
