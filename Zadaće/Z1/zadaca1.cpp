#include <iostream>

using namespace std;

template <typename Tip>
class Lista{
    public:
        Lista(){}
        virtual ~Lista(){}
        virtual int brojElemenata() const = 0;
        virtual Tip& trenutni() = 0;
        virtual const Tip& trenutni() const = 0;
        virtual bool prethodni() = 0;
        virtual bool sljedeci() = 0;
        virtual void pocetak() = 0;
        virtual void kraj() = 0;
        virtual void obrisi() = 0;
        virtual void dodajIspred(const Tip& element) = 0;
        virtual void dodajIza(const Tip& element) = 0;
        virtual Tip& operator [](int pozicija) = 0;
        virtual const Tip& operator [](int pozicija) const = 0;
};

template <typename Tip>
class DvostrukaLista : public Lista<Tip> {
    struct Cvor{
        Tip element;
        Cvor *prosli, *sljedeci;
    };
    int brElemenata;
    Cvor *pocetni, *krajnji, *tekuci;
    public: 
        DvostrukaLista(): Lista<Tip>(), pocetni(nullptr), krajnji(nullptr), tekuci(nullptr), brElemenata(0){}
        ~DvostrukaLista(){
            while(pocetni!=nullptr){
                tekuci = pocetni;
                pocetni = pocetni->prosli;
                tekuci->prosli = tekuci->sljedeci = nullptr;
                delete tekuci;
            }
        }
        DvostrukaLista(const DvostrukaLista &dl){
            brElemenata = dl.brElemenata;
            Cvor *temp = dl.pocetni, *temp2 = nullptr;
            while(temp!=nullptr){
                Cvor *novi = new Cvor{temp->element, nullptr, nullptr};
                if(temp2==nullptr) pocetni = novi;
                else{
                    novi->sljedeci = temp2;
                    temp2->prosli = novi;
                }
                temp2 = novi;
                if(temp==dl.tekuci) tekuci = novi;
                temp = temp->prosli;
            }
            krajnji = temp2;
        }
        DvostrukaLista& operator =(const DvostrukaLista &dl){
            if(&dl == this) return *this;
            while(pocetni!=nullptr){
                tekuci = pocetni;
                pocetni = pocetni->prosli;
                tekuci->prosli = tekuci->sljedeci = nullptr;
                delete tekuci;
            }
            brElemenata = dl.brElemenata;
            Cvor *temp = dl.pocetni, *temp2 = nullptr;
            while(temp!=nullptr){
                Cvor *novi = new Cvor{temp->element, nullptr, nullptr};
                if(temp2==nullptr) pocetni=novi;
                else{
                    novi->sljedeci=temp2;
                    temp2->prosli=novi;
                }
                temp2=novi;
                if(temp==dl.tekuci) tekuci=novi;
                temp=temp->prosli;
            }
            krajnji = temp2;
            return *this;
        }
        int brojElemenata() const override{
            return brElemenata;
        }
        Tip& trenutni() override{
            if(pocetni==nullptr) throw "Prazna lista";
            return tekuci->element;
        }
        const Tip& trenutni() const override{
            if(pocetni==nullptr) throw "Prazna lista";
            return tekuci->element;
        }
        bool prethodni() override{
            if(pocetni==nullptr) throw "Prazna lista";
            if(tekuci==pocetni) return false;
            tekuci = tekuci->sljedeci;
            return true;
        }
        bool sljedeci() override{
            if(pocetni==nullptr) throw "Prazna lista";
            if(tekuci==krajnji) return false;
            tekuci = tekuci->prosli;
            return true;
        }
        void pocetak() override{
            tekuci = pocetni;
        }
        void kraj() override{
            tekuci = krajnji;
        }
        void obrisi() override{
            if(pocetni==nullptr) throw "Prazna lista";
            brElemenata--;
            if(tekuci==pocetni){
                tekuci = pocetni->prosli;
                pocetni->prosli = nullptr;
                delete pocetni;
                pocetni = tekuci;
            }else{
                Cvor *temp = tekuci->sljedeci;
                temp->prosli = tekuci->prosli;
                delete tekuci;
                tekuci = temp->prosli;
                if(tekuci==nullptr){
                    krajnji = tekuci = temp;
                }
            }
        }
        void dodajIspred(const Tip &element) override{
            if(pocetni==nullptr){
                Cvor *novi = new Cvor{element, nullptr, nullptr};
                pocetni = tekuci = krajnji = novi;
            }else if(tekuci==pocetni){
                Cvor *novi = new Cvor{element, pocetni, nullptr};
                tekuci->sljedeci = novi;
                pocetni = novi;
            }else{
                Cvor *temp = tekuci->sljedeci;
                Cvor *temp2 = new Cvor{element, tekuci, tekuci->sljedeci};
                temp->prosli = temp2;
                tekuci->sljedeci = temp2;
            }   
            brElemenata++;
        }
        void dodajIza(const Tip  &element) override{
            if(pocetni==nullptr){
                Cvor *novi = new Cvor{element, nullptr, nullptr};
                pocetni = tekuci = krajnji = novi;
            }else{
                Cvor *temp = tekuci->prosli;
                Cvor *temp2 = new Cvor{element, tekuci->prosli, tekuci};
                tekuci->prosli = temp2;
                if(tekuci!=krajnji) temp->sljedeci = temp2;
                else if(tekuci==krajnji) krajnji = temp2;
            }   
            brElemenata++;
        }
        Tip& operator [](int pozicija) override{
            if(pozicija<0 || pozicija>=brElemenata) throw "Neispravan index";
            Cvor *temp(pocetni);
            for(int i=0; i<pozicija; i++) temp = temp->prosli;
            return temp->element;
        }
        const Tip& operator [](int pozicija) const override{
            if(pozicija<0 || pozicija>=brElemenata) throw "Neispravan index";
            Cvor *temp(pocetni);
            for(int i=0; i<pozicija; i++) temp = temp->prosli;
            return temp->element;
        }
};

template <typename Tip>
Tip dajMaksimum(const Lista<Tip> &l){
    DvostrukaLista<Tip> dl (static_cast<DvostrukaLista<Tip>&>(const_cast<Lista<Tip>&>(l)));
    dl.pocetak();
    Tip max = dl.trenutni();
    dl.sljedeci();
    for(int i=0; i<dl.brojElemenata(); i++){
        if(max<dl.trenutni()) max = dl.trenutni();
        dl.sljedeci();
    }
    return max;
}

int main(){
    Lista<int> *l;
    l = new DvostrukaLista<int>;
    for(int i=0; i<100; i++) l->dodajIspred(i);
    l->pocetak();
    cout<<l->trenutni()<<endl;
    for(int i=0; i<l->brojElemenata(); i++) {cout<<l->trenutni()<<" "; l->sljedeci();}
    cout<<l->brojElemenata()<<endl;
    Lista<string> *a;
    a = new DvostrukaLista<string>;
    a->dodajIspred("hana"); a->dodajIza("mahmutovic");
    cout<<a->trenutni();
    a->prethodni(); a->sljedeci();
    cout<<a->trenutni();
    a->obrisi();
    cout<<endl<<a->brojElemenata();
    Lista<int> *b;
    b = new DvostrukaLista<int>;
    for(int i=0; i<10; i++) b->dodajIspred(i);
    cout<<endl<<dajMaksimum(*b);
    b->pocetak();
    cout<<endl<<b->trenutni()<<" ";
    b->kraj();
    cout<<b->trenutni();
    (b=l)->brojElemenata();
    cout<<endl<<b->brojElemenata();
    b->obrisi();
    l=b;
    cout<<endl<<l->brojElemenata();
    return 0;
}