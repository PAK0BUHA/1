#include <iostream>
#include <ctime>
#include <string.h>
using namespace std;

char* myfunc(const char* str, int key)
{
	int i = 0;
	while (str[i] && str[i] != key) ++i;
	return key == str[i] ? (char*)str + i : NULL;
}

int main()
{
	setlocale(LC_ALL, "rus");
	char key;
	char* a = new char[64];
	cout << "Введите текст: " << endl;
	gets_s(a, 64);
	cout << endl << "Использование strchr(): " << endl;
	cout << "Что вы хотите найти в тексте?" << endl;
	cin >> key;
	if (strchr(a, key) == NULL)
	{
		cout << "Такого символа в тексте нет." << endl;
	}
	else
	{
		char* keystr = strchr(a, key);
		cout << '"' << key << '"' << " находится на " << (keystr - a + 1) << " позиции." << endl;
	}
	cout << endl << "Использование myfunc(): " << endl;
	cout << "Что вы хотите найти в тексте?" << endl;
	cin >> key;
	if (myfunc(a, key) == NULL)
	{
		cout << "Такого символа в тексте нет." << endl;
	}
	else
	{
		char* keystr = myfunc(a, key);
		cout << '"' << key << '"' << " находится " << (keystr - a + 1) << " позиции." << endl;
	}
	delete[] a;
}
