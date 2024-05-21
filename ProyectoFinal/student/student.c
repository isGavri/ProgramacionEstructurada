struct Materia {
  char* nombre;
  float calificacion;
};
struct Familia {
  char* name;
  char* relation;
  char* num;
};
typedef struct Student {
  char* name;
  int age;
  char* group;
  struct Familia family_data;
  struct Materia calificaciones[5];
  float promedo;
} student_t;
