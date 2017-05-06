/***************
* Inicia el estado de cada una de las personas del array
* @param persona recibe el array de persona
* @param cantidad recibe la cantidad de posiciones
* @param valor indica que valor va a recibir cada estado
*/
void iniciarEstado(EPersona persona[],int cantidad,int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        persona[i].estado=valor;
    }
}

/***************************************************************************************************************************************************************
********************                            BUSCAR POSICION COMO TAMBIEN BUSCAR ESPACIO LIBRE                                               ****************
/***************************************************************************************************************************************************************

/***************
*
*
*
*/
int buscarPosicion(EPersona persona[], int cantidad, int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if (persona[i].estado == valor)
        {
            return i;
        }
    }
    return -1;
}



/***************************************************************************************************************************************************************
********************                                                                                                                            ****************
/***************************************************************************************************************************************************************

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */

int buscarPorDni(EPersona lista[], int cantidad,char dni[])
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(strcmp(lista[i].dni,dni)==0)
            retorno=i;
    }
    return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------------------------


/**
* \brief Solicita un array de caracteres numericos al usuari,lo valida y lo devuelve
* \param array de datos
* \param cantidad de subindices
* \param array auxiliar
* \param Es el mensaje a ser mostrado
* \param Es el mensaje a ser mostrado
* \return 1 si el texto contiene solo letras
*/
int cargarDNI (EPersona lista[],int cant,char auxiliar[], char mensajeParaPedirDato[],char mensajeError[])
{
    char seguir='s';
    int indiceDniRepetido;
    int retorno=0;
    int cargaExitosa;
    do
    {
        cargaExitosa=getNumerosChar(auxiliar,mensajeParaPedirDato);
        if(!(cargaExitosa) || (strlen(auxiliar)!=8))
        {
            printf(mensajeError);  // Ejemplo "Ha ingresado caracteres invalidos para un nombre.\n"
            seguir=getChar("Desea reintentar? s/n");
            continue;
        }
        indiceDniRepetido=buscarPorDni(lista,cant,auxiliar);
        if(indiceDniRepetido==-1)
        {
            retorno = 1;
        }
        else
        {
            printf("Este DNI se encuentra ingresado en el sistema.");
            seguir=getChar("Desea reintentar? s/n");
        }

    }
    while(retorno!=1 && seguir == 's');

    return retorno;
}

/***************************************************************************************************************************************************************
********************                                                                                                                            ****************
/***************************************************************************************************************************************************************

/**
* \brief Solicita un array de caracteres numericos al usuari,lo valida y lo devuelve
* \param array de datos
* \param array auxiliar
* \param Es el mensaje a ser mostrado
* \param Es el mensaje de error a ser mostrado
* \return 1 si el texto contiene solo letras
*/
int cargarEdad (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[])
{
    char seguir='s';
    int retorno=0;
    int cargaExitosa;
    do
    {

        cargaExitosa=getNumerosChar(auxiliar,mensajeParaPedirDato);
        if(!(cargaExitosa) || (atoi(auxiliar)>100))
            {
            printf(mensajeError);  // Ejemplo "Ha ingresado caracteres invalidos para un nombre.\n"
            seguir=getChar("Desea reintentar? s/n");
            continue;
            }
            else
            {
            retorno = 1;
            }
    }while(retorno!=1 && seguir == 's');
    return retorno;
}

/***************************************************************************************************************************************************************
********************                                                                                                                            ****************
/***************************************************************************************************************************************************************


/**
 *
 * @param
 * @param
 * @return
 */
void ordenarPorNombre(EPersona persona[],int cantidad)
{

    int i,j;
    EPersona nombre;


    for(i=0; i< cantidad; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(stricmp(persona[i].nombre,persona[j].nombre)>0)
            {
                nombre = persona[i];
                persona[i] = persona[j];
                persona[j] = nombre;

            }
        }
    }
}

/***************************************************************************************************************************************************************
********************              MODELO PARA VALIDAR EL INGRESO DE UN NUMERO DENTRO DE UN RANGO                                                ****************
/***************************************************************************************************************************************************************

/**
* \brief Solicita un array de caracteres numericos al usuario,lo valida y lo devuelve
* \param array auxiliar
* \param Es el mensaje a ser mostrado
* \param Es el mensaje a ser mostrado
* \param valor minimo de referencia
* \param valor maximo de referencia
* \return 1 si el texto contiene solo letras
*/
int cargarNumero (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[],int minimo, int maximo)
{
    char seguir='s';
    int retorno=0;
    int cargaExitosa;
    do
    {

        cargaExitosa=getNumerosChar(auxiliar,mensajeParaPedirDato);
        if(!(cargaExitosa) || (atoi(auxiliar)>maximo) || (atoi(auxiliar)<minimo))
            {
            printf(mensajeError);  // Ejemplo "Ha ingresado caracteres invalidos .\n"
            seguir=getChar("Desea reintentar? s/n");
            continue;
            }
            else
            {
            retorno = 1;
            }


    }while(retorno!=1 && seguir == 's');

    return retorno;
}

/***************************************************************************************************************************************************************
********************                                MODELO PARA UN MENU EN UNA FUNCION                                                          ****************
/***************************************************************************************************************************************************************
/**
* \brief Solicita un valor por cada motivo de la llamada
* \param array de datos
* \param subindice donde se cargara el dato
* \return 1 si el texto contiene solo letras
*/
int motivoLlamada(ELlamadas listaLlamadas[],int indice)
{
    char opcion;
    int retorno=0;
    opcion=getChar("Ingrese la opcion a modificar, \n\n 1-ACV.\n 2-INFARO.\n3-GRIPE.\n");
    switch(opcion)
    {
    case '1':
        strcpy(listaLlamadas[indice].motivo,"ACV");
        retorno =1;
        break;
    case '2':
        strcpy(listaLlamadas[indice].motivo,"INFARTO");
        retorno =1;
        break;
    case '3':
        strcpy(listaLlamadas[indice].motivo,"GRIPE");
        retorno =1;
        break;
    default :
        printf("Error. Opcion incorrecta.");
        break;
    }
    return retorno;
}


/***************************************************************************************************************************************************************
********************                                                                                                                            ****************
/***************************************************************************************************************************************************************

/**
 * \brief Obtiene el indice del ID
 * \param listaPersonas recibe array de personas
 * \param cantidad,cantidad de subindices
 * \param id a comparar
 * \return indice del ID encontrado o -1 si no se encuentra
 *
 */

int buscarPorIdUsuario(EPersona lista[], int cantidad,int idUsuario)
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((idUsuario==lista[i].id) && lista[i].isEmpty==0)
        {
            retorno=i;
            break;
        }

    }

    return retorno;
}

/***************************************************************************************************************************************************************

/**
 * \brief Obtiene el indice del ID
 * \param listaPersonas recibe array de personas
 * \param cantidad,cantidad de subindices
 * \param mensaje, texto para solicitar el ID
 * \param mensajeError, texto si el dato es invalido
 * \param mensajeNoEncontrado, texto si no se encontro el ID
 * \return indice del ID encontrado
 *
 */

int obtenerIndicePorId(EPersona listaPersonas[],int cantidad,char mensaje[], char mensajeError[],char mensajeNoEncontrado[])
{
    int indiceId=-1;
    char id[5];
    char continuar;
    do
    {
        if(cargarNumero(id,mensaje,mensajeError,0,999)) // 0 Y 999 SERIA ENTRE QUE RANGO BUSCAR
        {
            indiceId = buscarPorIdUsuario(listaPersonas,cantidad,atoi(id));
            if(indiceId==-1)
            {
                printf("%s",mensajeNoEncontrado);
                continuar=getChar("\nDesea continuar? s/n");
            }
        }
    }
    while(indiceId==-1 && continuar=='s');
    return indiceId;
}




/***************************************************************************************************************************************************************
********************                      BUSQUEDA ENTRE DOS ESTRUCTURAS POR UN CRITERIO EJ LLAMADAS                                            ****************
/***************************************************************************************************************************************************************

/**
 * \brief Obtiene el usuario con mayor cantidad de llamadas realizadas
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param indice de usuarios con mayor cantidad de llamadas
 * \return 0 si hubo error 1 si esta todo ok
 *
 */

int usuarioConMayorCantidadDeLlamadas (ELlamadas listaLlamadas[],int cantComent,EPersona listaUsuar[],int cantUsuar,int usuarConMasMensajes[])
{
    int retorno=0;
    int maximo=0;
    int contador;
    int i;
    int j;
    int k=0;
    iniciarEstado(usuarConMasMensajes,cantUsuar,-1);
    for(i=0; i<cantUsuar; i++)
    {
        if(listaUsuar[i].isEmpty==1)
        {
            continue;
        }
        contador=0;
        for(j=0; j<cantComent; j++)
        {
            if(listaLlamadas[j].isEmpty==0 && listaLlamadas[j].idUsuario==listaUsuar[i].id)
            {
                contador++;

            }
        }
        if(contador>maximo)
        {
            k=0;
            iniciarEstado(usuarConMasMensajes,cantUsuar,-1);
            usuarConMasMensajes[k]=i;
            maximo=contador;
            retorno = 1;

        }
        else if(contador==maximo)
        {
            k++;
            usuarConMasMensajes[k]=i;
        }

    }
    return retorno;
}


/***************************************************************************************************************************************************************
********************                              BUSCAR EL MOTIVO MAS ELEGIDO ENTRE DISTINTAS OPCIONES                                         ****************
/***************************************************************************************************************************************************************

/**
 * \brief Obtiene el motivo más elegido
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param lista el array se pasa como parametro.
 * \param indice de motivos más elegidos
 * \return
 *
 */

void motivoMasRepetido (ELlamadas lista[],int cantidad,EMotivo motivo[],int motivosMasRepetidos[]) // EMotivo motivo[] (tendria que crear una estructura con los motivos. A cada motivo ponerle un contador
{
    int contador[3]= {0,0,0}; // cantidad de motivos en la estructura
    int maximo=0;
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(lista[i].isEmpty==0)
        {
            if(strcmp(lista[i].motivo,motivo[0].tipo)==0)
            {
                contador[0]++;
            }
            else if(strcmp(lista[i].motivo,motivo[1].tipo)==0)
            {
                contador[1]++;
            }
            else
            {
                contador[2]++;
            }
        }
    }

    for(i=0; i<3; i++)
    {
        if(contador[i]>maximo)
        {
            iniciarEstado(motivosMasRepetidos,3,0);
            motivosMasRepetidos[i]=1;
            maximo=contador[i];
        }
        else if(contador[i]==maximo)
        {
            motivosMasRepetidos[i]=1;
        }
    }
}


/***************************************************************************************************************************************************************
********************                            SACAR EL PROMEDIO ENTRE DIFERENTES MOTIVOS                                                      ****************
/***************************************************************************************************************************************************************


/**
 * \brief Obtiene el motivo con más tiempo en linea
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param lista el array se pasa como parametro.
 * \param indice de motivos con más tiempo en linea
 * \return
 *
 */
void motivoMasDemoraEnPromedio (ELlamadas lista[],int cantidad,EMotivo motivo[],int motivosMasDemorados[]) // EMotivo motivo[] (tendria que crear una estructura con los motivos. A cada motivo ponerle un contador
{
    int contador[3]= {0,0,0};
    int acumulador[3]= {0,0,0};
    int promedio[3]= {0,0,0};
    int maximo=0;
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(lista[i].isEmpty==0 && (stricmp(lista[i].estado,"CUMPLIDO")==0)) // Tratar de adaptar a cualquier caso (promedio de calificaciones)
        {
            if(strcmp(lista[i].motivo,motivo[0].tipo)==0)
            {
                contador[0]++;
                acumulador[0]=acumulador[0]+lista[i].duracion;

            }
            else if(strcmp(lista[i].motivo,motivo[1].tipo)==0)
            {
                contador[1]++;
                acumulador[1]=acumulador[1]+lista[i].duracion;
            }
            else
            {
                contador[2]++;
                acumulador[2]=acumulador[2]+lista[i].duracion;
            }
        }
    }
    for(i=0; i<3; i++)
    {
        if(contador[i]>0)
        {
            promedio[i]=(acumulador[i]/contador[i]);
        }

    }


    for(i=0; i<3; i++)
    {
        if(promedio[i]>maximo)
        {
            iniciarEstado(motivosMasDemorados,3,0);
            motivosMasDemorados[i]=1;
            maximo=promedio[i];

        }
        else if(promedio[i]==maximo)
        {
            motivosMasDemorados[i]=1;
        }
    }
}

/***************************************************************************************************************************************************************
********************                                 BUSCAR AL/LOS USUARIOS CON MAYOR EDAD                                                      ****************
/***************************************************************************************************************************************************************


/**
 * \brief
 * \param
 * \param
 * \param
 * \return
 *
 */

int usuarioMayorEdad (EPersona lista[],int cantidad,int listaUsuariosMayorEdad[])
{
    int retorno =0;
    int i,j;
    int maximo=0;
    int auxiliarEdad;
    for(i=0; i<cantidad; i++)
    {
        auxiliarEdad=(atoi(lista[i].edad));
        if(lista[i].isEmpty==0 && auxiliarEdad>maximo)
        {
            j=0;
            inicializarArrayDeIndices(listaUsuariosMayorEdad,cantidad,-1);
            listaUsuariosMayorEdad[j]=i;
            maximo=auxiliarEdad;
            retorno =1;
        }
        else if(lista[i].isEmpty==0 && auxiliarEdad==maximo)
        {
            j++;
            listaUsuariosMayorEdad[j]=i;
        }
    }
    return retorno;
}

/***************************************************************************************************************************************************************
********************                              ORDENAMIENTO POR DOS CRITERIOS                                                                ****************
/***************************************************************************************************************************************************************


/**
 * \brief Ordena un array de datos por criterio
 * \param cantidad de subindices/datos
 * \return -
 *
*/
void ordenarPorNombreYApellido(EPersona listaAfiliados[], int cantidad)
{
    int i,j,k;
    int flag;
    comprimirArray (listaAfiliados,cantidad,1);
    EPersona auxiliarPersona;
    for(i=0; i<cantidad; i++)
    {
        if(listaAfiliados[i].isEmpty==1)
        {
            break;
        }
        flag=0;
        auxiliarPersona = listaAfiliados[i];
        for(j=i; j > 0 && stricmp(auxiliarPersona.nombre,listaAfiliados[j-1].nombre)<=0 ; j--)
        {
            if(stricmp(auxiliarPersona.nombre,listaAfiliados[j-1].nombre)<0)
            {
                flag=1;
                continue;
            }
            else if((stricmp(auxiliarPersona.nombre,listaAfiliados[j-1].nombre))==0)
            {
                if(stricmp(auxiliarPersona.apellido,listaAfiliados[j-1].apellido)>0)
                {
                    flag=1;
                }
                else if((stricmp(auxiliarPersona.apellido,listaAfiliados[j-1].apellido)<0))
                {
                    break;
                }
            }


        }
        if(flag==1)
        {
            for(k=i; k>j; k--)
            {
                listaAfiliados[k]=listaAfiliados[k-1];
            }
            listaAfiliados[j]=auxiliarPersona;
        }

    }
}


/************************************************************************************************************************************************************************************

/**
 * \brief Comprime un array de estructuras de tipo EPersona para diversos usos.
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param valor que indica el lugar en el índice donde se encuentra el lugar vacío.
 */
void comprimirArray (EPersona arrayPersonas[],int cantidad, int estado)
{
    int i;
    for (i=0 ; i<cantidad; i++)
    {
        if(arrayPersonas[i].isEmpty==estado)
        {
            for(; i<cantidad-1; i++)
            {
                arrayPersonas[i]=arrayPersonas[i+1];
            }
            arrayPersonas[cantidad-1].isEmpty=estado;
        }
    }
}


/***************************************************************************************************************************************************************
********************                              ORDENAMIENTO POR UN CRITERIO Y COMPRIME EL ARRAY                                              ****************
/***************************************************************************************************************************************************************



/**
 * \brief Ordena un array de datos y lo comprime
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 */
void ordenarPorNombreYComprimir (EPersona arrayPersona[], int cantidad)
{
    /**Esta funcion primero comprime el array y luego valida los espacios vacios**/
    comprimirArray(arrayPersona,cantidad,0);
    int i,j;
    EPersona auxiliarPersona;
    for(i=0; i<cantidad; i++)
    {
        if(arrayPersona[i].isEmpty==1)
        {
            continue;
        }
        auxiliarPersona = arrayPersona[i];
        j=i;
        for( ; j>0 && stricmp(auxiliarPersona.nombre,arrayPersona[j-1].nombre)<0 ; j--)
        {
            if(arrayPersona[j].isEmpty==1)
            {
                continue;
            }
            arrayPersona[j]=arrayPersona[j-1];
        }
        arrayPersona[j]=auxiliarPersona;
    }
}

/***************************************************************************************************************************************************************
********************                                         MODELO PARA GRAFICO                                                                ****************
/***************************************************************************************************************************************************************

/**
 * \brief imprime grafico utilizando cantidad de personas por edad
 * \param estructura y cantidad de personas
 * \return -
 *
*/
void graficoEdad(EPersona listaAfiliados[],int cantidad)
{
    int contMenos18=0;
    int contEntre18y35=0;
    int contMas35=0;
    int i;
    int edad;

    for(i=0; i<cantidad; i++)
    {
        if(listaAfiliados[i].isEmpty==0)
        {


            edad=atoi(listaAfiliados[i].edad);
            if(edad<=18)
            {
                contMenos18++;
            }
            else if(edad>18 && edad<35)
            {
                contEntre18y35++;
            }
            else
            {
                contMas35++;
            }
        }
    }
    for(i=cantidad; i>0; i--)
    {
        if(!(contEntre18y35<i&&contMas35<i &&contMenos18<i))
        {
            if(i==contMenos18)
            {
                printf("\n*\t");
            }
            else
            {
                printf("\n \t");
            }

            if(i==contEntre18y35)
            {
                printf("*\t");
                contEntre18y35--;
            }
            else
            {
                printf("\t");
            }
            if(i==contMas35)
            {
                printf("*\n");
                contMas35--;
            }
            else
                printf("\n");

        }

    }
    printf("\n<18\t19-35\t>35\n");
}

/***************************************************************************************************************************************************************
********************                                CARGAR DATOS EN UNA ESTRUCTURA DE PERSONA                                                   ****************
/***************************************************************************************************************************************************************


/**
 * \brief Carga y valida datos ingresados por usuario
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param Id pasado por parametro
 */
int alta (EPersona listaPersonas[],int cantidad,int id)  // id: seria un contador que se va incrementando, sino sacar ese parametro
{
    int retorno=0;
    int indiceVacio;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[10];
    char auxEdad[4];

    indiceVacio=buscarPosicion(listaPersonas,cantidad,1);
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
        // Tener en cuenta como esta formada la estructura

        strcpy(listaPersonas[indiceVacio].nombre,auxNombre);
        strcpy(listaPersonas[indiceVacio].apellido,auxApellido);
        strcpy(listaPersonas[indiceVacio].dni,auxDni);
        strcpy(listaPersonas[indiceVacio].edad,auxEdad);
        listaPersonas[indiceVacio].id=id;
        listaPersonas[indiceVacio].isEmpty=0;

    }
    return retorno;
}

/***************************************************************************************************************************************************************
********************                                BAJA DE DATOS EN UNA ESTRUCTURA DE PERSONA                                                  ****************
/***************************************************************************************************************************************************************



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
            indiceId = buscarPosicion(listaPersonas,cantidad,atoi(id));
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

/***************************************************************************************************************************************************************
********************                                MODIFICACION DE DATOS EN UNA ESTRUCTURA DE PERSONA                                          ****************
/***************************************************************************************************************************************************************

/**
 * \brief Busca por indice y realiza carga de datos a modificar
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param mensaje para el usuario
 */
void modificar (EPersona listaPersonas[],int cantidad,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[])
{
    // TENER EN CUENTA LA CANTIDAD DE ATRIBUTOS DE LA PERSONA Y LAS OPCIONES DEL MENU

    int indiceId;
    int cargaExitosa;
    char auxNombre[50];
    char auxApellido[50];
    char opcion;
    if((indiceId =buscarPosicion(listaPersonas,cantidad,mensaje,mensajeError,mensajeNoEncontrado))!=-1)
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

/***************************************************************************************************************************************************************
********************                              CARGAR ALGO NUEVO QUE SE CONECTA CON LA ESTRUCTURA DE PERSONAS                                ****************
/***************************************************************************************************************************************************************


/**
 * \brief Busca por indice activo en dos estructuras y crea una entrada para llamadas
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param array de datos a comparar
 * \param cantidad de posiciones que tiene el array.
 * \param dato pasado como parametro
 */

 // CAMBIAR NOMBRE DE LA FUNCION    TENER EN CUNETA LOS PARAMETROS Y PONER LOS NOMBRES DE LAS ESTRUCTURAS

void nuevaLlamada (EPersona listaPersonas[],int cantidad, ELlamadas listaLlamadas[], int cantidadLlamas,int id)
{
    int indiceId;
    int indiceVacio;
    indiceVacio=buscarPosicion(listaLlamadas,cantidadLlamas,1); // buscarPosicion HAY QUE HACER UN DUPLICADO PONIENDO LOS NOMBRES DE LA SEGUNDA ESTRUCTURA
    if(indiceVacio!=-1)
    {
        indiceId = buscarPosicion(listaPersonas,cantidad,"Ingrese ID de afiliado","ID invalido","ID no encontrado");
    }
    if(indiceId!=-1)
    {
        if((motivoLlamada(listaLlamadas,indiceVacio)))  //motivoLlamada: TENER EN CUENTA QUE VA A DEMPENDER DE CADA ESTRUCTURA
        {
            listaLlamadas[indiceVacio].idUsuario=listaPersonas[indiceId].id;
            listaLlamadas[indiceVacio].id=id;
            strcpy(listaLlamadas[indiceVacio].estado,"Pendiente");
            listaLlamadas[indiceVacio].isEmpty=0;
        }

    }
}

/***************************************************************************************************************************************************************
********************                                           IMPRIMIR LISTADO POR NOMBRE                                                      ****************
/***************************************************************************************************************************************************************


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

/***************************************************************************************************************************************************************
********************                                  IMPRIMIR LISTADO POR NOMBRE Y APELLIDO                                                    ****************
/***************************************************************************************************************************************************************


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
