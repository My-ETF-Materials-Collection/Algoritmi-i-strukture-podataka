#include <iostream>
using namespace std;

template <typename Tip>
struct Cvor{
    Tip element;
    Cvor<Tip> *prosli;
    Cvor<Tip> *sljedeci;
    Cvor(){}
    Cvor(const Cvor<Tip> &c): element(c->element), sljedeci(c->sljedeci), prosli(c->prosli){} 
    Cvor(const Tip &element, Cvor<Tip> *sljedeci, Cvor<Tip> *prosli): element(element), sljedeci(sljedeci), prosli(prosli){}
};

template <typename Tip>
class DvostraniRed{
    int brElemenata = 0;
    Cvor<Tip> *pocetak = nullptr, *kraj = nullptr;
    public: 
        DvostraniRed(){}
        DvostraniRed(const DvostraniRed<Tip> &dr){
            brElemenata = dr.brElemenata;
            Cvor<Tip> *temp = dr.pocetak;
            Cvor<Tip> *temp2 = new Cvor<Tip>;
            temp2->element = temp->element;
            pocetak = temp2;
            temp = temp->sljedeci;
            while(temp!=nullptr){
                temp2->sljedeci = new Cvor<Tip>;
                temp2->sljedeci->element = temp->element;
                temp2->sljedeci->prosli = temp2;
                temp = temp->sljedeci;
                temp2 = temp2->sljedeci;
            }
            kraj = temp2;
        }
        DvostraniRed &operator =(const DvostraniRed &dr){
            if(this==&dr) return *this;
            brisi();
            brElemenata = dr.brElemenata;
            Cvor<Tip> *temp = dr.pocetak;
            Cvor<Tip> *temp2 = new Cvor<Tip>;
            temp2->element = temp->element;
            pocetak = temp2;
            temp = temp->sljedeci;
            while(temp!=nullptr){
                temp2->sljedeci = new Cvor<Tip>;
                temp2->sljedeci->element = temp->element;
                temp2->sljedeci->prosli = temp2;
                temp = temp->sljedeci;
                temp2 = temp2->sljedeci;
            }
            kraj = temp2;
            return *this;
        }
        ~DvostraniRed(){ brisi(); }
        int brojElemenata(){ return brElemenata; }
        void brisi(){
            while(brElemenata>0){
                Cvor<Tip> *temp = pocetak;
                pocetak = pocetak->sljedeci;
                delete temp;
                temp = nullptr;
                brElemenata--;
            }
        }
        void staviNaVrh(const Tip &element){
            Cvor<Tip> *novi = new Cvor<Tip>(element, nullptr, nullptr);
            if(brElemenata==0) kraj = pocetak = novi;
            else{
                Cvor<Tip> *predKraj = kraj;
                kraj = novi;
                kraj->prosli = predKraj;
                predKraj->sljedeci = kraj;
            }
            brElemenata++;
        }
        void staviNaCelo(const Tip &element){
            Cvor<Tip> *novi = new Cvor<Tip>(element, nullptr, nullptr);
            if(brElemenata==0) pocetak = kraj = novi;
            else{
                Cvor<Tip> * predPocetak = pocetak;
                pocetak = novi;
                pocetak->sljedeci = predPocetak;
                predPocetak->prosli = pocetak;
            }
            brElemenata++;
        }
        Tip skiniSaVrha(){
            if(brElemenata==0) throw "Prazan dvostrani red";
            Tip vrhic = kraj->element;
            if(brElemenata==1){
                delete kraj;
                pocetak = nullptr;
                brElemenata = 0;
                return vrhic;
            }
            Cvor<Tip> *temp = kraj;
            kraj = kraj->prosli;
            delete temp;
            brElemenata--;
            return vrhic;
        }
        Tip skiniSaCela(){
            if(brElemenata==0) throw "Prazan dvostrani red";
            Tip celo = pocetak->element;
            if(brElemenata==1){
                delete pocetak;
                kraj = nullptr;
                brElemenata = 0;
                return celo;
            }
            Cvor<Tip> *temp = pocetak;
            pocetak = pocetak->sljedeci;
            delete temp;
            brElemenata--;
            return celo;
        }
        Tip &vrh(){
            if(brElemenata==0) throw "Prazan dvostrani red";
            return kraj->element;
        }
        Tip &celo(){
            if(brElemenata==0) throw "Prazan dvostrani red";
            return pocetak->element;
        }
};

int main(){
    DvostraniRed<int> dr;
    for(int i=15; i<70; i++) dr.staviNaVrh(i);
    cout<<dr.brojElemenata()<<endl;
    for(int i=0; i<dr.brojElemenata(); i++) {cout<<dr.vrh()<<" "; dr.skiniSaVrha();}
    cout<<endl;
    for(int i=0; i<dr.brojElemenata(); i++){cout<<dr.celo()<<" "; dr.skiniSaCela();}
    DvostraniRed<int> b(dr);
    for(int i=0; i<b.brojElemenata(); i++) b.staviNaCelo(i); cout<<endl;
    for(int i=0; i<b.brojElemenata(); i++) {cout<<b.vrh(); b.skiniSaCela();}
    b.brisi();
    return 0;
}