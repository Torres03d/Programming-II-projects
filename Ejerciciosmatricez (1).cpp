#include <iostream>
#include <limits>

using namespace std;

const int MAX_FILAS = 4;
const int MAX_COLUMNAS = 4;

// Prototipos de funciones
void mostrarMenu();
void obtenerEntradaMatriz(int matriz[][MAX_COLUMNAS], int filas, int columnas);
void sumarMatrices(int A[][MAX_COLUMNAS], int B[][MAX_COLUMNAS], int resultado[][MAX_COLUMNAS], int filas, int columnas);
void restarMatrices(int A[][MAX_COLUMNAS], int B[][MAX_COLUMNAS], int resultado[][MAX_COLUMNAS], int filas, int columnas);
void multiplicacionEscalar(int A[][MAX_COLUMNAS], int filas, int columnas, int escalar);
void multiplicacionMatrices(int A[][MAX_COLUMNAS], int B[][MAX_COLUMNAS], int resultado[][MAX_COLUMNAS], int filasA, int columnasA, int columnasB);
void transponerMatriz(int A[][MAX_COLUMNAS], int resultado[][MAX_COLUMNAS], int filas, int columnas);
void invertirMatriz2x2(int A[][MAX_COLUMNAS], int resultado[][MAX_COLUMNAS]);
int determinanteMatriz2x2(int A[][MAX_COLUMNAS]);
void imprimirMatriz(int matriz[][MAX_COLUMNAS], int filas, int columnas);

void mostrarMenu() {
    cout << "\nOperaciones con matrices:" << endl;
    cout << "1. Sumar matrices" << endl;
    cout << "2. Restar matrices" << endl;
    cout << "3. Multiplicar por escalar" << endl;
    cout << "4. Multiplicar matrices" << endl;
    cout << "5. Transponer matriz" << endl;
    cout << "6. Invertir matriz (2x2)" << endl;
    cout << "7. Determinante (2x2)" << endl;
    cout << "8. Salir" << endl;
    cout << "Ingrese su opción: ";
}

void obtenerEntradaMatriz(int matriz[][MAX_COLUMNAS], int filas, int columnas) {
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Ingrese elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void sumarMatrices(int A[][MAX_COLUMNAS], int B[][MAX_COLUMNAS], int resultado[][MAX_COLUMNAS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
}

void restarMatrices(int A[][MAX_COLUMNAS], int B[][MAX_COLUMNAS], int resultado[][MAX_COLUMNAS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplicacionEscalar(int A[][MAX_COLUMNAS], int filas, int columnas, int escalar) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            A[i][j] *= escalar;
        }
    }
}

void multiplicacionMatrices(int A[][MAX_COLUMNAS], int B[][MAX_COLUMNAS], int resultado[][MAX_COLUMNAS], int filasA, int columnasA, int columnasB) {
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < columnasA; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transponerMatriz(int A[][MAX_COLUMNAS], int resultado[][MAX_COLUMNAS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[j][i] = A[i][j];
        }
    }
}

void invertirMatriz2x2(int A[][MAX_COLUMNAS], int resultado[][MAX_COLUMNAS]) {
    int det = determinanteMatriz2x2(A);
    if (det == 0) {
        cout << "Error: La matriz es singular (determinante es 0). No existe inversa." << endl;
        return;
    }
    resultado[0][0] = A[1][1];
    resultado[0][1] = -A[0][1];
    resultado[1][0] = -A[1][0];
    resultado[1][1] = A[0][0];
    multiplicacionEscalar(resultado, 2, 2, 1 / det);
}

int determinanteMatriz2x2(int A[][MAX_COLUMNAS]) {
    return (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
}

void imprimirMatriz(int matriz[][MAX_COLUMNAS], int filas, int columnas) {
    cout << "Matriz resultante:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int filasA, columnasA, filasB, columnasB, opcion, escalar;
    int matrizA[MAX_FILAS][MAX_COLUMNAS], matrizB[MAX_FILAS][MAX_COLUMNAS], resultado[MAX_FILAS][MAX_COLUMNAS];

    do {
        mostrarMenu();
        cin >> opcion;

        if (opcion >= 1 && opcion <= 8) {
            switch (opcion) {
                case 1:  // Sumar matrices
                    cout << "Ingrese el número de filas para la matriz A (máximo 4): ";
                    cin >> filasA;
                    cout << "Ingrese el número de columnas para la matriz A (máximo 4): ";
                    cin >> columnasA;

                    cout << "Ingrese el número de filas para la matriz B (máximo 4): ";
                    cin >> filasB;
                    cout << "Ingrese el número de columnas para la matriz B (máximo 4): ";
                    cin >> columnasB;

                    if (filasA != filasB || columnasA != columnasB) {
                        cout << "Error: Las matrices deben tener las mismas dimensiones para la suma." << endl;
                        break;
                    }

                    cout << "Ingrese la matriz A:" << endl;
                    obtenerEntradaMatriz(matrizA, filasA, columnasA);
                    cout << "Ingrese la matriz B:" << endl;
                    obtenerEntradaMatriz(matrizB, filasB, columnasB);
                    sumarMatrices(matrizA, matrizB, resultado, filasA, columnasA);
                    imprimirMatriz(resultado, filasA, columnasA);
                    break;

                case 2:  // Restar matrices
                    cout << "Ingrese el número de filas para la matriz A (máximo 4): ";
                    cin >> filasA;
                    cout << "Ingrese el número de columnas para la matriz A (máximo 4): ";
                    cin >> columnasA;

                    cout << "Ingrese el número de filas para la matriz B (máximo 4): ";
                    cin >> filasB;
                    cout << "Ingrese el número de columnas para la matriz B (máximo 4): ";
                    cin >> columnasB;

                    if (filasA != filasB || columnasA != columnasB) {
                        cout << "Error: Las matrices deben tener las mismas dimensiones para la resta." << endl;
                        break;
                    }

                    cout << "Ingrese la matriz A:" << endl;
                    obtenerEntradaMatriz(matrizA, filasA, columnasA);
                    cout << "Ingrese la matriz B:" << endl;
                    obtenerEntradaMatriz(matrizB, filasB, columnasB);
                    restarMatrices(matrizA, matrizB, resultado, filasA, columnasA);
                    imprimirMatriz(resultado, filasA, columnasA);
                    break;

                case 3:  // Multiplicar por escalar
                    cout << "Ingrese el número de filas para la matriz A (máximo 4): ";
                    cin >> filasA;
                    cout << "Ingrese el número de columnas para la matriz A (máximo 4): ";
                    cin >> columnasA;
                    cout << "Ingrese el valor escalar: ";
                    cin >> escalar;

                    cout << "Ingrese la matriz A:" << endl;
                    obtenerEntradaMatriz(matrizA, filasA, columnasA);
                    multiplicacionEscalar(matrizA, filasA, columnasA, escalar);
                    imprimirMatriz(matrizA, filasA, columnasA);
                    break;

                case 4:  // Multiplicar matrices
                    cout << "Ingrese el número de filas para la matriz A (máximo 4): ";
                    cin >> filasA;
                    cout << "Ingrese el número de columnas para la matriz A (máximo 4): ";
                    cin >> columnasA;

                    cout << "Ingrese el número de filas para la matriz B (máximo 4): ";
                    cin >> filasB;
                    cout << "Ingrese el número de columnas para la matriz B (máximo 4): ";
                    cin >> columnasB;

                    if (columnasA != filasB) {
                        cout << "Error: El número de columnas en la matriz A debe ser igual al número de filas en la matriz B para la multiplicación." << endl;
                        break;
                    }

                    cout << "Ingrese la matriz A:" << endl;
                    obtenerEntradaMatriz(matrizA, filasA, columnasA);
                    cout << "Ingrese la matriz B:" << endl;
                    obtenerEntradaMatriz(matrizB, filasB, columnasB);
                    multiplicacionMatrices(matrizA, matrizB, resultado, filasA, columnasA, columnasB);
                    imprimirMatriz(resultado, filasA, columnasB);
                    break;

                case 5:  // Transponer matriz
                    cout << "Ingrese el número de filas para la matriz A (máximo 4): ";
                    cin >> filasA;
                    cout << "Ingrese el número de columnas para la matriz A (máximo 4): ";
                    cin >> columnasA;

                    cout << "Ingrese la matriz A:" << endl;
                    obtenerEntradaMatriz(matrizA, filasA, columnasA);
                    transponerMatriz(matrizA, resultado, filasA, columnasA);
                    imprimirMatriz(resultado, columnasA, filasA);  // Imprime la matriz transpuesta
                    break;

                case 6:  // Invertir matriz (2x2)
                    cout << "Ingrese la matriz A (2x2):" << endl;
                    obtenerEntradaMatriz(matrizA, 2, 2);
                    invertirMatriz2x2(matrizA, resultado);
                    imprimirMatriz(resultado, 2, 2);
                    break;

                case 7:  // Determinante (2x2)
                    cout << "Ingrese la matriz A (2x2):" << endl;
                    obtenerEntradaMatriz(matrizA, 2, 2);
                    cout << "Determinante: " << determinanteMatriz2x2(matrizA) << endl;
                    break;

                case 8:
                    cout << "Saliendo del programa." << endl;
                    break;
            }
        } else {
            cout << "Opción inválida. Por favor ingrese un número entre 1 y 8." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer de entrada
        }
    } while (opcion != 8);

    return 0;
}