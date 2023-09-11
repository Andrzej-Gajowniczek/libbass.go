package main

import "unsafe"

import "C"

func main() {
	goStr := "Hello, C!"
	cStr := C.CString(goStr)
	defer C.Free(unsafe.Pointer(cStr))

}
