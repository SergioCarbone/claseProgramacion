#ifndef ENTIDAD1_H_INCLUDED
#define ENTIDAD1_H_INCLUDED

typedef struct
{
    int id;
    unsigned char flagOcupado;
    char a[50];
    int b;
}sEntidad1;

#endif // ENTIDAD1_H_INCLUDED

int ent1_init(sEntidad1* arrayEntidad,int longitud);
int ent1_generarProxId (sEntidad1* arrayEntidad, int longitud);
int ent1_buscarPosicionLibre (sEntidad1* arrayEntidad, int longitud);
int ent1_alta(sEntidad1* arrayEntidad, int longitud);
