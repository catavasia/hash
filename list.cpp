void AddToHeadList(List* list, Node* new_node)
{
	list->size++;
	//printf("new node is  %p\n", new_node);
	int check = CheckPtr(list->head);
	//printf("check %d\n", check);
	if( check == PTR_NULL)
	{
		list->head = new_node;
		//printf(" first node connected\n");
		return ;
	}
	else
	list->head->prev = new_node;
	//printf(" %p\n", list->head->prev);
	//printf(" list old head %p\n", list->head);
	new_node->next= list->head;
	//printf(" new node next %p\n", new_node.next);
	//printf(" new node next ok\n");
	list->head = new_node;
	//printf(" list new head %p\n", list->head);
}

void PrintList(List* list)
{
	Node* cur = list->head;
	while(cur!= NULL)
	{
		PrintNode(cur);
		cur = cur->next;
		//printf("ptr is %p\n", cur);
	}
}

Node* Search(List* list, Node* node)
{
	Node* cur = list->head;
	while(cur!= NULL)
	{
		if(strcmp(node->data, cur->data) == 0)
			return cur;
		cur = cur->next;
		//printf("ptr is %p\n", cur);
	}
	return cur;
}

void DeleteNodeFromHead(List* list, Node* cur)
{
	list->size--;
	list->head = cur->next;
	cur->next->prev = NULL;
	delete cur;
}

void ClearList(List* list)
{
	Node* cur = list->head;
	while(list->size!= 0)
	{
		DeleteNodeFromHead(list, cur);
		list->size--;
	}
}
