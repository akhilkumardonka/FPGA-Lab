#include <avr/io.h>
#include <util/delay.h>


int main (void)
{
  DDRB    |= ((1 << DDB5));
  while (1) {
unsigned char G;
    unsigned char X[8] = { 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01};
    unsigned char Y[8] = { 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01};
    unsigned char Z[8] = { 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01};


    for (int i = 0; i < 8; i++) {
        // Using Nand Logic
        int p= (X[i]&&Y[i]&&Z[i]);
        int q= (!(Z[i]))&&(!(X[i]&&Y[i]));
        int O=(p||q);

if(O==0) {
    PORTB = ((0 <<  PB5));}
else{PORTB = ((1 <<  PB5));}
    _delay_ms(1000);
    }
  }

  return 0;

}
