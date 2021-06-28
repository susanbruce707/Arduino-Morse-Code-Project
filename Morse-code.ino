/*
 * "Jesus is Lord"
 * 
 * Author Susan Amber Bruce 0n 27/6/2021.
 * S O S morse code transmitter.
 */
char Letters[] = "SEEK*FIRST*THE*KINGDOM*OF*GOD*AND*HIS*RIGHTEOUSNESS######"
"SEEK*FIRST*THE*KINGDOM*OF*GOD*AND*HIS*RIGHTEOUSNESS######";
const int sounder_A = 8;
const int sounder_B = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(sounder_A, OUTPUT); //connect the piezo across two ports
  pinMode(sounder_B, OUTPUT); //to double the signal amplitude.
  pinMode(12, OUTPUT); // initialize digital pin 12 as an output
}
// Call function with parameters - duration in mSecs, freq in Hz
void beep(long duration, int freq) {
    duration *= 1000;   //convert the duration to microseconds
    int period = (1.0 / freq) * 1000000; //get the oscillation period in microseconds
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(sounder_A, HIGH); //Piezo ports go hi/lo then lo/hi
        digitalWrite(sounder_B, LOW);  //to generate the tone
        delayMicroseconds(period / 2);
        digitalWrite(sounder_A, LOW);
        digitalWrite(sounder_B, HIGH);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }
        digitalWrite(sounder_A, LOW);  //kill the output
        digitalWrite(sounder_B, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  for (int i = 0; i < sizeof(Letters) - 1; i++){
    switch (Letters[i]) {
      case 'A':
        SendDot();
        SendDash();
        break;
      case 'B':
        SendDash();
        SendDot();
        SendDot();
        SendDot();
        break;
      case 'C':
        SendDash();
        SendDot();
        SendDash();
        SendDot();
        break;
      case 'D':
        SendDash();
        SendDot();
        SendDot();
        break;
      case 'E':
        SendDot();
        break;
      case 'F':
        SendDot();
        SendDot();
        SendDash();
        SendDot();
        break;
      case 'G':
        SendDash();
        SendDash();
        SendDot();
        break;
      case 'H':
        SendDot();
        SendDot();
        SendDot();
        SendDot();
        break;
      case 'I':
        SendDot();
        SendDot();
        break;
      case 'J':
        SendDot();
        SendDash();
        SendDash();
        SendDash();
        break;
      case 'K':
        SendDash();
        SendDot();
        SendDash();
        break;
      case 'L':
        SendDot();
        SendDash();
        SendDot();
        SendDot();
        break;
      case 'M':
        SendDash();
        SendDash();
        break;
      case 'N':
        SendDash();
        SendDot();
        break;
      case 'O':
        SendDash();
        SendDash();
        SendDash();
        break;
      case 'P':
        SendDot();
        SendDash();
        SendDash();
        SendDot();
        break;
      case 'Q':
        SendDash();
        SendDash();
        SendDot();
        SendDash();
        break;
      case 'R':
        SendDot();
        SendDash();
        SendDot();
        break;
      case 'S':
        SendDot();
        SendDot();
        SendDot();
        break;
      case 'T':
        SendDash();
        break;
      case 'U':
        SendDot();
        SendDot();
        SendDash();
        break;
      case 'V':
        SendDot();
        SendDot();
        SendDot();
        SendDash();
        break;
      case 'W':
        SendDot();
        SendDash();
        SendDash();
        break;
      case 'X':
        SendDash();
        SendDot();
        SendDot();
        SendDash();
        break;
      case 'Y':
        SendDash();
        SendDot();
        SendDash();
        SendDash();
        break;
      case 'Z':
        SendDash();
        SendDash();
        SendDot();
        SendDot();
        break;
      case '*':// space letter
        SendDelayThreeUnits();
        break;
      case '#':// space word
        SendDelaySevenUnits();
        break;
    }  
  }
}
// functions:

void Send_SOS(){
    for (int i = 0; i < 3; i++){
    SendDot();
    SendDelayOneUnit();
  }
  SendDelayThreeUnits();
  for (int i = 0; i < 3; i++){
    SendDash();
    SendDelayOneUnit();
  }
  SendDelayThreeUnits();
  SendDelaySevenUnits();
}
void SendDelayOneUnit(){
  delay(100); // delay 1 unit
}
void SendDelayThreeUnits(){
  delay(300); // delay 3 units
}
void SendDelaySevenUnits(){
  delay(700); // delay 7 units
}
void SendDot(){
  digitalWrite(12, HIGH);  // turn the LED on (HIGH is the voltage level)
  beep(100, 4000);
  digitalWrite(12, LOW);   // turn the LED off by making voltage LOW
  SendDelayOneUnit();
  // dots  
}
void SendDash(){
  digitalWrite(12, HIGH);  // turn the LED on (HIGH is the voltage level)
  beep(300, 4000);
  digitalWrite(12, LOW);   // turn the LED off by making voltage LOW
  SendDelayOneUnit();
  // dash  
}
