#include <stdio.h>

typedef struct node_s{
	int value;
	struct node_s *next;
}node_t;

node_t *creat_list(){
	node_t *head;
	head = (node_t *)malloc(sizeof(node_t));
	head->next = (node_t *)0;
	return head;
}

void enqueue(node_t **head, int value){
	node_t *new_node, *iterator;
	new_node = (node_t *)malloc(sizeof(node_t));
	new_node->next = (node_t *)0;
	new_node->value = value;
	if((node_t *)0 == *head){
        *head = new_node;
    }else{
        iterator = *head;
        while((node_t *)0 != iterator->next){
            iterator = iterator->next;
        }
        iterator->next = new_node;
    }
}

int dequeue(node_t **head){
	node_t *del;
	int value;
	del = *head;
	value = del->value;
	*head = (*head)->next;
	free(del);
	return value;
}

void print_list(node_t *head){
	while((node_t *)0 != head){
		printf("%d ", head->value);
		head = head->next;
	}
}


int main(void){
	
	node_t *head;
	int temp;
	
	head = (node_t *)0;
	
	enqueue(&head, 5);
	enqueue(&head, 10);
	enqueue(&head, 15);
	enqueue(&head, 20);
	temp = dequeue(&head);
	printf("delete from list head, return value:%d\n", temp);
	
	print_list(head);
	
	return 0;
} 
