#include "header_file.h"
Status insert_arguments(calculator **head1,calculator** tail1,calculator** head2,calculator** tail2,char* argv1,char* argv2)
{
	insert_at_last(head1,tail1,argv1);
	insert_at_last(head2,tail2,argv2);

}
Status insert_at_last(calculator** head,calculator** tail,char* argv)
{
	for(int i=0;i<strlen(argv);i++)
	{
		calculator* new = malloc(sizeof(calculator));
		if(new == NULL)
		{
			printf("Memory allocation failed\n");
			return failure;
		}
		if(argv[i] != '-' && argv[i] != '+')
		{
			new->data = argv[i] - 48;
			if(new->data >= 0 && new->data <= 9)
			{
				new->prev = NULL;
				new->next = NULL;
				if(*head == NULL)
				{
					*head = new;
					*tail = new;
				}
				else
				{
					new->prev = *tail;
					(*tail)->next = new;
					*tail = new;
				}
			}
		}
	}
	return success;
}
Status free_all(calculator** head1,calculator** tail1,calculator** head2,calculator** tail2,calculator** head3,calculator** tail3)
{
	free_node(head1,tail1);
	free_node(head2,tail2);
	free_node(head3,tail3);
}
void free_node(calculator** head,calculator** tail)
{
	calculator* temp = (*head);
	calculator* back_up = NULL;
	while(temp != NULL)
	{
		back_up = temp->next;
		free(temp);
		temp = back_up;
	}
	*head = NULL;
	*tail = NULL;
}
int find_bigger(calculator** head1,calculator** head2)
{
	calculator* temp = *head1;
	calculator* temp2 = *head2;
	while(temp && temp2)
	{
		if(temp->data > temp2->data)
			return 1;
		else if(temp2->data > temp->data)
			return 3;
		temp = temp->next;
		temp2 = temp2->next;

	}
	return 0;
}
void print_result(calculator** head,calculator** tail)
{
	printf("Result is ");
	calculator* temp = *head;
	while(temp != NULL)
	{
		if(temp->data == '-')
		{
			printf("%c",'-');
		}
		else
		{
			printf("%d",temp->data);
		}
		temp = temp->next;
	}
	printf("\n");
}
int find_length(char* argv)
{
	int i = 0,count = 0;
	while(argv[i] != '\0')
	{
		if(argv[i] == '-' || argv[i] == '+')
		{
			i++;
			continue;
		}
		else
		{
			count++;
			i++;
		}
	}
	return count;
}
