#ifndef KUTUPHANE_H
#define KUTUPHANE_H

#include <stdbool.h>
#include <math.h>  // IWYU pragma: export

#define WIDTH 960
#define HEIGHT 640


extern bool quit;


void circle(int x, int y, int r, unsigned char color);

void clear(void);

void sleepf(double secs);

int main(void);


#endif
