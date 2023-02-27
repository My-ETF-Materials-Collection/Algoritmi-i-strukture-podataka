#include <iostream>

using namespace std;

template <typename Tip> struct Cvor {
  Tip element;
  Cvor<Tip> *next;
  Cvor(Tip v, Cvor *n) {
    element = v;
    next = n;
  }
};

template <typename Tip> class Lista {
public:
  Cvor<Tip> *pocetak, *kraj, *trenutni;
  int brElemenata;
  int brojElemenata() {
    int count = 0;
    auto temp = pocetak;
    while (temp != nullptr) {
      temp = temp->next;
      count++;
    }
    brElemenata = count;
    return count;
  }

  void obrisiNPrvihIzadnjih(int n) {
    // nije moguce obrisati jer bi se obrisalo vise nego sto ima elemenata
    if (2 * n > brojElemenata())
      return;

    // brisanje prvih n cvorova
    Cvor<Tip> *temp = pocetak;
    for (int i = 0; i < n; i++) {
      Cvor<Tip> *temp2 = temp->next;
      delete temp;
      temp = temp2;
      pocetak = temp;
      brElemenata--;
    }

    // pronalazak ntog cvora
    Cvor<Tip> *temp3 = pocetak;
    for (int i = 1; i < brojElemenata() - n; i++)
      temp3 = temp3->next;

    // brisanje zadnjih n cvorova
    auto temp4 = temp3->next;
    while (temp4 != nullptr) {
      auto brisi = temp4;
      temp4 = temp4->next;
      delete temp4;
      brElemenata--;
    }

    // azuriranje pointera kraj
    kraj = temp3;
    kraj->next = nullptr;
  }
};

int main() {

  Lista<char> lista2;
  lista2.pocetak = new Cvor<char>(
      '1',
      new Cvor<char>(
          '2', new Cvor<char>(
                   '3', new Cvor<char>(
                            '4', new Cvor<char>(
                                     '5', new Cvor<char>('6', nullptr))))));
  cout << "List before deletion: ";
  Cvor<char> *temp = lista2.pocetak;
  while (temp != nullptr) {
    cout << temp->element << " ";
    temp = temp->next;
  }
  cout << endl;
  cout << "Number of elements before deletion: " << lista2.brojElemenata()
       << endl;

  lista2.obrisiNPrvihIzadnjih(2);
  cout << endl;
  cout << "List after deletion: ";
  temp = lista2.pocetak;
  while (temp != nullptr) {
    cout << temp->element << " ";
    temp = temp->next;
  }
  cout << endl;
  cout << "Number of elements after deletion: " << lista2.brojElemenata();

  return 0;
}