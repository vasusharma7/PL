//reverses list using pointer

/*

list prototype

 
************************
 typedef struct node{
	char *coll;
	struct node * next;
}node;

typedef node *List;
****************************
        
*/

void reverse(List *l){
	node *ptr, *temp;
	List r;
	init(&r);
	ptr = *l;
	while(ptr){
		temp = ptr;
		ptr = ptr->next;
		temp->next = r;
		r = temp;
	}
	*l = r;
}	
