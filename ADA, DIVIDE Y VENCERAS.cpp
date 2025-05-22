#include <iostream>
#include <vector>

    
int merge(std::vector<int>& lista, int inicio, int mitad, int final,int& contador)
{
    int i = 0;
    int j = 0;
    int k = inicio;


    int izq = mitad - inicio + 1;
    int der = final - mitad;

    std::vector<int>laizq(izq);
    std::vector<int>lader(der);

    for(int i = 0; i < izq; i++)
    {
        laizq[i] = lista[inicio + i];
    }
    for (int j = 0; j < der; j++)
    {
        lader[j] = lista[mitad + 1 + j];
    }

    while (i < izq && j < der)
    {
        if (laizq[i] <= lader[j])
        {
            lista[k] = laizq[i];
            i++;
        }
        else
        {
            std::cout << laizq[i] << " - " << lader[j] << std::endl;

            contador = contador + (izq-i);
            std::cout << contador << std::endl;

            lista[k] = lader[j];
            j++;
        }
        k++;
    }

    while (j < der) {
        lista[k] = lader[j];
        j++;
        k++;
    }
    while (i < izq)
    {
        lista[k] = laizq[i];
        i++;
        k++;
    }
    return contador;
}

void mergesort(std::vector<int>& lista, int inicio, int final)
{
    if (inicio < final)
    {
        static int contador = 0;
      
        int mitad = inicio + (final - inicio) / 2;
        mergesort(lista, inicio, mitad);
        mergesort(lista, mitad + 1, final);
        merge(lista, inicio, mitad, final, contador);
   
    }

}

void print(std::vector<int> lista)
{
    for (int i = 0; i < lista.size(); i++)
    {
        std::cout << lista[i] << ", ";
    }
}

int main()
{
    std::vector<int> mi = {3 ,7 ,10 ,14 ,18 ,19 ,2 ,11 ,16 ,17 ,23, 25 };
    mergesort(mi, 0, mi.size() - 1); 
}