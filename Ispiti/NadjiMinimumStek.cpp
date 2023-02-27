#include <iostream>
#include <stack>
using namespace std;

class StogSaMinimumom {
private:
    stack<int> stek;
    stack<int> stek_minimuma;
public:
    void dodaj(int x) {
        stek.push(x);
        if (stek_minimuma.empty() || x <= stek_minimuma.top()) {
            stek_minimuma.push(x);
        }
    }
    void ukloni() {
        if (stek.empty()) {
            return;
        }
        int x = stek.top();
        stek.pop();
        if (x == stek_minimuma.top()) {
            stek_minimuma.pop();
        }
    }
    int NadjiMinimum() {
        if (stek_minimuma.empty()) {
            return -1; // ili bilo koju vrijednost koju odaberete za prazan stek
        }
        return stek_minimuma.top();
    }
};

int main() {
    StogSaMinimumom stog;
    stog.dodaj(3);
    stog.dodaj(5);
    stog.dodaj(2);
    stog.dodaj(7);
    stog.dodaj(1);

    cout << "Najmanji element: " << stog.NadjiMinimum() << endl; // ispis: Najmanji element: 1

    stog.ukloni();
    stog.ukloni();

    cout << "Najmanji element: " << stog.NadjiMinimum() << endl; // ispis: Najmanji element: 2

    stog.dodaj(0);

    cout << "Najmanji element: " << stog.NadjiMinimum() << endl; // ispis: Najmanji element: 0

    return 0;
}
