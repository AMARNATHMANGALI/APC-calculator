/**************************************************************************************************************************************************************
*Title          : main function(Driver function)
*Description    : This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include"header_file.h"
int negative_flag=0;	
int main( int argc, char * argv[])
{
	/*Error handling to pass the valid arguments*/
	if(argc < 4)
	{
		fprintf(stderr,"Please Pass Valid Arguments\n");
		printf("Usage : result.exe operand operator operand\n");
		return 0;
	}
	/*Validation for the operator*/
	if((strcmp(argv[2],"+") !=0) && (strcmp(argv[2],"-") !=0) && (strcmp(argv[2],"x") !=0) && (strcmp(argv[2], "/") !=0))
	{
		fprintf(stderr,"Please pass valid arguments\n");
		return 0;
	}
	/*Declare pointers for the data and result*/
	calculator *head1 = NULL;
	calculator *tail1 = NULL;
	calculator *head2 = NULL;
	calculator *tail2 = NULL;
	calculator *head3 = NULL;
	calculator *tail3 = NULL;
	char ch = argv[2][0];
	/*Insert arguments into lists*/
	if( insert_arguments(&head1,&tail1,&head2,&tail2,argv[1],argv[3]) == success)
	{
		printf("Inserting successful\n");
	}
	else
	{
		printf("Inserting failed\n");
		return 0;
	}
	int difference;
	if(ch != 'x')
	{
		/*Find length of the both arguments excluding sign*/
		int length1 = find_length(argv[1]);
		int length2 = find_length(argv[3]);
		/*Based on difference add 0's to make lists equal*/
		if(length1 > length2)
		{
			difference = length1 - length2;
			for(int i = 0;i< difference;i++)
			{
				add_result(&head2,&tail2,0);			//run loop to add zeroes
			}
		}
		else if(length2 > length1)
		{
			difference = length2 - length1;
			for(int i = 0;i<difference;i++)
			{
				add_result(&head1,&tail1,0);
			}
		}
	}
	/*Find big number among two lists*/
	int big_num = find_bigger(&head1,&head2);
	if( ch == '+')											//if operator is +
	{
		if( argv[1][0] == '-' && argv[3][0] == '-')			//if both signs are negative add sign bit
		{
			negative_flag = 1;
		}
		else if(argv[big_num][0] == '-')				//if big num has - add negative sign
		{
			negative_flag = 1;
		}
	}
	else if( ch == '-')					//if ch is -
	{
		if(big_num == 1 && argv[1][0] == '-') 		//if both arguments are - enable negative flag 
		{
			negative_flag = 1;
		}
		else if(argv[3][0] != '-' && big_num != 1)		//if second argument has - and big number is not 1 enable negative flag
		{
			negative_flag = 1;
		}
	}
	else if( ch == '/' || ch == 'x')
	{
		if( argv[1][0] == '-' && argv[3][0] != '-')
			negative_flag = 1;
		else if( argv[1][0] != '-' && argv[3][0] == '-')
			negative_flag = 1;
	}
	/*Choose correct operator based on signs given for arguments*/
	if( argv[2][0] == '+')
	{
		if ( (argv[1][0] != '-' && argv[3][0] == '-') || (argv[1][0] == '-' && argv[3][0] != '-'))
		{
			ch = '-';
		}
		else
		{
			ch = '+';
		}
	}
	else if( argv[2][0] == '-')
	{
		if( (argv[1][0] == '-' && argv[3][0] != '-') || (argv[1][0] != '-' && argv[3][0] == '-'))
		{
			ch = '+';
		}
		else
		{
			ch = '-';
		}
	}
/*Switch case based on operator*/
	switch(ch)
	{
		case '+':
		/*Call addition Function*/
			if( do_addition(head1,tail1,head2,tail2,&head3,&tail3) == success)
			{
				printf("Addition successfully done\n");
			}
			else
			{
				printf("Addition failed\n");
			}
			break;
		case '-':
		/*Call Subtraction Function*/
			if(big_num == 1)
			{
				do_subt(head1,tail1,head2,tail2,&head3,&tail3) == success;
			}
			else if( big_num == 3)
			{
				do_subt(head2,tail2,head1,tail1,&head3,&tail3);
			}
			else
			{
				printf("Result is 0\n");
				return 0;
			}
			break;
		case '/':
		/*Call division Function*/
			if(big_num == 3)
			{
				printf("Result is 0\n");		//if denominator is big number than numerator the result is 0
				return 0;
			}
			else
			{
				do_division(head1,tail1,head2,tail2,&head3,&tail3);
			}

			break;
		case 'x':
		/*Call Multilication Function*/
			if(do_mul(head1,tail1,head2,tail2,&head3,&tail3) == success)
			{
				printf("Multiplication successfully done\n");
			}
			else
			{
				printf("Multiplication failed\n");
			}
			break;
	}
	/*Based on negative flag add sign for result*/
	if(negative_flag == 1)
	{
		add_result(&head3,&tail3,'-');
	}
	if(ch != 'x')
	{
		print_result(&head3,&tail3);
	}
	/*Free all the nodes after the operation*/
	free_all(&head1,&tail1,&head2,&tail2,&head3,&tail3);
	return 0;
}
