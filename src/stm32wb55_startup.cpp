/*!
 * \file
 * \brief
 * \author
 * \date
 */
#include <stdint.h>

// External variables from linker script
extern uint32_t _sdata;
extern uint32_t _etext;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _estack;

// External main functions
extern int cpu1_main(void);
extern int cpu2_main(void);

// Private functions
static void __system_init(void);

/*!
 * \brief Initializes the RAM memory of the device before jumping to main.
 * \details
 *
 * \param None
 *
 * \returns None
 */
extern "C" {
	void __reset_handler(void) {
		uint32_t *dest, *src;

		// Set stack pointer

		// Initialize base system
		__system_init();

		// Copy data from flash to RAM
		dest = &_sdata;
		src = &_etext;
		while (dest < &_edata) {
		
			*dest++ = *src++;

		}

		// 0 initialize bss data
		dest = &_sbss;
		while (dest < &_ebss) {
			
			*dest++ = 0;

		}

		// Set stack again before jumping to main code

		// Jump to main code
		cpu1_main();

	}
}

/*!
 * \brief Initializes base peripherals for the device.
 * \details
 *
 * \param
 *
 * \returns None
 */
static void __system_init(void) {

	

}

//==============================================================================
// Interrupt handlers
//==============================================================================
void Default_Handler(void) {

	while (1);

}

void __attribute__((weak)) NMI_Handler(void) {

	while (1);

}

void __attribute((weak)) HardFault_Handler(void) {
	
	while (1);

}

void __attribute__((weak)) MemManage_Handler(void) {

	while (1);

}

void __attribute__((weak)) BusFault_Handler(void) {

	while (1);

}

void __attribute__((weak)) UsageFault_Handler(void) {

	while (1);

}

void __attribute__((weak)) SVCall_Handler(void) {

}

void __attribute__((weak)) Debug_Handler(void) {

}

void __attribute__((weak)) PendSV_Handler(void) {

}

void __attribute__((weak)) SysTick_Handler(void) {

}

void __attribute__((weak)) WWDG_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) PVD_PVM_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) RTC_TAMP_STAMP_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) RTC_WKUP_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) Flash_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) RCC_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI0_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI3_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI4_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH3_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH4_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH5_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH6_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH7_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) ADC1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) USB_HP_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) USB_LP_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) C2SEV_PWRC2H_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) COMP_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI9_5_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TIM1_BRK_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TIM1_UP_TIM16_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TIM1_TRG_COM_TIM17_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TIM1_CC_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TIM2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) PKA_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) I2C1_EV_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) I2C1_ER_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) I2C3_EV_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) I2C3_ER_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) SPI1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) SPI2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) USART1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) LPUART1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) SAI1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TSC_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI15_10_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) RTC_ALARM_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) CRS_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) PWR_SOTF_BLEACT_802ACT_RFPHASE_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) IPPC_C1_RX_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) IPCC_C1_TX_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) HSEM_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) LPTIM1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) LPTIM2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) LCD_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) QUADSPI_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) AES1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) AES2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TRNG_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) FPU_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA2_CH1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA2_CH2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA2_CH3_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA2_CH4_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA2_CH5_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA2_CH6_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA2_CH7_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMAMUX1_OVR_ISR_Handler(void) { Default_Handler(); }

#define __ISR_IDX(addr) (addr/4)
__attribute__((section(".interrupt_vector")))
void (* const cpu1_interrupt_vector[])(void) = {

	[__ISR_IDX(0x0000)] = (void (*)())&_estack,	// Stack
	[__ISR_IDX(0x0004)] = __reset_handler,
	[__ISR_IDX(0x0008)] = NMI_Handler,
	[__ISR_IDX(0x000C)] = HardFault_Handler,
	[__ISR_IDX(0x0010)] = MemManage_Handler,
	[__ISR_IDX(0x0014)] = BusFault_Handler,
	[__ISR_IDX(0x0018)] = UsageFault_Handler,
	[__ISR_IDX(0x001C)] = 0,
	[__ISR_IDX(0x0020)] = 0,
	[__ISR_IDX(0x0024)] = 0,
	[__ISR_IDX(0x0028)] = 0,
	[__ISR_IDX(0x002C)] = SVCall_Handler,
	[__ISR_IDX(0x0030)] = Debug_Handler,
	[__ISR_IDX(0x0034)] = 0,
	[__ISR_IDX(0x0038)] = PendSV_Handler,
	[__ISR_IDX(0x003C)] = SysTick_Handler,
	[__ISR_IDX(0x0040)] = WWDG_ISR_Handler,
	[__ISR_IDX(0x0044)] = PVD_PVM_ISR_Handler,
	[__ISR_IDX(0x0048)] = RTC_TAMP_STAMP_ISR_Handler,
	[__ISR_IDX(0x004C)] = RTC_WKUP_ISR_Handler,
	[__ISR_IDX(0x0050)] = Flash_ISR_Handler,
	[__ISR_IDX(0x0054)] = RCC_ISR_Handler,
	[__ISR_IDX(0x0058)] = EXTI0_ISR_Handler,
	[__ISR_IDX(0x005C)] = EXTI1_ISR_Handler,
	[__ISR_IDX(0x0060)] = EXTI2_ISR_Handler,
	[__ISR_IDX(0x0064)] = EXTI3_ISR_Handler,
	[__ISR_IDX(0x0068)] = EXTI4_ISR_Handler,
	[__ISR_IDX(0x006C)] = DMA1_CH1_ISR_Handler,
	[__ISR_IDX(0x0070)] = DMA1_CH2_ISR_Handler,
	[__ISR_IDX(0x0074)] = DMA1_CH3_ISR_Handler,
	[__ISR_IDX(0x0078)] = DMA1_CH4_ISR_Handler,
	[__ISR_IDX(0x007C)] = DMA1_CH5_ISR_Handler,
	[__ISR_IDX(0x0080)] = DMA1_CH6_ISR_Handler,
	[__ISR_IDX(0x0084)] = DMA1_CH7_ISR_Handler,
	[__ISR_IDX(0x0088)] = ADC1_ISR_Handler,
	[__ISR_IDX(0x008C)] = USB_HP_ISR_Handler,
	[__ISR_IDX(0x0090)] = USB_LP_ISR_Handler,
	[__ISR_IDX(0x0094)] = C2SEV_PWRC2H_ISR_Handler,
	[__ISR_IDX(0x0098)] = COMP_ISR_Handler,
	[__ISR_IDX(0x009C)] = EXTI9_5_ISR_Handler,
	[__ISR_IDX(0x00A0)] = TIM1_BRK_ISR_Handler,
	[__ISR_IDX(0x00A4)] = TIM1_UP_TIM16_ISR_Handler,
	[__ISR_IDX(0x00A8)] = TIM1_TRG_COM_TIM17_ISR_Handler,
	[__ISR_IDX(0x00AC)] = TIM1_CC_ISR_Handler,
	[__ISR_IDX(0x00B0)] = TIM2_ISR_Handler,
	[__ISR_IDX(0x00B4)] = PKA_ISR_Handler,
	[__ISR_IDX(0x00B8)] = I2C1_EV_ISR_Handler,
	[__ISR_IDX(0x00BC)] = I2C1_ER_ISR_Handler,
	[__ISR_IDX(0x00C0)] = I2C3_EV_ISR_Handler,
	[__ISR_IDX(0x00C4)] = I2C3_ER_ISR_Handler,
	[__ISR_IDX(0x00C8)] = SPI1_ISR_Handler,
	[__ISR_IDX(0x00CC)] = SPI2_ISR_Handler,
	[__ISR_IDX(0x00D0)] = USART1_ISR_Handler,
	[__ISR_IDX(0x00D4)] = LPUART1_ISR_Handler,
	[__ISR_IDX(0x00D8)] = SAI1_ISR_Handler,
	[__ISR_IDX(0x00DC)] = TSC_ISR_Handler,
	[__ISR_IDX(0x00E0)] = EXTI15_10_ISR_Handler,
	[__ISR_IDX(0x00E4)] = RTC_ALARM_ISR_Handler,
	[__ISR_IDX(0x00E8)] = CRS_ISR_Handler,
	[__ISR_IDX(0x00EC)] = PWR_SOTF_BLEACT_802ACT_RFPHASE_ISR_Handler,
	[__ISR_IDX(0x00F0)] = IPPC_C1_RX_ISR_Handler,
	[__ISR_IDX(0x00F4)] = IPCC_C1_TX_ISR_Handler,
	[__ISR_IDX(0x00F8)] = HSEM_ISR_Handler,
	[__ISR_IDX(0x00FC)] = LPTIM1_ISR_Handler,
	[__ISR_IDX(0x0100)] = LPTIM2_ISR_Handler,
	[__ISR_IDX(0x0104)] = LCD_ISR_Handler,
	[__ISR_IDX(0x0108)] = QUADSPI_ISR_Handler,
	[__ISR_IDX(0x010C)] = AES1_ISR_Handler,
	[__ISR_IDX(0x0110)] = AES2_ISR_Handler,
	[__ISR_IDX(0x0114)] = TRNG_ISR_Handler,
	[__ISR_IDX(0x0118)] = FPU_ISR_Handler,
	[__ISR_IDX(0x011C)] = DMA2_CH1_ISR_Handler,
	[__ISR_IDX(0x0120)] = DMA2_CH2_ISR_Handler,
	[__ISR_IDX(0x0124)] = DMA2_CH3_ISR_Handler,
	[__ISR_IDX(0x0128)] = DMA2_CH4_ISR_Handler,
	[__ISR_IDX(0x012C)] = DMA2_CH5_ISR_Handler,
	[__ISR_IDX(0x0130)] = DMA2_CH6_ISR_Handler,
	[__ISR_IDX(0x0134)] = DMA2_CH7_ISR_Handler,
	[__ISR_IDX(0x0138)] = DMAMUX1_OVR_ISR_Handler,

};

__attribute__((section(".interrupt_vector")))
void (* const cpu2_interrupt_vector[])(void) = {

	[__ISR_IDX(0x0000)] = (void (*)())&_estack,	// Stack
	[__ISR_IDX(0x0004)] = __reset_handler,
	[__ISR_IDX(0x0008)] = NMI_Handler,
	[__ISR_IDX(0x000C)] = HardFault_Handler,
	[__ISR_IDX(0x0010)] = MemManage_Handler,
	[__ISR_IDX(0x0014)] = BusFault_Handler,
	[__ISR_IDX(0x0018)] = UsageFault_Handler,
	[__ISR_IDX(0x001C)] = 0,
	[__ISR_IDX(0x0020)] = 0,
	[__ISR_IDX(0x0024)] = 0,
	[__ISR_IDX(0x0028)] = 0,
	[__ISR_IDX(0x002C)] = SVCall_Handler,
	[__ISR_IDX(0x0030)] = Debug_Handler,
	[__ISR_IDX(0x0034)] = 0,
	[__ISR_IDX(0x0038)] = PendSV_Handler,
	[__ISR_IDX(0x003C)] = SysTick_Handler,
	[__ISR_IDX(0x0040)] = WWDG_ISR_Handler,
	[__ISR_IDX(0x0044)] = PVD_PVM_ISR_Handler,
	[__ISR_IDX(0x0048)] = RTC_TAMP_STAMP_ISR_Handler,
	[__ISR_IDX(0x004C)] = RTC_WKUP_ISR_Handler,
	[__ISR_IDX(0x0050)] = Flash_ISR_Handler,
	[__ISR_IDX(0x0054)] = RCC_ISR_Handler,
	[__ISR_IDX(0x0058)] = EXTI0_ISR_Handler,
	[__ISR_IDX(0x005C)] = EXTI1_ISR_Handler,
	[__ISR_IDX(0x0060)] = EXTI2_ISR_Handler,
	[__ISR_IDX(0x0064)] = EXTI3_ISR_Handler,
	[__ISR_IDX(0x0068)] = EXTI4_ISR_Handler,
	[__ISR_IDX(0x006C)] = DMA1_CH1_ISR_Handler,
	[__ISR_IDX(0x0070)] = DMA1_CH2_ISR_Handler,
	[__ISR_IDX(0x0074)] = DMA1_CH3_ISR_Handler,
	[__ISR_IDX(0x0078)] = DMA1_CH4_ISR_Handler,
	[__ISR_IDX(0x007C)] = DMA1_CH5_ISR_Handler,
	[__ISR_IDX(0x0080)] = DMA1_CH6_ISR_Handler,
	[__ISR_IDX(0x0084)] = DMA1_CH7_ISR_Handler,
	[__ISR_IDX(0x0088)] = ADC1_ISR_Handler,
	[__ISR_IDX(0x008C)] = USB_HP_ISR_Handler,
	[__ISR_IDX(0x0090)] = USB_LP_ISR_Handler,
	[__ISR_IDX(0x0094)] = C2SEV_PWRC2H_ISR_Handler,
	[__ISR_IDX(0x0098)] = COMP_ISR_Handler,
	[__ISR_IDX(0x009C)] = EXTI9_5_ISR_Handler,
	[__ISR_IDX(0x00A0)] = TIM1_BRK_ISR_Handler,
	[__ISR_IDX(0x00A4)] = TIM1_UP_TIM16_ISR_Handler,
	[__ISR_IDX(0x00A8)] = TIM1_TRG_COM_TIM17_ISR_Handler,
	[__ISR_IDX(0x00AC)] = TIM1_CC_ISR_Handler,
	[__ISR_IDX(0x00B0)] = TIM2_ISR_Handler,
	[__ISR_IDX(0x00B4)] = PKA_ISR_Handler,
	[__ISR_IDX(0x00B8)] = I2C1_EV_ISR_Handler,
	[__ISR_IDX(0x00BC)] = I2C1_ER_ISR_Handler,
	[__ISR_IDX(0x00C0)] = I2C3_EV_ISR_Handler,
	[__ISR_IDX(0x00C4)] = I2C3_ER_ISR_Handler,
	[__ISR_IDX(0x00C8)] = SPI1_ISR_Handler,
	[__ISR_IDX(0x00CC)] = SPI2_ISR_Handler,
	[__ISR_IDX(0x00D0)] = USART1_ISR_Handler,
	[__ISR_IDX(0x00D4)] = LPUART1_ISR_Handler,
	[__ISR_IDX(0x00D8)] = SAI1_ISR_Handler,
	[__ISR_IDX(0x00DC)] = TSC_ISR_Handler,
	[__ISR_IDX(0x00E0)] = EXTI15_10_ISR_Handler,
	[__ISR_IDX(0x00E4)] = RTC_ALARM_ISR_Handler,
	[__ISR_IDX(0x00E8)] = CRS_ISR_Handler,
	[__ISR_IDX(0x00EC)] = PWR_SOTF_BLEACT_802ACT_RFPHASE_ISR_Handler,
	[__ISR_IDX(0x00F0)] = IPPC_C1_RX_ISR_Handler,
	[__ISR_IDX(0x00F4)] = IPCC_C1_TX_ISR_Handler,
	[__ISR_IDX(0x00F8)] = HSEM_ISR_Handler,
	[__ISR_IDX(0x00FC)] = LPTIM1_ISR_Handler,
	[__ISR_IDX(0x0100)] = LPTIM2_ISR_Handler,
	[__ISR_IDX(0x0104)] = LCD_ISR_Handler,
	[__ISR_IDX(0x0108)] = QUADSPI_ISR_Handler,
	[__ISR_IDX(0x010C)] = AES1_ISR_Handler,
	[__ISR_IDX(0x0110)] = AES2_ISR_Handler,
	[__ISR_IDX(0x0114)] = TRNG_ISR_Handler,
	[__ISR_IDX(0x0118)] = FPU_ISR_Handler,
	[__ISR_IDX(0x011C)] = DMA2_CH1_ISR_Handler,
	[__ISR_IDX(0x0120)] = DMA2_CH2_ISR_Handler,
	[__ISR_IDX(0x0124)] = DMA2_CH3_ISR_Handler,
	[__ISR_IDX(0x0128)] = DMA2_CH4_ISR_Handler,
	[__ISR_IDX(0x012C)] = DMA2_CH5_ISR_Handler,
	[__ISR_IDX(0x0130)] = DMA2_CH6_ISR_Handler,
	[__ISR_IDX(0x0134)] = DMA2_CH7_ISR_Handler,
	[__ISR_IDX(0x0138)] = DMAMUX1_OVR_ISR_Handler,

};


