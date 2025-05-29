
#include <iostream>
#include <vector>

std::vector<int> cambio(int* monedas,int tam)
{
 
    std::vector<int> solu;
    int prev = monedas[0];
    solu.push_back(monedas[0]);

    for (int i = 1; i < tam-1; i++)
    {
        if ( prev + monedas[i] < monedas[i+1])
        {
            prev = prev + monedas[i];
            solu.push_back(monedas[i]);
        }
    }
    solu.push_back(monedas[tam-1]);
    return solu;
}

int main()
{
    int tam;
    int coins;

    std::cout << "cuantos monedas hay disponibles: ";
    std::cin >> tam;

    int* mone = new int[tam];

    for (int i = 0; i < tam; i++)
    {
        std::cout << "ingrese valores de monedas: ";
        std::cin >> coins;
        mone[i] = coins;
    }

    std::vector<int> resultado = cambio(mone, tam);

    std::cout << "Monedas devueltas: " << resultado.size() << std::endl;


}






