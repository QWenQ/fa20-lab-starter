#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
	if (head == NULL) return 0;
	node* tortoise = head;
	node* hare = head->next;
	while (tortoise != NULL && hare != NULL && tortoise != hare) {
		tortoise = tortoise->next;
		hare = hare->next;
		if (hare != NULL) {
			hare = hare->next;
		}
	}
	if (tortoise != NULL && hare != NULL && tortoise == hare) return 1;
	return 0;
}
