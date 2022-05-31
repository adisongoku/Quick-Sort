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

