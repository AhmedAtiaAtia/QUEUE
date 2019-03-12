/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    12 March 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/ 
/*							for Queue [int.h] 				    */
/****************************************************************/


/****************************************************************/
/* Description   : Gaurd to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _QUEUE_INT_H_
#define _QUEUE_INT_H_

#include "QUEUE_cfg.h"
#include "QUEUE_priv.h"


/****************************************************************/
/* Description    :  This function used to initialize Queue     */
/*					 Inputs : (pq_cpy) pointer to queue         */
/*                   return : Error Status 						*/
/****************************************************************/

LBTY_tenuErrorStatus QUEUE_enuInitialize (Queue  * pq_cpy) ;



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

LBTY_tenuErrorStatus QUEUE_enuPush ( QueueEntry element_cpy , Queue * pq_cpy) ;


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

LBTY_tenuErrorStatus QUEUE_enuIsFull ( Queue * pq_cpy , u8 * pout_cpy) ;

 
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

LBTY_tenuErrorStatus QUEUE_enuPop( Queue * pq_cpy , QueueEntry * pReturnElement_cpy) ; ; 


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

LBTY_tenuErrorStatus QUEUE_enuIsEmpty ( Queue * pq_cpy , u8 * pout_cpy) ;


/*****************************************************************/
/* Description   : This function used to check on queue data size*/ 					                                       															
/*				   Inputs : pointer to queue 	 ,  			 */
/*   						pointer to Data Size on queue        */
/*				   Return : Error Status 					     */
/*****************************************************************/
/* Pre_condition  :  this function must be used after queue      */
/*     				 initialized 							     */
/*****************************************************************/

LBTY_tenuErrorStatus QUEUE_enuSize ( Queue * pq_cpy , u8 * pQueueSize_Cpy) ;


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


LBTY_tenuErrorStatus QUEUE_enuEnd ( Queue * pq_cpy , QueueEntry * pElement_cpy) ;


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


LBTY_tenuErrorStatus QUEUE_enuStart (Queue  * pq_cpy , QueueEntry * pElement_cpy) ;

#endif /**!comment : End of the gaurd 							**/