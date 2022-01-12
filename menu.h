#ifndef H_MENU
#define H_MENU

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Menu
{
    int largo = 0, ancho = 0;
    int margen = 0;
    char titulo[100];
    int seleccion = -1;
    ListaCadenas *opciones = NULL;
    ListaCadenas *valores = NULL;
    ListaCadenas *controles = NULL;
};

Menu menu;

void modificar_dato(const char dato[], const char valor[])
{
    /**
     * 
    */

    char temp[2] = "";

    if (strcmp(dato, "largo") == 0) menu.largo = atoi(valor);
    if (strcmp(dato, "ancho") == 0) menu.ancho = atoi(valor);
    if (strcmp(dato, "margen") == 0) menu.margen = atoi(valor);
    if (strcmp(dato, "seleccion") == 0) menu.seleccion = atoi(valor);
    if (strcmp(dato, "titulo") == 0) strcpy(menu.titulo, valor);
    if (strcmp(dato, "control") == 0) insertar_cadena(menu.controles, valor);
    if (strcmp(dato, "opcion") == 0) insertar_cadena(menu.opciones, valor);
    if (strcmp(dato, "valor") == 0)
    {
        memcpy(temp, valor, 1);
        insertar_cadena(menu.valores, valor);
    }
}

void mostrar_menu()
{
    system("cls");

    int imprimir = 0, ultimo_imprimir = 0, pos_opcion = 0, pos = 0; // Define que parametro se va a imprimir
    int linea_control = 2;                                          // En que linea se imprimen los controles
    
    ListaCadenas *aux;
    char buffer[100] = "";

    // Valores por defecto ante entradas no validas o nulas
    if (menu.largo < 2) menu.largo = 20;
    if (menu.ancho < 2) menu.ancho = 70;
    if (menu.margen < 0) menu.margen = 0;

    // Borde superior
    printf("\xC9");
    for (int x = 0; x < menu.ancho-2; x++) printf("\xCD");
    printf("\xBB\n");

    // Laterales
    for (int x = 0; x < menu.largo-2; x++)
    {
        // Lateral izquierdo
        printf("\xBA"); 

        // Medio
        for (int y = 0; y < menu.ancho-2; y++)
        {
            // Titulo
            if (x == 0 && y >= (menu.ancho/2) && imprimir == 0)
            {
                for (int z = 0; z < ((strlen(menu.titulo)/2) + (strlen(menu.titulo)%2) + ((menu.ancho/2)%2)); z++) printf("\b");
                printf("%s", menu.titulo);

                y += ((strlen(menu.titulo)/2) - ((menu.ancho/2)%2));

                ultimo_imprimir = imprimir;
                imprimir++;
            }

            // Opciones
            if (x > 1 && (y >= menu.margen && y < menu.ancho-menu.margen))
            {
                if (obtener_cadena(menu.opciones, pos_opcion, buffer) == 0 && ultimo_imprimir != imprimir)
                {
                    char selec[4] = "";
                    if (menu.seleccion == pos_opcion) strcpy(selec, "\xAF");
                    else strcpy(selec, " ");

                    printf("%s %s", selec, buffer);

                    y += strlen(buffer) + 2;

                    pos_opcion++;
                    ultimo_imprimir = imprimir;
                    linea_control++;
                }
            }

            // Controles
            if (x >= linea_control && y >= menu.ancho-menu.margen-2)
            {
                if (obtener_cadena(menu.controles, pos, buffer) == 0 && ultimo_imprimir != imprimir)
                {
                    for (int borrar = 0; borrar < strlen(buffer); borrar++) printf("\b");

                    printf("%s", buffer);

                    pos++;
                    ultimo_imprimir = imprimir;
                }
            }

            // Espacios en blanco
            printf(" ");
        }
        
        if (imprimir > 0)
            imprimir++;

        // Lateral derecho
        printf("\xBA\n");
    }
    
    // Borde inferior
    printf("\xC8");
    for (int x = 0; x < menu.ancho-2; x++) printf("\xCD");
    printf("\xBC\n");

    // DEBUG
    printf("  imprimir=%d, ultimo_imprimir=%d, pos_opcion=%d, pos_control=%d\n\n", imprimir, ultimo_imprimir, pos_opcion, pos);
}

#endif