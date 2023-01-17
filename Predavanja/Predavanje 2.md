# Predavanje 2 - Analiza vremenske složenosti algoritama

## Uvod

- Analizom vremenske složenosti nekog algoritma određujemo trajanje algoritamskog procesa

- Analizom efikasnosti nekog algoritma, najčešće nas zanima u koju klasu stupnja rasta vremenske složenosti taj algoritam spada

- Ekvivalentni algoritmi su algoritmi koji su dozvoljeni za iste klase ulaznih objekata i koji imaju jednake rezultate za jednake ulazne objekte

- Primjer problema je dizajniranje algoritma za zbrajanje prvih n brojeva, a algoritmi koji se koriste su SUMA (for i=1 do n suma+=i) i SUMA-M(suma=n\*(n+1)/2), koji su ekvivalentni

- Glavna razlika između ovih algoritama je trajanje algoritamskog procesa, jer u prvom algoritmu for petlja se izvršava n puta, dok u drugom algoritmu se obavlja jedno zbrajanje, jedno množenje, i jedno dijeljenje.

- Pitanje da li je vrijeme ključni kriterij uz današnju tehnološku platformu je potvrdno, jer iako se većina implementacija aplikacija temelji na brzoj hardverskoj platformi, grafičkom korisničkom sučelju, umrežavanju, itd., bitni sastavni elementi većine aplikacija su različiti algoritamski sadržaji.

- Dizajn i implementacija bilo kojeg grafičkog sučelja se temelji na algoritmima, rutiranje u računarskim mrežama se temelji na algoritmima, a aplikacije su pisane u nekom od programskih jezika, što znači da se koristi kompajler, interpreter ili možda asembler, koji se u velikoj mjeri temelje na algoritmima.

- Algoritmi su jezgra većine tehnologija korištenih u današnjim računarima i konstantnim napredovanjem tih tehnologija se rješavaju problemi sa sve većim veličinama ulaza, a efikasnost postaje izuzetno važna upravo za velike veličine ulaza. Iako je sa današnjom tehnologijom moguće obaviti veliki spektar zadataka bez poznavanja algoritama i struktura podataka, za razvoj kvalitetnih aplikacija neophodno je poznavanje algoritama i struktura podataka.

- Težine algoritma se određuju analizom vremenske složenosti, odnosno izračunom broja elementarnih operacija T(n) potrebnih za izvođenje algoritma u zavisnosti od veličine ulaza. Koncept veličine ulaza se razlikuje od problema do problema.

- Izraz T(n) = an^2+bn+c, koji se dobija kao rezultat analize efikasnosti nekog algoritma, predstavlja broj elementarnih operacija koje algoritam treba izvesti za ulaz veličine n. Konstanta a označava koeficijent koji stoji uz najviši stepen, n^2, te se smatra dominantnim u izrazu za velike vrijednosti n. Konstante b i c označavaju koeficijente koji stoje uz niže stepene, n i 1, te se smatraju zanemarljivim u odnosu na a kada n postaje vrlo veliko.

- Kada se analizira efikasnost algoritma, najčešće se dobija izraz koji se sastoji od jednog ili više članova koji zavise od n (veličine ulaza). Ova analiza se koristi za identifikaciju dominantnog člana izraza, koji je odlučujući za performanse algoritma za velike ulaze.

- Za izražavanje vremenske složenosti se koristi big-O notacija, gdje se složenost reda n^2 zapisuje kao O(n^2).

### Ponašanje algoritama za različite ulaze

- Ponašanje algoritama ovisi o ulazima koji definiraju put izvršavanja algoritamskog procesa

- Broj operacija koji se izvršavaju u algoritmu zavisi od ulaznih podataka

- U analizi algoritama važno je uzeti u obzir različita ponašanja algoritma za različite ulaze

- U primjeru funkcije MAX-ELEMENT, broj operacija dodjele koji se izvršavaju varira između 1 i n, što ovisi o poziciji najvećeg elementa u nizu

'''
MAX-ELEMENT (K)
max = K[0]
for i = 1 to n-1 do
if (K[i] > max) then
max = K[i]
end_if
end_for
return max
'''

- Općenito, trajanje algoritamskog procesa ovisi o ulaznim podacima koje algoritam obrađuje.
