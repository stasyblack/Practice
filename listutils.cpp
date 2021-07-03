#include <iostream>
#include <Windows.h>
using namespace std;

const int m = 5;// ����� ������ �� m ���������
const int n = 10;//���������� ��������� � ������

struct Node {
  int val;
  void init(Node& node);
  Node* next;
};

class List
{
    Node* head;
public:
    List() :head(NULL) {}; //����������� �� ��������� (Head=NULL)
    ~List();    //�������� �����������
    void initNode(int n);
    void show();
    void pushNode(Node& node);
    void rShiftList(Node& node, int m);
    int testEmptyList();
    int testrShiftList(int n, int m);
};

List::~List()
{
    while (head != NULL)                //���� �� ������ ���� ���� ���-��
    {
        Node* temp;
        temp = head->next;     //����� ���������� ��������� �� ����� ���������� �������� ���������
        delete head;                    //����������� ������ �� ����� ������ ������
        head = temp;                    //������ ����� ������ ������
    }

}

// ������������� �������� ������������ ������ ������

void Node::init(Node& node)
{
    node.val = 12;//��������� �������� ��� ������������ �������� � ������
}

// ����������� ������������ ������ �� �����
void List::show() 
{
    Node* temp;
    temp = head;// ��������� �� ������ ������
    while (temp != NULL) //���� �� ����� �� ����� ������
    {
        //����� �������a ���������
        cout << temp->val << "\t";
        temp = temp->next; // ��������� �� ��������� ����� �� ������
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
        temp = new Node; //��������� ������ ��� ����� ���������
        temp->next = head;
        temp->val = initVal;
        head = temp;// ����� ������ ������ ������
    }
}

// ���������� �������� � ����������� ������
void List::pushNode(Node& node)
{
    Node* temp;
    temp = new Node; //��������� ������ ��� ����� ���������
    temp->next = head;
    temp->val = node.val;
    head = temp;// ����� ������ ������ ������
} 


// �������� ������� ������ �������� ������ �� n-��������� � ����������� ������� ��������� ������
void List::rShiftList(Node& node, int n)
{
    int i, num, numNext;
    Node* temp;
    for (i = 0; i < n; i++)
    {
        temp = head;// ��������� �� ������ ������
        num = temp->val;
        temp->val = 0;
        while (temp->next != NULL) //���� �� ����� �� ����� ������
        {

            temp = temp->next; // ��������� �� ��������� ����� �� ������
            swap(temp->val, num);
        }
    }
}


int List::testEmptyList()
{
    if (head == NULL)
    {
        cout << "������: ������ ����";
        return -1;
    }
    return 0;
}

int List::testrShiftList(int n, int m)
{
    if (m > n + 1)
    {
        cout << "������: ����� ��������� ���������� ���������";
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