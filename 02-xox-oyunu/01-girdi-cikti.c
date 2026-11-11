#include <stdio.h>


int main(void)
{
	int width = 20;
	int height = 10;

	int x;
	int y;

	printf("x ve y koordinatları: ");
	scanf("%d %d", &x, &y);

	/* koordinat düzleminde 0, 0'dan başlayıp 19, 9'a kadar gidelim
	 * mesela */

	/* dıştaki for = tekrar tekrar satır yazdık */
	for (int b = 0; b < height; b++) {

		/* içteki for = bir adet satır yazdık */
		for (int a = 0; a < width; a++) {
			if (x == a && y == b) {
				printf("*");
			} else {
				printf(".");
			}
		}

		printf("\n");
	}
}
