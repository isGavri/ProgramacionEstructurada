#include <iostream>
using namespace std;

// Declaración de la estructura
struct Persona {
    string nombre;
    int edad;
    float altura;
};

int main() {
    // Declaración de una variable de tipo Persona
    Persona persona1;

    // Asignación de valores a los miembros de la estructura
    persona1.nombre = "Juan";
    persona1.edad = 30;
    persona1.altura = 1.75;

    // Impresión de los valores de la estructura
    cout << "Nombre: " << persona1.nombre << endl;
    cout << "Edad: " << persona1.edad << endl;
    cout << "Altura: " << persona1.altura << " metros" << endl;

    return 0;
}
