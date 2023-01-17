# Predavanje 2 - Analiza vremenske složenosti algoritama

## Uvod

- Analizom vremenske složenosti nekog algoritma određujemo trajanje algoritamskog procesa

- Analizom efikasnosti nekog algoritma, najčešće nas zanima u koju klasu stupnja rasta vremenske složenosti taj algoritam spada

- Ekvivalentni algoritmi su algoritmi koji su dozvoljeni za iste klase ulaznih objekata i koji imaju jednake rezultate za jednake ulazne objekte

- Primjer problema je dizajniranje algoritma za zbrajanje prvih n brojeva, a algoritmi koji se koriste su SUMA (for i=1 do n suma+=i) i SUMA-M(suma=n\*(n+1)/2), koji su ekvivalentni

```c++
SUMA (n)
s = 0
for i = 1 to n do
s = s + i
end_for
return s
```

```c++
SUMA-M (n)
s = n*(n+1)/2
return s
```

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

```c++
MAX-ELEMENT (K)
max = K[0]
for i = 1 to n-1 do
if (K[i] > max) then
max = K[i]
end_if
end_for
return max
```

- Općenito, trajanje algoritamskog procesa ovisi o ulaznim podacima koje algoritam obrađuje.

## Najbolji, najgori i prosječan slučaj

- Pri analizi vremenske složenosti algoritama, potrebno je odlučiti koje operacije su bitne sa stanovišta efikasnosti algoritama.

- Postoje različiti tipovi operacija, kao npr. operacije usporedbi, operacije premještanja elemenata sa jedne lokacije na drugu, aritmetičke operacije, operacije dodjele vrijednosti itd.

- Operacije koje se tretiraju kao relevantne pri nekoj analizi vremenske složenosti, ovisi o konkretnoj situaciji i implementaciji algoritma.

- Aritmetičke operacije se mogu svrstati u dvije grupe: aditivne i multiplikativne.

- Specijalan slučaj je kada imamo cjelobrojno množenje ili dijeljenje sa potencijom broja 2, jer se tada takve operacije mogu svesti na operaciju pomaka.

- U određenim situacijama je opravdano sve tipove operacija razmatrati zajedno.

- Trajanje algoritamskog procesa može varirati ne samo u ovisnosti od veličine ulaza, nego i o konkretnim vrijednostima ulaznih podataka.

- Pri analizi algoritama se mogu razmatrati najbolji, najgori i prosječni slučaj.

### Najbolji slučaj

- Najbolji slučaj predstavlja kombinaciju ulaznih podataka za koju algoritam izvršava u najkraćem vremenu.

- Najbolji slučaj se često odnosi na situaciju kada se tražena vrijednost nalazi na prvoj poziciji u nizu.

- Analiza najboljeg slučaja obično nije od interesa jer ne daje dovoljno dobar uvid u ponašanje algoritma.

- Najbolji slučaj se rijetko analizira jer se obično fokusira na ponašanje algoritma u najgorem slučaju.

### Najgori slučaj

- Najgori slučaj za analizu vremenske složenosti algoritma predstavlja gornju granicu trajanja algoritamskog procesa za bilo koje vrijednosti ulaznih podataka, što osigurava garanciju efikasnosti algoritma.

- Analiza najgoreg slučaja traži identifikaciju ulaznih vrijednosti za koje trajanje algoritamskog procesa bude najduže.

- Primjer najgoreg slučaja u algoritmima pretraživanja je kada se tražena vrijednost ne nalazi u nizu ili se tražena vrijednost nalazi na zadnjoj poziciji u nizu.

- Najgori slučaj se pojavljuje često u nekim algoritmima.

### Klase ulaza i prosječan slučaj

- Klase ulaza se koriste za smanjenje broja mogućih ulaza koji se trebaju razmotriti pri analizi vremenske složenosti nekog algoritma.

- Analiza prosječnog slučaja algoritma se temelji na podjeli svih mogućih ulaza u različite klase ulaza i razmatranju ponašanja algoritma za svaku klasu.

- Analiza prosječnog slučaja omogućuje dobivanje potpunije slike o ponašanju algoritma, jer se razmatra ponašanje algoritma za različite klase ulaza.

- Algoritam sekvencijalnog pretraživanja može se analizirati u dva slučaja, pretpostavljajući da je pretraživanje uvijek uspješno ili ponekad neuspješno.

- U analizi prosječnog slučaja se uzimaju u obzir sve pozicije na kojima se traženi element može nalaziti u nizu.

- Broj operacija usporedbe potreban za pronalaženje traženog elementa u algoritmu sekvencijalnog pretraživanja ovisi o poziciji na kojoj se taj element nalazi.

```c++
TRAZI-SEKV (K, k)
i = 0
while (i ≤ n-1) do
if (K[i] == k) then
return i
else
i = i+1
end_if
end_while
return -1
```
![image](https://user-images.githubusercontent.com/113919501/213008604-cb4ab6bb-a843-4535-b8e6-2a403cbcd35f.png)
![image](https://user-images.githubusercontent.com/113919501/213008641-84513fdc-29d2-4e18-adfb-ec4801e76a82.png)
![image](https://user-images.githubusercontent.com/113919501/213008675-3519ecf0-8f06-4b5e-bb8c-020fc36ff810.png)

Da bi našli prosječan slučaj potrebno je uraditi sljedeće:

1. Utvrditi broj različitih grupa m, odnosno broj različitih klasa ulaza, u koje se mogu svrstati svi mogući ulazi za neki algoritam.

2. Za svaku identificiranu moguću grupu ulaza ui, odrediti broj operacija t(ui), koje se izvršavaju u algoritmu.

3. Zbrojiti operacije za sve grupe ulaza i zbroj podijeliti sa brojem grupa: ![image](https://user-images.githubusercontent.com/113919501/213008720-618512b2-2b2d-4516-8ac9-3f0580553f23.png)

4. Utvrditi vjerojatnost pojavljivanja svake klase ulaza i izračunati prosječno očekivani broj operacija T(n) kao:

 `![image](https://user-images.githubusercontent.com/113919501/213008755-344ba11e-05fe-4104-b880-941f9bc17b79.png)`

gdje su:
- n veličina ulaza
- m broj različitih klasa ulaza
- t(ui) broj operacija za klasu ulaza ui
- p(ui) vjerojatnost pojavljivanja klase ulaza ui, pri čemu je:

5. Prosječna analiza vremenske složenosti algoritma se bazira na identifikaciji različitih klasa ulaza i razmatranju ponašanja algoritma za svaku klasu.

6. Analiza prosječnog slučaja daje očekivana vremena trajanja algoritamskog procesa, te je često najzahtjevnija zbog problema identifikacije prosječnog slučaja zbog različitih vjerojatnosti pojavljivanja ulaznih vrijednosti.
