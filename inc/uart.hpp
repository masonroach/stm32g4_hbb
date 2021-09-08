/*!
 * \file uart.hpp
 * \brief Header file for U(S)ART functions
 * \author Mason Roach
 * \date May 6, 2021
 */

#ifndef __UART_CORE_H
#define __UART_CORE_H
// =============================================================================
// Defines
// =============================================================================
#include "stm32wb_corelib.hpp"

#define USART_CR1_UE_POS (0)
#define USART_CR1_UE_MASK (0x1 << USART_CR1_UE_POS)
#define USART_CR1_UESM_POS (1)
#define USART_CR1_UESM_MASK (0x1 << USART_CR1_UESM_POS)
#define USART_CR1_RE_POS (2)
#define USART_CR1_RE_MASK (0x1 << USART_CR1_RE_POS)
#define USART_CR1_TE_POS (3)
#define USART_CR1_TE_MASK (0x1 << USART_CR1_TE_POS)
#define USART_CR1_IDLEIE_POS (4)
#define USART_CR1_IDLEIE_MASK (0x1 << USART_CR1_IDLEIE_POS)
#define USART_CR1_RXFNEIE_POS (5)
#define USART_CR1_RXFNEIE_MASK (0x1 << USART_CR1_RXFNEIE_POS)
#define USART_CR1_TCIE_POS (6)
#define USART_CR1_TCIE_MASK (0x1 << USART_CR1_TCIE_POS)
#define USART_CR1_TXFNFIE_POS (7)
#define USART_CR1_TXFNFIE_MASK (0x1 << USART_CR1_TXFNFIE_POS)
#define USART_CR1_PEIE_POS (8)
#define USART_CR1_PEIE_MASK (0x1 << USART_CR1_PEIE_POS)
#define USART_CR1_PS_POS (9)
#define USART_CR1_PS_MASK (0x1 << USART_CR1_PS_POS)
#define USART_CR1_PCE_POS (10)
#define USART_CR1_PCE_MASK (0x1 << USART_CR1_PCE_POS)
#define USART_CR1_WAKE_POS (11)
#define USART_CR1_WAKE_MASK (0x1 << USART_CR1_WAKE_POS)
#define USART_CR1_M0_POS (12)
#define USART_CR1_M0_MASK (0x1 << USART_CR1_M0_POS)
#define USART_CR1_MME_POS (13)
#define USART_CR1_MME_MASK (0x1 << USART_CR1_MME_POS)
#define USART_CR1_CMIE_POS (14)
#define USART_CR1_CMIE_MASK (0x1 << USART_CR1_CMIE_POS)
#define USART_CR1_OVER8_POS (15)
#define USART_CR1_OVER8_MASK (0x1 << USART_CR1_OVER8_POS)
#define USART_CR1_DEDT_POS (16)
#define USART_CR1_DEDT_MASK (0x1F << USART_CR1_DEDT_POS)
#define USART_CR1_DEAT_POS (21)
#define USART_CR1_DEAT_MASK (0x1F << USART_CR1_DEAT_POS)
#define USART_CR1_RTOIE_POS (26)
#define USART_CR1_RTOIE_MASK (0x1 << USART_CR1_RTOIE_POS)
#define USART_CR1_EOBIE_POS (27)
#define USART_CR1_EOBIE_MASK (0x1 << USART_CR1_EOBIE_POS)
#define USART_CR1_M1_POS (28)
#define USART_CR1_M1_MASK (0x1 << USART_CR1_M1_POS)
#define USART_CR1_FIFOEN_POS (29)
#define USART_CR1_FIFOEN_MASK (0x1 << USART_CR1_FIFOEN_POS)
#define USART_CR1_TXFEIE_POS (30)
#define USART_CR1_TXFEIE_MASK (0x1 << USART_CR1_TXFEIE_POS)
#define USART_CR1_RXFFIE_POS (31)
#define USART_CR1_RXFFIE_MASK (0x1 << USART_CR1_RXFFIE_POS)

#define USART_CR2_SLVEN_POS (0)
#define USART_CR2_SLVEN_MASK (0x1 << USART_CR2_SLVEN_POS)
#define USART_CR2_DISNSS_POS (3)
#define USART_CR2_DISNSS_MASK (0x1 << USART_CR2_DISNSS_POS)
#define USART_CR2_ADDM7_POS (4)
#define USART_CR2_ADDM7_MASK (0x1 << USART_CR2_ADDM7_POS)
#define USART_CR2_LBDL_POS (5)
#define USART_CR2_LBDL_MASK (0x1 << USART_CR2_LBDL_POS)
#define USART_CR2_LBDIE_POS (6)
#define USART_CR2_LBDIE_MASK (0x1 << USART_CR2_LBDIE_POS)
#define USART_CR2_LBCL_POS (8)
#define USART_CR2_LBCL_MASK (0x1 << USART_CR2_LBCL_POS)
#define USART_CR2_CPHA_POS (9)
#define USART_CR2_CPHA_MASK (0x1 << USART_CR2_CPHA_POS)
#define USART_CR2_CPOL_POS (10)
#define USART_CR2_CPOL_MASK (0x1 << USART_CR2_CPOL_POS)
#define USART_CR2_CLKEN_POS (11)
#define USART_CR2_CLKEN_MASK (0x1 << USART_CR2_CLKEN_POS)
#define USART_CR2_STOP_POS (12)
#define USART_CR2_STOP_MASK (0x3 << USART_CR2_STOP_POS)
#define USART_CR2_LINEN_POS (14)
#define USART_CR2_LINEN_MASK (0x1 << USART_CR2_LINEN_POS)
#define USART_CR2_SWAP_POS (15)
#define USART_CR2_SWAP_MASK (0x1 << USART_CR2_SWAP_POS)
#define USART_CR2_RXINV_POS (16)
#define USART_CR2_RXINV_MASK (0x1 << USART_CR2_RXINV_POS)
#define USART_CR2_TXINV_POS (17)
#define USART_CR2_TXINV_MASK (0x1 << USART_CR2_TXINV_POS)
#define USART_CR2_DATAINV_POS (18)
#define USART_CR2_DATAINV_MASK (0x1 << USART_CR2_DATAINV_POS)
#define USART_CR2_MSBFIRST_POS (19)
#define USART_CR2_MSBFIRST_MASK (0x1 << USART_CR2_MSBFIRST_POS)
#define USART_CR2_ABREN_POS (20)
#define USART_CR2_ABREN_MASK (0x1 << USART_CR2_ABREN_POS)
#define USART_CR2_ABRMOD_POS (21)
#define USART_CR2_ABRMOD_MASK (0x3 << USART_CR2_ABRMOD_POS)
#define USART_CR2_RTOEN_POS (23)
#define USART_CR2_RTOEN_MASK (0x1 << USART_CR2_RTOEN_POS)
#define USART_CR2_ADD_POS (24)
#define USART_CR2_ADD_MASK (0x7F << USART_CR2_ADD_POS)

#define USART_CR3_EIE_POS (0)
#define USART_CR3_EIE_MASK (0x1 << USART_CR3_EIE_POS)
#define USART_CR3_IREN_POS (1)
#define USART_CR3_IREN_MASK (0x1 << USART_CR3_IREN_POS)
#define USART_CR3_IRLP_POS (2)
#define USART_CR3_IRLP_MASK (0x1 << USART_CR3_IRLP_POS)
#define USART_CR3_HDSEL_POS (3)
#define USART_CR3_HDSEL_MASK (0x1 << USART_CR3_HDSEL_POS)
#define USART_CR3_NACK_POS (4)
#define USART_CR3_NACK_MASK (0x1 << USART_CR3_NACK_POS)
#define USART_CR3_SCEN_POS (5)
#define USART_CR3_SCEN_MASK (0x1 << USART_CR3_SCEN_POS)
#define USART_CR3_DMAR_POS (6)
#define USART_CR3_DMAR_MASK (0x1 << USART_CR3_DMAR_POS)
#define USART_CR3_DMAT_POS (7)
#define USART_CR3_DMAT_MASK (0x1 << USART_CR3_DMAT_POS)
#define USART_CR3_RTSE_POS (8)
#define USART_CR3_RTSE_MASK (0x1 << USART_CR3_RTSE_POS)
#define USART_CR3_CTSE_POS (9)
#define USART_CR3_CTSE_MASK (0x1 << USART_CR3_CTSE_POS)
#define USART_CR3_CTSIE_POS (10)
#define USART_CR3_CTSIE_MASK (0x1 << USART_CR3_CTSIE_POS)
#define USART_CR3_ONEBIT_POS (11)
#define USART_CR3_ONEBIT_MASK (0x1 << USART_CR3_ONEBIT_POS)
#define USART_CR3_OVRDIS_POS (12)
#define USART_CR3_OVRDIS_MASK (0x1 << USART_CR3_OVRDIS_POS)
#define USART_CR3_DDRE_POS (13)
#define USART_CR3_DDRE_MASK (0x1 << USART_CR3_DDRE_POS)
#define USART_CR3_DEM_POS (14)
#define USART_CR3_DEM_MASK (0x1 << USART_CR3_DEM_POS)
#define USART_CR3_DEP_POS (15)
#define USART_CR3_DEP_MASK (0x1 << USART_CR3_DEP_POS)
#define USART_CR3_SCARCNT_POS (17)
#define USART_CR3_SCARCNT_MASK (0x7 << USART_CR3_SCARCNT_POS)
#define USART_CR3_WUS_POS (20)
#define USART_CR3_WUS_MASK (0x3 << USART_CR3_WUS_POS)
#define USART_CR3_WUFIE_POS (22)
#define USART_CR3_WUFIE_MASK (0x1 << USART_CR3_WUFIE_POS)
#define USART_CR3_TXFTIE_POS (23)
#define USART_CR3_TXFTIE_MASK (0x1 << USART_CR3_TXFTIE_POS)
#define USART_CR3_TCBGTIE_POS (24)
#define USART_CR3_TCBGTIE_MASK (0x1 << USART_CR3_TCBGTIE_POS)
#define USART_CR3_RXFTCFG_POS (25)
#define USART_CR3_RXFTCFG_MASK (0x7 << USART_CR3_RXFTCFG_POS)
#define USART_CR3_RXFTIE_POS (28)
#define USART_CR3_RXFTIE_MASK (0x1 << USART_CR3_RXFTIE_POS)
#define USART_CR3_TXFTCFG_POS (29)
#define USART_CR3_TXFTCFG_MASK (0x7 << USART_CR3_TXFTCFG_POS)

#define USART_BRR_BRR_POS (0)
#define USART_BRR_BRR_MASK (0xFFFF << USART_BRR_BRR_POS)

#define USART_GTPR_PSC_POS (0)
#define USART_GTPR_PSC_MASK (0xFF << USART_GTPR_PSC_POS)
#define USART_GTPR_GT_POS (8)
#define USART_GTPR_GT_MASK (0xFF << USART_GTPR_GT_POS)

#define USART_RTOR_RTO_POS (0)
#define USART_RTOR_RTO_MASK (0xFFFFFF << USART_RTOR_RTO_POS)
#define USART_RTOR_BLEN_POS (24)
#define USART_RTOR_BLEN_MASK (0xFF << USART_RTOR_BLEN_POS)

#define USART_RQR_ABRRQ_POS (0)
#define USART_RQR_ABRRQ_MASK (0x1 << USART_RQR_ABRRQ_POS)
#define USART_RQR_SBKRQ_POS (1)
#define USART_RQR_SBKRQ_MASK (0x1 << USART_RQR_SBKRQ_POS)
#define USART_RQR_MMRQ_POS (2)
#define USART_RQR_MMRQ_MASK (0x1 << USART_RQR_MMRQ_POS)
#define USART_RQR_RXFRQ_POS (3)
#define USART_RQR_RXFRQ_MASK (0x1 << USART_RQR_RXFRQ_POS)
#define USART_RQR_TXFRQ_POS (4)
#define USART_RQR_TXFRQ_MASK (0x1 << USART_RQR_TXFRQ_POS)

#define USART_ISR_PE_POS (0)
#define USART_ISR_PE_MASK (0x1 << USART_ISR_PE_POS)
#define USART_ISR_FE_POS (1)
#define USART_ISR_FE_MASK (0x1 << USART_ISR_FE_POS)
#define USART_ISR_NE_POS (2)
#define USART_ISR_NE_MASK (0x1 << USART_ISR_NE_POS)
#define USART_ISR_ORE_POS (3)
#define USART_ISR_ORE_MASK (0x1 << USART_ISR_ORE_POS)
#define USART_ISR_IDLE_POS (4)
#define USART_ISR_IDLE_MASK (0x1 << USART_ISR_IDLE_POS)
#define USART_ISR_RXFNE_POS (5)
#define USART_ISR_RXFNE_MASK (0x1 << USART_ISR_RXFNE_POS)
#define USART_ISR_TC_POS (6)
#define USART_ISR_TC_MASK (0x1 << USART_ISR_TC_POS)
#define USART_ISR_TXFNF_POS (7)
#define USART_ISR_TXFNF_MASK (0x1 << USART_ISR_TXFNF_POS)
#define USART_ISR_LBDF_POS (8)
#define USART_ISR_LBDF_MASK (0x1 << USART_ISR_LBDF_POS)
#define USART_ISR_CTSIF_POS (9)
#define USART_ISR_CTSIF_MASK (0x1 << USART_ISR_CTSIF_POS)
#define USART_ISR_CTS_POS (10)
#define USART_ISR_CTS_MASK (0x1 << USART_ISR_CTS_POS)
#define USART_ISR_RTOF_POS (11)
#define USART_ISR_RTOF_MASK (0x1 << USART_ISR_RTOF_POS)
#define USART_ISR_EOBF_POS (12)
#define USART_ISR_EOBF_MASK (0x1 << USART_ISR_EOBF_POS)
#define USART_ISR_UDR_POS (13)
#define USART_ISR_UDR_MASK (0x1 << USART_ISR_UDR_POS)
#define USART_ISR_ABRE_POS (14)
#define USART_ISR_ABRE_MASK (0x1 << USART_ISR_ABRE_POS)
#define USART_ISR_ABRF_POS (15)
#define USART_ISR_ABRF_MASK (0x1 << USART_ISR_ABRF_POS)
#define USART_ISR_BUSY_POS (16)
#define USART_ISR_BUSY_MASK (0x1 << USART_ISR_BUSY_POS)
#define USART_ISR_CMF_POS (17)
#define USART_ISR_CMF_MASK (0x1 << USART_ISR_CMF_POS)
#define USART_ISR_SBKF_POS (18)
#define USART_ISR_SBKF_MASK (0x1 << USART_ISR_SBKF_POS)
#define USART_ISR_RWU_POS (19)
#define USART_ISR_RWU_MASK (0x1 << USART_ISR_RWU_POS)
#define USART_ISR_WUF_POS (20)
#define USART_ISR_WUF_MASK (0x1 << USART_ISR_WUF_POS)
#define USART_ISR_TEACK_POS (21)
#define USART_ISR_TEACK_MASK (0x1 << USART_ISR_TEACK_POS)
#define USART_ISR_REACK_POS (22)
#define USART_ISR_REACK_MASK (0x1 << USART_ISR_REACK_POS)
#define USART_ISR_TXFE_POS (23)
#define USART_ISR_TXFE_MASK (0x1 << USART_ISR_TXFE_POS)
#define USART_ISR_RXFF_POS (24)
#define USART_ISR_RXFF_MASK (0x1 << USART_ISR_RXFF_POS)
#define USART_ISR_TCBGT_POS (25)
#define USART_ISR_TCBGT_MASK (0x1 << USART_ISR_TCBGT_POS)
#define USART_ISR_RXFT_POS (26)
#define USART_ISR_RXFT_MASK (0x1 << USART_ISR_RXFT_POS)
#define USART_ISR_TXFT_POS (27)
#define USART_ISR_TXFT_MASK (0x1 << USART_ISR_TXFT_POS)

#define USART_ICR_PECF_POS (0)
#define USART_ICR_PECF_MASK (0x1 << USART_ICR_PECF_POS)
#define USART_ICR_FECF_POS (1)
#define USART_ICR_FECF_MASK (0x1 << USART_ICR_FECF_POS)
#define USART_ICR_NECF_POS (2)
#define USART_ICR_NECF_MASK (0x1 << USART_ICR_NECF_POS)
#define USART_ICR_ORECF_POS (3)
#define USART_ICR_ORECF_MASK (0x1 << USART_ICR_ORECF_POS)
#define USART_ICR_IDLECF_POS (4)
#define USART_ICR_IDLECF_MASK (0x1 << USART_ICR_IDLECF_POS)
#define USART_ICR_TXFECF_POS (5)
#define USART_ICR_TXFECF_MASK (0x1 << USART_ICR_TXFECF_POS)
#define USART_ICR_TCCF_POS (6)
#define USART_ICR_TCCF_MASK (0x1 << USART_ICR_TCCF_POS)
#define USART_ICR_TCBGTCF_POS (7)
#define USART_ICR_TCBGTCF_MASK (0x1 << USART_ICR_TCBGTCF_POS)
#define USART_ICR_LBDCF_POS (8)
#define USART_ICR_LBDCF_MASK (0x1 << USART_ICR_LBDCF_POS)
#define USART_ICR_CTSCF_POS (9)
#define USART_ICR_CTSCF_MASK (0x1 << USART_ICR_CTSCF_POS)
#define USART_ICR_RTOCF_POS (11)
#define USART_ICR_RTOCF_MASK (0x1 << USART_ICR_RTOCF_POS)
#define USART_ICR_EOBCF_POS (12)
#define USART_ICR_EOBCF_MASK (0x1 << USART_ICR_EOBCF_POS)
#define USART_ICR_UDRCF_POS (13)
#define USART_ICR_UDRCF_MASK (0x1 << USART_ICR_UDRCF_POS)
#define USART_ICR_CMCF_POS (17)
#define USART_ICR_CMCF_MASK (0x1 << USART_ICR_CMCF_POS)
#define USART_ICR_WUCF_POS (20)
#define USART_ICR_WUCF_MASK (0x1 << USART_ICR_WUCF_POS)

#define USART_RDR_RDR_POS (0)
#define USART_RDR_RDR_MASK (0x1FF << USART_RDR_RDR_POS)

#define USART_TDR_TDR_POS (0)
#define USART_TDR_TDR_MASK (0x1FF << USART_TDR_TDR_POS)

#define USART_PRESC_PRESCALER_POS (0)
#define USART_PRESC_PRESCALER_MASK (0xF << USART_PRESC_PRESCALER_POS)

/*!
 * \brief USART register structure 
 */
typedef struct {
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t BRR;
	volatile uint32_t GTPR;
	volatile uint32_t RTOR;
	volatile uint32_t RQR;
	volatile uint32_t ISR;
	volatile uint32_t ICR;
	volatile uint32_t RDR;
	volatile uint32_t TDR;
	volatile uint32_t PRESC;
} USART_Regs_t;
#define USART1 ((USART_Regs_t *)USART1_BASE)

/*!
 * \brief
 */
typedef enum {
	USART_COMM_MODE_RX_ONLY = USART_CR1_RE_MASK,
	USART_COMM_MODE_TX_ONLY = USART_CR1_TE_MASK,
	USART_COMM_MODE_TX_RX = USART_CR1_RE_MASK | USART_CR1_TE_MASK
} USART_Comm_Mode_t;

/*!
 * \brief
 */
typedef enum {
	USART_WORD_LEN_7 = USART_CR1_M1_MASK,
	USART_WORD_LEN_8 = 0,
	USART_WORD_LEN_9 = USART_CR1_M0_MASK
} USART_Word_Length_t;

/*!
 * \brief
 */
typedef enum {
	USART_STOP_BITS_1 = 0,
	USART_STOP_BITS_0p5 = (0x1 << USART_CR2_STOP_POS),
	USART_STOP_BITS_2 = (0x2 << USART_CR2_STOP_POS),
	USART_STOP_BITS_1p5 = (0x3 << USART_CR2_STOP_POS)
} USART_Stop_Bits_t;

/*!
 * \brief
 */
typedef enum {
	USART_PARITY_NONE = 0,
	USART_PARITY_EVEN = USART_CR1_PCE_MASK,
	USART_PARITY_ODD = USART_CR1_PCE_MASK | USART_CR1_PS_MASK,
} USART_Parity_t;

/*!
 * \brief
 */
typedef enum {
	USART_FLOW_CONTROL_NONE = 0,
	USART_FLOW_CONTROL_CTS_ONLY = USART_CR3_CTSE_MASK,
	USART_FLOW_CONTROL_RTS_ONLY = USART_CR3_RTSE_MASK,
	USART_FLOW_CONTROL_CTS_RTS = USART_CR3_CTSE_MASK | USART_CR3_RTSE_MASK
} USART_Flow_Control_t;

/*!
 * \brief
 */
typedef enum {
	USART_OVERSAMP_8 = USART_CR1_OVER8_MASK,
	USART_OVERSAMP_16 = 0
} USART_Oversamp_t;

class USART_Handle_t {
public:
	// Constructors
	USART_Handle_t();
	USART_Handle_t(USART_Regs_t *reg_base_addr);

	// Destructors
	~USART_Handle_t();

	// Initializations
	Sys_Err_t port_init(
		uint32_t baud,
		USART_Comm_Mode_t comm_mode = USART_COMM_MODE_TX_RX,
		USART_Word_Length_t word_length = USART_WORD_LEN_8,
		USART_Stop_Bits_t stop_bits = USART_STOP_BITS_1,
		USART_Parity_t parity = USART_PARITY_NONE,
		USART_Flow_Control_t flow_control = USART_FLOW_CONTROL_NONE,
		uint8_t prescaler = 1,
		USART_Oversamp_t oversamp = USART_OVERSAMP_8
	);
	
	// Use functions
	Sys_Err_t transmit_blocking(
		uint8_t *data,
		uint32_t len
	);

	Sys_Err_t receive_blocking(
		uint8_t *buf,
		uint32_t len
	);

	// Interrupt functions

protected:
	USART_Regs_t *regs = 0;

private:

};

#endif
