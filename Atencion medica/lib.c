#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "validaciones.h"
#include "cargaYEdicion.h"
#include "edicionArrays.h"
#include "busqueda.h"
/**
 * \brief Carga y valida datos ingresados por usuario
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param Id pasado por parametro
 */
int alta (EPersona listaPersonas[],int cantidad,int id)
{
    int retorno=0;
    int indiceVacio;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[10];
    char auxEdad[4];

    indiceVacio=obtenerEspacioLibre(listaPersonas,cantidad,1);
    if(indiceVacio!=-1)
    {
        retorno = ingresarSoloLetras(auxNombre,"\nIngrse su nombre: ","\nCaracteres invalidos para un nombre.\n");
        if(retorno)
        {
            retorno = ingresarSoloLetras(auxApellido,"\nIngrse su apellido: ","\nCaracteres invalidos para un apellido.\n");
        }
        if(retorno)
        {
            retorno = cargarDNI(listaPersonas,cantidad,auxDni,"\nIngrse su dni: ","\nCaracteres invalidos para un DNI.\n");
        }
        if(retorno)
        {
            retorno = cargarEdad(auxEdad,"\nIngrse su edad: ","\nCaracteres invalidos para una edad.\n");
        }
    }
    if(retorno==1)
    {
        strcpy(listaPersonas[indiceVacio].nombre,auxNombre);
        strcpy(listaPersonas[indiceVacio].apellido,auxApellido);
        strcpy(listaPersonas[indiceVacio].dni,auxDni);
        strcpy(listaPersonas[indiceVacio].edad,auxEdad);
        listaPersonas[indiceVacio].id=id;
        listaPersonas[indiceVacio].isEmpty=0;

    }
    return retorno;
}
/**
 * \brief Busca por indice y realiza baja lógica
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param mensaje para el usuario
 */
void baja (EPersona listaPersonas[],int cantidad,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[])
{
    int indiceId;
    char continuar;
    int cargaExitosa;
    char id[4];
    do
    {
        if(cargarNumero(id,mensaje,mensajeError,0,999))
        {
            indiceId = buscarPorIdUsuario(listaPersonas,cantidad,atoi(id));
            if(indiceId!=-1)
            {
                listaPersonas[indiceId].isEmpty=1;
                cargaExitosa =1;
            }
            else
            {
                printf("%s",mensajeNoEncontrado);
                continuar=getChar("\nDesea continuar? s/n");
            }
        }
    }
    while(cargaExitosa==0 && continuar=='s');
}
/**
 * \brief Busca por indice y realiza carga de datos a modificar
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param mensaje para el usuario
 */
void modificar (EPersona listaPersonas[],int cantidad,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[])
{
    int indiceId;
    int cargaExitosa;
    char auxNombre[50];
    char auxApellido[50];
    char opcion;
    if((indiceId =obtenerIndicePorId(listaPersonas,cantidad,mensaje,mensajeError,mensajeNoEncontrado))!=-1)
    {
        opcion=getChar("Ingrese la opcion a modificar, \n\n 1-Nomrbre.\n 2-Apellido.\n");
        switch(opcion)
        {
        case '1':
            cargaExitosa = ingresarSoloLetras(auxNombre,"\nNombre: ","\nCaracteres invalidos para un nombre.\n");
            if(cargaExitosa==1)
            {
                strcpy(listaPersonas[indiceId].nombre,auxNombre);
            }
            break;
        case '2':
            cargaExitosa = ingresarSoloLetras(auxApellido,"\nApellido: ","\nCaracteres invalidos para un apellido.\n");
            if(cargaExitosa==1)
            {
                strcpy(listaPersonas[indiceId].apellido,auxApellido);
            }
            break;
        default :
            printf("Error. Opcion incorrecta.");
            break;
        }
    }


}
/**
 * \brief Busca por indice activo en dos estructuras y crea una entrada para llamadas
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param array de datos a comparar
 * \param cantidad de posiciones que tiene el array.
 * \param dato pasado como parametro
 */
void nuevaLlamada (EPersona listaPersonas[],int cantidad, ELlamadas listaLlamadas[], int cantidadLlamas,int id)
{
    int indiceId;
    int indiceVacio;
    indiceVacio=obtenerEspacioLibreLlamadas(listaLlamadas,cantidadLlamas,1);
    if(indiceVacio!=-1)
    {
        indiceId = obtenerIndicePorId(listaPersonas,cantidad,"Ingrese ID de afiliado","ID invalido","ID no encontrado");
    }
    if(indiceId!=-1)
    {
        if((motivoLlamada(listaLlamadas,indiceVacio)))
            listaLlamadas[indiceVacio].idUsuario=listaPersonas[indiceId].id;
        listaLlamadas[indiceVacio].id=id;
        strcpy(listaLlamadas[indiceVacio].estado,"Pendiente");
        listaLlamadas[indiceVacio].isEmpty=0;
    }
}

void asignarAmbulancia (EPersona listaAfiliados[],int cantidadPersonas, ELlamadas listaLlamadas[],int cantiadLlamadas,int idAmbulancia)
{
    if(idAmbulancia<10)
    {
        int indiceLlamada;
        char auxiliarDuracion[10];
        indiceLlamada=obtenerIndiceLlamadaPorId(listaLlamadas,cantiadLlamadas,"Ingrese ID","ID incorrecto","ID no encontrado");
        if(indiceLlamada!=-1)
        {
            if(cargarNumero(auxiliarDuracion,"Ingrese duracion de llamada en minutos: ","Error",0,120))
            {
                listaLlamadas[indiceLlamada].idAmbulancia=idAmbulancia;
                listaLlamadas[indiceLlamada].duracion=(atoi(auxiliarDuracion));
            }
        }
    }
    else
    {
        printf("No hay ambulancias disponibles.");
    }
}
/**
 * \brief Imprime por pantalla los afiliados con más llamadas realizadas
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param array de datos a comparar
 * \param cantidad de posiciones que tiene el array.
 * \param array con indices que posean mayor cantidad de llamadas realizadas
 */
void informarAfiliadosMasLlamadas(ELlamadas listaLlamadas[],int cantLlamadas,EPersona listaPersonas[],int cantidad,int afiliadosConMasLlamadas[])
{
    int i;
    if(usuarioConMayorCantidadDeLlamadas(listaLlamadas,cantLlamadas,listaPersonas,cantidad,afiliadosConMasLlamadas))
    {

        printf("Afiliados con mayor cantidad e llamadas: \n\n");
        for(i=0; i<cantidad && afiliadosConMasLlamadas[i]!=-1; i++)
        {
            printf("-%s ",listaPersonas[(afiliadosConMasLlamadas[i])].nombre);
            printf("%s\n",listaPersonas[(afiliadosConMasLlamadas[i])].apellido);

        }
    }

}
/**
 * \brief Imprime los motivos más consultados
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param array de datos
 */
void informarMotivosMasRepetidos(ELlamadas listaLlamadas[],int canttidadLlamadas,EMotivo motivo[])
{
    int i;
    int listaMotivosMasRepetidos[3];
    motivoMasRepetido(listaLlamadas,canttidadLlamadas,motivo,listaMotivosMasRepetidos);
    for(i=0; i<3; i++)
    {
        if(listaMotivosMasRepetidos[i]==1)
        {
            printf("\n-Motivo mas recurrente: %s\n",motivo[i].tipo);
        }

    }
}
/**
 * \brief Imprime las llamadas cuyos motivos estuvieron más tiempo en linea
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param array de datos
 */
void informarMotivosMasDemorados(ELlamadas listaLlamadas[],int cantidadLlamadas,EMotivo motivo[])
{
    int i;
    int motivoMasDemoraEnPromedios[3];
    motivoMasDemoraEnPromedio(listaLlamadas,cantidadLlamadas,motivo,motivoMasDemoraEnPromedios);
    for(i=0; i<3; i++)
    {
        if(motivoMasDemoraEnPromedios[i]==1)
        {
            printf("\n-Motivo/s, en promedio/s, mas demorado/s: %s\n",motivo[i].tipo);
        }

    }
}
/**
 * \brief Imprime una lista ordenada por nombre
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 */

void imprimirListaPorNombre(EPersona listaAfiliados[],int cantidad)
{
    int i;
    ordenarPorNombreYComprimir(listaAfiliados,cantidad);
    printf("Nombre.\t\tEdad.\t\tDNI\n\n");
    for(i=0; i<cantidad && listaAfiliados[i].isEmpty==0; i++)
    {
        printf("%s\t\t%s\t\t%s\n",listaAfiliados[i].nombre,listaAfiliados[i].edad,listaAfiliados[i].dni);
    }
}
/**
 * \brief Imprime una lista ordenada por nombre y apellido
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 */

void informarAfiliadosPorNombreyApellido(EPersona listaAfiliados[],int cantidad)
{
    int i;
    ordenarPorNombreYApellido(listaAfiliados,cantidad);
    for(i=0; i<cantidad; i++)
    {
        if(listaAfiliados[i].isEmpty==0)
        {
            printf("Nombre %s --Apellido %s\n\n",listaAfiliados[i].nombre,listaAfiliados[i].apellido);
        }
    }
}
