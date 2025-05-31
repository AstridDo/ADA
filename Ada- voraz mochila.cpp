

#include <iostream>

int min(int cant_conte, int menor, int* _pesos, int& idx_menor, float* solucion)
{
	for (int i = 0; i < cant_conte; i++)
	{
		if (menor > _pesos[i] && solucion[i] == 0)
		{
			menor = _pesos[i];
			idx_menor = i;
		}
	}
	return menor;
}

void mochila(float capacidad, int cant_conte)
{

	int* _pesos = new int[cant_conte];
	int n;


	for (int i = 0; i < cant_conte; i++)
	{
		std::cout << "Ingrese pesos de contenedores: ";

		std::cin >> n;
		_pesos[i] = n;
	}

	float* solucion = new float[cant_conte];

	for (int i = 0; i < cant_conte; i++)
	{
		solucion[i] = 0;
	}

	int p = cant_conte - 1;
	int menor = INT_MAX;
	int idx_menor = 0;
	int low;
	int hasta = cant_conte;
	float frac = 0;
	float total = 0;
	while (capacidad > 0 && hasta > 0)
	{
		low = min(cant_conte, menor, _pesos, idx_menor, solucion);
		if (capacidad > low)
		{
			capacidad = capacidad - low;
			total = total + 1;
			solucion[idx_menor] = 1;
			hasta = hasta - 1;
		}
		else
		{
			frac = float(capacidad / low);
			capacidad = capacidad - frac;
			total = total + frac;
			solucion[idx_menor] = frac;
			hasta = hasta - 1;
		}
	}

	std::cout << "\nContenedores usados " << std::endl;
	for (int i = 0; i < cant_conte; i++)
	{
		std::cout << solucion[i] << "  ";
	}
	std::cout << "\n\nTotal de contenedores usados:\n  " << total << "\n\n";
}

int main()
{
	std::cout << "Ingrese capacidad de buque: ";
	int n;
	std::cin >> n;
	std::cout << "\nIngrese cantidad de contenedores: ";
	int m;
	std::cin >> m;
	std::cout << std::endl;
	mochila(n, 5);
}