#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DEBUG

//#define METH_SCANF
#define METH_GETS


#define STEP_LEN ((long int)100000)

int array[STEP_LEN];
int heapSize = 0;

void heapify(int i, int heapSize);
void heapify_stupid(int idx_son, int heapSize);

int getLeftChildIdx(int idx);
int getRightChildIdx(int idx);
int getParentIdx(int idx);

int swap(int a, int b);

int main(int argc, char* argv[])
{
	
	#ifdef DEBUG
		printf("\n Enter length of array...\n");
	#endif
	
	// get length of array
	scanf("%d", &heapSize);
	
	//fool defense
	if ( heapSize < 1) return 0;
	
	#ifdef DEBUG
		printf("\n Enter %d elements of array...\n", heapSize);
	#endif
	
	//get all elements
	for(int i = 1; i <= heapSize; i++)
	{
		scanf("%d",&array[i]);
	}
	
	
	/* 1
	for( int i = heapSize/2; i >= 0; i--)
	{
		#ifdef DEBUG
			printf("\n heapify! %d ", i);
		#endif
		heapify( 1, heapSize);
	}
	*/
	
	/* 2
	for(int i = heapSize; i >= 1; i--)
	{
		heapify_stupid(i, heapSize);
	}
	*/
	
	int i = heapSize;
	while( (i > 1) && ( array[getParentIdx(i)] > array[i] ) )
	{
		int temp = array[getParentIdx(i)];
		array[getParentIdx(i)] = array[i];
		array[i] = temp;	
		 
						 
		i = getParentIdx(i);
	}
		
	#ifdef DEBUG
		printf("\n Result : %d elements of array...\n", heapSize);
		for(int i = 1; i <= heapSize; i++)
		{
			printf("%d ", array[i]);
		}
	#endif
	
	return 0;
}

void heapify(int idx, int heapSize)
{
	int leftChild;
	int rightChild;
	int largestChild = -1;
	

	while( 1 )
	{
		leftChild = 2 * idx + 1;
		rightChild = 2 * idx + 2;
		largestChild = idx;
		
		if( leftChild < heapSize && array[leftChild] > array[largestChild])
		{
			largestChild = leftChild;
		}
		
		if( rightChild < heapSize && array[rightChild] > array[largestChild] )
		{
			largestChild = rightChild;
		}
		
		if(largestChild == idx )
		{
			break;
			#ifdef DEBUG
				printf("\n break!...\n");
			#endif
		}
		
		int temp = array[idx];
		array[idx] = array[largestChild];
		array[largestChild] = temp;
		idx = largestChild;
	}
}


void heapify_stupid(int idx_son, int heapSize)
{
	const int wRootIdx = 1;
	if ( idx_son == wRootIdx) return;
	
	int wIdxParent = idx_son / 2;
	
	if( array[wIdxParent] > array[idx_son])
	{
		int temp = array[wIdxParent];
		array[wIdxParent] = array[idx_son];
		array[idx_son] = temp;
	}
	
}


int getLeftChildIdx(int idx)
{
	return 2*idx;
}

int getRightChildIdx(int idx)
{
	return (2*idx + 1);
}

int getParentIdx(int idx)
{
	return idx/2;
}


