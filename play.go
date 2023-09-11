package main

/*
#cgo CFLAGS: -Iheaders
#cgo LDFLAGS: ./headers/libs/x86_64/libbass.so
#include <./headers/bass.h>


*/
import "C"
import (
	"fmt"
)

func main() {
	var czy C.BOOL = C.BASS_Init(-1, 48000, C.BASS_DEVICE_STEREO, C.NULL, C.NULL)
	if czy == 0 {
		fmt.Println("Initialization failed")
	} else {
		fmt.Println("Initialization succeeded")
	}
	defer C.BASS_Free()

	tytul := `muza/beyond.mod`

	play := C.BASS_MusicLoad(
		C.FALSE,
		&C.cgo(tytul),
		0,
		0,
		0,
		0,
	)

	//play = play
	if play == nil {
		fmt.Println("Music load failed")
	} else {
		fmt.Println("Music load succeeded")
	}
}
