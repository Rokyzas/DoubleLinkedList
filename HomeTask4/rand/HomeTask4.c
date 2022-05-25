//Sudaryti dvipusį sąrašą. Parašyti procedūrą, kuri išmeta iš sąrašo mažiausią elementą
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
	void *data;
	struct Node *prev;
	struct Node *next;
};

void printNode(struct Node *head);
void push(struct Node **head, int newData);
void createRandomDLL(struct Node **head, int size);
void removeLowestValue(struct Node** head);

int main()
{
	struct Node *head = NULL;

	push(&head, 1);

	createEmptyDLL;

	createRandomDLL(&head, 7);

	push(&head, 1);

	printNode(head);

	for (int i = 0; i < 3; ++i)
	{
		removeLowestValue(&head);

		printNode(head);
	}
	

	return 0;
}

void printNode(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void push(struct Node **head, int newData)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->prev = NULL;
	newNode->next = NULL;
	if ((*head) != NULL)
	{
		newNode->next = (*head);
		(*head)->prev = newNode;
	}
	(*head) = newNode;
}

void createRandomDLL(struct Node **head, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		push(head, (rand() % 100));
	}
}

void removeLowestValue(struct Node **head)
{
	struct Node *lowest = (*head);
	struct Node *temp = (*head)->next;
	while (temp != NULL)
	{
		if (temp->data < lowest->data)
		{
			lowest = temp;
		}
		temp = temp->next;
	}

	if (lowest->prev != NULL)
	{
		lowest->prev->next = lowest->next;
	}
	else
	{
		(*head) = lowest->next;
	}
	
	if (lowest->next != NULL)
	{
		lowest->next->prev = lowest->prev;
	}

	free(lowest);
}
