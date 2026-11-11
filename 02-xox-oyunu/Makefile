_default:
	@(echo 'Bir komut belirtin:')
	@(echo '	make derle - Kodları derler.')
	@(echo '	make temizle - Derlenmiş kodları temizler.')


CFLAGS := $(CFLAGS) -g3 -O0 -std=c99 -Wall -pedantic


CIKTILAR = $(patsubst %.c,cikti/%.out,$(wildcard *.c))

.SECONDARY:
cikti/obj/%.o: %.c | cikti/obj/
	$(CC) -c -o $@ $< $(CFLAGS)

cikti/%.out: cikti/obj/%.o | cikti//
	$(CC) -o $@ $^ $(CFLAGS)


cikti%/:
	mkdir -p $@

derle: $(CIKTILAR)

temizle:
	$(RM) -r cikti/

.PHONY: temizle derle _default
