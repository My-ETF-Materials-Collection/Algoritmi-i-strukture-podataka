/*
Vježba 1

Cilj vježbe 1 je upoznavanje studenata sa primjenom najčešće korištenih notacija za
izražavanje vremenske kompleksnosti kao što su big-O, big-Ω i big-Θ. Studenti će na
vježbama analizirati vremensku kompleksnost na odgovarajućim primjerima.

Pripremni zadatak

Napraviti funkciju sa sljedećim prototipom: void Goldbach (int n, int& p, int& q) koja
testira Goldbachovu hipotezu za broj n. Goldbachova hipoteza glasi da se svaki paran
broj n veći od 2 može napisati kao zbir dva prosta broja p i q. Ova hipoteza nikada nije
dokazana ali nije ni opovrgnuta, odnosno nije pronaĎen broj n za koji ne važi, tako da se
smatra da je tačna. Dakle, vaša funkcija treba odrediti brojeve p i q koji su prosti i čiji je
zbir n i upisati ih u primljene reference. Ukoliko primljeni broj n nije paran ili nije veći
od 2 funkcija treba baciti izuzetak. Osim toga, treba baciti izuzetak i u slučaju da
Goldbachova hipoteza nije tačna. Napravite i kraću main() funkciju koja omogućava unos
broja n, poziva napisanu funkciju Goldbach i ispisuje na ekranu p i q, te hvata sve bačene
izuzetke.

Diskusija pripremnog zadatka

U pripremnom zadatku se tražilo da napravite funkciju za testiranje Goldbachove
hipoteze.

a) Koliko dugo se izvršava vaša funkcija?

Da bismo izmjerili vrijeme izvršavanja funkcije možemo koristiti funkciju clock() iz
biblioteke ctime (koja se u C-u zove time.h). Funkcija clock() vraća broj “otkucaja sata”
od pokretanja programa. Pošto otkucaj sata ne traje jednako dugo na svakom računaru,
koristi se konstanta CLOCKS_PER_SEC da se odredi vrijeme izvršavanja u sekundama.
Mi ćemo koristiti milisekunde koje će nam dati preciznije vrijeme izvršenja funkcije.
Na primjer, nakon što smo dodali #include <ctime> u zaglavlje programa, možemo pisati
ovako:

clock_t vrijeme1 = clock();
Goldbach(n,p,q);
clock_t vrijeme2 = clock();
int ukvrijeme = (vrijeme2 - vrijeme1) / (CLOCKS_PER_SEC / 1000);
cout << "Vrijeme izvrsenja: " << ukvrijeme << " ms." << endl;

Prilikom testiranja, za n unosite vrijednosti: 10, 100, 1000, 10000, itd. dok ne doĎete do
neke dovoljno velike vrijednosti za koju se vaš program izvršava oko 2 sekunde.

b) Pokušajte eksperimentalno odrediti vremensku kompleksnost vašeg rješenja.
Umjesto prethodno odreĎenog broja za n, unesite broj koji je dva puta veći, a zatim i broj
koji je dva puta manji. Svaki put zabilježite vrijeme izvršavanja. Sada pogledajte
standardne klase kompleksnosti i uporedite ih sa onim što ste zabilježili. Na primjer, ako
se za dva puta veći n, program izvršava četiri puta duže, riječ je o kvadratnoj
kompleksnosti i slično. Na sličan način bi se mogla procijeniti i memorijska
kompleksnost. Nažalost, mjerenje iskorištenja memorije nije jednostavno kao mjerenje
vremena izvršavanja.

c) Prodiskutujte različita rješenja zadatka sa tutorom. Zašto su neka rješenja brža od
drugih? Može li se za dato rješenje zadatka odrediti matematička zavisnost fmem(n) koja
daje ukupnu zauzetu memoriju u bajtima za unesenu vrijednost n? Mogu li se odrediti
zavisnosti fop(n) koje odreĎuju broj pojedinih elementarnih operacija (sabiranje, dijeljenje,
stavljanje u niz) ovisno o unesenom broju n?

d) Sada probajte prepraviti svoj program tako da se koristi najefikasniji algoritam
*/

#include <iostream>
#include <vector>
using namespace std;

// Eratostenovo sito za pronalazak prostih brojeva
void SieveOfEratosthenes(vector<long long int> &primes, long long int n)
{
    primes.assign(n + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i * 2; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }
}

// Goldbachova funkcija koja testira Goldbachovu hipotezu za broj n
void Goldbach(long long int n, long long int &p, long long int &q)
{
    if (n <= 2 || n % 2 != 0)
    {
        throw "Broj n mora biti veći od 2 i paran!";
    }
    vector<long long int> primes;
    SieveOfEratosthenes(primes, n);
    for (int i = 2; i <= n / 2; i++)
    {
        if (primes[i] == 1 && primes[n - i] == 1)
        {
            p = i;
            q = n - i;
            return;
        }
    }
    throw "Goldbachova hipoteza nije tačna za uneseni broj n!";
}

int main()
{
    long long int n, p, q;
    cout << "Unesite broj n: ";
    cin >> n;

    try
    {
        Goldbach(n, p, q);
        cout << "Broj " << n << " može se napisati kao zbir prostih brojeva " << p << " i " << q << endl;
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }

    return 0;
}
