#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<Windows.h>
#include<fstream>
#include<sstream>

using namespace std;

void New_city(unordered_map<int, string> &mapa)
{
	system("cls");

	int kljuc;
	string grad;

	cout << "Grad:" << endl;
	getline(cin, grad);

	cout << "Postanski broj:" << endl;
	cin >> kljuc;
	cin.ignore();

	mapa.insert({ kljuc,grad });
}

void Search(unordered_map<int, string> &mapa)
{
	system("cls");

	int kljuc;
	
	bool ima_ga;
	

	cout << "Postanski broj:" << endl;
	cin >> kljuc;
	cin.ignore();

	for (auto it = mapa.begin(); it != mapa.end(); ++it)
	{
		if (kljuc == it->first)
		{
			ima_ga = true;
			cout << it->second << endl;
			break;
		}
		else
		{
			ima_ga = false;
		}
	}
	if (!ima_ga)
	{
		cout << "Nema ga" << endl;
		
	}
}

void Delete(unordered_map<int, string> &mapa)
{
	system("cls");

	int kljuc;

	bool ima_ga;


	cout << "Postanski broj:" << endl;
	cin >> kljuc;
	cin.ignore();

	for (auto it = mapa.begin(); it != mapa.end(); ++it)
	{
		if (kljuc == it->first)
		{
			ima_ga = true;
			mapa.erase(it);
			break;
		}
		else
		{
			ima_ga = false;
		}
	}
	if (!ima_ga)
	{
		cout << "Nema ga" << endl;

	}
}

void Print(unordered_map<int, string> &mapa)
{

	system("cls");
	for (auto it = mapa.begin(); it != mapa.end(); ++it)
	{
		cout << it->first << "," << it->second << endl;
	}

}

int main()
{
	unordered_map<int, string> mapa;
	int n;
	do
	{
		cout << "1. Unos grada" << endl;
		cout << "2. Pretrazi grad" << endl;
		cout << "3. Brisanje grada" << endl;
		cout << "4. Ispis svih" << endl;
		cout << "5. Izlaz" << endl;

		cout << "Vas odabir:" << endl;
		cin >> n;
		cin.ignore();

		switch (n)
		{
			

		case 1:
			New_city(mapa);
			break;
		case 2:
			Search(mapa);
			break;
		case 3:
			Delete(mapa);
			break;
		case 4:
			Print(mapa);
			break;
		}
		

	} while (n != 5);



	system("pause");
	return 0;
}
