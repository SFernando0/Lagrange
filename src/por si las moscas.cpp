#include <iostream>
#include <cmath>
#include <ncurses/ncurses.h>
#include "funciones.hpp"
#include "LagrangeInterpolacion.hpp"

int main()
{
    initscr(); // Inicializar la biblioteca NCURSES

    int menu;
    int tamanoTabla;

    pintarTitulo();
    printw("Ingrese el tamano de la tabla: ");
    scanw("%d", &tamanoTabla);

    limpiarPantalla();

    LagrangeInterpolacion lagrange(tamanoTabla);
    lagrange.leerDatos();
    limpiarPantalla();

    do {
        limpiarPantalla();
        pintarTitulo();
        lagrange.imprimirDatos();
        double valorX;

        printw("\n\nIngrese el valor de x para calcular f(x): ");
        scanw("%lf", &valorX);

        limpiarPantalla();
        pintarTitulo();
        double resultado = lagrange.calcularPolinomio(valorX);

        if (resultado != 0)
        {   
            printw("\nRESULTADO\n");
            printw("___________________________________________________\n");
            printw("El valor aproximado de f(%lf) es: %lf\n", valorX, resultado);
            printw("___________________________________________________\n");
        }

        printw("\nDeseas consultar en otra posicion x?\n");
        printw("\n*Agrega el numero correspondiente a la accion que deseas*\n");
        printw("\n1.- Si\n2.- No\n\nQuiero realizar la accion: ");
        scanw("%d", &menu);

        if (menu == 2)
        {
            printw("\n\n\nSaliendo del programa...\n\n");
            refresh();
            system("pause");
        }

        limpiarPantalla();

    } while (menu == 1);

    endwin(); // Finalizar la biblioteca NCURSES

    return 0;
}
