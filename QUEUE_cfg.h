/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    12 March 2019 						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   contain Queue size and type of      */
/*                          stored data   [config.h]            */
/****************************************************************/



/****************************************************************/
/* Description   : Gaurd to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _QUEUE_CFG_H_
#define _QUEUE_CFG_H_

/*****************************************************************/
/** please Enter Number to determine MAX Size For Queue         **/
/*****************************************************************/

#define MAXQUEUE   10 

/*****************************************************************/
/** Please Enter type of Data stored on Queue                    */
/** input Values may be [ u8 , u16 , u32 , s8 , s16 , s32 ]      */
/*****************************************************************/

#define TYPE_OF_DATA_STORED_ON_QUEUE           u8  

              

#endif /** end of gaurd 									   **/
