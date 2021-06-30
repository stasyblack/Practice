#include <iostream>
#include <Windows.h> 
#include <limits>
using namespace std;

int testrShiftMas();
void rShiftMas(int* source, int n, int size);
int source[1000];
int size0 = 10;
int testrShiftMas()
{
    int source[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = 10;
    int n = 3;
    if (n <= size)
        rShiftMas(source, n, size);
    else
        return -1;
    return 0;
}
void rShiftMas(int* source, int n, int size)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = size-1; i >= j; i--)
        {
            int m;
            m = source[i - 1];
            source[i] = m;
            if (i == 0)
                source[i] = 0;
        }
    }
    for (int i = 0; i < size0; i++)
        cout << source[i];
    cout << "\n";
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n1, i;
    if (testrShiftMas() == -1)
        cout << "Неправильные исходные данные";
    else
        cout << "Тест ок";
}
