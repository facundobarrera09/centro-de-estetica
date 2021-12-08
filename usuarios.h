#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "menu_login.h"

int buscar_usuario(Usuario usuario, Usuario usuarios[MAX_USUARIOS], int cantidad);

// FUNCION PRINCIPAL

int inicio_de_sesion(Usuario &usuario, int tipo, Usuario usuarios[MAX_USUARIOS], int cantidad)
{
    /**
     * INT DE RETORNO:
     * 
     * 0 - Se inicio sesion correctamente y se devolvió usuario
     * 1 - No existe el usuario
     * 2 - El usuario ingresado no coincide con el tipo
     * 3 - Usuarios esta vacio
     * 
     */

    Usuario usuario_ingresado;
    int seleccion = 2;
    int estado_de_usuario;

    bool ejecutar = true;
    char entrada[36];
    
    usuario_ingresado.tipo = tipo;
    
    reestablecer_menu();
    actualizar_menu(0, MENU1);
    actualizar_menu(1, "Inicio de sesion");

    // Pedir ingreso de datos
    while (ejecutar)
    {
        system("cls");
    
        mostrar_menu(seleccion);
        scanf("%s", entrada);

        if (strcmp(entrada, "NX") == 0)
        {
            if (seleccion == 2) seleccion = 3;
            else seleccion = 2;
        }
        else if (strcmp(entrada, "OK") == 0)
        {
            strcpy(usuario_ingresado.usuario, menu.usuario);
            strcpy(usuario_ingresado.contrasena, menu.contrasena);
            ejecutar = false;
        }
        else
        {
            actualizar_menu(seleccion, entrada);
        }

        system("cls");
    }

    // Verificar que los datos sean correctos
    if (strcmp(usuario_ingresado.usuario, "") == 0 || strcmp(usuario_ingresado.contrasena, "") == 0)
        return 1;

    // Verificar que el usuario exista

    estado_de_usuario = buscar_usuario(usuario_ingresado, usuarios, cantidad);
    
    if (estado_de_usuario == 0)
    {
        usuario = usuario_ingresado;
        return 0;
    }
    else
        return estado_de_usuario;
}

int crear_usuario(Usuario usuarios[MAX_USUARIOS], int &cantidad)
{
    /**
     * INT DE RETORNO
     * 
     * 0 - Usuario creado y almacenado con exito
     * 1 - Se ingresaron datos invalidos
     * 
     */

    Usuario usuario_ingresado;
    int seleccion = 2;

    bool ejecutar = true;
    char entrada[36];

    reestablecer_menu();
    actualizar_menu(0, MENU2);
    actualizar_menu(1, "Creacion de usuario");

    // Pedir ingreso de datos
    while (ejecutar)
    {
        system("cls");
    
        mostrar_menu(seleccion);
        scanf("%s", entrada);

        if (strcmp(entrada, "NX") == 0)
        {
            if (seleccion < 4) seleccion++;
            else seleccion = 2;
        }
        else if (strcmp(entrada, "OK") == 0)
        {
            strcpy(usuario_ingresado.usuario, menu.usuario);
            strcpy(usuario_ingresado.contrasena, menu.contrasena);

            if (strcmp(menu.tipo, "ADMIN") == 0)
                usuario_ingresado.tipo = 1;
            else if (strcmp(menu.tipo, "PROF") == 0)
                usuario_ingresado.tipo = 2;
            else if (strcmp(menu.tipo, "ASIST") == 0)
                usuario_ingresado.tipo = 3;
            else
                usuario_ingresado.tipo = 0;
            
            ejecutar = false;
        }
        else
        {
            actualizar_menu(seleccion, entrada);
        }

        system("cls");
    }

    // Verificar que los datos sean correctos
    if (strcmp(usuario_ingresado.usuario, "") == 0 || strcmp(usuario_ingresado.contrasena, "") == 0 || usuario_ingresado.tipo == 0)
        return 1;

        // Verificacion de nombre de usuario
    if (strlen(usuario_ingresado.usuario) < 6 || strlen(usuario_ingresado.usuario) > 10);
        
}

// FUNCIONES SECUNDARIAS

int buscar_usuario(Usuario usuario, Usuario usuarios[MAX_USUARIOS], int cantidad)
{
    /**
     * INT DE RETORNO:
     * 
     * 0 - Se encontro el usuario
     * 1 - No se encontro el usuario
     * 2 - Se encontro el usuario pero coincide el tipo
     * 3 - Usuarios está vacio
     * 
     */

    if (cantidad == 0)
        return 3;

    for (int x = 0; x < cantidad; x++)
    {
        if (strcmp(usuario.usuario, usuarios[x].usuario) == 0 && strcmp(usuario.contrasena, usuarios[x].contrasena) == 0)
        {
            if (usuario.tipo == usuarios[x].tipo)
                return 0;
            else
                return 2;
        }
    }
}