#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;  // Número de dígitos
    cout << "Ingrese el número de dígitos: ";
    cin >> n;

    vector<int> digits(n);

    // Leer los dígitos del boleto
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el dígito " << i + 1 << ": ";
        cin >> digits[i];
    }

    // Comprobar si el número de dígitos es par
    if (n % 2 != 0) {
        cout << "El número de dígitos debe ser par." << endl;
        return 0;
    }

    int mid = n / 2;
    int sum_first_half = 0, sum_second_half = 0;

    // Sumar la primera mitad
    for (int i = 0; i < mid; i++) {
        sum_first_half += digits[i];
    }

    // Sumar la segunda mitad
    for (int i = mid; i < n; i++) {
        sum_second_half += digits[i];
    }

    // Comprobar si el boleto es válido
    if (sum_first_half == sum_second_half) {
        cout << sum_first_half << " 1" << endl;  // Boleto válido
    } else {
        cout << (sum_first_half + sum_second_half) << " 0" << endl;  // Boleto inválido
    }

    return 0;
}