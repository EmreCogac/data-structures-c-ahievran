// aradan herhangi bir elemanı silme (delete from anywhere) 
// ben datası 6 olan elemanı sileceğim

struct node * aradakiElemaniSil(struct node *head)	
{
	
	struct node * temp = head;
	struct node * temp2;
	
	while(temp->next->data !=6)
		temp= temp->next;
		temp2 = temp->next->next;
		
		free(temp->next);
		
		temp->next= temp2;
		
	return(head);
};
