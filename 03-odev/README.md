00-02 partları arasındaki konuların kısa özeti icin
[cheatsheet](./cheatsheet.md)'e bakabilirsiniz.


**q1.** Aşağıdaki deseni nasıl çizeriz?
```
***
**
**
**
***
```

<details>
<summary>Çözüm</summary>

i satır numaramızı temsil etsin ve 1'den başlasın. 1, 2, 3, 4 ve 5 değerlerini
alarak satırları tek tek çizdirsin.

```c
#include <stdio.h>


int main(void)
{
    int i = 1;

    while (i <= 5) {
        if (i == 1 || i == 5) {
            printf("***\n");
        } else {
            printf("**\n");
        }

        i = i + 1;
    }
}
```

- Bu çözüm while kullanıyor. `for` ile nasıl yapardık?
- i'yi hep 0'dan başlatarak döngü yapıyorduk, herhangi bir değerden
  başlatabiliyoruz gördüğünüz gibi. Yine 0'dan başlasaydı nasıl olurdu?
</details>


**q2.** Aşağıdaki deseni nasıl çizeriz?
```
*
**
***
****
*****
```

<details>
<summary>Çözüm</summary>

Yine i satır numaramızı temsil etsin ve 0'den başlasın. 1, 2, 3, 4 ve 5
değerlerini alarak satırları tek tek çizdirsin.

```c
#include <stdio.h>


int main(void)
{
    int i = 1;

    while (i <= 5) {
        int j = 0;
        while (j < i) {
            printf("*");
            j = j + 1;
        }

        printf("\n");

        i = i + 1;
    }
}
```

- İç içe `while` yerine `for` kullansaydık nasıl olurdu?
- Yine i, 1'den başlıyor. Bunu 0'a çeksek nasıl olurdu?
</details>


**q3.** Kullanıcıdak iki sayı sorup büyük olan sayıyı söyleyen programı
nasıl yazarsınız?
```
iki sayı yazınız: ... kullanıcı sayıyı yazar
ilk sayı daha büyük!
```

<details>
<summary>Çözüm</summary>

```c
#include <stdio.h>


int main(void)
{
    int a;
    int b;

    printf("iki sayı yazınız: ");
    scanf("%d %d", &a, &b);

    int aradaki_fark = a - b;

    if (aradaki_fark > 0) {
        printf("ilk sayı daha büyük!\n");
    } else if (aradaki_fark == 0) {
        printf("iki sayı da eşit!\n");
    } else {
        printf("ikinci sayı daha büyük!\n");
    }
}
```

- Gıcıklık değil mi abi a > b vs. yerine değişik bir şey yaptım. Bunun yerine
  "daha normal" bir çözüm, sayıların büyüklük, küçüklük ilişkisine
  `if`/`else if` içinde baksaydık nasıl olurdu?
</details>


**q4.** İki sayı alıp o ölçülerde dörtgen çizen programı nasıl yazarsınız?
```
iki sayı yazınız: ... kullanıcı sayıyı yazar, genişlik - yükseklik
#####
#####
#####
```

<details>
<summary>Çözüm</summary>

```c
#include <stdio.h>


int main(void)
{
    int genislik;
    int yukseklik;

    while (1 > 0) { /* sonsuz döngü */
        printf("iki sayı yazınız: ");
        scanf("%d %d", &genislik, &yukseklik);

        if (genislik < 10 && yukseklik < 10) {
            break; /* uygun genişlik ve yükseklik verilmişe program devam eder */
        }
        printf("çok büyük! tekrar yazacaksınız.\n");
    }

    for (int y = 0; y < yukseklik; y = y + 1) {
        for (int x = 0; x < genislik; x = x + 1) {
            printf("#");
        }

        printf("\n");
    }
}
```

- Genişlik ve yüksekliğin büyük olması durumunda döngüyle tekrar soruyoruz.
  Peki 0'a eşit veya daha küçük olması durumunu da benzer şekilde ele almak
  istesek nasıl yapardık?

Not: Ve (`&&`) operatörünün işlem önceliği veya (`||`) operatöründen daha
yüksektir. Yazacağınız koda göre parantez kullanmanız gerekebilir
</details>
