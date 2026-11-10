_default:
	@(echo 'Bir komut belirtin:')
	@(echo '	make derle - Kodları derler.')
	@(echo '	make temizle - Derlenmiş kodları temizler.')


CFLAGS := $(CFLAGS) -g3 -O0 -std=c99 -Wall -pedantic
LDFLAGS := -lX11


CIKTILAR = $(patsubst %.c,cikti/%.out,$(wildcard *.c))

cikti/obj/kutuphane.o: detay/kutuphane.c kutuphane.h | cikti/obj/
	$(CC) -c -o $@ $< $(CFLAGS)

.SECONDARY:
cikti/obj/%.o: %.c kutuphane.h | cikti/obj/
	$(CC) -c -o $@ $< $(CFLAGS)

cikti/%.out: cikti/obj/%.o cikti/obj/kutuphane.o | cikti//
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)


cikti%/:
	mkdir -p $@

derle: $(CIKTILAR)

temizle:
	$(RM) -r cikti/

.PHONY: temizle derle _default
