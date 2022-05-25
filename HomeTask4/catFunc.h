// Rokas Čebatorius, Programų sistemos 1 kursas, 2 pogrupis
// rokas.cebatorius@mif.stud.vu.lt
// 2022-01-19

#ifndef catFunc_h
#define catFunc_h

#define MAX_STRING 128

struct CarData
{
	char model[MAX_STRING];
	int year;
	float engineCapacity;
} typedef CarData;


CarData* CreateNewCarData();
void printCatalogList(struct Node** carCatalog);
void printCatalogItem(struct Node** carCatalog, int position);
void removeLowestEngineCapacity(struct Node** carCatalog);
void printCarCatalogMenu(int* choice);
void getCarCatalogPosition(int* position);

#endif