#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct RegistroTemperatura {
    string fecha;
    float manana;
    float tarde;
    float noche;
};


void ingresarRegistros(RegistroTemperatura registros[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese la fecha para el dia " << i + 1 << ": ";
        cin >> registros[i].fecha;
        cout << "Ingrese la temperatura de la mañana: ";
        cin >> registros[i].manana;
        cout << "Ingrese la temperatura de la tarde: ";
        cin >> registros[i].tarde;
        cout << "Ingrese la temperatura de la noche: ";
        cin >> registros[i].noche;
    }
}


void mostrarRegistros(RegistroTemperatura registros[], int n) {
    cout << "Registros de temperatura:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Fecha: " << registros[i].fecha << endl;
        cout << "Mañana: " << registros[i].manana << "C" << endl;
        cout << "Tarde: " << registros[i].tarde << "C" << endl;
        cout << "Noche: " << registros[i].noche << "C" << endl;
        cout << endl;
    }
}


float promedioTemperaturaDia(const RegistroTemperatura& registro) {
    return (registro.manana + registro.tarde + registro.noche) / 3.0;
}


float promedioTemperaturaTotal(RegistroTemperatura registros[], int n) {
    float sumaTotal = 0;
    for (int i = 0; i < n; ++i) {
        sumaTotal += promedioTemperaturaDia(registros[i]);
    }
    return sumaTotal / n;
}

int main() {
    const int n = 3; 
    RegistroTemperatura registros[n];


    ingresarRegistros(registros, n);


    mostrarRegistros(registros, n);


    cout << "Promedio de temperatura del dia:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Dia " << i + 1 << ": " << promedioTemperaturaDia(registros[i]) << "C" << endl;
    }


    cout << "Promedio de temperatura de todos los registros: " << promedioTemperaturaTotal(registros, n) << "C" << endl;

    return 0;
}
