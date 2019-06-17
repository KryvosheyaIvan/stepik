#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG

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
	Buffer* stepik_buffer;
} Queue;

//global vars
int* ret_data; //time when PC started to process every of num_packets
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
	Buffer* incoming_buffer;
	
	Queue queue = {
		.front = -1,
		.rear = -1,
		.items_in = 0 };
			
	
	#ifdef DEBUG
		printf("\n Enter size of a buffer and then number of incoming packets! \n");
	#endif
	
	scanf("%d",&size);
	scanf("%d",&num_packets);
	
	/* Allocate memory for buffer */
	if( size > 0) {
		queue.stepik_buffer = malloc(sizeof(Buffer)*size);
		queue.size = size;
		incoming_buffer = malloc(sizeof(Buffer)*num_packets);
		ret_data = malloc(sizeof(int)*num_packets);
	}
	
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
	for( int i = 0; i < num_packets; i++)
	{
		/*
		if( !is_full(&queue) && timeflow )
		{
			enqueue(&queue, incoming_buffer+i);
			
			// if timeflow > time of arrival, return timeflow. Return time when packet is started to be processed 
			ret_data[i] = ( timeflow > (incoming_buffer+i)->arrival) ? timeflow : (incoming_buffer+i)->arrival;
			timeflow = ret_data[i] + (incoming_buffer+i)->duration;

		}
		// if we process packet in time until another comes - dequeue it and enqueue new		
		else {
			int ax_arrival, ax_duration;
			peek(&queue, &ax_arrival, &ax_duration);
		}
		*/
		if ( is_empty(&queue) )
		{
			enqueue(&queue, incoming_buffer+i);
			queue.front = 0;
			continue;
		}
		
		int ax_arrival, ax_duration;
		peek(&queue, &ax_arrival, &ax_duration);
		int handle_time = (ax_arrival < timeflow) ? ax_arrival : timeflow;
		handle_time = handle_time + ax_duration;
		
		/* If we have new packet before we handle front packet - then put it into queue */
		if( (incoming_buffer+i)->arrival < handle_time )
		{
			if ( is_full(&queue)) {
			//for the moment of time, queue is full. Thats why we lose packet!
			 ret_data[i] = -1;	
			 continue;
			}
			//add packet!
			enqueue(&queue, incoming_buffer+i);
		}
		else { //we manage to handle packet at first!
			
			//calculate current time!
			peek(&queue, &ax_arrival, &ax_duration);
			ret_data[i] = (ax_arrival > timeflow) ? ax_arrival : timeflow;
			timeflow = ret_data[i] ;
			timeflow +=  ax_duration;
			//remove element from queue
			dequeue(&queue);
			i--;
		}
		
	}
	
	#ifdef DEBUG
		printf("\n Return data! \n");
		for( int i = 0; i < num_packets; i++)
		{
			printf("[%d] %d \n", i, ret_data[i]);
		}
	#endif
	
	//deallocating data
	if( queue.stepik_buffer != NULL )   free(queue.stepik_buffer);
	if( ret_data != NULL )				free(ret_data);
	if( incoming_buffer != NULL )		free(incoming_buffer);
		
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
	
	queue->rear++;
	queue->items_in++;
	queue->stepik_buffer[queue->rear].arrival = buffer->arrival;
	queue->stepik_buffer[queue->rear].duration = buffer->duration;
}

/* remove an item from the queue */
void dequeue(Queue* queue)
{
	queue->items_in--;
	
	if ( !is_empty(queue)) {
		queue->front++;
	}
	else {
		queue->front = -1;
	}
}

/* get front element, without removing it! */
void peek(Queue* queue, int* arr, int* dur)
{
	*arr = queue->stepik_buffer[queue->front].arrival;
	*dur = queue->stepik_buffer[queue->front].duration;
}
				 
				 
				 
				 
				 
				 
				 
