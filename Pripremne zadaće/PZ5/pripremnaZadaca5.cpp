#include <iostream>
using namespace std;

int fib_petlja(int n){
    if(n<=1) return n;
    int pretprosli(0), prosli(1), rezultat;
    for(int i(2); i<=n; i++){
        rezultat = pretprosli + prosli;
        pretprosli = prosli;
        prosli = rezultat;
    }
    return rezultat;
}

int fib2_0(int n, int prosli=1, int pretprosli=0, int rezultat=0){
    if(n<=1) return rezultat;
    rezultat = prosli + pretprosli;
    pretprosli = prosli;
    prosli = rezultat;
    return fib2_0(n-1, prosli, pretprosli, rezultat);
}

int nzd(int x, int y){
    if(!y) return x;
    return nzd(y, x%y);
}

int main(){

    //nti clan Fibbonacijevog niza
    cout<<fib_petlja(5)<<" "<<fib_petlja(6)<<" "<<fib_petlja(7)<<endl;

    //rekurzivno nti clan Fibbonacijevog niza
    cout<<"Rekurzivno nađen nti član Fibbonacijevog niza: ";
    int n;
    cin>>n;
    cout<<fib2_0(n)<<endl;

    //rekurzivno nađen NZD(x,y)
    cout<<"Rekurzivno nađen NZD(x,y): ";
    int x,y;
    cin>>x>>y;
    cout<<nzd(x,y);

    return 0;
}