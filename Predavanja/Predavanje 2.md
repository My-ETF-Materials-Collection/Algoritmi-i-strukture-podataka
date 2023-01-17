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

Da bi našli prosječan slučaj potrebno je uraditi sljedeće:

1. Utvrditi broj različitih grupa m, odnosno broj različitih klasa ulaza, u koje se mogu svrstati svi mogući ulazi za neki algoritam.

2. Za svaku identificiranu moguću grupu ulaza ui, odrediti broj operacija t(ui), koje se izvršavaju u algoritmu.

3. Zbrojiti operacije za sve grupe ulaza i zbroj podijeliti sa brojem grupa:

4. Utvrditi vjerojatnost pojavljivanja svake klase ulaza i izračunati prosječno očekivani broj operacija T(n) kao:

gdje su:
n veličina ulaza
m broj različitih klasa ulaza
t(ui) broj operacija za klasu ulaza ui
p(ui) vjerojatnost pojavljivanja klase ulaza ui, pri čemu je:

5. Prosječna analiza vremenske složenosti algoritma se bazira na identifikaciji različitih klasa ulaza i razmatranju ponašanja algoritma za svaku klasu.

6. Analiza prosječnog slučaja daje očekivana vremena trajanja algoritamskog procesa, te je često najzahtjevnija zbog problema identifikacije prosječnog slučaja zbog različitih vjerojatnosti pojavljivanja ulaznih vrijednosti.

### Asimptotska analiza i klasifikacija stupnjeva rasta

- Pri analizi vremenske složenosti algoritama, interesira nas stupanj rasta sa porastom veličine ulaza, a ne tačan broj operacija.

- Interesira nas ponašanje algoritma za velike ulaze, a ne za male.

- Algoritmi se klasificiraju prema klasama stupnjeva rasta njihove vremenske složenosti.

- Razlike su značajne kod različitih klasa algoritama za velike veličine ulaza.

- Ako je vremenska složenost kombinacija dvije ili više klasa složenosti, dominantna klasa dominira nad ostalima.

- Klasifikacije uobičajenih klasa algoritama su: O(1), O(log n), O(n), O(n log n), O(n^2), O(n^3), O(2^n) and O(n!)

#### Notacija big-O

- Big-O notacija se koristi za klasifikaciju algoritama prema stupnju rasta vremenske složenosti.

- Funkcija f(n) se kaže da je O(g(n)) ako postoje pozitivne konstante c i n0 za koje vrijedi f(n) <= cg(n) za svako n>=n0.

- Big-O notacija definira gornju granicu složenosti algoritma, jer f(n) je asimptotski ograničeno sa g(n) i sigurno nema veći red veličine rasta sa porastom veličine ulaza n.

- Big-O notacija se koristi za klasifikaciju algoritama prema stupnju rasta vremenske složenosti, a ne tačnom broju operacija.

- Postoji beskonačno puno funkcija g(n) za datu funkciju f(n), a za g(n) se izabire funkcija s najmanjim rastom.

- Notacija big-O ima svojstva kao što su: ako su f(n) i g(n) reda O(h(n)), onda je f(n) + g(n) reda O(h(n)), funkcija ank je reda O(nk), i funkcija nk je reda O(nk+j) za sve pozitivne vrijednosti j.

- Vremenska složenost polinomskog oblika f(n) = a_nn^k+a_k-1n^(k-1)+...+a_1n+a_0 izražena big-O notacijom ima oblik O(n^k)

#### Notacija big-Ω

- Big-O notacija daje uvid o ponašanju algoritma prije svega za velike vrijednosti n.

- Big-O notacija daje gornju granicu složenosti algoritama.

- Ponekad se koristi i donja granica složenosti algoritama, koja se izražava big-Ω notacijom.

- Big-Ω notacija izražava da postoje pozitivni brojevi c i n0 takvi da je: f(n) >= cg(n) za svako n>=n0.

#### Notacija big-Θ

- Notacija big-Ω služi za izražavanje donje granice složenosti algoritama

- Notacija big-Θ služi za izražavanje asimptotske granice performansi nekog algoritma sa obje strane, tj. i sa gornje i sa donje strane

- Notacija big-Θ se koristi kada se želi izraziti složenost funkcije f(n) sa gornje i sa donje strane

- U literaturi se pojavljuju različiti zapisi kojima se prikazuje da neka funkcija f pripada skupu O(g), Ω(g) i Θ(g)

#### Neke tipične klase stupnjeva rasta vremenske složenosti
