#include "2.h"

struct Node
{
	char symbol;
	Node* next;
	Node* prev;
};

void Push(Node*head, Node*tail, char symbol)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->symbol = symbol;

	if (head == nullptr)
	{
		head = tail = tmp;
		head->next = head->prev = tail->next = tail->prev = nullptr;
	}
	else
	{
		tail->next = tmp;
		tmp->next = nullptr;
		tmp->prev = tail;
		tail = tmp;
	}

}

void Pull(Node*head, Node*tail)
{
	if (head == tail) head = tail = nullptr;
	else
	{
		head = head->next;
		free(head->prev);
		head->prev = nullptr;
	}
}