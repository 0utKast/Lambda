
#if 0
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

// Nuestra función devolverá true si el elemento coincide
bool contieneVer(std::string_view str)
{
    // std::string_view::find devuelve std::string_view::npos si no encuentra
    // el substring. Si lo encuentra devuelve el índice donde está el substring
    // en str.
    return (str.find("ver") != std::string_view::npos);
}

int main()
{


    


    std::array <std::string_view, 4> arr{ "amarillo", "naranja", "verde", "rojo" };

    // Escanea nuestro array para ver si alguno de los elementos contiene el subtring "ver"
    auto encontrado{ std::find_if(arr.begin(), arr.end(), contieneVer) };

    if (encontrado == arr.end())
    {
        std::cout << "No se encontró ver \n";
    }
    else
    {
        std::cout << "Encontrado en:  " << *encontrado << '\n';
    }

    return 0;
}







#include <iostream>

int main()
{
    auto a = []() {}; // define un lambda sin capturas, ni parámetros, y sin tipo de retorno

     std::cout << a;

    

    return 0;
}






#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
    constexpr std::array<std::string_view, 4> arr{ "amarillo", "naranja", "verde", "rojo" };

    // Definimos la función justo donde la usamos.
    const auto encontrado{ std::find_if(arr.begin(), arr.end(),
                             [](std::string_view str) // esta es nuestra lambda, sin cláusula de captura
                             {
                               return (str.find("ver") != std::string_view::npos);
                             }) };

    if (encontrado == arr.end())
    {
        std::cout << "No se encontró ver\n";
    }
    else
    {
        std::cout << "Encontrado en:  " << *encontrado << '\n';
    }

    return 0;
}




#include <vector>
#include <iostream>
#include <algorithm>
int main()
{

    std::vector <int> array{ 4,6,8,10,12 };
   

    // Confuso: tenemos que leer el lambda para entender lo que pasa.
// illustrate all_of
    if (std::all_of(array.begin(), array.end(), [](int i) { return i % 2 == 0; }))
    {
        std::cout << "Todos los enteros son pares\n";
    }
    else
    {
        std::cout << "No todos los enteros son pares\n";

    }
}



#include <vector>
#include <iostream>
#include <algorithm>
int main()
{

    // Mejor: En su lugar, podemos almacenar la lambda en una variable con nombre y pasarla a la fúnción.
    auto esPar{
      [](int i)
      {
        return ((i % 2) == 0);
      }
    };

    std::vector <int> array{ 4,6,8,10,12 };

    if (std::all_of(array.begin(), array.end(), esPar))
    {
        std::cout << "Todos los enteros son pares\n";
    }
    else
    {
        std::cout << "No todos los enteros son pares\n";

    }
}

#endif







#include <functional>
#include <iostream>

int main()
{
    // Un puntero de función regular. Sólo funciona si la cláusula de captura está vacía.
    double (*addNumeros1)(double, double) {
        [](double a, double b) {
            return (a + b);
        }
    };

    double a1 = addNumeros1(1, 2);

    // Usando std::function. La lambda podría tener una cláusula de captura no vacía (próximo VT).
    std::function addNumeros2{ // nota: pre-C++17, usa std::function<double(double, double)> en su lugar
      [](double a, double b) {
        return (a + b);
      }
    };

    double a2 = addNumeros2(3, 4);

    // Usando auto. Almacena lambda con su tipo real.
    auto addNumeros3{
      [](double a, double b) {
        return (a + b);
      }
    };

    auto a3 = addNumeros3(5, 6);

    std::cout << a1<<'\n';
    std::cout << a2 << '\n';
    std::cout << a3 << '\n';
    return 0;
}

#if 0
#endif