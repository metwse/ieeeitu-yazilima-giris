#include <stdio.h>


/* değişkeni üstte tanımlayarak bütün fonksiyonlar arasında paylaşabiliriz */
int c[9];


/* koordinat dönüşümü */
int f(int x, int y)
{
	return x + y * 3;
}

/* x, y koordinatını bir degere ata */
void set(int x, int y, int val)
{
	c[f(x, y)] = val;
}

/* x, y koordinatındaki değeri bul */
int get(int x, int y)
{
	return c[f(x, y)];
}

/* listeyi yazdır */
void print(void)
{
	for (int b = 0; b < 3; b++) {
		for (int a = 0; a < 3; a++) {
			if (get(a, b) == 0) {
				printf(" ");
			}
			if (get(a, b) == 1) {
				printf("x");
			}
			if (get(a, b) == 2) {
				printf("o");
			}
		}
		printf("\n");
	}
}


int main(void)
{
	for (int i = 0; i < 9; i++) {
		c[i] = 0;
	}

	while (1) {
		int x;
		int y;
		print();

		printf("x ve y koordinatları: ");
		scanf("%d %d", &x, &y);

		if (x > 2 || y > 2) {
			printf("çok büyük abi dur\n");
			return 1;
		}

		/* 0 -> 1 -> 2 -> 0... */
		int yeni_deger = (get(x, y) + 1) % 3;

		set(x, y, yeni_deger);
	}
}
