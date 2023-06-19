#include <iostream>
#include <cmath>
#include <windows.h>
#include <ncurses/ncurses.h>
#include "funciones.hpp"
#include "LagrangeInterpolacion.hpp"
using namespace std;

int main()
{
    system("color f0");

    int menu;
    int tamanoTabla;

    pintarTitulo();
    std::cout << "Ingrese el tamano de la tabla: ";
    std::cin >> tamanoTabla;

    limpiarPantalla();

    LagrangeInterpolacion lagrange(tamanoTabla);
    lagrange.leerDatos();
    limpiarPantalla();

    do {
        limpiarPantalla();
        pintarTitulo();
        lagrange.imprimirDatos();
        double valorX;

        std::cout << "\n\nIngrese el valor de x para calcular f(x): ";
        std::cin >> valorX;

        limpiarPantalla();
        pintarTitulo();
        double resultado = lagrange.calcularPolinomio(valorX);

        if (resultado != 0)
        {   
            std::cout << "\nRESULTADO" << std::endl;
            std::cout << "___________________________________________________" << std::endl;
            std::cout << "El valor aproximado de f(" << valorX << ") es: " << resultado << std::endl;
            std::cout << "___________________________________________________" << std::endl;
        }

        std::cout << "\nDeseas consultar en otra posicion x?" << std::endl;
        std::cout << "\n*Agrega el numero correspondiente a la accion que deseas*" << std::endl;
        std::cout << "\n1.- Si\n2.- No\n\nQuiero realizar la accion: ";
        std::cin >> menu;

        if (menu == 2)
        {
            std::cout << "\n\n\nSaliendo del programa...\n\n" << std::endl;
            system("\n\npause");
        }

        limpiarPantalla();

    } while (menu == 1);

    return 0;
}
