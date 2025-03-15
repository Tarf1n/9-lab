#include <iostream>
#include <clocale>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	int n1, n2;
	setlocale(LC_ALL, "Ru");
	FILE *f1, *f2;
	f1 = fopen("F1.txt", "r");
	f2 = fopen("F2.txt", "w");
	const int maxl = 255;
	char buf[maxl];
	if (f1 == NULL)
	{
		cerr << "Ошибка. Не удалось открыть входной файл";
		return 1;
	}
	if (f2 == NULL)
	{
		fclose(f1);
		cerr << "Ошибка. Не удалось открыть выходной файл";
		return 1;
	}
	cout << "Введите номер строки, с которой начнется копирование" << endl;
	cin >> n1;
	cout << "Введите номер строки, до которой продолжить копирование" << endl;
	cin >> n2;
	int currentLine = 0;

	while (fgets(buf, maxl, f1) != NULL)
	{
		currentLine++;
		if ((buf[0] == 'А' || buf[0] == 'a') && (currentLine >= n1 && currentLine <= n2))
		{
			fputs(buf, f2);
			cout << buf;
		}
	}
	fclose(f2);
	f2 = fopen("F2.txt", "r");

	int maxSogl = 0;
	int maxSoglLine = -1;
	currentLine = 0;
	while (fgets(buf, maxl, f2) != NULL)
	{
		currentLine++;
		int soglCount = 0;
		for (int i = 0; i < buf[i] != '\0'; i++)
		{
			if (buf[i] != 'a' && buf[i] != 'A' && buf[i] != 'y' &&
				buf[i] != 'Y' && buf[i] != 'i' && buf[i] != 'I' &&
				buf[i] != 'e' && buf[i] != 'E' && buf[i] != 'u' &&
				buf[i] != 'U' && buf[i] != 'o' && buf[i] != 'O')
			{
				soglCount++;
			}
			if (soglCount > maxSogl)
			{
				maxSogl = soglCount;
				maxSoglLine = currentLine;
			}
		}
	}
	
	if (maxSoglLine != -1)
	{
		cout << "Номер строки, в которой больше всего согласных: " << maxSoglLine << endl;
	}
	else
	{
		cout << "В файле нет строк с согласными буквами." << endl;
	}

	fclose(f1);
	fclose(f2);
	return 0;
}