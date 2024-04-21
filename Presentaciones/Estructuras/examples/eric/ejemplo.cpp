#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    string nombre;
    int codigo;
    string carrera;
};

void ingresarDatosEstudiante(Estudiante* estudiante) {
    cout << "Ingrese el nombre del estudiante: ";
    cin>>estudiante->nombre;

    cout << "Ingrese el codigo del estudiante: ";
    cin >> estudiante->codigo;
    

    cout << "Ingrese la carrera del estudiante: ";
    cin>>estudiante->carrera;
}

void imprimirDatosEstudiante(Estudiante* estudiante) {
    cout << endl << "Datos del estudiante:" << endl;
    cout << "Nombre: " << estudiante->nombre << endl;
    cout << "Código: " << estudiante->codigo << endl;
    cout << "Carrera: " << estudiante->carrera << endl;
}

int main() {
    Estudiante estudiante;

    ingresarDatosEstudiante(&estudiante);
    imprimirDatosEstudiante(&estudiante);

    return 0;
}
