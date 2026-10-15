# E.E.S.T. N.º 1 "Eduardo Ader" --- 5.º 3.ª --- 2026

# Actividad 7: Manual de Usuario

## Mini Juego "Piedra, Papel o Tijera"

**Integrantes:** Martina Araujo, Thiago Goya y Sofia Salaberry\
**Escuela:** Escuela Técnica N.º 1 de Vicente López\
**Curso:** Ciclo Superior, 5.º año 3.ª\
**Docentes:** Yamil Ganduglia y York Elías Mansilla Muñoz\
**Materia:** Laboratorio de Programación\
**Repositorio de GitHub:** https://github.com/GoyaYuki/Mini_juego\
**Año:** 2026

## Inicio

Para ejecutar el código, se puede hacer clic derecho sobre el archivo
`main.cpp`. Se abrirá un menú con distintas opciones; hay que
seleccionar **Run Code**. Si la opción no aparece, se puede instalar la
extensión correspondiente. También se puede utilizar la combinación de
teclas `Ctrl + Alt + N`.

A continuación, se abrirá la terminal en la parte inferior del entorno
de desarrollo integrado (IDE).

## Menú principal

Una vez ejecutado el código, aparecerá el menú del juego con las
siguientes opciones:

1.  **Jugar Partida (Piedra, Papel o Tijera):** comienza una nueva
    partida contra la computadora.
2.  **Ver Historial de Partidas Guardadas en Disco (.txt):** muestra las
    partidas que se guardaron anteriormente.
3.  **Salir del Sistema:** termina la ejecución del programa.

Luego, el sistema pedirá que se ingrese una opción.

## Jugar partida (Piedra, Papel o Tijera)

Si se elige la opción 1, el programa pedirá ingresar el nombre o apodo
del jugador.

Luego pedirá elegir una jugada:

1.  Piedra.
2.  Papel.
3.  Tijera.

A continuación, la inteligencia artificial del sistema elegirá una
jugada al azar. En pantalla se mostrarán las dos elecciones y el
resultado. Al finalizar, el programa indicará si fue una victoria, una
derrota o un empate. Después, guardará automáticamente el registro en el
historial.

## Ver historial de partidas guardadas en disco (.txt)

Para elegir esta opción, hay que ingresar `2` en el menú. El programa
leerá el archivo `src/historial_partidas.txt` y mostrará las partidas
guardadas hasta ese momento.

Si todavía no se jugó ninguna partida o el archivo no se encuentra
disponible en la ruta esperada, el programa mostrará un aviso.

## Salir del sistema

Para terminar la ejecución, hay que seleccionar la opción `3` en el menú
principal.

## Recomendaciones

-   Ingresar el número de la opción que se desea seleccionar.
-   Elegir `1`, `2` o `3` cuando el programa solicite una opción del
    menú.
-   Jugar al menos una partida antes de consultar el historial.
-   No eliminar ni mover `historial_partidas.txt` si se desea conservar
    el registro de las partidas.
