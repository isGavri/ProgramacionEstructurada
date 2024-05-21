#include "student.c"
#include <cjson/cJSON.h>
#include <stdio.h>
void read_all() {
}
void add_to_the_database(student_t *s) {

  cJSON *json = cJSON_CreateObject();
  cJSON_AddStringToObject(json, "Nombre", s->name);
  cJSON_AddNumberToObject(json, "Edad", s->age);
  cJSON_AddStringToObject(json, "Grupo", s->group);

  cJSON *datos_familia = cJSON_CreateObject();
  cJSON_AddStringToObject(datos_familia, "Nombre", s->family_data.name);
  cJSON_AddStringToObject(datos_familia, "Relacion", s->family_data.relation);
  cJSON_AddStringToObject(datos_familia, "Numero", s->family_data.num);
  cJSON_AddItemToObject(json, "Datos de Familia", datos_familia);

  cJSON *materias = cJSON_CreateObject();
  cJSON_AddNumberToObject(materias, s->calificaciones[0].nombre,
                          s->calificaciones[0].calificacion);
  cJSON_AddNumberToObject(materias, s->calificaciones[1].nombre,
                          s->calificaciones[1].calificacion);
  cJSON_AddNumberToObject(materias, s->calificaciones[2].nombre,
                          s->calificaciones[2].calificacion);
  cJSON_AddNumberToObject(materias, s->calificaciones[3].nombre,
                          s->calificaciones[3].calificacion);
  cJSON_AddNumberToObject(materias, s->calificaciones[4].nombre,
                          s->calificaciones[4].calificacion);
  cJSON_AddItemToObject(json, "Materias", materias);

  char *json_str = cJSON_Print(json);

  FILE *db = fopen("database.json", "w");
  fputs(json_str, db);
  fclose(db);

  cJSON_free(json_str);
  cJSON_Delete(datos_familia);
  cJSON_Delete(materias);
  cJSON_Delete(json);
}
