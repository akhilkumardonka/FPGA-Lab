#include <Arduino.h>

unsigned char num ;                             	//input number
unsigned char _U=0x00,_V=0x00,_W=0x00,_X=0x00;      	//binary inputs
unsigned char one = 0x01;
unsigned char Out;                         	//outputs
char buffer[40];

void disp_num(unsigned char A, unsigned char B, unsigned char C, unsigned char D){

  unsigned char a,b,c,d,e,f,g;
  a = ~( ((A)&(~B)&(~C)) | ((~A)&(B)&(D)) | ((A)&(~D)) | ((~A)&(C)) | ((B)&(C)) | ((~B)&(~D)) );
  b = ~( ((~A)&(~C)&(~D)) | ((~A)&(C)&(D)) | ((A)&(~C)&(D)) | ((~B)&(~C)) | ((~B)&(~D)) );
  c = ~( ((~B)&(~C)) | ((~A)&(D)) | ((D)&(~C)) | ((~A)&(B)) | ((A)&(~B)) );
  d = ~( ((~A)&(~B)&(~D)) | ((~B)&(C)&(D)) | ((B)&(~C)&(D)) | ((B)&(C)&(~D)) | ((A)&(~C)) );
  e = ~( ((~D)&(~B)) | ((C)&(~D)) | ((A)&(C)) | ((A)&(B)) );
  f = ~( ((~A)&(B)) | ((~C)&(~D)) | ((B)&(~D)) | ((A)&(~B)) | ((A)&(C)) );
  g = ~( ((~A)&(B)&(~C)) | ((C)&(~B)) | ((C)&(~D)) | ((A)&(~B)) | ((A)&(D)) );

  digitalWrite(2,one&a);
  digitalWrite(3,one&b);
  digitalWrite(4,one&c);
  digitalWrite(5,one&d);
  digitalWrite(6,one&e);
  digitalWrite(7,one&f);
  digitalWrite(8,one&g);

}

void setup() {
  pinMode(2,OUTPUT);    //a
  pinMode(3,OUTPUT);    //b
  pinMode(4,OUTPUT);    //c
  pinMode(5,OUTPUT);    //d
  pinMode(6,OUTPUT);    //e
  pinMode(7,OUTPUT);    //f
  pinMode(8,OUTPUT);    //g
  pinMode(13,OUTPUT);   //output
}

unsigned char NAND(unsigned char X, unsigned char Y){ return ~(X&Y); } //NAND function

unsigned char Output(unsigned char U, unsigned char V, unsigned char W, unsigned char X){ return ((~(W&V))&(~X)) | (V&W&X); } //Out function

void loop() {

  for (num = 0x00; num<0x08; num++){
        //loop to iterate through all usecases
        delay(2000);

        _U = num>>3;    _V = num>>2;    _W = num>>1;    _X = num>>0; //changing the inputs , D is LSB
        disp_num(_U, _V, _W, _X);
        Out = Output(_U, _V, _W, _X);          //NAND gate equivalent Boolean Function
	
        digitalWrite(13,one&Out); //Output Org, Nor

    }
}
