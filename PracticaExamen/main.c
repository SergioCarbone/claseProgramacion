#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "carga_edicion.h"
#include "validaciones.h"
#define USUARIOS 5

int main()
{
    EPersona listaUsuarios[USUARIOS];
    EComentario listaComentarios[USUARIOS];
    /* //---------------------------------------------------------------------
     strcpy(listaUsuarios[0].claveAcceso, "A1");
     strcpy(listaUsuarios[1].claveAcceso, "A2");
     strcpy(listaUsuarios[2].claveAcceso, "A3");

     strcpy(listaUsuarios[0].nombre, "Sergio");
     strcpy(listaUsuarios[1].nombre, "Pablo");
     strcpy(listaUsuarios[2].nombre, "Pablo");

     strcpy(listaUsuarios[0].nick, "zz");
     strcpy(listaUsuarios[1].nick, "gg");
     strcpy(listaUsuarios[2].nick, "aa");

     strcpy(listaUsuarios[0].email, "hola@hola");
     strcpy(listaUsuarios[0].email, "hola@hola");
     strcpy(listaUsuarios[0].email, "hola@hola");

     listaUsuarios[0].id = 10;
     listaUsuarios[1].id = 10;
     listaUsuarios[2].id = 10;

     listaUsuarios[0].isEmpty = 0;
     listaUsuarios[1].isEmpty = 0;
     listaUsuarios[2].isEmpty = 0;


     //-----------------------------------------------------------------------------------------------
    */
    char seguir='s';
    char opcion= '0';
    int lugarLibre, resultadoBusqueda, i,idUsuario = 0,contComentario = 0;
    char nombreAux[50],emailAux[50], nickAux[50],claveAccesoAux[50],mensajeAux[150];


    iniciarEstado(listaUsuarios,USUARIOS,1);
    iniciarComentario(listaComentarios,USUARIOS,1);
    iniciarMeGusta(listaComentarios,USUARIOS,0);


    do
    {

        printf("\n\n1- Cargar un usuario\n");
        printf("2- Modificar datos de un usuario\n");
        printf("3- Borrar un usuario\n");
        printf("4- Agregar un comentario\n");
        printf("5- Nuevo me gusta\n");
        printf("6- Informar\n");
        printf("7- Listar\n");
        printf("8- Salir\n\n");

        fflush(stdin);

        opcion = getChar("Ingrese una opcion: ");
        if(opcion <'1' || opcion >'8')
        {
            printf("Ingrese una opcion del menu!!\n\n");
        }

        switch(opcion)
        {
        case '1':

            lugarLibre = buscarPosicion(listaUsuarios,USUARIOS,1);
            if(lugarLibre==-1)
            {
                printf("error");
                break;
            }
            idUsuario ++;
            if(!getStringLetras("\nIngrese el Nombre: ",nombreAux))
            {
                printf("Solo puede ingresar letras!\n");
                break;
            }
            if(!getStringClave("Ingrese la clave: ",claveAccesoAux))
            {
                printf("Solo puede ingresar 8 digitos!\n\n");
                break;
            }
            resultadoBusqueda = buscarPorClave(listaUsuarios, claveAccesoAux,USUARIOS);
            if(resultadoBusqueda != -1)
            {
                printf("La clave ya existe ya existe!!\n\n");
                break;
            }

            if(!getStringNick("Ingrese su nick: ", nickAux))
            {
                printf("Solo puede ingresar 8 digitos!\n\n");
                break;
            }
            resultadoBusqueda = buscarPorNick(listaUsuarios,nickAux,USUARIOS);
            if(resultadoBusqueda ==1)
            {
                printf("El nick ya existe!!");
                break;
            }

            if(!getStringMail("ingrese su mail: ", emailAux))
            {
                printf("Error, solo se permite un @!");
                break;
            }
            resultadoBusqueda = buscarPorEmail(listaUsuarios, emailAux,USUARIOS);
            if(resultadoBusqueda != -1)
            {
                printf("El email ya existe!!\n\n");
                break;
            }

            listaUsuarios[lugarLibre].isEmpty = 0;

            strcpy(listaUsuarios[lugarLibre].nombre,nombreAux);
            strcpy(listaUsuarios[lugarLibre].nick,nickAux);
            strcpy(listaUsuarios[lugarLibre].email,emailAux);
            strcpy(listaUsuarios[lugarLibre].claveAcceso,claveAccesoAux);
            listaUsuarios[lugarLibre].id = idUsuario;


            break;

        case '2':
            if(!getStringNick("Ingrese su nick: ", nickAux))
            {
                printf("Solo puede ingresar 8 digitos!\n\n");
                break;
            }
            resultadoBusqueda = buscarPorNick(listaUsuarios,nickAux,USUARIOS);
            if(resultadoBusqueda == -1)
            {
                printf("El nick no existe!!");
                break;
            }
            if(!getStringLetras("\nIngrese el Nombre: ",nombreAux))
            {
                printf("Solo puede ingresar letras!\n");
                break;
            }
            if(!getStringClave("Ingrese la clave: ",claveAccesoAux))
            {
                printf("Solo puede ingresar 8 digitos!\n\n");
                break;
            }
            resultadoBusqueda = buscarPorClave(listaUsuarios, claveAccesoAux,USUARIOS);
            if(resultadoBusqueda != -1)
            {
                printf("La clave ya existe ya existe!!\n\n");
                break;
            }
            if(!getStringMail("ingrese su mail: ", emailAux))
            {
                printf("Error, solo se permite un @!");
                break;
            }
            resultadoBusqueda = buscarPorEmail(listaUsuarios, emailAux,USUARIOS);
            if(resultadoBusqueda != -1)
            {
                printf("La clave ya existe ya existe!!\n\n");
                break;
            }

            strcpy(listaUsuarios[lugarLibre].nombre,nombreAux);
            strcpy(listaUsuarios[lugarLibre].email,emailAux);
            strcpy(listaUsuarios[lugarLibre].claveAcceso,claveAccesoAux);
            break;

        case '3':
            if(!getStringNick("Ingrese su nick: ", nickAux))
            {
                printf("Solo puede ingresar 8 digitos!\n\n");
                break;
            }
            resultadoBusqueda = buscarPorNick(listaUsuarios,nickAux,USUARIOS);
            if(resultadoBusqueda == -1)
            {
                printf("El nick no existe!!");
                break;
            }
            listaUsuarios[resultadoBusqueda].isEmpty = 1;
            break;
        case '4':
           if(!getStringNick("Ingrese su nick: ", nickAux))
            {
                printf("Solo puede ingresar 8 digitos!\n\n");
                break;
            }
            resultadoBusqueda = buscarPorNick(listaUsuarios,nickAux,USUARIOS);
            if(resultadoBusqueda ==-1)
            {
                printf("El nick no existe!!");
                break;
            }
            lugarLibre = buscarPosicionDeComentario(listaComentarios,USUARIOS,1);
            if(lugarLibre==-1)
            {
                printf("No hay lugar libre");
                break;
            }
            if(!getStringMensaje("Ingrese el mensaje: ", mensajeAux))
            {
                printf("Solo puede ingresar 150 caracteres!\n\n");
                break;
            }
                contComentario ++;
                strcpy(listaComentarios[lugarLibre].mensaje,mensajeAux);
                listaComentarios[lugarLibre].id=contComentario;
                listaComentarios[lugarLibre].idUsuario=listaUsuarios[resultadoBusqueda].id;

            break;
        case '5':

            break;

        case '6':
            break;
        case '7':
            for (i=0; i<USUARIOS; i++)
            {
                if(listaUsuarios[i].isEmpty == 0)
                {
                    printf("%s\t%s\t%s\t%s\t\n\n%s", listaUsuarios[i].nombre,listaUsuarios[i].nick,listaUsuarios[i].email,listaUsuarios[i].claveAcceso,listaComentarios[i].mensaje);
                }
            }
            break;
        case '8':
            seguir = 'n';
            break;
        }
    }
    while(seguir=='s');
    return 0;
}
