#include <iostream>
#include <Windows.h> 
#include <limits>
using namespace std;


struct Node 
{
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
    void initNode();
    void show();
    void pushNode(Node& node);
    void rShiftList(Node& node, int n);
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
void Node::init(Node& node)
{
    node.val = 12;
}

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

void List::initNode()
{
    Node* temp;
    int i;
    int n = 10;
    int initVal = 0;
    for (i = 0; i < n; i++)
    {
        temp = new Node; //выделение памяти под новую структуру
        temp->next = head;
        temp->val = initVal;
        head = temp;// смена адреса начала списка
    }
}

void List::pushNode(Node& node)
{
    Node* temp;
    temp = new Node; //выделение памяти под новую структуру
    temp->next = head;
    temp->val = node.val;
    head = temp;// смена адреса начала списка
}

void List::rShiftList(Node& node, int n)
{
    int i, num,numNext;
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

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node node;
    int n = 5;
    List lst;
    lst.initNode();
    lst.show();
    node.init(node);
    lst.pushNode(node);
    lst.show();
    lst.rShiftList(node, n);
    lst.show();
}