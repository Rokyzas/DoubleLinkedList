// Rokas Čebatorius, Programų sistemos 1 kursas, 2 pogrupis
// rokas.cebatorius@mif.stud.vu.lt
// 2022-01-19
//
// Program can be used as a tool to create auto catalog containing cars data.
// (N9. Sudaryti dvipusį sąrašą. Parašyti procedūrą, kuri išmeta iš sąrašo mažiausią elementą.)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "listFunc.h"
#include "catFunc.h"

int main()
{
	printf("Program is a tool for creating car catalog with car data.\n");

	struct Node *carCatalog;
	int position = 0;
	int choice = 0;
	int flag = 0;

	printCarCatalogMenu(&choice);

	while (choice != 9)
	{
		if (choice == 0 && flag == 0) // Check if catalog has been created
		{
			createEmptyDLL(&carCatalog);
			printf("Catalog has been created\n\n");
			flag = 1;
		}
		
		if (flag == 1) // Check if catalog has been created in order to interact with it
		{
			switch (choice)
			{
			case 1:
				push(&carCatalog, CreateNewCarData()); // Create new list element with created car data address
				printf("Car has been added to the catalog\n\n");
				break;
			case 2:
				getCarCatalogPosition(&position);
				while ((position <= 0) || (position > (sizeOfDLL(&carCatalog) + 1))) // Validate position
				{
					printf("Invalid position\n");
					getCarCatalogPosition(&position);
				}
				insertPosValue(&carCatalog, CreateNewCarData(), position);
				printf("Car has been added to %d position in the catalog\n\n", position);
				break;
			case 3:
				getCarCatalogPosition(&position);
				if (sizeOfDLL(&carCatalog) > 0) // Check if list is not empty
				{
					while ((position <= 0) || (position > (sizeOfDLL(&carCatalog)))) // validate position
					{
						printf("Invalid position\n");
						getCarCatalogPosition(&position);
					}
					removePosValue(&carCatalog, position);
					printf("Car has been removed from catalogs %d position\n\n", position);
				}
				else
				{
					printf("Catalog is empty\n\n");
				}
				break;
			case 4:
				removeLowestEngineCapacity(&carCatalog);
				printf("Lowest engine capacity car has been removed from the list\n\n");
				break;
			case 5:
				printf("Number of elements in catalog: %d\n\n", sizeOfDLL(&carCatalog));
				break;
			case 6:
				printCatalogList(&carCatalog);
				break;
			case 7:
				getCarCatalogPosition(&position);
				if (sizeOfDLL(&carCatalog) > 0) // Check if list is not empty
				{
					while ((position <= 0) || (position > (sizeOfDLL(&carCatalog)))) // Validate position
					{
						printf("Invalid position\n");
						getCarCatalogPosition(&position);
					}
					printCatalogItem(&carCatalog, position);
				}
				else
				{
					printf("Catalog is empty\n\n");
				}
				break;
			case 8:
				deleteDLL(&carCatalog);
				printf("Car catalog has been deleted\n\n");
				flag = 0; // Catalog no longer exists
				break;
			}
		}
		else
		{
			printf("Catalog doesnt exist. Create catalog in order to interact with it.\n\n");
		}
		printCarCatalogMenu(&choice);
	}

	return 0;
}