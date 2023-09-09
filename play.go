package main

/*
#cgo CFLAGS: -Iheaders
#cgo LDFLAGS: -L./headers/libs/x86_64 -lbass
#include <./headers/bass.h>
*/
import "C"
import "fmt"

func main() {
	var czy C.BOOL = C.BASS_Init(-1, 48000, C.BASS_DEVICE_STEREO, C.NULL, C.NULL)
	if czy == 0 {
		fmt.Println("Initialization failed")
	} else {
		fmt.Println("Initialization succeeded")
	}
}
