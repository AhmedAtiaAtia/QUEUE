#include <Stdio.h>
#include "Std_types.h"
#include "LBTY.h"
#include "QUEUE_int.h"


void main (void )
{
	
	/****Draft check */
	Queue q ;
	u8 status ;
	
	QUEUE_enuInitialize (&q);
	
	QUEUE_enuIsFull(&q , &status );
	
	if (status == 0)
	{
		QUEUE_enuPush( 150 ,&q );
		QUEUE_enuPush( 5 ,&q );
		QUEUE_enuPush( 50 ,&q );
		
		
	}
	
	QUEUE_enuPop(&q , &status);
	printf("%d \n", status );
	QUEUE_enuPop(&q , &status);
	printf("%d \n", status );
	QUEUE_enuPop(&q , &status);
	printf("%d \n", status );
	QUEUE_enuPop(&q , &status);
	printf("%d \n", status );
	QUEUE_enuPop(&q , &status);
	printf("%d \n", status );
	
	
	
}