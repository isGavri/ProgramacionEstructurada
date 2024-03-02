#include <vector>

using std::vector;

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
  result.insert(result.begin(), v1.begin(), v1.end());
  result.insert(result.end(), v2.begin(), v2.end());
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
