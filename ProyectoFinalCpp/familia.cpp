#include <cstdio>
#include <string>

class Family {
public:
  Family();
  Family(std::string, std::string, std::string);
  std::string get_name();
  std::string get_relation();
  std::string get_num();
  void set_name(const char*);
  void set_relation(const char*);
  void set_num(const char*);
  void print_data();
  ~Family();

private:
  std::string name;
  std::string relation;
  std::string num;
};

Family::Family(std::string name_, std::string relation_, std::string num_) {
  name = name_;
  relation = relation_;
  num = num_;
}
Family::Family(){

}
void Family::set_name(const char* name_){
  this->name = name_;
}
void Family::set_relation(const char* relation_){
  this->relation = relation_;
}
void Family::set_num(const char* num_){
  this->num = num_;
}
Family::~Family() {}
std::string Family::get_name(){
  return this->name;
}
std::string Family::get_relation(){
  return this->relation;
}
std::string Family::get_num(){
  return this->num;
}
void Family::print_data() {
  printf("- Datos de la familia\n");
  printf("Nombre de familiar: %s\n", name.c_str());
  printf("Relacion con el alumno: %s\n", relation.c_str());
  printf("Numero telefonico: %s\n", num.c_str());
}
