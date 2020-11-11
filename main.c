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

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[funcion principal]======================================*/
void main(void) {
    /* TODO: Agregar el Cod1iogo de la Aplicación aquí */
    tick_t tinicioRojo,tinicioAmarillo,tinicioVerde,tinicioAzul;
    uint8_t numero = 0;
    tick_t tinicioDisp;
    
    appInit();          /* Inicializa I/O y Periféricos de la aplicación */
    displayWrite(numero);       //Muestra un 0
    tinicioDisp = tickRead();   //Inicia temporización del display

    PIN_LED_V = 1;              //Prende led
    PIN_LED_R = 0;              //Apaga led    
    PIN_LED_AM = 0;             //Apaga led    
    PIN_LED_AZ = 0;             //Apaga led    

    while (1) {
        //Testea los pines
        if (PIN_TEC1 == 0){     // Al pulsar
            PIN_LED_R = 1;      //prende led
            tinicioRojo = tickRead();  //Toma tiempo de inicio
        } 
        if (PIN_TEC2 == 0){     // Al pulsar
            PIN_LED_AM = 1;     //prende led
            tinicioAmarillo = tickRead();//Toma tiempo de inicio
        } 
        if (PIN_TEC3 == 0){     // Al pulsar
            PIN_LED_V = 1;      //prende led
            tinicioVerde = tickRead();  //Toma tiempo de inicio
        }
        if (PIN_TEC4 == 0){     // Al pulsar
            PIN_LED_AZ = 1;      //prende led
            tinicioAzul = tickRead();  //Toma tiempo de inicio
        }
        
        //Testea los leds y el tiempo
        if (PIN_LED_R == 1 &&  tickRead()-tinicioRojo > 1000 ){ // Si esta prendido y paso 1 seg
            PIN_LED_R = 0;      //apaga led
        }
        if (PIN_LED_AM == 1 &&  tickRead()-tinicioAmarillo > 2000 ){ // Si esta prendido y paso 2 seg
            PIN_LED_AM = 0;     //apaga led
        }
        if (PIN_LED_V == 1 &&  tickRead()-tinicioVerde > 3000 ){ // Si esta prendido y paso 3 seg
            PIN_LED_V = 0;      //apaga led
        }
        if (PIN_LED_AZ == 1 &&  tickRead()-tinicioAzul > 4000 ){ // Si esta prendido y paso 4 seg
            PIN_LED_AZ = 0;     //apaga led
        }
        //Incrementa el display cada segundo
        if (tickRead()-tinicioDisp > 1000){
            tinicioDisp += 1000;      //Inicia la espera de otro segundo
            //Incrementa el display
            if(++numero > 9){
                numero = 0;
            }
            //Muestra el numero
            displayWrite(numero);
        }
    }
}

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
