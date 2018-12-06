
int CheckPtr(Node* cur)
{
	if(cur == NULL)
		return PTR_NULL;
	else
		return PTR_OK;
}

void PrintNode(Node* cur)
{
	printf("%s\n", cur->data);
}

char* My_Strdup(char* s)
{
	int len = strlen(s);
	//printf("%d\n", len);
	char* data = new char[len+1];
	strcpy(data,s);
	return data;
}
