#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char *coll;
	struct node * next;
}node;

typedef node *List;

void init(List *l){
	*l = NULL;
}

void insert(List *l, char *str){
	node *newnode, *ptr, *temp;
	newnode = (node *)malloc(sizeof(node));
	newnode->coll = str;
	ptr = *l;
	if(!ptr){
		newnode->next = ptr;
		*l = newnode;
		return;
	}
	temp = ptr;
	while(ptr && (strcmp(ptr->coll, newnode->coll) < 0)){
		temp = ptr;
		ptr = ptr->next;
	}
	if(ptr == (*l)){
		ptr = ptr->next;
	}
	if(strcmp((*l)->coll, newnode->coll) > 0){
		newnode->next = *l;
		*l = newnode;
		return;
	}
	newnode->next = ptr;
	temp->next = newnode;
	return;
}
