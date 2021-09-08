/*!
 * \file uart.cpp
 * \brief Function definitions for U(S)ART functions
 * \author Mason Roach
 * \date May 7, 2021
 */
#include "stm32wb.hpp"
#include "uart.hpp"

/*!
 * \group??
 */

/*!
 * \brief
 */
USART_Handle_t::USART_Handle_t()
{



}

/*!
 * \brief
 */
USART_Handle_t::USART_Handle_t(
	USART_Regs_t *reg_base_addr
)
{

	// TODO assert port
	// assert(reg_base_addr);

	regs = reg_base_addr;

}

/*!
 * \brief
 */
Sys_Err_t USART_Handle_t::port_init(
	uint32_t baud,
	USART_Comm_Mode_t comm_mode,
	USART_Word_Length_t word_length,
	USART_Stop_Bits_t stop_bits,
	USART_Parity_t parity,
	USART_Flow_Control_t flow_control,
	uint8_t prescaler,
	USART_Oversamp_t oversamp
)
{
	// TODO add assertions
	// assert(comm_mode);
	// assert(word_length);
	// assert(stop_bits);
	// assert(parity);
	// assert(flow_control);
	// assert(parity);
	// assert(over_sampling);

	// Make sure the register has been defined
	if (regs == 0) {
		return ERR_NOPORT;
	}

	// Make sure the port is not already initialized
	// TODO

	// Do registers need to get cleared first?

	// Set the baud rate register
#ifdef SYSTEM_CLOCK
	baud = SYSTEM_CLOCK / baud / prescaler;
	if (oversamp == USART_OVERSAMP_8) {
		baud = baud * 2;
		baud = (0xFFF0 & baud) | ((0x000F & baud) >> 1);
	} else {
		baud = baud & 0xFFFF;
	}
#endif
	regs->BRR = baud;

	// Initialize control registers
	regs->CR1 |= (comm_mode | word_length | parity | oversamp);
	regs->CR2 |= (stop_bits);
	regs->CR3 |= (flow_control);
	regs->GTPR |= (prescaler << USART_GTPR_PSC_POS);

	// Enable the UART peripheral
	regs->CR1 |= USART_CR1_UE_MASK;

	return ERR_NONE;

}

/*!
 * \brief
 */
Sys_Err_t USART_Handle_t::transmit_blocking(
	uint8_t *data,
	uint32_t len
)
{
	
	// Check if the peripheral is already in use
	if (regs->ISR & USART_ISR_BUSY_MASK) {
		return ERR_BUSY;
	}

	// Transmit data
	while (len) {
		regs->TDR = *data;
		data++;
		len--;
	}

	return ERR_NONE;

}

/*!
 * \brief
 */
Sys_Err_t USART_Handle_t::receive_blocking(
	uint8_t *buf,
	uint32_t len
)
{

	(void)buf;
	(void)len;

	return ERR_NONE;

}

