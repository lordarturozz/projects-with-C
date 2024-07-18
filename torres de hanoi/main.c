//
//  main.c
//  torres de hanoi
//
//  Created by Arturo Roldan sanchez on 21/09/18.
//  Copyright © 2018 Arturo Roldan sanchez. All rights reserved.
//

#include <stdio.h>
#include "hanoi.h"


int main()
{
    char A,B,C;
    int n;
    printf("Ingrese los anillos:\n");
    scanf("%d",&n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
