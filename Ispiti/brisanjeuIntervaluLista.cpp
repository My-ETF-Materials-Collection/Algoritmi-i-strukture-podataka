#include <iostream>

using namespace std;

template <typename Tip> struct Cvor {
public:
  Tip element;
  Cvor<Tip> *next;
  Cvor(Tip v, Cvor *n) {
    element = v;
    next = n;
  }
};

template <typename Tip> class Lista {
public:
  Cvor<Tip> *pocetak, *kraj, *trenutni;
  int brElemenata;
  int brojElemenata(){ 
        if(pocetak!=nullptr && brElemenata==0){
            auto temp=pocetak;
            while(temp!=nullptr){ temp=temp->next; brElemenata++; }
        }
        return brElemenata; 
    }
  void Metoda(Cvor<Tip> *a, Cvor<Tip> *b) {
    // metoda za brisanje elemenata iz liste od cvora A do cvora B, ukljucujuci
    // B, ne ukljucujuci A (1 2 3 4 5 6 7-> 1 2 6 7  ako se daju cvorovi od 2 do 5)
    Cvor<Tip> *temp = pocetak;
    while (temp != nullptr && temp != a)
      temp = temp->next;
    if (temp == nullptr)
      return; // A not found in the list
    Cvor<Tip> *temp2 = temp->next;
    while (temp2 != nullptr && temp2 != b) {
      Cvor<Tip> *temp3 = temp2;
      temp2 = temp2->next;
      delete temp3;
      brElemenata--;
    }
    if (temp2 == nullptr)
      return; // B not found in the list
    temp->next = temp2->next;
    delete temp2;
    brElemenata--;
  }
void Metoda2(Cvor<Tip> *a, Cvor<Tip> *b){
    // metoda za brisanje elemenata iz liste od cvora A do cvora B, ukljucujuci
    // i A i B  (1 2 3 4 5 6 7-> 1 6 7  ako se daju cvorovi od 2 do 5)
    Cvor<Tip> *temp = pocetak, *previous=nullptr;
    while(temp != nullptr && temp != a){ previous=temp; temp = temp->next;}
    if(temp == nullptr) return; // A not found in the list

    Cvor<Tip> *temp2 = temp;
    while(temp2 != nullptr && temp2 != b) {
        Cvor<Tip> *temp3 = temp2;
        temp2 = temp2->next;
        delete temp3;
        brElemenata--;
    }
    if(temp2 == nullptr) return; // B not found in the list

    // Add this line of code to delete node B
    Cvor<Tip> *temp3 = temp2;
    temp2 = temp2->next;
    if(previous!=nullptr) previous->next=temp3->next;
    else pocetak=temp3->next;
    delete temp3;
    brElemenata--;
}


};

int main() {

  Lista<char> lista, lista2;
  lista.pocetak = new Cvor<char>(
      '5',
      new Cvor<char>(
          'x',
          new Cvor<char>(
              '?',
              new Cvor<char>(
                  '3',
                  new Cvor<char>(
                      '.',
                      new Cvor<char>(
                          'A',
                          new Cvor<char>(
                              'b',
                              new Cvor<char>(
                                  ' ',
                                  new Cvor<char>(
                                      'C', new Cvor<char>(
                                               '1', new Cvor<char>(
                                                        'z', nullptr)))))))))));
  lista2.pocetak = new Cvor<char>(
      '1',
      new Cvor<char>(
          '2', new Cvor<char>(
                   '3', new Cvor<char>('4', new Cvor<char>('5', nullptr)))));
  cout << "List before deletion: ";
  Cvor<char> *temp = lista2.pocetak;
  while (temp != nullptr) {
    cout << temp->element << " ";
    temp = temp->next;
  }
  cout << endl;
  cout<<"Number of elements before deletion: "<<lista2.brojElemenata()<<endl;

  lista2.Metoda2(lista2.pocetak->next, lista2.pocetak->next->next->next);
cout << endl;
  cout << "List after deletion: ";
  temp = lista2.pocetak;
  while (temp != nullptr) {
    cout << temp->element << " ";
    temp = temp->next;
  }
  cout<<endl;
  cout<<"Number of elements after deletion: "<<lista2.brojElemenata();

  return 0;
}