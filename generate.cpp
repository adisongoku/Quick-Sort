#include <iostream>
#include <cstdlib>
#include <vector>	
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> data;
	data.reserve(10000);
	int k = 10000;	
	while (k <=1000000)
	{
		srand(time(NULL));
		data.clear();
		for (int i = 0; i < k - 1; i++)
		{
			data.push_back((rand()*rand() % k + 1000) + 0);			
		}
		sort(data.begin(), data.end());
		ofstream fout(to_string(k) + "dataRos.txt");
		for (auto const& x : data)
			fout << x << '\n';
		k = k + 10000;
	}
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
