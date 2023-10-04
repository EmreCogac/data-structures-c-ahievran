 // listenin sonundaki elemanı silme / delete from last

struct node * SondakiElemaniSil(struct node *head)
{

	struct node * temp = head;
	

    while(temp->next->next != NULL)
        temp=temp->next;
	
	free(temp->next);
	
	temp->next = NULL;

	return head;
	
};