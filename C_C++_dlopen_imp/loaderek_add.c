#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*add_a_b)(int, int);
    char *error;

    handle = dlopen("./libadd.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    dlerror();  // Clear any existing error

    *(void **)(&add_a_b) = dlsym(handle, "add_a_b");

    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    int result = add_a_b(2, 3);
    printf("Result: %d\n", result);

    dlclose(handle);
    return 0;
}
/*
You can compile main.c with the libadd.so library as follows:

bash

gcc -o my_program main.c -ldl

Here's what this command does:

    -o my_program: Specifies the output filename for the compiled program (you can choose any name you like).
    main.c: The source file containing your main function.
    -ldl: Links the program with the libdl library, which provides dynamic linking functions like dlopen, dlsym, and dlclose.

After running this command, you will have a binary executable named my_program that dynamically links with libadd.so. When you run my_program, it will load libadd.so at runtime and use the add_a_b function from the shared library.
*/
