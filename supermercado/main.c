//
//  main.c
//  supermercado
//
//  Created by Arturo Roldan sanchez on 10/22/18.
//  Copyright © 2018 Arturo Roldan sanchez. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 500
int posterior =0,delantera=0;

int cola[SIZE];

int isEmpty(){
    if(posterior ==delantera)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void insert(int dato){
    if(posterior< SIZE)
    {
        cola[posterior]=dato;
        posterior++;
    }
}

int remueve(void)
{
    int dato;
    if(!isEmpty())
    {
        dato=cola[delantera];
        delantera++;
        return dato;
    }
    return '\0';
}

int simulacion()
{
srand(time(0));
    int tiempo=0,inicio=0;
    inicio=rand()%4+1;
    int siguienteC=rand()%4+1+tiempo+inicio;
    int servicio=inicio;
    int maxQ=0,maxw=0,temp=0,temp1=0;
    
    while(tiempo<720)
    {
        printf("Tiempo : %d :Atención por el momento\n",tiempo+1);
        if(tiempo==inicio)
        {
            servicio=rand()%4+1;
            printf("En servicio: %d\n",servicio);
            siguienteC=rand()%4+1+tiempo;
            insert(tiempo);
        }
        else if (tiempo == siguienteC)
        {
            printf("Llego cliente a la cola\n");
            insert(tiempo);
            siguienteC=rand()%4+1+tiempo;
            printf("Tiempo de espera :%d\n",siguienteC-tiempo);
        }
        if(servicio ==0)
        {
            printf("Cliente atendido!\n");
            servicio=rand()%4+1;
            printf("Tiempo de servicio: %d\n",servicio);
            insert(temp);
            temp1=temp;
            if(temp1>maxw)
                maxw=temp1;
        }
        if(remueve()>maxQ)
            maxQ=remueve();
        servicio--;
        temp++;
        tiempo++;
    }
    printf("Todos los clientes han sido sacados!\n\n");
    printf("Larga espera: %d\n",tiempo-maxw);
    printf("Mayoria de clientes en fila: %d\n",maxQ);
    printf("Tiempo promedio de atención al cliente %d\n",(720-tiempo)/60);
    return 0;
}
    
int main(int argc, const char * argv[]) {
    simulacion();
    

    return 0;

}
