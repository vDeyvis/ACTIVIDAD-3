#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {

    array<int, 20> numeros = {
        21, 23, 25, 27, 29,
        51, 53, 55, 57, 59, 61, 63, 65, 67, 69,
        1, 3, 5, 7, 9
    };

    cout << "a) Todos los elementos:\n";

    for (auto it = numeros.begin(); it != numeros.end(); it++) {
        cout << *it << " ";
    }

    cout << "\n\nb) Elementos mayores de 20 y menores de 50:\n";

    for (auto it = numeros.begin(); it != numeros.end(); it++) {
        if (*it > 20 && *it < 50) {
            cout << *it << " ";
        }
    }

    sort(numeros.begin(), numeros.end());

    cout << "\n\nc) Elementos ordenados:\n";

    for (auto it = numeros.begin(); it != numeros.end(); it++) {
        cout << *it << " ";
    }

    cout << "\n\nd) Elementos ubicados en indices impares menores de 10:\n";

    for (int i = 1; i < 10; i += 2) {
        cout << numeros[i] << " ";
    }

    cout << endl;

    return 0;
}