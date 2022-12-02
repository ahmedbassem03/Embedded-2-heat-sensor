#include <avr/io.h>
#include <util/delay.h>

float temponlcd(){//function that return a float value 
  Adc_Init();//intializing adc
  float tempreture;//defining a temp value to use it
  char *string[0];//defining a string to use it in the lcd
  DDRC=0b00000000;//using DDRC as input
  PORTC=0b00000000;
  tempreture=Adc_ReadChannel(4);//passing the ADC register value to the pre defined value
  itoa(tempreture/20,*string,10);//dividing the value of the on the temp on 20 due to using of the refrence voltage and then transfering it to the string
  _delay_ms(300);//delay
  LCD_String_xy(0,0,"the temp is ");//displaying on the first row 'the temp is'
  LCD_String_xy(1,0,*string);//showing the value on the string
  LCD_String_xy(1,6,"C");//showing the unit we used
  _delay_ms(300);
  return tempreture;//returing the tempreture value
}