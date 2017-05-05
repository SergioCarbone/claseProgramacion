typedef struct
{
    char nombre[50];
    char email[50];
    char nick[50];
    char claveAcceso[50];
    int id;
    int isEmpty;

} EPersona;

typedef struct
{
    char mensaje[150];
    int id;
    int meGusta;
    int idUsuario;
    int isEmpty;

} EComentario;






int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
char getNumeroAleatorio(int desde, int hasta, int iniciar);
void getString(char mensaje[], char auxiliar[]);
int getStringLetras(char mensaje[], char auxiliar[]);
int getStringNumeros(char mensaje[], char auxiliar[]);
int buscarPorNick(EPersona listaUsuarios[], char valor[],int cantidad);
int buscarPosicion(EPersona persona[], int cantidad, int valor);
void iniciarEstado(EPersona persona[],int cantidad,int valor);
void ordenarPorNombre(EPersona persona[],int cantidad);
int buscarPorClave(EPersona listaUsuarios[], char valor[],int cantidad);
int buscarPorEmail(EPersona listaUsuarios[], char valor[],int cantidad);
void iniciarMeGusta(EComentario listaComentarios[],int cantidad,int valor);
void iniciarComentario(EComentario listaComentarios[],int cantidad,int valor);
int buscarPosicionDeComentario(EComentario listaComentarios[], int cantidad, int valor);

