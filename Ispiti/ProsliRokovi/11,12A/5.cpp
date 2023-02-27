/* 5. (2 boda)
Napišite formalnu definiciju za Big-θ notaciju, 
te ukratko obrazložite značenje ove notacije
koristeći se grafičkim prikazom.
*/

/*
Big-θ notacija :

za predstavljanje asimptotske granice performansi nekog
algoritma i sa gornje i sa donje granice koristi se Big-θ notacija.
Za funkciju f(n) kažemo da je θ(g(n)), ako postoje pozitivni 
brojevi c1,c2 i n0 za koje ce se zadovoljavati relacije:
c1g(n)<=f(n)<=c2g(n) za svako n>=n0

Iz ovoga vidimo da je f(n)=θ(g(n)) ako je f(n)=O(n) i f(n)=Ω(g(n),
što u biti predstavlja asimptotsku granicu performansi i sa gornje
i sa donje strane.

Graficki prikaz:

f(n) = n^2
graf na kojem imamo tri fje sa f(n), c1g(n) i c2g(n).
Funkcije se presjecaju međusobno random, ali od određenog n0
f(n) je onda uvijek veća od c1g(n), te uvijek manja od c2g(n)
*/

/*
Ukratko objasnite pojam binarne rekurzije, 
kao i pojam eksponencijalne rekurzije.
*/

/*
Ako se izvršavanje određene funkcije sadrži od samo 2 rekurzivna 
poziva, tada ta funkcija se naziva binarnom rekurzivnom funkcijom, 
te se takav tip rekurzije zove binarna rekurzija.

Binarna rekurzija se odnosi na rekurzivne funkcije koje su bazirane 
na binarnom podjeli problema. To znači da se svaki poziv funkcije 
dijeli na dva manja podproblema, koji se također rješavaju rekurzivno.

Primjer binarne rekurzije je algoritam za pretraživanje 
binarnog stabla. Algoritam počinje traženje na korijenu stabla,
a zatim se rekurzivno poziva na lijevo ili desno podstablo, ovisno
o tome gdje se može naći traženi element.

Ova metoda se također može koristiti za algoritme koji se 
baziraju na podjeli-i-vladaj principu, kao što su algoritmi za 
sortiranje podjelom (npr. Quicksort) ili pretraživanje podjelom 
(npr. Ternarno pretraživanje).

Binarna rekurzija se može koristiti za rješavanje problema 
koji se mogu podijeliti na dva manja podproblema, što često 
omogućuje efikasnije rješenje nego iterativni pristup. Međutim, 
binarna rekurzija također može potrošiti više memorije zbog potrebe 
za stvaranjem novih stoga svaki put kada se poziva funkcija.
*/
