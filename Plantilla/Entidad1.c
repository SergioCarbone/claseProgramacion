#include <stdio.h>
#include <stdlib.h>
#include "Entidad1.h"

int ent1_init(sEntidad1* arrayEntidad,int longitud)
{

    return 0;
}

int ent1_generarProxId (sEntidad1* arrayEntidad, int longitud)
{
    return 0;
}

int ent1_buscarPosicionLibre (sEntidad1* arrayEntidad, int longitud)
{
    return 0;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
 int ent1_alta(sEntidad1* arrayEntidad, int longitud)
 {
     int retorno = -1;
     char bufferAuxNombre[50];
     int indiceVacio = ent1_buscarPosicionLibre(arrayEntidad,longitud);
     int nuevoId = ent1_generarProxId(arrayEntidad,longitud);

     if(val_getString(bufferAuxNombre,"Ingrese nombre","Solo letras",3,50)!= -1)
     {
         arrayEntidad[indiceVacio].flagOcupado = 1;
         arrayEntidad[indiceVacio].id = nuevoId;
         strncpy(arrayEntidad[indiceVacio].a,bufferAuxNombre,50);
         retorno = 0;

     }





     return 0;
 }

 int imprimirTodo (sEntidad1* arrayEntidad1, int LONGITUD_ENTIDAD1, sEntidad2* arrayEntidad2, int LONGITUD_ENTIDAD2)
 {
     int i;
     int retorno = -1;

     for(i=0, i<LONGITUD_ENTIDAD1,i++)
     {
         if(arrayEntidad1[i].flagOcupado == 1)
         {
             int idE2 = arrayEntidad1[i].id;
             ent2_buscarIndicePorId(arrayEntidad2,LONGITUD_ENTIDAD2,idE2)
             {

             }
         }
     }
 }

