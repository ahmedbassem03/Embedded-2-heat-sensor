#include <avr/io.h>
#include <util/delay.h>
//ahmed taha 202000189
//Mohammed Barakat 202000053
//mohammed abbas 202000957

void init(){
  Adc_Init();
  LCD_Init();
  temponlcd();
}
int main(){
 init();
  DDRB=0b11100111;//intializing pins 3 and 4 as input
  float maxtemp=40;//defining the max temp to give warning 40
  float lowesttemp=24;//defing the lowest temp to give warning as 24
  float thetemp;//defing a value to hold the temp value
  char *stringmax[0];//string to hold the max temp value
  char *stringmin[0];//string to hold the lowest temp value
  while(1)
  {
  thetemp = temponlcd();//passing the temp val to thetemp
  _delay_ms(300);
  if((thetemp/20)>maxtemp|(thetemp/20)<lowesttemp){//if function to give warning by lighting led light and make the buzzer beep 
      PORTB=0b11111111;//making the buzzer and led work
  }
  else{
     PORTB=0b11111011;//close both buzzer and led
  }
if(Adc_ReadChannel(0)>500){//when voltage pass through the button to the adc and adc reads volt function starts
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){//a must work function
    LCD_Clear();//clears lcd
    maxtemp++;//increment max temp making the value increase by 1 
  }
    LCD_String_xy(0,0,"40 C changed to ");//showing the orginal value at which it gives warning
    itoa(maxtemp,*stringmax,10);//passing the value to the string
    LCD_String_xy(1,0,*stringmax);//showing the value after increasing it by 1
    LCD_String_xy(1,6,"C");
    _delay_ms(2500);
    LCD_Clear();//clears lcd
    
  }
  if(Adc_ReadChannel(2)>500){//when voltage pass through the button to the adc and adc reads volt function starts
  _delay_ms(50);
  if(PORTB&(1<<3)!=1){//a must work function
    LCD_Clear();//clears lcd
    lowesttemp--;//decrease min tempreture value by 1
  }
    LCD_String_xy(0,0,"24 C changed to ");//showing the orginal value at which it gives warning
    itoa(lowesttemp,*stringmin,10);//passing the value to the string
    LCD_String_xy(1,0,*stringmin);//showing the value after increasing it by 1
    LCD_String_xy(1,6,"C");
   _delay_ms(2500);
    LCD_Clear();//clears lcd
  }
    
}
}