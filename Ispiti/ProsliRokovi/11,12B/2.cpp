/*
U klasi Lista (datoj u prilogu) implementirati novu metodu:
void dodajNto (const Tip&el, int n)

koja primljeni element el dodaje u listu prije n-tog elementa, pri čemu se koristi C notacija po kojoj
je prvi element označen brojem nula. Dakle, ako je lista glasila
A B C D
poziv funkcije dodajNto('E', 1) će imati sljedeći rezultat
A E B C D
*/

#include <iostream>

using namespace std;

template <typename Tip>
struct Cvor{
    public:
    Tip value;
    Cvor* next;
    Cvor(Tip v, Cvor* n){
        value=v;
        next=n;
    }
};

template <typename Tip>
class Lista{
    public:
    Cvor<Tip> *pocetak, *kraj;
    void ispisiElemente(){
        Cvor<char> * temp = pocetak;
        while(temp!=nullptr){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void dodajNto(const Tip& el, int n) {
        if(n<0) throw "Ilegalan indeks";
        if (n == 0) {
            pocetak = new Cvor<Tip>(el, pocetak);
            return;
        }

        Cvor<Tip> *trenutni = pocetak;
        for (int i = 0; i < n-1; i++) {
            if (trenutni->next == nullptr) {
                cout << "Ne postoji " << n << ". element u listi. Element se dodaje na kraj liste." << endl;
                kraj->next = new Cvor<Tip>(el, nullptr);
                kraj = kraj->next;
                return;
            }
            trenutni = trenutni->next;
        }
        trenutni->next = new Cvor<Tip>(el, trenutni->next);
    }
};

int main(){
    Lista<char> l1, l2, l3, l4;
    l3.pocetak = new Cvor<char>('A', new Cvor<char>('B', new Cvor<char>('C', new Cvor<char>('D', nullptr))));
    l3.ispisiElemente();
    l3.dodajNto('E', 1);
    l3.ispisiElemente();
    return 0;
}