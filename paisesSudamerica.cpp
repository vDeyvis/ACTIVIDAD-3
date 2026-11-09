#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    array<string, 12> paises = {
        "Argentina",
        "Bolivia",
        "Brasil",
        "Chile",
        "Colombia",
        "Ecuador",
        "Guyana",
        "Paraguay",
        "Peru",
        "Surinam"
    };

    paises.at(10) = "Uruguay";
    paises[11] = "Venezuela";

    cout << "a) Insercion de los paises restantes:\n";

    cout << "Se insertaron Uruguay y Venezuela.\n";

    cout << "\nb) Paises que comienzan con C o P:\n";

    for (auto it = paises.begin(); it != paises.end(); it++) {
        if ((*it)[0] == 'C' || (*it)[0] == 'P') {
            cout << *it << endl;
        }
    }

    cout << "\nc) Primer y ultimo pais:\n";

    cout << "Primer pais: " << paises.front() << endl;
    cout << "Ultimo pais: " << paises.back() << endl;

    sort(paises.begin(), paises.end());

    cout << "\nd) Paises ordenados alfabeticamente:\n";

    for (auto it = paises.begin(); it != paises.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}