#include <iostream>

using namespace std;

template <typename Tip>
struct Cvor{
    Tip element;
    Cvor<Tip> *next;
};

template <typename Tip>
class Red{
    Cvor<Tip>* pocetak;
    Cvor<Tip>* kraj;
    int velicina;
    public:
        Red() : velicina(0), pocetak(nullptr), kraj(nullptr){};
        Red(const Red<Tip> &r){
            velicina = r.velicina;
            auto temp = r.pocetak;
            auto klizni = pocetak = nullptr;
            for(;temp;){
                if(!pocetak){
                    pocetak = new Cvor<Tip> {temp->element, nullptr};
                    klizni = pocetak;
                    temp = temp->next;
                    kraj = pocetak;
                }else{
                    klizni->next = new Cvor<Tip> {temp->element, nullptr};
                    klizni = klizni->next;
                    kraj = klizni;
                    temp = temp->next;
                }
            }
        }
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
        Red &operator =(const Red &r){
            if(&r!=this){
                brisi();
                Cvor<Tip> *kopija = r.pocetak;
                while(kopija!=nullptr){
                    stavi(kopija->element);
                    kopija = kopija->next;
                }
            }
            return *this;
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

int main(){
    Red<int> r;
    for(int i=1; i<10; i++) r.stavi(i);
    for(int i=0; i<r.brojElemenata(); i++) {cout<<r.celo()<<" "; r.skini();}
    r.brisi();
    cout<<"Broj elemenata reda je "<<r.brojElemenata()<<endl;
    r.stavi(5); r.stavi(10); r.stavi(3); 
    Red<int> a(r); a.skini();
    for(int i=0; i<a.brojElemenata(); i++) {cout<<a.celo()<<" "; a.skini();}
 //desi se da kao i u prethodnoj zadaci pri skidanju da se smanji velicina za 1 pa ujedno i petlja ide za manji broj 
    cout<<endl<<a.celo();
    (a=r).brojElemenata();
    cout<<endl<<a.brojElemenata();
    return 0;
}