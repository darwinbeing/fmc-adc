`include "vme64x_bfm.svh"
`include "svec_vme_buffers.svh"
`include "fmc.svh"
`include "ddr3.svh"

module main;

   reg rst_n = 0;
   reg clk_20m = 0;

   always #25ns clk_20m <= ~clk_20m;

   initial begin
      repeat(20) @(posedge clk_20m);
      rst_n = 1;
   end

   IVME64X VME(rst_n);

   `DECLARE_VME_BUFFERS(VME.slave);

   `DECLARE_DDR(0);
   `DECLARE_DDR(1);

   `DECLARE_FMC(0);
   `DECLARE_FMC(1);

   logic [1:0] fp_led_line_oen;
   logic [1:0] fp_led_line;
   logic [3:0] fp_led_column;
   wire        carrier_scl;
   wire        carrier_sda;
   wire        carrier_one_wire;

   svec_top_fmc_adc_100Ms
     #(
       .g_SIMULATION("TRUE"),
       .g_CALIB_SOFT_IP("FALSE")
       )
   DUT
     (
      .clk_20m_vcxo_i(clk_20m),
      .rst_n_i(rst_n),

      .fp_led_line_oen_o(fp_led_line_oen),
      .fp_led_line_o(fp_led_line),
      .fp_led_column_o(fp_led_column),
      .carrier_scl_b(carrier_scl),
      .carrier_sda_b(carrier_sda),
      .pcbrev_i(5'b00001),
      .carrier_one_wire_b(carrier_one_wire),

      `WIRE_DDR(0)
      `WIRE_DDR(1)

      `WIRE_FMC(0)
      `WIRE_FMC(1)

      `WIRE_VME_PINS(8) // slot number in parameter
      );

   task automatic init_vme64x_core(ref CBusAccessor_VME64x acc);
      uint64_t rv;

      /* map func0 to 0x80000000, A32 */

      acc.write('h7ff63, 'h80, A32|CR_CSR|D08Byte3);
      acc.write('h7ff67, 0, CR_CSR|A32|D08Byte3);
      acc.write('h7ff6b, 0, CR_CSR|A32|D08Byte3);
      acc.write('h7ff6f, 36, CR_CSR|A32|D08Byte3);
      acc.write('h7ff33, 1, CR_CSR|A32|D08Byte3);
      acc.write('h7fffb, 'h10, CR_CSR|A32|D08Byte3); /* enable module (BIT_SET = 0x10) */


      acc.set_default_modifiers(A32 | D32 | SINGLE);
   endtask // init_vme64x_core


   initial begin
      uint64_t d;
      uint32_t wr_data;

      int i, result;

      CBusAccessor_VME64x acc = new(VME.master);


      #20us;
      init_vme64x_core(acc);


      acc.write('h2200, 'h0, A32|SINGLE|D32);
      for(i=0; i<5; i++)
        begin
           acc.read('h2100, d, A32|SINGLE|D32);
           $display("Read %d: 0x%x\n", i, d);
        end

      acc.write('h2200, 'h0, A32|SINGLE|D32);
      for(i=0; i<2; i++)
        begin
           wr_data = i;
           acc.write('h2100, wr_data, A32|SINGLE|D32);
           $display("Write %d: 0x%x\n", i, wr_data);
        end

      acc.write('h2200, 'h0, A32|SINGLE|D32);
      for(i=0; i<5; i++)
        begin
           acc.read('h2100, d, A32|SINGLE|D32);
           $display("Read %d: 0x%x\n", i, d);
        end

   end


endmodule // main



