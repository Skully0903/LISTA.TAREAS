#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char titulo[50];
    int completada; // 0 para pendiente, 1 para completada
}Tarea;

Tarea tareas[100]; //arreglo dentro de la estructura
int numTareas = 0; //inicializando la variable

// Función para mostrar el menú de opciones
void mostrarMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Agregar una nueva tarea.\n");
    printf("2. Marcar una tarea como completada.\n");
    printf("3. Listar todas las tareas pendientes.\n");
    printf("4. Listar todas las tareas.\n");
    printf("5. Buscar una tarea.\n");
    printf("6. Salir del programa.\n");
}

// Función para agregar una nueva tarea
void agregarTarea() {
    if (numTareas < 100) {
        printf("Ingrese el titulo de la nueva tarea: ");
        scanf(" %[^\n]s", tareas[numTareas].titulo); //se pone "^n" para que el scanf lea los espacios o mas bien los ignore y siga leyendo despues de un salto por que normalmente al momento de un salto deja de scanear
        tareas[numTareas].completada = 0; // Por defecto, la tarea se marca como pendiente
        numTareas++;
        printf("Tarea agregada correctamente.\n");
    } else {
        printf("No es posible agregar mas tareas, se alcanzo el limite maximo.\n");
    }
}

// Función para marcar una tarea como completada
void marcarCompletada() {
    int indice;
    printf("Ingrese el número de tarea que desea marcar como completada: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < numTareas) { //primero evalua si el numero existe dentro del arreglo y  despues si es menor que el numero de tareas que ya existe
        tareas[indice].completada = 1; //ya que el indice coincide se le cambia su valor a 1.
        printf("Tarea marcada como completada.\n");
    } else {
        printf("indice de tarea invalido.\n");
    }
}

// Procedimiento para mostrar todas las tareas pendientes
void listarTareasPendientes() {
    printf("--- Tareas Pendientes ---\n");
    for (int i = 0; i < numTareas; i++) { //loop para que recorra toda la structura
        if (tareas[i].completada == 0) { //aqui verifica si la tarea encontrada sea igual a 0 (incompleta)
            printf("%d. %s\n", i, tareas[i].titulo);
        }
    }
}

// Procedimiento para mostrar todas las tareas
void listarTareas() {
    printf("--- Todas las Tareas ---\n");
    for (int i = 0; i < numTareas; i++) {
        printf("%d. %s - %s\n", i, tareas[i].titulo, tareas[i].completada ? "Completada" : "Pendiente");//aqui el "?" sirve como un if haciendo saber si el arreglo es igual a 0 dara pendiente y si es diferente a 0 dara completada(la funcion de los : es como un else)
    }
}

// Procedimiento para buscar una tarea (inicia la búsqueda recursiva)
void buscarTarea() {
    char tituloBuscado[50];
    printf("Ingrese el titulo de la tarea que desea buscar: ");
    scanf(" %[^\n]s", tituloBuscado);

    buscarTareaRecursivo(tituloBuscado, 0); //se llama a la funcion donde se hace toda la busqueda
}

// Función recursiva para buscar una tarea por título
void buscarTareaRecursivo(char tituloBuscado[], int indice) {
    if (indice == numTareas) {
        printf("La tarea no existe en la lista.\n");
        return;
    }

    if (strcmp(tituloBuscado, tareas[indice].titulo) == 0) { //usando la libreria de string hacemos que compare el texto que ingresamos con el texto del indice numero 0 (inicialmente) despues si no la encuentra se le agrega uno al indice y se hace la recursividad para que se repita
        printf("Tarea encontrada - Estado: %s\n", tareas[indice].completada ? "Completada" : "Pendiente");//aqui el "?" sirve como un if haciendo saber si el arreglo es igual a 0 dara pendiente y si es diferente a 0 dara completada(la funcion de los : es como un else)
        return;
    }

    buscarTareaRecursivo(tituloBuscado, indice + 1);
}



#endif // FUNCIONES_H_INCLUDED
