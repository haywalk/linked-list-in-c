/*
 * Making a linked linkedlist using structures and pointers!
 * Hayden Walker, 2023-02-09
 * (Following the COMP 2931 lecture on pointers)
 */

#include <stdio.h>
#include <stdlib.h>

/* Create a structure for a node in a linked list */
struct linkedlist {
	int data;
	struct linkedlist *next;
};

/* List functions */
void add_to_front(struct linkedlist **list, int data);
void add_to_end(struct linkedlist **list, int data);
int remove_element(struct linkedlist **list);

/* Demo functions */
void stack_demo();
void queue_demo();

/*
 * Run some demo functions.
 */
int main()
{
	printf("----------------------------------\n");
	printf("Linked List Demo in C\n");
	printf("Hayden Walker, 2023-02-09\n");
	stack_demo();
	queue_demo();
	printf("----------------------------------\n");
	return 0;
}

/*
 * Demonstrate how a linked list can be a stack.
 */
void stack_demo()
{
	printf("----------------------------------\n");
	printf("A linked list can work as a stack!\n");

	/* create an empty list */
	struct linkedlist *list = NULL;
	
	/* add some numbers and print them */
	int i;
	for(i = 1; i < 6; i++) {
		add_to_front(&list, i);
		printf("Push: %d\n", i);
	}

	/* remove the numbers and print them */
	while(list != NULL)
		printf("Pop:  %d\n", remove_element(&list));

}

/*
 * Demonstrate how a linked list can be a queue.
 */
void queue_demo()
{
	printf("----------------------------------\n");
	printf("A linked list can also be a queue!\n");

	/* create an empty list */
	struct linkedlist *list = NULL;
	
	/* add some numbers and print them */
	int i;
	for(i = 1; i < 6; i++) {
		add_to_end(&list, i);
		printf("Enqueue: %d\n", i);
	}

	/* remove the numbers and print them */
	while(list != NULL)
		printf("Dequeue: %d\n", remove_element(&list));

}

/*
 * Add an element to the front of a list.
 */
void add_to_front(struct linkedlist **list, int data)
{
	/* allocate RAM for the new node */
	struct linkedlist *new = (struct linkedlist *) malloc(sizeof(struct linkedlist));
	
	/* set the new node's data */
	new->data = data;
	new->next = *list;
	
	/* point the list pointer to the new node */
	*list = new;
}

/*
 * Add an element to the end of the list
 */
void add_to_end(struct linkedlist **list, int data)
{
	/* create a new node */
	struct linkedlist *new = (struct linkedlist *) malloc(sizeof(struct linkedlist));
	new->data = data;
	new->next = NULL;

	/* if the list is empty, point it to the new node */
	if(*list == NULL) {
		*list = new;
		return;
	}

	/* otherwise traverse until the last node */
	struct linkedlist *current = *list;

	while(current->next != NULL)
		current = current->next;

	/* add the new node onto the end */
	current->next = new;
}

/*
 * Remove an element from the front of a list.
 */
int remove_element(struct linkedlist **list)
{
	/* get the pointer to the node we're removing */
	struct linkedlist *to_remove = *list;

	/* get its data and remove it */
	int data = to_remove->data;
	*list = to_remove->next;

	/* free the removed node's memory */
	free(to_remove);

	/* return the removed node's data */
	return data;
}
