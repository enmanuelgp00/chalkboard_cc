#include <windows.h>
#include <stdio.h>

int main() {
    DEVMODE devMode;
    int modeNum = 0;

    while (EnumDisplaySettings(NULL, modeNum++, &devMode)) {
        printf("Width: %d, Height: %d, BitsPerPel: %d, Frequency: %d\n",
               devMode.dmPelsWidth,
               devMode.dmPelsHeight,
               devMode.dmBitsPerPel,
               devMode.dmDisplayFrequency);
    }

    return 0;
}