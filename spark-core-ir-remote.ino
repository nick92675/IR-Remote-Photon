// This #include statement was automatically added by the Particle IDE.
#include "IRemote.h"

// -----------------------------------
// Controlling LEDs over the Internet
// https://github.com/qwertzguy/Spark-Core-IRremote/wiki/Help
// https://github.com/eflynch/sparkcoreiremitter/blob/master/ir_emitter/ir_emitter.ino
// https://github.com/qwertzguy/Spark-Core-IRremote
//https://kalshagar.wikispaces.com/Arduino+and+IR+(infrared)
// -----------------------------------

// name the pins
int IRledPin = 13;
IRsend irsend(D1);


void setup()
{
    // We are also going to declare a Spark.function so that we can turn the LED on and off from the cloud.
   Spark.function("rotel",rotelFunctions);
   Spark.function("atv",atvFunctions);
   Spark.function("tv",tvFunctions);
   Spark.function("marantz",marantzFunctions);
   // This is saying that when we ask the cloud for the function "tvpower", it will employ the function tvpowerToggle() from this app.

}

void loop() {
	}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ROTEL RECIEVER 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int rotelFunctions(String command) {

    if (command=="on") {
      	for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC18819E6, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  power on
                delay(40);
            }
	    return 1;
    }
    else if (command=="off") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC18801FE, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  power off
                delay(40);
            }
        return 0;
    }
     else if (command=="volUp") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC1886897, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  vol up
                delay(40);
            }
        return 1;
    }
    else if (command=="volDown") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC188E817, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  VOL+
                delay(40);
            }
        return 1;
    }
     else if (command=="mute") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC18818E7, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  Mute
                delay(40);
            }
        return 1;
    }
    else if (command=="7ch") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC188E11E, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  7ch in
                delay(40);
            }
        return 1;
    }
    else if (command=="appletvin") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC18820DF, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  appletvin
                delay(40);
            }
        return 1;
    }
    else if (command=="lpin") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC18810EF, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  lp-in
                delay(40);
            }
        return 1;
    }
    else if (command=="tvin") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC188E01F, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  tv-in
                delay(40);
            }
        return 1;
    }
    else if (command=="zone") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC18859A6, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  zone
                delay(40);
            }
        return 1;
    }
    else if (command=="v3in") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC188906F, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  v3 in
                delay(40);
            }
        return 1;
    }
    else if (command=="v4in") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC188C03F, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  v4in
                delay(40);
            }
        return 1;
    }
    else if (command=="2ch") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendNEC(0xC188C13E, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  2ch in 2nd
                delay(40);
            }
        return 1;
    }
    else {
        return -1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SHARP LCD TV - PULLED FROM REMOTE LC-RC1-14
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int tvFunctions(String command) {
    
    int khz=38; //NB Change this default value as neccessary to the correct carrier frequency
    
    if (command=="tv-power") {
                unsigned int Signal_tv_power_25[] = {275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,46244,275,1900,275,775,275,775,275,775,275,775,275,1900,275,775,275,775,275,1900,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,44148,275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,54084,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275,40996,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,49394,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275}; //AnalysIR Batch Export (IRremote) - RAW
        
                irsend.sendRaw(Signal_tv_power_25, sizeof(Signal_tv_power_25)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                 // AnalysIR IR Protocol: DENON, Key:  tv power
      return 1;
    }
    if (command=="tv-ch-down") {
                unsigned int Signal_tv_ch__27[] = {275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,47292,275,1900,275,775,275,775,275,775,275,775,275,1900,275,775,275,1900,275,1900,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,43096,275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,69422,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275,40996,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,49392,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275}; //AnalysIR Batch Export (IRremote) - RAW
                
                irsend.sendRaw(Signal_tv_ch__27, sizeof(Signal_tv_ch__27)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                // AnalysIR IR Protocol: DENON, Key:  tv-ch-
      return 1;
    }
    if (command=="tv-ch-up") {
                unsigned int Signal_tv_ch__28[] = {275,1900,275,775,275,775,275,775,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,47266,275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,43064,275,1900,275,775,275,775,275,775,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275}; //AnalysIR Batch Export (IRremote) - RAW
                
                irsend.sendRaw(Signal_tv_ch__28, sizeof(Signal_tv_ch__28)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                 // AnalysIR IR Protocol: DENON, Key:  tv-ch+       
      return 1;
    }
    if (command=="tv-mute") {
                unsigned int Signal_tv_mute_29[] = {275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,45170,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,45176,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,70356,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275,41004,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,49402,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275}; //AnalysIR Batch Export (IRremote) - RAW
                
                irsend.sendRaw(Signal_tv_mute_29, sizeof(Signal_tv_mute_29)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                 // AnalysIR IR Protocol: DENON, Key:  tv mute       
      return 1;
    }
    if (command=="tv-vol-down") {
                unsigned int Signal_tv_vol__30[] = {275,1900,275,775,275,775,275,775,275,775,275,1900,275,775,275,1900,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,46220,275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,1900,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,44118,275,1900,275,775,275,775,275,775,275,775,275,1900,275,775,275,1900,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275}; //AnalysIR Batch Export (IRremote) - RAW
                
                irsend.sendRaw(Signal_tv_vol__30, sizeof(Signal_tv_vol__30)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                 // AnalysIR IR Protocol: DENON, Key:  tv-vol-   
      return 1;
    }
    if (command=="tv-vol-up") {
                unsigned int Signal_tv_vol__31[] = {275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,47266,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,1900,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,43072,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,62280,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275,40972,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,49376,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275}; //AnalysIR Batch Export (IRremote) - RAW
                
                irsend.sendRaw(Signal_tv_vol__31, sizeof(Signal_tv_vol__31)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                 // AnalysIR IR Protocol: DENON, Key:  tv-vol+       
      return 1;
    }
    if (command=="tv-enter") {
                unsigned int Signal_tv_enter_32[] = {275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,42028,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,48318,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,41890,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275}; //AnalysIR Batch Export (IRremote) - RAW
                
                irsend.sendRaw(Signal_tv_enter_32, sizeof(Signal_tv_enter_32)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                 // AnalysIR IR Protocol: DENON, Key:  tv-enter       
      return 1;
    }
    if (command=="tv-left") {
                unsigned int Signal_tv_left_33[] = {275,1900,275,775,275,775,275,775,275,775,275,1900,275,775,275,1900,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,43104,275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,47302,275,1900,275,775,275,775,275,775,275,775,275,1900,275,775,275,1900,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275}; //AnalysIR Batch Export (IRremote) - RAW
                
                irsend.sendRaw(Signal_tv_left_33, sizeof(Signal_tv_left_33)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                 // AnalysIR IR Protocol: DENON, Key:  tv-left       
      return 1;
    }
    if (command=="tv-down") {
                 unsigned int Signal_tv_down_34[] = {275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,1900,275,775,275,1900,275,775,275,46248,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,775,275,775,275,1900,275,775,275,1900,275,775,275,1900,275,44112,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,1900,275,775,275,1900,275,775,275}; //AnalysIR Batch Export (IRremote) - RAW
                
                irsend.sendRaw(Signal_tv_down_34, sizeof(Signal_tv_down_34)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                 // AnalysIR IR Protocol: DENON, Key:  tv-down      
      return 1;
    }
    if (command=="tv-right") {
                unsigned int Signal_tv_right_35[] = {275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,43090,275,1900,275,775,275,775,275,775,275,775,275,1900,275,775,275,775,275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,47302,275,1900,275,775,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,61142,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275,41002,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,49396,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275}; //AnalysIR Batch Export (IRremote) - RAW
                
                irsend.sendRaw(Signal_tv_right_35, sizeof(Signal_tv_right_35)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                 // AnalysIR IR Protocol: DENON, Key:  tv-right       
      return 1;
    }
    if (command=="tv-up") {
                unsigned int Signal_tv_up_36[] = {275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,775,275,1900,275,775,275,1900,275,775,275,44122,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,1900,275,775,275,1900,275,775,275,1900,275,46224,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,775,275,1900,275,775,275,1900,275,775,275,70324,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275,40974,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,775,275,49368,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,1900,275,775,275,1900,275}; //AnalysIR Batch Export (IRremote) - RAW
                
                irsend.sendRaw(Signal_tv_up_36, sizeof(Signal_tv_up_36)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                 // AnalysIR IR Protocol: DENON, Key:  tv-up   
      return 1;
    }
    if (command=="tv-input") {
                unsigned int Signal_tv_input_37[] = {275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,46246,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,44150,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275,46106,275,1900,275,775,275,775,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,1900,275,1900,275,1900,275,775,275,1900,275,44008,275,1900,275,775,275,775,275,775,275,775,275,1900,275,1900,275,775,275,775,275,1900,275,775,275,775,275,775,275,1900,275,775,275}; //AnalysIR Batch Export (IRremote) - RAW
                
                irsend.sendRaw(Signal_tv_input_37, sizeof(Signal_tv_input_37)/sizeof(int), khz); //AnalysIR Batch Export (IRremote) - RAW
                 // AnalysIR IR Protocol: DENON, Key:  tv-input       
      return 1;
    }
    else {
        return -1;
    }
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// APPLE TV 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int atvFunctions(String command) {
    if (command=="atv-menu") {
        irsend.sendNEC(0x77E1C09E, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  atv-menu
        return 1;
    }
    else if (command=="atv-enter") {
        irsend.sendNEC(0x77E13A9E, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  atv-enter
        return 0;
    }
    else if (command=="atv-left") {
        irsend.sendNEC(0x77E1909E, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  atv-left
        return 0;
    }
    else if (command=="atv-right") {
        irsend.sendNEC(0x77E1609E, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  atv-right
        return 0;
    }
    else if (command=="atv-up") {
        irsend.sendNEC(0x77E1509E, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  atv-up
        return 0;
    }
    else if (command=="atv-down") {
        irsend.sendNEC(0x77E1309E, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  atv-down
        return 0;
    }
    else if (command=="atv-playpause") {
        irsend.sendNEC(0x77E1FA9E, 32); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: NEC, Key:  atv-playpause
        return 0;
    }
    else {
        return -1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MARANTZ
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int marantzFunctions(String command) {
   
    if (command=="m-power") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendRC5(0x140C, 14); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: RC5, Key:  marantzpower
                delay(40);
            }
        return 1;   
   }
    else if (command=="m-mute") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendRC5(0x140D, 14); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: RC5, Key:  marantz mute
                delay(40);
            }
        return 0;
    }
    else if (command=="m-vol-up") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendRC5(0x1410, 14); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: RC5, Key:  marantz vol +
                delay(40);
            }
        return 0;
    }
    else if (command=="m-vol-down") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendRC5(0x1411, 14); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: RC5, Key:  marantz vol -
                delay(40);
            }
        return 0;
    }
    else if (command=="m-sleep") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendRC5(0x1426, 14); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: RC5, Key:  marantz sleep
                delay(40);
            }
        return 0;
    }
    else if (command=="m-tuner") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendRC5(0x147F, 14); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: RC5, Key:  marantz tuner
                delay(40);
            }
        return 0;
    }    
    else if (command=="m-dvd") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendRC5(0x050, 9); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: RC5, Key:  marantz dvd
                delay(40);
            }
        return 0;
    }    
    else if (command=="m-phono") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendRC5(0x157F, 14); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: RC5, Key:  marantz phono
                delay(40);
            }
        return 0;
    }
    else if (command=="m-cd") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendRC5(0x153F, 14); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: RC5, Key:  marantz cd
                delay(40);
            }
        return 0;
    }    
    else if (command=="m-dss") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendRC5(0x11BF, 14); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: RC5, Key:  marantz dss
                delay(40);
            }
        return 0;
    }
    else if (command=="m-vcr") {
        for (int i = 0; i < 3; i++) 
            {
                irsend.sendRC5(0x117F, 14); //AnalysIR Batch Export (IRremote) // AnalysIR IR Protocol: RC5, Key:  marantz vcr
                delay(40);
            }
        return 0;
    }
    else {
        return -1;
    }
}




