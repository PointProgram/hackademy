#include <stdio.h>
#include <stdlib.h>
#include <../include/linked_list.h>

node_t *list_create(void *data)
{
	node_t *main_head = (node_t *) malloc(sizeof(node_t));
	main_head->data = data;
	main_head->next = NULL;
	
	return main_head;
}

void list_destroy (node_t **head, void (*fp)(void *data)) 
{
	node_t *actual_ptr;
	
	while ((*head) != NULL ) 
	{
		actual_ptr = *head;
		fp((*head)->data);
		*head = (*head)->next;
		free(actual_ptr);
	}
	*head = NULL;
}

void list_push (node_t *head, void *data) 
{
	node_t *actual_ptr = head, *pushed_elem = (node_t *)malloc(sizeof(node_t));
	pushed_elem->data = data;
	pushed_elem->next = NULL;

	while(actual_ptr->next != NULL)
	{
		actual_ptr = actual_ptr->next;
	}
	
	actual_ptr->next = pushed_elem;
}

void list_unshift (node_t **head, void *data)
{
	node_t *pushed_elem = (node_t *)malloc (sizeof(node_t));

	pushed_elem->data = data;
	pushed_elem->next = *head;
	*head = pushed_elem;
}

void *list_shift(node_t **head)
{
	void *val;
	node_t *next_ptr;

	next_ptr = (*head)->next;
	val = (*head)->data;
	free(*head);
	*head = next_ptr;
	return val;
}

void *list_pop(node_t **head) 
{
	void *val;
	node_t *actual_ptr = *head;
		
	if (actual_ptr == NULL)
	{
		return NULL;
	}
	else if (actual_ptr->next == NULL)
	{
		val = actual_ptr->data;
		free(actual_ptr);
		return val;
	}

	while (actual_ptr->next->next != NULL)
	{
		actual_ptr = actual_ptr->next;
	}

	val = actual_ptr->next->data;
	free(actual_ptr->next);
	actual_ptr->next = NULL;
	return val;
}

void *list_remove(node_t **head, int pos)
{
	node_t *actual_ptr = *head, *tmp = NULL;
	void *val;
	int iterator;

	if (pos == 0)
	{
		return list_pop(&actual_ptr);
	}

	while (iterator++ < pos - 1)
	{
		if(actual_ptr->next == NULL)
		{
			return NULL;
		}
		actual_ptr = actual_ptr->next;
	}
	tmp = actual_ptr->next;
	actual_ptr->next = tmp->next;
	val = tmp->data;
	free(tmp);

	return val;
}

void list_print(node_t *head)
{
	node_t *actual_ptr = head;
	while(actual_ptr != NULL)
	{
		printf("%s\n", (char *) actual_ptr->data);
		actual_ptr = actual_ptr->next;
	}
}

void list_visitor(node_t *head, void (*fp)(void *data)) 
{
	node_t *actual_ptr = head;
	
	while (actual_ptr != NULL)
	{
		fp(actual_ptr->data);
		actual_ptr = actual_ptr->next;
	}

}
