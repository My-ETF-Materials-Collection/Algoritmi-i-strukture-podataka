#include <iostream>

using namespace std;

template <typename Tip> struct Cvor {
  Tip element;
  Cvor<Tip> *next;
};

template <typename Tip> class Stek {
    public:
  int velicina;
  Cvor<Tip> *vrhic;
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

template <typename Tip>
Tip sumaZadnjaDva(Stek<Tip> &s) {
    if (s.brojElemenata() < 2)
        throw "Stek mora imati barem 2 elementa.";
    Cvor<Tip> *temp = s.vrhic, *p1 = nullptr, *p2 = nullptr;
    for (int i = 0; i < s.brojElemenata() - 3; i++) {
        temp = temp->next;
    }
    p1 = temp->next, p2 = p1->next;
    temp->next = p2->next;
    s.velicina -= 2;
    Tip sum = p1->element + p2->element;
    delete p1, delete p2;
    return sum;
}

int main() {
  Stek<int> s;
  for (int i = 3; i < 10; i++) {
    s.stavi(i);
  }
    Cvor<int> *temp = s.vrhic;
    while (temp != nullptr) {
        cout << temp->element << " ";
        temp = temp->next;
    }
cout << endl;

  try {
        int suma = sumaZadnjaDva(s);
        cout << "Suma zadnja dva elementa je: " << suma << endl;
    } catch (...) {
        cout<<"Neuspješno sabiranje elemenata"<< endl;
    }

        temp = s.vrhic;
    while (temp != nullptr) {
        cout << temp->element << " ";
        temp = temp->next;
    }
    cout << endl<<"Vrh ovog steka je: "<<s.vrh();

  
  return 0;
}