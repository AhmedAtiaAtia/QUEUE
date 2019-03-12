/****************************************************************/
/*   Author             :    Ahmed Atia Atia				    */
/*	 Date 				:    12 March 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Progam algorithm for Queue [prog.c]*/
/****************************************************************/

/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "Std_types.h"
#include "LBTY.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "QUEUE_cfg.h"
#include "QUEUE_priv.h"
#include "QUEUE_int.h"


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize Queue     */
/*					 Inputs : (pq_cpy) pointer to queue         */
/*                   return : Error Status 						*/
/****************************************************************/

LBTY_tenuErrorStatus QUEUE_enuInitialize (Queue  * pq_cpy)
{
	
	LBTY_tenuErrorStatus ErrorStat ; 
	
	/***********************************************************/
	/**!comment   :  we need to check on passing parameter     */
	/**              pointer if null return null else  ok      */
	/***********************************************************/
	
	if (pq_cpy != LBTY_NULL)
	{
		
	/*********************************************************************/
	/**!comment : we initialize Queue by inialize (front = rear-1)=start */
	/**           [start of queue indicate to place will enqueue on it]  */ 
	/*********************************************************************/
		pq_cpy -> front = 0  ;
	    pq_cpy -> rear = 0   ; 
		ErrorStat = LBTY_OK ;
	
	}
	else 
	{
		ErrorStat = LBTY_NULL_POINTER ;
	}
	
	return ErrorStat ; 
}



/*******************************************************************/
/* Description    :  This function used to enqueue new element in  */
/*					 queue  	    					  		   */
/*					 Inputs : pointer to enqueue (rear) ,          */
/*   						  element we need to enqueue 		   */
/*					 return : Error Status 						   */
/*******************************************************************/
/* Pre_condition  :  this function must be used after queue        */
/*     				 initialized and check if it is Is not Full    */
/*                   we can use it to enqueue 					   */
/*******************************************************************/

LBTY_tenuErrorStatus QUEUE_enuPush ( QueueEntry element_cpy , Queue * pq_cpy)
{
	LBTY_tenuErrorStatus ErrorStat  ;
	
	/***********************************************************/
	/**!comment   :  we need to check on passing parameter     */
	/**              pointer if null return null else  ok      */
	/***********************************************************/
	
	if ( pq_cpy == LBTY_NULL )
	{
		ErrorStat  = LBTY_NULL_POINTER ;
		
	}
	else 
	{
		
	/***********************************************************/
	/**!comment   :  enqueu data element to next place in queue*/
	/**              and increment position start to the next  */
	/**				 place 									   */
	/***********************************************************/
	    
		
		pq_cpy -> QueueData[pq_cpy -> rear ] = element_cpy ;  
	     
		pq_cpy -> rear ++ ;
		
		ErrorStat = LBTY_OK ;	
	
	}
	
	return ErrorStat ; 
	
}


/****************************************************************/
/* Description    : This function used to check if queue is Full*/ 
/*					or not full used befor enqueu any element.  */
/*					Inputs : pointer to enqueu (rear)	 ,  	*/
/*   						 pointer to output status 			*/
/*					Return : Error Status 						*/
/****************************************************************/
/* Pre_condition  :  this function must be used after queue     */
/*     				 initialized 							    */
/****************************************************************/

LBTY_tenuErrorStatus QUEUE_enuIsFull ( Queue * pq_cpy , u8 * pout_cpy)
{
	LBTY_tenuErrorStatus ErrorStatLoc ; 
	
	/************************************************************/
	/** !comment :  check on passing pointers                   */
	/************************************************************/
	
	if (pq_cpy == LBTY_NULL || pout_cpy == LBTY_NULL )
	{
			
			ErrorStatLoc = LBTY_NULL_POINTER ;
			
	}
	else 
	{
		
	/***********************************************************/	
	/** !comment : check if last position equal Maxqueue size  */
	/*             that is mean queue is full 				   */
	/***********************************************************/
	
		if  ( pq_cpy -> rear  >= MAXQUEUE)
		{
						    /************************************/
			*pout_cpy = 1 ; /** mean queue Full                 */
						    /************************************/
		}
		else 
		{				    /************************************/
			*pout_cpy = 0 ; /* mean queue is not full           */
						    /************************************/
		}
		
		ErrorStatLoc = LBTY_OK ; 
		
	}
	
	return ErrorStatLoc ; 
}


/***********************************************************************/
/* Description   : This function used to dequeue first element enqueued*/
/*				   in queue until now 							       */
/*				   Inputs : pointer to dequeue (front) 	 ,  		   */
/*   					    pointer to element we need to dequeue      */			
/*				   Return : Error Status 						       */
/***********************************************************************/
/* Pre_condition  :  this function must be used after queue            */
/*     				 initialized and check if it is Is not Empty       */
/*                   we can use it to dequeue from queue 	           */
/***********************************************************************/

LBTY_tenuErrorStatus QUEUE_enuPop( Queue * pq_cpy , QueueEntry * pReturnElement_cpy)
{
	
	LBTY_tenuErrorStatus ErrorStatLoc ; 
	
	/************************************************************/
	/** !comment :  check on passing pointers                   */
	/************************************************************/
	
	if (pq_cpy == LBTY_NULL || pReturnElement_cpy == LBTY_NULL )
	{
			
	    ErrorStatLoc = LBTY_NULL_POINTER ;
			
	}
	else 
	{
		
		
		/**********************************************************/
		/** !comment : return first data enqueued in queue to user*/ 
		/*			   by passing value to passed pointer         */
		/**********************************************************/
		
	    *(pReturnElement_cpy) = pq_cpy -> QueueData [pq_cpy->front] ;

		
        /************************************************************/
		/* means no value in this position							*/
		/* initial value of array         							*/
		/* dequeue of this position =0							    */
	    /************************************************************/

		pq_cpy -> QueueData [pq_cpy->front] = 0;							  
									  
        /*******************************************************/
		/** !comment  : increment first to point to next first */
		/*              Data element enqueued to returned      */
		/*******************************************************/
									  
		pq_cpy -> front ++ ;
		
		
	
	    ErrorStatLoc = LBTY_OK ; 
	}
	
	return ErrorStatLoc  ;
}


/*****************************************************************/
/* Description    : This function used to check if queue is Empty*/ 
/*					or not Empty used befor dequeue any element  */
/*                  from queue                                   */
/*					Inputs : pointer to dequeue (front) ,        */
/*                           pointer to enqueue (rear) ,		 */
/*   						 pointer to output status 			 */
/*					Return : Error Status 					     */
/*****************************************************************/
/* Pre_condition  :  this function must be used after dequeue    */
/*     				 initialized 							     */
/*****************************************************************/

LBTY_tenuErrorStatus QUEUE_enuIsEmpty ( Queue * pq_cpy , u8 * pout_cpy)
{
	LBTY_tenuErrorStatus ErrorStatLoc ; 
	
	/************************************************************/
	/** !comment :  check on passing pointers                   */
	/************************************************************/
	
	if ( pq_cpy == LBTY_NULL || pout_cpy == LBTY_NULL )
	{
			
			ErrorStatLoc = LBTY_NULL_POINTER ;
			
	}
	else 
	{
		
	/***********************************************************/	
	/** !comment : check if top equal zero size  that is mean  */
	/**            queue is Empty    					       */
	/***********************************************************/
	
		if  (( pq_cpy -> front  > pq_cpy -> rear ) && ((pq_cpy -> QueueData [pq_cpy->front]) == 0))
		{
						    /************************************/
			*pout_cpy = 1 ; /** mean queue Empty                */
						    /************************************/
		}
		else 
		{				    /************************************/
			*pout_cpy = 0 ; /* mean queue is not Empty          */
						    /************************************/
		}
		
		ErrorStatLoc = LBTY_OK ; 
		
	}
	
	return ErrorStatLoc ; 
}


/*****************************************************************/
/* Description   : This function used to check on queue data size*/ 					                                       															
/*				   Inputs : pointer to queue 	 ,  			 */
/*   						pointer to Data Size on queue        */
/*				   Return : Error Status 					     */
/*****************************************************************/
/* Pre_condition  :  this function must be used after queue      */
/*     				 initialized 							     */
/*****************************************************************/

LBTY_tenuErrorStatus QUEUE_enuSize ( Queue * pq_cpy , u8 * pQueueSize_Cpy)
{
	LBTY_tenuErrorStatus ErrorStatLoc ;
		
	/************************************************************/
	/** !comment :  check on passing pointers                   */
	/************************************************************/
	
	if ( pq_cpy == LBTY_NULL || pQueueSize_Cpy == LBTY_NULL )
	{										
		ErrorStatLoc = LBTY_NULL_POINTER ;  
		
	}
	else 
	{
			
	/***********************************************************/	
	/** !comment : Return to pQueueSize_Cpy  Queue data size by*/ 
	/**            returnning queue (last - first) +1 		   */
	/***********************************************************/
	
		*(pQueueSize_Cpy) = ((pq_cpy -> rear - pq_cpy -> front) +1) ;
		
		ErrorStatLoc = LBTY_OK ; 
		
	}
	
	return  ErrorStatLoc ;
	
}


/******************************************************************/
/* Description   : This function used to return Data on queueEnd  */
/*                 without change queue Size 					  */ 					                                       															
/*				   Inputs : pointer to enqueu (rear) ,  		  */
/*   						pointer to Data element 			  */
/*				   Return : Error Status 					      */
/******************************************************************/
/* Pre_condition  :  this function must be used after queue       */
/*     				 initialized 	and Not Empty                 */
/******************************************************************/


LBTY_tenuErrorStatus QUEUE_enuEnd ( Queue * pq_cpy , QueueEntry * pElement_cpy)
{
	LBTY_tenuErrorStatus ErrorStatLoc ;
	
	/** !comment : check on passing parameter                    */
	
	if (pq_cpy == LBTY_NULL || pElement_cpy == LBTY_NULL )
	{
		
		ErrorStatLoc = LBTY_NULL_POINTER  ; 
		
	}
	else 
	{	/********************************************************/
		/** !comment:  return Data on queueEnd to pElement      */
		/**            without Change rear or queue size or data*/   
		/********************************************************/
		
		 *pElement_cpy = pq_cpy -> QueueData [ (pq_cpy -> rear ) ] ; 
		 
		 ErrorStatLoc = LBTY_OK ;
	}
	
	return ErrorStatLoc ; 
}

/******************************************************************/
/* Description   : This function used to return Data on queueStart*/
/*                 without change Queue Size 					  */ 					                                       															
/*				   Inputs : pointer to dequeue (front) 	 ,  	  */
/*   						pointer to Data element 			  */
/*				   Return : Error Status 					      */
/******************************************************************/
/* Pre_condition  :  this function must be used after queue       */
/*     				 initialized 	and Not full                  */
/******************************************************************/


LBTY_tenuErrorStatus QUEUE_enuStart (Queue  * pq_cpy , QueueEntry * pElement_cpy)
{
	LBTY_tenuErrorStatus ErrorStatLoc ;
	
	/** !comment : check on passing parameter                    */
	
	if (pq_cpy == LBTY_NULL || pElement_cpy == LBTY_NULL )
	{
		
		ErrorStatLoc = LBTY_NULL_POINTER  ; 
		
	}
	else 
	{	/*********************************************************/
		/** !comment:  return Data on queueStart to pElement     */
		/**            without Change top or stack size or data  */   
		/*********************************************************/
		
		 *pElement_cpy = pq_cpy -> QueueData [ (pq_cpy -> front ) ] ; 
		 
		 ErrorStatLoc = LBTY_OK ;
	}
	
	return ErrorStatLoc ; 
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/