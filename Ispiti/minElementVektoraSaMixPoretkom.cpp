#include <iostream>
#include <vector>

using namespace std;

int findMinElement(const vector<int> &V) {
  int min = V[0];
  int pivot = V[V.size() - 1];
  for (int i = V.size() - 1; i >= 0; i--) {
    if (V[i] > pivot) {
      pivot = V[i];
    } else if (V[i] < min) {
      min = V[i];
    }
  }
  return min;
}

int main() {
  vector<int> V = {10, 9, 8, 7, 6, 5, 4, 2, 3, 11, 15};
  cout << "Min element: " << findMinElement(V) << endl;
  return 0;
}

template <typename Tip>
int minElement(const vector<Tip> &v){
    Tip min=v.at(0), pivot = v.at(v.size()-1);
    for(int i=v.size()-1; i>=0; i--){
        if(v.at(i)>pivot){
            pivot = v.at(i);
        }else if(v.at(i)<min){
            min = v.at(i);
        }
    }
    return min;
}
























