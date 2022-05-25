// Rokas Čebatorius, Programų sistemos 1 kursas, 2 pogrupis
// rokas.cebatorius@mif.stud.vu.lt
// 2022-01-19

#ifndef listFunc_h
#define listFunc_h

struct Node {
	void* data;
	struct Node* prev;
	struct Node* next;
};

void printListInt(struct Node* head);
void printPosValueInt(struct Node** head, int position);
void push(struct Node** head, void* newData);
void pushRandomIntDLL(struct Node** head, int size);
void createEmptyDLL(struct Node** head);
void removeLowestValueInt(struct Node** head);
void deleteDLL(struct Node** head);
int sizeOfDLL(struct Node** head);
void insertPosValue(struct Node** head, void* value, int position);
void removePosValue(struct Node** head, int position);

#endif