#include <stdio.h>
#include "headers/bass.h"
#include <termios.h>
#include <unistd.h>

void main(){


BOOL czy = BASS_Init(
		-1,
		44100,
		BASS_DEVICE_DEFAULT,
		NULL,
		NULL
);

if (!czy) {
       printf("Init() failed\n");
}else{
 printf("Init() OK\n");
}
/*
void *  tytul = "/home/alfa/Music/SDXCV-103_1253632615_Camco-Craviotto_Jam.mp3";
HCHANNEL kawalek = BASS_SampleLoad(
		FALSE,
		tytul,
		0,
        0,  3,
		BASS_STREAM_AUTOFREE
		
		
);
*/
HSTREAM kawalek = BASS_StreamCreateFile(FALSE, "sonda.ogg", 0, 0, BASS_STREAM_AUTOFREE);
printf("adresik kawałka: %02x\n",kawalek);
if (kawalek == 0){
	printf("Load error\n");
}else{
	printf("Loaded OK!\n");
}

//BASS_ChannelSetAttribute(mp3Stream, BASS_ATTRIB_VOL, 1.0f); 
BASS_ChannelSetAttribute(kawalek, BASS_ATTRIB_VOL, 1.0f); 

BOOL czy2 ;
czy2 = BASS_ChannelPlay(kawalek,FALSE);
if (czy2 == TRUE) {
	printf("Plays Music!\n");
}else{
    int Berror = BASS_ErrorGetCode();
	printf("Something went wrong - doesn't play at all, error:%d, device: %d\n",Berror,BASS_IsStarted());

//BASS_Start();
}
/*
printf("Press any key to continue...\n");
 getch(); // Wait for a key press
 printf("You pressed a key!\n");
*/


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
BASS_SampleFree(kawalek);
BASS_Free();

}

