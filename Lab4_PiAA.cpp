// Lab4_PiAA.cpp: определяет точку входа для консольного приложения.
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
int d[LEN + 1][LEN + 1];//редакционное расстояние
int p[LEN + 1][LEN + 1];//код операции (вставка 2, удаление 0, замена 1)
void edit(int l1, int l2, string s1, string s2);
int main()
{
	setlocale(LC_ALL, "russian");
	int count;
	cout << "Выберите одно из предложенных действий:\nНажмите 1, чтобы ввести данные с клавиатуры.\nНажмите 2, чтобы прочитать из файла "<< endl;
	cin >> count;
	switch (count)
	{
	case 1: {


		string s1, s2;
		cout << "Введите перую строку:\n";
		cin >> s1;
		cout << "Введите вторую строку:\n";
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
		cout << "Введённые строки:\n" << s1 << "\n" << s2 << endl;
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
			if (i < l1 && j < l2 && s1[i] == s2[j])//элементы равны
			{
				//cout << "Равные элементы! " << s1[i] << " и " << s2[j] << endl;
				d[i][j] = d[i + 1][j + 1];
				p[i][j] = 3;
			}
			if (i + 1 <= l1)//удалить символ
			{

				if (d[i + 1][j] + 1 < d[i][j])
				{


					d[i][j] = d[i + 1][j] + 1;
					p[i][j] = 0;
					//cout << "Различные элементы! " << d[i][j] << " Первый : " << s1[i] << " Второй : " << s2[j] << endl;
				}

			}
			if (i + 1 <= l1 && j + 1 <= l2)//можно заменить символ из первой стр на символ из второй
			{
				if (d[i + 1][j + 1] + 1 < d[i][j])
				{
					d[i][j] = d[i + 1][j + 1] + 1;
					p[i][j] = 1;

				}
			}
			if (j + 1 <= l2)//добавить в начало строки символ из второй и исключить эти символы из рассмотрения
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




