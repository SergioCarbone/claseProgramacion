#ifndef _PERSONA
#define _PERSONA
typedef struct{
    char nombre[51];
    char apellido[51];
    char DNI[10];
    int id;
    unsigned char edad;
    unsigned char estado;
}sPersona;
#endif // _PERSONA


#define PERSONA_LIBRE 0
#define PERSONA_OCUPADO 1


int persona_buscarProximoId (sPersona* arrayPersona, int longitud);
int persona_cargarPersona (sPersona* arrayPersona, int indice, int longitud);
int persona_initArray (sPersona* arrayPersona, int longitud);
int persona_buscarIndicePorId (sPersona* arrayPersona, int longitud, int id, char* mensaje);
int persona_modificarPersona (sPersona* arrayPersona, int longitud);
int persona_darDeBajaPersona (sPersona* arrayPersona, int longitud);

