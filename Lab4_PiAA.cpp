// Lab4_PiAA.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;
fstream infile("input.txt");
const int INF = 1E9;
const int LEN = 1000;
int d[LEN + 1][LEN + 1];//������������ ����������
int p[LEN + 1][LEN + 1];//��� �������� (������� 2, �������� 0, ������ 1)
void edit(int l1, int l2, string s1, string s2);
int main()
{
	setlocale(LC_ALL, "russian");
	int count;
	cout << "�������� ���� �� ������������ ��������:\n������� 1, ����� ������ ������ � ����������.\n������� 2, ����� ��������� �� ����� "<< endl;
	cin >> count;
	switch (count)
	{
	case 1: {


		string s1, s2;
		cout << "������� ����� ������:\n";
		cin >> s1;
		cout << "������� ������ ������:\n";
		cin >> s2;

		int l1 = s1.length();
		int l2 = s2.length();
		d[l1][l2] = 0;
		edit(l1, l2, s1, s2);
		break;

	}
	case 2: {
		string s1, s2;
		infile >> s1;
		infile >> s2;
		cout << "�������� ������:\n" << s1 << "\n" << s2 << endl;
		int l1 = s1.length();
		int l2 = s2.length();
		d[l1][l2] = 0;
		edit(l1, l2, s1, s2);
		//d[l1][l2] = 0;
		break;
	}
	}
	system("pause");
	return 0;
}



void edit(int l1, int l2, string s1, string s2)
{
	for (int i = l1; i >= 0; --i)
		for (int j = l2; j >= 0; --j)
		{
			if (i == l1 && j == l2)
				continue;
			d[i][j] = INF;
			if (i < l1 && j < l2 && s1[i] == s2[j])//�������� �����
			{
				//cout << "������ ��������! " << s1[i] << " � " << s2[j] << endl;
				d[i][j] = d[i + 1][j + 1];
				p[i][j] = 3;
			}
			if (i + 1 <= l1)//������� ������
			{

				if (d[i + 1][j] + 1 < d[i][j])
				{


					d[i][j] = d[i + 1][j] + 1;
					p[i][j] = 0;
					//cout << "��������� ��������! " << d[i][j] << " ������ : " << s1[i] << " ������ : " << s2[j] << endl;
				}

			}
			if (i + 1 <= l1 && j + 1 <= l2)//����� �������� ������ �� ������ ��� �� ������ �� ������
			{
				if (d[i + 1][j + 1] + 1 < d[i][j])
				{
					d[i][j] = d[i + 1][j + 1] + 1;
					p[i][j] = 1;

				}
			}
			if (j + 1 <= l2)//�������� � ������ ������ ������ �� ������ � ��������� ��� ������� �� ������������
			{
				if (d[i][j + 1] + 1 < d[i][j])
				{
					d[i][j] = d[i][j + 1] + 1;
					p[i][j] = 2;
				}
			}
		}
	cout << d[0][0] << endl;
	int curi = 0, curj = 0;
	int ch = 0;
	while (curi < l1 || curj < l2)
	{
		switch (p[curi][curj])
		{
		case 0:

		{
			cout << "DELETE " << curi + ch << endl;
			++curi;
			--ch;
			break;
		}
		case 1:
		{
			cout << "REPLACE " << curi + ch << ' ' << s2[curj] << endl;
			++curi;
			++curj;
			break;
		}
		case 2:
		{
			cout << "INSERT " << curi + ch << ' ' << s2[curj] << endl;
			++curj;
			++ch;
			break;
		}
		case 3:
		{
			++curi;
			++curj;
		}
		}
	}
}




