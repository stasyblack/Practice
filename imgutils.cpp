#include <iostream>

struct Image {
  int mx;
  int my;
  int* points;  //�������� �������� mx * my
};



// �������� �����������
void createImage(Image* img,int tmx, int tmy) {
  // �������� ������  �������� tmx * tmy 

}


// ����������� ����������� �� ����� � pnm �������
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  1 0 0 0 1 0
//  0 1 1 1 0 0
//  0 0 0 0 0 0
//  0 0 0 0 0 0


void showImage(Image* img) {
  // ������� �������� �� ����� ��� ������ cout ��� 

}


// ��������� ����� �� �����������
//  ���������� �������� � ������� points - ����� � ������������ mx*y+x � ����� color
//  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  1 0 0 0 1 0  0 1 1 1 0 0  0 0 0 0 0 0  0 0 0 0 0 0
   

void setPointImage(Image* img,int x, int y,int color) {

}


// ��������� ����� �� �����������
int getPointImage(Image* img,int x, int y) {

  return 0;
}


// ����������� ����������� �� ����� � pnm ������� - P1
// https://en.wikipedia.org/wiki/Netpbm#File_formats
//
//  P1
//  6 10
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  0 0 0 0 1 0
//  1 0 0 0 1 0
//  0 1 1 1 0 0
//  0 0 0 0 0 0
//  0 0 0 0 0 0
//  ���� ����� ������� � gimp

void saveToPnmFile(Image* img, string fileName) {


}

int main() {
  return 0;
}
