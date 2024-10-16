#include <Windows.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int x = atoi(argv[1]); 
    int y = atoi(argv[2]);

    SetCursorPos(x, y);

    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0); 

    return 0;
}
