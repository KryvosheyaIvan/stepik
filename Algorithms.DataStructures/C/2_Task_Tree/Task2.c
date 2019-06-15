#include <stdio.h>

#define DEBUG
char temp[100];

int n; //number of nodes

int main( int argc, char* argv[])
{	
	#ifdef DEBUG
		printf("Enter number of nodes in the tree \n");
	#endif 
		
	scanf("%d",&n);
	
	#ifdef DEBUG
		sprintf(temp,"nodes: %d \n", n);
		printf("%s",temp);		
	#endif 
	

	return 0;
}