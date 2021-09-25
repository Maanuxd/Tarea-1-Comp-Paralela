Tarea 1 Computacion Paralela y Distribuida: coloreado de imagen en escala de grises

Programa Realizado en C++ empleando la libreria openCV, que toma como argumento una imagen en escala de grises y la colorea.

Es necesaria la instalación de la libreria openCV para la ejecución de este programa
Video guia: https://www.youtube.com/watch?v=8dbpf8BpK8U&t=2s

Al ejecutar el programa por consola, se debe especificar como argumentos la ruta de la imagen a tratar (opencv tiene una funcion para leer la imagen en escala de grises) y la ruta donde se dese guardar la imagen tratada.

Para ejecutar el programa desde la consola:
    - Ir a la directorio donde se tiene almacenado el programa
    - Estando en el directorio, ingresar las siguientes instrucciones:
        - cmake .
        - make
        - ./output <ruta de la imagen> <ruta de guardado>

la imagen tratada estará en formato .png

Pendientes:
    - Uso de Open MP para la paralelización 
    - Coloreado adecuado de la imagen

Realizado por:
- Manuel Toledo Levican
- Byron Diaz Jara
- Branislav Vecka Muñoz
