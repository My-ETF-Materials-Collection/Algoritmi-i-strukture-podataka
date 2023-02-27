#include <iostream>
#include <vector>

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
class Red{
    Cvor<Tip>* pocetak;
    Cvor<Tip>* kraj;
    int velicina;
    public:
        Red() : velicina(0), pocetak(nullptr), kraj(nullptr){};
        void brisi(){
            while(velicina>0){
                Cvor<Tip> *temp = pocetak;
                pocetak = pocetak->next;
                delete temp;
                temp = nullptr;
                velicina--;
            }
        }
        ~Red(){brisi();} 
        void stavi(const Tip &r){
            Cvor<Tip> *novi = new Cvor<Tip>{r, nullptr};
            if(velicina==0){
                pocetak = kraj = novi;
            }else{
                kraj->next = novi;
                kraj = kraj->next;
            }velicina++;
        }
        Tip skini(){
            if(velicina==0) throw "Prazan red"; 
            Tip el = pocetak->element;
            Cvor<Tip> *p = pocetak;
            if(pocetak==kraj) pocetak = kraj = nullptr;
            else pocetak = pocetak->next;
            delete p;
            velicina--;
            return el;
        }
        Tip& celo() {if(velicina==0) throw "Prazan red"; return pocetak->element;}
        const Tip& celo() const {if(velicina==0) throw "Prazan red"; return pocetak->element;}
        int brojElemenata() const {return velicina;}
};

void Funkcija(Stek<int> &s, Red<int> &r) {
  // Base case: if either the queue or the stack is empty, return
  if (!r.brojElemenata() || !s.brojElemenata()) return;

  // Move first element of queue to the top of stack
  int x = r.celo();
  r.skini();
  s.stavi(x);

  // Recursive call
  Funkcija(s, r);
  // Move all elements from stack to queue
  while (s.brojElemenata()) {
    r.stavi(s.skini());
  }
}


int main() {
  // Initialize stack and queue
  Stek<int> s;
  s.stavi(4);
  s.stavi(5);
  s.stavi(6);

  Red<int> r;
  r.stavi(1);
  r.stavi(2);
  r.stavi(3);

    // Print the modified stack and queue
  std::cout << "Original stack: ";
  while (s.brojElemenata()) {
    std::cout << s.skini() << " ";
  }
  std::cout << std::endl;

  std::cout << "Original queue: ";
  while (r.brojElemenata()) {
    std::cout << r.celo() << " ";
    r.skini();
  }
  std::cout << std::endl;
    s.stavi(4);
    s.stavi(5);
    s.stavi(6);

    r.stavi(1);
    r.stavi(2);
    r.stavi(3);
    cout<<endl<<"Vrh steka je "<<s.vrh()<<" i celo reda je "<<r.celo()<<endl;
  // Call the function
  Funkcija(s, r);

  // Print the modified stack and queue
  std::cout << "Modified stack: ";
  while (s.brojElemenata()) {
    std::cout << s.skini() << " ";
  }
  std::cout << std::endl;

  std::cout << "Modified queue: ";
  while (r.brojElemenata()) {
    std::cout << r.celo() << " ";
    r.skini();
  }
  std::cout << std::endl;

  return 0;
}