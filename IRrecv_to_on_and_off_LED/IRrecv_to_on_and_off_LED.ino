//Using Remote to on and off LED, there are four different button used
//Cai Zhixiang, Lim Kim and Xinhao group

#include <IRremote.h>

int RECV_PIN = 11;
int LEDpin = 3; //LED to be attached to Pin3
int y;

IRrecv irrecv(RECV_PIN); //setup IRreceiver in Pin11

decode_results results; //devoder for received IR signal.

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver  

 
pinMode(LEDpin, OUTPUT);
}

void loop() {
  
  if (irrecv.decode(&results)) { // decode IR signal
    int angle = results.value;   // received value
    Serial.println(results.value, DEC);
   
    if(results.value == 604803425)//remote button RED to on LED
  {
    digitalWrite(LEDpin, HIGH);
  }
  else if (results.value == 2724465097 //remote button GREEN to off LED
)
  {
    digitalWrite(LEDpin, LOW);
  }
  else if (results.value == 3760167553) //remote button YELLOW to blink LED
  {
    digitalWrite(LEDpin, HIGH);
    delay(500);               
    digitalWrite(LEDpin, LOW);
    delay(500);               
    digitalWrite(LEDpin, HIGH);
  }
  else if (results.value == 1760049649) //remote button BLUE to off LED
  {
    digitalWrite(LEDpin, HIGH);
    delay(500); 
   digitalWrite(LEDpin,LOW);
  
  }
  


    irrecv.resume(); // Receive the next value
  } 
  
}
