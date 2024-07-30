/*******************************************************************************************************************************************************************
*Title                  : Multiplication
*Description            : This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype              : int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters       : head1: Pointer to the first node of the first double linked list.
                        : tail1: Pointer to the last node of the first double linked list.
                        : head2: Pointer to the first node of the second double linked list.
                        : tail2: Pointer to the last node of the second double linked list.
                        : head3: Pointer to the first node of the resultant double linked list.
*Output                 : Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "header_file.h"
extern int negative_flag;
Status do_mul(calculator* head1,calculator* tail1,calculator* head2,calculator* tail2,calculator** head3,calculator** tail3)
{
	int result = 0,count= 0,mult = 0,carry = 0;
	calculator* temp1 = tail1;
	calculator* temp2 = tail2;
	calculator* result_head1 = NULL;
	calculator* result_tail1 = NULL;
	calculator* result_head2 = NULL;
	calculator* result_tail2 = NULL;
	while(temp2)
	{
		carry=0;
		temp1 = tail1;
		while(temp1)
		{
			mult =  carry;
			for(int i = 0;i<temp2->data;i++)
			{
				mult = mult + temp1->data;
			}
			carry = mult / 10;
			mult = mult % 10;
			if(count == 0)
			{
				add_result(&result_head1,&result_tail1,mult);
			}
			else
			{
				add_result(&result_head2,&result_tail2,mult);
			}

			temp1 = temp1->prev;
		}
		if(carry > 0 && count > 0)
		{
			add_result(&result_head2,&result_tail2,carry);
		}
		if(count==0)
		{
			if(carry > 0)
			{
				add_result(&result_head1,&result_tail1,carry);
			}
			add_result(&result_head1,&result_tail1,0);
		}
		if(count >= 1)
		{
			for(int i = 1;i<=count;i++)
			{
				insert_last(&result_head2,&result_tail2);
			}
			if(count%2 == 1)
			{
				do_addition(result_head1,result_tail1,result_head2,result_tail2,head3,tail3);
				free_node(&result_head2,&result_tail2);
				free_node(&result_head1,&result_tail1);
				add_result(head3,tail3,0);
			}
			else
			{
				do_addition(*head3,*tail3,result_head2,result_tail2,&result_head1,&result_tail1);
				free_node(head3,tail3);
				free_node(&result_head2,&result_tail2);
				add_result(&result_head1,&result_tail1,0);
			}
		}
		temp2 = temp2->prev;
		count++;
	}
	if(count%2)
	{
		free_first(&result_head1);
		if(negative_flag)
			add_result(&result_head1,&result_tail1,'-');
		print_result(&result_head1,&result_tail1);
	}
	else
	{
		free_first(head3);
		if(negative_flag)
			add_result(head3,tail3,'-');
		print_result(head3,tail3);
	}
	free_node(&result_head1,&result_tail1);
	free_node(&result_head2,&result_tail2);
	return success;
}
void insert_last(calculator** head,calculator** tail)
{
	calculator* new = malloc(sizeof(calculator));
	if(new == NULL)
	{
		printf("Memory allocation failed\n");
	}
	else
	{
		new->data = 0;
		new->prev = *tail;
		(*tail)->next = new;
		new->next = NULL;
		*tail = new;
	}
}
void free_first(calculator** head)
{
	calculator* temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
