//������������ ��������

#include <iostream>
#include "Polinom.h"
#include "Monom.h"
#include "locale.h"
//---------------------------------------------------------------------------

void main()
{
	setlocale(0, "");
	cout << "����� ������� " << endl;
	string st;
	cin >> st;
	Polinom a(st);
	cout << "� = ";
	cout << a.Getpolinom() << endl;
	Polinom b = a;
	cout << "b = a = "<< b.Getpolinom() << endl;
	Polinom c(a);
	cout << " c=a " << endl;
	cout << "c = ";

	cout << c.Getpolinom() << endl;
	cout << " c= a + b " << endl;
	c = a + b;
	cout << "c = ";
	cout << c.Getpolinom() << endl;
	cout << " c= a - b " << endl;
	c = a - b;
	cout << "c = ";
	cout << c.Getpolinom() << endl;
	cout << " c= a * b " << endl;
	c = a * b;
	cout << "c = ";
	cout << c.Getpolinom() << endl;
	int x;
	cout << "������� x "<< endl;
	cin >> x;
	int y;
	cout << "������� y " << endl;
	cin >> y;
	int z;
	cout << "������� z " << endl;
	cin >> z;
	cout << c.GetResult(x,y,z) << endl;
}
//---------------------------------------------------------------------------
