#include "Arduino.h"
#include "logic.h"
#include "Audio.h"
#include "SPIFFS.h"
                          //   ESP32       I2S
                          // ------------------
#define I2S_DOUT  	A1    // A1:  BROWN  => DIN
#define I2S_BCLK   	A10   // A10: ORANGE => BCLK
#define I2S_LRC    	A0    // A0:  BLUE   => LRC

// I2S Setup
// ------------
// Gain: controls gain/boost between  3dB, 6dB, (9dB), 12dB or 15dB
//         15dB if a 100K resistor is connected between GAIN and GND
//         12dB if GAIN is connected directly to GND
//         9dB is default when nothing is connected
//         6dB if GAIN is connected directly to Vin
//         3dB if a 100K resistor is connected between GAIN and Vin
// SD: various behaviors based on connections and current
//         If SD is connected to ground directly (voltage is under 0.16V) then the amp is shut down
//         If the voltage on SD is between 0.16V and 0.77V then the output is (Left + Right)/2, that is the stereo average. 
//         If the voltage on SD is between 0.77V and 1.4V then the output is just the Right channel
//         If the voltage on SD is higher than 1.4V then the output is the Left channel.  
// GND: tying to all grounds
// Vin: using microcontroller out, but might need to drive externally

Audio audio;

Sound::Sound(Logic &logic)
: _logic(logic)
{
}

void Sound::setup() {
    if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }

    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setBalance(-16); // mutes the left channel
    audio.setVolume(21);   // max loudness
	audio.forceMono(true);
}

void Sound::handle() {
    audio.loop();
    
}

void Sound::playRaven(const char * fName) {
    audio.connecttoFS(SPIFFS, fName);
}

bool Sound::isPlaying() {
    return audio.isRunning();
}

// optional
// void audio_info(const char *info){
//     Serial.print("info        "); Serial.println(info);
// }
// void audio_id3data(const char *info){  //id3 metadata
//     Serial.print("id3data     ");Serial.println(info);
// }
// void audio_eof_mp3(const char *info){  //end of file
//     Serial.print("eof_mp3     ");Serial.println(info);
// }
// void audio_showstation(const char *info){
//     Serial.print("station     ");Serial.println(info);
// }
// void audio_showstreamtitle(const char *info){
//     Serial.print("streamtitle ");Serial.println(info);
// }
// void audio_bitrate(const char *info){
//     Serial.print("bitrate     ");Serial.println(info);
// }
// void audio_commercial(const char *info){  //duration in sec
//     Serial.print("commercial  ");Serial.println(info);
// }
// void audio_icyurl(const char *info){  //homepage
//     Serial.print("icyurl      ");Serial.println(info);
// }
// void audio_lasthost(const char *info){  //stream URL played
//     Serial.print("lasthost    ");Serial.println(info);
// }