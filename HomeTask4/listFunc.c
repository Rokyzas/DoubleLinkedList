// Rokas Čebatorius, Programų sistemos 1 kursas, 2 pogrupis
// rokas.cebatorius@mif.stud.vu.lt
// 2022-01-19
//
// Functions to work with lists.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listFunc.h"

void printListInt(struct Node* head) // Prints out all list with int type (type needs to be changed manually)
{
	if (head == NULL)
	{
		printf("List is empty");
	}
	else
	{
		struct Node* temp = head;

		while (temp != NULL)
		{
			printf("%d ", *(int*)temp->data); // Possible to change type (e.g. for char use "printf("%c ", *(char*)temp->data)")
			temp = temp->next;
		}
	}
	printf("\n\n");
}

void insertPosValue(struct Node** head, void *value, int position) // Insert data (by pointer) in any list position (from 1 to size of list + 1)
{
	if (position == 1)
	{
		push((head), value);
	}
	else if (position < 1 || position >(sizeOfDLL(head) + 1))
	{
		printf("Error: invalid position\n");
	}
	else if (position == (sizeOfDLL(head) + 1))
	{
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		struct Node* temp = (*head);
		newNode->data = value;
		newNode->prev = NULL;
		newNode->next = NULL;

		for (int i = 1; i < (position - 1); ++i)
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
		temp->prev = newNode;
	}

}

void removePosValue(struct Node** head, int position) // Remove value from any list position (from 1 to size of list) 
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

void printPosValueInt(struct Node** head, int position) // Print single int type data from any list position (type needs to be changed manually)
{
	struct Node* temp = (*head);
	for (int i = 1; i < position; ++i)
	{
		temp = temp->next;
	}

	printf("%d\n", *(int*)temp->data); // Possible to change type (e.g. for char use "printf("%c ", *(char*)temp->data)")
}

void push(struct Node** head, void* newData) // Insert new data at the beggining, by receiving pointer to data
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

int sizeOfDLL(struct Node** head) // Return number of elements in the list
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

void pushRandomIntDLL(struct Node** head, int size) // Push random int values to the list from 0 to 99 (can be used for other types)
{
	srand(time(NULL));
	int* x = malloc(sizeof(int)*size); // Memory allocated, but not freed up 
	for (int i = 0; i < size; ++i)
	{
		x[i] = (rand() % 100);
		push(head, &(x[i]));
	}
}

void createEmptyDLL(struct Node** head) // Create empty list with NULL address
{
	(*head) = NULL;
}

void removeLowestValueInt(struct Node** head) // Remove lowest int value in the list
{
	struct Node* lowest = (*head);
	struct Node* temp = (*head)->next;
	while (temp != NULL)
	{
		if (*(int*)temp->data < *(int*)lowest->data)
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

void deleteDLL(struct Node** head) // Delete list and free up memory
{
	struct Node *temp = (*head);
	while((*head) != NULL)
	{
		temp = (*head)->next;
		free(*head);
		(*head) = temp;
	}
}