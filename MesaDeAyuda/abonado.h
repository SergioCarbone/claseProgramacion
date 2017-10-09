#ifndef _ABONADO
#define _ABONADO

typedef struct{
    char nombre[51];
    char apellido[51];
    int id;
    unsigned char estado;
}sAbonado;
#endif

#define ABONADO_LIBRE 0
#define ABONADO_OCUPADO 1

int abonado_initArray (sAbonado* arrayAbonado, int longitud);
int abonado_cargarAbonado (sAbonado* arrayAbonado ,int longitud);
int abonado_modificarAbonado (sAbonado* arrayAbonado, int longitud);
int abonado_darDeBajaAbonado (sAbonado* arrayAbonado, int longitud);
int abonado_buscarIndicePorId (sAbonado* arrayAbonado, int longitud, int id, char* mensaje);
