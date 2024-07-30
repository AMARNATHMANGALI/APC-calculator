#ifndef HEADER_FILE
#define HEADER_FILE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	struct node* prev;
	int data;
	struct node* next;
}calculator;

typedef enum 
{
	failure,
	success,
}Status;

Status insert_arguments(calculator **head1,calculator** tail1,calculator** head2,calculator** tail2,char* argv1,char* argv2);

Status insert_at_last(calculator** head1,calculator** tail1,char* data);

Status do_addition(calculator *head1,calculator *tail1,calculator *head2,calculator *tail2,calculator **head3,calculator **tail3);


Status add_result(calculator **head3,calculator **tail3,int sum);

Status free_all(calculator** head1,calculator** tail1,calculator** head2,calculator** tail2,calculator** head3,calculator** tail3);

void free_node(calculator** head,calculator** tail);
int find_bigger(calculator** head1,calculator** head2);

Status do_subt(calculator *head1,calculator *tail1,calculator *head2,calculator *tail2,calculator **head3,calculator **tail3);
void print_result(calculator** head,calculator** tail);
int find_length(char* argv);

Status do_division(calculator* head1,calculator* tail1,calculator* head2,calculator* tail2,calculator** head3,calculator** tail3);
int check_node(calculator** head1,calculator** head2);
Status do_mul(calculator* head1,calculator* tail1,calculator* head2,calculator* tail2,calculator** head3,calculator** tail3);
void insert_last(calculator** head,calculator** tail);
void insert_first(calculator** head, calculator** tail, int data);
void free_first(calculator** head);
//Status do_sub(calculator *head1,calculator *tail1,calculator *head2,calculator *tail2,calculator **head3,calculator **tail3);



/*int find_length(char* argv);
int flag(int value1,int value2);

Status insert_at_last(calculator **head1,calculator **tail1,calculator **head2,calculator **tail2,char* argv1,char* argv2);

Status insert_list(calculator **head,calculator **tail,char* argv);

Status do_sub(calculator *head1,calculator *tail1,calculator *head2,calculator *tail2,calculator **head3,calculator **tail3);
Status sub(calculator *head1,calculator *tail1,calculator *head2,calculator *tail2,calculator **head3,calculator **tail3);*/


#endif
