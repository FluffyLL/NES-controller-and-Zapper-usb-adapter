#include <DigiJoystick.h>

//Rpu=20k-50k 52500

//Low fuse: 0xe1
//High fuse: 0x5d
//Extended fuse: 0xfe

const byte latch=1;
const byte clock=2;
const byte data =0;
const byte light=5;
byte btn0,btn1;
bool btn[8+1];
byte ConnectedTo=0x00;
#define isZapper 0x01
#define isController 0x02

void setup() {
  DigiJoystick.setX((byte)127);
  DigiJoystick.setY((byte)127);
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,INPUT_PULLUP);//pull up prevents garbage data when controller is unpluged  / required for zapper trigger
  pinMode(light,INPUT_PULLUP);
}

void readData(){
  digitalWrite(latch,HIGH);
  delayMicroseconds(12);
  digitalWrite(latch,LOW);

  for(int i=0;i<9;i++){//reads 8 button inputs and an extra one to check if zapper is connected in famiclones
    btn[i]=!digitalRead(data);
    delayMicroseconds(6);
    digitalWrite(clock,HIGH);
    delayMicroseconds(6);
    digitalWrite(clock,LOW);
  }
}

void loop() {
  if(ConnectedTo==isZapper){
    btn0=digitalRead(data)|digitalRead(light)<<1;
  }else if(ConnectedTo==isController){
    readData();
    btn0=btn[0]<<1|btn[1];//A,B buttons
    if(btn[2]&&btn0){//Select+A or Select+B button combination for 2 extra inputs
      btn0=btn0<<2;
      btn[2]=false;
    }
    btn1=btn[2]|btn[3]<<1|btn[4]<<4|btn[5]<<5|btn[6]<<6|btn[7]<<7;//Select,Start and Dpad

    //uses Dpad as joystick input  (btn[4]&&btn[5])||(btn[6]&&btn[7])
    DigiJoystick.setY((byte)((-btn[4]+btn[5]+1)*(127.5f)));
    DigiJoystick.setX((byte)((-btn[6]+btn[7]+1)*(127.5f)));

  }else if(!ConnectedTo){//checks if zapper or controller is connected
    readData();
    if(btn[8]&&(btn[4]&&btn[5]&&btn[6]&&btn[7]&&btn[0]&&btn[1]&&btn[2]&&btn[3]))ConnectedTo=isZapper;
    else ConnectedTo=isController;
  }

  DigiJoystick.setButtons(btn0,btn1);
  DigiJoystick.update();
  //DigiJoystick.delay(50);
}
