#include "kutuphane.h"


void ciz(int x, int y, int r)
{
	circle(x, y, r, 120);
	circle(x, y, r - 10, 90);
}

int main(void)
{
	/* konumu a ve b değişkenlerinde tutalım */
	int a = 100;
	int b = 100;

	int yatay_hiz = 1;
	int dusey_hiz = 1;

	while (!quit) {
		/* her döngüde konumu güncelliyoruz hız kadar */
		a += yatay_hiz;
		b += dusey_hiz;

		/* a ve b'nin sınırlarımızdan çıkmadığından emin olalım */
		if (a + 50 >= WIDTH) {
			yatay_hiz = -1;
		}
		if (b + 50 >= HEIGHT) {
			dusey_hiz = -1;
		}
		if (a <= 50) {
			yatay_hiz = 1;
		}
		if (b <= 50) {
			dusey_hiz = 1;
		}

		/* silip her şeyi tekrar çizelim */
		clear();
		ciz(a, b, 50);

		sleepf(0.003);
	}
}
