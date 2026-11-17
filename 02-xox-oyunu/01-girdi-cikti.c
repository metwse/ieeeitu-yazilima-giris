#include <stdio.h>


int main(void)
{
	int width = 20;
	int height = 10;

	int x;
	int y;

	printf("x ve y koordinatları: ");
	/* scanf ve %d'yi de sorgulamamanızı istiyorum */
	scanf("%d %d", &x, &y);

	/* scanf ile kullanıcıdan girdi alabiliyoruz.
	 *
	 * değişken sayımı kadar %d koyup sonrasında &degisken_ismi şeklinde
	 * bir kullanımı var:
	 *
	 * scanf("%d", &bir_degisken);
	 * scanf("%d %d", &bir, &ikinci_degisken); */

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
