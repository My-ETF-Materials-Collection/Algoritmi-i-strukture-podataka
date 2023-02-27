#include <iostream>
#include <vector>

using namespace std;

vector<int> countingSort(const vector<int> &v){
    vector<int> c(10,0);
    for(int i=0; i<v.size(); i++){
        c.at(v.at(i))++;
    }
    for(int i=1; i<c.size(); i++){
        c.at(i)+=c.at(i-1);
    }
    vector<int> b(v.size(),0);
    for(int i=v.size()-1; i>=0; i--){
        c.at(v.at(i))--; 
        b.at(c.at(v.at(i))) = v.at(i);
    }
    return b;
}


int main(){
    vector<int> a={8,5,7,5,3,9,4,5,6,9};
    for(auto el: countingSort(a)){
        cout<<el<<" ";
    }
    return 0;
}
