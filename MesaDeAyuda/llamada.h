
#ifndef _LLAMADA
#define _LLAMADA
typedef struct{
    int idAbonado;
    int idLlamada;
    unsigned char motivo;
    unsigned char estadoLlamada;
    int tiempo;

}sLlamada;
#endif // _PERSONA

#define MOTIVO_FALLA_3G 0
#define MOTIVO_FALLA_LTE 1
#define MOTIVO_FALLA_EQUIPO 2

#define ESTADO_EN_CURSO 0
#define ESTADO_SOLUCIONADO 1
#define ESTADO_NO_SOLUCIONADO 2
#define ESTADO_SIN_USO 3

int llamada_initArray (sLlamada* arrayLlamada, int longitud);
int llamada_nuevaLlamada (sLlamada* arrayLlamada,sAbonado* arrayAbonado,int longitudAbonado, int longitudLlamada, char* mensajeError);
int llamada_finLlamada (sAbonado* arrayAbonado,sLlamada* arrayLlamada,int longitudAbonado, int longitudLlamada, char* mensaje);
int llamada_buscarLlamadasEnCurso (sAbonado* arrayAbonado, sLlamada* arrayLlamada, int lontidudAbonado, int lontigudLlamada, int id);
