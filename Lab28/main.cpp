/*
2.	Определить количество слов в тексте и вывести каждое слово на новой строке
12.	Дан текст. Какие прописные английские буквы содержатся в нем?
20.	В данной строке вставить после каждого символа 'a' символ 'b'.
*/
#include <conio.h>
#include <iostream>

int Len(char *s)
{
	int l = 0;
	while (s[l] != '\0')
		l++;
	return l;
}


void main()
{
	setlocale(LC_ALL, "");
	int length = 256;
	char *s = (char*)malloc((length) * sizeof(char));
	gets_s(s, 256);
	int quantity = 0, len = Len(s);

#pragma region quantity

	for (int i = 0; i <= len; i++)
	{
		if (s[i] != ' ' && s[i] != '\0') printf_s("%c", s[i]);
		if (s[i] != ' ' && s[i] != '\0')
		{
			int tmp = i;
			do
			{
				tmp++;
				if (s[tmp] != ' ' && s[i] != '\0')	printf_s("%c", s[tmp]);
			} while (s[tmp] != ' ' && s[tmp] != '\0');
			if (s[tmp] == ' ')
			{
				quantity++;
				printf_s("\n");
				i = tmp;
			}
			if (s[tmp] == '\0')
			{
				quantity++;
				printf_s("\n");
				break;
			}
		}
	}

	printf_s("Количество слов в тексте: %d\n", quantity);

#pragma endregion

#pragma region 2
	{
		char * tmp = (char*)malloc((len + 1) * sizeof(char));
		int n = 0;
		for (int i = 0; i < len; i++)
		{
			bool check = true;

			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				tmp[n] = s[i];
				for (int j = 0; j < n; j++)
				{
					if (tmp[j] == s[i]) check = false;
				}
				n++;
				if (check) printf_s("%c ", s[i]);
			}
		}
		printf_s("\n");
	}

#pragma endregion

	realloc(s, (2 * len + 1) * sizeof(char));
	for (int i = 0; i < len; i++)
	{
		if ((s[i] == 'a'))
		{
			char tmp[256];
			for (int j = i; j < len + 1; j++)
			{
				tmp[j + 1] = s[j];
			}
			for (int j = i + 1; j < len + 1; j++)
			{
				if (j == i + 1)
				{
					len++;
					s[j] = 'b';
				}
				else
					s[j] = tmp[j];
			}
		}
	}
	puts(s);
	free(s);
	_getch();
}

