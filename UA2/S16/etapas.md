Ejercicio 4 · Etapas de gcc 
1. Con letrero.c, genere los archivos de cada etapa: gcc -E, gcc -S, gcc -c y el enlace.

2. ¿Qué archivo contiene el texto de stdio.h? ¿Cómo lo comprobó?
stdio contiene la libreria de C, lo comprobé abriendolo en VS CODE

3. ¿Qué archivo tiene instrucciones como mov y call?
El letrero.s

4. ¿Cuál no se puede leer como texto? ¿Por qué?
No se pueden leer letrero.o y letrero(ejecutable, en windows seria el .exe) porque estan en binario

5. ¿Qué etapa une su programa con el código de printf?
La del enlazador: el enlazador toma el archivo en binario y lo conecta
con la biblioteca C donde estan las instrucciones reale, una vez que hace esa 
unión, genera el archivo ejecutable final, listo para ser corrido. Si el Print esta mal escrito muestra un error de referencia no definida.