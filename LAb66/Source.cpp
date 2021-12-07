#include <iostream>
#include <ctime>
#include <windows.h>
#include <algorithm>
using namespace std;

int getValue()
{
	while (true)
	{
		cout << "Please input VALLUE";
		cout << '\n';
		int a;
		cin >> a;
		cout << '\n';
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else return a;
	}
}

double getValueD()
{
	while (true)
	{
		cout << "Please input VALLUE";
		cout << '\n';
		double a;
		cin >> a;
		cout << '\n';

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else return a;

	}

}

struct tovar
{
	int section;
	string name;
	double price;
	int vallue;
};

void add(tovar store[], int needmas[])
{
	system("cls");
	int varible_add;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "How much do you want add" << endl;
	cin >> varible_add;
	if (needmas[0] == 0)
	{
		int need = 0;
		for (int i = 0; i < varible_add; i++)
		{
			need++;
			cout << "Add section" << endl;
			store[i].section = getValue();
			cout << "Add name" << endl;
			cin >> store[i].name;
			cout << "Add price" << endl;
			store[i].price = getValueD();
			cout << "Add vallue" << endl;
			store[i].vallue = getValue();
			needmas[1]++;
			system("cls");
		}
		needmas[0]++;

	}
	else
	{
		int need = 0;
		for (int i = needmas[1] + 1; i < varible_add + needmas[1]; i++)
		{
			need++;
			cout << "Add section" << endl;
			store[i].section = getValue();
			cout << "Add name" << endl;
			cin >> store[i].name;
			cout << "Add price" << endl;
			store[i].price = getValueD();
			cout << "Add vallue" << endl;
			store[i].vallue = getValue();
			if (need == 2)
			{
				for (int j = 0; j < need + needmas[1]; j++)
				{
					if ((store[i].price == store[j].price) && (store[i].name == store[j].name))
					{
						store[i].vallue++;
						store[i].section = 0;
						break;

					}
					else {
						needmas[1]++;
					}
				}
			}
			system("cls");
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void print(tovar store[], int needmas[])
{
	system("cls");
	cout << "Please input name product" << endl;
	string names;
	cin >> names;
	int var_nub = 0;
	for (int i = 0; i < needmas[1]; i++)
	{
		if (store[i].name == names)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << "______________General_Inforamtion______________" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			cout << " Names production:  \t" << store[i].name << endl;
			cout << "Section is:  \t" << store[i].section << endl;
			cout << "Price product:  \t" << store[i].price << endl;
			cout << "Vallue is:  \t" << store[i].vallue << endl;
			var_nub++;
			cout << '\n';
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		}
		if ((i == needmas[1] - 1) && (var_nub == 0))
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			cout << "No found" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}
	var_nub = 0;
	system("pause");
	system("cls");
}

void find_1(tovar store[], int needmas[])
{
	system("cls");
	int section_need;
	section_need = getValue();
	int find = 0;
	for (int i = 0; i < needmas[1]; i++)
	{
		if (store[i].section == section_need)
		{
			find++;
		}
	}
	string* names = new string[find];
	for (int i = 0; i < needmas[1]; i++)
	{
		int need = 0;
		if (store[i].section == section_need)
		{
			names[need] = store[i].name;
			need++;
		}
	}
	sort(names, names + find);
	cout << "This elements are found" << endl;
	for (int i = 0; i < find; i++)
	{
		cout << names[i] << endl;
	}
	system("pause");
	system("cls");
}

void find_2(tovar store[], int needmas[])
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "Please input vallue product" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	int vallue_products;
	vallue_products = getValue();
	int prover = 0;
	for (int i = 0; i < needmas[1]; i++)
	{

		if (vallue_products > store[i].vallue)
		{
			cout << store[i].name << endl;
			prover++;
		}
		if ((i == needmas[1] - 1) && (prover == 0))
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			cout << "Not enough any products" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}
	prover = 0;
	system("cls");
}

int main()
{
	tovar* store = new tovar[10000];
	int needmas[2];
	needmas[0] = 0;
	needmas[1] = 0;
	int solution = 0;
	while (solution != 5)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "______________________M.E.N.U______________________" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Add new object...................................1" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Print base objects...............................2" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Find objects for section.........................3" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Find objects with vallue smaller then keep.......4 " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "Exit with program................................5" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "===================================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Wait your answer" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		solution = getValue();
		switch (solution)
		{
		case 1:
		{
			add(store, needmas);
			int ezzy = 0;
			tovar* store_time = new tovar[needmas[1]];
			
			int fiil = 0;
			while (fiil != ezzy)
			{
				int i = 0;
				if (store_time[i].name == "0")
				{
					i++;
					continue;
				}
				else
				{
					store[fiil].section = store_time[i].section;
					store[fiil].name = store_time[i].name;
					store[fiil].price = store_time[i].price;
					store[fiil].vallue = store_time[i].vallue;
					fiil++;
					i++;
				}
			}
			needmas[1] = needmas[1] - ezzy;
			break;
		}
		case 2:
		{
			print(store, needmas);
			break;
		}
		case 3:
		{
			find_1(store, needmas);
			break;
		}
		case 4:
		{
			find_2(store, needmas);
			break;
		}
		case 5:
		{
			solution = 5;
			break;
		}
		case 6:
		{
			for (int i = 0; i < needmas[1]; i++)
			{
				cout << "______________General_Inforamtion______________" << endl;
				cout << " Names production :>>>" << '\t' << store[i].name << endl;
				cout << "Section is :>>>" << '\t' << store[i].section << endl;
				cout << "Price product :>>>" << '\t' << store[i].price << endl;
				cout << "Vallue is :>>>" << '\t' << store[i].vallue << endl;
				cout << '\n';
			}
			break;
		}
		}
	}
}
