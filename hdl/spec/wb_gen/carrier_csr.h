/*
  Register definitions for slave core: Carrier control and status registers

  * File           : carrier_csr.h
  * Author         : auto-generated by wbgen2 from carrier_csr.wb
  * Created        : Wed Apr 23 10:05:23 2014
  * Standard       : ANSI C

    THIS FILE WAS GENERATED BY wbgen2 FROM SOURCE FILE carrier_csr.wb
    DO NOT HAND-EDIT UNLESS IT'S ABSOLUTELY NECESSARY!

*/

#ifndef __WBGEN2_REGDEFS_CARRIER_CSR_WB
#define __WBGEN2_REGDEFS_CARRIER_CSR_WB

#include <inttypes.h>

#if defined( __GNUC__)
#define PACKED __attribute__ ((packed))
#else
#error "Unsupported compiler?"
#endif

#ifndef __WBGEN2_MACROS_DEFINED__
#define __WBGEN2_MACROS_DEFINED__
#define WBGEN2_GEN_MASK(offset, size) (((1<<(size))-1) << (offset))
#define WBGEN2_GEN_WRITE(value, offset, size) (((value) & ((1<<(size))-1)) << (offset))
#define WBGEN2_GEN_READ(reg, offset, size) (((reg) >> (offset)) & ((1<<(size))-1))
#define WBGEN2_SIGN_EXTEND(value, bits) (((value) & (1<<bits) ? ~((1<<(bits))-1): 0 ) | (value))
#endif


/* definitions for register: Carrier type and PCB version */

/* definitions for field: PCB revision in reg: Carrier type and PCB version */
#define CARRIER_CSR_CARRIER_PCB_REV_MASK      WBGEN2_GEN_MASK(0, 4)
#define CARRIER_CSR_CARRIER_PCB_REV_SHIFT     0
#define CARRIER_CSR_CARRIER_PCB_REV_W(value)  WBGEN2_GEN_WRITE(value, 0, 4)
#define CARRIER_CSR_CARRIER_PCB_REV_R(reg)    WBGEN2_GEN_READ(reg, 0, 4)

/* definitions for field: Reserved register in reg: Carrier type and PCB version */
#define CARRIER_CSR_CARRIER_RESERVED_MASK     WBGEN2_GEN_MASK(4, 12)
#define CARRIER_CSR_CARRIER_RESERVED_SHIFT    4
#define CARRIER_CSR_CARRIER_RESERVED_W(value) WBGEN2_GEN_WRITE(value, 4, 12)
#define CARRIER_CSR_CARRIER_RESERVED_R(reg)   WBGEN2_GEN_READ(reg, 4, 12)

/* definitions for field: Carrier type in reg: Carrier type and PCB version */
#define CARRIER_CSR_CARRIER_TYPE_MASK         WBGEN2_GEN_MASK(16, 16)
#define CARRIER_CSR_CARRIER_TYPE_SHIFT        16
#define CARRIER_CSR_CARRIER_TYPE_W(value)     WBGEN2_GEN_WRITE(value, 16, 16)
#define CARRIER_CSR_CARRIER_TYPE_R(reg)       WBGEN2_GEN_READ(reg, 16, 16)

/* definitions for register: Status */

/* definitions for field: FMC presence in reg: Status */
#define CARRIER_CSR_STAT_FMC_PRES             WBGEN2_GEN_MASK(0, 1)

/* definitions for field: GN4142 core P2L PLL status in reg: Status */
#define CARRIER_CSR_STAT_P2L_PLL_LCK          WBGEN2_GEN_MASK(1, 1)

/* definitions for field: System clock PLL status in reg: Status */
#define CARRIER_CSR_STAT_SYS_PLL_LCK          WBGEN2_GEN_MASK(2, 1)

/* definitions for field: DDR3 calibration status in reg: Status */
#define CARRIER_CSR_STAT_DDR3_CAL_DONE        WBGEN2_GEN_MASK(3, 1)

/* definitions for register: Control */

/* definitions for field: Green LED in reg: Control */
#define CARRIER_CSR_CTRL_LED_GREEN            WBGEN2_GEN_MASK(0, 1)

/* definitions for field: Red LED in reg: Control */
#define CARRIER_CSR_CTRL_LED_RED              WBGEN2_GEN_MASK(1, 1)

/* definitions for field: DAC clear in reg: Control */
#define CARRIER_CSR_CTRL_DAC_CLR_N            WBGEN2_GEN_MASK(2, 1)

/* definitions for register: Reset Register */

/* definitions for field: State of the reset line in reg: Reset Register */
#define CARRIER_CSR_RST_FMC0_N                WBGEN2_GEN_MASK(0, 1)

PACKED struct CARRIER_CSR_WB {
  /* [0x0]: REG Carrier type and PCB version */
  uint32_t CARRIER;
  /* [0x4]: REG Status */
  uint32_t STAT;
  /* [0x8]: REG Control */
  uint32_t CTRL;
  /* [0xc]: REG Reset Register */
  uint32_t RST;
};

#endif
