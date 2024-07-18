//
//  basededatos.h
//  proyecto estructuras 2
//
//  Created by Arturo Roldan sanchez on 11/22/18.
//  Copyright © 2018 Arturo Roldan sanchez. All rights reserved.
//

#ifndef basededatos_h
#define basededatos_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
struct INE
{
    
    char Nombre[30];
    char ApellidoPat[15];
    char ApellidoMat[15];
    char Domicilio[30];
    char ClaveE[20];
    char CURP[20];
    char Localidad[4];
    int Registro, Estado, Municipio, Seccion, Emision, Vigencia;
    
} BaseDatos[SIZE];

#endif /* basededatos_h */
