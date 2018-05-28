// CPPLab2-3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Reloader
{
private:
	char str[256];
	
	int neg;
	string var1; string var2;
public:
	int tmp = 0;
	Reloader() {
		for (int i = 0; i < 256; i++)  str[i] = '\0';
	}
	void operator +(char *s) 
	{
		strcat(str, s); //сложение строк
	}
	void operator() (string A, string B) 
	{
		var1 = A;
		var2 = B;
		swap(var1, var2);
	}
	void operator [] (int n) 
	{
		neg = n;
		neg = -neg;
	}
	void operator++ () {
		tmp = tmp + 5;
	}
	void operator++(int) {
		tmp = tmp + 5;
	}
	void getStr()
	{
		cout << str << endl << endl;//вывод символьного массива класса на экран
	}
	void getTmp()
	{
		cout << "\nIncremented number: " << tmp << endl << endl;
	}
	void getSwapped()
	{
		cout << "\nA=" << var1 << "\tB=" << var2 << "\n";
	}
	void getNegative()
	{
		cout << "\nNegative: " << neg << endl;
	}
};
//################# FUNCTIONS ##############
void reload_plus() {
	char *str1 = new char[strlen("У лукоморья дуб зелёный;\n") + 1]; //выделим память для строк
	char *str2 = new char[strlen("Всё ходит по цепи кругом;\n") + 1];
	char *str3 = new char[strlen("И днём и ночью кот учёный\n") + 1];
	char *str4 = new char[strlen("Златая цепь на дубе том:\n") + 1];

	strcpy(str1, "У лукоморья дуб зелёный;\n");//инициализируем
	strcpy(str2, "Всё ходит по цепи кругом;\n");
	strcpy(str3, "И днём и ночью кот учёный\n");
	strcpy(str4, "Златая цепь на дубе том:\n");

	cout << "1) " << str1;
	cout << "2) " << str2;
	cout << "3) " << str3;
	cout << "4) " << str4 << endl;

	Reloader rld;//создаем объект и добавяем в него строки с помощью перегруженного +
	rld + str1;
	rld + str4;
	rld + str3;
	rld + str2;

	cout << "========================================" << endl;
	cout << "Стих, после правильного сложения строк: " << endl;
	cout << "========================================" << endl << endl;
	rld.getStr();
}
void reload_equal() {
	system("cls");
	string A; string B;
	cout << "\nInput A = "; cin >> A;
	cout << "\nInput B = "; cin >> B;
	Reloader eqs;
	eqs(A, B);
	eqs.getSwapped();
}
void reload_incr() {
	Reloader tmp;
	cout << "\nInput number to be incremented: "; cin >> tmp.tmp;
	tmp++;
	++tmp;
	tmp++;
	++tmp;
	tmp.getTmp();
}
void reload_sqrskb()
{
	int n;
	cout << "\nInput converting number: "; cin >> n;
	Reloader neg;
	neg[n];
	neg.getNegative();
}
void test_func() {
	//cout << !-7;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "\n 1. Reload + to char+char\n 2. Reload [] to do num negative\n 3.Reload () to swap\n 4.Reload Incr from +1 to +5\nInput num: ";
	cin >> n;
	switch (n)
	{
	case 1: reload_plus(); break;
	case 2: reload_sqrskb(); break;
	case 3: reload_equal(); break;
	case 4: reload_incr(); break;
	case 5: test_func(); break;
	default: 
		system("cls");
		cout << "Wrong item. Choose other.";
		break;
	}
	

	
	system("pause");
    return 0;
}

