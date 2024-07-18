//
//  hanoi.h
//  torres de hanoi
//
//  Created by Arturo Roldan sanchez on 21/09/18.
//  Copyright © 2018 Arturo Roldan sanchez. All rights reserved.
//

#ifndef hanoi_h
#define hanoi_h
void hanoi( int n, char desde, char hasta, char aux)
{
    if(n> 0)
    {
        hanoi(n-1,desde,aux,hasta);
        printf("Se va a mover el anillo %d de la torre %c hasta la torre %c\n",n,desde,hasta);
        hanoi(n-1,aux,hasta,desde);
    }
}

#endif /* hanoi_h */
