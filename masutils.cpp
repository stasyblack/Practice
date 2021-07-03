#include <iostream>
#include <Windows.h>
using namespace std;


const int MASSIZE = 1000;
int mas[MASSIZE]={};

// Вариант 5:
// Написать функцию сдвига вправо на n-элементов с заполнением крайних элементов нулями

void rShiftMas(int* source,int n, int size) 
{
    int temp;
    for (int i = 0; i < n; i++)
    {   
        temp = 0;
        for (int j = i; j < size; j++)
        {
            swap(temp, source[j]);
        }
    }
    for (int i = 0; i < size; i++)
        cout << source[i]<<"   ";
    cout << "\n";
}




// Вариант 5:
// Написать функцию сдвига вправо на n-элементов с заполнением крайних элементов нулями


int testrShiftMas() 
{
    int source[] = { 1, 2, 3, 4, 5, 6, 7, 8,9,10};
    int n = 3;
    int size=10;
    int realSize;
    realSize = sizeof(source) /sizeof(int);
    if (size > realSize)
    {
        std::cout << "Элементов меньше, чем заданный размер массива " << " - FAIL" << std::endl;
        size = realSize;
    } 
    if ((n <= size)&&(n>0))
        rShiftMas(source,n,size);
    else
        return -1;
    return 0;
}




void runTest(int (*testFunction)(),const std::string& testName)
{
  if(testFunction()==0)
    std::cout << "Test "<< testName << " - OK" << std::endl;
  else 
    std::cout << "Test "<< testName << " - FAIL" << std::endl;
}



int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    runTest(testrShiftMas,"testrShiftMas");
}

