#include  "usart.h" 

void UsartInit(long int UartSpeed);
void UsartWrite(unsigned char data);
unsigned char UsartRead(void);

//������������ USART
void UsartInit(long int UartSpeed){
	//Set baud rate 
    unsigned int ubrr;
	ubrr=F_CPU/16/UartSpeed-1;
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	//Enable receiver and transmitter 
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	// 8data, 2stop bit
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void UsartWrite(unsigned char data){
	// Wait for empty transmit buffer
	while (!(UCSR0A & (1<<UDRE0)))
	;
	//Put data into buffer, sends the data
	UDR0 = data;
}

unsigned char UsartRead(void){
	// Wait for data to be received 
	while (!(UCSR0A & (1<<RXC0)));
	// Get and return received data from buffer 
	return UDR0;
}
