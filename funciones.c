#include <stdio.h>
#include <string.h>
#include "funciones.h"

void cargarPeliculas(char peliculas[][4][40]) {
    FILE *file = fopen("peliculas.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo de peliculas.\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        fscanf(file, "%s %s %s %s", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }
    fclose(file);
}

void guardarPeliculas(char peliculas[][4][40]) {
    FILE *file = fopen("peliculas.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo de peliculas.\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        fprintf(file, "%s %s %s %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }
    fclose(file);
}

void cargarClientes(char clientes[][2][40]) {
    FILE *file = fopen("clientes.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo de clientes.\n");
        return;
    }
    for (int i = 0; i < 20; i++) {
        fscanf(file, "%s %s", clientes[i][0], clientes[i][1]);
    }
    fclose(file);
}

void guardarClientes(char clientes[][2][40]) {
    FILE *file = fopen("clientes.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo de clientes.\n");
        return;
    }
    for (int i = 0; i < 20; i++) {
        fprintf(file, "%s %s\n", clientes[i][0], clientes[i][1]);
    }
    fclose(file);
}

void cargarReservas(int reserva[][4]) {
    FILE *file = fopen("reservas.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo de reservas.\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        fscanf(file, "%d %d %d %d", &reserva[i][0], &reserva[i][1], &reserva[i][2], &reserva[i][3]);
    }
    fclose(file);
}

void guardarReservas(int reserva[][4]) {
    FILE *file = fopen("reservas.txt", "w");
    if (file == NULL) {
        printf("Error al abrir el archivo de reservas.\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        fprintf(file, "%d %d %d %d\n", reserva[i][0], reserva[i][1], reserva[i][2], reserva[i][3]);
    }
    fclose(file);
}

void ingresarCliente(char clientes[][2][40]) {
    for (int i = 0; i < 20; i++) {
        if (strcmp(clientes[i][0], "vacío") == 0) {
            printf("Ingrese nombre del nuevo cliente: ");
            scanf("%s", clientes[i][0]);
            printf("Ingrese cédula del nuevo cliente: ");
            scanf("%s", clientes[i][1]);
            break;
        }
    }
    imprimirClientes(clientes);
}

void imprimirClientes(char clientes[][2][40]) {
    for (int i = 0; i < 20; i++) {
        printf("%s\t\t%s\n", clientes[i][0], clientes[i][1]);
    }
}

void listarPeliculas(char peliculas[][4][40]) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][0], "vacío") != 0) {
            printf("ID: %s, Titulo: %s, Hora: %s, Genero: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
        }
    }
}

void buscarporNombre(char peliculas[][4][40]) {
    char nombre[40];
    printf("Ingrese el nombre de la pelicula: ");
    scanf("%s", nombre);
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][1], nombre) == 0) {
            printf("Pelicula encontrada: ID: %s, Titulo: %s, Hora: %s, Genero: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
            return;
        }
    }
    printf("Pelicula no encontrada.\n");
}

void buscarporGenero(char peliculas[][4][40]) {
    char genero[40];
    printf("Ingrese el genero de la pelicula: ");
    scanf("%s", genero);
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][3], genero) == 0) {
            printf("Pelicula encontrada: ID: %s, Titulo: %s, Hora: %s, Genero: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
            return;
        }
    }
    printf("Pelicula no encontrada.\n");
}

void comprarTicket(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    int idPelicula, tipoTicket, clienteIndex;

    listarPeliculas(peliculas);
    printf("Ingrese el ID de la pelicula: ");
    scanf("%d", &idPelicula);

    if (idPelicula < 1 || idPelicula > 10 || strcmp(peliculas[idPelicula - 1][0], "vacío") == 0) {
        printf("ID de pelicula no valido.\n");
        return;
    }

    printf("Tipos de ticket:\n1. General\n2. Niños menores de 5\n3. Mayor de 60\n");
    printf("Ingrese el tipo de ticket: ");
    scanf("%d", &tipoTicket);

    printf("Clientes registrados:\n");
    imprimirClientes(clientes);
    printf("Ingrese el índice del cliente: ");
    scanf("%d", &clienteIndex);

    if (clienteIndex < 0 || clienteIndex >= 20 || strcmp(clientes[clienteIndex][0], "vacío") == 0) {
        printf("Índice de cliente no válido.\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (reserva[i][0] == -1) {
            reserva[i][0] = clienteIndex;
            reserva[i][1] = idPelicula - 1;
            reserva[i][2] = tipoTicket - 1;
            reserva[i][3] = precio[tipoTicket - 1];
            break;
        }
    }

    printf("Compra realizada con éxito.\n");
}

void verCompras(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    printf("Listado de compras:\n");
    for (int i = 0; i < 10; i++) {
        if (reserva[i][0] != -1) {
            int clienteIndex = reserva[i][0];
            int peliculaIndex = reserva[i][1];
            int tipoTicket = reserva[i][2];
            printf("Cliente: %s, Pelicula: %s, Hora: %s, Genero: %s, Tipo de ticket: %s, Precio: $%.2f\n",
                   clientes[clienteIndex][0],
                   peliculas[peliculaIndex][1],
                   peliculas[peliculaIndex][2],
                   peliculas[peliculaIndex][3],
                   tipoTicket == 0 ? "General" : tipoTicket == 1 ? "Niños menores de 5" : "Mayor de 60",
                   precio[tipoTicket]);
        }
    }
}

