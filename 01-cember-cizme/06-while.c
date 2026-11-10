#include "kutuphane.h"


void ciz(int x, int y)
{
	circle(x, y, 50, 120);
	circle(x, y, 40, 90);
}

int main(void)
{
	int a = 0;

	/* tek bir yerde... */
	while (a < WIDTH) {
		ciz(a, 320);
		a += 120;
	}
}
