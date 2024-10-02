#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Enum para representar los colores
enum Color {
    BLANCO, AMARILLO, ROSA, NARANJA, PURPURA, MORADO, ROJO, VERDE, AZUL, NEGRO, NO_COLOR
};

// La función ValidateWord es para convertir una palabra a minúsculas y eliminar signos de puntuación finales
string ValidateWord(string word) {
    if (!word.empty() && (word.back() == '.' || word.back() == ',')) {
        word.pop_back();
    }

    for (int i = 0; i < word.size(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] + 32; // Convertir a minúsculas
        }
    }

    return word;
}//end ValidateWord

// La función Identifier es para convertir una palabra en un enum de Color
Color Identifier(string word) {
    if (word == "blanco" || word == "blanca") return BLANCO;
    if (word == "amarillo" || word == "amarilla") return AMARILLO;
    if (word == "rosa") return ROSA;
    if (word == "naranja") return NARANJA;
    if (word == "púrpura") return PURPURA;
    if (word == "morado") return MORADO;
    if (word == "rojo") return ROJO;
    if (word == "verde") return VERDE;
    if (word == "azul") return AZUL;
    if (word == "negro") return NEGRO;
    return NO_COLOR;
}//end Identifier

// La función ColorToString es para convertir un enum de Color a su representación en string
string ColorToString(Color color) {
    switch (color) {
        case BLANCO: return "Blanco";
        case AMARILLO: return "Amarillo";
        case ROSA: return "Rosa";
        case NARANJA: return "Naranja";
        case PURPURA: return "Púrpura";
        case MORADO: return "Morado";
        case ROJO: return "Rojo";
        case VERDE: return "Verde";
        case AZUL: return "Azul";
        case NEGRO: return "Negro";
        default: return "Desconocido";
    }
}//end ColorToString

// La función ExistsInArray verifica si un color ya ha sido almacenado en el array
bool ExistsInArray(string colors[], string color) {
    for (int i = 0; i < NO_COLOR-1; i++) {
        if (colors[i] == color) {
            return true; // El color ya está en el array
        }
    }
    return false;
}//end ExistsInArray

// La función GetArrayLength calcula cuántos colores no vacíos hay en el array
int GetArrayLength(string colors[]) {
    int length = 0;
    for (int i = 0; i < NO_COLOR-1; i++) {
        if (!colors[i].empty()) {
            length++;
        }
    }
    return length;
}//end GetArrayLength

// La función ColorDetector es para leer el archivo y detectar colores
void ColorDetector(string colors[]) {

    ifstream archivo("Texto-1.txt");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo.";
        return;
    }

    string word;
    while (archivo >> word) { 
        word = ValidateWord(word); 

        Color detectedColor = Identifier(word);

        if (detectedColor != NO_COLOR) {

            string colorName = ColorToString(detectedColor); 
            if (!ExistsInArray(colors, colorName)) {

                if (GetArrayLength(colors) < NO_COLOR-1) {
                    colors[GetArrayLength(colors)] = colorName; 
                }

            }

        }

    }

    archivo.close();
}//end ColorDetector

// La función PrintColors es para imprimir los colores almacenados en el array
void PrintColors(string colors[]) {
    if (GetArrayLength(colors) == 0) {
        cout << endl <<"No se detectaron colores en el archivo." << endl;
        return;
    }

    cout << "Colores detectados: " << endl;
    for (int i = 0; i < GetArrayLength(colors); i++) {  
        cout << "- " << colors[i] << endl;
    }
}//end PrintColors

int main() {
    string detectedColors[NO_COLOR-1]; 

    // Leer el archivo y detectar colores dentro de él
    ColorDetector(detectedColors);

    // Imprimir los colores detectados
    PrintColors(detectedColors);

    return 0;
}