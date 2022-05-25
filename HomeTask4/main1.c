// Rokas Čebatorius, Programų sistemos 1 kursas, 2 pogrupis
// rokas.cebatorius@mif.stud.vu.lt
// 2022-01-19
//
// Program presents functionality of custom created functions that work with double linked list.
// (N9. Sudaryti dvipusį sąrašą. Parašyti procedūrą, kuri išmeta iš sąrašo mažiausią elementą.)

#include <stdio.h>
#include "listFunc.h"

int main() 
{
	struct Node *head;

	int x = 1, y = 5, z = 3;
	
	printf("Values x=%d, y=%d, z=%d\n", x, y, z);
	printf("Creating empty Double Linked List, Adding x(%d) to the list and then another y(%d) random values.\nDLL: ", x, y);
	createEmptyDLL(&head);
	push(&head, &x);
	pushRandomIntDLL(&head, y);
	printListInt(head);

	printf("Number of elements in the list: %d\n", sizeOfDLL(&head));
	printf("Inserting value y(%d) in to z(%d) position.\nDLL: ", y, z);
	insertPosValue(&head, &y, z);
	printListInt(head);

	printf("Printing value of z+1(%d) position and then removing y(%d) position value.\n%d position value: ", z + 1, y, z + 1);
	printPosValueInt(&head, z + 1);
	removePosValue(&head, y);
	printf("DLL: ");
	printListInt(head);

	printf("Removing lowest value element from the list.\nDLL: ");
	removeLowestValueInt(&head);
	printListInt(head);

	printf("Removing lowest value element from the list.\nDLL: ");
	removeLowestValueInt(&head);
	printListInt(head);

	printf("Number of elements in the list: %d\n\n", sizeOfDLL(&head));

	printf("Deleting DLL and freeing up allocated memory of list elements.\nDLL: ");
	deleteDLL(&head);
	printListInt(head);

	getchar();

	return 0;
}