#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>


using namespace std;



int mediana3(int arr[], int low, int high)
{
    if (high - low < 3) return arr[low];
    else
    {
        int* med = new int[3];
        med[0] = arr[low];
        med[1] = arr[low + ((high - low) / 2)];
        med[2] = high;
        sort(med, med + 3);
        int ans = med[1];
        delete[] med;
        return ans;
    }
}


int mediana5(int arr[], int low, int high)
{
    if (high - low < 5) return mediana3(arr, low, high);
    else
    {
        int* med = new int[5];
        med[0] = arr[low];
        med[1] = arr[low + ((high - low) / 5)];
        med[2] = arr[low + ((high - low) / 2)];
        med[3] = arr[high - ((high - low) / 5)];
        med[4] = high;
        sort(med, med + 5);
        int ans = med[2];
        delete[] med;
        return ans;
    }
}

int mediana7(int arr[], int low, int high)
{
    if (high - low < 7) return mediana5(arr, low, high);
    else
    {
        int* med = new int[7];
        med[0] = arr[low];
        med[1] = arr[low + ((high - low) / 7)];
        med[2] = arr[(low + ((high - low) / 7) * 2)];
        med[3] = arr[low + ((high - low) / 2)];
        med[4] = arr[(high - ((high - low) / 7) * 2)];
        med[5] = arr[high - ((high - low) / 7)];
        med[6] = high;
        sort(med, med + 7);
        int ans = med[3];
        delete[] med;
        return ans;
    }
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);       
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

int randomized_partition(int arr[], int low, int high)
{

    srand(time(NULL));

    int random = low + (rand()*rand() % (high - low));


    swap(arr[random], arr[low]);

    return partition(arr, low, high);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high) // konczy rekurencje jezeli tablica ma 2 elementy
    {
        int pivot = randomized_partition(arr, low, high); //wyznacza czesc podzialu tablicy

        quickSort(arr, low, pivot); // sortuje lewa czesc tablicy
        quickSort(arr, pivot + 1, high); // sortuje prawa czesc tablicy
    }
}

ofstream out;

void printArray(int arr[], long long int size)
{
    int i;
    for (i = 0; i < size; i++)
        out << arr[i] << endl;
    cout << endl;
}


int main()
{

    
    ifstream in;

    int tmp = 0;
    int ilosc = 10000;
    out.open("wynikiRandomPivot_0k_test.txt");
    string plik;
    string plikk;

    while (ilosc < 10100)
    {
        plik = to_string(ilosc) + "data0_k.txt";
        in.open(plik);
        tmp = 0;

        int* arr = new int[ilosc];
        for (int i = 0; i < ilosc; i++)
        {
            in >> tmp;
            arr[i] = tmp;
        }

        in.close();

        
        clock_t start = clock();

        quickSort(arr, 0,ilosc - 1);
      
        clock_t end = clock();

        double dur = ((double)end - (double)start);

       
        
        //out << ilosc << ";" << dur << endl;

        printArray(arr, ilosc);

        ilosc = ilosc + 10000;
        delete[] arr;
    }


    out.close();

    return 0;
}
