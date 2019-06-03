#include "two-dimensional array.h"



char ** CreateMas(int quantity, int length)
{
	if (!(quantity > 0 && length > 0)) exit(1);
	char **mas = (char**)malloc(quantity * sizeof(char*));
	for (int i = 0; i < quantity; i++)
		mas[i] = (char*)malloc(length * sizeof(char));
	return mas;
}

void WriteIn(int quantity, int length, int **mas)
{
	for (int i = 0; i < quantity; i++)
		for (int j = 0; j < length; j++)
			scanf_s("%d", &mas[i][j]);
}

int * Counter(int quantity, int length, int **mas)
{
	int n = 0;
	int *ctr = (int*)malloc(quantity * sizeof(int));
	for (int i = 0; i < quantity; i++)
	{
		for (int j = 0; j < length; j++)
			if (mas[i][j] < 0) n++;
		ctr[i] = n;
		n = 0;
	}
	return ctr;
}

void PrintOnScreen(int quantity, int length, int ** mas)
{
	system("cls");
	for (int i = 0; i < quantity; i++)
	{
		for (int j = 0; j < length; j++)
		{
			printf_s("%5d ", mas[i][j]);
		}
		printf_s("\n");
	}
}
void FreeMas(int quantity, int ** mas)
{
	for (int i = 0; i < quantity; i++)
		free(mas[i]);
	free(mas);
}