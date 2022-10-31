#include  "usart.h" 

void UsartInit(long int UartSpeed);
void UsartWrite(uint8_t data);
uint8_t UsartRead(void);

//инициализаци USART
void UsartInit(long int UartSpeed){
	//Set baud rate 
    uint8_t ubrr;
	ubrr=F_CPU/16/UartSpeed-1;
	UBRR0H = (uint8_t)(ubrr>>8);
	UBRR0L = (uint8_t)ubrr;
	//Enable receiver and transmitter 
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	// 8data, 2stop bit
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void UsartWrite(uint8_t data){
	// Wait for empty transmit buffer
	while (!(UCSR0A & (1<<UDRE0)))
	;
	//Put data into buffer, sends the data
	UDR0 = data;
}

uint8_t UsartRead(void){
	// Wait for data to be received 
	while (!(UCSR0A & (1<<RXC0)));
	// Get and return received data from buffer 
	return UDR0;
}
