#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <sys/stat.h>
#include <string.h> 
const int DATA = 50; // сколько номеров
const int SIZE = 12; // размер массива листов
const int NUMOFDIG = 11; // цифр в номере
const int INSERT = 3;
const int ALREADYHAS = -3;
const int ERRORFILEOPEN = -31;
const int OK = 31;

char** GenerateNumbers(int s);
int FuncFind(char* s);
int FindorInsert(Node* node, List* list);
int CheckFile(FILE* f);

struct Table
{
	List hashed[SIZE];
};

int main()
{
	Table one;
	char** numbase = GenerateNumbers(DATA);
	FILE *f1 = fopen("numbers.txt", "w");
	int result = CheckFile(f1);
	if( result!= OK)
	{
		fclose(f1);
		return result;
	}
	for(int k = 0; k < DATA; k++)
	{	
		Node* cur = new Node(*(numbase+k));
		printf(" cur ptr %p\n", cur);
		PrintNode(cur);
		fprintf(f1, "%s\n", *(numbase+k));
		printf("%s\n", *(numbase+k));
		int key = FuncFind(*(numbase+k));
		printf("key is %d\n", key);
		PrintNode(cur);
		//printf(" cur ptr %p\n", cur.next);
		int check = FindorInsert(cur, &(one.hashed[key]));
		//PrintList(&one.hashed[key]);
		//printf(" findorinsert head %d\n", check);
		printf(" check %d\n", check);
	}
	fclose(f1);
	printf(" size %d\n", (one.hashed+14)->size); // проблемы с размером
	FILE* f2 = fopen("results.csv","w");
	int result2 = CheckFile(f2);
	if( result2!= OK)
	{
		fclose(f2);
		return result2;
	}
	for( int m = 0; m < SIZE; m++)
	{
		fprintf(f2, " %d, %d \n", m, (one.hashed+m)->size);// keys frequency
	}
	fclose(f2);
	//PrintList(&one.hashed[1]);
	//PrintList(&one.hashed[0]);
	//PrintList(&one.hashed[2]);
	//PrintList(&one.hashed[4]);
	//printf("ptr head  %p\n", (one.hashed+4)->head);
	/*for( int m = 0; m < SIZE; m++)
	{
		
		if((one.hashed+m)->head != NULL)
			ClearList(one.hashed+m);
	}*/

}


int FindorInsert(Node* node, List* list)
{
	Node* cur = Search(list, node);
	printf(" cur is %p\n", cur);
	if(cur == NULL)
	{
		AddToHeadList(list, node);
		return INSERT;
	}
	return ALREADYHAS;
}

int FuncFind(char* s)
{
	int key = 0;
	for(int i = 0; i < NUMOFDIG; i++)
	{
		if(s[i]== '7')
			key++;
	}
	return key;
}

char** GenerateNumbers(int s)
{
	char** num = new char*[s];
	for(int j = 0; j < s; j++)
	{
		*(num+j) = new char[NUMOFDIG];
		**(num+j) = '8';
		*(*(num+j)+1) = '9';
		for( int i = 2; i < NUMOFDIG; i++)
		{
			*(*(num+j)+i) = random()%9 + 48;
			//printf("%c\n", *(*(num+j)+i));
		}
	}
	return num;
}

int CheckFile(FILE* f)
{
	if(f == NULL) 
	{
		printf("Cannot open file \n");
		return ERRORFILEOPEN;
	}
	else
		return OK;
}
