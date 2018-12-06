#include <stdio.h>
#include <stdlib.h>

const int PTR_OK = 1;
const int PTR_NULL = -1;

char* My_Strdup(char* s);

struct Node
{
	char* data;
	Node* next;
	Node* prev;
	Node(char* s)
	{
		next = NULL;
		prev = NULL;
		//int a = strlen(s);
		//data = new char[a];
		data = My_Strdup(s); 
		//printf( " data strdup ok\n");
	}
	~Node()
	{
		next = NULL;
		prev = NULL;
		delete[] data; 
		printf(" сработал деструктор\n");
	}
};

int CheckPtr(Node* cur);
void PrintNode(Node* cur);

#include "node.cpp"
