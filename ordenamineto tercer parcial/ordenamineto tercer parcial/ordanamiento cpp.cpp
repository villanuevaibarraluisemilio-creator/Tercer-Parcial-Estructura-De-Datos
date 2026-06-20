#include <iostream>
#include <algorithm>

using namespace std;

class Ordenamiento {
protected:
    int* datos;
    int n;

public:
    Ordenamiento(int arr[], int tam) : n(tam), datos(new int[tam]) {
        for (int i = 0; i < n; i++) {
            datos[i] = arr[i];
        }
    }

    virtual void ordenar() = 0;

    void mostrar() const {
        for (int i = 0; i < n; i++) {
            cout << datos[i] << " ";
        }
        cout << "\n";
    }

    virtual ~Ordenamiento() {
        delete[] datos;
    }
};

class QuickSort : public Ordenamiento {
private:
    int particion(int bajo, int alto) {
        int pivote = datos[alto];
        int i = bajo - 1;

        for (int j = bajo; j < alto; j++) {
            if (datos[j] < pivote) {
                i++;
                swap(datos[i], datos[j]);
            }
        }
        swap(datos[i + 1], datos[alto]);
        return i + 1;
    }

    void quick(int bajo, int alto) {
        if (bajo < alto) {
            int pi = particion(bajo, alto);
            quick(bajo, pi - 1);
            quick(pi + 1, alto);
        }
    }

public:
    QuickSort(int arr[], int tam) : Ordenamiento(arr, tam) {}

    void ordenar() override {
        quick(0, n - 1);
    }
};

int main() {
    int v[] = {9, 4, 8, 2, 1};
    int tamano = sizeof(v) / sizeof(v[0]);

    QuickSort q(v, tamano);

    q.ordenar();
    q.mostrar();

    return 0;
}
