#include <iostream>
#include <fstream> 
#include <Windows.h>
using namespace std;
struct Image 
{
  int mx=6;
  int my=10;
  int* points;  //�������� �������� mx * my
  void createImage(Image* img);
  void showImage(Image* img);
  void setPointImage(Image* img, int x, int y, int color);
  int getPointImage(Image* img, int x, int y);
  int testSaveToPnmFile(string fileName);
  int saveToPnmFile(Image* img, string fileName);
  int testCreateImage();
  int testGetPointImage(int x, int y);
  int testSetPointImage(int color);
  void dataImage(Image* img);
};

void Image::dataImage(Image* img)
{
	points[4] = 1;
	points[10] = 1;
	points[16] = 1;
	points[22] = 1;
	points[28] = 1;
	points[34] = 1;
	points[40] = 1;
	points[45] = 1;
	points[44] = 1;
	points[43] = 1;
	points[36] = 1;
}

// �������� �����������
void Image::createImage(Image* img) 
{
  // �������� ������  �������� tmx * tmy 
	int n = mx * my;
	points = new int[n];
	for (int i = 0; i < n; i++)
		points[i] = 0;
	dataImage(img);

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


void Image::showImage(Image* img)
{
  // ������� �������� �� ����� ��� ������ cout ��� 
	int n;
	for (int i = 0; i < my; i++)
	{
		for (int j = 0; j < mx; j++)
		{
			n = (i * mx + j);
			cout << points[n] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


// ��������� ����� �� �����������
//  ���������� �������� � ������� points - ����� � ������������ mx*y+x � ����� color
//  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  1 0 0 0 1 0  0 1 1 1 0 0  0 0 0 0 0 0  0 0 0 0 0 0
   

void Image::setPointImage(Image* img,int x, int y,int color) 
{
	int n;
	n = x * mx + y;
	points[n] = color;
}


// ��������� ����� �� �����������
int Image::getPointImage(Image* img,int x, int y)
{
	int n, color;
	n = x * mx + y;
	color=points[n];
	return color;
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


int Image::testSaveToPnmFile(string fileName)
{
	if (fileName == "")
	{
		cout << "������ �������� �����";
		return -1;
	}
	return 0;
}

int Image::saveToPnmFile(Image* img, string fileName) 
{
	if (testSaveToPnmFile(fileName) == -1)
		return -1;
	fstream fout(fileName, ios::out);
	int n;
	fout << "P1" << endl;
	fout << mx << " " << my << endl;
	for (int i = 0; i < my; i++)
	{
		for (int j = 0; j <mx; j++)
		{
			n = (i * mx + j);
			fout << points[n] << " ";
		}
		fout << endl;
	}
	fout << endl;
	fout.close();
}



int Image::testCreateImage()
{
	if ((mx <= 0) || (my <= 0))
	{
		cout << "������ ����� ������� �����������";
		return -1;
	}
	return 0;
}

int Image::testGetPointImage(int x, int y)
{
	if ((x > mx) || (y > my))
	{
		cout << "������ � ������� ���������� �����";
		return -1;
	}
}

int Image::testSetPointImage(int color)
{
	if ((color < 0) || (color > 255))
	{
		cout << "������ � ������� �����";
		return -1;
	}
	return 0;
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Image img;
	int x = 1;
	int y = 4;
	int color = 0;
	if (img.testCreateImage() == -1)
		return -1;
	img.createImage(&img);
	img.showImage(&img);
	if (img.testGetPointImage(x, y) == -1)
		return -1;
	if (img.testSetPointImage(color) == -1)
		return -1;
	img.setPointImage(&img, x, y, color);
	img.showImage(&img);
	if (img.saveToPnmFile(&img, "image1.pnm") == -1)
		return -1;
	x = 2;
	y = 4;
	if (img.testGetPointImage(x, y) == -1)
		return -1;
	cout<< "���� ����� � ������������ ("<<x<<", "<<y<<"):" << img.getPointImage(&img, x,  y);

	delete[] img.points;
	
	return 0;
}
