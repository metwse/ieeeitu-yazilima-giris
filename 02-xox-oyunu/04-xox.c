#include <stdio.h>


int c[9];


int f(int x, int y)
{
	return x + y * 3;
}

void set(int x, int y, int val)
{
	c[f(x, y)] = val;
}

int get(int x, int y)
{
	return c[f(x, y)];
}

void print(void)
{
	for (int b = 0; b < 3; b++) {
		for (int a = 0; a < 3; a++) {
			if (get(a, b) == 0) {
				printf(" ");
			}
			if (get(a, b) == 1) {
				printf("O");
			}
			if (get(a, b) == 2) {
				printf("X");
			}
		}
		printf("\n");
	}
}

/* kazananı yazdırır */
void kazanani_ilan_et(int sira)
{
	if (sira == 1) {
		printf("Kazanan O!\n");
	}
	if (sira == 2) {
		printf("Kazanan X!\n");
	}
}

/* bir kazanan var mı? varsa yaz ve 1 dön, yoksa 0 dön */
int kazanan_kontrol(void)
{
	/* O = 1 ve X = 2 için kazanma kontrolü */
	for (int sira = 1; sira <= 2; sira++) {

		/* x koordinatı 0, 1, 2 olan düşey kısım */
		for (int a = 0; a < 3; a++) {
			int dusey = 0;

			/* y koordinatı 0, 1, 2 */
			for (int b = 0; b < 3; b++) {
				if (get(a, b) == sira) {
					dusey++;
				}
			}

			/* y'dekilerin üçü de 'sira' ise */
			if (dusey == 3) {
				kazanani_ilan_et(sira);
				return 1;
			}
		}

		/* aynısı, ama ters koordinatlarla. satır satır kontrol */
		for (int b = 0; b < 3; b++) {
			int yatay = 0;

			for (int a = 0; a < 3; a++) {
				if (get(a, b) == sira) {
					yatay++;
				}
			}

			if (yatay == 3) {
				kazanani_ilan_et(sira);
				return 1;
			}
		}

		/* çaprazlar manuel */
		if (get(0, 0) == sira && get(1, 1) == sira && get(2, 2) == sira) {
			kazanani_ilan_et(sira);
			return 1;
		}
		if (get(0, 2) == sira && get(1, 1) == sira && get(2, 0) == sira) {
			kazanani_ilan_et(sira);
			return 1;
		}
	}

	return 0;
}


int main(void)
{
	for (int i = 0; i < 9; i++) {
		c[i] = 0;
	}

	/* 1 = O'da, 2 = X'te */
	int sira = 1;
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

		if (get(x, y) != 0) {
			/* continue: döngünün devamını atlayarak başa dön */
			printf("dolu dolu\n");
			continue;
		}

		set(x, y, sira);
		/* 1 -> 2, 2 -> 1 */
		sira = 3 - sira;

		int kazanan_var_mi = kazanan_kontrol();

		if (kazanan_var_mi == 1) {
			/* break: döngüyü kır */
			break;
		}
	}
}
