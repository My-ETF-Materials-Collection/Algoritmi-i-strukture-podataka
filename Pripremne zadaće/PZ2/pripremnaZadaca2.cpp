#include <iostream>

using namespace std;

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

template <typename Tip> class NizLista : public Lista<Tip> {
protected:
  int kapacitet;
  int brElemenata;
  int tekuci;
  Tip **L;

public:
  NizLista(const NizLista &nl) {
    kapacitet = nl.kapacitet;
    brElemenata = nl.brElemenata;
    tekuci = nl.tekuci;
    L = new Tip *[kapacitet];
    for (int i = 0; i < brElemenata; i++)
      L[i] = new Tip(*nl.L[i]);
  }
  NizLista &operator=(NizLista &nl) {
    if (&nl == this)
      return *this;
    for (int i = 0; i < this->brojElemenata(); i++)
      delete L[i];
    delete[] L;
    L = new Tip *[nl.kapacitet];
    this->brElemenata = nl.brElemenata;
    this->kapacitet = nl.kapacitet;
    this->tekuci = nl.tekuci;
    for (int i = 0; i < nl.brElemenata; i++)
      L[i] = new Tip(*nl.L[i]);
    return *this;
  }
  explicit NizLista(int vel = 1000) {
    kapacitet = vel;
    brElemenata = tekuci = 0;
    L = new Tip *[kapacitet];
  }
  ~NizLista() {
    for (int i = 0; i < this->brojElemenata(); i++)
      delete L[i];
    delete[] L;
  }
  int brojElemenata() const { return brElemenata; }
  bool prethodni() {
    if (tekuci == 0)
      return false;
    tekuci--;
    return true;
  }
  bool sljedeci() {
    if (tekuci == brElemenata - 1)
      return false;
    tekuci++;
    return true;
  }
  Tip &trenutni() {
    if (brElemenata == 0)
      throw "Prazna lista";
    return *L[tekuci];
  }
  Tip &trenutni() const {
    if (brElemenata == 0)
      throw "Prazna lista";
    return *L[tekuci];
  }
  Tip &operator[](int broj) {
    if (broj < 0 || broj >= brElemenata)
      throw "Pogrešan indeks";
    return *L[broj];
  }
  Tip const &operator[](int broj) const {
    if (broj < 0 || broj >= brElemenata)
      throw "Pogrešan indeks";
    return *L[broj];
  }
  void pocetak() { tekuci = 0; }
  void kraj() { tekuci = brElemenata - 1; }
  void obrisi() {
    if (brElemenata == 0)
      throw "Prazna lista";
    for (int i = tekuci; i < brElemenata - 1; i++)
      *L[i] = *L[i + 1];
    delete L[brElemenata - 1];
    brElemenata--;
    if (tekuci == brElemenata)
      prethodni();
  }
  void dodajIspred(const Tip &element) {
    if (brElemenata <= kapacitet) {
      // alociramo prvo memorije da ima mjesta da se ubaci novi element
      if (brElemenata == kapacitet) {
        Tip **novaLista = new Tip *[(kapacitet + 1) * 2];
        for (int i = 0; i < brElemenata; i++) {
          novaLista[i] = L[i];
        }
        delete[] L;
        kapacitet = (kapacitet + 1) * 2;
        L = novaLista;
      }
      if (brElemenata == 0) {
        brElemenata++;
        tekuci = 0;
        L[tekuci] = new Tip(element);
      } else {
        // nakon alokacije memorije postavljamo na to novo mjesto dati element
        for (int i = brElemenata; i > tekuci; i--)
          L[i] = L[i - 1]; // odzada ka tekucem idemo i premjestamo sve
                           // dosadasnje za jedno mjesto ulijevo
        L[tekuci] = new Tip(element);
        brElemenata++;
        sljedeci();
      }
    }
  }
  void dodajIza(const Tip &element) {
    if (brElemenata <= kapacitet) {
      // alociramo prvo memorije da ima mjesta da se ubaci novi element
      if (brElemenata == kapacitet) {
        Tip **novaLista = new Tip *[(kapacitet + 1) * 2];
        for (int i = 0; i < kapacitet; i++)
          novaLista[i] = L[i];
        delete[] L;
        kapacitet = (kapacitet + 1) * 2;
        L = novaLista;
      }
      if (brElemenata == 0) {
        brElemenata++;
        tekuci = 0;
        L[0] = new Tip(element);
      } else if (brElemenata == 1) {
        L[brElemenata] = new Tip(element);
        brElemenata++;
      } else {
        // nakon alokacije memorije postavljamo na to novo mjesto dati element
        L[brElemenata] = new Tip(*L[brElemenata - 1]);
        for (int i = brElemenata - 1; i > tekuci + 1; i--)
          *L[i] = *L[i - 1]; // odzada ka tekucem idemo i premjestamo sve
                             // dosadasnje za jedno mjesto udesno
        *L[tekuci + 1] = element;
        brElemenata++;
      }
    }
  }
};

template <typename Tip> class JednostrukaLista : public Lista<Tip> {
private:
  struct Cvor {
    Tip element;
    Cvor *sljedeci = nullptr;
    Cvor(const Cvor &c) : element(c.element), sljedeci(nullptr) {}
    Cvor() { sljedeci = nullptr; }
  };
  int velicina;
  Cvor *pocetni;
  Cvor *krajnji;
  Cvor *tekuci;

public:
  JednostrukaLista() : pocetni(0), krajnji(0), tekuci(0), velicina(0) {}
  JednostrukaLista(const JednostrukaLista &jdl)
      : pocetni(0), krajnji(0), tekuci(0), velicina(0) {
    Cvor *p = jdl.pocetni;
    while (p != 0) {
      dodajIza(p->element);
      p = p->sljedeci;
    }
    /*
    if(jdl.brojElemenata()==0){
        velicina = 0;
        tekuci = pocetni = krajnji = nullptr;
    }else{
        Cvor* pomocni = jdl.pocetni;
        pocetni = new Cvor(*pomocni);
        pocetni->element = pomocni->element;
        tekuci = pocetni;
        while(pomocni->sljedeci!=nullptr){
            pomocni = pomocni->sljedeci;
            tekuci = new Cvor(*pomocni);
            tekuci->element = pomocni->element;
    }
    tekuci = krajnji;
    tekuci->element = pomocni->element;
    tekuci->sljedeci = nullptr;*/
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
      Cvor *pomocni = jdl.pocetni;
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
      Cvor *preth = pocetni;
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
      Cvor *temp = pocetni;
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
      Cvor *pomocniCvor = pocetni;
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
    Cvor *noviCvor = new Cvor();
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
      Cvor *temp = pocetni;
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
    Cvor *noviCvor = new Cvor();
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
      Cvor *temp = pocetni;
      noviCvor->sljedeci = temp->sljedeci;
      temp->sljedeci = noviCvor;
      velicina++;
    }
  }
  int brojElemenata() const { return velicina; }
  Tip &operator[](int broj) {
    Cvor *temp = pocetni;
    for (int j = 0; j < broj; j++) {
      if (temp != krajnji)
        temp = temp->sljedeci;
    }
    return temp->element;
  }
  Tip const &operator[](int broj) const {
    Cvor *temp = pocetni;
    for (int j = 0; j < broj; j++) {
      if (temp != krajnji)
        temp = temp->sljedeci;
    }
    return temp->element;
  }
};

int main() {
  NizLista<int> lista;
  for (int i = 0; i < 5; i++) {
    lista.dodajIza(i);
    lista.sljedeci();
  }
  NizLista<int> niz2(lista);
  lista.obrisi();
  for (int i = 0; i < niz2.brojElemenata(); i++) {
    cout << niz2[i] << " ";
  }
  cout << endl << niz2.brojElemenata() << endl;
  JednostrukaLista<int> jdl;
  for (int i = 0; i < 10; i++)
    jdl.dodajIza(i);
  cout << jdl.brojElemenata() << " ";
  jdl.sljedeci();
  cout << jdl.trenutni() << " ";
  jdl.kraj();
  cout << jdl.trenutni() << " ";
  NizLista<int> l2(lista);
  l2.obrisi();
  cout << l2.trenutni() << " ";
  NizLista<int> l3;
  for (int i = 25; i >= 20; i--)
    l3.dodajIspred(i);
  cout << l3.trenutni() << endl;
  l3 = lista;
  for (int i = 0; i < l3.brojElemenata(); i++) {
    cout << l3.trenutni() << " ";
    l3.sljedeci();
  }
  return 0;
}
