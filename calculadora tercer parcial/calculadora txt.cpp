#include <iostream>
using namespace std;

class OperacionMatematica {

private:
    int opcionMenu;
    float valorFinal;

public:
    OperacionMatematica() : opcionMenu(0), valorFinal(0.0f) {}

    void desplegarMenu() {
        cout << "\n--- MENU CALCULADORA ---\n";
        cout << "[1] Adicion\n";
        cout << "[2] Sustraccion\n";
        cout << "[3] Multiplicar\n";
        cout << "[4] Dividir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcionMenu;
    }

    int obtenerOpcion() {
        return opcionMenu;
    }

    void capturarEntradas(float arreglo[], int longitud) {
        for (int idx = 0; idx < longitud; idx++) {
            cout << "Ingrese el numero " << idx + 1 << ": ";
            cin >> arreglo[idx];
        }
    }

    void calcularSuma(float arreglo[], int longitud) {
        valorFinal = 0;
        for (int idx = 0; idx < longitud; idx++) {
            valorFinal += arreglo[idx];
        }
    }

    void calcularResta(float arreglo[], int longitud) {
        valorFinal = arreglo[0];
        for (int idx = 1; idx < longitud; idx++) {
            valorFinal -= arreglo[idx];
        }
    }

    void calcularMultiplicacion(float arreglo[], int longitud) {
        valorFinal = 1;
        for (int idx = 0; idx < longitud; idx++) {
            valorFinal *= arreglo[idx];
        }
    }

    void calcularDivision(float arreglo[], int longitud) {
        valorFinal = arreglo[0];
        for (int idx = 1; idx < longitud; idx++) {
            if (arreglo[idx] == 0) {
                cout << "Aviso: No es posible dividir entre cero.\n";
                return;
            }
            valorFinal /= arreglo[idx];
        }
    }

    void imprimirTotal() {
        cout << "\nEl resultado total es: " << valorFinal << endl;
    }
};

int main() {
    char respuestaUsuario;

    do {
        int cantidadElementos;

        do {
            cout << "\n¿Cuantos datos va a registrar?: ";
            cin >> cantidadElementos;
        } while (cantidadElementos <= 0);

        float* listaNumeros = new float[cantidadElementos];
        OperacionMatematica ejecutor;

        ejecutor.desplegarMenu();
        ejecutor.capturarEntradas(listaNumeros, cantidadElementos);

        switch (ejecutor.obtenerOpcion()) {
            case 1:
                ejecutor.calcularSuma(listaNumeros, cantidadElementos);
                break;
            case 2:
                ejecutor.calcularResta(listaNumeros, cantidadElementos);
                break;
            case 3:
                ejecutor.calcularMultiplicacion(listaNumeros, cantidadElementos);
                break;
            case 4:
                ejecutor.calcularDivision(listaNumeros, cantidadElementos);
                break;
            default:
                cout << "La opcion ingresada no es valida.\n";
        }

        ejecutor.imprimirTotal();

        delete[] listaNumeros;

        cout << "\n¿Quiere realizar otra operacion? (S/N): ";
        cin >> respuestaUsuario;

    } while (respuestaUsuario == 's' || respuestaUsuario == 'S');

    return 0;
}
