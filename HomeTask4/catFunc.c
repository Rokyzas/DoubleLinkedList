// Rokas Čebatorius, Programų sistemos 1 kursas, 2 pogrupis
// rokas.cebatorius@mif.stud.vu.lt
// 2022-01-19
//
// Functions to work with car catalog project.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "listFunc.h"
#include "catFunc.h"

CarData* CreateNewCarData() // Gather car data from user and return address of it's struct
{
	int isCorrect = 0;
	CarData* newCarData = (CarData*)malloc(sizeof(CarData));

	printf("Model: ");
	scanf("%s", newCarData->model);

	printf("Year: ");
	isCorrect = 0;
	while (!isCorrect)
	{
		if ((scanf("%d", &(newCarData->year)) == 1) && getchar() == '\n')
		{
			if (((newCarData->year) >= 0) && ((newCarData->year) <= 9999))
			{
				isCorrect = 1;
			}
			else
			{
				printf("Invalid input, year can be between 0 and 9999, try again:\n");
			}
		}
		else
		{
			printf("Invalid input, try again:\n");
			scanf("%*[^\n]");
		}
	}
	printf("Engine capacity(liters): ");

	isCorrect = 0;
	while (!isCorrect)
	{
		if ((scanf("%f", &(newCarData->engineCapacity)) == 1) && getchar() == '\n')
		{
			if (((newCarData->engineCapacity) >= 0) && ((newCarData->engineCapacity) <= 100))
			{
				isCorrect = 1;

			}
			else
			{
				printf("Invalid input, liters can be between 0 and 100, try again:\n");
			}
		}
		else
		{
			printf("Invalid input, try again:\n");
			scanf("%*[^\n]");
		}
	}

	return newCarData;
}

void printCatalogList(struct Node** carCatalog) // Print out all list with its data
{
	if (sizeOfDLL(carCatalog) < 1)
	{
		printf("Car catalog is empty.\n\n");
	}
	else
	{
		struct Node* tempCatalog = (*carCatalog);
		CarData* tempData = (CarData*)tempCatalog->data;

		int i = 1;
		printf("--------------------CarCatalog--------------------\n");
		while (tempCatalog != NULL)
		{
			tempData = (CarData*)tempCatalog->data;
			printf("%d.Make: %s ", i, tempData->model);
			printf("Year: %d ", tempData->year);
			printf("Engine capacity: %.1f\n", tempData->engineCapacity);
			tempCatalog = tempCatalog->next;
			++i;
		}
		printf("--------------------------------------------------\n\n");
	}
}

void printCatalogItem(struct Node** carCatalog, int position) // Print single data from any list position
{
	struct Node* tempCatalog = (*carCatalog);

	int i = 0;
	for (i = 1; i < position; ++i)
	{
		tempCatalog = tempCatalog->next;
	}

	CarData* tempData = (CarData*)tempCatalog->data;

	printf("--------------------CarCatalog--------------------\n");
	printf("%d.Make: %s ", i, tempData->model);
	printf("Year: %d ", tempData->year);
	printf("Engine capacity: %.1f\n", tempData->engineCapacity);
	printf("--------------------------------------------------\n\n");
}

void removeLowestEngineCapacity(struct Node** carCatalog) // Remove data from list by it's engine capacity value
{
	struct Node* tempCatalog = (*carCatalog);
	CarData* tempData = (CarData*)tempCatalog->data;

	struct Node* lowestCat = (*carCatalog);
	CarData* lowest = tempData;

	CarData* temp = tempData;

	while (tempCatalog->next != NULL)
	{
		tempCatalog = tempCatalog->next;
		tempData = (CarData*)tempCatalog->data;
		temp = tempData;

		if (temp->engineCapacity < lowest->engineCapacity)
		{
			lowest = temp;
			lowestCat = tempCatalog;
		}
	}

	if (lowestCat->prev != NULL)
	{
		lowestCat->prev->next = lowestCat->next;
	}
	else
	{
		(*carCatalog) = lowestCat->next;
	}

	if (lowestCat->next != NULL)
	{
		lowestCat->next->prev = lowestCat->prev;
	}

	free(lowestCat);
}

void printCarCatalogMenu(int* choice) // Print menu and get valid user's choice 
{
	printf("--------------------Menu--------------------\n\
0 - Create car data catalog\n\
1 - Add new car data to catalog\n\
2 - Add new car data to specific position to catalog\n\
3 - Remove a car data from specific catalog position\n\
4 - Remove lowest engine capacity car\n\
5 - Size of catalog\n\
6 - Print catalog list\n\
7 - Print specific position in catalog car data\n\
8 - Delete catalog\n\
9 - Exit\n");	

	int isCorrect = 0;
	while (!isCorrect)
	{
		if ((scanf("%d", choice) == 1) && getchar() == '\n')
		{
			if (((*choice) >= 0) && ((*choice) < 10))
			{
				isCorrect = 1;
			}
			else
			{
				printf("Invalid input, try again:\n");
			}
		}
		else
		{
			printf("Invalid input, try again:\n");
			scanf("%*[^\n]");
		}
	}
}

void getCarCatalogPosition(int* position) // Get valid position number from user
{
	printf("Enter position: ");
	int isCorrect = 0;
	while (!isCorrect)
	{
		if ((scanf("%d", position) == 1) && getchar() == '\n')
		{
				isCorrect = 1;
		}
		else
		{
			printf("Invalid input, try again:\n");
			scanf("%*[^\n]");
		}
	}
}

