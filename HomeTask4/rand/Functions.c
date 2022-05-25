#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
	void* data;
	struct Node* prev;
	struct Node* next;
};

void printNode(struct Node* head);
void printSingleDLLValue(struct Node* head, int position);
void push(struct Node** head, int newData);
void createRandomDLL(struct Node** head, int size);
void createEmptyDLL(struct Node** head, int size);
void removeLowestValue(struct Node** head);
void deleteDLL(struct Node** head);
int sizeOfDLL(struct Node** head);
void insertValue(struct Node** head, int value, int position);
void removeValue(struct Node** head, int position);



int main()
{
	struct Node* head = NULL;

	printNode(head);

	createEmptyDLL(&head, 6);

	push(&head, 1);
	push(&head, 2);

	printNode(head);

	insertValue(&head, 5, 9);

	removeValue(&head, 9);

	printNode(head);



	return 0;
}

void printNode(struct Node* head)
{
	if (head == NULL)
	{
		printf("List doesn't exist");
	}
	else
	{
		struct Node* temp = head;

		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
}

void insertValue(struct Node** head, int value, int position)
{
	if (position == 1)
	{
		push((head), value);
	}
	else if(position < 1 || position > (sizeOfDLL(head)+1))
	{
		printf("Error: invalid position\n");
	}
	else if(position == (sizeOfDLL(head) + 1))
	{
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		struct Node* temp = (*head);
		newNode->data = value;
		newNode->prev = NULL;
		newNode->next = NULL;

		for (int i = 1; i < (position-1); ++i)
		{
			temp = temp->next;
		}

		newNode->prev = temp;
		temp->next = newNode;
	}
	else
	{
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		struct Node* temp = (*head);
		newNode->data = value;
		newNode->prev = NULL;
		newNode->next = NULL;

		for (int i = 1; i < position; ++i)
		{
			temp = temp->next;
		}

		newNode->next = temp;
		newNode->prev = temp->prev;
		temp->prev->next = newNode;
	}
	
}

void removeValue(struct Node** head, int position)
{
	if (position < 1 || position >(sizeOfDLL(head)))
	{
		printf("Error: invalid position\n");
	}
	else
	{
		struct Node* temp = (*head);

		for (int i = 1; i < position; ++i)
		{
			temp = temp->next;
		}

		if (temp->prev != NULL)
		{
			temp->prev->next = temp->next;
		}
		else
		{
			(*head) = temp->next;
		}

		if (temp->next != NULL)
		{
			temp->next->prev = temp->prev;
		}

		free(temp);
	}

}

void printSingleDLLValueByPosition(struct Node* head, int position)
{
	struct Node* temp = head;
	for (int i = 1; i < position; ++i)
	{
		temp = temp->next;
	}

	printf("%d\n", temp->data);
}

void push(struct Node** head, int newData)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

int sizeOfDLL(struct Node** head)
{
	int size = 0;
	if ((*head) != NULL)
	{
		struct Node* temp = (*head);
		while (temp != NULL)
		{
			++size;
			temp = temp->next;
		}
	}
	
	return size;
}

void createRandomDLL(struct Node** head, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		push(head, (rand() % 100));
	}
}

void createEmptyDLL(struct Node** head, int size)
{

	for (int i = 0; i < size; ++i)
	{
		push(head, 0);
	}
}

void removeLowestValue(struct Node** head)
{
	struct Node* lowest = (*head);
	struct Node* temp = (*head)->next;
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

void deleteDLL(struct Node** head)
{
	struct Node* temp = (*head)->next;
	printf("%d\n", *head);
	free(*head);
	printf("%d\n", (head));
}