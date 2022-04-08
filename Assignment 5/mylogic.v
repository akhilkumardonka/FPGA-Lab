/*BCD to 7 segment display decoder
January 21,2021
Code by G V V Sharma
Released under GNU GPL
*/

//declaring the blink module
module helloworldfpga(

input  wire A, //MSB bit input
input  wire B,
input  wire C,
input  wire D, //LSB bit input

output wire a,
output wire b,
output wire c,
output wire d,
output wire e,
output wire f,
output wire g

);

reg W,X,Y,Z,out;

//Display Decoder
always @(*)
begin

out = ((!(B&C))&(!D))|(B&C&D);

if(out == 1)
	begin
		Z=0;
		Y=0;
		X=0;
		W=1;
	end
else
	begin
		Z=0;
		Y=0;
		X=0;
		W=0;
	end

a=(!Z&!Y&!X&W)|(!Z&Y&!X&!W);
b=(!Z&Y&!X&W)|(!Z&Y&X&!W);
c=(!Z&!Y&X&!W);
d=(!Z&!Y&!X&W)|(!Z&Y&!X&!W)|(!Z&Y&X&W);
e=(!Z&!Y&!X&W)|(!Z&!Y&X&W)|(!Z&Y&!X&!W)|(!Z&Y&!X&W)|(!Z&Y&X&W)|(Z&!Y&!X&W);
f=(!Z&!Y&!X&W)|(!Z&!Y&X&!W)|(!Z&!Y&X&W)|(!Z&Y&X&W);
g=(!Z&!Y&!X&!W)|(!Z&!Y&!X&W)|(!Z&Y&X&W);

end
endmodule
//end of the module
