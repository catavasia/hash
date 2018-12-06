#include <string.h> 
#include "node.h"

struct List
{
	Node* head;
	int size;
	List()
	{
		head = NULL;
		size = 0;
	}
	~List()
	{
		printf(" list destructor\n");
		size = 0;
	}
};

void AddToHeadList(List* list, Node* new_node); // вставляет в начало списка
Node* Search(List* list, Node* node);
void PrintList(List* list);
void DeleteNodeFromHead(List* list, Node* cur);
void ClearList(List* list);

#include "list.cpp"
	
	


	

