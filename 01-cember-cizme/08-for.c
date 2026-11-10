#include "kutuphane.h"


void ciz(int x, int y)
{
	circle(x, y, 50, 120);
	circle(x, y, 40, 90);
}

int main(void)
{
	/* Değişken tanımı / koşul / artış tek bir yerde! */
	for (int b = 0; b <= HEIGHT; b += 120) {
		for (int a = 0; a <= WIDTH; a += 120) {
			ciz(a, b);
		}
	}
}
