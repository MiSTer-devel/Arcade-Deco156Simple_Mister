`ifdef JTFRAME_SRAM
    output    [16:0]  sram_addr,
    output    [15:0]  sram_din,
    input     [15:0]  sram_dout,
    output            sram_wen,
    output    [ 1:0]  sram_dsn,
    input             sram_ok,
`endif
    input cen_arm, // 7000000 = 48000000*7/48 Hz 
    input cen_oki1, // 1000000 = 48000000*1/48 Hz 
    input cen_oki2, // 1000000 = 48000000*1/48 Hz 

    // Audio channels
    
    output signed [13:0] pcm1,
    output signed [13:0] pcm2,
    // Memory ports
`ifdef JTFRAME_SDRAM_XL
    input   [23:0]  prog_addr,
`elsif JTFRAME_SDRAM_LARGE
    input   [22:0]  prog_addr,
`else
    input   [21:0]  prog_addr,
`endif
    input   [ 7:0]  prog_data,
    input           prog_we,
    input   [ 1:0]  prog_ba,
    input   [25:0]  ioctl_addr,
    input           prom_we,
`ifdef JTFRAME_SDRAM_XL
    output reg [23:0] post_addr,
`elsif JTFRAME_SDRAM_LARGE
    output reg [22:0] post_addr,
`else
    output reg [21:0] post_addr,
`endif

    output reg [ 7:0] post_data,

`ifdef JTFRAME_HEADER
    input           header,
`endif
`ifdef JTFRAME_IOCTL_RD
    input           ioctl_wr,
    output   [ 7:0] ioctl_din,
    input    [ 7:0] ioctl_dout, `endif
    input           ioctl_ram,
    input           ioctl_cart,
    // Explicit ports
    // Buses to BRAM

    // Buses to SDRAM
    input    [31:0] main_data,
    output          main_cs,
    output   [18:2] main_addr,
    input           main_ok,

    input    [15:0] gfx1a_data,
    output          gfx1a_cs,
    output   [20:1] gfx1a_addr,
    input           gfx1a_ok,

    input    [15:0] gfx1b_data,
    output          gfx1b_cs,
    output   [20:1] gfx1b_addr,
    input           gfx1b_ok,

    input    [15:0] gfx1c_data,
    output          gfx1c_cs,
    output   [20:1] gfx1c_addr,
    input           gfx1c_ok,

    input    [15:0] gfx1d_data,
    output          gfx1d_cs,
    output   [20:1] gfx1d_addr,
    input           gfx1d_ok,

    input    [ 7:0] oki1_data,
    output          oki1_cs,
    output   [17:0] oki1_addr,
    input           oki1_ok,

    input    [ 7:0] oki2_data,
    output          oki2_cs,
    output   [20:0] oki2_addr,
    input           oki2_ok,

    input    [31:0] obj_data,
    output          obj_cs,
    output   [22:2] obj_addr,
    input           obj_ok
