package main

/*

#cgo LDFLAGS: ./headers/libs/x86_64/libbass.so
#include <./headers/bass.h>
HSAMPLE uchwyt = 0;
//void * nnazwa = "/home/alfa/Music/wakacyjna_kolekcja/trim00011.ogg";
void * ctytul ="sonda.ogg";
*/
import "C"
import (
	"fmt"
	"os"
	"os/exec"
)

func main() {

	var czy C.BOOL = C.BASS_Init(-1, 48000, C.BASS_DEVICE_STEREO, C.NULL, C.NULL)
	if czy == 0 {
		fmt.Println("Initialization failed")
	} else {
		fmt.Println("Initialization succeeded")
	}
	defer C.BASS_Free()
	//tytul := "./sonda.ogg"
	//tytul := "muza/beyond.mod"
	//tytul := "/home/alfa/Music/wakacyjna_kolekcja/trim00011.ogg"
	//ctytul := C.CString(tytul)
	/*
		playErr := C.BASS_MusicLoad(
			C.FALSE,
			unsafe.Pointer(ctytul),
			0,
			0,
			0,
			0,
		)
	*/
	C.uchwyt = C.BASS_StreamCreateFile(C.FALSE, C.ctytul, 0, 0, C.BASS_SAMPLE_LOOP)
	//C.uchwyt = C.BASS_SampleLoad(C.FALSE, C.nnazwa, 0, 0, 0, 0)

	//play = play
	if C.uchwyt == C.FALSE {
		fmt.Println("Music load failed")
	} else {
		fmt.Println("Music load succeeded")
	}

	C.BASS_ChannelSetAttribute(C.uchwyt, C.BASS_ATTRIB_VOL, 1)
	C.BASS_ChannelPlay(C.uchwyt, C.FALSE)

	waitForKeyPress()
	fmt.Println("You pressed a key!")

	C.BASS_Free()
}

func waitForKeyPress() {
	fmt.Print("Press any key to continue...")
	var input rune
	fmt.Scanf("%c", &input)

	// Clear the terminal screen (optional)
	cmd := exec.Command("clear") // Use "cls" instead of "clear" on Windows
	cmd.Stdout = os.Stdout
	cmd.Run()
}
