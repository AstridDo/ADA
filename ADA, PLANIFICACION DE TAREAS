#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool entra(int i, vector<pair<int, int>> temp, vector<int>& solucion, vector<pair<int, int>> bene, int& b)
{
    int limite = temp[bene[i].second].first;

    for (int j = limite - 1; j >= 0; j--) 
    {
        if (j >= solucion.size())
        {
            return false;
        }

        if (solucion[j] == -1) 
        {
            solucion[j] = bene[i].second; 
            b = b + bene[i].first;
            return true;
        }
    }
    return false;
}


vector<int> select(vector<pair<int, int>> bene, vector<pair<int, int>> temp, int n, int& b)
{
    vector<int> solucion(n, -1);
    
    for (int i = 0; i < n; i++)
    {
        entra(i, temp, solucion, bene, b);
    }
    return solucion;
}


void tareas(int n)
{
    vector<pair<int, int>> tiempo(n);
    vector<pair<int, int>> beneficios(n);



    int pide;
    int tem;

    int b = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Beneficio por tarea "<< i + 1 << " :";
        cin >> pide;
        beneficios[i].first = pide;
        beneficios[i].second = i;
        cout << "Tiempo por tarea: " << i + 1 << " :";
        cin >> tem;
        tiempo[i].first = tem;
        tiempo[i].second = i;
    }


    


    sort(beneficios.begin(), beneficios.end(), greater<>());

   
    vector<int> solucion = select(beneficios, tiempo, n, b);

    cout << "\nTareas seleccionadas:\n";

    for (int i = 0; i < n; i++) 
    {
        if (solucion[i] != -1)
        {
            cout << "Tarea " << solucion[i] + 1 << "\n";
           
        }
        
    }
    cout << "Beneficio total: " << b;

}



int main() {
    cout << "Cantidad de tareas: ";
    int n;
    cin >> n;
    tareas(n);

}
