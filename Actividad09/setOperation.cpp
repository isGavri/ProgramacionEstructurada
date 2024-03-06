#include <vector>

using std::vector;

bool validar(char ch, vector<char> const &v);
vector<char> inter(vector<char> const &v1, vector<char> const &v2) {
  vector<char> result;
  for (auto i : v1) {
    for (auto j : v2) {
      if (i == j) {
        result.push_back(i);
      }
    }
  }
  return result;
}
vector<char> uni(vector<char> const &v1, vector<char> const &v2) {
  vector<char> result;
  for (auto i : v1) {
    if (validar(i, result)) {
      result.push_back(i);
    }
  }
  for (auto i : v2) {
    if (validar(i, result)) {
      result.push_back(i);
    }
  }
  return result;
}
vector<char> dif(vector<char> const &v1, vector<char> const &v2) {
  vector<char> result;
  vector<char> intrsc = inter(v1, v2);
  for (auto i : v1) {
    bool flag = true;
    for (auto j : intrsc) {
      if (i == j) {
        flag = false;
      }
    }
    if (flag == true) {
      result.push_back(i);
    }
  }
  return result;
}

vector<char> comp(vector<char> const &v1, vector<char> const &v2) {
  return dif(v2, v1);
}
bool validar(char ch, vector<char> const &v) {
  bool flag = true;
  for (int i = 0; i < v.size(); i++) {
    if (ch == v[i]) {
      flag = false;
    }
  }
  return flag;
}
