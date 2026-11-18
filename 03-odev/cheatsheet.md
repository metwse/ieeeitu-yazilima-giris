00-02 arasındaki konuları özetlersek, değişkenlerle başlamıştık:

### Değişkenler ve Aritmetik

```c
/* int: tam sayı değişken */
int degisken_adi = 123;  /* değişkeni tanımlayıp bir değere atıyoruz */
int baska_degisken;  /* illa ilk tanımladığımız vakit atamak zorunda değiliz */

degisken_adi = 321; /* degerini degistiriyoruz*/
baska_degisken = -1;


/* double: tam sayıların yanısıra ondalık sayı da tutabilir */
double ondalik_degisken = 1.2;

ondalik_degisken = 3.5;
ondalik_degisken = 5;  /* yine de tam sayı tutuyor */
```

C'deki aritmetik, matematikten çok da farklı değil:

```c
int x = 1 + 2;

/* / bölme için */
x = x / 2;  /* not: int'lerle bölme işlemi yapınca aşağı yuvarlar */
/* = 3 / 2 = 1.5, ancak int içinde 1 kalır. */

/* * çarmpa için */
x = 1 * 3 - 4;

double y = 1.5;
y = y / 3;  /* bu sefer sonuç 0.5, yuvarlama yok */

/* toplama, çıkarma, çarpma, bölmenin yanısıra "bölümden kalan" işlemi
 * tanımlıdır: */

int k = 12;

k = k % 10;  /* k'yı, k'nın 10 ile bölümünden kalanına (yani 2'ye) eşitle */
```

| işlem | operatör |
|--|--|
| toplama/çıkarma | `+`/`-` |
| çarpma/bölme | `*`/`/` |
| bölümden kalan | `%` |

Koşullar içinse,

| koşul | operatör |
|--|--|
| eşittir | `==` |
| eşit değildir | `!=` |
| büyüktür/büyük eşittir | `>`/`>=` |
| küçüktür/küçük eşittir | `<`/`<=` |

Birden fazla koşul kontrolü için ve (ikisi de doğruysa, `&&`) ile veya
(ikisinden herhangi biri doğruysa, `||`) operatörleri kullanılabilir:

`x > 10 || x == 3` x 10'dan büyük veya 3'e eşit koşullarının herhangi birinin
doğru olması durumunu temsil eder.

Dikkat: Bir değişkeni atamak için `=` (tek eşittir) kullanıyoruz, eşitlik
durumunu kontrol etmek içinse `==`.

Son olarak, işlem önceliğini değiştirmek için yine matematikteki gibi parantez
kullanabiliriz.

`(3 + 6) / 3`, 3'e eşit. \
`3 + 6 / 3`, 5'e eşit.


### Koşullu İfadeler

Bir ifadenin doğruluk durumuna göre kod çalıştıran `if`, `else if` ve `else`

```c
if (/* koşul */) {
    /* koşul doğruysa burası çalışır*/
}
/* kalan kod, koşuldan bağımsız çalışır */
```

```c
if (/* koşul */) {
    /* koşul doğruysa burası çalışır*/
} else {
    /* koşul yanlışsa burası çalışır */
}
/* kalan kod, koşuldan bağımsız çalışır */
```

```c
if (/* 1. koşul */) {
    /* 1. koşul doğruysa burası çalışır*/
} else if (/* 2. koşul */) {
    /* 2. koşul doğruysa burası çalışır*/
} else if (/* 3. koşul */) {
    /* 3. koşul doğruysa burası çalışır*/

    /* daha da ilerletebiliriz*/
} /* buranın sonrasına yine de else gelebilir */
/* kalan kod, koşuldan bağımsız çalışır */
```

Daha somut bir örnek vermek gerekirse:

```c
int x = 10;

if (x > 10) {
    printf("x, 10'dan büyük!\n");
} else {
    printf("x, 10'a eşit ya da 10'dan küçük!\n");
}
```


### Döngüler

Belirli bir koşul sağlandıkça çalışan kodlar için `while` ve `for` kullanmıştık:

```c
while (/* koşul */) {
    /* koşul doğru olduğu sürece burası çalışır */
}
```

Yine somut bir örnek:

```c
int x = 0;

while (x < 10) {
    printf("x hâlâ 10'dan küçük\n");
    x = x + 1;
}
```

While'daki ayrı değişken tanımlama, koşul ve artış ifadelerini daha derli
yazmak için for kullandık:

```c
for (/* değişken tanımı ; koşul ; değişim */) {
    /* koşul sağlandıkça bu kod çalışır */
}
```

Bir önceki while örneğinin for'lu hâli,

```c
/*   tanım      koşul   değişim  */
for (int x = 0; x < 10; x = x + 1) {
    printf("x hâlâ 10'dan küçük\n");
}
```

Bu kodun 10 defa "x hâlâ 10'dan küçük" yazmasını bekleriz. x = 0'dan başlayarak
9'a kadar ilerler, her seferinde içindeki kod çalışır, sonrasında x = 10
yapılır ve içteki kod artık çıkar.


### Fonksiyonlar

Parametre alıp bir değer döndürebilen fonksiyonlardan bahsetmiştik. Değer
döndürmek opsiyoneldi,

```c
/* bu fonksiyon bir parametre alıp integer döner */
int ikiye_carp(int a)
{
    return a * 2;
}

/* iki değerden büyük olanı döner */
int buyuk_olan(int x, int y)
{
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

/* değer dönmeyen fonksiyonlarda void kullanırız */
void tek_mi_cift_mi(int k)
{
    if (k % 2 == 1) {
        printf("k tek\n");
    } else {
        printf("k çift\n");
    }
}
```


### Array'ler

Birden fazla değeri tutmak için array'lerden bahsetmiştik. Bu değişkenler,
matematikteki vektörlere benzer.

```c

int c[9];  /* 9 eleman boyutunda array */

c[0] = 1;  /* ilk eleman 0. index'te bulunur */
// ...
c[8] = 1;  /* ve son eleman 8. index'te bulunur */

/* array'in herhangi bir indexteki elemanına değişken yardımıya da erişebiliriz */
int i = 2;
c[i] = 3;  /* i. index'i (2. index, yani baştan 3. eleman) 3'e eşitle */

/* bu değişken yardımıyla farklı değerlere erişebilme döngülerde işimize epey
 * yarıyor, bir değişkende tuttuğumuz index sayesinde farklı slotlara
 * erişebiliyoruz */
for (int a = 0; a < 9; a++) {
    c[a] = 0;
}

```


### Döngü Detayları

Bu kısım daha fazla pratikle oturur. Referans olsun diye yazıyorum.

`break` kullanarak koşul hâlâ sağlanıyorken döngüyü bitirmiştik. While ve
for'da kullanabiliriz:

```c
int y = 0;

while (1 > 0) { /* bu koşul hep sağlanır */
    y = y + 1;

    if (y > 10) {
        /* break, alttaki printf satırını atlayarak döngüyü bitirir */
        break;
    }

    printf("y 10'dan küçük\n");
}

/* y = 10 olduğu zaman while'den if içindeki break çıkar  */
```

`continue` ile de döngünün bir sonraki adımına atlamıştık. Yine while ve
for'da kullanabiliriz:

```c
for (int x = 0; x < 10; x = x + 1) {
    if (x % 2 == 1) {
        /* x'in iki ile bölümünden kalan 1'e eşitse (x tek ise) döngünün
         * geri kalanı atlanır ve alttaki "x çift" yazdırılmaz */
        continue;
    }

    printf("x çift\n");
}
```
