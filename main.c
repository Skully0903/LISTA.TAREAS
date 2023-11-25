#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función principal
int main() {
    int opcion;

    do {
        mostrarMenu();
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarTarea();
                break;
            case 2:
                marcarCompletada();
                break;
            case 3:
                listarTareasPendientes();
                break;
            case 4:
                listarTareas();
                break;
            case 5:
                buscarTarea();
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}


