`ifdef JTFRAME_SRAM
    output    [16:0]  sram_addr,
    output    [15:0]  sram_din,
    input     [15:0]  sram_dout,
    output            sram_wen,
    output    [ 1:0]  sram_dsn,
    input             sram_ok,
`endif
    input cen_arm, // 7000000 = 56000000*1/8 Hz 
    input cen_oki1, // 1000000 = 56000000*1/56 Hz 
    input cen_oki2, // 1000000 = 56000000*1/56 Hz 
    input cen_oki2b, // 2000000 = 56000000*1/28 Hz 

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
`ifdef JTFRAME_SDRAM_XL
    input   [26:0]  ioctl_addr,
`else
    input   [25:0]  ioctl_addr,
`endif
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
    output   [1:0] mramh_we,
    output   [10:1] palhrw_addr,
    input   [15:0] oramrw_dout,
    output   [24:0] main_post_addr,
    input   [15:0] palh2palhrw_data,
    output   [11:1] obj_oaddr,
    input   [15:0] rs2_dout,
    output   [11:1] rs2rw_addr,
    output   [13:1] mram_addr,
    input   [15:0] palh_dout,
    output   [11:1] oramrw_addr,
    output   [15:0] cpu_dout,
    output   [11:1] pf1_rsa,
    input   [15:0] oram_dout,
    input   [15:0] rs12rs1rw_data,
    output   [10:1] pal_rd,
    input   [15:0] mramh_dout,
    input   [15:0] palrw_dout,
    input   [15:0] rs1_dout,
    output   [11:1] rs1rw_addr,
    output   [11:1] pf2_rsa,
    output   [15:0] cpu_dhi,
    input   [15:0] mram_dout,
    input   [15:0] pal_dout,
    output   [10:1] palrw_addr,
    input   [15:0] rs22rs2rw_data,
    input   [24:0] main_pre_addr,
    output   [1:0] mram_we,
    // Buses to BRAM

    
    
    output   [ 1:0] palrw_we, // Dual port for palrw
    
    output   [ 1:0] palhrw_we, // Dual port for palhrw
    
    output   [ 1:0] oramrw_we, // Dual port for oramrw
    
    output   [ 1:0] rs1rw_we, // Dual port for rs1rw
    
    output   [ 1:0] rs2rw_we, // Dual port for rs2rw
    
    // Buses to SDRAM
    input    [31:0] main_data,
    output          main_cs,
    output   [19:2] main_addr,
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
    output   [18:0] oki1_addr,
    input           oki1_ok,

    input    [ 7:0] oki2_data,
    output          oki2_cs,
    output   [20:0] oki2_addr,
    input           oki2_ok,

    input    [31:0] obj_data,
    output          obj_cs,
    output   [22:2] obj_addr,
    input           obj_ok
