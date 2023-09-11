package main

/*
#cgo CFLAGS: -I./headers
#cgo LDFLAGS: ./headers/libs/x86_64/libbass.so
#include "headers/bass.h"
*/
import "C"
import (
	"fmt"
)

func main() {
	var czy C.BOOL = C.BASS_Init(-1, 48000, C.BASS_DEVICE_STEREO, nil, nil)
	if czy == 0 {
		fmt.Println("Initialization failed")
	} else {
		fmt.Println("Initialization succeeded")
	}
	defer C.BASS_Free()

	tytul := *C.CString("muza/beyond.mod")
	//defer C.free(unsafe.Pointer(tytul)) // No need for C.free here

	var play *C.HMUSIC = C.BASS_MusicLoad(
		C.FALSE,
		tytul,
		0,
		0,
		0,
		0,
	)

	if play == nil {
		fmt.Println("Music load failed")
	} else {
		fmt.Println("Music load succeeded")
	}

}
