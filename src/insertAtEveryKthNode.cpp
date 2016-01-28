/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (K < 1 || head == NULL)
		return NULL;
	int count = 1;
	struct node * temp;
	struct node * pointer = head;
	while (head)
	{
		if (count == K && head != NULL)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->num = K;
			temp->next = head->next;
			head->next = temp;
			head = temp->next;
			count = 1;
		}
		else
		{
			count = (count + 1) % (K + 1);
			head = head->next;
		}
	}
	return pointer;
}
