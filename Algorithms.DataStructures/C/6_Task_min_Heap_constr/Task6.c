#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define kNoTest (uint8_t)0
#define STEP_LEN ((long int)100000)

//#define METH_SCANF
#define METH_GETS

//return
int numbOper = 0; //number of replacings
char retStr[STEP_LEN];

/* Debug depth levels */
typedef enum
{
	debugOff  = 0,
	debugLev1,
	debugLev2,
	debugLev3,
	debugLev_max
} enumDebugLev;

/* Structire holding Debug/Test configuration */
typedef struct
{
	int cTEST;
	enumDebugLev eDebugLev;
} structDevTool;

/* Function establishes dev Test or Debug */
structDevTool getDevOptions(int argc, char* argv[]);





int array[STEP_LEN];
int heapSize = 0;

int getParentIdx(int idx);


int main(int argc, char* argv[])
{
	//init dev tools
	structDevTool sDevTool = { kNoTest, debugOff};
	
	sDevTool = getDevOptions(argc,argv);
	
	if(sDevTool.eDebugLev) {
		printf("\n Test %d", sDevTool.cTEST);
		printf("\n Debug %d", sDevTool.eDebugLev);
	}

	
	if(sDevTool.eDebugLev) {
		printf("\n Enter length of array...\n");
	}
	
	// get length of array
	scanf("%d", &heapSize);
	
	//fool defense
	if ( heapSize < 1) return 0;
	
	if(sDevTool.eDebugLev) {
		printf("\n Enter %d elements of array...\n", heapSize);
	}
	
	//get all elements
	for(int i = 0; i < heapSize; i++)
	{
		scanf("%d",&array[i]);
	}
	
	int parIdx = 0;
	int idxResult;
	bool isRepl = false;
	int idxTemp;
	//Algorithm
	for(int idx = heapSize-1; idx != 0 ; idx--)
	{
		idxTemp = idx;
		do {
			parIdx = getParentIdx(idxTemp);	
			if(array[parIdx] > array[idxTemp]) {
				int temp = array[parIdx];
				array[parIdx] = array[idxTemp];
				array[idxTemp] = temp;
				numbOper++;
				isRepl = true;
				idxResult = idxTemp;  // save idx to return string (to print it at the end)
				idxTemp = parIdx;	  //save to next iteration
				
				//build output string
				char cTempStr[32];
				if(sDevTool.cTEST) {
					sprintf(cTempStr,"%d<->%d_", parIdx, idxResult);
					strcat(retStr,cTempStr);	
				}
				else {
					sprintf(cTempStr,"%d %d\n", parIdx, idxResult);
					strcat(retStr,cTempStr);					
				}
			} 
			else {
				isRepl = false;
			}
		} while(isRepl);
		
	}

	if(sDevTool.eDebugLev) {
		printf("\n m : %d (numb of actions)", numbOper);
		printf("\n Result : %d elements of array...\n", heapSize);
		for(int i = 0; i < heapSize; i++)
		{
			printf("%d ", array[i]);
		}
		
		printf("\n Stepik gets\n");
		printf("%d\n", numbOper);	//print number of swap used
		printf("%s", retStr);
	}
	//Printing result to ....
	else if(sDevTool.cTEST) {
		//automatic testing in bash
		printf("%d_", numbOper);	//print number of swap used
		printf("%s", retStr);
	}
	else {//print results for stepik
		printf("%d\n", numbOper);	//print number of swap used
		printf("%s", retStr);
	}
	

	
	return 0;
}

int getParentIdx(int idx)
{
	//return idx/2;
	return (idx-1)/2;
}

/* Function establishes dev Test or Debug */
structDevTool getDevOptions(int argc, char* argv[])
{
	structDevTool retStruct = { kNoTest, debugOff};	
	static char* cTest  = "TEST";
	static char* cDebug = "DEBUG";
	
	if( !(argc > 1)) return retStruct;
	else if (argc >= 2) {
		//printf("opt %s", argv[1]);
		if ( strstr(argv[1], cTest) != NULL) {
			//Test option
			sscanf(argv[1],"%*[^0123456789]%d", &retStruct.cTEST);
		}
		else if( strstr(argv[1], cDebug) != NULL) {
			//Debug option
			sscanf(argv[1],"%*[^0123456789]%d", (int*)&retStruct.eDebugLev);
		}
		
	}
	
	if( argc >= 3) {
		if ( strstr(argv[2], cTest) != NULL) {
			//Test option
			sscanf(argv[2],"%*[^0123456789]%d", &retStruct.cTEST);
		}
		else if( strstr(argv[2], cDebug) != NULL) {
			//Debug option
			sscanf(argv[2],"%*[^0123456789]%d", (int*)&retStruct.eDebugLev);
		}
	}
	
	// var limitation
	retStruct.eDebugLev = (retStruct.eDebugLev > debugLev_max) ? debugLev_max : retStruct.eDebugLev;
	retStruct.cTEST = (retStruct.cTEST > 1) ? 1 : retStruct.cTEST ;
	
	//If Test --> No Debug
	if ( retStruct.cTEST) retStruct.eDebugLev = debugOff;
	
	return retStruct;
}

