#include <iostream>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

int main() {
    Estudiante estudiantes[3];
    
    for (int i = 0; i < 3; i++) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].nombre;
        
        cout << "Ingrese la edad del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].edad;
        
        cout << "Ingrese el promedio del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].promedio;
        
        cout << endl;
    }
    
    cout << "Datos de los estudiantes:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Estudiante " << i + 1 << ":" << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        cout << endl;
    }
    
    return 0;
}
