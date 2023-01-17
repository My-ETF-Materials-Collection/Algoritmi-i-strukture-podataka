# Predavanje 2 - Analiza vremenske složenosti algoritama

## Uvod

- Analizom vremenske složenosti nekog algoritma određujemo trajanje algoritamskog procesa

- Analizom efikasnosti nekog algoritma, najčešće nas zanima u koju klasu stupnja rasta vremenske složenosti taj algoritam spada

- Ekvivalentni algoritmi su algoritmi koji su dozvoljeni za iste klase ulaznih objekata i koji imaju jednake rezultate za jednake ulazne objekte

- Primjer problema je dizajniranje algoritma za zbrajanje prvih n brojeva, a algoritmi koji se koriste su SUMA (for i=1 do n suma+=i) i SUMA-M(suma=n\*(n+1)/2), koji su ekvivalentni

- Glavna razlika između ovih algoritama je trajanje algoritamskog procesa, jer u prvom algoritmu for petlja se izvršava n puta, dok u drugom algoritmu se obavlja jedno zbrajanje, jedno množenje, i jedno dijeljenje.
