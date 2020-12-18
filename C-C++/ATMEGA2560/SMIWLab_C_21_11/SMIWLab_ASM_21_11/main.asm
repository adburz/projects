//////////////////////////////////////////////////////////////////////////////
// Laboratory AVR Microcontrollers Part1
// Program template for ASM lab 7
// Please fill in this information before starting coding
// Authors:
// 1. Adam Burzynski
// Group: 2
// Section: 1
// Task number: 11
//
// Version: 5.0
//////////////////////////////////////////////////////////////////////////////
.nolist ;quartz assumption 4Mhz
.include "m2560def.inc"
;//////////////////////////////////////////////////////////////////////////////
.list
.equ xlength =	100
;//////////////////////////////////////////////////////////////////////////////
; EEPROM - data non volatile memory segment 
.ESEG 

;//////////////////////////////////////////////////////////////////////////////
; StaticRAM - data memory.segment
.DSEG 
.ORG 0x200; may be omitted this is default value
; Destination table (xlengthx bytes). 
; Replace "xlengthx" with correct value
TAB_RAM: .BYTE xlength

;//////////////////////////////////////////////////////////////////////////////
; CODE - Program memory segment
; Please Remember that it is "word" address space
;
.CSEG  
.org 0x0000 ; may be omitted this is default value 
jmp	RESET	; Reset Handler
; Interrupts vector table / change to your procedure only when needed 
jmp	EXT_INT0	; IRQ0 Handler
jmp	EXT_INT1	; IRQ1 Handler
jmp	EXT_INT2	; IRQ2 Handler
jmp	EXT_INT3	; IRQ3 Handler
jmp	EXT_INT4	; IRQ4 Handler
jmp	EXT_INT5	; IRQ5 Handler
jmp	EXT_INT6	; IRQ6 Handler
jmp	EXT_INT7	; IRQ7 Handler
jmp HPCINT0		; PCINT0 Handler
jmp HPCINT1		; PCINT1 Handler
jmp HPCINT2		; PCINT2 Handler
jmp WDT			; WDT Handler
jmp	TIM2_COMPA	; Timer2 CompareA Handler
jmp	TIM2_COMPB	; Timer2 CompareB Handler
jmp	TIM2_OVF   	; Timer2 Overflow Handler
jmp	TIM1_CAPT 	; Timer1 Capture Handler
jmp	TIM1_C0MPA	; Timer1 CompareA Handler
jmp	TIM1_C0MPB	; Timer1 CompareB Handler
jmp TIM1_COMPC	; Timer1 CompareC Handler
jmp	TIM1_0VF  	; Timer1 Overflow Handler
jmp	TIM0_COMPA 	; Timer0 CompareA Handler
jmp	TIM0_COMPB 	; Timer0 CompareB Handler
jmp	TIM0_OVF  	; Timer0 Overflow Handler
jmp	SPI_STC   	; SPI Transfer Complete Handler
jmp	USART0_RXC	; USART0 RX Complete Handler
jmp	USART0_UDRE	; USART0,UDR Empty Handler
jmp	USART0_TXC	; USART0 TX Complete Handler
jmp ANA_COMP	; Analog COmparator Handler
jmp	HADC        	; ADC Conversion Complete Handler
jmp	EE_RDY    	; EEPROM Ready Handler
jmp	TIM3_CAPT 	; Timer3 Capture Handler
jmp	TIM3_COMPA	; Timer3 CompareA Handler
jmp	TIM3_COMPB	; Timer3 CompareB Handler
jmp	TIM3_COMPC	; Timer3 CompareC Handler
jmp	TIM3_OVF  	; Timer3 Overflow Handler
jmp	USART1_RXC	; USART1 RX Complete Handler
jmp	USART1_UDRE	; USART1,UDR Empty Handler
jmp	USART1_TXC	; USART1 TX Complete Handler
jmp	TWI        	; Two-wire Serial Interface Interrupt Handler
jmp	SPM_RDY   	; SPM Ready Handler
jmp TIM4_CAPT	; Timer4 Capture Handler
jmp TIM4_COMPA	; Timer4 CompareA Handler
jmp TIM4_COMPB	; Timer4 CompareB Handler
jmp TIM4_COMPC	; Timer4 CompareC Handler
jmp TIM4_OVF	; Timer4 Overlflow Handler
jmp TIM5_CAPT	; Timer5 Capture Handler
jmp TIM5_COMPA	; Timer5 CompareA Handler
jmp TIM5_COMPB	; Timer5 CompareB Handler
jmp TIM5_COMPC	; Timer5 CompareC Handler
jmp TIM5_OVF	; Timer5 Overlflow Handler
jmp	USART2_RXC	; USART2 RX Complete Handler
jmp	USART2_UDRE	; USART2,UDR Empty Handler
jmp	USART2_TXC	; USART2 TX Complete Handler
jmp	USART3_RXC	; USART3 RX Complete Handler
jmp	USART3_UDRE	; USART3,UDR Empty Handler
jmp	USART3_TXC	; USART3 TX Complete Handler

//////////////////////////////////////////////////////////////////////////////
EXT_INT0:	; IRQ0 Handler
EXT_INT1:	; IRQ1 Handler
EXT_INT2:	; IRQ2 Handler
EXT_INT3:	; IRQ3 Handler
EXT_INT4:	; IRQ4 Handler
EXT_INT5:	; IRQ5 Handler
EXT_INT6:	; IRQ6 Handler
EXT_INT7:	; IRQ7 Handler
HPCINT0:		; PCINT0 Handler
HPCINT1:		; PCINT1 Handler
HPCINT2:		; PCINT2 Handler
WDT:		; WDT Handler
TIM2_COMPA:	; Timer2 CompareA Handler
TIM2_COMPB:	; Timer2 CompareB Handler
TIM2_OVF:  	; Timer2 Overflow Handler
TIM1_CAPT: 	; Timer1 Capture Handler
TIM1_C0MPA:	; Timer1 CompareA Handler
TIM1_C0MPB:	; Timer1 CompareB Handler
TIM1_COMPC:	; Timer1 CompareC Handler
TIM1_0VF:  	; Timer1 Overflow Handler

	inc R21	//increments the interrupts counter
	ldi R19, 0x0B	//initializing timer with value FFFF - 62500 = 3035
	ldi R22, 0xDB 
	
	sts TCNT1H, R19	//initializing timer
	sts TCNT1L, R22 //3035 -> 0xBDB at two registers

TIM0_COMPA: ; Timer0 CompareA Handler
TIM0_COMPB: ; Timer0 CompareB Handler
TIM0_OVF:  	; Timer0 Overflow Handler
SPI_STC:   	; SPI Transfer Complete Handler
USART0_RXC:	; USART0 RX Complete Handler
USART0_UDRE:; USART0,UDR Empty Handler
USART0_TXC:	; USART0 TX Complete Handler
ANA_COMP:	; Analog COmparator Handler
HADC:       ; ADC Conversion Complete Handler
EE_RDY:    	; EEPROM Ready Handler
TIM3_CAPT: 	; Timer3 Capture Handler
TIM3_COMPA:	; Timer3 CompareA Handler
TIM3_COMPB:	; Timer3 CompareB Handler
TIM3_COMPC:	; Timer3 CompareC Handler
TIM3_OVF:  	; Timer3 Overflow Handler
USART1_RXC:	; USART1 RX Complete Handler
USART1_UDRE:; USART1,UDR Empty Handler
USART1_TXC:	; USART1 TX Complete Handler
TWI:       	; Two-wire Serial Interface Interrupt Handler
SPM_RDY:   	; SPM Ready Handler
TIM4_CAPT:	; Timer4 Capture Handler
TIM4_COMPA:	; Timer4 CompareA Handler
TIM4_COMPB:	; Timer4 CompareB Handler
TIM4_COMPC:	; Timer4 CompareC Handler
TIM4_OVF:	; Timer4 Overlflow Handler
TIM5_CAPT:	; Timer5 Capture Handler
TIM5_COMPA:	; Timer5 CompareA Handler
TIM5_COMPB:	; Timer5 CompareB Handler
TIM5_COMPC:	; Timer5 CompareC Handler
TIM5_OVF:	; Timer5 Overlflow Handler
USART2_RXC:	; USART2 RX Complete Handler
USART2_UDRE:; USART2,UDR Empty Handler
USART2_TXC:	; USART2 TX Complete Handler
USART3_RXC:	; USART3 RX Complete Handler
USART3_UDRE:; USART3,UDR Empty Handler
USART3_TXC:	; USART3 TX Complete Handler
	reti		; return from all no used

;//////////////////////////////////////////////////////////////////////////////
; Program start

;//////////////////////////////////////////////////////////////////////////////
; Program start
RESET:
	cli ; disable all interrupts
// Set stack pointer to the top of RAM
	ldi R16, HIGH(RAMEND)
	out SPH, R16
	ldi R16, LOW(RAMEND)
	out SPL, R16
// 1. Place here code related to initialization of all ports
// for instance: port A as input and no pullups
// DDRA=0x00
// PORTA=0x00
// port B as output and initial value FF
// DDRB=0xFF
// PORTB=0xFF


ldi R17, 0x00 // setting R17 as 0x00
ldi R18, 0xFF // setting R18 as 0xFF

out DDRA, R17 // initialising port type of A as input
out PORTA, R17 // assigning 0 to A

sbi DDRB, 5 // initialising port type of B.5 as output
sbi DDRB, 6 // initialising port type of B.6 as output
sbi DDRB, 7 // initialising port type of B.7 as output
sbi PORTB, 5 // assigning 1 to B.5
sbi PORTB, 6 // assigning 1 to B.6
sbi PORTB, 7 // assigning 1 to B.7

out DDRC, R18 // initialising port type of C as output
out PORTC, R18 // assigning 1 to C


// Writing a logic one to PINxn toggles the value of PORTxn, regardless of the value of DDRxn
// Note that the SBI instruction can be used to toggle one single bit in a port.
// for instance: sbi DDRB, 0
// 2. Enable interrupts if needed
// sei
//------------------------------------------------------------------------------
// 3. Load initial values of index registers
// Z, X, Y
ldi R21, 0x00	//setting interrupts iterator

ldi R19, 0x0B	//initializing timer with value FFFF - 62500 = 3035
ldi R22, 0xDB 

sts TCNT1H, R19	//initializing timer
sts TCNT1L, R22 //3035 -> 0xBDB at two registers

ldi R22, (1<<CS10) | (1<<CS11)	//initializing prescaller
sts TCCR1B, R22	

ldi R22, 1<<TOIE1	// enable timer overflow interrupt for both Timer1
sts TIMSK1, R22

sei	//enabling global interrupts

ldi XL, LOW(TAB_RAM) // assinging lower part of TAB_RAM adress into XL 
ldi XH, HIGH(TAB_RAM) // assinging higher part of TAB_RAM adress into XH

ldi R16, byte3(TAB_ROM<<1) // assigning extra adressing bits of TAB_ROM into R16
out RAMPZ, R16 // assigning extra address bits of TAB_ROM into RAMPZ
ldi ZL, low(TAB_ROM<<1) // assinging lower part of TAB_ROM into ZL
ldi ZH, high(TAB_ROM<<1) // assinging higher part of TAB_ROM into ZH
ldi R16, 0x00	// counter array

ifPressed:	// checks if the button is pressed
in R17, PINA	// loading value of PINA into R17
cpi R17, 0xFF	// checks if button is pressed
breq endingLoop	// if button is not pressed -> end

checkIfEndOfArray: // checks if its end of array by loop counter
cbi PORTB, 6 // turning the 6th LED ON 
cpi R16, xlength // checking if it is end of an array 
breq endingLoop //if it is, toggle led on 

loop: //loop 
elpm R20, Z+ // assigning value from TAB_ROM into R20 and incrementation of the pointer 
cpi R20, 0x00 // checking if R20 is equal to 0x00
brne copying // if R20 is not equal to 0x00 we don't have to check next value 
elpm R20, Z // assigning next value from TAB_ROM into R16 now without incrementation 
cpi R20, 0x00 // checking if R20 is equal to 0x00 
breq endingLoop // we've reached the end of TAB_ROM (two 0x00 values after one another) 
sbiw Z, 1 // decrementation of the pointer 
elpm R20, Z+ // assigning current value from TAB_ROM into R20 

copying: //assign value if in array is not double zero 
st X+, R20 // assigning current TAB_ROM value into TAB_RAM 
inc R16 //inc loop iterator 
rjmp checkIfEndOfArray // jump to the checkIfEndOfArray

endingLoop:	//while loop with "if" statements to turn off/on LED 
	cpi R21, 0x01	//comparing interrupt counter with 0x01 
	breq turnLED_OFF	//if its equal, we want to turn off LED
	cpi R21, 0x03	//checking if interrupt counter is equal to 0x03
	breq turnLED_ON	//if its equal, we want to turn on LED and after that jump to the end
	rjmp endingLoop	//if its not equal, we want to repeat process, so jump into endingLoop

turnLED_OFF:	//label which turns the LED off, and increments the counter, to prevent endingLoop label from getting into turnLED_OFF label
	sbi PORTB, 6 // turning the 6th LED off
	inc R21	//incrementing interrupt counter to prevent it from turning ON the LED like in while loop
	rjmp endingLoop

turnLED_ON:	//label which turns the LED on and jumps into ending label
	cbi PORTB, 6 // turning the 6th LED ON 
	sbi PORTB, 6 // turning the 6th LED OFF
	rjmp End 

// Program end - Ending loop
//------------------------------------------------------------------------------
End:
rjmp END
//------------------------------------------------------------------------------
// Table Declaration - place here test values
// Test with other table values and different begin addresses of a table (also above 0x8000)
//
//.org 0x8000
TAB_ROM: .db 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x1F
.db 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1F, 0x1F
.db 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F
.db 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F
.db 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F
.db 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F
.db 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F
.db 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F
.db 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F
.db 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F
.db 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaA, 0xaB, 0xaC, 0xaD, 0xAE, 0xAF
.db 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF
.db 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF
.db 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF
.db 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3, 0xF2, 0xF1, 0xF0
// please correct end of this table according to the guidelines given by the teacher
.db 0x00,0x00
.EXIT
//------------------------------------------------------------------------------