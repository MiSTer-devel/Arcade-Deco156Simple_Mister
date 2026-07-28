/*  This file is part of JTFRAME.
    JTFRAME program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    JTFRAME program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with JTFRAME.  If not, see <http://www.gnu.org/licenses/>.

    Author: Jose Tejada Gomez. Twitter: @topapate
    Version: 1.0
    Date: 6-12-2022 */

`ifdef JTFRAME_PXLCLK
module jtframe_pxlcen(
    input   clk,
    output  pxl_cen,
    output  pxl2_cen
);

    // PXLCLK table. Integer codes 6/8/12 are the legacy short form
    // (=> integer MHz @ clk48). Codes ≥50 are "rate * 10" so we can
    // express tenths-of-MHz fractional rates needed by some boards
    // whose real pixel clock isn't a clean divisor of 48 MHz.
    //
    //   PXLCLK | n  | m  | pxl_cen @ clk48 | notes
    //   -------+----+----+-----------------+-------------
    //      6   |  1 |  4 |    6.00 MHz     | legacy default
    //      8   |  1 |  3 |    8.00 MHz     | legacy
    //     12   |  1 |  2 |   12.00 MHz     | legacy
    //     55   | 11 | 48 |    5.50 MHz     | cabal
    //     70   |  7 | 24 |    7.00 MHz     | taitob (TC0180VCU ~6.79 MHz)
    //
    // pxl_cen rate = clk * n / (2 * m), pxl2_cen rate = clk * n / m.
    // m is shifted left by 1 when JTFRAME_SDRAM96 doubles clk to 96 MHz,
    // keeping the absolute pxl_cen rate constant.
    //
    // Adding a new rate: pick n/m so that 48*n/(2*m) is the wanted
    // pxl_cen frequency, then add the code to N, M, and the initial
    // check below. Keep WC ≥ ceil(log2(max(n,m)))+1.
    localparam PXLCLK = `JTFRAME_PXLCLK,
               CLK    = `ifdef JTFRAME_SDRAM96 96 `else 48 `endif,
               N      = (PXLCLK==55 ? 11 :
                         PXLCLK==70 ?  7 :
                                       1),
               M      = (PXLCLK==55 ? 48 :
                         PXLCLK==70 ? 24 :
                         PXLCLK==12 ?  2 :
                         PXLCLK==8  ?  3 :
                                       4) << (CLK==96 ? 1:0);

    initial begin
        if( PXLCLK!=8 && PXLCLK!=6 && PXLCLK!=55 && PXLCLK!=70 ) begin
            $display("JTFRAME_PXLCLK is set to %d. But that value isn't supported yet.",PXLCLK);
            $finish;
        end else begin
            $display("jtframe_pxlcen: using %0d as clock divider", M[3:0]);
        end
    end

    // WC=8 sized to fit the fractional codes (m up to 48, room to grow
    // without re-touching the width).
    jtframe_frac_cen #(.WC(8),.W(2)) u_cen(
        .clk    ( clk       ),    // 48 or 96 MHz
        .n      ( N[7:0]    ),
        .m      ( M[7:0]    ),
        .cen    ( { pxl_cen, pxl2_cen } ),
        .cenb   (           )
    );

endmodule
`endif
