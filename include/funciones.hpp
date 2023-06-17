void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void limpiarPantalla()
{
    system("cls");
}

void pintarTitulo()
{
    int x = 50; // Posición horizontal
    int y = 2;  // Posición vertical
    gotoxy(x, y);
    std::cout << "  METODOS NUMERICOS" << std::endl;

    y += 1;
    gotoxy(x, y);
    std::cout << "      LAGRANGE" << std::endl;

    y += 1;
    gotoxy(x, y);
    std::cout << "         de " << std::endl;

    y += 1;
    gotoxy(x-2, y);
    std::cout << "  Fernando Soto Oregon \n\n\n" << std::endl;
}