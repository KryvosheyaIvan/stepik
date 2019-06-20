#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG

#define STEP_LEN ((long int)100000)

#define ACT_ENQ 1
#define ACT_DEQ 2



typedef struct 
{
	int arrival;
	int duration;
	int index;
} Buffer;

typedef struct
{
	int rear;
	int front;
	int size;
	int items_in;
	Buffer stepik_buffer[STEP_LEN];
} Queue;


Buffer incoming_buffer[STEP_LEN];

//global vars
int ret_time[STEP_LEN]; //time when PC started to process every of num_packets
int finish_time[STEP_LEN]; //time when PC finished to process every of num_packets

bool is_empty(Queue* queue);
bool is_full(Queue* queue);
void enqueue(Queue* queue, Buffer* buffer, int idx);	//add, insert
void dequeue(Queue* queue);		//remove

/* return index of first packet from circular buffer */		 
int ret_index_from_cQueue(Queue* queue);


void watch_time(int action, int i, Queue* queue);

int main(void)
{
int size;
int num_packets;
	
	Queue queue = {
		.front = -1,
		.rear = -1,
		.items_in = 0 };
			
	
	#ifdef DEBUG
		//printf("\n Enter size of a buffer and then number of incoming packets! \n");
	#endif
	
	scanf("%d",&size);
	scanf("%d",&num_packets);

	if( size > 0) {
		queue.size = size;
	}
	else return;
	
	#ifdef DEBUG
		//printf("\n Enter arrival time and duration to process it for each packet! \n");
	#endif
	for( int i = 0; i < num_packets; i++)
	{
		scanf("%d", &incoming_buffer[i].arrival);	
		scanf("%d", &incoming_buffer[i].duration);
	}
	
	/* If there are no packets - return! */
	if ( num_packets <= 0) return;
	
	/* Algorithm */
	for( int idx = 0; idx < num_packets; idx++)
	{
		//if not full --> insert data
		if ( !is_full(&queue)) {
			
			watch_time( ACT_ENQ, idx, &queue);
			
			/* insert packet */
			enqueue(&queue, &incoming_buffer[idx], idx);
		}
		else if ( is_full(&queue)) {
			
			watch_time( ACT_DEQ, idx, &queue);
			/* delete packet*/
			//dequeue(&queue);
		}
	}
	
	
	#ifdef DEBUG
		printf("\n Return data! \n");
		for( int i = 0; i < num_packets; i++)
		{
			//printf("[%d] %d \n", i, ret_time[i]);
			printf("%d ", ret_time[i]);
		}
		printf("\n ");
	#else
		for( int i = 0; i < num_packets; i++)
		{
			printf("%d\n", ret_time[i]);
		}
	#endif
	
		
	return 0;
}



bool is_empty(Queue* queue)
{
	if ( queue->items_in == 0 || queue->front== -1)
	{
		return true;
	}
	return false;
}

bool is_full(Queue* queue)
{
	if((queue->front== 0 && queue->rear == queue->size-1)|| ( queue->front == queue->rear+1) )
	{
		return true;
	}

	return false;
}

/* add an item to the queue */
void enqueue(Queue* queue, Buffer* buffer, int idx)
{
	if( is_full(queue)) {
		return;
	}

	if ( queue->front == -1) queue->front = queue->front + 1;
	
	if (queue->rear == queue->size-1) { queue->rear  = 0; }
	else { queue->rear = queue->rear + 1;}
	
	if ( queue->rear < 0) queue->rear = 0;

	queue->items_in++;
	queue->stepik_buffer[queue->rear].arrival = buffer->arrival;
	queue->stepik_buffer[queue->rear].duration = buffer->duration;
	queue->stepik_buffer[queue->rear].index = idx; //save index from incoming buffer
}

/* remove an item from the queue */
void dequeue(Queue* queue)
{
	if (is_empty(queue)) {
		queue->items_in = 0;
		return;
	}
	
	if ( queue->front == queue->size-1) queue->front = 0;
	else if( queue->front == queue->rear)
	{
		queue->front = -1;
		queue->rear = -1;
	}
	else {
		queue->front++;	
	}

}
				 
				 
void watch_time(int action, int i, Queue* queue)
{
	int idx_finish;
	int finish_value;
	
	/* if we insert previously */
	if ( action == ACT_ENQ) 
	{
		if ( i > 0) {
			idx_finish = i - 1;
			finish_value = finish_time[idx_finish];
			/* if packet arrives first, we take that time. If previous packet are managed later -> we take later time */
			ret_time[i] = (incoming_buffer[i].arrival > finish_value) ? incoming_buffer[i].arrival : finish_value;
			
			/* save time for next iteration */
			finish_time[i] = ret_time[i] + incoming_buffer[i].duration;
		}
		else if( i == 0) {
			ret_time[i] = incoming_buffer[i].arrival;
			finish_time[i] = ret_time[i] + incoming_buffer[i].duration;
		}
	}
	else if ( action == ACT_DEQ)
	{
		/* if last packet arrives after previous has been processed */
		if( incoming_buffer[i].arrival >= finish_time[ret_index_from_cQueue(queue)] )
		{			
			//free 1 space
			dequeue(queue);
			
			//old
			//ret_time[i] = incoming_buffer[i].arrival;
			ret_time[i] = (incoming_buffer[i].arrival > finish_time[i-1]) ? incoming_buffer[i].arrival : finish_time[i-1];
			finish_time[i] = ret_time[i] + incoming_buffer[i].duration;

			enqueue(queue, &incoming_buffer[i], i);
			
		}
		/* we lost packet!( */
		else if ( incoming_buffer[i].arrival < finish_time[ret_index_from_cQueue(queue)] )
		{
			ret_time[i] = -1;
			finish_time[i] = finish_time[i-1]; //wrong value but we will not use it for real!
		}
	}
}				 
				 
/* return index of first packet from circular buffer */		 
int ret_index_from_cQueue(Queue* queue)
{
	return queue->stepik_buffer[queue->front].index;
}
