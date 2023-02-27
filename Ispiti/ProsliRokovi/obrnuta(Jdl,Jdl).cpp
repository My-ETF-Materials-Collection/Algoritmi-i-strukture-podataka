#include <iostream>

using namespace std;

template <typename Tip>
struct Cvor {
    Tip element;
    Cvor *sljedeci = nullptr;
    Cvor(const Cvor &c) : element(c.element), sljedeci(nullptr) {}
    Cvor() { sljedeci = nullptr; }
  };

template <typename Tip> class Lista {
  // void operator = (const Lista&);
  // Lista(const Lista&);
public:
  // konstruktor bez parametara koji kreira praznu listu
  Lista() {}

  // destruktor
  virtual ~Lista(){};

  // metoda koja vraca broj elemenata stavljenih u listu (na pocetku 0)
  virtual int brojElemenata() const = 0;

  // metoda koja vraca trenutni element u listi
  virtual Tip &trenutni() = 0;

  // metoda koja pomjera trenutni element odnosno mijenjaju vrijednost koju ce
  // vratiti trenutni P.S. ako je trenutni element prvi (posljednji) onda ne
  // treba nista uraditi, ali treba vratiti false, u suprotnom ako je pomjeranje
  // trenutnog bilo uspjesno treba vratiti true
  virtual bool prethodni() = 0;

  // metoda slicna metodi prethodni()
  virtual bool sljedeci() = 0;

  // metoda koja postavlja trenutni element na pocetak liste
  virtual void pocetak() = 0;

  // metoda koja postavlja trenutni element na kraj liste
  virtual void kraj() = 0;

  // metoda koja briše iz liste trenutni element u listi, element prije njega
  // postaje trenutni
  virtual void obrisi() = 0;

  // metoda koja dodaje element ispred trenutnog elementa
  virtual void dodajIspred(const Tip &element) = 0;

  // metoda koja dodaje element iza trenutnog elementa
  virtual void dodajIza(const Tip &element) = 0;

  // preklopljeni operator [ ] koji omogućuje pristup i-tom članu niza,
  // uključujući njegovo čitanje i izmjenu
  virtual Tip &operator[](int broj) = 0;
};

template <typename Tip> class JednostrukaLista : public Lista<Tip> {
public:
  int velicina;
  Cvor<Tip> *pocetni;
  Cvor<Tip> *krajnji;
  Cvor<Tip> *tekuci;



  JednostrukaLista() : pocetni(0), krajnji(0), tekuci(0), velicina(0) {}
  JednostrukaLista(const JednostrukaLista &jdl)
      : pocetni(0), krajnji(0), tekuci(0), velicina(0) {
    Cvor<Tip> *p = jdl.pocetni;
    while (p != 0) {
      dodajIza(p->element);
      p = p->sljedeci;
    }
  }
  JednostrukaLista &operator=(const JednostrukaLista &jdl) {
    if (&jdl == this)
      return *this;
    while (pocetni != nullptr) {
      tekuci = pocetni;
      pocetni = pocetni->sljedeci;
      delete tekuci;
    }
    if (jdl.velicina == 0)
      pocetni = krajnji = tekuci = nullptr;
    else {
      Cvor<Tip> *pomocni = jdl.pocetni;
      while (pomocni != 0) {
        dodajIza(pomocni->element);
        sljedeci();
        pomocni = pomocni->sljedeci;
      }
    }
    velicina = jdl.velicina;
    return *this;
  }
  ~JednostrukaLista() {
    while (pocetni != nullptr) {
      tekuci = pocetni;
      pocetni = pocetni->sljedeci;
      delete tekuci;
    }
    pocetni = krajnji = tekuci = 0;
  }
  void pocetak() { tekuci = pocetni; }
  void kraj() { tekuci = krajnji; }
  bool prethodni() {
    if (tekuci == pocetni)
      return false;
    if (velicina != 0) {
      Cvor<Tip> *preth = pocetni;
      while (preth->sljedeci != tekuci)
        preth = preth->sljedeci;
      tekuci = preth;
      return true;
    }
    return true;
  }
  bool sljedeci() {
    if (tekuci == krajnji)
      return false;
    tekuci = tekuci->sljedeci;
    return true;
  }
  void obrisi() {
    if (velicina == 0)
      throw "Prazna lista";
    else if (tekuci == krajnji) {
      Cvor<Tip> *temp = pocetni;
      if (pocetni != krajnji) {
        while (temp->sljedeci != krajnji)
          temp = temp->sljedeci;
      }
      delete krajnji;
      krajnji = temp;
      tekuci = krajnji;
      if (velicina - 1 != 0)
        tekuci->sljedeci = nullptr;
      velicina--;
    } else if (tekuci == pocetni) {
      pocetni = tekuci->sljedeci;
      delete tekuci;
      tekuci = pocetni;
      velicina--;
    } else {
      Cvor<Tip> *pomocniCvor = pocetni;
      while (pomocniCvor != krajnji && pomocniCvor->sljedeci != krajnji &&
             pomocniCvor->sljedeci != tekuci)
        pomocniCvor = pomocniCvor->sljedeci;
      auto drugiPomocni = tekuci->sljedeci;
      delete tekuci;
      pomocniCvor->sljedeci =
          drugiPomocni; // element gdje je bio u trenutku postaje sljedeci
      tekuci = pomocniCvor->sljedeci;
      velicina--;
    }
    if (velicina == 0) {
      krajnji = tekuci = pocetni = 0;
    }
  }
  Tip trenutni() const {
    if (velicina <= 0)
      throw "Prazna lista";
    else
      return tekuci->element;
  }
  Tip &trenutni() {
    if (velicina <= 0)
      throw "Prazna lista";
    else
      return tekuci->element;
  }
  void dodajIspred(const Tip &x) {
    Cvor<Tip> *noviCvor = new Cvor<Tip>();
    noviCvor->element = x;
    if (velicina == 0) {
      pocetni = noviCvor;
      krajnji = noviCvor;
      tekuci = noviCvor;
      noviCvor->sljedeci = 0;
      velicina++;
    } else if (tekuci == pocetni) // ima samo 1 element
    {
      noviCvor->sljedeci = pocetni;
      pocetni = noviCvor;
      velicina++;
    } else {
      Cvor<Tip> *temp = pocetni;
      while (temp != krajnji && temp->sljedeci != tekuci &&
             temp->sljedeci != krajnji) {
        temp = temp->sljedeci;
      }
      noviCvor->sljedeci = temp->sljedeci;
      temp->sljedeci = noviCvor;
      velicina++;
    }
  }
  void dodajIza(const Tip &x) {
    Cvor<Tip> *noviCvor = new Cvor<Tip>();
    noviCvor->element = x;
    if (velicina == 0) {
      pocetni = noviCvor;
      krajnji = noviCvor;
      tekuci = noviCvor;
      noviCvor->sljedeci = 0;
      velicina++;
    } else if (tekuci == krajnji) {
      tekuci->sljedeci = noviCvor;
      noviCvor->sljedeci = 0;
      krajnji = noviCvor;
      velicina++;
    } else {
      Cvor<Tip> *temp = pocetni;
      noviCvor->sljedeci = temp->sljedeci;
      temp->sljedeci = noviCvor;
      velicina++;
    }
  }
  int brojElemenata() const { return velicina; }
  Tip &operator[](int broj) {
    Cvor<Tip> *temp = pocetni;
    for (int j = 0; j < broj; j++) {
      if (temp != krajnji)
        temp = temp->sljedeci;
    }
    return temp->element;
  }
  Tip const &operator[](int broj) const {
    Cvor<Tip> *temp = pocetni;
    for (int j = 0; j < broj; j++) {
      if (temp != krajnji)
        temp = temp->sljedeci;
    }
    return temp->element;
  }
  void pomakni();
  void brisiZadnji();
};

template<typename Tip>
void JednostrukaLista<Tip>::pomakni() {
    if (tekuci != nullptr)
        tekuci = tekuci->sljedeci;
}

template<typename Tip>
void JednostrukaLista<Tip>::brisiZadnji() {
    if (pocetni == nullptr) return;
    if (pocetni == krajnji) {
        pocetni = nullptr;
        krajnji = nullptr;
    } else {
        auto temp = pocetni;
        while (temp->sljedeci != krajnji) {
            temp = temp->sljedeci;
        }
        temp->sljedeci = nullptr;
        krajnji = temp;
    }
    kraj();
}


template<typename Tip>
bool obrnuta(JednostrukaLista<Tip>& lista1, JednostrukaLista<Tip>& lista2) {
    auto zadnji1 = lista1.krajnji;
    auto zadnji2 = lista2.krajnji;
    if (zadnji1 == nullptr && zadnji2 == nullptr) return true;
    if (zadnji1 == nullptr || zadnji2 == nullptr) return false;
    if (zadnji1->element != zadnji2->element) return false;
    lista1.brisiZadnji();
    lista2.brisiZadnji();
    return obrnuta(lista1, lista2);
}



int main() {

    JednostrukaLista<int> lista1;
    lista1.dodajIza(1);
    lista1.dodajIza(2);
    lista1.dodajIza(3);
    lista1.dodajIza(4);
    lista1.dodajIza(5);

    JednostrukaLista<int> lista2;
    lista2.dodajIza(1);
    lista2.dodajIza(2);
    lista2.dodajIza(3);
    lista2.dodajIza(4);
    lista2.dodajIza(5);

    Cvor<int>* temp = lista1.pocetni;
    while(temp!=nullptr){
        cout<<temp->element<<" ";
        temp=temp->sljedeci;
    }

    cout<<endl;

    temp = lista2.pocetni;
    while(temp!=nullptr){
        cout<<temp->element<<" ";
        temp=temp->sljedeci;
    }

    cout<<endl;

    if(obrnuta(lista1, lista2))
        std::cout << "Liste su obrnuta jedna drugoj" << std::endl;
    else
        std::cout << "Liste nisu obrnuta jedna drugoj" << std::endl;

    return 0;
}
