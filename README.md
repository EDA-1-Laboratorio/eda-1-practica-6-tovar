[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Y2axHSFd)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=23213488&assignment_repo_type=AssignmentRepo)
# Práctica 6. Colas
## Ejercicio 1. Definiciones incompletas
El primer ejercicio consiste de tres incisos:

a. Las primeras definiciones que hacen falta llenar se encuentran en el archivo "queue1.c". Para comprobar que el programa funciona correctamente, ingresa el siguiente input:

  `a 102`
  
  `b 203`
  
  `a 140`
  
  `b 111`
  
  `a 200`
  
  `b 333`
  
  `b 31`
  

Luego, presiona `Ctrl + D`.

**Pregunta**: De acuerdo con lo que imprime la consola, ¿qué está haciendo el bloque main?

b. Generar un nuevo archivo de encabezado "circular_queue.h" y, basados en el archivo "queue.h", definir las operaciones básicas de las colas circulares.

c. Generar un nuevo archivo de encabezado "double_linked_queue.h" y, basados en el archivo "queue.h", definir las operaciones básicas de las colas doblemente ligadas.


## Ejercicio 2. Sistema de comandas

a. Basándose en el bloque `main` del archivo "queue.c", generar un sistema de _comandas_ en un restaurante. El sistema debe de preguntarle al usuario cuál es la siguiente orden (pueden ingresar las órdenes en forma de texto libre, o guardar los platillos posibes en el encabezado del programa, por ejemplo con la función "enum" quien toma la orden solamente tendría que ingresar un número para indicar el platillo, tal y como ocurre en las cadenas de comida rápida). Deben de definir una operación de "recibir comanda" (enqueue), de "servir platillo" (dequeue) y de consultar cuáles fueron el platillo que sigue por servirse o último platillo que se anotó en la comanda. 

b. La segunda parte del ejercicio consiste en "mejorar" el sistema de comandas anterior. Resulta que después de varios meses de funcionar, los gerentes del restaurante se dieron cuenta que nunca hay más de 6 órdenes en espera de ser preparadas, ya que si una orden toma mucho tiempo en hacerse, para cuando llegara la séptima, el comensal de la primera orden ya se habría ido por la desesperación. Por lo tanto, les piden a ustedes que el sistema solamente acepte 6 órdenes a la vez. ¿Cómo harían la modificación?

## Ejercicio 3. Lista de reproducción
Pensando en usar una lista doblemente ligada, diseñen un programa que, de un catálogo de canciones disponibles, les permita generar una playlist, y agregar canciones al inicio o al final de la cola. Recuerden definir todas las operaciones básicas para este tipo de estructuras, de modo que las operaciones se puedan ver reflejadas en la manipulación de la playlist.
