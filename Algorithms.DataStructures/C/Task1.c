#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#define DEBUG_TASK1 1

#ifdef DEBUG_TASK1
	char deb[100];
#endif

#define LEN 3
#define INPUT_LEN 100

char open_brackets[LEN] =
{
	'[',
	'{',
	'('
};

char close_brackets[LEN] =
{
	']',
	'}',
	')'
};

char stack[100000];
int stack_idx = 0;					// stack pointer

int idx_first = -1;					//save index (in input array) of first unclosed bracket

void pop();
void push(char a);
bool is_stack_empty();

void ret_success(void);
void ret_fail(int index);

bool is_it_bracket(char symb);
bool is_it_open_bracket(char symb);
bool is_it_close_bracket(char symb);

bool is_row_correct(char cl_bracket);

int main(int argc, char* argv[]) {
	
	char input[101];
	int input_len = 0;
	int input_char_num = 0;
	
	#ifdef DEBUG_TASK1
		printf("Please enter a sequence of brackets (e.g. ([]{}) \r\n");
	#endif
	
	gets(input);
	input_len = strlen(input);
	
	#ifdef DEBUG_TASK1
		sprintf(deb,"IN: '%s'. Size : %d\n\n",input, strlen(input));
		printf("%s",deb);
	#endif
	
	for(int k = 0; k < input_len; k++)
	{
		input_char_num++; // var to know the index of improper symbol
		bool is_bracket = is_it_bracket(input[k]);
		if (is_bracket) {
			#ifdef DEBUG_TASK1
			//	printf("It is bracket!\n");
			#endif
			if(is_it_open_bracket(input[k])) {
				push(input[k]);	
				if(stack_idx == 1 && stack[0] != 0)
				{
					idx_first = (k+1); //save index of symbol from INPUT. (starting from 1)
				}
			}
			else if(is_it_close_bracket(input[k])) {
				//check if previous is close bracket with the same index
				if ( is_row_correct(input[k]) &&  !is_stack_empty()) {
					pop();
					
				}
				else {
					//need to find out index of first open bracket
					#ifdef DEBUG_TASK1
						printf("Exiting program...");
					#endif
					ret_fail(input_char_num);
				}
			}
		}
		else {
			//ret_fail(input_char_num);
		}
	}

	if ( is_stack_empty() ) {
	 	ret_success();
	}
	
	#ifdef DEBUG_TASK1
		printf("Cycle ended. Stack is not empty. No close bracket \n");
	#endif
	
	/* Type of error - there is open bracket and no close bracket */
	ret_fail(idx_first);

	return 0;
}


void ret_success(void) {
	printf("Success");
	exit(0);
}

void ret_fail(int index) {
	printf("%d",index);
	exit(0);
}

bool is_it_bracket(char symb) {
	for(int i = 0; i < LEN; i++)
	{
		if ( symb == open_brackets[i] || symb == close_brackets[i])
			return true;
	}
	return false;
}

bool is_it_open_bracket(char symb) {
		for(int i = 0; i < LEN; i++)
	{
		if ( symb == open_brackets[i] )
			return true;
	}
	return false;
}

bool is_it_close_bracket(char symb) {
		for(int i = 0; i < LEN; i++)
	{
		if ( symb == close_brackets[i] )
			return true;
	}
	return false;
}


void push(char a) 
{
	stack[stack_idx] = a;
	stack_idx++;
}

void pop() 
{
	stack_idx--;
	stack[stack_idx] = 0;
}

bool is_stack_empty(void) 
{
	for(int k = 0; k < INPUT_LEN; k++)
	{
		if ( stack[k] != 0 ) {
			return false;
		}
	}
	return true;
}

bool is_row_correct(char cl_bracket)
{
	int idx = 0;
	
	//define index
	for(int i = 0; i < LEN; i++)
	{
		if ( cl_bracket == close_brackets[i]) {
			idx = i;
		}
	}
	
	//check previous item in the stack
	if ( stack[stack_idx-1] == open_brackets[idx]) {
		#ifdef DEBUG_TASK1
			printf("Brackets were closed \n");
		#endif
		return true;
	}
	#ifdef DEBUG_TASK1
		printf("Brackets were improperly closed \n");
	#endif
	return false;
}

