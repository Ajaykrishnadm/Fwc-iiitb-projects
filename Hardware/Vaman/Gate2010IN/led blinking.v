module led_blink_xor_nand(
    input X,        // Input switch 1
    input Y,        // Input switch 2
    output LED      // LED output
);
    wire Xn, Yn, t1, t2;

    // XOR gate built using NAND gates
    nand (Xn, X, X);     // X'
    nand (Yn, Y, Y);     // Y'
    nand (t1, X, Yn);    // (X * Y')'
    nand (t2, Y, Xn);    // (Y * X')'
    nand (LED, t1, t2);  // Final XOR output -> LED

endmodule
