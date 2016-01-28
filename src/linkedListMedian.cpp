/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	if (head->next == NULL)
		return head->num;
	struct node *pos1 , *pos2;
	pos1 = pos2 = head;
	while (true)
	{
		if (pos2->next == NULL)
			return pos1->num;
		else if (pos2->next->next == NULL)
			return ((pos1->num + pos1->next->num) / 2);

		pos1 = pos1->next;
		pos2 = pos2->next->next;
	}
}
