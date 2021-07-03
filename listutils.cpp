#include <iostream>
#include <Windows.h>
using namespace std;

const int m = 5;// сдвиг списка на m элементов
const int n = 10;//количество элементов в списке

struct Node {
  int val;
  void init(Node& node);
  Node* next;
};

class List
{
    Node* head;
public:
    List() :head(NULL) {}; //Конструктор по умолчанию (Head=NULL)
    ~List();    //Прототип деструктора
    void initNode(int n);
    void show();
    void pushNode(Node& node);
    void rShiftList(Node& node, int m);
    int testEmptyList();
    int testrShiftList(int n, int m);
};

List::~List()
{
    while (head != NULL)                //Пока по адресу есть хоть что-то
    {
        Node* temp;
        temp = head->next;     //Сразу запоминаем указатель на адрес следующего элемента структуры
        delete head;                    //Освобождаем память по месту начала списка
        head = temp;                    //Меняем адрес начала списка
    }

}

// Инициализации элемента односвязного списка нулями

void Node::init(Node& node)
{
    node.val = 12;//начальное значение для добавляемого элемента в список
}

// Отображения односвязного списка на экран
void List::show() 
{
    Node* temp;
    temp = head;// указатель на начало списка
    while (temp != NULL) //пока не дошли до конца списка
    {
        //вывод элементa структуры
        cout << temp->val << "\t";
        temp = temp->next; // указываем на следующий адрес из списка
    }
    cout << endl;
}

void List::initNode(int n)
{
    Node* temp;
    int i;
    int initVal = 0;
    for (i = 0; i < n; i++)
    {
        temp = new Node; //выделение памяти под новую структуру
        temp->next = head;
        temp->val = initVal;
        head = temp;// смена адреса начала списка
    }
}

// Добавления элемента в односвязный список
void List::pushNode(Node& node)
{
    Node* temp;
    temp = new Node; //выделение памяти под новую структуру
    temp->next = head;
    temp->val = node.val;
    head = temp;// смена адреса начала списка
} 


// Написать функцию сдвига значений вправо на n-элементов с заполнением крайних элементов нулями
void List::rShiftList(Node& node, int n)
{
    int i, num, numNext;
    Node* temp;
    for (i = 0; i < n; i++)
    {
        temp = head;// указатель на начало списка
        num = temp->val;
        temp->val = 0;
        while (temp->next != NULL) //пока не дошли до конца списка
        {

            temp = temp->next; // указываем на следующий адрес из списка
            swap(temp->val, num);
        }
    }
}


int List::testEmptyList()
{
    if (head == NULL)
    {
        cout << "Ошибка: список пуст";
        return -1;
    }
    return 0;
}

int List::testrShiftList(int n, int m)
{
    if (m > n + 1)
    {
        cout << "Ошибка: сдвиг превышает количество элементов";
        return -1;
    }
    return 0;
}


int main() 
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  Node node;
  List lst;
  lst.initNode(n);
  if (lst.testEmptyList() == -1)
      return -1;
  lst.show();
  node.init(node);
  lst.pushNode(node);
  lst.show();
  if (lst.testrShiftList(n, m) == -1)
      return -1;
  lst.rShiftList(node, m);
  lst.show();
}