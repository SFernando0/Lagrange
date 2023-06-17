
class LagrangeInterpolacion
{
public:
    int n;
    double* x;
    double* f;

    LagrangeInterpolacion(int size)
    {
        n = size;
        x = new double[n];
        f = new double[n];
    }

    ~LagrangeInterpolacion()
    {
        delete[] x;
        delete[] f;
    }

   void leerDatos()
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << "Ingrese el valor de x[" << i << "]: ";
            std::cin >> x[i];
            system("cls");
            std::cout << "Ingrese el valor de f(x[" << i << "]): ";
            std::cin >> f[i];
            system("cls");
        }
    }

    void imprimirDatos()
    {
    std::cout << "Tabla de datos:\n";
    std::cout << "-----------------\t-----------------\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "x[" << i << "] = " << x[i] << "\t|\tf(x[" << i << "]) = " << f[i] << "\n";
    }
    std::cout << "-----------------\t-----------------";
    }

    double calcularPolinomio(double xi)
    {
        if (xi < x[0] || xi > x[n - 1])
        {
            std::cout << "\n\nEl valor x[i] esta fuera del rango de interpolación." << std::endl;
            return 0.0; // O cualquier valor apropiado en caso de error
        }

        double resultado = 0.0;
        for (int i = 0; i < n; i++)
        {
            double termino = f[i];

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    termino *= (xi - x[j]) / (x[i] - x[j]);
                }
            }

            resultado += termino;
        }

        return resultado;
    }
};