#include<stdio.h>
#include"headers/bass.h" 
#include"mod_data.h"



void main(){
/*
    size_t binaryDataSize = sizeof(binary_data);
    unsigned char* binaryDataPtr = binary_data;
  */

 void * muza ;
 muza = &_home_alfa_Music_SKYRIDER_S3M[0];
 
    printf("Ala ma kota %s\n", "Feliksa!");
    BOOL czy =BASS_Init(-1,48000,BASS_DEVICE_STEREO,NULL,NULL);
if(!czy){
   printf( "lipa");
}else{
    printf("Poszedł init!!\n");
}
HMUSIC modul = BASS_MusicLoad(
    TRUE,
    muza,
    0,
    _home_alfa_Music_SKYRIDER_S3M_len,
    0,
    0
);
if (!modul){
    printf("nie udalo sie zaladować moda\n");
}else{
    printf("mamy mod'a na pokładzie\n");
}
 
BASS_ChannelPlay(
    modul,
    FALSE
);
 
 
 
 int num;

    // Prompt the user to enter an integer
    printf("Enter an integer: ");

    // Use scanf to read an integer from the user
    if (scanf("%d", &num) == 1) {
        // scanf returns the number of successfully read items
        printf("You entered: %d\n", num);
    } else {
        printf("Invalid input or no input provided.\n");
    }

 BASS_MusicFree(
    modul
);


}