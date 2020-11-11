/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene las definiciones de uart
 * 
 * Aquí se encuentra la implementación de uart, los defines, macros, 
 * datos internos y externos, declaraciones y definiciones de funciones
 * internas y definiciones de funciones externas.
 */

/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

#include "system.h"     /* Funciones/Parametros System, como conf de osc/perif */
#include "uart.h"       /* Funciones/Parametros Uart */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/
/**
 * @brief	Configura e inicializa la UART
 * @return	Nada
 * @note    Las opciones se modifican en el código, por ejemplo con la 
 * constante UART_BAUDRATE
 * @sa      UART_BAUDRATE    
 */
void uartInit(void) {
#if((SYS_FREQ - UART_BAUDRATE*16L)/(UART_BAUDRATE*16L)) > 255 //Si necesita High Baud Rate
#if	(SYS_FREQ - UART_BAUDRATE*64L)/(UART_BAUDRATE*64L) > 255
#error Baud Rate demasiado Bajo
#endif
    SPBRG = (SYS_FREQ - UART_BAUDRATE * 64L) / (UART_BAUDRATE * 64L); //SPBRG para Low Baud Rate
    BRGH = 0;   //Selecciona Low Baud Rate
#else
    SPBRG = (SYS_FREQ - UART_BAUDRATE * 16L) / (UART_BAUDRATE * 16L); //SPBRG para High Baud Rate
    BRGH = 1;   //Selecciona High Baud Rate
#endif
    SYNC = 0;   //Selecciona Modo Asincronico
    SPEN = 1;   //Habilita Puerto Serie
    TRISC7 = 1;
    TRISC6 = 1;
    CREN = 1;   //Habilita Recepción continua
    TXEN = 1;   //Habilita Transmisión
}

/**
 * @brief	Envía un byte a la salida stdout en forma bloqueante pero por poco tiempo
 * @param	data Byte o dato a transmitir
 * @return	Nada
 * @note    Define la salida estandar para la librería stdio
 */
void putch(char data) {
    while (!TXIF)   //Espera que haya espacio en la FIFO (bloquea poco tiempo)
        continue;
    TXREG = data;   //Envía el byte
}

/**
 * @brief       Envía un byte en forma bloqueante pero por poco tiempo
 * @param[in]   value Valor a transmitir 
 * @return      Nada
 */
void uartWriteByte( uint8_t value ){
    while (!TXIF)   //Espera que haya espacio en la FIFO (bloquea poco tiempo)
        continue;
    TXREG = value;  //Envía el byte
}

/**
 * @brief	Toma un byte de la entrada stdin en forma bloqueante
 * @return	El byte recibido
 * @note    Define la entrada estandar para la librería stdio
 */
char getch(void) {
    while (!RCIF)   //Espera hasta que haya un byte recibido (bloqueante)
        continue;
    return RCREG;   //retorna lo recibido
}

/**
 * @brief       Toma un byte de la FIFO de recepción en forma no bloqueante, chequea primero si hay un dato disponible
 * @param[out]  receivedByte Apunta al destino para el byte recibido
 * @return      1 si hay un byte recibido, 0 si no hay dato disponible 
 */
__bit uartReadByte( uint8_t* receivedByte ){
   if ( RCIF ){     //Si hay por lo menos un byte recibido
      *receivedByte = RCREG;    //lo coloca en el lugar de destino
      return 1;     //Retorna 1 para indicar que ha recibido
   }
   return 0;        //Retorna 0 para indicar que no ha recibido
}

/**
 * @brief	Toma un byte de la entrada stdin con eco y en forma bloqueante
 * @return  El byte recibido
 * @note
 */
char getche(void) {
    char data;
    while (!RCIF)   //Espera hasta que haya un byte recibido (bloqueante)
        continue;
    data = RCREG;   //almacena lo recibido
    while (!TXIF)   //Espera que haya espacio en la FIFO (bloqueante poco tiempo)
        continue;
    TXREG = data;   //Envía el byte
    return data;    //retorna lo recibido
}

/*==================[fin del archivo]========================================*/
