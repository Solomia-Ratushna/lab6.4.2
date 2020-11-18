#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Input(int* a, const int size, int i)
{
    cout << "a[" << i << "] = ";
    cin >> a[i];

    if (i < size - 1)
        Input(a, size, i + 1);
    else
        cout << endl;
}
void Sort(int* a, const int size, int i) // i - параметр зовнішнього циклу
{ // ітераційної версії
    int min = a[i];
    int imin = i;
    for (int j = i + 1; j < size; j++)
        if (min > a[j])
        {
            min = a[j];
            imin = j;
        }
    a[imin] = a[i];
    a[i] = min;

    if (i < size - 2)
        Sort(a, size, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}
int Max(int* a, const int size, int i, int max)
{
    if (a[i] > a[max])
        max = i;
    if (i < size - 1)
        return Max(a, size, i + 1, max);
    else
        return max;
}
int Min(int* a, const int size, int i, int min)
{
    if (a[i] < a[min])
        min = i;
    if (i < size - 1)
        return Min(a, size, i + 1, min);
    else
        return min;
}
int S1(int* a, const int size, int max_v, int min_v, int i, int p)
{
    if ((a[i] == a[min_v] && a[i + 1] == a[max_v]) || (a[i] == a[max_v] && a[i + 1] == a[min_v]))
        return p;
    if (a[i] == a[min_v])
    {
        for (i = i + 1; i < max_v; i++)
            p *= a[i];
        i = size + 1;
    }
    else;
    if (a[i] == a[max_v])
    {
        for (i = i + 1; i < min_v; i++)
            p *= a[i];
        i = size + 1;
    }
    else;
    if (i < size - 1)
        return S1(a, size, max_v, min_v, i + 1, p);
    else
        return p;
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    const int n = 5;
    int a[n];
    int Low = -10;
    int High = 10;
    Input(a, n, 0);
    Print(a, n, 0);
    Sort(a, n, 0);
    Print(a, n, 0);


    int max_v = Max(a, n, 1, 0);
    int min_v = Min(a, n, 1, 0);

    cout << "max = " << a[max_v] << endl;//вивід макс
    cout << "min = " << a[min_v] << endl;//вивід мін
    int p = S1(a, n, max_v, min_v, 0, 1);
    if (p == 1)
        cout << "ne mae elementiv v promishky " << endl;
    else
        cout << "S1 = " << p << endl;

    return 0;
}