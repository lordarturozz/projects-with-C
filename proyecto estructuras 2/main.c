//
//  main.c
//  proyecto estructuras 2
//
//  Created by Arturo Roldan sanchez on 11/09/18.
//  Copyright © 2018 Arturo Roldan sanchez. All rights reserved.
//



#include "basededatos.h"

FILE *archivo;

void ordenaBase(){
    char aux[SIZE];
    int i,j,k,l=0;
    archivo=fopen("BaseDatos.bat","wb");
    if(archivo==NULL){
        exit(1);
    }
    printf("Ordenando la Base de Datos...");
    for(i=0;i<l-1;i++){
        k=i;
        strcpy(aux,BaseDatos[i].ApellidoPat);
        for(j=i+1;j<l;j++)
        {
            if(strcmp(BaseDatos[j].ApellidoPat, aux)<0)
            {
                k=j;
                strcpy(aux, BaseDatos[j].ApellidoPat);
    
            }
        }
        strcpy(BaseDatos[k].ApellidoPat, BaseDatos[i].ApellidoPat);
        strcpy(BaseDatos[i].ApellidoPat, aux);
    }
    printf("Base de Datos ordenada");
}



void imprimeRegistros(int posicion){
    int i;
    for(i=0;i<posicion;i++)
    {
        printf("Registro %d",i);
    printf("-----------------------------------------------------------------\n");
    printf("|                          INSTITUTO NACIONAL ELECTORAL         |\n");
    printf("|                          Credencial para votar                |\n");
    printf("|  ------------ Nombre:                                         |\n");
    printf("|  |          | %-35s             |\n",BaseDatos[posicion].Nombre);
    printf("|  |          | %-20s                            |\n",BaseDatos[posicion].ApellidoPat);
    printf("|  |     F    | %-20s                            |\n",BaseDatos[posicion].ApellidoMat);
    printf("|  |     O    | Dirección:                                      |\n");
    printf("|  |     T    | %-20s                            |\n",BaseDatos[posicion].Domicilio);
    printf("|  |     O    | Clave de Elector: %-20s          |\n",BaseDatos[posicion].ClaveE);
    printf("|  |          | CURP: %-20s  Registro: %-4d      |\n",BaseDatos[posicion].CURP, BaseDatos[posicion].Registro);
    printf("|  |          | Estado: %-2d  Municipio: %-3d  Seccion: %-4d       |\n",BaseDatos[posicion].Estado, BaseDatos[posicion].Municipio, BaseDatos[posicion].Seccion);
    printf("|  ------------ Localidad: %-4s  Emision: %-4d  Vigencia: %-4d  |\n",BaseDatos[posicion].Localidad, BaseDatos[posicion].Emision, BaseDatos[posicion].Vigencia);
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    
    printf("\n\n");
}
}


void guardarBaseDatos(){
    int i;
    archivo=fopen("BaseDatos.dat","wb");
    if(archivo==NULL){
        printf("El archivo BaseDatos.dat no existe\n");
        exit(1);
    }
    printf("Qué número de INE se va a guardar en el archivo\n");
    scanf("%d",&i);
    fwrite(&BaseDatos[i].Nombre, sizeof(struct INE), 1, archivo);
    fwrite(&BaseDatos[i].ApellidoPat,sizeof(struct INE),1,archivo);
    fwrite(&BaseDatos[i].ApellidoMat, sizeof(struct INE), 1, archivo);
    fwrite(&BaseDatos[i].Domicilio,sizeof(struct INE),1,archivo);
    fwrite(&BaseDatos[i].ClaveE, sizeof(struct INE), 1, archivo);
       fwrite(&BaseDatos[i].CURP, sizeof(struct INE), 1, archivo);
       fwrite(&BaseDatos[i].Localidad, sizeof(struct INE), 1, archivo);
       fwrite(&BaseDatos[i].Registro, sizeof(struct INE), 1, archivo);
       fwrite(&BaseDatos[i].Estado, sizeof(struct INE), 1, archivo);
       fwrite(&BaseDatos[i].Municipio, sizeof(struct INE), 1, archivo);
       fwrite(&BaseDatos[i].Seccion, sizeof(struct INE), 1, archivo);
       fwrite(&BaseDatos[i].Emision, sizeof(struct INE), 1, archivo);
       fwrite(&BaseDatos[i].Vigencia, sizeof(struct INE), 1, archivo);
    fclose(archivo);
    printf("Se creo el archivo BaseDatos.dat\n");
    
}
void restaurarBaseDatos()
{
    
    int i;
    int regreso=Menu();
    archivo=fopen("BaseDatos.dat", "r");
    if(archivo==NULL){
        exit(regreso);
    }
    
    printf("Qué número de INE se va a recuperar en el archivo\n");
    scanf("%d",&i);
    while(!feof(archivo))
    {
    printf("Restaurando base de datos");
    fread(&BaseDatos[i].Nombre, sizeof(struct INE), 1, archivo);
    fread(&BaseDatos[i].ApellidoPat,sizeof(struct INE),1,archivo);
    fread(&BaseDatos[i].ApellidoMat, sizeof(struct INE), 1, archivo);
    fread(&BaseDatos[i].Domicilio,sizeof(struct INE),1,archivo);
    fread(&BaseDatos[i].ClaveE, sizeof(struct INE), 1, archivo);
    fread(&BaseDatos[i].CURP, sizeof(struct INE), 1, archivo);
    fread(&BaseDatos[i].Localidad, sizeof(struct INE), 1, archivo);
    fread(&BaseDatos[i].Registro, sizeof(struct INE), 1, archivo);
    fread(&BaseDatos[i].Estado, sizeof(struct INE), 1, archivo);
    fread(&BaseDatos[i].Municipio, sizeof(struct INE), 1, archivo);
    fread(&BaseDatos[i].Seccion, sizeof(struct INE), 1, archivo);
    fread(&BaseDatos[i].Emision, sizeof(struct INE), 1, archivo);
    fread(&BaseDatos[i].Vigencia, sizeof(struct INE), 1, archivo);
    
    printf("Se restauró el archivo BaseDatos.dat\n");
    }
    fclose(archivo);
}
void cambiaRegistro()
{
    archivo=fopen("BaseDatos.dat", "wb");
    int e,a;
    int opcion=0;
    if(archivo==NULL)
        exit(1);
    printf("Que registro desea modificar [0 - 9]\n");
    scanf("%d",&e);
    printf("Desea modificar este registro [1. Si, 2.No]? ");
    scanf("%d",&a);
    if(a==0)
    {
        exit(1);
    }
    else if(a==1)
    {
        printf("Seleccione el campo a cambiar:\n");
        printf("1. Nombre\n");
        printf("2. Apellido Paterno\n");
        printf("3. Apellido Materno\n");
        printf("4. Domicilio\n");
        printf("5. Clave de elector\n");
        printf("6. CURP\n");
        printf("7. Localidad\n");
        printf("8. Registro\n");
        printf("9. Estado\n");
        printf("10. Municipio\n");
        printf("11. Seccion\n");
        printf("12. Emision\n");
        printf("13. Vigencia\n");
        scanf("%d",&opcion);
    switch(opcion)
        {
            case 1:         printf("El nuevo Nombre es:\n");
                gets(BaseDatos[e].Nombre);
                fwrite(&BaseDatos[e].Nombre, sizeof(struct INE), 1, archivo);
                break;
            case 2:printf("El nuevo Apellido Paterno es:\n");
                gets(BaseDatos[e].ApellidoPat);
                fwrite(&BaseDatos[e].ApellidoPat, sizeof(struct INE), 1, archivo);
                break;
                
            case 3: printf("El nuevo Apellido Materno es:\n");
                gets(BaseDatos[e].ApellidoMat);
                fwrite(&BaseDatos[e].ApellidoMat, sizeof(struct INE), 1, archivo);
                break;
            case 4: printf("El nuevo Domicilio es:\n");
                gets(BaseDatos[e].Domicilio);
                fwrite(&BaseDatos[e].Domicilio, sizeof(struct INE), 1, archivo);
                break;
            case 5:printf("El nuevo Clave de Elector es:\n");
                gets(BaseDatos[e].ClaveE);
                fwrite(&BaseDatos[e].ClaveE, sizeof(struct INE ), 1, archivo);
                break;
            case 6:printf("El nuevo CURP es:\n");
                gets(BaseDatos[e].CURP);
                fwrite(&BaseDatos[e].CURP, sizeof(struct INE), 1, archivo);
                break;
            case 7:
                printf("El nuevo Localidad es:\n");
               gets(BaseDatos[e].Localidad);
                fwrite(&BaseDatos[e].Localidad, sizeof(struct INE), 1, archivo);
                break;
            case 8:printf("El nuevo Registro es:\n");
                scanf("%d",&BaseDatos[e].Registro);
                fwrite(&BaseDatos[e].Registro, sizeof(struct INE), 1, archivo);
                break;
            case 9:printf("El nuevo Estado es:\n");
                scanf("%d",&BaseDatos[e].Estado);
                fwrite(&BaseDatos[e].Estado, sizeof(struct INE), 1, archivo);
                break;
            case 10: printf("El nuevo Municipio es:\n");
                scanf("%d",&BaseDatos[e].Municipio);
                fwrite(&BaseDatos[e].Municipio, sizeof(struct INE), 1, archivo);
                break;
            case 11: printf("El nuevo Seccion es:\n");
                scanf("%d",&BaseDatos[e].Seccion);
                fwrite(&BaseDatos[e].Seccion, sizeof(struct INE), 1, archivo);
                break;
            case 12: printf("El nuevo Emision es:\n");
                scanf("%d",&BaseDatos[e].Emision);
                fwrite(&BaseDatos[e].Emision, sizeof(struct INE), 1, archivo);
                break;
            case 13: printf("El nuevo Vigencia es:\n");
                scanf("%d",&BaseDatos[e].Vigencia);
                fwrite(&BaseDatos[e].Vigencia, sizeof(struct INE), 1, archivo);
                break;
    default:
                break;
    }
    }
    fclose(archivo);
}

void inicializa()
{
    int e;
    
    for(e = 0; e < SIZE; e++)
    {
        strcpy(BaseDatos[e].Nombre, "\0");
        strcpy(BaseDatos[e].ApellidoPat, "\0");
        strcpy(BaseDatos[e].ApellidoMat, "\0");
        strcpy(BaseDatos[e].Domicilio, "\0");
        strcpy(BaseDatos[e].ClaveE, "\0");
        strcpy(BaseDatos[e].CURP, "\0");
        strcpy(BaseDatos[e].Localidad, "\0");
        BaseDatos[e].Registro = 0;
        BaseDatos[e].Estado = 0;
        BaseDatos[e].Municipio = 0;
        BaseDatos[e].Seccion = 0;
        BaseDatos[e].Emision = 0;
        BaseDatos[e].Vigencia = 0;
        
    }
}

void bajas()
{
    int baja;
    int opcion = 0;
    int confirmacion;
    
    printf("\t1. Dar de baja \n");
    printf("\t2. Regresar \n\n");
    printf("\tOpcion: ");
    scanf("%d", &opcion);
    
    switch(opcion)
    {
            while ( opcion != 2 )
            {
            case 1:
                printf("\n\tQue identificacion deseas dar de baja [ 0 - 9 ]: ");
                scanf("%d", &baja);
                
                if( BaseDatos[baja].Nombre != '\0' && BaseDatos[baja].Vigencia != 0 )
                {
                    printf("\n\tLa identificacion contiene datos que pueden ser borrados\n");
                    printf("\n\tEsta seguro que desea borralos [ 1. SI,    2. NO ]: ");
                    scanf("%d", &confirmacion);
                    
                    if ( confirmacion == 1 )
                    {
                        strcpy(BaseDatos[baja].Nombre, "\0");
                        strcpy(BaseDatos[baja].ApellidoPat, "\0");
                        strcpy(BaseDatos[baja].ApellidoMat, "\0");
                        strcpy(BaseDatos[baja].Domicilio, "\0");
                        strcpy(BaseDatos[baja].ClaveE, "\0");
                        strcpy(BaseDatos[baja].CURP, "\0");
                        strcpy(BaseDatos[baja].Localidad, "\0");
                        BaseDatos[baja].Registro = 0;
                        BaseDatos[baja].Estado = 0;
                        BaseDatos[baja].Municipio = 0;
                        BaseDatos[baja].Seccion = 0;
                        BaseDatos[baja].Emision = 0;
                        BaseDatos[baja].Vigencia = 0;
                        
                        printf("\n\tLos datos han sido eliminados exitosamente\n\n");
                    }
                    else if ( confirmacion == 2 )
                    {
                        break;
                    }
                }
                else
                {
                    printf("\nLa identificacion no contiene datos\n\n");
                }
                break;
                
            case 2:
                break;
                
            default :
                printf("\nOpcion incorrecta\n\n");
                break;
            }
    }

}

void altaRegistro(int posicion)
{
    
    printf("\nNombre: ");
    fflush(stdin);
    gets(BaseDatos[posicion].Nombre);
    
    printf("Apellido Paterno: ");
    fflush(stdin);
    gets(BaseDatos[posicion].ApellidoPat);
    
    printf("Apellido Materno: ");
    fflush(stdin);
    gets(BaseDatos[posicion].ApellidoMat);
    
    printf("Domicilio: ");
    fflush(stdin);
    gets(BaseDatos[posicion].Domicilio);
    
    printf("Clave de Elector: ");
    fflush(stdin);
    gets(BaseDatos[posicion].ClaveE);
    
    printf("CURP: ");
    fflush(stdin);
    gets(BaseDatos[posicion].CURP);
    
    printf("Registro: ");
    fflush(stdin);
    scanf("%d", &BaseDatos[posicion].Registro);
    
    printf("Estado: ");
    fflush(stdin);
    scanf("%d", &BaseDatos[posicion].Estado);
    
    printf("Municipio: ");
    fflush(stdin);
    scanf("%d", &BaseDatos[posicion].Municipio);
    
    printf("Seccion: ");
    fflush(stdin);
    scanf("%d", &BaseDatos[posicion].Seccion);
    
    printf("Localidad: ");
    fflush(stdin);
    gets(BaseDatos[posicion].Localidad);
    
    printf("Emision: ");
    fflush(stdin);
    scanf("%d", &BaseDatos[posicion].Emision);
    
    printf("Vigencia: ");
    fflush(stdin);
    scanf("%d", &BaseDatos[posicion].Vigencia);
    
    printf("\n");
}

void imprimeRegistro(int posicion)
{
    
    printf("-----------------------------------------------------------------\n");
    printf("|                          INSTITUTO NACIONAL ELECTORAL         |\n");
    printf("|                          Credencial para votar                |\n");
    printf("|  ------------ Nombre:                                         |\n");
    printf("|  |          | %-35s             |\n",BaseDatos[posicion].Nombre);
    printf("|  |          | %-20s                            |\n",BaseDatos[posicion].ApellidoPat);
    printf("|  |     F    | %-20s                            |\n",BaseDatos[posicion].ApellidoMat);
    printf("|  |     O    | Dirección:                                      |\n");
    printf("|  |     T    | %-20s                            |\n",BaseDatos[posicion].Domicilio);
    printf("|  |     O    | Clave de Elector: %-20s          |\n",BaseDatos[posicion].ClaveE);
    printf("|  |          | CURP: %-20s  Registro: %-4i      |\n",BaseDatos[posicion].CURP, BaseDatos[posicion].Registro);
    printf("|  |          | Estado: %-2i  Municipio: %-3i  Secci¢n: %-4i       |\n",BaseDatos[posicion].Estado, BaseDatos[posicion].Municipio, BaseDatos[posicion].Seccion);
    printf("|  ------------ Localidad: %-4s  Emision: %-4i  Vigencia: %-4i  |\n",BaseDatos[posicion].Localidad, BaseDatos[posicion].Emision, BaseDatos[posicion].Vigencia);
    printf("|                                                               |\n");
    printf("-----------------------------------------------------------------\n");
    
    printf("\n\n");
}

int Menu()
{
    
    int opcion = 0;
    int p = 0;
    
  printf("\t\tMENU \n\n");
    printf("1. Alta Registro.\n");
    printf("2. Baja de Registro.\n");
    printf("4. Ordena Registro. \n");
    printf("5. Imprimir registro.\n");
    printf("6. Imprimir registros.\n");
    printf("7. Guarda Registro. \n");
    printf("8. Restaura Registro. \n");
    printf("9. Salir.\n");
    printf("Opcion: ");
    
    scanf("%d", &opcion);
    
    switch (opcion)
    {
        case 1:
            printf("\n\t Alta Registro");
            printf("\n\t En que posicion deseas que se guarde [ 0 - 9] : ");
            scanf("%d",&p);
            altaRegistro(p);
            break;
            
        case 2:
            printf("\n\tBajas\n");
            bajas();
            break;
        case 4:
            printf("\n\tOrdenar la Base de Datos");
            ordenaBase();
            break;
        case 5:
            printf("\nImprime Registro");
            printf("\nQue credencial deseas imprimir [0-9]: ");
            scanf("%d",&p);
            imprimeRegistro(p);
            break;
        case 6:
            printf("\n Imprime registros");
            printf("Desde que credencial desea imprimir [0-9]: ");
            scanf("%d",&p);
            imprimeRegistros(p);
            break;
        case 7:
            printf("\nGuarda Registro\n");
            guardarBaseDatos();
            break;
            
        case 8:
            printf("\nRestaura Registro");
            restaurarBaseDatos();
            break;
            
        case 9:
            break;
            
        default :
            printf("\nOpcion invalida\n");
                   Menu();
            break;
    }
    
    return opcion;
}


int main()
{
    int opcion = 0;
    
    inicializa();
    
    while (opcion!=9)
    {
        opcion = Menu();
    }
    

   
    return 0;
}
