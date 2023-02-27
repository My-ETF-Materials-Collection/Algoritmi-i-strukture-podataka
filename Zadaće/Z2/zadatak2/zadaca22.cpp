#include <iostream>
#include <vector>

using namespace std;

template <typename Tip>
struct Cvor{
        Tip element;
        Cvor* sljedeci;
};

template <typename Tip>
class Stek{
    int brElemenata;
    Cvor<Tip>* vrhic;
    public:
        Stek(){
            vrhic = nullptr, brElemenata = 0;
        }
        ~Stek(){
            brisi();
        }
        Stek(const Stek<Tip> &s){
            if(s.brElemenata==0){
                vrhic = nullptr;
                brElemenata = 0;
            }else{
                vrhic = new Cvor<Tip>{s.vrhic->element, nullptr};
                auto temp = s.vrhic;
                temp = s.vrhic->sljedeci;
                auto klizni = vrhic;
                for(;temp;){
                    klizni->sljedeci = new Cvor<Tip>{temp->element, nullptr};
                    klizni = klizni->sljedeci;
                    temp = temp->sljedeci;
                }
                brElemenata = s.brElemenata;
            }
        }
        Stek<Tip> &operator =(const Stek<Tip> &s){
            if(this==&s) return *this;
            Stek<Tip> a = s;
            auto temp = vrhic;
            vrhic = a.vrhic;
            a.vrhic = temp;
            auto temp2 = brElemenata;
            brElemenata = a.brElemenata;
            a.brElemenata = temp2;
            return *this;
        }
        void brisi(){
            auto x = vrhic;
            for(; vrhic; ){
                x = vrhic;
                vrhic = vrhic->sljedeci;
                delete x;
            }
            brElemenata = 0;
        }
        void stavi(const Tip& element){
            try{
                auto temp = new Cvor<Tip>{element, vrhic};
                vrhic = temp;
                brElemenata++;
            }catch(...){
                auto x = vrhic;
                for(;vrhic;){
                    x = vrhic;
                    vrhic = vrhic->sljedeci;
                    delete x;
                }
                throw "Nema dovoljno memorije";
            }
        }
        Tip skini(){
            if(brElemenata==0) throw "Prazan stek";
            Tip a = vrhic->element;
            auto temp = vrhic;
            vrhic = vrhic->sljedeci;
            delete temp;
            brElemenata--;
            return a;
        }
        Tip& vrh(){
            if(brElemenata==0) throw "Prazan stek";
            return vrhic->element;
        }
        int brojElemenata() const{
            return brElemenata;
        }
};

void pretraga(Stek<vector<int>> &s, int trazeni){
    if(s.brojElemenata()==0){
        cout<<"Nema elementa"; return;
    }
    auto p = s.vrh();
    int pocetak = 0, kraj = p.size();
    if(p.size()!=0){
        if(p.at(0)==trazeni){
            cout<<"0"<<" "<<s.brojElemenata()-1; return;
        }
        while(pocetak<kraj){
            int sredina = (pocetak+kraj)/2;
            if(sredina<0 || sredina>p.size()) break;
            if(p.at(sredina)==trazeni){
                cout<<sredina<<" "<<s.brojElemenata()-1; return;
            }else if(p.at(sredina)<trazeni) pocetak = sredina+1; 
            else kraj = sredina-1;
        }
    }
    auto a = s.skini();
    pretraga(s, trazeni);
    s.stavi(a);
}

int main(){
    Stek<int> s;
    for(int i=20; i<100; i*=2){
        s.stavi(i);
    }
    cout<<s.brojElemenata()<<endl;
    for(int i=0; i<s.brojElemenata(); i++) {cout<<s.vrh()<<" "; s.skini();}
    Stek<vector<int>> b;
    vector<int> a;
    for(int i=10; i<50; i++){
        a.push_back(i);
    }
    cout<<endl;
    b.stavi(a);
    pretraga(b, 3); cout<<endl;
    pretraga(b, 11);
    return 0;
}