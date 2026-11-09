#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

struct Estudiante {
    string nombre;
    int nacimiento;
    float gpa;
};

int main() {

    array<Estudiante, 10> estudiantes = {{
        {"Juan", 2000, 3.4},
        {"Maria", 2005, 2.8}
    }};

    cout << "a) Ingreso de datos del tercer estudiante:\n";

    cout << "Nombre: ";
    cin >> estudiantes[2].nombre;

    cout << "Anio de nacimiento: ";
    cin >> estudiantes[2].nacimiento;

    cout << "GPA: ";
    cin >> estudiantes[2].gpa;

    cout << "\nIngreso de datos del cuarto estudiante:\n";

    cout << "Nombre: ";
    cin >> estudiantes[3].nombre;

    cout << "Anio de nacimiento: ";
    cin >> estudiantes[3].nacimiento;

    cout << "GPA: ";
    cin >> estudiantes[3].gpa;

    cout << "\nb) Insercion desde arrays basicos:\n";

    string nombres[] = {"Gaby", "Patty", "Diana"};
    int nacimientos[] = {2002, 2004, 2006};
    float gps[] = {3.8, 3.0, 2.9};

    for (int i = 0; i < 2; i++) {
        estudiantes[i + 4].nombre = nombres[i];
        estudiantes[i + 4].nacimiento = nacimientos[i];
        estudiantes[i + 4].gpa = gps[i];
    }

    cout << "Estudiantes insertados: Gaby y Patty.\n";

    cout << "\nc) Insercion desde archivo datos.txt:\n";

    ifstream archivo("datos.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo datos.txt\n";
        return 1;
    }

    for (int i = 6; i < 10; i++) {
        if (!(archivo >> estudiantes[i].nombre
                      >> estudiantes[i].nacimiento
                      >> estudiantes[i].gpa)) {
            cout << "Error al leer los datos del archivo.\n";
            return 1;
        }
    }

    archivo.close();

    cout << "Datos cargados correctamente.\n";

    cout << "\nd) LISTA DE ESTUDIANTES:\n\n";

    time_t ahora = time(nullptr);
    tm* fecha = localtime(&ahora);
    int anioActual = fecha->tm_year + 1900;

    cout << fixed << setprecision(1);

    for (auto it = estudiantes.begin(); it != estudiantes.end(); it++) {

        int edad = anioActual - it->nacimiento;

        cout << "Nombre: " << it->nombre << endl;
        cout << "Anio de nacimiento: " << it->nacimiento << endl;
        cout << "Edad aproximada: " << edad << endl;
        cout << "GPA: " << it->gpa << endl;

        if (it->gpa >= 3.5) {
            cout << "Beca: Califica\n";
        } else {
            cout << "Beca: No califica\n";
        }

        cout << "-------------------------\n";
    }

    return 0;
}