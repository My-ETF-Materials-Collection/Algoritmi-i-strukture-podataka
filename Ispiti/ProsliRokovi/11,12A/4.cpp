/* 4. (5 bodova)
U klasu Lista dodati metodu koja na ekranu ispisuje elemente liste unazad (od
posljednjeg do prvog) koristeći rekurziju.
*/

#include <iostream>

using namespace std;

template <typename Tip> struct Cvor {
public:
  Tip value;
  Cvor *next;
  Cvor(Tip v, Cvor *n) {
    value = v;
    next = n;
  }
};

template <typename Tip> class Lista {
public:
  Cvor<Tip> *pocetak, *kraj;
  void ispisiUnazad(Cvor<Tip> *trenutni);
  void ispisiUnaprijed(Cvor<Tip> *trenutni);
};

template <typename Tip> void Lista<Tip>::ispisiUnazad(Cvor<Tip> *trenutni) {
  if (trenutni == nullptr) {
    return;
  }
  ispisiUnazad(trenutni->next);
  cout << trenutni->value << " ";
}

template <typename Tip> void Lista<Tip>::ispisiUnaprijed(Cvor<Tip> *trenutni) {
  if (trenutni == nullptr) {
    return;
  }
  cout << trenutni->value << " ";
  ispisiUnaprijed(trenutni->next);
}

int main() {
  Lista<int> l;
  l.pocetak = new Cvor<int>(5, new Cvor<int>(10, new Cvor<int>(34, new Cvor<int>(-12, new Cvor<int>(4, nullptr)))));
  l.ispisiUnazad(l.pocetak);
  cout << endl;
  l.ispisiUnaprijed(l.pocetak);
  return 0;
}
