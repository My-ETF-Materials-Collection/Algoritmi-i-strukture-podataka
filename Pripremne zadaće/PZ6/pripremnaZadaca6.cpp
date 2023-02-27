#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename Tip1, typename Tip2>
class Mapa{
    public:
        //konstruktor bez parametara
        Mapa(){};
        //destruktor
        virtual ~Mapa(){};
        //preklopljeni operator nekonstantna varijanta
        virtual Tip2& operator[](const Tip1 &kljuc)=0;
        //preklopljeni operator konstantna varijanta
        virtual const Tip2& operator[](const Tip1 &kljuc) const = 0;
        //broj elemenata
        virtual int brojElemenata() const = 0;
        //metoda koja brise sve elemente iz mape
        virtual void obrisi() = 0;
        //metoda koja obrise samo jedan element iz mape
        virtual void obrisi(const Tip1& kljuc) = 0;
};

template <typename Tip1, typename Tip2>
class NizMapa : public Mapa<Tip1,Tip2> {
            int brElemenata, kapacitet;
            Tip2 p;
            pair<Tip1,Tip2> *niz = nullptr;
            void alocirajNiz(){
                pair<Tip1,Tip2> *helper = new pair<Tip1,Tip2> [2*kapacitet];
                for(int i=0; i<brElemenata; i++){
                    helper[i].first = niz[i].first;
                    helper[i].second = niz[i].second;
                }
                delete[] niz;
                niz = helper;
                helper = nullptr;
            }
        public:
            NizMapa(): kapacitet(1000), brElemenata(0), niz(new pair<Tip1,Tip2>[kapacitet]), p(Tip2()){}
            ~NizMapa(){delete[] niz;}
            NizMapa(const NizMapa<Tip1,Tip2> &nm): kapacitet(nm.kapacitet), brElemenata(nm.brElemenata), niz(new pair<Tip1,Tip2>[kapacitet]){
                for(int i=0; i<brElemenata; i++){
                    niz[i].first = nm.niz[i].first;
                    niz[i].second = nm.niz[i].second;
                }
            }
            NizMapa<Tip1,Tip2> &operator =(const NizMapa<Tip1,Tip2> &nm){
                if(this==&nm) return *this;
                delete[] niz;
                kapacitet = nm.kapacitet;
                brElemenata = nm.brElemenata;
                niz = new pair<Tip1, Tip2>[kapacitet];
                for(int i=0; i<brElemenata; i++){
                    niz[i].first=nm.niz[i].first;
                    niz[i].second=nm.niz[i].second;
                }
                return *this;
            }
            Tip2& operator[](const Tip1 &kljuc){
                for(int i=0; i<brElemenata; i++){
                    if(niz[i].first==kljuc) return niz[i].second;
                }
                if(brElemenata==kapacitet) alocirajNiz();
                niz[brElemenata]=pair<Tip1,Tip2>(kljuc, Tip2());
                return niz[brElemenata++].second;
            }
            const Tip2& operator[](const Tip1 &kljuc) const{
                for(int i=0; i<brElemenata; i++){
                    if(niz[i].first==kljuc) return niz[i].second;
                }
                return p;
            }
            int brojElemenata() const{ return brElemenata; }
            void obrisi(const Tip1 &kljuc){
                    for(int i=0; i<brElemenata; i++){
                        if(niz[i].first==kljuc){
                            niz[i].first = niz[brElemenata-1].first;
                            niz[i].second = niz[brElemenata-1].second;
                            brElemenata--;
                            return;
                        }
                    }
                    throw("Nije pronadjen element");
            }
            void obrisi(){
            brElemenata=0;
            }
};

void Test1(){
    NizMapa<string, string> nm;
    nm["hmahmutovic3"]="Hana Mahmutović";
    cout<<nm.brojElemenata();
}

void Test2(){
    NizMapa<int, int> nm;
    for(int i=0; i<5; i++){
        nm[i]=i;
    }
    nm.obrisi(4);
    cout<<nm.brojElemenata();
}

void Test3(){
    NizMapa<string, double> nm;
    nm["asp_z1"]=123;
    nm["asp_z2"]=456;
    nm["asp_z3"]=789;
    cout<<(nm["asp_z2"]-5)<<1;
}

void Test4(){
    NizMapa<int, char> nm;
    for(int i=0; i<5; i++){
        nm[i]=(char)i;
    }
    nm.obrisi();
    if(nm.brojElemenata()==0){cout<<"Nema elemenata"; return;}
    cout<<"Ima elemenata";
}

void Test5(){
    NizMapa<string, string> nm;
    nm["hmahmutovi3"]="Hana Mahmutovic";
    nm["hmahmutovi3"]="Hanci Mahmutovic";
    NizMapa<string, string> nm1(nm);
    if(nm1.brojElemenata()==2){cout<<"Imaju 2 elementa"; return;}
    cout<<"Nema 2 elementa, elementi su: ";
    for(auto x: nm1["hmahmutovi3"]){
        cout<<x<<" ";
    }
}

void Test6(){
    NizMapa<double, vector<double>> nm;
    nm[0]={1,2,3};
    for(auto x: nm[0]){
        cout<<x<<" ";
    }
}

int main(){
Test1(); cout<<endl;
Test2(); cout<<endl;
Test3(); cout<<endl;
Test4(); cout<<endl;
Test5(); cout<<endl;
Test6(); cout<<endl;
return 0;
}