/*******************************************************************************************************************************************************************
*Title                  : Subtraction
*Description            : This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype              : int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters       : head1: Pointer to the first node of the first double linked list.
                        : tail1: Pointer to the last node of the first double linked list.
                        : head2: Pointer to the first node of the second double linked list.
                        : tail2: Pointer to the last node of the second double linked list.
                        : head3: Pointer to the first node of the resultant double linked list.
*Output                 : Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "header_file.h"

Status do_subt(calculator *head1,calculator *tail1,calculator *head2,calculator *tail2,calculator **head3,calculator **tail3)
{
	int sub=0;
	calculator* temp1 = tail1;
	calculator* temp2 = tail2;
	calculator* temp3 = temp1;

	while( temp1 != NULL || temp2 != NULL)
	{
		if( temp1->data >= temp2->data)
		{
			sub = (temp1->data) - (temp2->data);
		}
		else
		{
			temp3 = temp1->prev;
			while( temp3 != NULL)
			{
				if( temp3->data > 0 )
				{
					(temp3->data)--;
					break;
				}
				else if ( temp3->data == 0 && temp3->prev != NULL)
				{
					temp3->data = 9;
				}
				temp3 = temp3->prev;
			}

			sub = ( (temp1->data) +10) - (temp2->data);
		}
		add_result(head3,tail3,sub);
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
}
