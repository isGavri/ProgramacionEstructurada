#include "student.cpp"
#include <iostream>
#include <mariadb/conncpp.hpp>
#include <unistd.h>

void list_by_id(int id);
void insert(Student *new_student);

// Funcion para obtener conexion a la base de datos

std::unique_ptr<sql::Connection> get_conection() {
  try {
    sql::SQLString url(
        "jdbc:mariadb://localhost:3306/siiau_db?user=notsy&password=12345");
    std::unique_ptr<sql::Connection> con(
        sql::DriverManager::getConnection(url));
    return con;
  } catch (...) {
    std::cerr << "Fallo en la conexion a la base de datos" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Funcion para listar todos los alumnos del registro

void list_all() {
  std::unique_ptr<sql::Connection> con = get_conection();
  try {
    std::shared_ptr<sql::Statement> statement(con->createStatement());
    std::unique_ptr<sql::ResultSet> res(
        statement->executeQuery("SELECT * FROM students WHERE active = 1"));

    while (res->next()) {

      int id = res->getInt("id");

      printf("*** --- Datos del estudiante --- ***\n");
      printf("- ID del estudiante: %d\n", id);
      printf("- Nombre del estudiante: %s\n", res->getString("name").c_str());
      printf("- Edad del estudiante: %d\n", res->getInt("age"));
      printf("- Promedio del estudiante: %.2Lf\n",
             res->getDouble("promedio_n"));
      printf("- Rendimiento: %s\n", res->getString("promedio").c_str());

      std::shared_ptr<sql::PreparedStatement> statement_family_data(
          con->prepareStatement(
              "SELECT * FROM datos_familia WHERE student_id = ?"));
      statement_family_data->setInt(1, id);
      std::unique_ptr<sql::ResultSet> result_family_data(
          statement_family_data->executeQuery());

      while (result_family_data->next()) {
        printf("*** --- Datos de la familia --- ***\n");
        printf("- Nombre del familiar: %s\n",
               result_family_data->getString("name").c_str());
        printf("- Relacion con el alumno: %s\n",
               result_family_data->getString("relation").c_str());
        printf("- Numero telefonico: %s\n",
               result_family_data->getString("phone_number").c_str());
      }

      std::shared_ptr<sql::PreparedStatement> statement_calif(
          con->prepareStatement("SELECT * FROM grades WHERE student_id = ?"));
      statement_calif->setInt(1, id);
      std::unique_ptr<sql::ResultSet> result_calif(
          statement_calif->executeQuery());

      printf("*** --- Calificaciones --- ***\n");
      while (result_calif->next()) {
        printf("%s: %.2Lf\n", result_calif->getString("class").c_str(),
               result_calif->getDouble("grades"));
      }
      printf("\n");
    }

  } catch (sql::SQLException &e) {
    std::cerr << "Fallo al listar los elementos: " << e.what() << std::endl;
    con->close();
  }
  con->close();
}

void list_by_materia(std::string materia) {
  std::unique_ptr<sql::Connection> con = get_conection();
  try {
    std::shared_ptr<sql::PreparedStatement> statement(
        con->prepareStatement("SELECT student_id FROM grades WHERE class = ?"));
    statement->setString(1, materia);
    std::unique_ptr<sql::ResultSet> res_id(statement->executeQuery());
    while (res_id->next()) {

      int id = res_id->getInt("student_id");
      list_by_id(id);

    }
  } catch (sql::SQLException &e) {
    std::cerr << "Fallo al listar registro: " << e.what() << std::endl;
  }
  con->close();
}
void list_by_group(std::string grupo) {
  std::unique_ptr<sql::Connection> con = get_conection();
  try {
    std::shared_ptr<sql::PreparedStatement> statement(
        con->prepareStatement("SELECT * FROM students WHERE grupo = ?"));
    statement->setString(1, grupo);
    std::unique_ptr<sql::ResultSet> res(statement->executeQuery());
    while (res->next()) {

      int id = res->getInt("id");

      printf("*** --- Datos del estudiante --- ***\n");
      printf("- ID del estudiante: %d\n", id);
      printf("- Nombre del estudiante: %s\n", res->getString("name").c_str());
      printf("- Edad del estudiante: %d\n", res->getInt("age"));
      printf("- Promedio del estudiante: %.2Lf\n",
             res->getDouble("promedio_n"));
      printf("- Rendimiento: %s\n", res->getString("promedio").c_str());

      std::shared_ptr<sql::PreparedStatement> statement_family_data(
          con->prepareStatement(
              "SELECT * FROM datos_familia WHERE student_id = ?"));
      statement_family_data->setInt(1, id);
      std::unique_ptr<sql::ResultSet> result_family_data(
          statement_family_data->executeQuery());

      while (result_family_data->next()) {
        printf("*** --- Datos de la familia --- ***\n");
        printf("- Nombre del familiar: %s\n",
               result_family_data->getString("name").c_str());
        printf("- Relacion con el alumno: %s\n",
               result_family_data->getString("relation").c_str());
        printf("- Numero telefonico: %s\n",
               result_family_data->getString("phone_number").c_str());
      }

      std::shared_ptr<sql::PreparedStatement> statement_calif(
          con->prepareStatement("SELECT * FROM grades WHERE student_id = ?"));
      statement_calif->setInt(1, id);
      std::unique_ptr<sql::ResultSet> result_calif(
          statement_calif->executeQuery());

      printf("*** --- Calificaciones --- ***\n");
      while (result_calif->next()) {
        printf("%s: %.2Lf\n", result_calif->getString("class").c_str(),
               result_calif->getDouble("grades"));
      }
    }
  } catch (sql::SQLException &e) {
    std::cerr << "Fallo al listar registro: " << e.what() << std::endl;
  }
  con->close();
}
// Funcion para listar por ID

void list_by_id(int id) {
  std::unique_ptr<sql::Connection> con = get_conection();
  try {
    std::shared_ptr<sql::PreparedStatement> statement(
        con->prepareStatement("SELECT * FROM students WHERE id = ?"));
    statement->setInt(1, id);
    std::unique_ptr<sql::ResultSet> res(statement->executeQuery());
    while (res->next()) {

      printf("*** --- Datos del estudiante --- ***\n");
      printf("- ID del estudiante: %d\n", id);
      printf("- Nombre del estudiante: %s\n", res->getString("name").c_str());
      printf("- Edad del estudiante: %d\n", res->getInt("age"));
      printf("- Promedio del estudiante: %.2Lf\n",
             res->getDouble("promedio_n"));
      printf("- Rendimiento: %s\n", res->getString("promedio").c_str());

      std::shared_ptr<sql::PreparedStatement> statement_family_data(
          con->prepareStatement(
              "SELECT * FROM datos_familia WHERE student_id = ?"));
      statement_family_data->setInt(1, id);
      std::unique_ptr<sql::ResultSet> result_family_data(
          statement_family_data->executeQuery());

      while (result_family_data->next()) {
        printf("*** --- Datos de la familia --- ***\n");
        printf("- Nombre del familiar: %s\n",
               result_family_data->getString("name").c_str());
        printf("- Relacion con el alumno: %s\n",
               result_family_data->getString("relation").c_str());
        printf("- Numero telefonico: %s\n",
               result_family_data->getString("phone_number").c_str());
      }

      std::shared_ptr<sql::PreparedStatement> statement_calif(
          con->prepareStatement("SELECT * FROM grades WHERE student_id = ?"));
      statement_calif->setInt(1, id);
      std::unique_ptr<sql::ResultSet> result_calif(
          statement_calif->executeQuery());

      printf("*** --- Calificaciones --- ***\n");
      while (result_calif->next()) {
        printf("%s: %.2Lf\n", result_calif->getString("class").c_str(),
               result_calif->getDouble("grades"));
      }
    }
  } catch (sql::SQLException &e) {
    std::cerr << "Fallo al listar registro: " << e.what() << std::endl;
  }
  con->close();
}

// Funcion para borrar los datos de la base de datos

void delete_database() {
  std::unique_ptr<sql::Connection> con = get_conection();
  try {
    std::shared_ptr<sql::Statement> truncate(con->createStatement());
    truncate->executeQuery(
        "SET FOREIGN_KEY_CHECKS = 0; TRUNCATE TABLE students; SET "
        "FOREIGN_KEY_CHECKS = 1; TRUNCATE TABLE "
        "datos_familia; TRUNCATE TABLE grades");

  } catch (sql::SQLException &e) {
    std::cerr << "Error eliminando datos de la base de datos: " << e.what()
              << std::endl;
    con->close();
    return;
  }
  con->close();
  printf("Base de datos eliminada con exito\n");
}

// Funcion para dar de baja a un alumno

void deregister(int id) {
  std::unique_ptr<sql::Connection> con = get_conection();
  std::shared_ptr<sql::PreparedStatement> statement(
      con->prepareStatement("UPDATE students SET active = 0 WHERE id = ?"));
  try {
    statement->setInt(1, id);
    statement->executeUpdate();
  } catch (sql::SQLException &e) {
    std::cerr << "Error al dar de baja a alumno: " << e.what() << std::endl;
  }
  con->close();
}

// Funcion para modificar los datos de un estudiante

void insert(Student *new_student, int id_) {

  std::unique_ptr<sql::Connection> con = get_conection();

  std::shared_ptr<sql::Statement> check(con->createStatement());
  std::shared_ptr<sql::PreparedStatement> delete_student(
      con->prepareStatement("DELETE FROM students "
                            "WHERE id = ?"));

  std::shared_ptr<sql::PreparedStatement> delete_datos_familia(
      con->prepareStatement("DELETE FROM datos_familia WHERE student_id = ?"));

  std::shared_ptr<sql::PreparedStatement> delete_califs(
      con->prepareStatement("DELETE FROM grades WHERE student_id = ?"));
  try {

    check->executeQuery("SET FOREIGN_KEY_CHECKS = 0");

    delete_student->setInt(1, id_);
    delete_student->execute();

    check->executeQuery("SET FOREIGN_KEY_CHECKS = 1");

    delete_datos_familia->setInt(1, id_);
    delete_datos_familia->execute();

    delete_califs->setInt(1, id_);
    delete_califs->execute();

  } catch (sql::SQLException &e) {
    std::cerr << "No se ha podido añaidir modificar el registro de estudiante: "
              << e.what() << std::endl;
    con->close();
    exit(EXIT_FAILURE);
  }
  con->close();
  insert(new_student);
}

// Funcion para registrar un nuevo alumno

void insert(Student *new_student) {
  std::unique_ptr<sql::Connection> con = get_conection();
  std::shared_ptr<sql::PreparedStatement> statement_student(
      con->prepareStatement(
          "INSERT INTO students(name, age, grupo, promedio_n, promedio, "
          "active) VALUES (?, ?, ?, ?, ?, ?)"));
  std::shared_ptr<sql::PreparedStatement> statement_datos_familia(
      con->prepareStatement(
          "INSERT INTO datos_familia(student_id, name, relation, phone_number) "
          "VALUES (?, ?, ?, ?)"));
  std::shared_ptr<sql::Statement> get_last_id(con->createStatement());
  try {
    statement_student->setString(1, new_student->get_name());
    statement_student->setInt(2, new_student->get_age());
    statement_student->setString(3, new_student->get_group());
    statement_student->setDouble(4, new_student->get_promedio());
    statement_student->setString(5, new_student->get_leyenda());
    statement_student->setBoolean(6, true);

    statement_student->executeUpdate();

    std::unique_ptr<sql::ResultSet> res(
        get_last_id->executeQuery("SELECT LAST_INSERT_ID()"));

    int id = 0;
    while (res->next()) {
      id = res->getInt("LAST_INSERT_ID()");
    }

    statement_datos_familia->setInt(1, id);
    statement_datos_familia->setString(
        2, new_student->get_datos_familia().get_name());
    statement_datos_familia->setString(
        3, new_student->get_datos_familia().get_relation());
    statement_datos_familia->setString(
        4, new_student->get_datos_familia().get_num());

    statement_datos_familia->executeUpdate();

    for (auto x : new_student->get_calificaciones()) {
      std::shared_ptr<sql::PreparedStatement> statement_calificaciones(
          con->prepareStatement("INSERT INTO grades(student_id, class, grades) "
                                "VALUES (?, ?, ?)"));
      statement_calificaciones->setInt(1, id);
      statement_calificaciones->setString(2, x.first);
      statement_calificaciones->setDouble(3, x.second);

      statement_calificaciones->executeUpdate();
    }
  } catch (sql::SQLException &e) {
    std::cerr << "No se ha podido añaidir los datos de estudiante a la base de "
                 "datos: "
              << e.what() << std::endl;
    con->close();
    exit(EXIT_FAILURE);
  }
  con->close();
}
