#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//#define DEBUG

int num_queries;

int stack[100000];
int stack_top = -1;					// stack pointer
int max_element;					// max element on the stack

int curr_val_to_push;				// next value to stack

char ret_str[400000]; 

void pop();
void push(int a);
bool is_stack_empty();

/* Function returns true is it is push operation
	and then sets global variable curr_push
*/
bool is_push_input(char* input, int* num_to_push);

/* Function returns true if it is "max" input
	else - false
	*/
bool is_max_input(char* input);

/* Get max value on the stack */
int get_max_on_stack(void);

int main(int argc, char* argv[]) {
	
	char input[64];
	bool is_push = false, is_max = false;
	
	#ifdef DEBUG
		printf("\n Enter number of queries...\n");
	#endif
	
	// get number of queries
	fgets(input, sizeof(input), stdin);
	sscanf(input,"%d", &num_queries);
	
	if( num_queries <= 0) return 0;
	
	for ( int i = 0; i < num_queries; i++)
	{
		#ifdef DEBUG
			printf("\n Enter operation and value (ex pop or push 34) or max \n");
		#endif
		fgets(input, 64, stdin); //sizeof(input)
		
		is_max = is_max_input(input);
		
		if ( !is_max) {
			is_push = is_push_input(input, &curr_val_to_push);
			
			if ( is_push ) {			
				// if stack is empty, set max value
				if( is_stack_empty() ) max_element = curr_val_to_push;
				
				push(curr_val_to_push);
				
				//if current element > max_element then reset max value
				if ( curr_val_to_push > max_element) max_element = curr_val_to_push;
			}
			else {			//pop operation
				if( !is_stack_empty() ){
					if ( stack[stack_top] >= max_element)
					{
						pop();
						if( !is_stack_empty() ) {
							//reevaluate maximum element on the stack
							max_element = get_max_on_stack();
						}
					}
					else {
						//just pop
						pop();
					}
				}	
			}
			
		}
		else { //actions if max was entered
			//if stack is not empty - show current max value on the stack
			
		 	if( !is_stack_empty() ) {
				//olf #55test failed// printf("%d\n", max_element);
				char curr_max[60];
				sprintf(curr_max,"%d\n",max_element);
				strcat(ret_str,curr_max);
				//append ret string
			}
		}
		
	#ifdef DEBUG
		if( !is_max)
			printf("\n [%d] %s %d \n", i, (is_push ? "push" : "pop"), ( !is_push ? -1 : curr_val_to_push) );
		else
			printf("\n [%d] %s \n", i, "max");
	#endif
		
	}

	#ifdef DEBUG
	printf("%s\n\n\n", ret_str);
	#endif
	
	fwrite(ret_str, 1, strlen(ret_str), stdout);
	//printf("%s", ret_str);
	//puts(ret_str);

	return 0;
}

/* Function returns true if it is push operation
	and then sets global variable curr_push
*/
bool is_push_input(char* input, int* num_to_push)
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
		//old sscanf(input,"%s%d", operation_type, &curr_val_to_push);//num_to_push);
		return PUSH;
	}
	return POP;	
}

/* Function returns true if it is "max" input
	else - false
	*/
bool is_max_input(char* input)
{
	if( memcmp(input, "max", 3) == 0) return true;
	
	return false;
}


void push(int a) 
{
	stack_top++;
	stack[stack_top] = a;
}

void pop() 
{
	if ( is_stack_empty()) return;
	stack[stack_top] = 0;
	stack_top--;
}

bool is_stack_empty(void) 
{

	if ( stack_top <= -1 ) {
		stack_top = -1;
		return true;
	}

	return false;
}

/* Get max value on the stack */
int get_max_on_stack(void) 
{
	int max_element;
	if ( stack_top == 0) {
		max_element = stack[0];
		return max_element;
	}
	max_element = stack[0];
	
	for ( int i = 0; i <= stack_top; i++)
	{
		if( stack[i] > max_element) max_element = stack[i];
	}
	return max_element;
}

