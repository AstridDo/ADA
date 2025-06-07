#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;
void prim(map<char, vector<pair<char, int>>> graf)
{
    char inicio;
    cout << "Nodo de inicio: ";
    cin >> inicio;

    if (graf.find(inicio) == graf.cend())
    {
        cout << "Nodo no existe";
        return;
    }

    map <char, bool> visi;


    priority_queue <pair <int, pair <char, char>>, vector<pair<int, pair<char, char>>>, greater<>> lis;
    visi[inicio] = true;
    

    vector <pair<char, int>> veci = graf[inicio];

    char desti;
    int peso;
    int peso_tot = 0;

    for (int i = 0; i < veci.size(); i++)
    {
        desti = veci[i].first;
        peso = veci[i].second;

        lis.push({peso, { inicio, desti }});
    }

    while (!lis.empty())
    {
        pair<int, pair<char, char>> ahora = lis.top();
        lis.pop();

        inicio = ahora.second.first;
        desti = ahora.second.second;
        peso = ahora.first;

        if (visi[desti])
        {
            continue;
        }

        visi[desti] = true;
        peso_tot = peso_tot + peso;


        cout << inicio << "  ->  " << desti << " con peso: " << peso << endl;

        veci = graf[desti];
        for (int i = 0; i < veci.size(); i++)
        {
            char de = veci[i].first;
            peso = veci[i].second;

            if (!visi[de])
            {
                lis.push({ peso, { desti, de } });
            }
        }
        
    }

    cout << "Costo total: " << peso_tot;
}



int main() {
    map<char, vector<pair<char, int>>> cont;
    cont['A'] = { {'D',3},{'C', 3}, {'B', 2} };

    cont['B'] = { {'A',2},{'C', 4}, {'E', 3} };
    cont['C'] = { {'A',3 }, { 'B', 4 }, { 'E', 1 },{'F', 6},{'D',5} };
    cont['D'] = { {'A',3 }, { 'C', 5 },{'F', 7} };
    cont['F'] = { {'D',7 }, { 'C', 6 }, { 'E', 1 },{'E', 8},{'G',9} };
    cont['G'] = { {'F',9} };

    prim(cont);

};