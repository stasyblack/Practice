#include <iostream>
#include <Windows.h> 
#include <limits>
using namespace std;

int source[1000];
const int size0 = 10;//размерность массива
const int n = 3;//размер сдвига

void rShiftMas(int* source)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = size0 - 1; i >= j; i--)
        {
            int m;
            m = source[i - 1];
            source[i] = m;
            if (i == 0)
                source[i] = 0;
        }
    }
    for (int i = 0; i < size0; i++)
        cout << source[i]<<" ";
    cout << "\n";
}

int testrShiftMas()
{
    int source[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    if (n <= size0)
        rShiftMas(source);
    else
        return -1;
    return 0;
}

int testEmptyArray()
{
    if (size0 == 0)
        return -1;
    return 0;
}

int testManyElements()
{
    int m = 10;//максимальный размер массива
    if (size0 > m)
        return -1;
    return 0;
}

int runTest(int (*testFunction)(), const std::string& testName)
{
    if (testFunction() == -1)
    {
        std::cout << "Test " << testName << " - FAIL" << std::endl;
        return -1;
    }
    std::cout << "Test " << testName << " - OK" << std::endl;
    return 0;
        
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n1, i;
    if (runTest(testManyElements, "testManyElements") == -1)
        return -1;
    if (runTest(testrShiftMas, "testrShiftMas") == -1)
        return -1;
    
    runTest(testEmptyArray, "testEmptyArray");
}