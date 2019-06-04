/*
2.	Определить количество слов в тексте и вывести каждое слово на новой строке
12.	Дан текст. Какие прописные русские буквы содержатся в нем?
20.	В данной строке вставить после каждого символа 'a' символ 'b'.
*/
#include "2.h"
int Len(char *s) {

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

	for (int i = 1; i <= len; i++)
	{
		printf_s("%c", s[i]);
		if (quantity == 0 && s[i] == ' ' && s[i + 1] != ' ')
		{
			quantity++;
		}
		else
		if ( s[i] == ' ' && s[i - 1] != ' ')
		{
			quantity++;
			printf_s("\n");
		}
		else if (s[i] == ' ' &&  s[i + 1] != ' ')
		{
			quantity++;
			printf_s("\n");
		}
		if (quantity == 0 && s[i] == ' ' && s[i + 1] != ' ')
		{
			quantity++;
		}
		
	}

	printf_s("Количество слов в тексте: %d\n", quantity);

	for (int i = 0; i < len; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			printf_s("%c ", s[i]);
		}
	}
	printf_s("\n");

	for (int i = 0; i < len; i++)
	{
		if ((s[i] == 'a'))
		{
			realloc(s, (++length) * sizeof(char));
			char *tmp = (char*)malloc((length) * sizeof(char));
			for (int j = i; j < len+1; j++)
			{
				tmp[j+1] = s[j];
			}
			for (int j = i+1; j < len+1; j++)
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
	_getch();
}

