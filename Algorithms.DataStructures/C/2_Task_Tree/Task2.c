#include <stdio.h>
#include <string.h>

#define STEP_LENGTH 100000

//#define DEBUG
char temp[100];

int n; //number of nodes
int tree_array[STEP_LENGTH];
int depth_array[STEP_LENGTH];
int height;

void find_depth(int tree[], int idx, int depth[]);

int main( int argc, char* argv[])
{	
	/* Set 0 to all depths */
	memset(depth_array, 0, STEP_LENGTH);
	
	#ifdef DEBUG
		printf("Enter number of nodes in the tree \n");
	#endif 
		
	scanf("%d",&n);
	
	#ifdef DEBUG
		sprintf(temp,"nodes: %d \n", n);
		printf("%s",temp);		
	#endif 
	
	for( int i = 0; i < n; i++)
	{
		scanf("%d",&(tree_array[i]));
	}
	
	#ifdef DEBUG
	printf("\n");
	for( int i = 0; i < n; i++)
	{
		sprintf(temp,"%d \t", tree_array[i]);
		printf("%s",temp);
	}
	#endif 
	
	/* Algorithm itself! */
	for( int i = 0; i < n; i++)
	{
		find_depth(tree_array, i, depth_array);
	}
	
	#ifdef DEBUG
	printf("Depth! \n");
	for( int i = 0; i < n; i++)
	{
		printf("%d \t", depth_array[i]);
	}
	#endif 
	
	/* Find maximun of a depth! */
	height = depth_array[0];
	for( int i = 1; i < n; i++)
	{
		if ( depth_array[i] > height) height = depth_array[i];
	}

	/* Height! */
	#ifdef DEBUG
		printf("\n Height: %d", height);
	#else
		printf("%d", height);
	#endif 
	
	return 0;
}

void find_depth(int tree[], int idx, int depth[])
{
	/* There is already a value! (calculated already) */
	if( depth[idx] ) return;	
	
	if( tree[idx] == -1) { 
		depth[idx] = 1;
		return;
	}
	/* if we do not have a depth of a parent - we cant evaluate this value! */
	if( depth[tree[idx]] == 0) {
		find_depth(tree_array, tree[idx], depth_array);
	}
	
	/* Now we have a depth of a parent! */		  
	depth[idx] = depth[tree[idx]] + 1;
	
}



