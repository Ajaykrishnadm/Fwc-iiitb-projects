
//declaring the blink module
module helloworldfpga(
    output wire redled,
    output wire greenled,
    output wire blueled
);
    wire clk;

    qlal4s3b_cell_macro u_qlal4s3b_cell_macro (
        .Sys_Clk0 (clk),
    );

    reg[26:0] delay;
     reg	led;
always@(posedge clk) begin
delay = delay+1; 
  
if(delay > 20000000) //blink delay in decimal
begin
delay=27'b0;
led=!led; //reset the led
end
end
  
assign redled = led; //If you want to change led colour to red, 
endmodule
//end of the module




