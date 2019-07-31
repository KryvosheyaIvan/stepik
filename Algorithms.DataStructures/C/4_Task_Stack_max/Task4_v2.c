#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#define DEBUG
bool TEST = false;

//
int max_stack[100000];				// stack with max elements
int max_top = -1;
//


int num_queries;

/* Stack itself */
int stack[100000];
int stack_top = -1;					// stack pointer

int curr_val_to_push;				// next value to stack

char ret_str[400000]; 

void pop();
void push(int a);
bool is_stack_empty();

/* Function returns true is it is push operation
	and then sets global variable curr_push
*/
bool is_push_input(char* input);

/* Function returns true if it is "max" input
	else - false
	*/
bool is_max_input(char* input);

/* 2d Array with commands */
char input_2D[400000][64];

int main(int argc, char* argv[]) {
	
	char input[64];
	bool is_push = false, is_max = false;
	
	/* ./objectFile TEST=1 to use test.sh */
	/* Its to simplify automatic testing  */
	if ( argc > 1 ) {
		//deb printf("%s", argv[1]);
		TEST=true;
	}
		
	#ifdef DEBUG
		printf("\n Enter number of queries...\n");
	#endif
	
	// get number of queries
	fgets(input, sizeof(input), stdin);
	sscanf(input,"%d", &num_queries);
	
	#ifdef DEBUG
		printf("\n queries : %d \n", num_queries);
	#endif
	
	if( num_queries <= 0) return 0;
	
	/* Get cmds (max,pop,push) */
	for ( int i = 0; i < num_queries; i++)
	{
		fgets(&input_2D[i][0], sizeof(input), stdin); 	
	}
	
	/* Walk through cmds */
	for ( int i = 0; i < num_queries; i++)
	{
		is_max = is_max_input(&input_2D[i][0]);
		
		if ( !is_max) {
			is_push = is_push_input(&input_2D[i][0]);
			
			if ( is_push ) {								//push
				push(curr_val_to_push);
			}
			else if( !is_stack_empty() ){
						pop();
			}	
		
			
		}
		else { //actions if max was entered
			//if stack is not empty - show current max value on the stack		
		 	if( !is_stack_empty() ) {
				char curr_max[60];
				if(TEST) {
					sprintf(curr_max,"%d;", max_stack[max_top]);
					strcat(ret_str,curr_max); //append ret string
				}
				else {
					sprintf(curr_max,"%d\n", max_stack[max_top]);
					strcat(ret_str,curr_max); //append ret string
				}			
			}
		}
	}// ~for
	
	fwrite(ret_str, 1, strlen(ret_str), stdout);
	return 0;
}

/* Function returns true if it is push operation
	and then sets global variable curr_push
*/
bool is_push_input(char* input)
{
	char operation_type[64]; //pop or push
	bool POP = false, PUSH = true;
	static char* pop_s = "pop";
	static char* push_s = "push";

	sscanf(input,"%s%d", operation_type,&curr_val_to_push);

	if(memcmp(operation_type, pop_s, 3) == 0) 
	{
		return POP;
	}
	else if (memcmp(operation_type, push_s, 4) == 0) 
	{
		return PUSH;
	}
	return POP;	
}

/* Function returns true if it is "max" input
	else - false
	*/
bool is_max_input(char* input)
{
	#ifdef DEBUG
		printf("\n is_max: %s \n", input);
	#endif
	
	if( memcmp(input, "max", 3) == 0) return true;
	
	return false;
}


void push(int a) 
{
	//stack
	stack_top++;
	stack[stack_top] = a;
			
	max_top++;
	//max_stack
	if ( max_top != 0) {
		max_stack[max_top]= (a > max_stack[max_top-1]) ? a : max_stack[max_top-1];
	}
	else {
		max_stack[max_top] = a;
	}
}

void pop() 
{
	if ( is_stack_empty()) return;
	//stack
	stack[stack_top] = 0;
	stack_top--;
	
	//max_stack
	max_stack[max_top]=0;
	max_top--;
}

/* Check if stack empty */
bool is_stack_empty(void) 
{

	if ( stack_top <= -1 ) {
		stack_top = -1;
		max_top = - 1;
		return true;
	}

	return false;
}

