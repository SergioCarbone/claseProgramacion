typedef struct
{

    char nombre[50];
    int edad;
    int estado;
    int dni;

} EPersona;

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
char getNumeroAleatorio(int desde, int hasta, int iniciar);
void getString(char mensaje[], char auxiliar[]);
int getStringLetras(char mensaje[], char auxiliar[]);
int getStringNumeros(char mensaje[], char auxiliar[]);
int buscarPorDni(EPersona persona[], int dni,int cantidad);
int buscarPosicion(EPersona persona[], int cantidad, int valor);
void iniciarEstado(EPersona persona[],int cantidad,int valor);
void ordenarPorNombre(EPersona persona[],int cantidad);

