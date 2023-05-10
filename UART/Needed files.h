#define HWREG(x)                                                              \
        (*((volatile uint32_t *)(x)))
//GPIO
#define GPIO_O_DEN              0x0000051C  // GPIO Digital Enable
#define GPIO_O_PUR              0x00000510  // GPIO Pull-Up Select
#define GPIO_O_IM               0x00000410  // GPIO Interrupt Mask
#define GPIO_O_RIS              0x00000414  // GPIO Raw Interrupt Status
#define GPIO_O_MIS              0x00000418  // GPIO Masked Interrupt Status
#define GPIO_O_ICR              0x0000041C  // GPIO Interrupt Clear
#define GPIO_O_LOCK             0x00000520  // GPIO Lock
#define GPIO_IM_GPIO_M          0x000000FF  // GPIO Interrupt Mask Enable
#define GPIO_IM_GPIO_S          0
#define GPIO_RIS_GPIO_M         0x000000FF  // GPIO Interrupt Raw Status
#define GPIO_RIS_GPIO_S         0
#define GPIO_MIS_GPIO_M         0x000000FF  // GPIO Masked Interrupt Status
#define GPIO_MIS_GPIO_S         0
#define GPIO_ICR_GPIO_M         0x000000FF  // GPIO Interrupt Clear
#define GPIO_ICR_GPIO_S         0
#define GPIO_LOCK_M             0xFFFFFFFF  // GPIO Lock
#define GPIO_LOCK_UNLOCKED      0x00000000  // The GPIOCR register is unlocked
#define GPIO_LOCK_LOCKED        0x00000001  // The GPIOCR register is locked
#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register

//UART
#define UART_O_DR               0x00000000  // UART Data
#define UART_O_RSR              0x00000004  // UART Receive Status/Error Clear
#define UART_O_ECR              0x00000004  // UART Receive Status/Error Clear
#define UART_O_FR               0x00000018  // UART Flag
#define UART_O_ILPR             0x00000020  // UART IrDA Low-Power Register
#define UART_O_IBRD             0x00000024  // UART Integer Baud-Rate Divisor
#define UART_O_FBRD             0x00000028  // UART Fractional Baud-Rate
#define UART_O_LCRH             0x0000002C  // UART Line Control
#define UART_O_CTL              0x00000030  // UART Control
#define UART_O_IFLS             0x00000034  // UART Interrupt FIFO Level Select
#define UART_O_IM               0x00000038  // UART Interrupt Mask
#define UART_O_RIS              0x0000003C  // UART Raw Interrupt Status
#define UART_O_MIS              0x00000040  // UART Masked Interrupt Status
#define UART_O_ICR              0x00000044  // UART Interrupt Clear
#define UART_O_DMACTL           0x00000048  // UART DMA Control
#define UART_O_9BITADDR         0x000000A4  // UART 9-Bit Self Address
#define UART_O_9BITAMASK        0x000000A8  // UART 9-Bit Self Address Mask
#define UART_O_PP               0x00000FC0  // UART Peripheral Properties
#define UART_O_CC               0x00000FC8  // UART Clock Configuration
#define UART_DR_OE              0x00000800  // UART Overrun Error
#define UART_DR_BE              0x00000400  // UART Break Error
#define UART_DR_PE              0x00000200  // UART Parity Error
#define UART_DR_FE              0x00000100  // UART Framing Error
#define UART_DR_DATA_M          0x000000FF  // Data Transmitted or Received
#define UART_DR_DATA_S          0
#define UART_RSR_OE             0x00000008  // UART Overrun Error
#define UART_RSR_BE             0x00000004  // UART Break Error
#define UART_RSR_PE             0x00000002  // UART Parity Error
#define UART_RSR_FE             0x00000001  // UART Framing Error
#define UART_ECR_DATA_M         0x000000FF  // Error Clear
#define UART_ECR_DATA_S         0
#define UART_FR_TXFE            0x00000080  // UART Transmit FIFO Empty
#define UART_FR_RXFF            0x00000040  // UART Receive FIFO Full
#define UART_FR_TXFF            0x00000020  // UART Transmit FIFO Full
#define UART_FR_RXFE            0x00000010  // UART Receive FIFO Empty
#define UART_FR_BUSY            0x00000008  // UART Busy
#define UART_FR_CTS             0x00000001  // Clear To Send
#define UART_ILPR_ILPDVSR_M     0x000000FF  // IrDA Low-Power Divisor
#define UART_ILPR_ILPDVSR_S     0
#define UART_IBRD_DIVINT_M      0x0000FFFF  // Integer Baud-Rate Divisor
#define UART_IBRD_DIVINT_S      0
#define UART_LCRH_SPS           0x00000080  // UART Stick Parity Select
#define UART_LCRH_WLEN_M        0x00000060  // UART Word Length
#define UART_LCRH_WLEN_5        0x00000000  // 5 bits (default)
#define UART_LCRH_WLEN_6        0x00000020  // 6 bits
#define UART_LCRH_WLEN_7        0x00000040  // 7 bits
#define UART_LCRH_WLEN_8        0x00000060  // 8 bits
#define UART_LCRH_FEN           0x00000010  // UART Enable FIFOs
#define UART_LCRH_STP2          0x00000008  // UART Two Stop Bits Select
#define UART_LCRH_EPS           0x00000004  // UART Even Parity Select
#define UART_LCRH_PEN           0x00000002  // UART Parity Enable
#define UART_LCRH_BRK           0x00000001  // UART Send Break
#define UART_CTL_CTSEN          0x00008000  // Enable Clear To Send
#define UART_CTL_RTSEN          0x00004000  // Enable Request to Send
#define UART_CTL_RTS            0x00000800  // Request to Send
#define UART_CTL_RXE            0x00000200  // UART Receive Enable
#define UART_CTL_TXE            0x00000100  // UART Transmit Enable
#define UART_CTL_LBE            0x00000080  // UART Loop Back Enable
#define UART_CTL_HSE            0x00000020  // High-Speed Enable
#define UART_CTL_EOT            0x00000010  // End of Transmission
#define UART_CTL_SMART          0x00000008  // ISO 7816 Smart Card Support
#define UART_CTL_SIRLP          0x00000004  // UART SIR Low-Power Mode
#define UART_CTL_SIREN          0x00000002  // UART SIR Enable
#define UART_CTL_UARTEN         0x00000001  // UART Enable
#define UART_IFLS_RX_M          0x00000038  // UART Receive Interrupt FIFO
#define UART_IFLS_RX1_8         0x00000000  // RX FIFO >= 1/8 full
#define UART_IFLS_RX2_8         0x00000008  // RX FIFO >= 1/4 full
#define UART_IFLS_RX4_8         0x00000010  // RX FIFO >= 1/2 full (default)
#define UART_IFLS_RX6_8         0x00000018  // RX FIFO >= 3/4 full
#define UART_IFLS_RX7_8         0x00000020  // RX FIFO >= 7/8 full
#define UART_IFLS_TX_M          0x00000007  // UART Transmit Interrupt FIFO
#define UART_IFLS_TX1_8         0x00000000  // TX FIFO <= 1/8 full
#define UART_IFLS_TX2_8         0x00000001  // TX FIFO <= 1/4 full
#define UART_IFLS_TX4_8         0x00000002  // TX FIFO <= 1/2 full (default)
#define UART_IFLS_TX6_8         0x00000003  // TX FIFO <= 3/4 full
#define UART_IFLS_TX7_8         0x00000004  // TX FIFO <= 7/8 full
#define UART_IM_9BITIM          0x00001000  // 9-Bit Mode Interrupt Mask
#define UART_IM_OEIM            0x00000400  // UART Overrun Error Interrupt
#define UART_IM_BEIM            0x00000200  // UART Break Error Interrupt Mask
#define UART_IM_PEIM            0x00000100  // UART Parity Error Interrupt Mask
#define UART_IM_FEIM            0x00000080  // UART Framing Error Interrupt
#define UART_IM_RTIM            0x00000040  // UART Receive Time-Out Interrupt
#define UART_IM_TXIM            0x00000020  // UART Transmit Interrupt Mask
#define UART_IM_RXIM            0x00000010  // UART Receive Interrupt Mask
#define UART_IM_CTSMIM          0x00000002  // UART Clear to Send Modem
#define UART_RIS_9BITRIS        0x00001000  // 9-Bit Mode Raw Interrupt Status
#define UART_RIS_OERIS          0x00000400  // UART Overrun Error Raw Interrupt
#define UART_RIS_BERIS          0x00000200  // UART Break Error Raw Interrupt
#define UART_RIS_PERIS          0x00000100  // UART Parity Error Raw Interrupt
#define UART_RIS_FERIS          0x00000080  // UART Framing Error Raw Interrupt
#define UART_RIS_RTRIS          0x00000040  // UART Receive Time-Out Raw
#define UART_RIS_TXRIS          0x00000020  // UART Transmit Raw Interrupt
#define UART_RIS_RXRIS          0x00000010  // UART Receive Raw Interrupt
#define UART_RIS_CTSRIS         0x00000002  // UART Clear to Send Modem Raw
#define UART_MIS_9BITMIS        0x00001000  // 9-Bit Mode Masked Interrupt
#define UART_MIS_OEMIS          0x00000400  // UART Overrun Error Masked
#define UART_MIS_BEMIS          0x00000200  // UART Break Error Masked
#define UART_MIS_PEMIS          0x00000100  // UART Parity Error Masked
#define UART_MIS_FEMIS          0x00000080  // UART Framing Error Masked
#define UART_MIS_RTMIS          0x00000040  // UART Receive Time-Out Masked
#define UART_MIS_TXMIS          0x00000020  // UART Transmit Masked Interrupt
#define UART_MIS_RXMIS          0x00000010  // UART Receive Masked Interrupt
#define UART_MIS_CTSMIS         0x00000002  // UART Clear to Send Modem Masked
#define UART_ICR_9BITIC         0x00001000  // 9-Bit Mode Interrupt Clear
#define UART_ICR_OEIC           0x00000400  // Overrun Error Interrupt Clear
#define UART_ICR_BEIC           0x00000200  // Break Error Interrupt Clear
#define UART_ICR_PEIC           0x00000100  // Parity Error Interrupt Clear
#define UART_ICR_FEIC           0x00000080  // Framing Error Interrupt Clear
#define UART_ICR_RTIC           0x00000040  // Receive Time-Out Interrupt Clear
#define UART_ICR_TXIC           0x00000020  // Transmit Interrupt Clear
#define UART_ICR_RXIC           0x00000010  // Receive Interrupt Clear
#define UART_ICR_CTSMIC         0x00000002  // UART Clear to Send Modem
#define UART_DMACTL_DMAERR      0x00000004  // DMA on Error
#define UART_DMACTL_TXDMAE      0x00000002  // Transmit DMA Enable
#define UART_DMACTL_RXDMAE      0x00000001  // Receive DMA Enable
#define UART_9BITADDR_9BITEN    0x00008000  // Enable 9-Bit Mode
#define UART_9BITADDR_ADDR_M    0x000000FF  // Self Address for 9-Bit Mode
#define UART_9BITADDR_ADDR_S    0
#define UART_9BITAMASK_MASK_M   0x000000FF  // Self Address Mask for 9-Bit Mode
#define UART_9BITAMASK_MASK_S   0
#define UART_PP_NB              0x00000002  // 9-Bit Support
#define UART_PP_SC              0x00000001  // Smart Card Support
#define UART_CC_CS_M            0x0000000F  // UART Baud Clock Source
#define UART_CC_CS_SYSCLK       0x00000000  // System clock (based on clock source and divisor factor)
#define UART_CC_CS_PIOSC        0x00000005  // PIOSC

//memmap
#define GPIO_PORTA_BASE         0x40004000  // GPIO Port A
#define GPIO_PORTB_BASE         0x40005000  // GPIO Port B
#define UART0_BASE              0x4000C000  // UART0

//sysctl
#define SYSCTL_DID0             0x400FE000  // Device Identification 0
#define SYSCTL_DID1             0x400FE004  // Device Identification 1
#define SYSCTL_DC0              0x400FE008  // Device Capabilities 0
#define SYSCTL_DC1              0x400FE010  // Device Capabilities 1
#define SYSCTL_DC2              0x400FE014  // Device Capabilities 2
#define SYSCTL_DC3              0x400FE018  // Device Capabilities 3
#define SYSCTL_DC4              0x400FE01C  // Device Capabilities 4
#define SYSCTL_DC5              0x400FE020  // Device Capabilities 5
#define SYSCTL_DC6              0x400FE024  // Device Capabilities 6
#define SYSCTL_DC7              0x400FE028  // Device Capabilities 7
#define SYSCTL_DC8              0x400FE02C  // Device Capabilities 8
#define SYSCTL_PBORCTL          0x400FE030  // Brown-Out Reset Control
#define SYSCTL_SRCR0            0x400FE040  // Software Reset Control 0
#define SYSCTL_SRCR1            0x400FE044  // Software Reset Control 1
#define SYSCTL_SRCR2            0x400FE048  // Software Reset Control 2
#define SYSCTL_RIS              0x400FE050  // Raw Interrupt Status
#define SYSCTL_IMC              0x400FE054  // Interrupt Mask Control
#define SYSCTL_MISC             0x400FE058  // Masked Interrupt Status and
// Clear
#define SYSCTL_RESC             0x400FE05C  // Reset Cause
#define SYSCTL_RCC              0x400FE060  // Run-Mode Clock Configuration
#define SYSCTL_GPIOHBCTL        0x400FE06C  // GPIO High-Performance Bus
// Control
#define SYSCTL_RCC2             0x400FE070  // Run-Mode Clock Configuration 2
#define SYSCTL_MOSCCTL          0x400FE07C  // Main Oscillator Control
#define SYSCTL_RCGC0            0x400FE100  // Run Mode Clock Gating Control
// Register 0
#define SYSCTL_RCGC1            0x400FE104  // Run Mode Clock Gating Control
// Register 1
#define SYSCTL_RCGC2            0x400FE108  // Run Mode Clock Gating Control
// Register 2
#define SYSCTL_SCGC0            0x400FE110  // Sleep Mode Clock Gating Control
// Register 0
#define SYSCTL_SCGC1            0x400FE114  // Sleep Mode Clock Gating Control
// Register 1
#define SYSCTL_SCGC2            0x400FE118  // Sleep Mode Clock Gating Control
// Register 2
#define SYSCTL_DCGC0            0x400FE120  // Deep Sleep Mode Clock Gating
// Control Register 0
#define SYSCTL_DCGC1            0x400FE124  // Deep-Sleep Mode Clock Gating
// Control Register 1
#define SYSCTL_DCGC2            0x400FE128  // Deep Sleep Mode Clock Gating
// Control Register 2
#define SYSCTL_DSLPCLKCFG       0x400FE144  // Deep Sleep Clock Configuration
#define SYSCTL_SYSPROP          0x400FE14C  // System Properties
#define SYSCTL_PIOSCCAL         0x400FE150  // Precision Internal Oscillator
// Calibration
#define SYSCTL_PIOSCSTAT        0x400FE154  // Precision Internal Oscillator
// Statistics
#define SYSCTL_PLLFREQ0         0x400FE160  // PLL Frequency 0
#define SYSCTL_PLLFREQ1         0x400FE164  // PLL Frequency 1
#define SYSCTL_PLLSTAT          0x400FE168  // PLL Status
#define SYSCTL_SLPPWRCFG        0x400FE188  // Sleep Power Configuration
#define SYSCTL_DSLPPWRCFG       0x400FE18C  // Deep-Sleep Power Configuration
#define SYSCTL_DC9              0x400FE190  // Device Capabilities 9
#define SYSCTL_NVMSTAT          0x400FE1A0  // Non-Volatile Memory Information
#define SYSCTL_LDOSPCTL         0x400FE1B4  // LDO Sleep Power Control
#define SYSCTL_LDODPCTL         0x400FE1BC  // LDO Deep-Sleep Power Control
#define SYSCTL_PPWD             0x400FE300  // Watchdog Timer Peripheral
// Present
#define SYSCTL_PPTIMER          0x400FE304  // 16/32-Bit General-Purpose Timer
// Peripheral Present
#define SYSCTL_PPGPIO           0x400FE308  // General-Purpose Input/Output
// Peripheral Present
#define SYSCTL_PPDMA            0x400FE30C  // Micro Direct Memory Access
// Peripheral Present
#define SYSCTL_PPHIB            0x400FE314  // Hibernation Peripheral Present
#define SYSCTL_PPUART           0x400FE318  // Universal Asynchronous
// Receiver/Transmitter Peripheral
// Present
#define SYSCTL_PPSSI            0x400FE31C  // Synchronous Serial Interface
// Peripheral Present
#define SYSCTL_PPI2C            0x400FE320  // Inter-Integrated Circuit
// Peripheral Present
#define SYSCTL_PPUSB            0x400FE328  // Universal Serial Bus Peripheral
// Present
#define SYSCTL_PPCAN            0x400FE334  // Controller Area Network
// Peripheral Present
#define SYSCTL_PPADC            0x400FE338  // Analog-to-Digital Converter
// Peripheral Present
#define SYSCTL_PPACMP           0x400FE33C  // Analog Comparator Peripheral
// Present
#define SYSCTL_PPPWM            0x400FE340  // Pulse Width Modulator Peripheral
// Present
#define SYSCTL_PPQEI            0x400FE344  // Quadrature Encoder Interface
// Peripheral Present
#define SYSCTL_PPEEPROM         0x400FE358  // EEPROM Peripheral Present
#define SYSCTL_PPWTIMER         0x400FE35C  // 32/64-Bit Wide General-Purpose
// Timer Peripheral Present
#define SYSCTL_SRWD             0x400FE500  // Watchdog Timer Software Reset
#define SYSCTL_SRTIMER          0x400FE504  // 16/32-Bit General-Purpose Timer
// Software Reset
#define SYSCTL_SRGPIO           0x400FE508  // General-Purpose Input/Output
// Software Reset
#define SYSCTL_SRDMA            0x400FE50C  // Micro Direct Memory Access
// Software Reset
#define SYSCTL_SRHIB            0x400FE514  // Hibernation Software Reset
#define SYSCTL_SRUART           0x400FE518  // Universal Asynchronous
// Receiver/Transmitter Software
// Reset
#define SYSCTL_SRSSI            0x400FE51C  // Synchronous Serial Interface
// Software Reset
#define SYSCTL_SRI2C            0x400FE520  // Inter-Integrated Circuit
// Software Reset
#define SYSCTL_SRUSB            0x400FE528  // Universal Serial Bus Software
// Reset
#define SYSCTL_SRCAN            0x400FE534  // Controller Area Network Software
// Reset
#define SYSCTL_SRADC            0x400FE538  // Analog-to-Digital Converter
// Software Reset
#define SYSCTL_SRACMP           0x400FE53C  // Analog Comparator Software Reset
#define SYSCTL_SRPWM            0x400FE540  // Pulse Width Modulator Software
// Reset
#define SYSCTL_SRQEI            0x400FE544  // Quadrature Encoder Interface
// Software Reset
#define SYSCTL_SREEPROM         0x400FE558  // EEPROM Software Reset
#define SYSCTL_SRWTIMER         0x400FE55C  // 32/64-Bit Wide General-Purpose
// Timer Software Reset
// Software Reset
#define SYSCTL_RCGCWD           0x400FE600  // Watchdog Timer Run Mode Clock
// Gating Control
#define SYSCTL_RCGCTIMER        0x400FE604  // 16/32-Bit General-Purpose Timer
// Run Mode Clock Gating Control
#define SYSCTL_RCGCGPIO         0x400FE608  // General-Purpose Input/Output Run
// Mode Clock Gating Control
#define SYSCTL_RCGCDMA          0x400FE60C  // Micro Direct Memory Access Run
// Mode Clock Gating Control
#define SYSCTL_RCGCHIB          0x400FE614  // Hibernation Run Mode Clock
// Gating Control
#define SYSCTL_RCGCUART         0x400FE618  // Universal Asynchronous
// Receiver/Transmitter Run Mode
// Clock Gating Control
#define SYSCTL_RCGCSSI          0x400FE61C  // Synchronous Serial Interface Run
// Mode Clock Gating Control
#define SYSCTL_RCGCI2C          0x400FE620  // Inter-Integrated Circuit Run
// Mode Clock Gating Control
#define SYSCTL_RCGCUSB          0x400FE628  // Universal Serial Bus Run Mode
// Clock Gating Control
#define SYSCTL_RCGCCAN          0x400FE634  // Controller Area Network Run Mode
// Clock Gating Control
#define SYSCTL_RCGCADC          0x400FE638  // Analog-to-Digital Converter Run
// Mode Clock Gating Control
#define SYSCTL_RCGCACMP         0x400FE63C  // Analog Comparator Run Mode Clock
// Gating Control
#define SYSCTL_RCGCPWM          0x400FE640  // Pulse Width Modulator Run Mode
// Clock Gating Control
#define SYSCTL_RCGCQEI          0x400FE644  // Quadrature Encoder Interface Run
// Mode Clock Gating Control
#define SYSCTL_RCGCEEPROM       0x400FE658  // EEPROM Run Mode Clock Gating
// Control
#define SYSCTL_RCGCWTIMER       0x400FE65C  // 32/64-Bit Wide General-Purpose
// Timer Run Mode Clock Gating
// Control
#define SYSCTL_SCGCWD           0x400FE700  // Watchdog Timer Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCTIMER        0x400FE704  // 16/32-Bit General-Purpose Timer
// Sleep Mode Clock Gating Control
#define SYSCTL_SCGCGPIO         0x400FE708  // General-Purpose Input/Output
// Sleep Mode Clock Gating Control
#define SYSCTL_SCGCDMA          0x400FE70C  // Micro Direct Memory Access Sleep
// Mode Clock Gating Control
#define SYSCTL_SCGCHIB          0x400FE714  // Hibernation Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCUART         0x400FE718  // Universal Asynchronous
// Receiver/Transmitter Sleep Mode
// Clock Gating Control
#define SYSCTL_SCGCSSI          0x400FE71C  // Synchronous Serial Interface
// Sleep Mode Clock Gating Control
#define SYSCTL_SCGCI2C          0x400FE720  // Inter-Integrated Circuit Sleep
// Mode Clock Gating Control
#define SYSCTL_SCGCUSB          0x400FE728  // Universal Serial Bus Sleep Mode
// Clock Gating Control
#define SYSCTL_SCGCCAN          0x400FE734  // Controller Area Network Sleep
// Mode Clock Gating Control
#define SYSCTL_SCGCADC          0x400FE738  // Analog-to-Digital Converter
// Sleep Mode Clock Gating Control
#define SYSCTL_SCGCACMP         0x400FE73C  // Analog Comparator Sleep Mode
// Clock Gating Control
#define SYSCTL_SCGCPWM          0x400FE740  // Pulse Width Modulator Sleep Mode
// Clock Gating Control
#define SYSCTL_SCGCQEI          0x400FE744  // Quadrature Encoder Interface
// Sleep Mode Clock Gating Control
#define SYSCTL_SCGCEEPROM       0x400FE758  // EEPROM Sleep Mode Clock Gating
// Control
#define SYSCTL_SCGCWTIMER       0x400FE75C  // 32/64-Bit Wide General-Purpose
// Timer Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCWD           0x400FE800  // Watchdog Timer Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCTIMER        0x400FE804  // 16/32-Bit General-Purpose Timer
// Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCGPIO         0x400FE808  // General-Purpose Input/Output
// Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCDMA          0x400FE80C  // Micro Direct Memory Access
// Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCHIB          0x400FE814  // Hibernation Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCUART         0x400FE818  // Universal Asynchronous
// Receiver/Transmitter Deep-Sleep
// Mode Clock Gating Control
#define SYSCTL_DCGCSSI          0x400FE81C  // Synchronous Serial Interface
// Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCI2C          0x400FE820  // Inter-Integrated Circuit
// Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCUSB          0x400FE828  // Universal Serial Bus Deep-Sleep
// Mode Clock Gating Control
// Clock Gating Control
#define SYSCTL_DCGCCAN          0x400FE834  // Controller Area Network
// Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCADC          0x400FE838  // Analog-to-Digital Converter
// Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCACMP         0x400FE83C  // Analog Comparator Deep-Sleep
// Mode Clock Gating Control
#define SYSCTL_DCGCPWM          0x400FE840  // Pulse Width Modulator Deep-Sleep
// Mode Clock Gating Control
#define SYSCTL_DCGCQEI          0x400FE844  // Quadrature Encoder Interface
// Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCEEPROM       0x400FE858  // EEPROM Deep-Sleep Mode Clock
// Gating Control
#define SYSCTL_DCGCWTIMER       0x400FE85C  // 32/64-Bit Wide General-Purpose
// Timer Deep-Sleep Mode Clock
#define SYSCTL_PRWD             0x400FEA00  // Watchdog Timer Peripheral Ready
#define SYSCTL_PRTIMER          0x400FEA04  // 16/32-Bit General-Purpose Timer
// Peripheral Ready
#define SYSCTL_PRGPIO           0x400FEA08  // General-Purpose Input/Output
// Peripheral Ready
#define SYSCTL_PRDMA            0x400FEA0C  // Micro Direct Memory Access
// Peripheral Ready
#define SYSCTL_PRHIB            0x400FEA14  // Hibernation Peripheral Ready
#define SYSCTL_PRUART           0x400FEA18  // Universal Asynchronous
// Receiver/Transmitter Peripheral
// Ready
#define SYSCTL_PRSSI            0x400FEA1C  // Synchronous Serial Interface
// Peripheral Ready
#define SYSCTL_PRI2C            0x400FEA20  // Inter-Integrated Circuit
// Peripheral Ready
#define SYSCTL_PRUSB            0x400FEA28  // Universal Serial Bus Peripheral
// Ready
#define SYSCTL_PRCAN            0x400FEA34  // Controller Area Network
// Peripheral Ready
#define SYSCTL_PRADC            0x400FEA38  // Analog-to-Digital Converter
// Peripheral Ready
#define SYSCTL_PRACMP           0x400FEA3C  // Analog Comparator Peripheral
// Ready
#define SYSCTL_PRPWM            0x400FEA40  // Pulse Width Modulator Peripheral
// Ready
#define SYSCTL_PRQEI            0x400FEA44  // Quadrature Encoder Interface
// Peripheral Ready
#define SYSCTL_PREEPROM         0x400FEA58  // EEPROM Peripheral Ready
#define SYSCTL_PRWTIMER         0x400FEA5C  // 32/64-Bit Wide General-Purpose
// Timer Peripheral Ready
#define SYSCTL_DID0_VER_M       0x70000000  // DID0 Version
#define SYSCTL_DID0_VER_1       0x10000000  // Second version of the DID0
// register format.
#define SYSCTL_DID0_CLASS_M     0x00FF0000  // Device Class
#define SYSCTL_DID0_CLASS_TM4C123                                             \
                                0x00050000  // Tiva TM4C123x and TM4E123x
// microcontrollers
#define SYSCTL_DID0_CLASS_TM4C129                                             \
                                0x000A0000  // Tiva(TM) TM4C129-class
// microcontrollers
#define SYSCTL_DID0_MAJ_M       0x0000FF00  // Major Revision
#define SYSCTL_DID0_MAJ_REVA    0x00000000  // Revision A (initial device)
#define SYSCTL_DID0_MAJ_REVB    0x00000100  // Revision B (first base layer
// revision)
#define SYSCTL_DID0_MAJ_REVC    0x00000200  // Revision C (second base layer
// revision)
#define SYSCTL_DID0_MIN_M       0x000000FF  // Minor Revision
#define SYSCTL_DID0_MIN_0       0x00000000  // Initial device, or a major
// revision update
#define SYSCTL_DID0_MIN_1       0x00000001  // First metal layer change
#define SYSCTL_DID0_MIN_2       0x00000002  // Second metal layer change

#define SYSCTL_DID1_VER_M       0xF0000000  // DID1 Version
#define SYSCTL_DID1_VER_1       0x10000000  // fury_ib
#define SYSCTL_DID1_FAM_M       0x0F000000  // Family
#define SYSCTL_DID1_FAM_TIVA    0x00000000  // Tiva family of microcontollers
#define SYSCTL_DID1_PRTNO_M     0x00FF0000  // Part Number
#define SYSCTL_DID1_PRTNO_TM4C123GH6PM                                        \
                                0x00A10000  // TM4C123GH6PM
#define SYSCTL_DID1_PINCNT_M    0x0000E000  // Package Pin Count
#define SYSCTL_DID1_PINCNT_100  0x00004000  // 100-pin LQFP package
#define SYSCTL_DID1_PINCNT_64   0x00006000  // 64-pin LQFP package
#define SYSCTL_DID1_PINCNT_144  0x00008000  // 144-pin LQFP package
#define SYSCTL_DID1_PINCNT_157  0x0000A000  // 157-pin BGA package
#define SYSCTL_DID1_PINCNT_128  0x0000C000  // 128-pin TQFP package
#define SYSCTL_DID1_TEMP_M      0x000000E0  // Temperature Range
#define SYSCTL_DID1_TEMP_I      0x00000020  // Industrial temperature range
#define SYSCTL_DID1_TEMP_E      0x00000040  // Extended temperature range
#define SYSCTL_DID1_TEMP_IE     0x00000060  // Available in both industrial
// temperature range (-40C to 85C)
// and extended temperature range
// (-40C to 105C) devices. See
#define SYSCTL_DID1_PKG_M       0x00000018  // Package Type
#define SYSCTL_DID1_PKG_QFP     0x00000008  // QFP package
#define SYSCTL_DID1_PKG_BGA     0x00000010  // BGA package
#define SYSCTL_DID1_ROHS        0x00000004  // RoHS-Compliance
#define SYSCTL_DID1_QUAL_M      0x00000003  // Qualification Status
#define SYSCTL_DID1_QUAL_ES     0x00000000  // Engineering Sample (unqualified)
#define SYSCTL_DID1_QUAL_PP     0x00000001  // Pilot Production (unqualified)
#define SYSCTL_DID1_QUAL_FQ     0x00000002  // Fully Qualified
#define SYSCTL_DC0_SRAMSZ_M     0xFFFF0000  // SRAM Size
#define SYSCTL_DC0_SRAMSZ_2KB   0x00070000  // 2 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_4KB   0x000F0000  // 4 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_6KB   0x00170000  // 6 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_8KB   0x001F0000  // 8 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_12KB  0x002F0000  // 12 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_16KB  0x003F0000  // 16 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_20KB  0x004F0000  // 20 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_24KB  0x005F0000  // 24 KB of SRAM
#define SYSCTL_DC0_SRAMSZ_32KB  0x007F0000  // 32 KB of SRAM
#define SYSCTL_DC0_FLASHSZ_M    0x0000FFFF  // Flash Size
#define SYSCTL_DC0_FLASHSZ_8KB  0x00000003  // 8 KB of Flash
#define SYSCTL_DC0_FLASHSZ_16KB 0x00000007  // 16 KB of Flash
#define SYSCTL_DC0_FLASHSZ_32KB 0x0000000F  // 32 KB of Flash
#define SYSCTL_DC0_FLASHSZ_64KB 0x0000001F  // 64 KB of Flash
#define SYSCTL_DC0_FLASHSZ_96KB 0x0000002F  // 96 KB of Flash
#define SYSCTL_DC0_FLASHSZ_128K 0x0000003F  // 128 KB of Flash
#define SYSCTL_DC0_FLASHSZ_192K 0x0000005F  // 192 KB of Flash
#define SYSCTL_DC0_FLASHSZ_256K 0x0000007F  // 256 KB of Flash
#define SYSCTL_DC1_WDT1         0x10000000  // Watchdog Timer1 Present
#define SYSCTL_DC1_CAN1         0x02000000  // CAN Module 1 Present
#define SYSCTL_DC1_CAN0         0x01000000  // CAN Module 0 Present
#define SYSCTL_DC1_PWM1         0x00200000  // PWM Module 1 Present
#define SYSCTL_DC1_PWM0         0x00100000  // PWM Module 0 Present
#define SYSCTL_DC1_ADC1         0x00020000  // ADC Module 1 Present
#define SYSCTL_DC1_ADC0         0x00010000  // ADC Module 0 Present
#define SYSCTL_DC1_MINSYSDIV_M  0x0000F000  // System Clock Divider
#define SYSCTL_DC1_MINSYSDIV_80 0x00002000  // Specifies an 80-MHz CPU clock
// with a PLL divider of 2.5
#define SYSCTL_DC1_MINSYSDIV_50 0x00003000  // Specifies a 50-MHz CPU clock
// with a PLL divider of 4
#define SYSCTL_DC1_MINSYSDIV_40 0x00004000  // Specifies a 40-MHz CPU clock
// with a PLL divider of 5
#define SYSCTL_DC1_MINSYSDIV_25 0x00007000  // Specifies a 25-MHz clock with a
// PLL divider of 8
#define SYSCTL_DC1_MINSYSDIV_20 0x00009000  // Specifies a 20-MHz clock with a
// PLL divider of 10
#define SYSCTL_DC1_ADC1SPD_M    0x00000C00  // Max ADC1 Speed
#define SYSCTL_DC1_ADC1SPD_125K 0x00000000  // 125K samples/second
#define SYSCTL_DC1_ADC1SPD_250K 0x00000400  // 250K samples/second
#define SYSCTL_DC1_ADC1SPD_500K 0x00000800  // 500K samples/second
#define SYSCTL_DC1_ADC1SPD_1M   0x00000C00  // 1M samples/second
#define SYSCTL_DC1_ADC0SPD_M    0x00000300  // Max ADC0 Speed
#define SYSCTL_DC1_ADC0SPD_125K 0x00000000  // 125K samples/second
#define SYSCTL_DC1_ADC0SPD_250K 0x00000100  // 250K samples/second
#define SYSCTL_DC1_ADC0SPD_500K 0x00000200  // 500K samples/second
#define SYSCTL_DC1_ADC0SPD_1M   0x00000300  // 1M samples/second
#define SYSCTL_DC1_MPU          0x00000080  // MPU Present
#define SYSCTL_DC1_HIB          0x00000040  // Hibernation Module Present
#define SYSCTL_DC1_TEMP         0x00000020  // Temp Sensor Present
#define SYSCTL_DC1_PLL          0x00000010  // PLL Present
#define SYSCTL_DC1_WDT0         0x00000008  // Watchdog Timer 0 Present
#define SYSCTL_DC1_SWO          0x00000004  // SWO Trace Port Present
#define SYSCTL_DC1_SWD          0x00000002  // SWD Present
#define SYSCTL_DC1_JTAG         0x00000001  // JTAG Present
#define SYSCTL_DC2_EPI0         0x40000000  // EPI Module 0 Present
#define SYSCTL_DC2_I2S0         0x10000000  // I2S Module 0 Present
#define SYSCTL_DC2_COMP2        0x04000000  // Analog Comparator 2 Present
#define SYSCTL_DC2_COMP1        0x02000000  // Analog Comparator 1 Present
#define SYSCTL_DC2_COMP0        0x01000000  // Analog Comparator 0 Present
#define SYSCTL_DC2_TIMER3       0x00080000  // Timer Module 3 Present
#define SYSCTL_DC2_TIMER2       0x00040000  // Timer Module 2 Present
#define SYSCTL_DC2_TIMER1       0x00020000  // Timer Module 1 Present
#define SYSCTL_DC2_TIMER0       0x00010000  // Timer Module 0 Present
#define SYSCTL_DC2_I2C1HS       0x00008000  // I2C Module 1 Speed
#define SYSCTL_DC2_I2C1         0x00004000  // I2C Module 1 Present
#define SYSCTL_DC2_I2C0HS       0x00002000  // I2C Module 0 Speed
#define SYSCTL_DC2_I2C0         0x00001000  // I2C Module 0 Present
#define SYSCTL_DC2_QEI1         0x00000200  // QEI Module 1 Present
#define SYSCTL_DC2_QEI0         0x00000100  // QEI Module 0 Present
#define SYSCTL_DC2_SSI1         0x00000020  // SSI Module 1 Present
#define SYSCTL_DC2_SSI0         0x00000010  // SSI Module 0 Present
#define SYSCTL_DC2_UART2        0x00000004  // UART Module 2 Present
#define SYSCTL_DC2_UART1        0x00000002  // UART Module 1 Present
#define SYSCTL_DC2_UART0        0x00000001  // UART Module 0 Present
#define SYSCTL_DC3_32KHZ        0x80000000  // 32KHz Input Clock Available
#define SYSCTL_DC3_CCP5         0x20000000  // T2CCP1 Pin Present
#define SYSCTL_DC3_CCP4         0x10000000  // T2CCP0 Pin Present
#define SYSCTL_DC3_CCP3         0x08000000  // T1CCP1 Pin Present
#define SYSCTL_DC3_CCP2         0x04000000  // T1CCP0 Pin Present
#define SYSCTL_DC3_CCP1         0x02000000  // T0CCP1 Pin Present
#define SYSCTL_DC3_CCP0         0x01000000  // T0CCP0 Pin Present
#define SYSCTL_DC3_ADC0AIN7     0x00800000  // ADC Module 0 AIN7 Pin Present
#define SYSCTL_DC3_ADC0AIN6     0x00400000  // ADC Module 0 AIN6 Pin Present
#define SYSCTL_DC3_ADC0AIN5     0x00200000  // ADC Module 0 AIN5 Pin Present
#define SYSCTL_DC3_ADC0AIN4     0x00100000  // ADC Module 0 AIN4 Pin Present
#define SYSCTL_DC3_ADC0AIN3     0x00080000  // ADC Module 0 AIN3 Pin Present
#define SYSCTL_DC3_ADC0AIN2     0x00040000  // ADC Module 0 AIN2 Pin Present
#define SYSCTL_DC3_ADC0AIN1     0x00020000  // ADC Module 0 AIN1 Pin Present
#define SYSCTL_DC3_ADC0AIN0     0x00010000  // ADC Module 0 AIN0 Pin Present
#define SYSCTL_DC3_PWMFAULT     0x00008000  // PWM Fault Pin Present
#define SYSCTL_DC3_C2O          0x00004000  // C2o Pin Present
#define SYSCTL_DC3_C2PLUS       0x00002000  // C2+ Pin Present
#define SYSCTL_DC3_C2MINUS      0x00001000  // C2- Pin Present
#define SYSCTL_DC3_C1O          0x00000800  // C1o Pin Present
#define SYSCTL_DC3_C1PLUS       0x00000400  // C1+ Pin Present
#define SYSCTL_DC3_C1MINUS      0x00000200  // C1- Pin Present
#define SYSCTL_DC3_C0O          0x00000100  // C0o Pin Present
#define SYSCTL_DC3_C0PLUS       0x00000080  // C0+ Pin Present
#define SYSCTL_DC3_C0MINUS      0x00000040  // C0- Pin Present
#define SYSCTL_DC3_PWM5         0x00000020  // PWM5 Pin Present
#define SYSCTL_DC3_PWM4         0x00000010  // PWM4 Pin Present
#define SYSCTL_DC3_PWM3         0x00000008  // PWM3 Pin Present
#define SYSCTL_DC3_PWM2         0x00000004  // PWM2 Pin Present
#define SYSCTL_DC3_PWM1         0x00000002  // PWM1 Pin Present
#define SYSCTL_DC3_PWM0         0x00000001  // PWM0 Pin Present
#define SYSCTL_DC4_EPHY0        0x40000000  // Ethernet PHY Layer 0 Present
#define SYSCTL_DC4_EMAC0        0x10000000  // Ethernet MAC Layer 0 Present
#define SYSCTL_DC4_E1588        0x01000000  // 1588 Capable
#define SYSCTL_DC4_PICAL        0x00040000  // PIOSC Calibrate
#define SYSCTL_DC4_CCP7         0x00008000  // T3CCP1 Pin Present
#define SYSCTL_DC4_CCP6         0x00004000  // T3CCP0 Pin Present
#define SYSCTL_DC4_UDMA         0x00002000  // Micro-DMA Module Present
#define SYSCTL_DC4_ROM          0x00001000  // Internal Code ROM Present
#define SYSCTL_DC4_GPIOJ        0x00000100  // GPIO Port J Present
#define SYSCTL_DC4_GPIOH        0x00000080  // GPIO Port H Present
#define SYSCTL_DC4_GPIOG        0x00000040  // GPIO Port G Present
#define SYSCTL_DC4_GPIOF        0x00000020  // GPIO Port F Present
#define SYSCTL_DC4_GPIOE        0x00000010  // GPIO Port E Present
#define SYSCTL_DC4_GPIOD        0x00000008  // GPIO Port D Present
#define SYSCTL_DC4_GPIOC        0x00000004  // GPIO Port C Present
#define SYSCTL_DC4_GPIOB        0x00000002  // GPIO Port B Present
#define SYSCTL_DC4_GPIOA        0x00000001  // GPIO Port A Present
#define SYSCTL_DC5_PWMFAULT3    0x08000000  // PWM Fault 3 Pin Present
#define SYSCTL_DC5_PWMFAULT2    0x04000000  // PWM Fault 2 Pin Present
#define SYSCTL_DC5_PWMFAULT1    0x02000000  // PWM Fault 1 Pin Present
#define SYSCTL_DC5_PWMFAULT0    0x01000000  // PWM Fault 0 Pin Present
#define SYSCTL_DC5_PWMEFLT      0x00200000  // PWM Extended Fault Active
#define SYSCTL_DC5_PWMESYNC     0x00100000  // PWM Extended SYNC Active
#define SYSCTL_DC5_PWM7         0x00000080  // PWM7 Pin Present
#define SYSCTL_DC5_PWM6         0x00000040  // PWM6 Pin Present
#define SYSCTL_DC5_PWM5         0x00000020  // PWM5 Pin Present
#define SYSCTL_DC5_PWM4         0x00000010  // PWM4 Pin Present
#define SYSCTL_DC5_PWM3         0x00000008  // PWM3 Pin Present
#define SYSCTL_DC5_PWM2         0x00000004  // PWM2 Pin Present
#define SYSCTL_DC5_PWM1         0x00000002  // PWM1 Pin Present
#define SYSCTL_DC5_PWM0         0x00000001  // PWM0 Pin Present
#define SYSCTL_DC6_USB0PHY      0x00000010  // USB Module 0 PHY Present
#define SYSCTL_DC6_USB0_M       0x00000003  // USB Module 0 Present
#define SYSCTL_DC6_USB0_DEV     0x00000001  // USB0 is Device Only
#define SYSCTL_DC6_USB0_HOSTDEV 0x00000002  // USB is Device or Host
#define SYSCTL_DC6_USB0_OTG     0x00000003  // USB0 is OTG
#define SYSCTL_DC7_DMACH30      0x40000000  // DMA Channel 30
#define SYSCTL_DC7_DMACH29      0x20000000  // DMA Channel 29
#define SYSCTL_DC7_DMACH28      0x10000000  // DMA Channel 28
#define SYSCTL_DC7_DMACH27      0x08000000  // DMA Channel 27
#define SYSCTL_DC7_DMACH26      0x04000000  // DMA Channel 26
#define SYSCTL_DC7_DMACH25      0x02000000  // DMA Channel 25
#define SYSCTL_DC7_DMACH24      0x01000000  // DMA Channel 24
#define SYSCTL_DC7_DMACH23      0x00800000  // DMA Channel 23
#define SYSCTL_DC7_DMACH22      0x00400000  // DMA Channel 22
#define SYSCTL_DC7_DMACH21      0x00200000  // DMA Channel 21
#define SYSCTL_DC7_DMACH20      0x00100000  // DMA Channel 20
#define SYSCTL_DC7_DMACH19      0x00080000  // DMA Channel 19
#define SYSCTL_DC7_DMACH18      0x00040000  // DMA Channel 18
#define SYSCTL_DC7_DMACH17      0x00020000  // DMA Channel 17
#define SYSCTL_DC7_DMACH16      0x00010000  // DMA Channel 16
#define SYSCTL_DC7_DMACH15      0x00008000  // DMA Channel 15
#define SYSCTL_DC7_DMACH14      0x00004000  // DMA Channel 14
#define SYSCTL_DC7_DMACH13      0x00002000  // DMA Channel 13
#define SYSCTL_DC7_DMACH12      0x00001000  // DMA Channel 12
#define SYSCTL_DC7_DMACH11      0x00000800  // DMA Channel 11
#define SYSCTL_DC7_DMACH10      0x00000400  // DMA Channel 10
#define SYSCTL_DC7_DMACH9       0x00000200  // DMA Channel 9
#define SYSCTL_DC7_DMACH8       0x00000100  // DMA Channel 8
#define SYSCTL_DC7_DMACH7       0x00000080  // DMA Channel 7
#define SYSCTL_DC7_DMACH6       0x00000040  // DMA Channel 6
#define SYSCTL_DC7_DMACH5       0x00000020  // DMA Channel 5
#define SYSCTL_DC7_DMACH4       0x00000010  // DMA Channel 4
#define SYSCTL_DC7_DMACH3       0x00000008  // DMA Channel 3
#define SYSCTL_DC7_DMACH2       0x00000004  // DMA Channel 2
#define SYSCTL_DC7_DMACH1       0x00000002  // DMA Channel 1
#define SYSCTL_DC7_DMACH0       0x00000001  // DMA Channel 0
#define SYSCTL_DC8_ADC1AIN15    0x80000000  // ADC Module 1 AIN15 Pin Present
#define SYSCTL_DC8_ADC1AIN14    0x40000000  // ADC Module 1 AIN14 Pin Present
#define SYSCTL_DC8_ADC1AIN13    0x20000000  // ADC Module 1 AIN13 Pin Present
#define SYSCTL_DC8_ADC1AIN12    0x10000000  // ADC Module 1 AIN12 Pin Present
#define SYSCTL_DC8_ADC1AIN11    0x08000000  // ADC Module 1 AIN11 Pin Present
#define SYSCTL_DC8_ADC1AIN10    0x04000000  // ADC Module 1 AIN10 Pin Present
#define SYSCTL_DC8_ADC1AIN9     0x02000000  // ADC Module 1 AIN9 Pin Present
#define SYSCTL_DC8_ADC1AIN8     0x01000000  // ADC Module 1 AIN8 Pin Present
#define SYSCTL_DC8_ADC1AIN7     0x00800000  // ADC Module 1 AIN7 Pin Present
#define SYSCTL_DC8_ADC1AIN6     0x00400000  // ADC Module 1 AIN6 Pin Present
#define SYSCTL_DC8_ADC1AIN5     0x00200000  // ADC Module 1 AIN5 Pin Present
#define SYSCTL_DC8_ADC1AIN4     0x00100000  // ADC Module 1 AIN4 Pin Present
#define SYSCTL_DC8_ADC1AIN3     0x00080000  // ADC Module 1 AIN3 Pin Present
#define SYSCTL_DC8_ADC1AIN2     0x00040000  // ADC Module 1 AIN2 Pin Present
#define SYSCTL_DC8_ADC1AIN1     0x00020000  // ADC Module 1 AIN1 Pin Present
#define SYSCTL_DC8_ADC1AIN0     0x00010000  // ADC Module 1 AIN0 Pin Present
#define SYSCTL_DC8_ADC0AIN15    0x00008000  // ADC Module 0 AIN15 Pin Present
#define SYSCTL_DC8_ADC0AIN14    0x00004000  // ADC Module 0 AIN14 Pin Present
#define SYSCTL_DC8_ADC0AIN13    0x00002000  // ADC Module 0 AIN13 Pin Present
#define SYSCTL_DC8_ADC0AIN12    0x00001000  // ADC Module 0 AIN12 Pin Present
#define SYSCTL_DC8_ADC0AIN11    0x00000800  // ADC Module 0 AIN11 Pin Present
#define SYSCTL_DC8_ADC0AIN10    0x00000400  // ADC Module 0 AIN10 Pin Present
#define SYSCTL_DC8_ADC0AIN9     0x00000200  // ADC Module 0 AIN9 Pin Present
#define SYSCTL_DC8_ADC0AIN8     0x00000100  // ADC Module 0 AIN8 Pin Present
#define SYSCTL_DC8_ADC0AIN7     0x00000080  // ADC Module 0 AIN7 Pin Present
#define SYSCTL_DC8_ADC0AIN6     0x00000040  // ADC Module 0 AIN6 Pin Present
#define SYSCTL_DC8_ADC0AIN5     0x00000020  // ADC Module 0 AIN5 Pin Present
#define SYSCTL_DC8_ADC0AIN4     0x00000010  // ADC Module 0 AIN4 Pin Present
#define SYSCTL_DC8_ADC0AIN3     0x00000008  // ADC Module 0 AIN3 Pin Present
#define SYSCTL_DC8_ADC0AIN2     0x00000004  // ADC Module 0 AIN2 Pin Present
#define SYSCTL_DC8_ADC0AIN1     0x00000002  // ADC Module 0 AIN1 Pin Present
#define SYSCTL_DC8_ADC0AIN0     0x00000001  // ADC Module 0 AIN0 Pin Present
#define SYSCTL_PBORCTL_BOR0     0x00000004  // VDD under BOR0 Event Action
#define SYSCTL_PBORCTL_BOR1     0x00000002  // VDD under BOR1 Event Action
#define SYSCTL_SRCR0_WDT1       0x10000000  // WDT1 Reset Control
#define SYSCTL_SRCR0_CAN1       0x02000000  // CAN1 Reset Control
#define SYSCTL_SRCR0_CAN0       0x01000000  // CAN0 Reset Control
#define SYSCTL_SRCR0_PWM0       0x00100000  // PWM Reset Control
#define SYSCTL_SRCR0_ADC1       0x00020000  // ADC1 Reset Control
#define SYSCTL_SRCR0_ADC0       0x00010000  // ADC0 Reset Control
#define SYSCTL_SRCR0_HIB        0x00000040  // HIB Reset Control
#define SYSCTL_SRCR0_WDT0       0x00000008  // WDT0 Reset Control
#define SYSCTL_SRCR1_COMP1      0x02000000  // Analog Comp 1 Reset Control
#define SYSCTL_SRCR1_COMP0      0x01000000  // Analog Comp 0 Reset Control
#define SYSCTL_SRCR1_TIMER3     0x00080000  // Timer 3 Reset Control
#define SYSCTL_SRCR1_TIMER2     0x00040000  // Timer 2 Reset Control
#define SYSCTL_SRCR1_TIMER1     0x00020000  // Timer 1 Reset Control
#define SYSCTL_SRCR1_TIMER0     0x00010000  // Timer 0 Reset Control
#define SYSCTL_SRCR1_I2C1       0x00004000  // I2C1 Reset Control
#define SYSCTL_SRCR1_I2C0       0x00001000  // I2C0 Reset Control
#define SYSCTL_SRCR1_QEI1       0x00000200  // QEI1 Reset Control
#define SYSCTL_SRCR1_QEI0       0x00000100  // QEI0 Reset Control
#define SYSCTL_SRCR1_SSI1       0x00000020  // SSI1 Reset Control
#define SYSCTL_SRCR1_SSI0       0x00000010  // SSI0 Reset Control
#define SYSCTL_SRCR1_UART2      0x00000004  // UART2 Reset Control
#define SYSCTL_SRCR1_UART1      0x00000002  // UART1 Reset Control
#define SYSCTL_SRCR1_UART0      0x00000001  // UART0 Reset Control
#define SYSCTL_SRCR2_USB0       0x00010000  // USB0 Reset Control
#define SYSCTL_SRCR2_UDMA       0x00002000  // Micro-DMA Reset Control
#define SYSCTL_SRCR2_GPIOF      0x00000020  // Port F Reset Control
#define SYSCTL_SRCR2_GPIOE      0x00000010  // Port E Reset Control
#define SYSCTL_SRCR2_GPIOD      0x00000008  // Port D Reset Control
#define SYSCTL_SRCR2_GPIOC      0x00000004  // Port C Reset Control
#define SYSCTL_SRCR2_GPIOB      0x00000002  // Port B Reset Control
#define SYSCTL_SRCR2_GPIOA      0x00000001  // Port A Reset Control
#define SYSCTL_RIS_BOR0RIS      0x00000800  // VDD under BOR0 Raw Interrupt
// Status
#define SYSCTL_RIS_VDDARIS      0x00000400  // VDDA Power OK Event Raw
// Interrupt Status
#define SYSCTL_RIS_MOSCPUPRIS   0x00000100  // MOSC Power Up Raw Interrupt
// Status
#define SYSCTL_RIS_USBPLLLRIS   0x00000080  // USB PLL Lock Raw Interrupt
// Status
#define SYSCTL_RIS_PLLLRIS      0x00000040  // PLL Lock Raw Interrupt Status
#define SYSCTL_RIS_MOFRIS       0x00000008  // Main Oscillator Failure Raw
// Interrupt Status
#define SYSCTL_RIS_BOR1RIS      0x00000002  // VDD under BOR1 Raw Interrupt
#define SYSCTL_IMC_BOR0IM       0x00000800  // VDD under BOR0 Interrupt Mask
#define SYSCTL_IMC_VDDAIM       0x00000400  // VDDA Power OK Interrupt Mask
#define SYSCTL_IMC_MOSCPUPIM    0x00000100  // MOSC Power Up Interrupt Mask
#define SYSCTL_IMC_USBPLLLIM    0x00000080  // USB PLL Lock Interrupt Mask
#define SYSCTL_IMC_PLLLIM       0x00000040  // PLL Lock Interrupt Mask
#define SYSCTL_IMC_MOFIM        0x00000008  // Main Oscillator Failure
// Interrupt Mask
#define SYSCTL_IMC_BOR1IM       0x00000002  // VDD under BOR1 Interrupt Mask
#define SYSCTL_MISC_BOR0MIS     0x00000800  // VDD under BOR0 Masked Interrupt
// Status
#define SYSCTL_MISC_VDDAMIS     0x00000400  // VDDA Power OK Masked Interrupt
// Status
#define SYSCTL_MISC_MOSCPUPMIS  0x00000100  // MOSC Power Up Masked Interrupt
// Status
#define SYSCTL_MISC_USBPLLLMIS  0x00000080  // USB PLL Lock Masked Interrupt
// Status
#define SYSCTL_MISC_PLLLMIS     0x00000040  // PLL Lock Masked Interrupt Status
#define SYSCTL_MISC_MOFMIS      0x00000008  // Main Oscillator Failure Masked
// Interrupt Status
#define SYSCTL_MISC_BOR1MIS     0x00000002  // VDD under BOR1 Masked Interrupt
#define SYSCTL_RESC_MOSCFAIL    0x00010000  // MOSC Failure Reset
#define SYSCTL_RESC_WDT1        0x00000020  // Watchdog Timer 1 Reset
#define SYSCTL_RESC_SW          0x00000010  // Software Reset
#define SYSCTL_RESC_WDT0        0x00000008  // Watchdog Timer 0 Reset
#define SYSCTL_RESC_BOR         0x00000004  // Brown-Out Reset
#define SYSCTL_RESC_POR         0x00000002  // Power-On Reset
#define SYSCTL_RESC_EXT         0x00000001  // External Reset
#define SYSCTL_RCC_ACG          0x08000000  // Auto Clock Gating
#define SYSCTL_RCC_SYSDIV_M     0x07800000  // System Clock Divisor
#define SYSCTL_RCC_USESYSDIV    0x00400000  // Enable System Clock Divider
#define SYSCTL_RCC_USEPWMDIV    0x00100000  // Enable PWM Clock Divisor
#define SYSCTL_RCC_PWMDIV_M     0x000E0000  // PWM Unit Clock Divisor
#define SYSCTL_RCC_PWMDIV_2     0x00000000  // PWM clock /2
#define SYSCTL_RCC_PWMDIV_4     0x00020000  // PWM clock /4
#define SYSCTL_RCC_PWMDIV_8     0x00040000  // PWM clock /8
#define SYSCTL_RCC_PWMDIV_16    0x00060000  // PWM clock /16
#define SYSCTL_RCC_PWMDIV_32    0x00080000  // PWM clock /32
#define SYSCTL_RCC_PWMDIV_64    0x000A0000  // PWM clock /64
#define SYSCTL_RCC_PWRDN        0x00002000  // PLL Power Down
#define SYSCTL_RCC_BYPASS       0x00000800  // PLL Bypass
#define SYSCTL_RCC_XTAL_M       0x000007C0  // Crystal Value
#define SYSCTL_RCC_XTAL_4MHZ    0x00000180  // 4 MHz
#define SYSCTL_RCC_XTAL_4_09MHZ 0x000001C0  // 4.096 MHz
#define SYSCTL_RCC_XTAL_4_91MHZ 0x00000200  // 4.9152 MHz
#define SYSCTL_RCC_XTAL_5MHZ    0x00000240  // 5 MHz
#define SYSCTL_RCC_XTAL_5_12MHZ 0x00000280  // 5.12 MHz
#define SYSCTL_RCC_XTAL_6MHZ    0x000002C0  // 6 MHz
#define SYSCTL_RCC_XTAL_6_14MHZ 0x00000300  // 6.144 MHz
#define SYSCTL_RCC_XTAL_7_37MHZ 0x00000340  // 7.3728 MHz
#define SYSCTL_RCC_XTAL_8MHZ    0x00000380  // 8 MHz
#define SYSCTL_RCC_XTAL_8_19MHZ 0x000003C0  // 8.192 MHz
#define SYSCTL_RCC_XTAL_10MHZ   0x00000400  // 10 MHz
#define SYSCTL_RCC_XTAL_12MHZ   0x00000440  // 12 MHz
#define SYSCTL_RCC_XTAL_12_2MHZ 0x00000480  // 12.288 MHz
#define SYSCTL_RCC_XTAL_13_5MHZ 0x000004C0  // 13.56 MHz
#define SYSCTL_RCC_XTAL_14_3MHZ 0x00000500  // 14.31818 MHz
#define SYSCTL_RCC_XTAL_16MHZ   0x00000540  // 16 MHz
#define SYSCTL_RCC_XTAL_16_3MHZ 0x00000580  // 16.384 MHz
#define SYSCTL_RCC_XTAL_18MHZ   0x000005C0  // 18.0 MHz (USB)
#define SYSCTL_RCC_XTAL_20MHZ   0x00000600  // 20.0 MHz (USB)
#define SYSCTL_RCC_XTAL_24MHZ   0x00000640  // 24.0 MHz (USB)
#define SYSCTL_RCC_XTAL_25MHZ   0x00000680  // 25.0 MHz (USB)
#define SYSCTL_RCC_OSCSRC_M     0x00000030  // Oscillator Source
#define SYSCTL_RCC_OSCSRC_MAIN  0x00000000  // MOSC
#define SYSCTL_RCC_OSCSRC_INT   0x00000010  // IOSC
#define SYSCTL_RCC_OSCSRC_INT4  0x00000020  // IOSC/4
#define SYSCTL_RCC_OSCSRC_30    0x00000030  // LFIOSC
#define SYSCTL_RCC_MOSCDIS      0x00000001  // Main Oscillator Disable
#define SYSCTL_RCC_SYSDIV_S     23
#define SYSCTL_GPIOHBCTL_PORTF  0x00000020  // Port F Advanced High-Performance
// Bus
#define SYSCTL_GPIOHBCTL_PORTE  0x00000010  // Port E Advanced High-Performance
// Bus
#define SYSCTL_GPIOHBCTL_PORTD  0x00000008  // Port D Advanced High-Performance
// Bus
#define SYSCTL_GPIOHBCTL_PORTC  0x00000004  // Port C Advanced High-Performance
// Bus
#define SYSCTL_GPIOHBCTL_PORTB  0x00000002  // Port B Advanced High-Performance
// Bus
#define SYSCTL_GPIOHBCTL_PORTA  0x00000001  // Port A Advanced High-Performance
// Bus
#define SYSCTL_RCC2_USERCC2     0x80000000  // Use RCC2
#define SYSCTL_RCC2_DIV400      0x40000000  // Divide PLL as 400 MHz vs. 200
// MHz
#define SYSCTL_RCC2_SYSDIV2_M   0x1F800000  // System Clock Divisor 2
#define SYSCTL_RCC2_SYSDIV2LSB  0x00400000  // Additional LSB for SYSDIV2
#define SYSCTL_RCC2_USBPWRDN    0x00004000  // Power-Down USB PLL
#define SYSCTL_RCC2_PWRDN2      0x00002000  // Power-Down PLL 2
#define SYSCTL_RCC2_BYPASS2     0x00000800  // PLL Bypass 2
#define SYSCTL_RCC2_OSCSRC2_M   0x00000070  // Oscillator Source 2
#define SYSCTL_RCC2_OSCSRC2_MO  0x00000000  // MOSC
#define SYSCTL_RCC2_OSCSRC2_IO  0x00000010  // PIOSC
#define SYSCTL_RCC2_OSCSRC2_IO4 0x00000020  // PIOSC/4
#define SYSCTL_RCC2_OSCSRC2_30  0x00000030  // LFIOSC
#define SYSCTL_RCC2_OSCSRC2_32  0x00000070  // 32.768 kHz
#define SYSCTL_RCC2_SYSDIV2_S   23
#define SYSCTL_MOSCCTL_NOXTAL   0x00000004  // No Crystal Connected
#define SYSCTL_MOSCCTL_MOSCIM   0x00000002  // MOSC Failure Action
#define SYSCTL_MOSCCTL_CVAL     0x00000001  // Clock Validation for MOSC
#define SYSCTL_RCGC0_WDT1       0x10000000  // WDT1 Clock Gating Control
#define SYSCTL_RCGC0_CAN1       0x02000000  // CAN1 Clock Gating Control
#define SYSCTL_RCGC0_CAN0       0x01000000  // CAN0 Clock Gating Control
#define SYSCTL_RCGC0_PWM0       0x00100000  // PWM Clock Gating Control
#define SYSCTL_RCGC0_ADC1       0x00020000  // ADC1 Clock Gating Control
#define SYSCTL_RCGC0_ADC0       0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_RCGC0_ADC1SPD_M  0x00000C00  // ADC1 Sample Speed
#define SYSCTL_RCGC0_ADC1SPD_125K                                             \
                                0x00000000  // 125K samples/second
#define SYSCTL_RCGC0_ADC1SPD_250K                                             \
                                0x00000400  // 250K samples/second
#define SYSCTL_RCGC0_ADC1SPD_500K                                             \
                                0x00000800  // 500K samples/second
#define SYSCTL_RCGC0_ADC1SPD_1M 0x00000C00  // 1M samples/second
#define SYSCTL_RCGC0_ADC0SPD_M  0x00000300  // ADC0 Sample Speed
#define SYSCTL_RCGC0_ADC0SPD_125K                                             \
                                0x00000000  // 125K samples/second
#define SYSCTL_RCGC0_ADC0SPD_250K                                             \
                                0x00000100  // 250K samples/second
#define SYSCTL_RCGC0_ADC0SPD_500K                                             \
                                0x00000200  // 500K samples/second
#define SYSCTL_RCGC0_ADC0SPD_1M 0x00000300  // 1M samples/second
#define SYSCTL_RCGC0_HIB        0x00000040  // HIB Clock Gating Control
#define SYSCTL_RCGC0_WDT0       0x00000008  // WDT0 Clock Gating Control
#define SYSCTL_RCGC1_COMP1      0x02000000  // Analog Comparator 1 Clock Gating
#define SYSCTL_RCGC1_COMP0      0x01000000  // Analog Comparator 0 Clock Gating
#define SYSCTL_RCGC1_TIMER3     0x00080000  // Timer 3 Clock Gating Control
#define SYSCTL_RCGC1_TIMER2     0x00040000  // Timer 2 Clock Gating Control
#define SYSCTL_RCGC1_TIMER1     0x00020000  // Timer 1 Clock Gating Control
#define SYSCTL_RCGC1_TIMER0     0x00010000  // Timer 0 Clock Gating Control
#define SYSCTL_RCGC1_I2C1       0x00004000  // I2C1 Clock Gating Control
#define SYSCTL_RCGC1_I2C0       0x00001000  // I2C0 Clock Gating Control
#define SYSCTL_RCGC1_QEI1       0x00000200  // QEI1 Clock Gating Control
#define SYSCTL_RCGC1_QEI0       0x00000100  // QEI0 Clock Gating Control
#define SYSCTL_RCGC1_SSI1       0x00000020  // SSI1 Clock Gating Control
#define SYSCTL_RCGC1_SSI0       0x00000010  // SSI0 Clock Gating Control
#define SYSCTL_RCGC1_UART2      0x00000004  // UART2 Clock Gating Control
#define SYSCTL_RCGC1_UART1      0x00000002  // UART1 Clock Gating Control
#define SYSCTL_RCGC1_UART0      0x00000001  // UART0 Clock Gating Control
#define SYSCTL_RCGC2_USB0       0x00010000  // USB0 Clock Gating Control
#define SYSCTL_RCGC2_UDMA       0x00002000  // Micro-DMA Clock Gating Control
#define SYSCTL_RCGC2_GPIOF      0x00000020  // Port F Clock Gating Control
#define SYSCTL_RCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_RCGC2_GPIOD      0x00000008  // Port D Clock Gating Control
#define SYSCTL_RCGC2_GPIOC      0x00000004  // Port C Clock Gating Control
#define SYSCTL_RCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
#define SYSCTL_RCGC2_GPIOA      0x00000001  // Port A Clock Gating Control
#define SYSCTL_SCGC0_WDT1       0x10000000  // WDT1 Clock Gating Control
#define SYSCTL_SCGC0_CAN1       0x02000000  // CAN1 Clock Gating Control
#define SYSCTL_SCGC0_CAN0       0x01000000  // CAN0 Clock Gating Control
#define SYSCTL_SCGC0_PWM0       0x00100000  // PWM Clock Gating Control
#define SYSCTL_SCGC0_ADC1       0x00020000  // ADC1 Clock Gating Control
#define SYSCTL_SCGC0_ADC0       0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_SCGC0_HIB        0x00000040  // HIB Clock Gating Control
#define SYSCTL_SCGC0_WDT0       0x00000008  // WDT0 Clock Gating Control
#define SYSCTL_SCGC1_COMP1      0x02000000  // Analog Comparator 1 Clock Gating
#define SYSCTL_SCGC1_COMP0      0x01000000  // Analog Comparator 0 Clock Gating
#define SYSCTL_SCGC1_TIMER3     0x00080000  // Timer 3 Clock Gating Control
#define SYSCTL_SCGC1_TIMER2     0x00040000  // Timer 2 Clock Gating Control
#define SYSCTL_SCGC1_TIMER1     0x00020000  // Timer 1 Clock Gating Control
#define SYSCTL_SCGC1_TIMER0     0x00010000  // Timer 0 Clock Gating Control
#define SYSCTL_SCGC1_I2C1       0x00004000  // I2C1 Clock Gating Control
#define SYSCTL_SCGC1_I2C0       0x00001000  // I2C0 Clock Gating Control
#define SYSCTL_SCGC1_QEI1       0x00000200  // QEI1 Clock Gating Control
#define SYSCTL_SCGC1_QEI0       0x00000100  // QEI0 Clock Gating Control
#define SYSCTL_SCGC1_SSI1       0x00000020  // SSI1 Clock Gating Control
#define SYSCTL_SCGC1_SSI0       0x00000010  // SSI0 Clock Gating Control
#define SYSCTL_SCGC1_UART2      0x00000004  // UART2 Clock Gating Control
#define SYSCTL_SCGC1_UART1      0x00000002  // UART1 Clock Gating Control
#define SYSCTL_SCGC1_UART0      0x00000001  // UART0 Clock Gating Control
#define SYSCTL_SCGC2_USB0       0x00010000  // USB0 Clock Gating Control
#define SYSCTL_SCGC2_UDMA       0x00002000  // Micro-DMA Clock Gating Control
#define SYSCTL_SCGC2_GPIOF      0x00000020  // Port F Clock Gating Control
#define SYSCTL_SCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_SCGC2_GPIOD      0x00000008  // Port D Clock Gating Control
#define SYSCTL_SCGC2_GPIOC      0x00000004  // Port C Clock Gating Control
#define SYSCTL_SCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
#define SYSCTL_SCGC2_GPIOA      0x00000001  // Port A Clock Gating Control
#define SYSCTL_DCGC0_WDT1       0x10000000  // WDT1 Clock Gating Control
#define SYSCTL_DCGC0_CAN1       0x02000000  // CAN1 Clock Gating Control
#define SYSCTL_DCGC0_CAN0       0x01000000  // CAN0 Clock Gating Control
#define SYSCTL_DCGC0_PWM0       0x00100000  // PWM Clock Gating Control
#define SYSCTL_DCGC0_ADC1       0x00020000  // ADC1 Clock Gating Control
#define SYSCTL_DCGC0_ADC0       0x00010000  // ADC0 Clock Gating Control
#define SYSCTL_DCGC0_HIB        0x00000040  // HIB Clock Gating Control
#define SYSCTL_DCGC0_WDT0       0x00000008  // WDT0 Clock Gating Control
#define SYSCTL_DCGC1_COMP1      0x02000000  // Analog Comparator 1 Clock Gating
#define SYSCTL_DCGC1_COMP0      0x01000000  // Analog Comparator 0 Clock Gating
#define SYSCTL_DCGC1_TIMER3     0x00080000  // Timer 3 Clock Gating Control
#define SYSCTL_DCGC1_TIMER2     0x00040000  // Timer 2 Clock Gating Control
#define SYSCTL_DCGC1_TIMER1     0x00020000  // Timer 1 Clock Gating Control
#define SYSCTL_DCGC1_TIMER0     0x00010000  // Timer 0 Clock Gating Control
#define SYSCTL_DCGC1_I2C1       0x00004000  // I2C1 Clock Gating Control
#define SYSCTL_DCGC1_I2C0       0x00001000  // I2C0 Clock Gating Control
#define SYSCTL_DCGC1_QEI1       0x00000200  // QEI1 Clock Gating Control
#define SYSCTL_DCGC1_QEI0       0x00000100  // QEI0 Clock Gating Control
#define SYSCTL_DCGC1_SSI1       0x00000020  // SSI1 Clock Gating Control
#define SYSCTL_DCGC1_SSI0       0x00000010  // SSI0 Clock Gating Control
#define SYSCTL_DCGC1_UART2      0x00000004  // UART2 Clock Gating Control
#define SYSCTL_DCGC1_UART1      0x00000002  // UART1 Clock Gating Control
#define SYSCTL_DCGC1_UART0      0x00000001  // UART0 Clock Gating Control
#define SYSCTL_DCGC2_USB0       0x00010000  // USB0 Clock Gating Control
#define SYSCTL_DCGC2_UDMA       0x00002000  // Micro-DMA Clock Gating Control
#define SYSCTL_DCGC2_GPIOF      0x00000020  // Port F Clock Gating Control
#define SYSCTL_DCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_DCGC2_GPIOD      0x00000008  // Port D Clock Gating Control
#define SYSCTL_DCGC2_GPIOC      0x00000004  // Port C Clock Gating Control
#define SYSCTL_DCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
#define SYSCTL_DCGC2_GPIOA      0x00000001  // Port A Clock Gating Control
#define SYSCTL_DSLPCLKCFG_D_M   0x1F800000  // Divider Field Override
#define SYSCTL_DSLPCLKCFG_O_M   0x00000070  // Clock Source
#define SYSCTL_DSLPCLKCFG_O_IGN 0x00000000  // MOSC
#define SYSCTL_DSLPCLKCFG_O_IO  0x00000010  // PIOSC
#define SYSCTL_DSLPCLKCFG_O_30  0x00000030  // LFIOSC
#define SYSCTL_DSLPCLKCFG_O_32  0x00000070  // 32.768 kHz
#define SYSCTL_DSLPCLKCFG_PIOSCPD                                             \
                                0x00000002  // PIOSC Power Down Request
#define SYSCTL_DSLPCLKCFG_D_S   23
#define SYSCTL_SYSPROP_FPU      0x00000001  // FPU Present
#define SYSCTL_PIOSCCAL_UTEN    0x80000000  // Use User Trim Value
#define SYSCTL_PIOSCCAL_CAL     0x00000200  // Start Calibration
#define SYSCTL_PIOSCCAL_UPDATE  0x00000100  // Update Trim
#define SYSCTL_PIOSCCAL_UT_M    0x0000007F  // User Trim Value
#define SYSCTL_PIOSCCAL_UT_S    0
#define SYSCTL_PIOSCSTAT_DT_M   0x007F0000  // Default Trim Value
#define SYSCTL_PIOSCSTAT_CR_M   0x00000300  // Calibration Result
#define SYSCTL_PIOSCSTAT_CRNONE 0x00000000  // Calibration has not been
// attempted
#define SYSCTL_PIOSCSTAT_CRPASS 0x00000100  // The last calibration operation
// completed to meet 1% accuracy
#define SYSCTL_PIOSCSTAT_CRFAIL 0x00000200  // The last calibration operation
// failed to meet 1% accuracy
#define SYSCTL_PIOSCSTAT_CT_M   0x0000007F  // Calibration Trim Value
#define SYSCTL_PIOSCSTAT_DT_S   16
#define SYSCTL_PIOSCSTAT_CT_S   0
#define SYSCTL_PLLFREQ0_MFRAC_M 0x000FFC00  // PLL M Fractional Value
#define SYSCTL_PLLFREQ0_MINT_M  0x000003FF  // PLL M Integer Value
#define SYSCTL_PLLFREQ0_MFRAC_S 10
#define SYSCTL_PLLFREQ0_MINT_S  0
#define SYSCTL_PLLFREQ1_Q_M     0x00001F00  // PLL Q Value
#define SYSCTL_PLLFREQ1_N_M     0x0000001F  // PLL N Value
#define SYSCTL_PLLFREQ1_Q_S     8
#define SYSCTL_PLLFREQ1_N_S     0
#define SYSCTL_PLLSTAT_LOCK     0x00000001  // PLL Lock
#define SYSCTL_SLPPWRCFG_FLASHPM_M                                            \
                                0x00000030  // Flash Power Modes
#define SYSCTL_SLPPWRCFG_FLASHPM_NRM                                          \
                                0x00000000  // Active Mode
#define SYSCTL_SLPPWRCFG_FLASHPM_SLP                                          \
                                0x00000020  // Low Power Mode
#define SYSCTL_SLPPWRCFG_SRAMPM_M                                             \
                                0x00000003  // SRAM Power Modes
#define SYSCTL_SLPPWRCFG_SRAMPM_NRM                                           \
                                0x00000000  // Active Mode
#define SYSCTL_SLPPWRCFG_SRAMPM_SBY                                           \
                                0x00000001  // Standby Mode
#define SYSCTL_SLPPWRCFG_SRAMPM_LP                                            \
                                0x00000003  // Low Power Mode
#define SYSCTL_DSLPPWRCFG_FLASHPM_M                                           \
                                0x00000030  // Flash Power Modes
#define SYSCTL_DSLPPWRCFG_FLASHPM_NRM                                         \
                                0x00000000  // Active Mode
#define SYSCTL_DSLPPWRCFG_FLASHPM_SLP                                         \
                                0x00000020  // Low Power Mode
#define SYSCTL_DSLPPWRCFG_SRAMPM_M                                            \
                                0x00000003  // SRAM Power Modes
#define SYSCTL_DSLPPWRCFG_SRAMPM_NRM                                          \
                                0x00000000  // Active Mode
#define SYSCTL_DSLPPWRCFG_SRAMPM_SBY                                          \
                                0x00000001  // Standby Mode
#define SYSCTL_DSLPPWRCFG_SRAMPM_LP                                           \
                                0x00000003  // Low Power Mode
#define SYSCTL_DC9_ADC1DC7      0x00800000  // ADC1 DC7 Present
#define SYSCTL_DC9_ADC1DC6      0x00400000  // ADC1 DC6 Present
#define SYSCTL_DC9_ADC1DC5      0x00200000  // ADC1 DC5 Present
#define SYSCTL_DC9_ADC1DC4      0x00100000  // ADC1 DC4 Present
#define SYSCTL_DC9_ADC1DC3      0x00080000  // ADC1 DC3 Present
#define SYSCTL_DC9_ADC1DC2      0x00040000  // ADC1 DC2 Present
#define SYSCTL_DC9_ADC1DC1      0x00020000  // ADC1 DC1 Present
#define SYSCTL_DC9_ADC1DC0      0x00010000  // ADC1 DC0 Present
#define SYSCTL_DC9_ADC0DC7      0x00000080  // ADC0 DC7 Present
#define SYSCTL_DC9_ADC0DC6      0x00000040  // ADC0 DC6 Present
#define SYSCTL_DC9_ADC0DC5      0x00000020  // ADC0 DC5 Present
#define SYSCTL_DC9_ADC0DC4      0x00000010  // ADC0 DC4 Present
#define SYSCTL_DC9_ADC0DC3      0x00000008  // ADC0 DC3 Present
#define SYSCTL_DC9_ADC0DC2      0x00000004  // ADC0 DC2 Present
#define SYSCTL_DC9_ADC0DC1      0x00000002  // ADC0 DC1 Present
#define SYSCTL_DC9_ADC0DC0      0x00000001  // ADC0 DC0 Present

#define SYSCTL_NVMSTAT_FWB      0x00000001  // 32 Word Flash Write Buffer Available
#define SYSCTL_LDOSPCTL_VADJEN  0x80000000  // Voltage Adjust Enable
#define SYSCTL_LDOSPCTL_VLDO_M  0x000000FF  // LDO Output Voltage
#define SYSCTL_LDOSPCTL_VLDO_0_90V                                            \
                                0x00000012  // 0.90 V
#define SYSCTL_LDOSPCTL_VLDO_0_95V                                            \
                                0x00000013  // 0.95 V
#define SYSCTL_LDOSPCTL_VLDO_1_00V                                            \
                                0x00000014  // 1.00 V
#define SYSCTL_LDOSPCTL_VLDO_1_05V                                            \
                                0x00000015  // 1.05 V
#define SYSCTL_LDOSPCTL_VLDO_1_10V                                            \
                                0x00000016  // 1.10 V
#define SYSCTL_LDOSPCTL_VLDO_1_15V                                            \
                                0x00000017  // 1.15 V
#define SYSCTL_LDOSPCTL_VLDO_1_20V                                            \
                                0x00000018  // 1.20 V
#define SYSCTL_LDODPCTL_VADJEN  0x80000000  // Voltage Adjust Enable
#define SYSCTL_LDODPCTL_VLDO_M  0x000000FF  // LDO Output Voltage
#define SYSCTL_LDODPCTL_VLDO_0_90V                                            \
                                0x00000012  // 0.90 V
#define SYSCTL_LDODPCTL_VLDO_0_95V                                            \
                                0x00000013  // 0.95 V
#define SYSCTL_LDODPCTL_VLDO_1_00V                                            \
                                0x00000014  // 1.00 V
#define SYSCTL_LDODPCTL_VLDO_1_05V                                            \
                                0x00000015  // 1.05 V
#define SYSCTL_LDODPCTL_VLDO_1_10V                                            \
                                0x00000016  // 1.10 V
#define SYSCTL_LDODPCTL_VLDO_1_15V                                            \
                                0x00000017  // 1.15 V
#define SYSCTL_LDODPCTL_VLDO_1_20V                                            \
                                0x00000018  // 1.20 V
#define SYSCTL_PPWD_P1          0x00000002  // Watchdog Timer 1 Present
#define SYSCTL_PPWD_P0          0x00000001  // Watchdog Timer 0 Present
#define SYSCTL_PPTIMER_P5       0x00000020  // 16/32-Bit General-Purpose Timer
// 5 Present
#define SYSCTL_PPTIMER_P4       0x00000010  // 16/32-Bit General-Purpose Timer
// 4 Present
#define SYSCTL_PPTIMER_P3       0x00000008  // 16/32-Bit General-Purpose Timer
// 3 Present
#define SYSCTL_PPTIMER_P2       0x00000004  // 16/32-Bit General-Purpose Timer
// 2 Present
#define SYSCTL_PPTIMER_P1       0x00000002  // 16/32-Bit General-Purpose Timer
// 1 Present
#define SYSCTL_PPTIMER_P0       0x00000001  // 16/32-Bit General-Purpose Timer
// 0 Present
#define SYSCTL_PPGPIO_P14       0x00004000  // GPIO Port Q Present
#define SYSCTL_PPGPIO_P13       0x00002000  // GPIO Port P Present
#define SYSCTL_PPGPIO_P12       0x00001000  // GPIO Port N Present
#define SYSCTL_PPGPIO_P11       0x00000800  // GPIO Port M Present
#define SYSCTL_PPGPIO_P10       0x00000400  // GPIO Port L Present
#define SYSCTL_PPGPIO_P9        0x00000200  // GPIO Port K Present
#define SYSCTL_PPGPIO_P8        0x00000100  // GPIO Port J Present
#define SYSCTL_PPGPIO_P7        0x00000080  // GPIO Port H Present
#define SYSCTL_PPGPIO_P6        0x00000040  // GPIO Port G Present
#define SYSCTL_PPGPIO_P5        0x00000020  // GPIO Port F Present
#define SYSCTL_PPGPIO_P4        0x00000010  // GPIO Port E Present
#define SYSCTL_PPGPIO_P3        0x00000008  // GPIO Port D Present
#define SYSCTL_PPGPIO_P2        0x00000004  // GPIO Port C Present
#define SYSCTL_PPGPIO_P1        0x00000002  // GPIO Port B Present
#define SYSCTL_PPGPIO_P0        0x00000001  // GPIO Port A Present
#define SYSCTL_PPDMA_P0         0x00000001  // uDMA Module Present
#define SYSCTL_PPHIB_P0         0x00000001  // Hibernation Module Present
#define SYSCTL_PPUART_P7        0x00000080  // UART Module 7 Present
#define SYSCTL_PPUART_P6        0x00000040  // UART Module 6 Present
#define SYSCTL_PPUART_P5        0x00000020  // UART Module 5 Present
#define SYSCTL_PPUART_P4        0x00000010  // UART Module 4 Present
#define SYSCTL_PPUART_P3        0x00000008  // UART Module 3 Present
#define SYSCTL_PPUART_P2        0x00000004  // UART Module 2 Present
#define SYSCTL_PPUART_P1        0x00000002  // UART Module 1 Present
#define SYSCTL_PPUART_P0        0x00000001  // UART Module 0 Present
#define SYSCTL_PPSSI_P3         0x00000008  // SSI Module 3 Present
#define SYSCTL_PPSSI_P2         0x00000004  // SSI Module 2 Present
#define SYSCTL_PPSSI_P1         0x00000002  // SSI Module 1 Present
#define SYSCTL_PPSSI_P0         0x00000001  // SSI Module 0 Present
#define SYSCTL_PPI2C_P5         0x00000020  // I2C Module 5 Present
#define SYSCTL_PPI2C_P4         0x00000010  // I2C Module 4 Present
#define SYSCTL_PPI2C_P3         0x00000008  // I2C Module 3 Present
#define SYSCTL_PPI2C_P2         0x00000004  // I2C Module 2 Present
#define SYSCTL_PPI2C_P1         0x00000002  // I2C Module 1 Present
#define SYSCTL_PPI2C_P0         0x00000001  // I2C Module 0 Present
#define SYSCTL_PPUSB_P0         0x00000001  // USB Module Present
#define SYSCTL_PPCAN_P1         0x00000002  // CAN Module 1 Present
#define SYSCTL_PPCAN_P0         0x00000001  // CAN Module 0 Present
#define SYSCTL_PPADC_P1         0x00000002  // ADC Module 1 Present
#define SYSCTL_PPADC_P0         0x00000001  // ADC Module 0 Present
#define SYSCTL_PPACMP_P0        0x00000001  // Analog Comparator Module Present
#define SYSCTL_PPPWM_P1         0x00000002  // PWM Module 1 Present
#define SYSCTL_PPPWM_P0         0x00000001  // PWM Module 0 Present
#define SYSCTL_PPQEI_P1         0x00000002  // QEI Module 1 Present
#define SYSCTL_PPQEI_P0         0x00000001  // QEI Module 0 Present
#define SYSCTL_PPEEPROM_P0      0x00000001  // EEPROM Module Present
#define SYSCTL_PPWTIMER_P5      0x00000020  // 32/64-Bit Wide General-Purpose
// Timer 5 Present
#define SYSCTL_PPWTIMER_P4      0x00000010  // 32/64-Bit Wide General-Purpose
// Timer 4 Present
#define SYSCTL_PPWTIMER_P3      0x00000008  // 32/64-Bit Wide General-Purpose
// Timer 3 Present
#define SYSCTL_PPWTIMER_P2      0x00000004  // 32/64-Bit Wide General-Purpose
// Timer 2 Present
#define SYSCTL_PPWTIMER_P1      0x00000002  // 32/64-Bit Wide General-Purpose
// Timer 1 Present
#define SYSCTL_PPWTIMER_P0      0x00000001  // 32/64-Bit Wide General-Purpose
// Timer 0 Present
#define SYSCTL_SRWD_R1          0x00000002  // Watchdog Timer 1 Software Reset
#define SYSCTL_SRWD_R0          0x00000001  // Watchdog Timer 0 Software Reset
#define SYSCTL_SRTIMER_R5       0x00000020  // 16/32-Bit General-Purpose Timer
// 5 Software Reset
#define SYSCTL_SRTIMER_R4       0x00000010  // 16/32-Bit General-Purpose Timer
// 4 Software Reset
#define SYSCTL_SRTIMER_R3       0x00000008  // 16/32-Bit General-Purpose Timer
// 3 Software Reset
#define SYSCTL_SRTIMER_R2       0x00000004  // 16/32-Bit General-Purpose Timer
// 2 Software Reset
#define SYSCTL_SRTIMER_R1       0x00000002  // 16/32-Bit General-Purpose Timer
// 1 Software Reset
#define SYSCTL_SRTIMER_R0       0x00000001  // 16/32-Bit General-Purpose Timer
#define SYSCTL_SRGPIO_R5        0x00000020  // GPIO Port F Software Reset
#define SYSCTL_SRGPIO_R4        0x00000010  // GPIO Port E Software Reset
#define SYSCTL_SRGPIO_R3        0x00000008  // GPIO Port D Software Reset
#define SYSCTL_SRGPIO_R2        0x00000004  // GPIO Port C Software Reset
#define SYSCTL_SRGPIO_R1        0x00000002  // GPIO Port B Software Reset
#define SYSCTL_SRGPIO_R0        0x00000001  // GPIO Port A Software Reset
#define SYSCTL_SRDMA_R0         0x00000001  // uDMA Module Software Reset
#define SYSCTL_SRHIB_R0         0x00000001  // Hibernation Module Software
#define SYSCTL_SRUART_R7        0x00000080  // UART Module 7 Software Reset
#define SYSCTL_SRUART_R6        0x00000040  // UART Module 6 Software Reset
#define SYSCTL_SRUART_R5        0x00000020  // UART Module 5 Software Reset
#define SYSCTL_SRUART_R4        0x00000010  // UART Module 4 Software Reset
#define SYSCTL_SRUART_R3        0x00000008  // UART Module 3 Software Reset
#define SYSCTL_SRUART_R2        0x00000004  // UART Module 2 Software Reset
#define SYSCTL_SRUART_R1        0x00000002  // UART Module 1 Software Reset
#define SYSCTL_SRUART_R0        0x00000001  // UART Module 0 Software Reset
#define SYSCTL_SRSSI_R3         0x00000008  // SSI Module 3 Software Reset
#define SYSCTL_SRSSI_R2         0x00000004  // SSI Module 2 Software Reset
#define SYSCTL_SRSSI_R1         0x00000002  // SSI Module 1 Software Reset
#define SYSCTL_SRSSI_R0         0x00000001  // SSI Module 0 Software Reset
#define SYSCTL_SRI2C_R3         0x00000008  // I2C Module 3 Software Reset
#define SYSCTL_SRI2C_R2         0x00000004  // I2C Module 2 Software Reset
#define SYSCTL_SRI2C_R1         0x00000002  // I2C Module 1 Software Reset
#define SYSCTL_SRI2C_R0         0x00000001  // I2C Module 0 Software Reset
#define SYSCTL_SRUSB_R0         0x00000001  // USB Module Software Reset
#define SYSCTL_SRCAN_R1         0x00000002  // CAN Module 1 Software Reset
#define SYSCTL_SRCAN_R0         0x00000001  // CAN Module 0 Software Reset
#define SYSCTL_SRADC_R1         0x00000002  // ADC Module 1 Software Reset
#define SYSCTL_SRADC_R0         0x00000001  // ADC Module 0 Software Reset
#define SYSCTL_SRACMP_R0        0x00000001  // Analog Comparator Module 0
// Software Reset
#define SYSCTL_SRPWM_R1         0x00000002  // PWM Module 1 Software Reset
#define SYSCTL_SRPWM_R0         0x00000001  // PWM Module 0 Software Reset
#define SYSCTL_SRQEI_R1         0x00000002  // QEI Module 1 Software Reset
#define SYSCTL_SRQEI_R0         0x00000001  // QEI Module 0 Software Reset

#define SYSCTL_SREEPROM_R0      0x00000001  // EEPROM Module Software Reset
#define SYSCTL_SRWTIMER_R5      0x00000020  // 32/64-Bit Wide General-Purpose
// Timer 5 Software Reset
#define SYSCTL_SRWTIMER_R4      0x00000010  // 32/64-Bit Wide General-Purpose
// Timer 4 Software Reset
#define SYSCTL_SRWTIMER_R3      0x00000008  // 32/64-Bit Wide General-Purpose
// Timer 3 Software Reset
#define SYSCTL_SRWTIMER_R2      0x00000004  // 32/64-Bit Wide General-Purpose
// Timer 2 Software Reset
#define SYSCTL_SRWTIMER_R1      0x00000002  // 32/64-Bit Wide General-Purpose
// Timer 1 Software Reset
#define SYSCTL_SRWTIMER_R0      0x00000001  // 32/64-Bit Wide General-Purpose
// Timer 0 Software Reset
#define SYSCTL_RCGCWD_R1        0x00000002  // Watchdog Timer 1 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCWD_R0        0x00000001  // Watchdog Timer 0 Run Mode Clock
#define SYSCTL_RCGCTIMER_R5     0x00000020  // 16/32-Bit General-Purpose Timer
// 5 Run Mode Clock Gating Control
#define SYSCTL_RCGCTIMER_R4     0x00000010  // 16/32-Bit General-Purpose Timer
// 4 Run Mode Clock Gating Control
#define SYSCTL_RCGCTIMER_R3     0x00000008  // 16/32-Bit General-Purpose Timer
// 3 Run Mode Clock Gating Control
#define SYSCTL_RCGCTIMER_R2     0x00000004  // 16/32-Bit General-Purpose Timer
// 2 Run Mode Clock Gating Control
#define SYSCTL_RCGCTIMER_R1     0x00000002  // 16/32-Bit General-Purpose Timer
// 1 Run Mode Clock Gating Control
#define SYSCTL_RCGCTIMER_R0     0x00000001  // 16/32-Bit General-Purpose Timer
// 0 Run Mode Clock Gating Control

#define SYSCTL_RCGCGPIO_R5      0x00000020  // GPIO Port F Run Mode Clock
// Gating Control
#define SYSCTL_RCGCGPIO_R4      0x00000010  // GPIO Port E Run Mode Clock
// Gating Control
#define SYSCTL_RCGCGPIO_R3      0x00000008  // GPIO Port D Run Mode Clock
// Gating Control
#define SYSCTL_RCGCGPIO_R2      0x00000004  // GPIO Port C Run Mode Clock
// Gating Control
#define SYSCTL_RCGCGPIO_R1      0x00000002  // GPIO Port B Run Mode Clock
// Gating Control
#define SYSCTL_RCGCGPIO_R0      0x00000001  // GPIO Port A Run Mode Clock
// Gating Control
#define SYSCTL_RCGCDMA_R0       0x00000001  // uDMA Module Run Mode Clock
// Gating Control
#define SYSCTL_RCGCHIB_R0       0x00000001  // Hibernation Module Run Mode
// Clock Gating Control
#define SYSCTL_RCGCUART_R7      0x00000080  // UART Module 7 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCUART_R6      0x00000040  // UART Module 6 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCUART_R5      0x00000020  // UART Module 5 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCUART_R4      0x00000010  // UART Module 4 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCUART_R3      0x00000008  // UART Module 3 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCUART_R2      0x00000004  // UART Module 2 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCUART_R1      0x00000002  // UART Module 1 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCUART_R0      0x00000001  // UART Module 0 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCSSI_R3       0x00000008  // SSI Module 3 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCSSI_R2       0x00000004  // SSI Module 2 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCSSI_R1       0x00000002  // SSI Module 1 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCSSI_R0       0x00000001  // SSI Module 0 Run Mode Clock
#define SYSCTL_RCGCI2C_R3       0x00000008  // I2C Module 3 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCI2C_R2       0x00000004  // I2C Module 2 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCI2C_R1       0x00000002  // I2C Module 1 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCI2C_R0       0x00000001  // I2C Module 0 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCUSB_R0       0x00000001  // USB Module Run Mode Clock Gating
#define SYSCTL_RCGCCAN_R1       0x00000002  // CAN Module 1 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCCAN_R0       0x00000001  // CAN Module 0 Run Mode Clock
#define SYSCTL_RCGCADC_R1       0x00000002  // ADC Module 1 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCADC_R0       0x00000001  // ADC Module 0 Run Mode Clock
#define SYSCTL_RCGCACMP_R0      0x00000001  // Analog Comparator Module 0 Run
#define SYSCTL_RCGCPWM_R1       0x00000002  // PWM Module 1 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCPWM_R0       0x00000001  // PWM Module 0 Run Mode Clock
#define SYSCTL_RCGCQEI_R1       0x00000002  // QEI Module 1 Run Mode Clock
// Gating Control
#define SYSCTL_RCGCQEI_R0       0x00000001  // QEI Module 0 Run Mode Clock
#define SYSCTL_RCGCEEPROM_R0    0x00000001  // EEPROM Module Run Mode Clock

#define SYSCTL_RCGCWTIMER_R5    0x00000020  // 32/64-Bit Wide General-Purpose
// Timer 5 Run Mode Clock Gating
// Control
#define SYSCTL_RCGCWTIMER_R4    0x00000010  // 32/64-Bit Wide General-Purpose
// Timer 4 Run Mode Clock Gating
// Control
#define SYSCTL_RCGCWTIMER_R3    0x00000008  // 32/64-Bit Wide General-Purpose
// Timer 3 Run Mode Clock Gating
// Control
#define SYSCTL_RCGCWTIMER_R2    0x00000004  // 32/64-Bit Wide General-Purpose
// Timer 2 Run Mode Clock Gating
// Control
#define SYSCTL_RCGCWTIMER_R1    0x00000002  // 32/64-Bit Wide General-Purpose
// Timer 1 Run Mode Clock Gating
// Control
#define SYSCTL_RCGCWTIMER_R0    0x00000001  // 32/64-Bit Wide General-Purpose
#define SYSCTL_SCGCWD_S1        0x00000002  // Watchdog Timer 1 Sleep Mode
// Clock Gating Control
#define SYSCTL_SCGCWD_S0        0x00000001  // Watchdog Timer 0 Sleep Mode
// Clock Gating Control
#define SYSCTL_SCGCTIMER_S5     0x00000020  // 16/32-Bit General-Purpose Timer
// 5 Sleep Mode Clock Gating
// Control
#define SYSCTL_SCGCTIMER_S4     0x00000010  // 16/32-Bit General-Purpose Timer
// 4 Sleep Mode Clock Gating
// Control
#define SYSCTL_SCGCTIMER_S3     0x00000008  // 16/32-Bit General-Purpose Timer
// 3 Sleep Mode Clock Gating
// Control
#define SYSCTL_SCGCTIMER_S2     0x00000004  // 16/32-Bit General-Purpose Timer
// 2 Sleep Mode Clock Gating
// Control
#define SYSCTL_SCGCTIMER_S1     0x00000002  // 16/32-Bit General-Purpose Timer
// 1 Sleep Mode Clock Gating
// Control
#define SYSCTL_SCGCTIMER_S0     0x00000001  // 16/32-Bit General-Purpose Timer
#define SYSCTL_SCGCGPIO_S5      0x00000020  // GPIO Port F Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCGPIO_S4      0x00000010  // GPIO Port E Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCGPIO_S3      0x00000008  // GPIO Port D Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCGPIO_S2      0x00000004  // GPIO Port C Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCGPIO_S1      0x00000002  // GPIO Port B Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCGPIO_S0      0x00000001  // GPIO Port A Sleep Mode Clock
#define SYSCTL_SCGCDMA_S0       0x00000001  // uDMA Module Sleep Mode Clock
#define SYSCTL_SCGCHIB_S0       0x00000001  // Hibernation Module Sleep Mode
#define SYSCTL_SCGCUART_S7      0x00000080  // UART Module 7 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCUART_S6      0x00000040  // UART Module 6 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCUART_S5      0x00000020  // UART Module 5 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCUART_S4      0x00000010  // UART Module 4 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCUART_S3      0x00000008  // UART Module 3 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCUART_S2      0x00000004  // UART Module 2 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCUART_S1      0x00000002  // UART Module 1 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCUART_S0      0x00000001  // UART Module 0 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCSSI_S3       0x00000008  // SSI Module 3 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCSSI_S2       0x00000004  // SSI Module 2 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCSSI_S1       0x00000002  // SSI Module 1 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCSSI_S0       0x00000001  // SSI Module 0 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCI2C_S3       0x00000008  // I2C Module 3 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCI2C_S2       0x00000004  // I2C Module 2 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCI2C_S1       0x00000002  // I2C Module 1 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCI2C_S0       0x00000001  // I2C Module 0 Sleep Mode Clock
#define SYSCTL_SCGCUSB_S0       0x00000001  // USB Module Sleep Mode Clock
#define SYSCTL_SCGCCAN_S1       0x00000002  // CAN Module 1 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCCAN_S0       0x00000001  // CAN Module 0 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCADC_S1       0x00000002  // ADC Module 1 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCADC_S0       0x00000001  // ADC Module 0 Sleep Mode Clock
#define SYSCTL_SCGCACMP_S0      0x00000001  // Analog Comparator Module 0 Sleep
// Mode Clock Gating Control
#define SYSCTL_SCGCPWM_S1       0x00000002  // PWM Module 1 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCPWM_S0       0x00000001  // PWM Module 0 Sleep Mode Clock
#define SYSCTL_SCGCQEI_S1       0x00000002  // QEI Module 1 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCQEI_S0       0x00000001  // QEI Module 0 Sleep Mode Clock
// Gating Control
#define SYSCTL_SCGCEEPROM_S0    0x00000001  // EEPROM Module Sleep Mode Clock
#define SYSCTL_SCGCWTIMER_S5    0x00000020  // 32/64-Bit Wide General-Purpose
// Timer 5 Sleep Mode Clock Gating
// Control
#define SYSCTL_SCGCWTIMER_S4    0x00000010  // 32/64-Bit Wide General-Purpose
// Timer 4 Sleep Mode Clock Gating
// Control
#define SYSCTL_SCGCWTIMER_S3    0x00000008  // 32/64-Bit Wide General-Purpose
// Timer 3 Sleep Mode Clock Gating
// Control
#define SYSCTL_SCGCWTIMER_S2    0x00000004  // 32/64-Bit Wide General-Purpose
// Timer 2 Sleep Mode Clock Gating
// Control
#define SYSCTL_SCGCWTIMER_S1    0x00000002  // 32/64-Bit Wide General-Purpose
// Timer 1 Sleep Mode Clock Gating
// Control
#define SYSCTL_SCGCWTIMER_S0    0x00000001  // 32/64-Bit Wide General-Purpose
#define SYSCTL_DCGCWD_D1        0x00000002  // Watchdog Timer 1 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCWD_D0        0x00000001  // Watchdog Timer 0 Deep-Sleep Mode
#define SYSCTL_DCGCTIMER_D5     0x00000020  // 16/32-Bit General-Purpose Timer
// 5 Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCTIMER_D4     0x00000010  // 16/32-Bit General-Purpose Timer
// 4 Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCTIMER_D3     0x00000008  // 16/32-Bit General-Purpose Timer
// 3 Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCTIMER_D2     0x00000004  // 16/32-Bit General-Purpose Timer
// 2 Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCTIMER_D1     0x00000002  // 16/32-Bit General-Purpose Timer
// 1 Deep-Sleep Mode Clock Gating
// Control
#define SYSCTL_DCGCTIMER_D0     0x00000001  // 16/32-Bit General-Purpose Timer
#define SYSCTL_DCGCGPIO_D5      0x00000020  // GPIO Port F Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCGPIO_D4      0x00000010  // GPIO Port E Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCGPIO_D3      0x00000008  // GPIO Port D Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCGPIO_D2      0x00000004  // GPIO Port C Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCGPIO_D1      0x00000002  // GPIO Port B Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCGPIO_D0      0x00000001  // GPIO Port A Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCDMA_D0       0x00000001  // uDMA Module Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCHIB_D0       0x00000001  // Hibernation Module Deep-Sleep
// Mode Clock Gating Control
#define SYSCTL_DCGCUART_D7      0x00000080  // UART Module 7 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCUART_D6      0x00000040  // UART Module 6 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCUART_D5      0x00000020  // UART Module 5 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCUART_D4      0x00000010  // UART Module 4 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCUART_D3      0x00000008  // UART Module 3 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCUART_D2      0x00000004  // UART Module 2 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCUART_D1      0x00000002  // UART Module 1 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCUART_D0      0x00000001  // UART Module 0 Deep-Sleep Mode
#define SYSCTL_DCGCSSI_D3       0x00000008  // SSI Module 3 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCSSI_D2       0x00000004  // SSI Module 2 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCSSI_D1       0x00000002  // SSI Module 1 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCSSI_D0       0x00000001  // SSI Module 0 Deep-Sleep Mode
// Clock Gating Control

//*****************************************************************************
#define SYSCTL_DCGCI2C_D3       0x00000008  // I2C Module 3 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCI2C_D2       0x00000004  // I2C Module 2 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCI2C_D1       0x00000002  // I2C Module 1 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCI2C_D0       0x00000001  // I2C Module 0 Deep-Sleep Mode
// Clock Gating Control

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCTL_DCGCUSB register.
//
//*****************************************************************************
#define SYSCTL_DCGCUSB_D0       0x00000001  // USB Module Deep-Sleep Mode Clock
#define SYSCTL_DCGCCAN_D1       0x00000002  // CAN Module 1 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCCAN_D0       0x00000001  // CAN Module 0 Deep-Sleep Mode
#define SYSCTL_DCGCADC_D1       0x00000002  // ADC Module 1 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCADC_D0       0x00000001  // ADC Module 0 Deep-Sleep Mode
#define SYSCTL_DCGCACMP_D0      0x00000001  // Analog Comparator Module 0
#define SYSCTL_DCGCPWM_D1       0x00000002  // PWM Module 1 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCPWM_D0       0x00000001  // PWM Module 0 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCQEI_D1       0x00000002  // QEI Module 1 Deep-Sleep Mode
// Clock Gating Control
#define SYSCTL_DCGCQEI_D0       0x00000001  // QEI Module 0 Deep-Sleep Mode
#define SYSCTL_DCGCEEPROM_D0    0x00000001  // EEPROM Module Deep-Sleep Mode
#define SYSCTL_DCGCWTIMER_D5    0x00000020  // 32/64-Bit Wide General-Purpose
// Timer 5 Deep-Sleep Mode Clock
// Gating Control
#define SYSCTL_DCGCWTIMER_D4    0x00000010  // 32/64-Bit Wide General-Purpose
// Timer 4 Deep-Sleep Mode Clock
// Gating Control
#define SYSCTL_DCGCWTIMER_D3    0x00000008  // 32/64-Bit Wide General-Purpose
// Timer 3 Deep-Sleep Mode Clock
// Gating Control
#define SYSCTL_DCGCWTIMER_D2    0x00000004  // 32/64-Bit Wide General-Purpose
// Timer 2 Deep-Sleep Mode Clock
// Gating Control
#define SYSCTL_DCGCWTIMER_D1    0x00000002  // 32/64-Bit Wide General-Purpose
// Timer 1 Deep-Sleep Mode Clock
// Gating Control
#define SYSCTL_DCGCWTIMER_D0    0x00000001  // 32/64-Bit Wide General-Purpose
// Timer 0 Deep-Sleep Mode Clock
// Gating Control
#define SYSCTL_PRWD_R1          0x00000002  // Watchdog Timer 1 Peripheral
// Ready
#define SYSCTL_PRWD_R0          0x00000001  // Watchdog Timer 0 Peripheral
// Ready
#define SYSCTL_PRTIMER_R5       0x00000020  // 16/32-Bit General-Purpose Timer
// 5 Peripheral Ready
#define SYSCTL_PRTIMER_R4       0x00000010  // 16/32-Bit General-Purpose Timer
// 4 Peripheral Ready
#define SYSCTL_PRTIMER_R3       0x00000008  // 16/32-Bit General-Purpose Timer
// 3 Peripheral Ready
#define SYSCTL_PRTIMER_R2       0x00000004  // 16/32-Bit General-Purpose Timer
// 2 Peripheral Ready
#define SYSCTL_PRTIMER_R1       0x00000002  // 16/32-Bit General-Purpose Timer
// 1 Peripheral Ready
#define SYSCTL_PRTIMER_R0       0x00000001  // 16/32-Bit General-Purpose Timer
// 0 Peripheral Ready
#define SYSCTL_PRGPIO_R5        0x00000020  // GPIO Port F Peripheral Ready
#define SYSCTL_PRGPIO_R4        0x00000010  // GPIO Port E Peripheral Ready
#define SYSCTL_PRGPIO_R3        0x00000008  // GPIO Port D Peripheral Ready
#define SYSCTL_PRGPIO_R2        0x00000004  // GPIO Port C Peripheral Ready
#define SYSCTL_PRGPIO_R1        0x00000002  // GPIO Port B Peripheral Ready
#define SYSCTL_PRGPIO_R0        0x00000001  // GPIO Port A Peripheral Ready
#define SYSCTL_PRDMA_R0         0x00000001  // uDMA Module Peripheral Ready
#define SYSCTL_PRHIB_R0         0x00000001  // Hibernation Module Peripheral Ready
#define SYSCTL_PRUART_R7        0x00000080  // UART Module 7 Peripheral Ready
#define SYSCTL_PRUART_R6        0x00000040  // UART Module 6 Peripheral Ready
#define SYSCTL_PRUART_R5        0x00000020  // UART Module 5 Peripheral Ready
#define SYSCTL_PRUART_R4        0x00000010  // UART Module 4 Peripheral Ready
#define SYSCTL_PRUART_R3        0x00000008  // UART Module 3 Peripheral Ready
#define SYSCTL_PRUART_R2        0x00000004  // UART Module 2 Peripheral Ready
#define SYSCTL_PRUART_R1        0x00000002  // UART Module 1 Peripheral Ready
#define SYSCTL_PRUART_R0        0x00000001  // UART Module 0 Peripheral Ready
#define SYSCTL_PRSSI_R3         0x00000008  // SSI Module 3 Peripheral Ready
#define SYSCTL_PRSSI_R2         0x00000004  // SSI Module 2 Peripheral Ready
#define SYSCTL_PRSSI_R1         0x00000002  // SSI Module 1 Peripheral Ready
#define SYSCTL_PRSSI_R0         0x00000001  // SSI Module 0 Peripheral Ready
#define SYSCTL_PRI2C_R3         0x00000008  // I2C Module 3 Peripheral Ready
#define SYSCTL_PRI2C_R2         0x00000004  // I2C Module 2 Peripheral Ready
#define SYSCTL_PRI2C_R1         0x00000002  // I2C Module 1 Peripheral Ready
#define SYSCTL_PRI2C_R0         0x00000001  // I2C Module 0 Peripheral Ready
#define SYSCTL_PRUSB_R0         0x00000001  // USB Module Peripheral Ready
#define SYSCTL_PRCAN_R1         0x00000002  // CAN Module 1 Peripheral Ready
#define SYSCTL_PRCAN_R0         0x00000001  // CAN Module 0 Peripheral Ready
#define SYSCTL_PRADC_R1         0x00000002  // ADC Module 1 Peripheral Ready
#define SYSCTL_PRADC_R0         0x00000001  // ADC Module 0 Peripheral Ready
#define SYSCTL_PRACMP_R0        0x00000001  // Analog Comparator Module 0
#define SYSCTL_PRPWM_R1         0x00000002  // PWM Module 1 Peripheral Ready
#define SYSCTL_PRPWM_R0         0x00000001  // PWM Module 0 Peripheral Ready
#define SYSCTL_PRQEI_R1         0x00000002  // QEI Module 1 Peripheral Ready
#define SYSCTL_PRQEI_R0         0x00000001  // QEI Module 0 Peripheral Ready
#define SYSCTL_PREEPROM_R0      0x00000001  // EEPROM Module Peripheral Ready
#define SYSCTL_PRWTIMER_R5      0x00000020  // 32/64-Bit Wide General-Purpose
// Timer 5 Peripheral Ready
#define SYSCTL_PRWTIMER_R4      0x00000010  // 32/64-Bit Wide General-Purpose
// Timer 4 Peripheral Ready
#define SYSCTL_PRWTIMER_R3      0x00000008  // 32/64-Bit Wide General-Purpose
// Timer 3 Peripheral Ready
#define SYSCTL_PRWTIMER_R2      0x00000004  // 32/64-Bit Wide General-Purpose
// Timer 2 Peripheral Ready
#define SYSCTL_PRWTIMER_R1      0x00000002  // 32/64-Bit Wide General-Purpose
// Timer 1 Peripheral Ready
#define SYSCTL_PRWTIMER_R0      0x00000001  // 32/64-Bit Wide General-Purpose
// Timer 0 Peripheral Ready
#define SYSCTL_DID0_CLASS_BLIZZARD                                            \
                                0x00050000  // Tiva(TM) C Series TM4C123-class





