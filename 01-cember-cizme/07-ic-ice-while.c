#include "kutuphane.h"


void ciz(int x, int y)
{
	circle(x, y, 50, 120);
	circle(x, y, 40, 90);
}

int main(void)
{
	int a = 0;
	int b = 0;

	while (b <= HEIGHT) {
		/* < yerine <= kullanıp sonu da dahil ettik */
		a = 0;
		while (a <= WIDTH) {
			ciz(a, b);
			a += 120;
		}
		b += 120;
	}
}
