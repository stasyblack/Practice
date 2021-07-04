#include <iostream>
#include <fstream> 
#include <Windows.h>
using namespace std;
struct Image 
{
  int mx;
  int my;
  int* points;  //�������� �������� mx * my
};


// �������� �����������
void createImage(Image* img,int tmx, int tmy) 
{
  // �������� ������  �������� tmx * tmy 
	img->mx = tmx;
	img->my = tmy;
	int n = tmx * tmy;
	img->points = new int[n];
	for (int i = 0; i < n; i++)
		img->points[i] = 0;
	img->points[4] = 1;
	img->points[10] = 1;
	img->points[16] = 1;
	img->points[22] = 1;
	img->points[28] = 1;
	img->points[34] = 1;
	img->points[40] = 1;
	img->points[45] = 1;
	img->points[44] = 1;
	img->points[43] = 1;
	img->points[36] = 1;

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


void showImage(Image* img, int tmx, int tmy)
{
  // ������� �������� �� ����� ��� ������ cout ��� 
	int n;
	for (int i = 0; i < tmy; i++)
	{
		for (int j = 0; j < tmx; j++)
		{
			n = (i * tmx + j);
			cout << img->points[n] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


// ��������� ����� �� �����������
//  ���������� �������� � ������� points - ����� � ������������ mx*y+x � ����� color
//  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  0 0 0 0 1 0  1 0 0 0 1 0  0 1 1 1 0 0  0 0 0 0 0 0  0 0 0 0 0 0
   

void setPointImage(Image* img,int x, int y,int color,int tmx) 
{
	int n;
	n = x * tmx + y;
	img->points[n] = color;
}


// ��������� ����� �� �����������
int getPointImage(Image* img,int x, int y, int tmx)
{
	int n, color;
	n = x * tmx + y;
	color=img->points[n];
	cout << "����� (" << x << ", " << y << ") ����� ���� - " << color << endl;
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


int testSaveToPnmFile(string fileName)
{
	if (fileName == "")
	{
		cout << "������ �������� �����";
		return -1;
	}
	return 0;
}

int saveToPnmFile(Image* img, string fileName, int tmx,int tmy) 
{
	if (testSaveToPnmFile(fileName) == -1)
		return -1;
	fstream fout(fileName, ios::out);
	int n;
	fout << "P1" << endl;
	fout << tmx << " " << tmy << endl;
	for (int i = 0; i < tmy; i++)
	{
		for (int j = 0; j < tmx; j++)
		{
			n = (i * tmx + j);
			fout << img->points[n] << " ";
		}
		fout << endl;
	}
	fout << endl;
	fout.close();
}



int testCreateImage(int tmx, int tmy)
{
	if ((tmx <= 0) || (tmy <= 0))
	{
		cout << "������ ����� ������� �����������";
		return -1;
	}
	return 0;
}

int testGetPointImage(int x, int y, int tmx, int tmy)
{
	if ((x > tmx) || (y > tmy))
	{
		cout << "������ � ������� ���������� �����";
		return -1;
	}
}

int testSetPointImage(int color)
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
	int tmx = 6;
	int tmy = 10;
	int x = 1;
	int y = 4;
	int color = 0;
	if (testCreateImage(tmx, tmy) == -1)
		return -1;
	createImage(&img, tmx, tmy);
	showImage(&img,tmx,tmy);
	if (testGetPointImage(x, y, tmx, tmy) == -1)
		return -1;
	if (testSetPointImage(color) == -1)
		return -1;
	setPointImage(&img, x, y, color,tmx);
	showImage(&img, tmx, tmy);
	if (saveToPnmFile(&img, "image1.pnm", tmx, tmy) == -1)
		return -1;
	x = 2;
	y = 4;
	if (testGetPointImage(x, y, tmx, tmy) == -1)
		return -1;
	getPointImage(&img, x,  y, tmx);
	delete[] img.points;
	
	return 0;
}
