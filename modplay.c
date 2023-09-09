#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/libmodplug/modplug.h"
#include "mod_data.h"

int main() {
    ModPlugFile* mod;
    int result;

    // Initialize libmodplug
    ModPlug_Init();

    // Load the embedded .MOD data
    mod = ModPlug_Load(beyond_mod[0], sizeof(beyond_mod));
    if (!mod) {
        fprintf(stderr, "Failed to load .MOD data\n");
        return 1;
    }

    // Play the .MOD file
    result = ModPlug_Play(mod);

    // Your program logic here...

    // Clean up
    ModPlug_Unload(mod);
    ModPlug_Exit();

    return 0;
}
