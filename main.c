void delay1(int num);
void setup() { 
  volatile int blink[] = {0x0000003f, 0x00000006, 0x0000005b, 0x0000004f, 0x00000066, 0x0000006d, 0x0000007d, 0x00000007, 0x0000007f, 0x00000067};
  volatile int *configA, *configD, *setA, *setD,*configF,*setF;
  volatile int dig1, dig2, dig3, dig4, i;
  // GPIO Port A configuration
  configA = (volatile int*)0x50000000;
  *configA = 0x55555555;  
  configF = (volatile int*)0x50001400;
  *configF = 0x55555555;  
  // GPIO Port D configuration
  configD = (volatile int*)0x50000C00;
  *configD = 0x55555555; 
  // Set output data registers
  setF = (volatile int*)0x50001418;
  setA = (volatile int*)0x50000018;
  setD = (volatile int*)0x50000C18; 
  while (1) {
    for(dig1=0;dig1<10;dig1++){
      for(dig2=0;dig2<10;dig2++){ 
        for(dig3=0;dig3<6;dig3++){
          for(dig4=0;dig4<10;dig4++){
            for(i=0;i<100;i++){
              *setF = 0x0001000e;
              *setD = 0x00000007;
              *setA = blink[dig4];
              delay1(1);
              *setA = 0xffff0000;
              *setF = 0x000000ff;             
              *setD = 0x0004000b;
              *setA = blink[dig3];
              delay1(1);
              *setA = 0xffff0000;             
              *setD = 0x0002000d;
              *setA = blink[dig2];
              delay1(1);
              *setA = 0xffff0000;            
              *setD = 0x0001000e;
              *setA = blink[dig1];
              delay1(1);
              *setA = 0xffff0000;             
            }
          }
        }                 
      }
    }    
  }
}

void loop() {
  // Main loop remains empty
}

void delay1(int num) {
  volatile int i;
  while (num) {
    for (i = 0; i < 500; i++);  // Adjust the delay loop as necessary
    num--;
  }
}
