/* Copyright 2013, Michael J. Pont. 
 * Portado a PIC16 
 */

/*==================[inclusions]=============================================*/
#include "cooperativeOs_isr.h"       // <= encabezado propio
#include "cooperativeOs_scheduler.h" // <= dispatcher and task management header

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/
/* The array of tasks  */
extern sTask_t schedulerTasks[SCHEDULER_MAX_TASKS];
/* The error code variable */
extern uint8_t errorCode;

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/*------------------------------------------------------------------*
schedulerInit()
Scheduler initialization function. Prepares scheduler
data structures.
Must call this function before using the scheduler.
-*------------------------------------------------------------------*/
void schedulerInit(void) {
    osIndexTask_t i;
    for (i = 0; i < SCHEDULER_MAX_TASKS; i++) {
        schedulerDeleteTask(i);
    }
    /* Reset the global error variable
       - schedulerDelete_Task() will generate an error code,
         (because the task array is empty) */
    errorCode = 0;
    // Inicializar el conteo de Ticks con resoluci0n de 1ms, sin tickHook
    // tickConfig( 1, 0 ) );
}

/*------------------------------------------------------------------*
schedulerUpdate()
This is the scheduler ISR. It is called at a rate
determined by the timer settings in the 'init' function.
This version is triggered by Timer 2 interrupts:
timer is automatically reloaded.
-*------------------------------------------------------------------*/
void schedulerUpdate(void) {
    osIndexTask_t index;
    // NOTE: calculations are in *TICKS* (not milliseconds)
    for (index = 0; index < SCHEDULER_MAX_TASKS; index++) {
        // Check if there is a task at this location
        if (schedulerTasks[index].pTask) {
            //if( --schedulerTasks[index].delay <= 0 ){   /* if (schedulerTasks[index].delay == 0) */
            if (schedulerTasks[index].delay == 0) {
                // The task is due to run
                schedulerTasks[index].runMe++; // Inc. the 'runMe' flag
                if (schedulerTasks[index].period) {
                    // Schedule regular tasks to run again
                    schedulerTasks[index].delay = schedulerTasks[index].period;
                }
            } else {
                // Not yet ready to run: just decrement the delay
                schedulerTasks[index].delay--;
            }
        }
    }
}

/*------------------------------------------------------------------*
schedulerStart()
Starts the scheduler, by enabling timer interrupts.
NOTE: Usually called after all regular tasks are added,
to keep the tasks synchronized.
NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!!
-*------------------------------------------------------------------*/
//void schedulerStart(tick_t tickRateMs) {
    /* Inicializar el conteo de Ticks con resolucion de tickRateMs ms (se
       ejecuta periodicamente una interrupcon cada tickRateMs ms que
       incrementa un contador de Ticks obteniendose una base de tiempos).
       Se agrega ademas como "tick hook" a la funcion encargada de planificar
       las tareas schedulerDispatchTasks().
       El tick hook es simplemente una funcion que se ejecutara periodicamente
       con cada interrupcion de Tick, este nombre se refiere a una funcion
       "enganchada" a una interrupcion */

    // Inicializar el conteo de Ticks con resolucion de 1ms, sin tickHook
    //   if( tickConfig( 1, 0 ) ){
    // Inicializar el conteo de Ticks con resolucion de 1ms, con tickHook
    //   if (tickConfig(tickRateMs, schedulerUpdate)) {
    //     //      serialDebugPrintLnString( "Comienzo del planificador." );
    //   }
//}

/*==================[end of file]============================================*/
