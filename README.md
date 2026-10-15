# Mini_juego
Actividad 7 - Mini Juego "Piedra, Papel o Tijera"

Materia: Laboratorio de Programación (LPR), 5.º año
Curso/división: 5.º 3.ª A-B
Integrantes: Martina Araujo, Thiago Goya y Sofia Salaberry

## Introducción
En esta actividad desarrollamos un mini juego de Piedra, Papel o Tijera en C++, donde el jugador compite contra la Inteligencia Artificial de la consola. Cada partida se registra en una estructura llamada "Partida" y se guarda automáticamente en un archivo de texto llamado "historial_partidas.txt".

## Objetivo de la actividad
Los objetivos principales de esta actividad son:
- Modelado con struct: Agrupar los datos de cada partida, como el ID, el nombre del jugador, las elecciones y el resultado.
- Escritura en disco (ofstream): Guardar los resultados en un archivo de texto utilizando el modo "ios::app", para agregar nuevas partidas sin borrar las anteriores.
- Lectura desde disco (ifstream): Recuperar el historial de partidas guardadas y mostrarlo en la consola.

## Estructura
Para realizar la actividad se creó la estructura "Partida":

struct Partida {
    int idPartida;
    string jugador;
    string eleccionJugador;
    string eleccionIA;
    string resultado;
};

La estructura contiene cinco miembros:
- "idPartida": almacena el número identificador de la partida.
- "jugador": guarda el nombre o apodo del jugador.
- "eleccionJugador": almacena la elección del jugador.
- "eleccionIA": guarda la elección realizada por la inteligencia artificial.
- "resultado": indica si la partida terminó en victoria, derrota o empate.

El uso de "struct" nos permitio agrupar todos los datos relacionados con una partida en una sola entidad, facilitandonos su organización y utilización dentro del programa.

## Uso de archivos: ofstream e ifstream
Para trabajar con archivos se utiliza la biblioteca:
#include <fstream>

Esta biblioteca permite guardar y recuperar información del almacenamiento secundario.

## Escritura con ofstream
La función encargada de guardar los resultados es:
void guardarEnDisco(const Partida& p);

Dentro de esta función se abre el archivo en modo de agregado:

ofstream archivo("src/historial_partidas.txt", ios::app);

"ios::app" permite agregar cada nueva partida al final del archivo sin eliminar los registros anteriores.

Los datos se guardan separados por comas, incluyendo el ID, el jugador, las elecciones y el resultado.

## Lectura con ifstream
La función encargada de recuperar los datos es:
void leerHistorialDisco();

Para leer el archivo se utiliza:
ifstream archivo("src/historial_partidas.txt");

Mediante "getline()" se recuperan los datos guardados y se muestran en la consola. De esta manera, el jugador puede consultar las partidas anteriores incluso después de cerrar y volver a ejecutar el programa.

## Uso de cin.ignore() y getline()
Cuando se utiliza "cin >>" para ingresar una opción, queda un salto de línea ("\n") pendiente en el búfer de entrada.

Por ese motivo, antes de leer el nombre del jugador se utiliza:

cin.ignore();
getline(cin, p.jugador);

"cin.ignore()" descarta el carácter pendiente y permite que "getline()" lea correctamente el nombre completo, incluyendo los espacios.

## Funcionamiento del programa

El programa comienza inicializando la generación de números aleatorios que utiliza la inteligencia artificial y mostrando un menú principal con tres opciones:

1. Jugar una partida de Piedra, Papel o Tijera.
2. Consultar el historial de partidas guardadas en disco.
3. Salir del programa.

Cuando el usuario elige jugar, ingresa su nombre y selecciona piedra, papel o tijera. La inteligencia artificial realiza una elección aleatoria y el programa compara ambas jugadas para determinar el resultado.

Después, la partida se guarda automáticamente en el archivo "historial_partidas.txt". Si el usuario selecciona la segunda opción, el programa lee los registros almacenados y los muestra en la pantalla.

El funcionamiento general puede resumirse de la siguiente manera:
<pre>
Inicio
  ↓
Inicializar el programa
  ↓
Mostrar menú principal
  ↓
Seleccionar una opción
  ↓
¿Jugar una partida?
  ↓ Sí
Ingresar nombre del jugador
  ↓
Elegir jugada
  ↓
Generar elección de la IA
  ↓
Comparar las elecciones
  ↓
Mostrar resultado
  ↓
Guardar partida en el archivo
  ↓
Volver al menú
  ↓
¿Consultar historial?
  ↓ Sí
Leer archivo de texto
  ↓
Mostrar partidas guardadas
  ↓
Volver al menú
  ↓
Salir del programa
</pre>

## Diferencia entre memoria RAM y almacenamiento en disco

La memoria RAM almacena temporalmente los datos que utiliza el programa mientras se está ejecutando. Al cerrar el programa, esos datos dejan de estar disponibles en la memoria.

En cambio, el archivo "historial_partidas.txt" guarda la información en el disco, por lo que las partidas registradas permanecen almacenadas después de cerrar la consola. Esto se conoce como persistencia de datos.

## Estructura del repositorio
<pre>
piedrapapelotijera/
├── .gitattributes
├── .gitignore
├── LICENSE
├── README.md
├── docs/
│   ├── InformeEEST1_LPR2026_ACT07_G03_Informe_v1.0.0.pdf
│   ├── CHANGELOG.md
│   └── manuales/
│       ├── manual_programador_v1.0.0.pdf
│       ├── manual_programador_v1.0.0.md
│       ├── manual_usuario_v1.0.0.pdf
│       └── manual_usuario_v1.0.0.md
├── src/
│   ├── main.cpp
│   └── historial_partidas.txt
└── capturas/
    ├── jugada_consola.png
    └── archivo_disco.png
</pre>