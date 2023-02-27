/* 3. (5 bodova)
Napisati kod funkcije čiji je prototip
bool isteCifre(const Lista<char>& l1, const Lista<char>& l2)
Primljene liste l1 i l2 sadrže različite elemente tipa char 
(cifre, slova, razmake itd.). Funkcija treba
vratiti true ako su cifre unutar obje liste date istim redoslijedom, 
a false ako nisu. Zanemariti znakove koji nisu cifre. Primjer: za sljedeće liste
5x?3.Ab C1z
yyyyyyy53 .,.,?1
funkcija treba vratiti true jer se u obje liste javljaju cifre 531 istim redoslijedom. 
*/

#include <iostream>
#include <vector>

using namespace std;

struct Cvor{
    public:
    char value;
    Cvor* next;
    Cvor(char v, Cvor* n){
        value=v;
        next=n;
    }
};

template <typename Tip>
class Lista{
    public:
    Cvor *pocetak, *kraj;
};

bool jeLiCifra(char n){
    if(n>='0' && n<='9') return true;
    return false;
}

bool isteCifre(const Lista<char> &l1, const Lista<char> &l2){
    if(l1.pocetak==nullptr){
        // obje liste prazne
        if(l2.pocetak==nullptr) return true;
        // da li druga lista ima cifara u sebi, ako da return false, ako ne return true
        Cvor *temp = l2.pocetak;
        vector<char> cifre;
        while(temp!=nullptr){
            if(jeLiCifra(temp->value)) cifre.push_back(temp->value);
            temp=temp->next;
        }
        if(cifre.empty()) return true;
        return false;
    }
    if(l2.pocetak==nullptr){
        // da li druga lista ima cifara u sebi, ako da return false, ako ne return true
        Cvor *temp = l1.pocetak;
        vector<char> cifre;
        while(temp!=nullptr){
            if(jeLiCifra(temp->value)) cifre.push_back(temp->value);
            temp=temp->next;
        }
        if(cifre.empty()) return true;
        return false;
    }
    Cvor *temp1 = l1.pocetak, *temp2 = l2.pocetak;
    vector<char> cifre1, cifre2;
    while(temp1!=nullptr){
        if(jeLiCifra(temp1->value)) cifre1.push_back(temp1->value);
        temp1=temp1->next;
    }
    while(temp2!=nullptr){
        if(jeLiCifra(temp2->value)) cifre2.push_back(temp2->value);
        temp2=temp2->next;
    }
    if(cifre1!=cifre2) return false;
    return true;
}

int main(){
    Lista<char> l1, l2, l3, l4;
    l1.pocetak = new Cvor('5',new Cvor('x', new Cvor('?', new Cvor('3', new Cvor('.', new Cvor('A', new Cvor('b', new Cvor(' ', new Cvor('C', new Cvor('1', new Cvor('z', nullptr)))))))))));
    l2.pocetak = new Cvor('y',new Cvor('y', new Cvor('y', new Cvor('5', new Cvor('3', new Cvor(' ', new Cvor('.', new Cvor('1', nullptr))))))));
    l3.pocetak = new Cvor('1', nullptr);
    l4.pocetak = new Cvor('1', nullptr);
    cout<<isteCifre(l3,l4)<<endl;
    return 0;
}

/*
    if(l1.pocetak==l1.kraj){
        char cifra1 = l1.pocetak->value, cifra2 = 0;
        int brojac = 0;
        Cvor *temp = l2.pocetak;
        while(temp!=nullptr){
            cifra2=temp->value;
            if(jeLiCifra(cifra2)){
                brojac++;
            }
            temp=temp->next;
        }
        if(brojac==1 && cifra1==cifra2) return true;
        return false; 
    }*/