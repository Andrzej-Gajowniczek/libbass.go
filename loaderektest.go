package main

// #cgo LDFLAGS: -ldl
// #include <dlfcn.h>
import "C"
import (
	"fmt"
)

func main() {
	libPath := "./libbass.so" // Path to the bundled library

	// Load the library
	lib := C.dlopen(C.CString(libPath), C.RTLD_LAZY)
	if lib == nil {
		fmt.Println("Failed to load library:", C.GoString(C.dlerror()))
		return
	} else {
		fmt.Println("załadowałem")
	}
	defer C.dlclose(lib)

	// Use functions from the loaded library (e.g., C.dlsym)
	// Note: You'll need to know the exact function signatures.
	// Example:
	// funcPtr := C.dlsym(lib, C.CString("myFunction"))
}
