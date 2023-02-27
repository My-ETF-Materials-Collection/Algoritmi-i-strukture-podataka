// 1. odrediti kompleksnost od isječaka koda

/*
a)

int f(int a) {
int b=1, x=1;
do {
x = x * (a/b);
b ++;
} while (a>b);
return x;
}
for (int i(x-1); i>=0; i--) {
if (i*2 > niz[i]) continue;
suma += f(niz[i]);
}
*/

/*
funkcija f(int a) se izvrsava a puta, zavisno od ulaza
pa je to O(a) tj. O(n)
drugi dio se poziva f(niz[i]) sto daje O(niz[i])=O(n),
ali kako se vanjska for petlja izvrsava x puta tj. O(x)
time je ovo proizvod O(niz[i]*x) sto je zapravo O(n*f(n))
*/

/*
b)

i=2;
while (i<n)
{
j=2;
while (j<i) {
if (niz[i]==niz[j]) { goto LI; }
else {
if (j==i-1) {
b=b+1; goto LI; }
else goto LJ;
}
LJ: j++;
}
LI: i++;
}
*/

/*
Prva while petja se izvrsava n-2 puta sto 
daje u najgorem slucaju O(n),
druga while petlja iterira i puta, a znamo da se i krece
od 2 do n-1, time unutrasnja petlja daje kompleksnost od
2+3+4+...+(n-1)=(n-1)n/2 - 1 = 1/2 n^2 - 1/2 n - 1  ->
O(n^2)
unutar te petlje su samo O(1) operacije sa if uslovima i sl.
pa se one zanemaruju
time je konacno rj. O(n^2)
*/

/* 
c)

int f(1), sum(0);
for (int i(2); i<=n; i++)
f *= i;
for (int i(0); i<f; i++)
sum += i;
*/

/*
unutar for petlje i se krece od 2 do n te se f racuna 
kao faktorijel, druga for petlja se izvrsava zasebno 
dajuci broj iteracija f tj n! gdje se suma sabira samo
sto ne utice na kompleksnost jer je O(1),
time ovaj isjecak ima kompleksnost od
O(n+n!)->O(n!)
*/