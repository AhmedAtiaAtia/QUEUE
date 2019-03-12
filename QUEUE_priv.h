/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    12 March 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    Queue priv [priv.h] contain Queue  */
/*                           definition                 		*/
/****************************************************************/


/****************************************************************/
/* Description   : Gaurd to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _QUEUE_PRIV_H_
#define _QUEUE_PRIV_H_

/***************************************************************/
/** !comment : redefine new aliase Datatype for data stored in */
/**            Queue                                           */
/***************************************************************/

typedef TYPE_OF_DATA_STORED_ON_QUEUE QueueEntry ;

/*****************************************************************/
/*!comment :Define Encabsulated Data type [ Queue ] it is Struct**/
/*          contain u8 for front and rear pointer (control) and  */
/*          array for generic type of data user defined in       */
/*          configuration file                  				**/
/*****************************************************************/

typedef struct queue 
{
   /** front simulate front queue pointer refer to first place will dequeue*/
   //u8 top ; 
	u8 front;
   /** rear simulate rear queue pointer refer to last place will enqueue*/
	u8 rear;
   /** QueueData is container for data which type generic for user */
	QueueEntry QueueData [ MAXQUEUE ] ;
	
}Queue ; /** Queue  is new Data type */


#endif /** !comment  :  End of gaurd                            **/
