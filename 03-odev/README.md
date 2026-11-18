00-02 partları arasındaki konuların kısa özeti için
[cheatsheet](./cheatsheet.md)'e bakabilirsiniz.

<hr />

### q1 Aşağıdaki deseni nasıl çizersiniz?

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

<hr />

### q2 Aşağıdaki üçgeni nasıl çizersiniz?

```
*
**
***
****
*****
```

<details>
<summary>Çözüm</summary>

Yine i satır numaramızı temsil etsin ve 1'den başlasın. 1, 2, 3, 4 ve 5
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

<hr />

### q3 İki sayı sorup büyük olan sayıyı söyleyen programı nasıl yazarsınız?

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

<hr />

### q4 İki sayı alıp o ölçülerde dörtgen çizen programı nasıl yazarsınız?

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

<hr />

Şimdiye kadar `scanf("%d", &degisken_adi)` kullanarak hep *integer* değişkene
okuma yaptık. Benzer bir şekilde, `printf("%d", degisken_adi)` ile *integer*
değişkeni yazdırabiliyoruz. Üstelik printf'te değişkenle birlikte başka şeyler
de yazdırabiliriz:

```c
int x = 2;
x = x * 3;

printf("x * 3 ifadesinin sonucu %d sayısına eşittir\n", x);

/* birkaç ufak fark var:
 * - & kullanmadık
 * - metin de yazabiliyoruz. scanf'te sadece %d yazmıştık */
```

Yine birden fazla sayıyı birden fazla `%d` ile yazabiliriz:

```c
printf("x, y koordinatları: (%d, %d)\n", x, y);
```

<hr />

### q6 Aşağıdaki kodun çıktısı nedir?

```c
#include <stdio.h>


int main(void)
{
    int a = 5;
    int b = 10;
    int c = 15;
    int d = 20;

    a = a * 2;
    b = b + a;
    c = c + b - 5;
    d = d * 2;

    printf("%d - %d - %d - %d\n", a, b, c, d);
}
```


<details>
<summary>Çözüm</summary>

`10 - 20 - 30 - 40`

- Bu atama işlemleri satır satır ilerliyor. İlk işlemle a'yı iki katına
  eşitliyoruz, sonraki işlemde b'nin üzerine 5 * 2'yi ekliyoruz.
</details>

<hr />

### q7 Aşağıdaki kodun çıktısı nedir?

```c
#include <stdio.h>


int main(void)
{
    int arr[4];  /* 4 eleman tutacak bir array */

    /* arr'daki elemanların ilk değerini atıyoruz */
    arr[0] = 5;
    arr[1] = 10;
    arr[2] = 15;
    arr[3] = 20;

    arr[0] = arr[0] * 2;
    arr[1] = arr[1] + arr[0];
    arr[2] = arr[2] + arr[1] - 5;
    arr[3] = arr[3] * 2;

    printf("%d - %d - %d - %d\n", arr[0], arr[1], arr[2], arr[3]);
}
```

Hatırlatma: Array'lerde index 0'dan başlar.

<details>
<summary>Çözüm</summary>

`10 - 20 - 30 - 40`

- Aslında bu bir önceki kodun aynısı. 4 ayrı değişken yerine tek array içinde
  a, b, c ve d'yi tutmuş gibi olduk.
</details>

<hr />

### Foreshadowing: q8 Pointer'lar, bu kod ne yapar?

```c
#include <stdio.h>


int main(void) {
    int arr[4];

    arr[0] = 5;
    arr[1] = 10;
    arr[2] = 15;
    arr[3] = 20;

    int *ptr = arr;

    *ptr = *ptr * 2;
    *(ptr + 1) = *(ptr + 1) + *ptr;
    *(ptr + 2) = *(ptr + 2) + *(ptr + 1) - 5;
    *(ptr + 3) = *(ptr + 3) * 2;

    printf("%d - %d - %d - %d\n", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3));
}
```

Bir sonraki dersimizde *pointer*'larla ilgileneceğiz. Peki pointer nedir?
Pointer verinin kendisini değil, o verinin "bellekteki adresini" tutmaya
yarayan değişkendir.

Pekin neden pointer? Fonksiyona bir değişken verdiğinde C onun kopyasını
oluşturur. Fonksiyon bu kopya üzerinde ne yaparsa yapsın senin asıl değişkenin
değişmez. Orijinal değişkeni değiştirmek istiyorsak fonksiyona kopya değil,
değişkenin "adresini" yani pointer veririz. Fonksiyon da doğrudan adrese gidip
aslını değiştirir.

#### Adres Alıcı Operatör, `&`

"Bu değişkenin bellek adresi nedir?"

Bir değişkenin başına `&` koyduğunda, o değişkenin saklandığı bellek adresini
elde edersin.

- `degisken` - Değişkenin içindeki değerdir
- `&degisken` - Değişkenin bellek adresidir

Aslında biz scanf'e `&degisken` ile parametre verdiğimizde ona değeri oku
ve "git şu değişkene" yaz diyorduk! Bu sayede fonksiyona verdiğimiz
parametreyle dönüt aldık.

#### Dereference Operatörü, `*`

1. Yanındaki değişkenin bir pointer olduğunu belirtir

```c
int *ptr = dizi;
```

2. Pointer'ın tuttuğu adrese gidip oradaki kapıyı açar
```c
*ptr = *ptr * 2;
```

Bunu başta çarpma işlemiyle karıştırabilirsiniz. Zamanla mantığı oturacaktır,
daha detaylı da işleyeceğiz.

Cevaba gelecek olursak, yine `10 - 20 - 30 - 40`.
