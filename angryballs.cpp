#include <iostream>

/*
  Y^
   |
   |
   |
  -|--------->
             Y
*/

struct Ball {
  float x=0;
  float y=0;
  float vx=0;
  float vy=0;
  float ax=0;
  float ay=0;
  float m=0;

  Ball() {
  }
};

// ������������� ��������� ��������� ������ �� ����� dt � ��������
void move(Ball* ball, float dt) {

}

// ���������� �� ����� ��������� ������ ������
void show(Ball ball) {

}

int main() {
  float t = 0;
  Ball a;
  float deltaT = 1.;           // ������������ ����� �������������

  // ������ ��������� ������� (���������, ��������, ���������)
  // TODO

  for (int i=0; i<100; i++) {
     move(&a, deltaT);         // �������� ����� �� ���� ���� �������������

     cout << t;
     show(a);

     t = t + deltaT;           // ��������� ������� �������
  }
}