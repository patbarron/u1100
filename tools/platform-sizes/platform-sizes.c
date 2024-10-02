/*
 * u1100 - Sperry Univac 1100 Series Mainframe Emulator
 *         Copyright (c) 2024 Patrick Barron
 *         All rights reserved.
 *
 *         This software is licensed under the Clear BSD License.  Refer
 *         to the file "LICENSE" in the top level directory of this
 *         project for license terms.
 */

#include <stdio.h>

void main()
{
   printf("Size of char is %d\n",sizeof(char));
   printf("Size of short is %d\n",sizeof(short));
   printf("Size of int is %d\n",sizeof(int));
   printf("Size of long is %d\n",sizeof(long));
   printf("Size of long long is %d\n",sizeof(long long));
   printf("Size of float is %d\n",sizeof(float));
   printf("Size of double is %d\n",sizeof(double));
   printf("Size of char * is %d\n",sizeof(char *));
   printf("Size of int * is %d\n",sizeof(int *));
}
