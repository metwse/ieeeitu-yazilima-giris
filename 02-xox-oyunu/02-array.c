#include <stdio.h>


int main(void)
{
	/* 3x3'lük bir alanı ifade etmeye çalışalım
	 * koordinat düzlemimizde toplam 9 adet kare mevcut oluyor */

	/* 9 tane değişken tanımlayacak değiliz! */
	int c_0_0;
	int c_1_0;
	int c_2_0;
	int c_0_1;
	// ..

	/* array'lerle tanışın: */
	int c[9];  // 9 tam sayının bulunduğu bir liste!

	/* 2 boyutlu işlem yapmak için, her bir array elemanına atama yapsak...
	 *
	 * C'de doğal sayılar 0'dan başlıyor. array'in ilk elemani c[0], son
	 * (9.) elemanı c[8] ile ifade ediliyor.
	 *
	 * her bir x, y değeri için şu atamayı yapmamızda sakınca yoktur:
	 *
	 * x | y | karşılık array elemanı
	 * ------------
	 * 0 - 0 - c[0]
	 * 1 - 0 - c[1]
	 * 2 - 0 - c[2]
	 * ------------
	 * 0 - 1 - c[3]
	 * 1 - 1 - c[4]
	 * 2 - 1 - c[5]
	 * ------------
	 * 0 - 2 - c[6]
	 * 1 - 2 - c[7]
	 * 2 - 2 - c[8]
	 *
	 * örüntüyü fark ettiniz mi? (a, b) konumunu listede
	 *     f(a, b) = a + b * 3
	 * şeklinde ifade edebiliriz. */

	/* önceki girdi/çıktı kodumuzdan, */
	int x;
	int y;
	printf("x ve y koordinatları: ");
	scanf("%d %d", &x, &y);

	if (x > 2 || y > 2) {
		printf("çok büyük abi dur\n");
		return 1;
	}

	/* önce c[9] listesini 0'la dolduralım. */
	for (int i = 0; i < 9; i++) {
		c[i] = 0;
	}

	/* bir koordinat ayarlamak: */
	for (int b = 0; b < 3; b++) {
		for (int a = 0; a < 3; a++) {
			/* f(a, b) = a + b * 3 */
			if (x == a && y == b) {
				c[a + b * 3] = 1;
			}
		}
	}

	/* listeyi yazdırmak */
	for (int b = 0; b < 3; b++) {
		for (int a = 0; a < 3; a++) {
			if (c[a + b * 3] == 1) {
				printf("*");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
}
