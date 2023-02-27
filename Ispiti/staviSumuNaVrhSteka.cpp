#include <iostream>
#include <stack>

using namespace std;

#include <iostream>

using namespace std;

template <typename Tip> struct Cvor {
  Tip element;
  Cvor<Tip> *next;
};

template <typename Tip> class Stek {
  int velicina;
  Cvor<Tip> *vrhic;

public:
  Stek() {
    velicina = 0;
    vrhic = nullptr;
  }
  Stek(const Stek<Tip> &s) {
    if (s.velicina == 0) {
      vrhic = nullptr;
      velicina = 0;
    } else {
      vrhic = new Cvor<Tip>{s.vrhic->element, nullptr};
      auto temp = s.vrhic;
      temp = s.vrhic->next;
      auto klizni = vrhic;
      for (; temp;) {
        klizni->next = new Cvor<Tip>{temp->element, nullptr};
        klizni = klizni->next;
        temp = temp->next;
      }
      velicina = s.velicina;
    }
  }
  // Stek(Stek<Tip>&&s);
  Stek<Tip> &operator=(const Stek<Tip> &s) {
    if (&s == this)
      return *this;
    Stek<Tip> a(s);
    auto temp = vrhic;
    vrhic = a.vrhic;
    a.vrhic = temp;
    auto temp2 = velicina;
    velicina = a.velicina;
    a.velicina = temp2;
    return *this;
  }
  Stek<Tip> &operator=(Stek<Tip> &&s) {
    auto temp = vrhic;
    vrhic = s.vrhic;
    s.vrhic = temp;
    temp = velicina;
    velicina = s.velicina;
    s.velicina = temp;
    return *this;
  }
  void stavi(const Tip &element);
  void brisi();
  Tip skini();
  Tip &vrh();
  const Tip &vrh() const;
  const int brojElemenata() const { return velicina; }
  ~Stek() { brisi(); };
};

template <typename Tip> void Stek<Tip>::brisi() {
  auto x = vrhic;
  for (; vrhic;) {
    x = vrhic;
    vrhic = vrhic->next;
    delete x;
  }
  velicina = 0;
}

template <typename Tip> Tip &Stek<Tip>::vrh() {
  if (velicina == 0)
    throw "Prazan stek!";
  return vrhic->element;
}

template <typename Tip> const Tip &Stek<Tip>::vrh() const {
  if (velicina == 0)
    throw "Prazan stek!";
  return vrhic->element;
}

template <typename Tip> Tip Stek<Tip>::skini() {
  if (velicina == 0)
    throw "Prazan stek!";
  Tip a = vrhic->element;
  auto temp = vrhic;
  vrhic = vrhic->next;
  delete temp;
  velicina--;
  return a;
}

template <typename Tip> void Stek<Tip>::stavi(const Tip &element) {
  try {
    auto temp = new Cvor<Tip>{element, vrhic};
    vrhic = temp;
    velicina++;
  } catch (...) {
    auto x = vrhic;
    for (; vrhic;) {
      x = vrhic;
      vrhic = vrhic->next;
      delete x;
    }
    throw "Nema dovoljno memorije";
  }
}

template <typename Tip> void dodajSumuNaVrh(Stek<Tip> &stek) {
    int suma = 0;
    int brojElemenata = stek.brojElemenata();
    for (int i = 0; i < brojElemenata; i++) {
        suma += stek.skini();
        stek.stavi(1);
        brojElemenata++;
    }
    stek.stavi(suma);
}

int main(){
    
    Stek<int> s;
    s.stavi(5); s.stavi(8); s.stavi(3); s.stavi(5); s.stavi(1);
    
    cout << "Pocetni stek: ";
    Stek<int> temp = s;
    while (temp.brojElemenata()) {
        cout << temp.vrh() << " ";
        temp.skini();
    }
    cout << endl;

    dodajSumuNaVrh(s);

    cout << "Rezultantni stek: ";
    while (s.brojElemenata()){
        cout << s.vrh() << " ";
        s.skini();
    }
    cout << endl;

    return 0;

}
