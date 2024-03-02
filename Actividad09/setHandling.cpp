#include <iostream>
#include <regex>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::vector;

void fill(vector<char> &v, int s);
bool validarChar(char ch);
bool validarElem(char ch, vector<char> const &v);
void print(vector<char> const &v);
void printSet(vector<char> const &v1, vector<char> const &v2);
void clear(vector<char> &v);
void clearSet(vector<char> &v1, vector<char> &v2);
void edit(vector<char> &v);
void del(vector<char> &v);

void fill(vector<char> &v, int s) {
  for (int i = 0; i < s; i++) {
    char input;
    cin >> input;
    while (!(validarChar(input) && validarElem(input, v))) {
      cout << "Elemento invalido. Intenta de nuevo\n";
      cin >> input;
    }
    v.push_back(input);
  }
  cout << "\n";
}
bool validarChar(char const ch) {
  regex re("[a-zA-Z0-9]");
  return std::regex_match(&ch, re);
}
bool validarElem(char ch, vector<char> const &v){
  bool flag = true;
  for(int i = 0; i < v.size(); i++){
    if(ch == v[i]){
      flag = false;
    }
  }
  return flag;
}
void print(vector<char> const &v) {
  cout << "{ ";
  for (auto n : v) {
    cout << n << " ";
  }
  cout << "}\n";
}
void printSet(vector<char> const &v1, vector<char> const &v2) {
  cout << "A = ";
  print(v1);
  cout << "B = ";
  print(v2);
}
void clear(vector<char> &v) { v.clear(); }
void clearSet(vector<char> &v1, vector<char> &v2) {
  clear(v1);
  clear(v2);
}
void edit(vector<char> &v) {
  print(v);
  int i;
  char elem;
  cout << "Numero de elemento que desea editar?" << endl;
  cin >> i;
  cout << "Ingrese el nuevo elemento" << endl;
  cin >> elem;
  v[--i] = elem;
}

void del(vector<char> &v) {
  print(v);
  int i;
  cout << "Numero de elemento que desea eliminar?" << endl;
  cin >> i;
  v.erase(v.begin() + --i);
}
