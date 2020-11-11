# Template en C para PIC16F887
Template de proyecto básico para el comílador XC8 v2.10 con MPLABX IDE v5.30.
## Módulos disponibles
Nombre|Descripción
------|-----------
uart|Permite el manejo del puerto serie
display|Permite el manejo de un display de 7 segmentos
tick|Permite utilizar el contador de Tick para temporizaciones

## Instrucciones
 Agregar/modificar el código según sea necesario.
 
# Enunciado del TPSE06: Demoras por Contador de Tick
Codifica un programa que:
## 1. Módulo para Conversor AD
- [ ] Defina las etiquetas y constantes necesarias, inicialice entradas, salidas y los periféricos necesarios
- [ ] Codifica un programa principal muy simple que en su super lazo y en forma no bloqueante cada 600mS cuente del 1 a 4 en el display 7 segmentos volviendo a repetir indefinidamente.
- [ ] También cada vez que cambia el display, destelle  el led rojo (prenda y lego de 200mS vuelva a apagar)
- [ ] En forma independiente a lo anterior toglee el led verde 1 vez por segundo indicando que la aplicación esta en marcha
- [ ] al terminar esta parte identifícalo con commit: `punto1 listo`
## 2. Medición de Intervalo con contador de Tick
- [ ] Modifica el programa principal para que también mida el tiempo que transcurre entre que se presiona la tecla 1 y que se presiona la tecla 2, y guarde el resultado obtenido en la variable `tGolpe`. Recuerda al comienzo, inicializar esta variable en 600
- [ ] Si este tiempo que se esta midiendo luego de presionar la tecla 1, ya supera los 5 segundos descarta la medición
- [ ] Modifica para que el tiempo entre cuentas del display y destellos del led rojo, ahora sea igual al almacenado en la variable `tGolpe`
- [ ] También mida el tiempo que transcurre entre que se presiona la tecla 3 y que se presiona la tecla 4, y guarde el resultado obtenido en la variable `tToggle`, recuerda iniciarla en 1000
- [ ] Si este tiempo que se esta midiendo luego de presionar la tecla 3, ya supera los 5 segundos también descarta la medición
- [ ] Modifica para que toglee el led verde luego de transcurrido el tiempo almacenado en la variable `tToggle`


