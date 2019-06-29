#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define DEBUG
//#define DEEP_DEBUG

#define STEP_LEN ((long int)100000)

int arr_len = 0;
int window_len;
int array[STEP_LEN];

int array_B[STEP_LEN];		// max element starting from the start of the block to i`s element
int array_C[STEP_LEN];		// max element starting from the i`s to the end of the block 

int array_max[STEP_LEN];

int main(int argc, char* argv[])
{
	
	#ifdef DEBUG
		printf("\n Enter length of array...\n");
	#endif
	
	// get length of array
	scanf("%d", &arr_len);
	
	//fool defense
	if ( arr_len < 1) return 0;
	
	#ifdef DEBUG
		printf("\n Enter %d elements of array...\n", arr_len);
	#endif
	
	//get all elements
	for(int i = 0; i < arr_len; i++)
	{
		scanf("%d",&array[i]);
	}
	
	#ifdef DEBUG
		printf("\n Enter 'window' value...\n");
	#endif
	//get 'window' size
	scanf("%d",&window_len);
	
	#ifdef DEEP_DEBUG
		printf("\n Arr len : %d\n window len : %d \n ",arr_len, window_len);
		printf("Arr: ");
		for(int i = 0; i < arr_len; i++)
		{
			printf("%d ", array[i]);
		}
	#endif
	
	// if window len eq 1, then output is input array
	if ( window_len == 1) {
		for(int i = 0; i < arr_len; i++)
		{
			printf("%d ", array[i]);
		}
		//exit
		return 0;
	}
	
	
	int num_blocks = arr_len / (window_len - 1);
	num_blocks = (arr_len % (window_len - 1)) ? num_blocks + 1 : num_blocks;
	
	#ifdef DEEP_DEBUG
		printf("\n Number of blocks : %d \n", num_blocks);
	#endif
	
	int temp_max_B = 0;
	int temp_max_C = 0;
	//set array B and C
	for( int i = 0; i < num_blocks; i++)
	{
		for( int k = 0; k < window_len - 1; k++)
		{
			temp_max_B = 0;
			temp_max_C = 0;
			
			//derive temp_max_B
			for ( int j = 0; j <= k; j++)
			{
				temp_max_B = ( temp_max_B > array[ i*(window_len-1) + j] ) ? temp_max_B : array[ i*(window_len-1) + j] ;
			}
			array_B[ i*(window_len-1) + k ] = temp_max_B;
			
			//derive temp_max_C
			for ( int j = k; j < window_len - 1; j++)
			{
				temp_max_C = ( temp_max_C > array[ i*(window_len-1) + j] ) ? temp_max_C : array[ i*(window_len-1) + j] ;
			}
			array_C[ i*(window_len-1) + k ] = temp_max_C;
		}
	}
	
	#ifdef DEEP_DEBUG
		printf("\n Arr B: ");
		for(int i = 0; i < arr_len; i++)
		{
			printf("%d ", array_B[i]);
		}
	
		printf("\n Arr C: ");
		for(int i = 0; i < arr_len; i++)
		{
			printf("%d ", array_C[i]);
		}
	#endif
	
	// derive max element for every block
	for( int i = 0; i < ( arr_len - window_len + 1); i++)
	{
		array_max[i] = ( array_C[i] > array_B[ i + window_len - 1 ]) ? array_C[i] : array_B[ i + window_len - 1 ];
	}
	
	#ifdef DEEP_DEBUG
	printf("\n Arr max: ");
	#endif
	for( int i = 0; i < ( arr_len - window_len + 1); i++)
	{
		printf("%d ", array_max[i]);
	}
	
	
	return 0;
}






