#ifndef H_DATOS
#define H_DATOS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

int leer_usuarios(Usuario usuarios[MAX_USUARIOS], int &cantidad)
{
    /**
     * INT DE RETORNO
     *  0 - Lectura correcta (existen usuarios)
     *  1 - Lectura incorrecta (no existen usuarios)
     *  2 - Lectura incorrecta (no se pudo abrir el archivo)
     */
    int estado = -1;

    cantidad = 0;
    Usuario usuario;
    FILE *archivo = fopen(USUARIOS_DAT, "rb");

    if (archivo != NULL)
    {
        for (int x = 0; x < MAX_USUARIOS; x++)
        {
            if (fread(&usuario, sizeof(Usuario), 1, archivo) != 0)
            {
                usuarios[x] = usuario;
                cantidad++;
            }
        }

        if (cantidad != 0)
            estado = 0;
        else
            estado = 1;
    }
    else
        estado = 2;

    fclose(archivo);

    return estado; 
}

int escribir_usuario(Usuario usuario)
{
    /**
     * INT DE RETORNO
     *  0 - Escritura correcta (se escribio el usuario)
     *  1 - Escritura incorrecta (no se pudo escribir en el archivo)
     *  2 - Escritura incorrecta (no se pudo abrir el archivo)
     */

    int estado = -1;

    FILE *archivo = fopen(USUARIOS_DAT, "ab");

    if (archivo != NULL)
    {
        if (fwrite(&usuario, sizeof(Usuario), 1, archivo) != 0)
            estado = 0;
        else
            estado = 1;
    }
    else
        estado = 2;

    fclose(archivo);

    return estado;
}

int escribir_cliente(Cliente cliente)
{
    /**
     * 0 - Se escribio correctamente
     * 1 - No se pudo abrir el archivo
     */
    
    FILE *arch = fopen(CLIENTES_DAT,"ab");

    if (arch!=NULL)
    {   
        fwrite(&cliente, sizeof(Cliente), 1, arch);
        fclose(arch);
    }
    else
        return 1;

    return 0;
}

int leer_profesionales(Profesional profesionales[MAX_PROF], int &cantidad)
{
    /**
     * INT DE RETORNO
     *  0 - Lectura correcta (existen profesionales)
     *  1 - Lectura incorrecta (no existen profesionales)
     *  2 - Lectura incorrecta (no se pudo abrir el archivo)
     */
    int estado = -1;

    cantidad = 0;
    Profesional prof;
    FILE *archivo = fopen(PROFESIONALES_DAT, "rb");

    if (archivo != NULL)
    {
        for (int x = 0; x < MAX_PROF; x++)
        {
            if (fread(&prof, sizeof(Profesional), 1, archivo) != 0)
            {
                profesionales[x] = prof;
                cantidad++;
            }
        }

        if (cantidad != 0)
            estado = 0;
        else
            estado = 1;
    }
    else
        estado = 2;

    fclose(archivo);

    return estado;
}

int leer_informes(Informe informes[MAX_INFORMES], int &cantidad)
{
    /**
     * INT DE RETORNO
     *  0 - Lectura correcta (existen informes)
     *  1 - Lectura incorrecta (no existen informes)
     *  2 - Lectura incorrecta (no se pudo abrir el archivo)
     */
    int estado = -1;

    cantidad = 0;
    Informe informe;
    FILE *archivo = fopen(INFORMES_DAT, "rb");

    if (archivo != NULL)
    {
        for (int x = 0; x < MAX_INFORMES; x++)
        {
            if (fread(&informe, sizeof(Informe), 1, archivo) != 0)
            {
                informes[x] = informe;
                cantidad++;
            }
        }

        if (cantidad != 0)
            estado = 0;
        else
            estado = 1;
    }
    else
        estado = 2;

    fclose(archivo);

    return estado;
}

int leer_cliente(Cliente clientes[MAX_CLIENTES], int &cantidad)
{
    /**
     * INT DE RETORNO
     *  0 - Lectura correcta (existen clientes)
     *  1 - Lectura incorrecta (no existen clientes)
     *  2 - Lectura incorrecta (no se pudo abrir el archivo)
     */
    int estado = -1;

    cantidad = 0;
    Cliente cliente;
    FILE *archivo = fopen(CLIENTES_DAT, "rb");

    if (archivo != NULL)
    {
        for (int x = 0; x < MAX_CLIENTES; x++)
        {
            if (fread(&cliente, sizeof(Cliente), 1, archivo) != 0)
            {
                clientes[x] = cliente;
                cantidad++;
            }
            else
            	break;
        }

        if (cantidad != 0)
            estado = 0;
        else
            estado = 1;
    }
    else
        estado = 2;

    fclose(archivo);

    return estado;
}

#endif
