/*!
 * \file
 * \brief
 * \author
 * \date
 */
#ifndef __STM32WB55_H
#define __STM32WB55_H

#include <stdint.h>

//=============================================================================
// Memory map definitions
//=============================================================================

#define USER_FLASH_BASE 0x08000000
#define SRAM2_MIRROR_BASE 0x10000000
#define FLASH_BOOTLOADER_BASE 0x1FFF0000
#define OTP_BASE 0x1FFF7000
#define FLASH_OPTIONS_BASE 0x1FFF8000
#define SRAM1_BASE 0x20000000
#define SRAM2A_BASE 0x20030000
#define SRAM2B_BASE 0x20038000
#define TIM2_BASE 0x40000000
#define LCD_BASE 0x40002400
#define RTC_BASE 0x40002800
#define WWDG_BASE 0x40002C00
#define IWDG_BASE 0x40003000
#define SPI2_BASE 0x40003800
#define I2C1_BASE 0x40005400
#define I2C3_BASE 0x40005C00
#define CRS_BASE 0x40006000
#define USBFS_BASE 0x40006800
#define USBSRAM_BASE 0x40006C00
#define LPTIM1_BASE 0x40007C00
#define LPUART1_BASE 0x40008000
#define LPTIM2_BASE 0x40009400
#define SYSCFG_BASE 0x40010000
#define VREFBUF_BASE 0x40010030
//#define SYSCFG2_BASE 0x40010100
#define COMP_BASE 0x40010200
#define TIM1_BASE 0x40012C00
#define SPI1_BASE 0x40013000
#define USART1_BASE 0x40013800
#define TIM16_BASE 0x40014400
#define TIM17_BASE 0x40014800
#define SAI1_BASE 0x40015400
#define DMA1_BASE 0x40020000
#define DMA2_BASE 0x40020400
#define DMAMUX_BASE 0x40020800
#define CRC_BASE 0x40023000
#define TSC_BASE 0x40024000
#define GPIOA_BASE 0x48000000
#define GPIOB_BASE 0x48000400
#define GPIOC_BASE 0x48000800
#define GPIOD_BASE 0x48000C00
#define GPIOE_BASE 0x48001000
#define GPIOH_BASE 0x48001C00
#define ADC_BASE 0x50040000
#define AES1_BASE 0x50060000
#define RCC_BASE 0x58000000
#define PWR_BASE 0x58000400
#define EXTI_BASE 0x58000800
#define IPCC_BASE 0x58000C00
#define TRNG_BASE 0x58001000
#define HSEM_BASE 0x58001400
#define AES2_BASE 0x58001800
#define PKA_BASE 0x58002000
#define PKARAM_BASE 0x58002400
#define FLASH_BASE 0x58004000
#define BLECTRL_BASE 0x60000000
#define RADIOCTRL_BASE 0x60000400
#define ZIGBEE_BASE 0x60001000
#define QUADSPI_FLASH_BASE 0x90000000
#define QUADSPI_BASE 0xA0001000

//==============================================================================
// Structure definitions
//==============================================================================

/*!
 * \brief
 */
typedef enum {
	dummy
} interrupt_nums; 

/*!
 * \brief RCC register structure
 */
typedef struct {
	volatile uint32_t CR; // 0x00
	volatile uint32_t ICSCR; // 0x04
	volatile uint32_t CFGR; // 0x08
	volatile uint32_t PLL_CFGR; // 0x0C
	volatile uint32_t PLLSAI1_CFGR; // 0x10
	uint32_t __reserved_1; // 0x14
	volatile uint32_t CIER; // 0x18
	volatile uint32_t CIFR; // 0x1C
	volatile uint32_t CICR; // 0x20
	volatile uint32_t SMPSCR; // 0x24
	volatile uint32_t AHB1RSTR; // 0x28
	volatile uint32_t AHB2RSTR; // 0x2C
	volatile uint32_t AHB3RSTR; // 0x30
	uint32_t __reserved_2; // 0x34
	volatile uint32_t APB1RSTR1; // 0x38
	volatile uint32_t APB1RSTR2; // 0x3C
	volatile uint32_t APB2RSTR; // 0x40
	volatile uint32_t APB3RSTR; // 0x44
	volatile uint32_t AHB1ENR; // 0x48
	volatile uint32_t AHB2ENR; // 0x4C
	volatile uint32_t AHB3ENR; // 0x50
	uint32_t __reserved_3; // 0x54
	volatile uint32_t APB1ENR1; // 0x58
	volatile uint32_t APB1ENR2; // 0x5C
	volatile uint32_t APB2ENR; // 0x60
	uint32_t __reserved_4; // 0x64
	volatile uint32_t AHB1SMENR; // 0x68
	volatile uint32_t AHB2SMENR; // 0x6C
	volatile uint32_t AHB3SMENR; // 0x70
	uint32_t __reserved_5; // 0x74
	volatile uint32_t APB1SMENR1; // 0x78
	volatile uint32_t APB1SMENR2; // 0x7C
	volatile uint32_t APB2SMENR; // 0x80
	uint32_t __reserved_6; // 0x84
	volatile uint32_t CCIPR; // 0x88
	uint32_t __reserved_7; // 0x8C
	volatile uint32_t BDCR; // 0x90
	volatile uint32_t CSR; // 0x94
	volatile uint32_t CRRCR; // 0x98
	volatile uint32_t HSECR; // 0x9C
	uint32_t __reserved_8; // 0xA0
	uint32_t __reserved_9; // 0xA4
	uint32_t __reserved_10; // 0xA8
	uint32_t __reserved_11; // 0xAC
	uint32_t __reserved_12; // 0xB0
	uint32_t __reserved_13; // 0xB4
	uint32_t __reserved_14; // 0xB8
	uint32_t __reserved_15; // 0xBC
	uint32_t __reserved_16; // 0xC0
	uint32_t __reserved_17; // 0xC4
	uint32_t __reserved_18; // 0xC8
	uint32_t __reserved_19; // 0xCC
	uint32_t __reserved_20; // 0xD0
	uint32_t __reserved_21; // 0xD4
	uint32_t __reserved_22; // 0xD8
	uint32_t __reserved_23; // 0xDC
	uint32_t __reserved_24; // 0xE0
	uint32_t __reserved_25; // 0xE4
	uint32_t __reserved_26; // 0xE8
	uint32_t __reserved_27; // 0xEC
	uint32_t __reserved_28; // 0xF0
	uint32_t __reserved_29; // 0xF4
	uint32_t __reserved_30; // 0xF8
	uint32_t __reserved_31; // 0xFC
	uint32_t __reserved_32; // 0x100
	uint32_t __reserved_33; // 0x104
	volatile uint32_t EXTCFGR; // 0x108
	uint32_t __reserved_34; // 0x10C
	uint32_t __reserved_35; // 0x110
	uint32_t __reserved_36; // 0x114
	uint32_t __reserved_37; // 0x118
	uint32_t __reserved_38; // 0x11C
	uint32_t __reserved_39; // 0x120
	uint32_t __reserved_40; // 0x124
	uint32_t __reserved_41; // 0x128
	uint32_t __reserved_42; // 0x12C
	uint32_t __reserved_43; // 0x130
	uint32_t __reserved_44; // 0x134
	uint32_t __reserved_45; // 0x138
	uint32_t __reserved_46; // 0x13C
	uint32_t __reserved_47; // 0x140
	uint32_t __reserved_48; // 0x144
	volatile uint32_t C2AHB1ENR; // 0x148
	volatile uint32_t C2AHB2ENR; // 0x14C
	volatile uint32_t C2AHB3ENR; // 0x150
	uint32_t __reserved_49; // 0x154
	volatile uint32_t C2APB1ENR1; // 0x158
	volatile uint32_t C2APB1ENR2; // 0x15C
	volatile uint32_t C2APB2ENR; // 0x160
	volatile uint32_t C2APB3ENR; // 0x164
	volatile uint32_t C2AHB1SMENR; // 0x168
	volatile uint32_t C2AHB2SMENR; // 0x16C
	volatile uint32_t C2AHB3SMENR; // 0x170
	uint32_t __reserved_50; // 0x174
	volatile uint32_t C2APB1SMENR1; // 0x178
	volatile uint32_t C2APB1SMENR2; // 0x17C
	volatile uint32_t C2APB2SMENR; // 0x180
	volatile uint32_t C2APB3SMENR; // 0x184
} RCC_Regs_t;
#define RCC ((RCC_Regs_t *)RCC_BASE)

/*!
 * \brief
 */
//typedef enum {
//	RCC_CR_MSION = (1 << 0),
//} RCC_CR_Regs_t;

/*!
 * \brief
 */
//typedef enum {
//	RCC_ICSCR_HSITRIM_6 = (1 << 30)
//} RCC_ICSCR_Regs_t;






/*!
 * \brief
 */
typedef enum {
	RCC_AHB2ENR_GPIOAEN = (1 << 0),
	RCC_AHB2ENR_GPIOBEN = (1 << 1),
	RCC_AHB2ENR_GPIOCEN = (1 << 2),
	RCC_AHB2ENR_GPIODEN = (1 << 3),
	RCC_AHB2ENR_GPIOEEN = (1 << 4),
	RCC_AHB2ENR_GPIOHEN = (1 << 7),
	RCC_AHB2ENR_ADCEN = (1 << 13),
	RCC_AHB2ENR_AES1EN = (1 << 16)
} RCC_AHB2ENR_Regs_t;

#endif

