#include "kutuphane.h"


void ciz(int x, int y, int r)
{
	circle(x, y, r, 120);
	circle(x, y, r - 10, 90);
}

int main(void)
{
	double a = 100;
	double b = 100;

	double yatay_hiz = 200;
	double dusey_hiz = 40;

	double dusey_ivme = 100;

	double dt = 0.003;

	while (!quit) {
		/* zaman * hız = konumdaki yer değiştirme */
		a += yatay_hiz * dt;
		b += dusey_hiz * dt;

		/* zaman * ivme = hız değişimi */
		dusey_hiz += dusey_ivme * dt;

		if (a + 50 >= WIDTH) {
			yatay_hiz = -fabs(yatay_hiz);
		}
		if (b + 50 >= HEIGHT) {
			dusey_hiz = -fabs(dusey_hiz);
		}
		if (a <= 50) {
			yatay_hiz = fabs(yatay_hiz);
		}
		if (b <= 50) {
			dusey_hiz = fabs(dusey_hiz);
		}

		clear();
		ciz(a, b, 50);

		sleepf(dt);
	}
}
