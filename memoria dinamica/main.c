//
//  main.c
//  memoria dinamica
//
//  Created by Arturo Roldan sanchez on 11/8/18.
//  Copyright © 2018 Arturo Roldan sanchez. All rights reserved.
//

#include <stdio.h>


int main(int argc, const char * argv[]) {
    int *ptr;
    ptr = (int *)malloc(4);
    printf("Dame un número: \n");
    scanf("%d",ptr);
    printf("el numero es : %d \n",*ptr);
    printf("La direccion del numero es : %p \n",ptr);
    return 0;
}
