/* 
    ====================================================================
    Materia: Laboratorio de Programación (LPR) — 5° Año
    Institución: E.E.S.T. N° 1 — Vicente López
    Archivo: src/main.cpp
    Actividad 7: Mini Juego Piedra, Papel o Tijera + Persistencia en Disco
    ====================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Estructura de datos para representar una partida
struct Partida {
    int idPartida;
    string jugador;
    string eleccionJugador;
    string eleccionIA;
    string resultado;
};

// Prototipos de funciones modulares
void jugarPartida(int& contadorID);
void guardarEnDisco(const Partida& p);
void leerHistorialDisco();

int main() {
    // Inicializar la semilla para los números aleatorios de la IA
    srand(time(0));
    
    int contadorID = 1;
    int opcion = 0;

    cout << "=====================================================" << endl;
    cout << "  LPR 2026 - ACTIVIDAD 7: PIEDRA, PAPEL O TIJERA      " << endl;
    cout << "  Estudiante / Grupo: [Goya Thiago / MST]         " << endl;
    cout << "=====================================================" << endl;

    do {
        cout << "\n--- MENU PRINCIPAL DE JUEGO Y PERSISTENCIA ---" << endl;
        cout << "1. Jugar Partida (Piedra, Papel o Tijera)" << endl;
        cout << "2. Ver Historial de Partidas Guardadas en Disco (.txt)" << endl;
        cout << "3. Salir del Sistema" << endl;
        cout << "Ingrese una opcion (1-3): ";
        cin >> opcion;

        if (opcion == 1) {
            jugarPartida(contadorID);
        } 
        else if (opcion == 2) {
            leerHistorialDisco();
        } 
        else if (opcion == 3) {
            cout << "\n[SISTEMA] Saliendo del programa... Datos resguardados en disco." << endl;
        } 
        else {
            cout << "\n[ERROR] Opcion invalida. Reintente." << endl;
        }

    } while (opcion != 3);

    return 0;
}

// Función para procesar la jugada contra la IA
void jugarPartida(int& contadorID) {
    Partida p;
    p.idPartida = contadorID++;

    cout << "\n--- NUEVA PARTIDA #" << p.idPartida << " ---" << endl;
    cout << "Ingrese su Nombre / Nickname: ";
    cin.ignore(); // Limpieza de búfer
    getline(cin, p.jugador);

    int opcJugador = 0;
    cout << "\nElija su jugada:" << endl;
    cout << "1. Piedra" << endl;
    cout << "2. Papel" << endl;
    cout << "3. Tijera" << endl;
    cout << "Opcion (1-3): ";
    cin >> opcJugador;

    // Asignar selección del usuario
    if (opcJugador == 1) p.eleccionJugador = "Piedra";
    else if (opcJugador == 2) p.eleccionJugador = "Papel";
    else p.eleccionJugador = "Tijera";

    // Elección aleatoria de la IA (1 a 3)
    int opcIA = (rand() % 3) + 1;
    if (opcIA == 1) p.eleccionIA = "Piedra";
    else if (opcIA == 2) p.eleccionIA = "Papel";
    else p.eleccionIA = "Tijera";

    // Evaluar reglas del juego
    cout << "\n[JUGADA] " << p.jugador << " eligio: " << p.eleccionJugador << endl;
    cout << "[JUGADA] La IA eligio: " << p.eleccionIA << endl;

    if (p.eleccionJugador == p.eleccionIA) {
        p.resultado = "Empate";
    } 
    else if ((p.eleccionJugador == "Piedra" && p.eleccionIA == "Tijera") ||
            (p.eleccionJugador == "Papel" && p.eleccionIA == "Piedra") ||
            (p.eleccionJugador == "Tijera" && p.eleccionIA == "Papel")) {
        p.resultado = "Victoria";
    } 
    else {
        p.resultado = "Derrota";
    }

    cout << "=> RESULTADO: " << p.resultado << "!" << endl;

    // Persistir el resultado inmediatamente en el archivo
    guardarEnDisco(p);
}

// Función para ESCRIBIR en el archivo de texto en disco
void guardarEnDisco(const Partida& p) {
    // ios::app permite agregar al final sin borrar partidas anteriores
    ofstream archivo("../src/historial_partidas.txt", ios::app);

    if (!archivo.is_open()) {
        cerr << "[ERROR] No se pudo abrir el archivo para guardar la partida." << endl;
        return;
    }

    // Guardado de datos separados por comas (Formato CSV)
    archivo << p.idPartida << "," 
            << p.jugador << "," 
            << p.eleccionJugador << "," 
            << p.eleccionIA << "," 
            << p.resultado << endl;

    archivo.close();
    cout << "[DISCO] Partida resguardada con exito en 'historial_partidas.txt'." << endl;
}

// Función para LEER el historial persistido desde el archivo
void leerHistorialDisco() {
    ifstream archivo("../src/historial_partidas.txt");

    if (!archivo.is_open()) {
        cout << "\n[AVISO] Aun no existen partidas guardadas en disco." << endl;
        return;
    }

    cout << "\n=====================================================" << endl;
    cout << "  HISTORIAL DE PARTIDAS RECUPERADO DESDE DISCO       " << endl;
    cout << "=====================================================" << endl;

    string idStr, jugador, elJug, elIA, resultado;
    int total = 0;

    // Lectura secuencial delimitada por comas
    while (getline(archivo, idStr, ',') &&
            getline(archivo, jugador, ',') &&
            getline(archivo, elJug, ',') &&
            getline(archivo, elIA, ',') &&
            getline(archivo, resultado)) {
        
        total++;
        cout << "Partida #" << idStr 
            << " | Jugador: " << jugador 
            << " | " << elJug << " vs " << elIA 
            << " | Resultado: " << resultado << endl;
    }

    archivo.close();

    if (total == 0) {
        cout << "[AVISO] El archivo de historial esta vacio." << endl;
    } else {
        cout << "\n[SISTEMA] Total de registros leidos desde disco: " << total << endl;
    }
    cout << "=====================================================" << endl;
}
