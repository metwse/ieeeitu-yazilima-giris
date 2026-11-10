#include "kutuphane.h"


void ciz(int x, int y)
{
	circle(x, y, 50, 120);
	circle(x, y, 40, 90);  /* tek bir yerden kontrol ediyoruz! */
}

int main(void)
{
	int a = 0;

	ciz(a, 320);
	a += 120;

	ciz(a, 320);
	a += 120;

	ciz(a, 320);
	a += 120;

	ciz(a, 320);
	a += 120;

	ciz(a, 320);
	a += 120;

	ciz(a, 320);
	a += 120;

	ciz(a, 320);
	a += 120;

	ciz(a, 320);
	a += 120;

	ciz(a, 320);
	a += 120;

	ciz(a, 320);
	a += 120;
}
