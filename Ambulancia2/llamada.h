#ifndef _LLAMADA
#define _LLAMADA
typedef struct{
    int idAsociado;
    unsigned char motivo;
    unsigned char estadoLlamada;
    int idAmbulancia;
    int tiempo;
    int idLlamada;

}sLlamada;
#endif // _PERSONA

#define MOTIVO_INFARTO 0
#define MOTIVO_ACV 1
#define MOTIVO_GRIPE 2

#define ESTADO_SIN_USO 2
#define ESTADO_PENDIENTE 0
#define ESTADO_CUMPLIDO 1


int llamada_nuevaLlamada (sLlamada* arrayLlamada,sPersona* arrayPersona,int longitudPersona, int longitudLamada, char* mensajeError, char* mensajeError2);
int llamada_initArray (sLlamada* arrayLlamada, int longitud);
int llamada_finLlamada (sPersona* arrayPersona,sLlamada* arrayLlamada,int longitudPersona, int longitudLamada, char* mensaje);
int llamada_buscarIndicePorId (sLlamada* arrayLlamada, int longitud, int id, char* mensaje);
int llamada_printPersona (sPersona* arrayPersona, sLlamada* arrayLlamada,int longitudPersona, int longitudLlamada, char* mensajeError,char* mensajeError2);
int llamada_obtenerCantidadMotivosYllamadas (sLlamada* arrayLlamada, int longitud);
int llamada_generarProximoIndice (void);
int llamada_buscarIdConMasCantLlamadas (sLlamada* arrayLlamada, sPersona* arrayPersona, int longitudPersona, int longitudLlamada, char* mensajeError);
int llamada_buscarLlamadasPendientes (sPersona* arrayPersona, sLlamada* arrayLlamada, int lontidudPersona, int lontigudLlamada, int id);
int llamada_calcularPromediodeMotivos (sLlamada* arrayLlamada, int longitudLlamada);
int llamada_buscarCantidadLlamadasPorId (sLlamada* arrayLlamadas,int longitudLlamada,int id,char* mensaje);
