#include <windows.h>
#include <stdio.h>

int main() {
    HWND hwnd = GetForegroundWindow(); // Handle to the currently active window
    RECT rect;
    if (GetWindowRect(hwnd, &rect)) {
        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;
        printf("Width: %d, Height: %d\n", width, height);
    } else {
        printf("Failed to get window size\n");
    }
    return 0;
}