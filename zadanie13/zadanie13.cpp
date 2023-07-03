#include <iostream>
#include<locale.h>
#include<stdlib.h>
#include <time.h>
using namespace std;
void autor(void) {
	printf("\n");
	for (int i = 1; i <= 120; i++) cout << "*";
	cout << "Autor programu: Simon Dudek\n\n";
	for (int i = 1; i <= 120; i++) cout << "*";
}
void wyswietl(int rozmiar ,int ***tab) {
	for (int i = 0, j = 0, k=0; i < rozmiar && j < rozmiar && k<rozmiar; i++) {
		cout << tab[k][j][i]<<" ";
		if (i == rozmiar - 1) {
			cout << endl;
			i = -1;
			j++;
		}
		if (j == rozmiar) {
			cout << "\n\n";
			j = 0;
			k++;
		}

	}
}
void los(int x, int ***tab, int pocz, int kon, int kontroler) {
	srand(kontroler);
	if (pocz == 0) {
		kon++;
		for (int i = 0, j = 0, k=0; i < x && j < x && k<x; i++) {
			tab[k][j][i] = (pocz + rand() % kon);
			if (i == x - 1) {
				i = -1;
				j++;
			}
			if (j == x) {
				j = 0;
				k++;
			}
		}
	}
	else {
		if (pocz > 0) {
			kon -= pocz - 1;
			for (int i = 0, j = 0, k=0; i < x && j < x &&k<x; i++) {
				tab[k][j][i] = (pocz + rand() % kon);
				if (i == x - 1) {
					i = -1;
					j++;
				}
				if (j == x) {
					j = 0;
					k++;
				}
			}
		}
		else {
			kon += (pocz * (-1)) + 1;
			for (int i = 0, j = 0, k=0; i < x && j < x &&k<x; i++) {
				tab[k][j][i] = (pocz + rand() % kon);
				if (i == x - 1) {
					i = -1;
					j++;
				}
				if (j == x) {
					j = 0;
					k++;
				}
			}
		}
	}
}
void los(int x, int*** tab, int kontroler) {
	srand(kontroler);
	for (int i = 0, j = 0, k = 0; i < x && j < x && k < x; i++) {
		tab[k][j][i] = (0 + rand() % 10);
		if (i == x - 1) {
			i = -1;
			j++;
		}
		if (j == x) {
			j = 0;
			k++;
		}
	}
		
}
int main()
{
	setlocale(LC_ALL, "");
	int*** dynamo=NULL;
	int n, control, min, max;
	time_t t;
	control = time(&t);
	autor();
	cout << "Podaj wymiar sześcianu: ";
	cin >> n;
	cout << endl;
	dynamo = (int***)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		dynamo[i] = (int**)malloc(sizeof(int) * n);
	}
	for (int i = 0, j=0; i < n && j<n; i++) {
		dynamo[j][i] = (int*)malloc(sizeof(int)*n);
		if (i == n- 1) {
			i = -1;
			j++;
		}
	}
	cout << "Losowanie z zakresu podanego przez użytkownika.\n";
	cout << "Podaj zakres losowanych liczb.\n";
	cout << "Początek: ";
	cin >> min;
	cout << "Koniec: ";
	cin >> max;
	while (min >= max) {
		cout << "Błędne wpisanie zakresu! Aby zdefiniować liczba początkowa musi być mniejsza niż liczba końcowa!\n";
		cout << "Początek: ";
		cin >> min;
		cout << "Koniec: ";
		cin >> max;
	}
	cout << endl;
	los(n, dynamo, min, max, control);
	wyswietl(n, dynamo);
	control = time(&t);
	cout << "Losowanie z zakresu 0-9\n\n";
	los(n, dynamo, control);
	wyswietl(n, dynamo);
	free(dynamo);
	system("pause");
	return 0;
}
