/*
 * "Jesus is Lord"
 * 
 * Author Susan Amber Bruce 0n 27/6/2021.
 * S O S morse code transmitter, will also transmit sentences assigned to char Letters array..
 */
char Letters[] = "  SEEK FIRST THE KINGDOM OF GOD AND HIS RIGHTEOUSNESS  "
"  THE SERMON ON THE MOUNT  "
"  SEEING THE CROWDS HE WENT UP ON THE MOUNTAIN AND WHEN HE SAT DOWN HIS DISCIPLES CAME TO HIM  "
"  THE BEATITUDES  "
"  AND HE OPENED HIS MOUTH AND TAUGHT THEM SAYING  "
"  BLESSED ARE THE POOR IN SPIRIT FOR THEIRS IS THE KINGDOM OF HEAVEN  "
"  BLESSED ARE THOSE WHO MOURN FOR THEY SHALL BE COMFORTED  "
"  BLESSED ARE THE MEEK FOR THEY SHALL INHERIT THE EARTH  "
"  BLESSED ARE THOSE WHO HUNGER AND THIRST FOR RIGHTEOUSNESS FOR THEY SHALL BE SATISFIED  "
"  BLESSED ARE THE MERCIFUL FOR THEY SHALL RECEIVE MERCY  "
"  BLESSED ARE THE PURE IN HEART FOR THEY SHALL SEE GOD  "
"  BLESSED ARE THE PEACE MAKERS FOR THEY SHALL BE CALLED SONS OF GOD  "
"  BLESSED ARE THOSE WHO ARE PERSECUTED FOR RIGHTEOUSNESS SAKE FOR THEIRS IS THE KINGDOM OF HEAVEN  "
"  BLESSED ARE YOU WHEN OTHERS REVILE YOU AND PERSECUTE YOU AND UTTER ALL KINDS OF EVIL AGAINST YOU FALSELY ON MY ACCOUNT  "
"  REJOICE AND BE GLAD FOR YOUR REWARD IS GREAT IN HEAVEN FOR SO THEY PERSECUTED THE PROPHETS WHO WERE BEFORE YOU  "
"       ";
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
  Serial.begin(9600);
  delay(3000);
  Send_SOS();
  delay(5000);
  for (int i = 0; i < sizeof(Letters) - 1; i++){
    Serial.print(Letters[i]);  // prints output to serial monitor.
    switch (Letters[i]) {
      case 'A':  // A .-
        SendDot();
        SendDash();
        break;
      case 'B':  // B -...
        SendDash();
        SendDot();
        SendDot();
        SendDot();
        break;
      case 'C':  // C -.-.
        SendDash();
        SendDot();
        SendDash();
        SendDot();
        break;
      case 'D':  // D -..
        SendDash();
        SendDot();
        SendDot();
        break;
      case 'E':  // E .
        SendDot();
        break;
      case 'F':  // F ..-.
        SendDot();
        SendDot();
        SendDash();
        SendDot();
        break;
      case 'G':  // G --.
        SendDash();
        SendDash();
        SendDot();
        break;
      case 'H':  // H ....
        SendDot();
        SendDot();
        SendDot();
        SendDot();
        break;
      case 'I':  // I ..
        SendDot();
        SendDot();
        break;
      case 'J':  // J .---
        SendDot();
        SendDash();
        SendDash();
        SendDash();
        break;
      case 'K':  // K -.-
        SendDash();
        SendDot();
        SendDash();
        break;
      case 'L':  // L .-..
        SendDot();
        SendDash();
        SendDot();
        SendDot();
        break;
      case 'M':  // M --
        SendDash();
        SendDash();
        break;
      case 'N':  // N -.
        SendDash();
        SendDot();
        break;
      case 'O':  // O ---
        SendDash();
        SendDash();
        SendDash();
        break;
      case 'P':  // P .--.
        SendDot();
        SendDash();
        SendDash();
        SendDot();
        break;
      case 'Q':  // Q --.-
        SendDash();
        SendDash();
        SendDot();
        SendDash();
        break;
      case 'R':  // R .-.
        SendDot();
        SendDash();
        SendDot();
        break;
      case 'S':  // S ...
        SendDot();
        SendDot();
        SendDot();
        break;
      case 'T':  // T -
        SendDash();
        break;
      case 'U':  // U ..-
        SendDot();
        SendDot();
        SendDash();
        break;
      case 'V':  // V ...-
        SendDot();
        SendDot();
        SendDot();
        SendDash();
        break;
      case 'W':  // W .--
        SendDot();
        SendDash();
        SendDash();
        break;
      case 'X':  // X -..-
        SendDash();
        SendDot();
        SendDot();
        SendDash();
        break;
      case 'Y':  // Y -.--
        SendDash();
        SendDot();
        SendDash();
        SendDash();
        break;
      case 'Z':  // Z --..
        SendDash();
        SendDash();
        SendDot();
        SendDot();
        break;
      case ' ':  // space between words seven time units
        SendDelaySevenUnits();
        break;
      case '1':  // 1 .----
        SendDot();
        SendDash();
        SendDash();
        SendDash();
        SendDash();
        break;
      case '2':  // 2 ..---
        SendDot();
        SendDot();
        SendDash();
        SendDash();
        SendDash();
        break;
      case '3':  // 3 ...--
        SendDot();
        SendDot();
        SendDot();
        SendDash();
        SendDash();
        break;
      case '4':  // 4 ....-
        SendDot();
        SendDot();
        SendDot();
        SendDot();
        SendDash();
        break;
      case '5':  // 5 .....
        SendDot();
        SendDot();
        SendDot();
        SendDot();
        SendDot();
        break;
      case '6':  // 6 -....
        SendDash();
        SendDot();
        SendDot();
        SendDot();
        SendDot();
        break;
      case '7':  // 7 --...
        SendDash();
        SendDash();
        SendDot();
        SendDot();
        SendDot();
        break;
      case '8':  // 8 ---..
        SendDash();
        SendDash();
        SendDash();
        SendDot();
        SendDot();
        break;
      case '9':  // 9 ----.
        SendDash();
        SendDash();
        SendDash();
        SendDash();
        SendDot();
        break;
      case '0':  // 0 -----
        SendDash();
        SendDash();
        SendDash();
        SendDash();
        SendDash();
        break;
    }
    SendDelayThreeUnits(); // delay three time units beteen letters
  }
}
// functions:

void Send_SOS(){  // fuction to send just "SOS", can be extracted and used inplace of switch case-routine to shorten sketch.
    for (int i = 0; i < 3; i++){  // send tree dots.
    SendDot();
    SendDelayOneUnit();
  }
  SendDelayThreeUnits();
  for (int i = 0; i < 3; i++){  // send tree dashes.
    SendDash();
    SendDelayOneUnit();
  }
  SendDelayThreeUnits();
    for (int i = 0; i < 3; i++){  // send three dots.
    SendDot();
    SendDelayOneUnit();
  }
  SendDelaySevenUnits();  // send delay of seven time units between words.
}
void SendDelayOneUnit(){
  delay(100); // delay 1 unit
}
void SendDelayThreeUnits(){
  delay(300); // delay 3 units
}
void SendDelaySevenUnits(){
  delay(700); // delay 7  time units [time delay between words].
}
void SendDot(){            // dot [sound beep and flash LED for one time unit] and delay one time unit before next dot or dash.
  digitalWrite(12, HIGH);  // turn the LED on.
  beep(100, 700);         // sound pizo electric buzzer for 100 mili seconds (one unit of time).
  digitalWrite(12, LOW);   // turn the LED off.
  SendDelayOneUnit();      // one time unit of delay before next dot or dash.  
}

void SendDash(){
  digitalWrite(12, HIGH);  // turn the LED on.
  beep(300, 700);         // sound pizo electric buzzer for 300 mili seconds (three units of time).
  digitalWrite(12, LOW);   // turn the LED off.
  SendDelayOneUnit();      // one time unit of delay before next dot or dash.
  // dash  
}
