#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <sys/stat.h>
#include <string.h> 
const int DATA = 5000; // сколько номеров
const int SIZE = 200; // размер массива листов
const int NUMOFDIG = 11; // цифр в номере
const int INSERT = 3;
const int ALREADYHAS = -3;
const int ERRORFILEOPEN = -31;
const int OK = 31;
const int KEYTOOBIG = -33;
const int KEYOK = 33;

char** GenerateNumbers(int s);
int FuncFind1(char* s);
int FuncFind2(char* s);
int FindorInsert(char* s, List* list, int key);
int CheckFile(FILE* f);
int AppropriateKey(int key);

struct Table
{
	List hashed[SIZE];
};

int main()
{
	Table one;
	Table two;
	char** numbase = GenerateNumbers(DATA);
	FILE *f1 = fopen("numbers.txt", "w");
	int result = CheckFile(f1);
	if(result!= OK)
	{
		fclose(f1);
		return result;
	}
	for(int k = 0; k < DATA; k++)
	{	
		fprintf(f1, "%s\n", *(numbase+k));
		printf("%s\n", *(numbase+k));
		int key1 = FuncFind1(*(numbase+k));
		printf("key1 is %d\n", key1);
		int keycheck1 = AppropriateKey(key1);
		if(keycheck1 == KEYTOOBIG)
			printf(" key1 is too big\n");
		//printf(" cur ptr %p\n", cur.next);
		else
		{
			int check1 = FindorInsert(*(numbase+k), &(one.hashed[key1]), key1);
			printf("check1 %d\n", check1);
			//PrintList(&one.hashed[key]);
			//printf(" findorinsert head %d\n", check);
		}
	}
	fclose(f1);
	for(int n = 0; n < DATA; n++)
	{	
		int key2 = FuncFind2(*(numbase+n))%SIZE;// выход за границы массива
		printf("key2 is %d\n", key2);
		int keycheck2 = AppropriateKey(key2);
		if(keycheck2 == KEYTOOBIG)
			printf(" key2 is too big\n");
			//printf(" cur ptr %p\n", cur.next);
		else
		{
			int check2 = FindorInsert(*(numbase+n), &(two.hashed[key2]), key2);
			printf("check2 %d\n", check2);
		}
			//PrintList(&one.hashed[key]);
			//printf(" findorinsert head %d\n", check);
	}
	//printf(" size %d\n", (one.hashed+14)->size); 
	FILE* f2 = fopen("results.csv","w");
	int result2 = CheckFile(f2);
	if( result2!= OK)
	{
		fclose(f2);
		return result2;
	}
	for(int m = 0; m < SIZE; m++)
	{
		fprintf(f2, " %d, %d, %d, %d \n", m, (one.hashed+m)->size, m, (two.hashed+m)->size);// keys frequency
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


int FindorInsert(char* s, List* list, int key)
{
	Node* node = new Node(s);
	PrintNode(node);
	Node* cur = Search(list, node);
	printf(" cur is %p\n", cur);
	if(cur == NULL)
	{
		AddToHeadList(list, node);
		return INSERT;
	}
	return ALREADYHAS;
}

int FuncFind1(char* s)
{
	int key = 0;
	for(int i = 0; i < NUMOFDIG; i++)
	{
		if(s[i]== '7')
			key++;
	}
	return key;
}

int FuncFind2(char* s)
{
	int a = strlen(s);
	int key = 0;
	for( int i =0; i< a; i++)
	{
		key = key + s[i];
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

int AppropriateKey(int key)
{
	if( key >= SIZE)
		return KEYTOOBIG;
	return KEYOK;
}
	
