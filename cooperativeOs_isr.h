/* Copyright 2013, Michael J. Pont. 
 * Portado a PIC16 
 */

#ifndef _COOPERATIVE_OS_ISR_H_
#define _COOPERATIVE_OS_ISR_H_

/*==================[inclusions]=============================================*/

//#include "sapi.h"   // <= sAPI header

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

// FUNCION que inicializa el planificador de tareas.
void schedulerInit( void );

// FUNCION que inicializa la interrupcion que ejecuta el planificador de
// tareas.
//void schedulerStart( tick_t );

// FUNCION que contiene el planificador de tareas.
void schedulerUpdate( void );

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _COOPERATIVE_OS_ISR_H_ */
