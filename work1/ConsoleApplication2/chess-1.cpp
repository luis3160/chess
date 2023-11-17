#include <iostream>

using namespace std;

char tablero[8][8];

void InicializarTablero() {
    // Implementa la inicializaci�n del tablero seg�n tus necesidades
}

void MostrarTablero() {
    // Implementa la l�gica para mostrar el tablero
}

bool MoverPieza(int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino) {
    // Validar l�mites del tablero
    if (filaOrigen < 0 || filaOrigen >= 8 || columnaOrigen < 0 || columnaOrigen >= 8 ||
        filaDestino < 0 || filaDestino >= 8 || columnaDestino < 0 || columnaDestino >= 8) {
        return false;
    }

    char pieza = tablero[filaOrigen][columnaOrigen];

    switch (pieza) {
        // ... (resto del c�digo de movimientos)
    case 'c':
    case 'C':
        // L�gica de movimiento para caballos
        if ((abs(filaDestino - filaOrigen) == 2 && abs(columnaDestino - columnaOrigen) == 1) ||
            (abs(filaDestino - filaOrigen) == 1 && abs(columnaDestino - columnaOrigen) == 2)) {
            return true; // Movimiento v�lido para caballos
        }
        else {
            return false;
        }
        // ... (resto del c�digo de movimientos)
    }

    // Validar si la casilla de destino est� vac�a o tiene una pieza del oponente
    if (tablero[filaDestino][columnaDestino] != ' ' &&
        ((islower(pieza) && islower(tablero[filaDestino][columnaDestino])) ||
            (isupper(pieza) && isupper(tablero[filaDestino][columnaDestino])))) {
        return false; // Movimiento no v�lido, la casilla de destino no est� vac�a o tiene una pieza del mismo color
    }

    // Realizar el movimiento
    tablero[filaDestino][columnaDestino] = tablero[filaOrigen][columnaOrigen];
    tablero[filaOrigen][columnaOrigen] = ' ';

    return true;
}

void EntradaTeclado() {
    char columnaOrigen, columnaDestino;
    int filaOrigen, filaDestino;

    cout << "Ingrese la Columna de Origen (a-h): ";
    cin >> columnaOrigen;
    cout << "Ingrese la Fila de Origen (1-8): ";
    cin >> filaOrigen;

    cout << "Ingrese la Columna de Destino (a-h): ";
    cin >> columnaDestino;
    cout << "Ingrese la Fila de Destino (1-8): ";
    cin >> filaDestino;

    // Convertir la letra de la columna a un �ndice (0-7)
    int columnaOrigenIndice = columnaOrigen - 'a';
    int columnaDestinoIndice = columnaDestino - 'a';

    // Convertir la fila a un �ndice (0-7)
    int filaOrigenIndice = filaOrigen - 1;
    int filaDestinoIndice = filaDestino - 1;

    if (!MoverPieza(filaOrigenIndice, columnaOrigenIndice, filaDestinoIndice, columnaDestinoIndice)) {
        cout << "Movimiento no Permitido!" << endl;
    }
}

int main() {
    InicializarTablero();
    MostrarTablero();

    while (true) {
        EntradaTeclado();
        MostrarTablero();
    }

    cin.get();  // Espera a que el usuario presione Enter
    return 0;
}
