/* Copyright 2013, Michael J. Pont. 
 * Portado a PIC16 
 */

#ifndef _COOPERATIVE_OS_SCHEDULER_H_
#define _COOPERATIVE_OS_SCHEDULER_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>     /* For uint8_t definition */

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/* The maximum number of tasks required at any one time during the execution
   of the program. MUST BE ADJUSTED FOR EACH NEW PROJECT */
#ifndef SCHEDULER_MAX_TASKS
   #define SCHEDULER_MAX_TASKS   (5)
#endif

/*==================[typedef]================================================*/
typedef uint8_t osIndexTask_t;
typedef uint16_t osTick_t;
typedef uint8_t osRunMe_t;

/* Store in DATA area, if possible, for rapid access.
   Total memory per task is 7 bytes. */
typedef struct{
   // Pointer to the task (must be a 'void (void)' function)
   //sAPI_FuncPtr_t pTask;  // void (* pTask)(void);
   void (* pTask)(void);
   // Delay (ticks) until the function will (next) be run
   // - see schedulerAddTask() for further details
   osTick_t delay;
   // Interval (ticks) between subsequent runs.
   // - see schedulerAddTask() for further details
   osTick_t period;
   // Incremented (by scheduler) when task is due to execute
   osRunMe_t runMe;
} sTask_t;

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
// FUNCION que contiene el despachador de tareas.
void schedulerDispatchTasks( void );

// FUNCION que añade una tarea al planificador.
osIndexTask_t schedulerAddTask( void (* pFunction)(void),
                          const osTick_t DELAY,
                          const osTick_t PERIOD
                        );

// FUNCION que remueve una tarea del planificador.
int8_t schedulerDeleteTask( osIndexTask_t taskIndex );

// FUNCION que reporta el estado del sistema.
void schedulerReportStatus( void );

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _COOPERATIVE_OS_SCHEDULER_H_ */
