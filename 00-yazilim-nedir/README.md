# Yazılım Nedir?


<details>
<summary>Nedir abi?</summary>

Bilgisayara bir *işlemi*, *algoritmayı* tarif etmektir.

*"series of instructoins"*

Peki *bilgisayar nedir*?

[State machine](https://en.wikipedia.org/wiki/Finite-state_machine),
[pushdown automaton](https://en.wikipedia.org/wiki/Pushdown_automaton),
[Turing machine](https://en.wikipedia.org/wiki/Turing_machine),
[lambda calculus](https://en.wikipedia.org/wiki/Lambda_calculus)
teorisine çok fazla şey var. Özetlersek bir tür "gramer"e göre "durum" durum
değiştirip girdi/çıktı veren aygıt.

Gramerleri sadece bilgisayarlar mı kullanıyor?
</details>

<details>
<summary>Yumurta nasıl yapılır?</summary>

<details>
<summary>Malzeme + davranış</summary>
- `ingredient egg;`
- `ingredient water;`
- `ingredient salt;`
- `tool pot;`
- `tool timer;`
- `add_water();`
- `put_eggs();`
- `set_timer();`
- `wait(10 minutes);`
- `if (eggs are cracked)` yumurtalar küçükse önceden kırıabilirler
    - `hurry up! take them early`
- `wait(2 minutes);`
- `take_eggs();`
- `peel_eggs();`
- `add_salt();`

<details>
<summary>Gramer kullandık</summary>

Belirsiz bir gramer! `hurry up!` acele etme anlamına geliyor, ama ne kadar?
Acele kime göre neye göre?

Algoritmayı belirsiz bir şekilde ifade etmemeliyiz (yani genelde). Bunun için
"deterministik" gramerler kullanıyoruz, yazılım dilleri de aslında insan
dilleri gibi "gramer" olarak tanımlanıyor.

<details>
<summary>Gramer sınıfları</summary>

(Şimdilik) önemsiz detaylar:

Yazılım dilleri (genelde) "context free grammar" (CFG) ya da "context sensitive
grammar" (CSG) olarak ifade edilir. İnsan dilleri "unrestricted" denen, CFG ve
CSG'nin üst kümesinde bulunur.

Üstten alta gramer sınıfları:
- Unrestricted / Recursively enumerable (tip 0) ("her" algoritma")
- Context sensitive (tip 1)
- Context free (tip 2)
- Regular (tip 3)
- Non-recursive / finite (en kısıtlı)

Detayları derleyici tasarımı eğitiminde. Kökenleri dil bilime dayanan,
programlama dili teorisini daha yakından inceleyeceğiz.
</details>
</details>
</details>
</details>
