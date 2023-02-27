/* 2. (5 bodova)
U klasi Lista (datoj u prilogu) implementirati novu metodu
void dodajSortirano(const Tip& el)
koja u Listu ubacuje element na odgovarajuće mjesto tako da 
elementi u listi ostaju sortirani u rastućem poretku. 
Pretpostaviti da je prilikom poziva lista sortirana, 
odnosno metoda je besmislena ako su prethodno korištene metode Dodaj i Umetni. 
Takođe pretpostaviti da Tip podržava operatore poređenja.
*/

template <typename tip>
struct Cvor{
    int x;
    Cvor* next;
};

template <typename tip>
void dodajSortirano(const tip &el){
    Cvor<tip> *pocetak, *kraj, *tekuci, *novi = new Cvor<tip>();
    novi->x=el;
    if(pocetak==nullptr){
        pocetak=kraj=novi;
        return;
    } 
    if(el<=pocetak->x){
        novi->next = pocetak;
        pocetak = novi;
        return;
    }
    if(el>kraj->x){
        kraj->next = novi;
        kraj = novi;
        return;
    }
    tekuci = pocetak;
    while(el<tekuci->next->x){
        tekuci = tekuci->next;
    }
    novi->next = tekuci->next;
    tekuci->next = novi;
    return;
}

int main(){
    return 0;
}


