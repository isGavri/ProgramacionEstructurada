#include <string>
float suma(float a,float b){
  return a + b;
}
//bool valida(char car){
  //return car == 64 ? true : false;
//}
std::string valida(char ch){
  return (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ? "True" : "False";
}
