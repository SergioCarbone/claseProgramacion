#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED

typedef struct
{
    int id;
    int idEntidad1;
    unsigned char flagOcupado;
    char a[50];
    int b;
}sEntidad2;

#endif // ENTIDAD1_H_INCLUDED

int ent2_init(sEntidad2* arrayEntidad,int longitud);
int ent2_generarProxId (sEntidad2* arrayEntidad, int longitud);
int ent2_buscarPosicionLibre (sEntidad2* arrayEntidad, int longitud);
int ent2_alta(sEntidad2* arrayEntidad, int longitud);
