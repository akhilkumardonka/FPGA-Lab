#include <stdio.h>

int main(){
    unsigned char G; //output
    unsigned char one = 0x01;//used for displaying the output in bit
    unsigned char  U=0x01,V=0x00,W=0x00; //inputs in hex

    G = (U | (~W))&(V | (~W))&((~U) | (~V) | W);

    printf("%x%x%x",one&U,one&V,one&W);
    printf(" ");
    printf("%x\n" ,one&G);
    return 0;
}