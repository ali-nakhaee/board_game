#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <conio.h>
using namespace std;

int q = 0, b, a[16];
string w;

int Start(char a)
{
	cout << "new game (n)" << endl << "show records (s)" << endl << "exit (e)" << endl << endl << endl;
	cout << "help:" << endl << "up -> w" << endl << "down -> x" << endl << "right -> d" << endl << "left -> a" << endl;
	a=_getch();
	if (a == 'n')
	{
		return 1;
	}
	if (a == 's')
	{
		return 2;
	}
	if (a == 'e')
	{
		return 3;
	}
}



void Random(int a[])
{
	int j, i;
	for (i = 0; i<15; i++)
	{
		a[i] = (rand() % 15) + 1;
		for (j = 0; j<i; j++)
		{
			if (a[i] == a[j])
			{
				a[i] = (rand() % 15) + 1;
				j = -1;

			}

		}


	}
	a[15] = 0;
}


string IntToString(int input)
{
	string Result;
	stringstream convert;
	convert << input;
	Result = convert.str();
	return Result;
}


void ShowGame(int a1[])
{	
	string a[16];
	for (int i=0;i<16;i++)
	{
		if (a1[i] == 0)
		{
			a[i] = " ";
			continue;
		}
		a[i] = IntToString(a1[i]);
	}
	cout << (char)218 << "-------" << (char)194 << "-------" << (char)194 << "-------" << (char)194 << "-------" << (char)191 << endl;
	cout << (char)124 << "   " << a[0] << "\t" << "|    " << a[1] << "\t" << "|    " << a[2] << "\t" << "|    " << a[3] << "\t" << (char)124 << endl;
	cout << (char)124 << "-------------------------------" << (char)124 << endl;
	cout << (char)124 << "   " << a[4] << "\t" << "|    " << a[5] << "\t" << "|    " << a[6] << "\t" << "|    " << a[7] << "\t" << (char)124 << endl;
	cout << (char)124 << "-------------------------------" << (char)124 << endl;
	cout << (char)124 << "   " << a[8] << "\t" << "|    " << a[9] << "\t" << "|    " << a[10] << "\t" << "|    " << a[11] << "\t" << (char)124 << endl;
	cout << (char)124 << "-------------------------------" << (char)124 << endl;
	cout << (char)124 << "   " << a[12] << "\t" << "|    " << a[13] << "\t" << "|    " << a[14] << "\t" << "|    " << a[15] << "\t" << (char)124 << endl;
	cout << (char)192 << "-------" << (char)193 << "-------" << (char)193 << "-------" << (char)193 << "-------" << (char)217 << endl;
	cout << "number of move =  "<< q+1;
}

bool IsOnTable(char ward,int cur_cell)
{
	if (ward == 'w')
	{
		if (cur_cell < 4)
			return false;
	}
	if (ward == 'x')
	{
		if (cur_cell > 11)
			return false;
	}
	if (ward == 'a')
	{
		if (cur_cell % 4 == 0)
			return false;
	}
	if (ward == 'd')
	{
		if (cur_cell % 4 == 3)
			return false;
	}
	
	return true;
}

void Move(int a[])
{
	int p, n, j;
	char i;
	i=_getch();
	for (j=0;j<16;j++)
	{
		if (a[j] == 0)
		{
			n = j;
			break;
		}

	}
	if (IsOnTable (i, n))
	{
		if (i == 'w')
		{
			p = a[n - 4];
			a[n - 4] = a[n];
			a[n] = p;
			q++;
		}

		if (i == 'x')
		{
			p = a[n + 4];
			a[n + 4] = a[n];
			a[n] = p;
			q++;
		}

		if (i == 'a')
		{
			p = a[n - 1];
			a[n - 1] = a[n];
			a[n] = p;
			q++;
		}

		if (i == 'd')
		{
			p = a[n + 1];
			a[n + 1] = a[n];
			a[n] = p;
			q++;
		}
		
	}
}


void SaveRecord(int q, string w)
{
	cout << "inter your name" << endl;
	cin >> w;
	ofstream record;
	record.open("D:\\record.txt", std::ios::app);
	record << q << " " << w << endl;
	record.close();
}


void ShowRecords()
{
	string w;
	int q;
	ifstream record;
	record.open("D:\\record.txt");
	while (record >> q >> w)
	{
		cout << q << " " << w << endl;
	}
}


int Check(int a[])
{
	int b1 = 0, h;
	for (h = 0; h<15; h++)
	{
		if (a[h] == h + 1)
		{
			b1++;
		}
	}
	if (b1 == 15)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

int main()
{
	srand((unsigned)time(0));
	
	b = Start('a');

	if (b == 1)
	{
		Random(a);
		ShowGame(a);
		while (Check(a) == 0)
		{
			Move(a);
			system("cls");
			ShowGame(a);
		}

		SaveRecord(q, w);
	}

	if (b == 2)
	{
		ShowRecords();
	}

	if (b == 3)
		return 0;

}
