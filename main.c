/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene la función principal
 * 
 * Aquí se encuentra la implementación de la función principal
 */
/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* Para las definiciones de uint8_t por ej.*/
#include "system.h"     /* Funciones/Parametros System, como osc/peripheral config */
#include "user.h"       /* Funciones/Parametros User, como InitApp */
#include "uart.h"       /* Funciones/Parametros Uart */
#include "display.h"    /* Funciones/Parametros Display */
#include "tick.h"       /* Funciones/Parametros Tick */
#include <stdio.h>      /* Archivo de Encabezados StdIO */

#include "cooperativeOs_isr.h"       // <= dispatcher and task management header
#include "cooperativeOs_scheduler.h" // <= scheduler and system initialization header

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/
void Tarea1( void );
void Tarea2( void );
void Tarea3( void );

/*==================[funcion principal]======================================*/
void main(void) {
    /* TODO: Agregar el Cod1iogo de la Aplicación aquí */
    // FUNCION que inicializa el planificador de tareas
	schedulerInit();
	// Se agrega la tarea tarea1 al planificador
	schedulerAddTask( Tarea1, 0, 500);
	// Se agrega la tarea tarea2 al planificador
	schedulerAddTask( Tarea2, 10, 250 );
	// Se agrega la tarea tarea3 al planificador
	schedulerAddTask( Tarea3, 20, 3 );
    
    appInit();          /* Inicializa I/O y Periféricos de la aplicación */
    while (1) {
        schedulerDispatchTasks();
    }
}

/*==================[definiciones de funciones internas]=====================*/
void Tarea1( void ){
    static uint16_t t=0;
    PIN_LED_V = !PIN_LED_V;
    if(t++ > 50){
        t = 0;
    }
}

void Tarea2( void ){
    static uint16_t t=0;
    PIN_LED_R = !PIN_LED_R;
    if(t++ > 25){
        t = 0;
    }
}

void Tarea3( void ){
    PIN_SOUNDER = !PIN_SOUNDER;
}

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
