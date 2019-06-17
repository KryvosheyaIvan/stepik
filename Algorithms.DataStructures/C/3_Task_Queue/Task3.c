#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define DEBUG

#define STEP_LEN 100000

typedef struct 
{
	int arrival;
	int duration;
} Buffer;

typedef struct
{
	int rear;
	int front;
	int size;
	int items_in;
	Buffer stepik_buffer[STEP_LEN];
} Queue;

//global vars
int ret_data[STEP_LEN]; //time when PC started to process every of num_packets
int timeflow = 0;


bool is_empty(Queue* queue);
bool is_full(Queue* queue);
void enqueue(Queue* queue, Buffer* buffer);		//add, insert
void dequeue(Queue* queue);		//remove
void peek(Queue* queue, int* arr, int* dur);

int main(void)
{
	int size;
	int num_packets;
	Buffer incoming_buffer[STEP_LEN];
	
	Queue queue = {
		.front = -1,
		.rear = -1,
		.items_in = 0 };
			
	
	#ifdef DEBUG
		printf("\n Enter size of a buffer and then number of incoming packets! \n");
	#endif
	
	scanf("%d",&size);
	scanf("%d",&num_packets);

	if( size > 0) {
		queue.size = size;
	}
	else return;
	
	#ifdef DEBUG
		printf("\n Enter arrival time and duration to process it for each packet! \n");
	#endif
	for( int i = 0; i < num_packets; i++)
	{
		scanf("%d", &incoming_buffer[i].arrival);	
		scanf("%d", &incoming_buffer[i].duration);
	}
	
	/* If there are no packets - return! */
	if ( num_packets <= 0) return;
	
	/* Algorithm itself */
	int ax_arrival, ax_duration;
	for( int i = 0; i < num_packets; i++)
	{
		#ifdef DEBUG
			printf("\n [%d]", i);
		#endif

		if ( is_empty(&queue) )
		{
			#ifdef DEBUG
			printf("\n empty!");
			#endif
			enqueue(&queue, &incoming_buffer[i]);
			queue.front = 0;
			
			//calc time
			peek(&queue, &ax_arrival, &ax_duration);
			timeflow = ax_arrival;
			
			ret_data[i] = (incoming_buffer[i].arrival > timeflow) ? incoming_buffer[i].arrival : timeflow;
			timeflow = ret_data[i] + incoming_buffer[i].duration;
			continue;
		}
		
		
		peek(&queue, &ax_arrival, &ax_duration);
		int handle_time = (ax_arrival < timeflow) ? ax_arrival : timeflow;
		handle_time = handle_time + ax_duration;
		
		// If we have new packet before we handle front packet - then put it into queue 
		if( (incoming_buffer+i)->arrival < handle_time )
		{
			#ifdef DEBUG
			printf("\n Got first!");
			#endif
			if ( is_full(&queue)) {
			//for the moment of time, queue is full. Thats why we lose packet!
			 ret_data[i] = -1;	
			 continue;
			}
			//add packet!
			enqueue(&queue, &incoming_buffer[i]);
			ret_data[i] = (incoming_buffer[i].arrival > timeflow) ? incoming_buffer[i].arrival : timeflow;
			timeflow = ret_data[i] + incoming_buffer[i].duration;
		}
		else { //we manage to handle packet at first!
			#ifdef DEBUG
			printf("\n Managed first!");
			#endif
			
			//calculate current time!
			peek(&queue, &ax_arrival, &ax_duration);
			
			if ( is_full(&queue)) {
			//for the moment of time, queue is full. Thats why we lose packet!
			 ret_data[i] = -1;	
			}
			
			#ifdef DEBUG
			printf("\n arr: %d, time: %d", ax_arrival, timeflow);
			#endif
			
			ret_data[i] = (ax_arrival > timeflow) ? ax_arrival : timeflow;
			timeflow = ret_data[i] ;
			timeflow +=  ax_duration;
			//remove element from queue
			dequeue(&queue);
			--i;
		}
		
		#ifdef DEBUG
			printf("\n time: %d \n", timeflow);
		#endif
		
	}
	
	
	
	/* test
	enqueue(&queue, &incoming_buffer[1]);
	enqueue(&queue, &incoming_buffer[1]);
	dequeue(&queue);
	dequeue(&queue);
	*/
	
	
	//set ret buffer until queue is empty
	/*while( !is_empty(&queue) ) {
		
		peek(&queue, &ax_arrival, &ax_duration);
		ret_data[queue.front] = timeflow;
		timeflow += ax_duration;
		
		dequeue(&queue);
	}
	*/
	
	
	#ifdef DEBUG
		printf("\n Return data! \n");
		for( int i = 0; i < num_packets; i++)
		{
			printf("[%d] %d \n", i, ret_data[i]);
		}
	#else
		for( int i = 0; i < num_packets; i++)
		{
			printf("%d\n", ret_data[i]);
		}
	#endif
	
		
	return 0;
}



bool is_empty(Queue* queue)
{
	if ( queue->items_in == 0)
	{
		return true;
	}
	return false;
}

bool is_full(Queue* queue)
{
	if( queue->items_in >= queue->size)
	{
		return true;
	}

	return false;
}

/* add an item to the queue */
void enqueue(Queue* queue, Buffer* buffer)
{
	if( is_full(queue)) {
		return;
	}
	
	if( is_empty(queue)) {
		queue->items_in = 0;
		queue->rear = -1;
	}
	
	queue->rear++;
	queue->items_in++;
	queue->stepik_buffer[queue->rear].arrival = buffer->arrival;
	queue->stepik_buffer[queue->rear].duration = buffer->duration;
	
	#ifdef DEBUG
		//printf("\n enqueue! front : %d, items: %d, rear: %d\n", queue->front, queue->items_in, queue->rear);
	#endif
	
}

/* remove an item from the queue */
void dequeue(Queue* queue)
{
	queue->items_in--;
	
	if ( !is_empty(queue)) {
		queue->front++;
	}
	else if (is_empty(queue)) {
		queue->front = -1;
		queue->rear = -1;
		queue->items_in = 0;
	}
	
	#ifdef DEBUG
		//printf("\n dequeue! front : %d, items: %d, rear: %d\n", queue->front, queue->items_in, queue->rear);
	#endif
}

/* get front element, without removing it! */
void peek(Queue* queue, int* arr, int* dur)
{
	arr[0] = queue->stepik_buffer[queue->front].arrival;
	dur[0] = queue->stepik_buffer[queue->front].duration;
	
	#ifdef DEBUG
		printf("\n arr:%d, front: %d \n", queue->stepik_buffer[queue->front].arrival, queue->front);
	
		if ( is_empty(queue)) 
				printf("\n FUCK!! \n");
	
	#endif
}
				 
				 
				 
				 
				 
				 
				 
