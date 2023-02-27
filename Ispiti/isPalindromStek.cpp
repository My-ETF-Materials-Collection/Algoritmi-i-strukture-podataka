#include <iostream>
#include <stack>
using namespace std;

bool is_palindrom(string s) {
  stack<char> stek;
  int n = s.length();
  for (int i = 0; i < n / 2; i++) {
    stek.push(s[i]);
  }
  for (int i = (n + 1) / 2; i < n; i++) {
    char c = stek.top();
    stek.pop();
    if (c != s[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  string s;
  cout << "Unesite string: ";
  cin >> s;
  if (is_palindrom(s)) {
    cout << "String je palindrom" << endl;
  } else {
    cout << "String nije palindrom" << endl;
  }
  return 0;
}
