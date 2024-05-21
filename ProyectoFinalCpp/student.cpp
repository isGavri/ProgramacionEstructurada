#include "familia.cpp"
#include <unordered_map>

#define LEYENDA(a)                                                             \
  (a >= 90   ? "EXCELENTE"                                                     \
   : a >= 80 ? "MUY BIEN"                                                      \
   : a >= 60 ? "REGULAR"                                                       \
             : "REPROBADO")

class Student {
public:
  Student();
  Student(std::string, unsigned short int,
          std::unordered_map<std::string, double>, Family, std::string);

  std::string get_name();
  unsigned short int get_age();
  bool get_active();
  Family get_datos_familia();
  std::unordered_map<std::string, double> get_calificaciones();
  std::string get_group();
  double get_promedio();
  std::string get_leyenda();

  double set_promedio();

  void set_id(int);
  void set_name(const char *);
  void set_age(int);
  void set_calif(std::unordered_map<std::string, double>);
  void set_family_data(Family);
  void set_grupo(const char *);
  void set_promedio_n(double);
  void set_leyenda(const char *);

  void print_data();
  void print_calificaciones();
  ~Student();

private:
  unsigned int id;
  std::string name;
  unsigned short int age;
  std::unordered_map<std::string, double> calificaciones;
  Family datosFamilia;
  std::string group;
  double promedio;
  std::string leyenda;
  bool active;
};

Student::Student(std::string name_, unsigned short int age_,
                 std::unordered_map<std::string, double> calificaciones_,
                 Family datos_familia_, std::string group_)
    : datosFamilia(datos_familia_) {
  name = name_;
  age = age_;
  calificaciones = calificaciones_;
  group = group_;
  promedio = this->set_promedio();
  leyenda = LEYENDA(promedio);
  active = true;
}
Student::Student() { this->leyenda = LEYENDA(this->promedio); }
Student::~Student() {}

std::string Student::get_name() { return this->name; }
unsigned short int Student::get_age() { return this->age; }
bool Student::Student::get_active() { return this->active; }
Family Student::get_datos_familia() { return this->datosFamilia; }
std::unordered_map<std::string, double> Student::get_calificaciones() {
  return this->calificaciones;
}
std::string Student::get_group() { return this->group; }
double Student::get_promedio() { return this->promedio; }
std::string Student::get_leyenda() { return this->leyenda; }

double Student::set_promedio() {
  int i = 0;
  double sum = 0;
  for (auto x : this->calificaciones) {
    sum += x.second;
    i++;
  }
  this->promedio = sum / i;
  return sum / i;
}

void Student::set_id(int id_) { this->id = id_; }
void Student::set_name(const char *name_) { this->name = name_; }
void Student::set_age(int age_) { this->age = age_; }
void Student::set_calif(std::unordered_map<std::string, double> califs_) {
  this->calificaciones = califs_;
}
void Student::set_family_data(Family family_data_) {
  this->datosFamilia = family_data_;
}
void Student::set_grupo(const char *grupo_) { this->group = grupo_; }
void Student::set_promedio_n(double promedio_) { this->promedio = promedio_; }
void Student::set_leyenda(const char *leyenda_) { this->leyenda = leyenda_; }

void Student::print_calificaciones() {
  printf("- Calificaciones del estudiante\n");
  for (auto i : this->calificaciones) {
    printf("%s: %f\n", i.first.c_str(), i.second);
  }
};

void Student::print_data() {
  printf("- Datos del estudiante\n");
  printf("ID del estudiante: %u\n", this->id);
  printf("Nombre del estudiante: %s\n", this->name.c_str());
  printf("Edad del estudiante: %d\n", this->age);
  printf("Promedio del estudiante: %lf\n", this->promedio);
  printf("Leyenda del promedio: %s\n", this->leyenda.c_str());
  this->datosFamilia.print_data();
  this->print_calificaciones();
}
