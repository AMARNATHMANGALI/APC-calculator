/*******************************************************************************************************************************************************************
*Title                  : Addition
*Description            : This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype              : int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters       : head1: Pointer to the first node of the first double linked list.
                        : tail1: Pointer to the last node of the first double linked list.
                        : head2: Pointer to the first node of the second double linked list.
                        : tail2: Pointer to the last node of the second double linked list.
                        : head3: Pointer to the first node of the resultant double linked list.
                        : tail3: Pointer to the last node of the resultant double linked list.
*Output                 : Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "header_file.h"
Status do_addition(calculator *head1,calculator *tail1,calculator *head2,calculator *tail2,calculator **head3,calculator **tail3){
	int carry=0,sum=0,res=0,car=0;

	calculator *temp1 = tail1;
	calculator *temp2 = tail2;

	while(temp1 != NULL || temp2 != NULL)
	{
		if(temp1->prev == NULL && temp2->prev != NULL)
		{
			add_result(&head1,&tail1,0);
		}
		else if(temp2->prev == NULL && temp1->prev != NULL)
		{
			add_result(&head2,&tail2,0);
		}
		res = (temp1->data) + (temp2->data) + carry;
		car = res / 10;
		res = res % 10;
		sum =  res;

		add_result(head3,tail3,sum);

		temp1 = temp1->prev;
		temp2 = temp2->prev;
		carry = car;
	}
	if(carry != 0)
	{
		add_result(head3,tail3,carry);
	}

	return success;
}
Status add_result(calculator **head3,calculator **tail3,int sum)
{
	calculator* new = malloc(sizeof(calculator));
	if(new == NULL)
	{
		printf("Memory allocation failed\n");
		return failure;
	}

	new->data = sum;
	new->prev = NULL;
	new->next = NULL;
	if( *head3 == NULL)
	{
		*head3 = new;
		*tail3 = new;
	}
	else
	{
		new->next = *head3;
		(*head3)->prev = new;
		*head3 = new;
	}
	return success;
}
