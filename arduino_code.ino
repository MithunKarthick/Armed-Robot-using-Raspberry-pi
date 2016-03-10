#include <Servo.h> 
 
Servo myservo1; 
Servo myservo2;
 
int potpin = A5;  
int val;
int vall;
int valr;


int i=0,k=0,m=0;

int motor1Pin1 = 2;
int motor1Pin2 = 3;
int motor2Pin1 = 4;
int motor2Pin2 = 5;

int arm1Pin1 = 6;
int arm1Pin2 = 7;
int gun1 = 8;
int gun2 = 9;

int rot1 = 0;
int rot2 = 1;
int cut1 = 12;
int cut2 = 13;

void setup()
{
	
      
        pinMode(motor1Pin1, OUTPUT);
        pinMode(motor1Pin2, OUTPUT);
        pinMode(motor2Pin1, OUTPUT);
        pinMode(motor2Pin2, OUTPUT);
        
        pinMode(arm1Pin1, OUTPUT);
        pinMode(arm1Pin2, OUTPUT);        
        
        pinMode(gun1, OUTPUT);
        pinMode(gun2, OUTPUT);
        
        pinMode(rot1, OUTPUT);
        pinMode(rot2, OUTPUT);
        pinMode(cut1, OUTPUT);
        pinMode(cut2, OUTPUT);       
        
        myservo1.attach(10);  
        myservo2.attach(11);  
        
      
}
void loop()
{
	i = PINC;
	k = i & 0xFF;
	if(m != k) {
		switch (k) {
		case 0x00: {
                        delay(30);
                        sto();
			m=k;
			break;
		        }

  
  		case 0x01: {
			delay(30);
                        forward();
			m=k;
			break;
		        }

		case 0x02: {
			delay(30);
                        backward();
			m=k;
			break;
                        }
		case 0x03: {
			delay(30);
                        left();
			m=k;
			break;
		        } 

		case 0x04: {
			delay(30);
                        right();
			m=k;
			break;
                        }
                        
               case 0x05: {
			delay(30);
                        r_right();
			m=k;
			break;
		        }

               case 0x06: {
			delay(30);
                        r_left();
                        m=k;
			break;
		        }

		case 0x07: {
			delay(30);
                        c_right();
			m=k;
			break;
		        }

		case 0x08: {
			delay(30);
                        c_left();
			m=k;
			break;
		        }

		case 0x09: {
			delay(30);
                        arm_up();
			m=k;
			break;
		        }

		case 0x0A: {
			delay(30);
                        arm_down();
			m=k;
			break;
                        }

		case 0x0B: {
                        delay(30);
                        gun_up();
                       	m=k;
			break;
                        }  
           
		case 0x0C: {
                        delay(30);
                        gun_down();
                       	m=k;
			break;
                        }  

		default: {
			delay(30);
                        m=k;
			break;
		        }
		}
	}



  val = analogRead(potpin);           
  vall = map(val, 0, 1023, 0, 180);   
  valr = map(val, 0, 1023, 180, 0);  
  myservo1.write(vall); 
  myservo2.write(valr);   
  delay(15);             
  
  
  
}



void forward()
{
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void backward()
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void left()
{
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);

}

void right()
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

}


void arm_up()
{
  digitalWrite(arm1Pin1, HIGH);
  digitalWrite(arm1Pin2, LOW);
  digitalWrite(gun1, LOW);
  digitalWrite(gun2, LOW);
}

void arm_down()
{
  digitalWrite(arm1Pin1, LOW);
  digitalWrite(arm1Pin2, HIGH);
  digitalWrite(gun1, LOW);
  digitalWrite(gun2, LOW);
}

void gun_up()
{
  digitalWrite(arm1Pin1, LOW);
  digitalWrite(arm1Pin2, LOW);
  digitalWrite(gun1, HIGH);
  digitalWrite(gun2, LOW);
}

void gun_down()
{
  digitalWrite(arm1Pin1, LOW);
  digitalWrite(arm1Pin2, LOW);
  digitalWrite(gun1, LOW);
  digitalWrite(gun2, HIGH);
}

void r_left()
{
  digitalWrite(rot1, HIGH);
  digitalWrite(rot2, LOW);
  digitalWrite(cut1, LOW);
  digitalWrite(cut2, LOW);
}

void r_right()
{
  digitalWrite(rot1, LOW);
  digitalWrite(rot2, HIGH);
  digitalWrite(cut1, LOW);
  digitalWrite(cut2, LOW);

}

void c_left()
{
  digitalWrite(rot1, LOW);
  digitalWrite(rot2, LOW);
  digitalWrite(cut1, HIGH);
  digitalWrite(cut2, LOW);
}

void c_right()
{
  digitalWrite(rot1, LOW);
  digitalWrite(rot2, LOW);
  digitalWrite(cut1, LOW);
  digitalWrite(cut2, HIGH);

}

void sto()
{  
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);

}

