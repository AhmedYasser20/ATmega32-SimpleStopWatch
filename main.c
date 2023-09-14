#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>


void Init_Timer0(void){
	TCCR1A|=(1<<FOC1A);
	TCCR1B|=(1<<WGM12)|(1<<CS12)|(1<<CS10);
	SREG|=(1<<7);
	TCNT1=0;
	OCR1A=1000;
	TIMSK|=(1<<OCIE1A);
}
unsigned char Array[]={0,0,0,0,0,0};

ISR(TIMER1_COMPA_vect){

	Array[0]++;
	if(Array[0]==10){
		Array[0]=0;
		Array[1]++;
		for(int i=1;i<5;i++){
			if(i%2==1){
				if(Array[i]==6){
					Array[i]=0;
					Array[i+1]++;
				}
			}
			else{
				if(Array[i]==9){
					Array[i]=0;
					Array[i+1]++;
				}
			}
		}
	}
	if(Array[5]==10)
		for(int i=0;i<6;i++)
				Array[i]=0;
}

void Init_int0(){
	MCUCR|=(1<<ISC01);
	GICR|=(1<<INT0);
	SREG|=(1<<7);
	DDRD&=~(1<<2);
	PORTD|=(1<<2);
}
ISR(INT0_vect){
	for(int i=0;i<6;i++)
		Array[i]=0;
	TCNT1=0;
}

void Init_int1(void){
	MCUCR|=(1<<ISC11)|(1<<ISC10);
	GICR|=(1<<INT1);
	SREG|=(1<<7);
	DDRD&=~(1<<3);
}

ISR(INT1_vect){
	//flagToStart=0;
	TIMSK&=~(1<<OCIE1A);
}

void Init_int2(void){
	SREG|=(1<<7);
	GICR|=(1<<INT2);
	MCUCSR&=~(1<<ISC2);
	DDRB&=~(1<<2);
	PORTB|=(1<<2);
}
ISR(INT2_vect){
	TIMSK|=(1<<OCIE1A);
	TCNT1=0;
}

void Reset(){
	for(int i=0;i<6;i++)
		Array[i]=0;
}
int main(void){
	DDRC|=0x0F;
	DDRA|=0x3F;
	Init_Timer0();
	Init_int0();
	Init_int1();
	Init_int2();
	while(1){
		for(int i=5;i>=0;i--){
			_delay_ms(2);
			PORTA=0;
			PORTA|=(1<<i);
			PORTC=Array[i];
		}
	}
}
