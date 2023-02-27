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