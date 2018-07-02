#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<Windows.h>
#include<fstream>
#include<sstream>

using namespace std;

template<typename T>
T convert(string &s)
{
	stringstream c(s);
	T rezultat;
	c >> rezultat;

	return rezultat;


}

void load(ifstream &in, unordered_map<string, int> &mapa)
{
	string lajn;
	while (getline(in, lajn))
	{
		//cout << lajn << endl;
		stringstream sstr(lajn);
		string ime;
		getline(sstr, ime, ',');

		string temp;
		getline(sstr, temp, ',');

		getline(sstr, temp);
		int broj = convert<int>(temp);

		mapa[ime] += broj;
		
	}
}

void write(unordered_map<string, int> &mapa, ofstream &out)
{
	for (auto it = mapa.begin(); it != mapa.end(); ++it)
	{
		if (it->first[0] == 'A')
		{
			out << it->first << "," << it->second << endl;
		}
	}
}

int main()
{
	ofstream out("Nova.txt");
	ifstream in("yob1991.txt");
	if (!in || !out)
	{
		cout << "404" << endl;
		return 1;
	}

	unordered_map<string, int> mapa;

	load(in, mapa);

	/*for (auto it = mapa.begin(); it != mapa.end(); ++it)
	{
		
			cout << it->first << "," << it->second << endl;
		
	}*/

	in.close();

	write(mapa, out);

	out.close();

	system("pause");
	return 0;
}
