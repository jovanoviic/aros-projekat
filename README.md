
# Hranjenje Divljaka - README

Ovaj repozitorijum sadrži implementaciju problema hranjenja divljaka, gde kuvar priprema hranu koju divljaci konzumiraju. Ovaj problem je rešen korišćenjem niti, semafora i mutexa u programskom jeziku C.

## Struktura Repozitorijuma

- `savage.c`: Izvorni kod koji sadrži implementaciju problema.
- `Makefile`: Skripta za kompajliranje izvornog koda.
- `README.md`: Ovaj dokument koji pruža osnovne informacije o repozitorijumu.

## Kompajliranje

Za kompajliranje koda, koristite priloženi `Makefile`. Komanda za kompajliranje može izgledati ovako:

```bash
make
```

Ova komanda koristi `gcc` sa opcijom `-pthread` za podršku niti.

## Pokretanje Programa

Nakon uspešnog kompajliranja, možete pokrenuti program koristeći izlaznu izvršnu datoteku (`rez.out`). Na primer:

```bash
./rez.out
```

## Dodatne Napomene

- Ukoliko želite da prilagodite broj divljaka, obroka ili druge parametre, to možete uraditi direktno u izvornom kodu `savage.c`.

---
