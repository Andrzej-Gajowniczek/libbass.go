#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "headers/bass.h"

int main() {
    if (BASS_Init(-1, 44100, BASS_DEVICE_DEFAULT, NULL, NULL)) {
        HSTREAM mp3Stream = BASS_StreamCreateFile(FALSE, "sonda.ogg", 0, 0, BASS_STREAM_AUTOFREE);
        
        if (mp3Stream) {
            BASS_ChannelSetAttribute(mp3Stream, BASS_ATTRIB_VOL, 1.0f);
            BASS_ChannelPlay(mp3Stream, FALSE);
            
            // Wait or perform other tasks while the audio plays.
            

struct termios oldt, newt;
    int ch;

    printf("Press any key to continue...\n");

    // Get the current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);

    // Make a copy of the current settings to modify
    newt = oldt;

    // Disable canonical mode (line buffering) and echo
    newt.c_lflag &= ~(ICANON | ECHO);

    // Apply the new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read a single character
    ch = getchar();

    // Restore the old terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    printf("You pressed a key: %c\n", ch);



            // When done, free resources.
            BASS_StreamFree(mp3Stream);
            BASS_Free();
        }
    }
    return 0;
}

