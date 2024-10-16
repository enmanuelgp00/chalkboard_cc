#include <windows.h>
#include <stdio.h>

//prototype
int getASCII (char); //American Standard Code for Information Interchange
POINT getCursorPos();
int getX();
int getY();
int main () {
  int KEY_PRESSED = -32768;
  int KEY_RELEASED = 0;
  int state;
  
  printf("%d", getASCII('A'));
  for (int i = 0; i < 1; i--) {
    if (GetAsyncKeyState(getASCII('A')) == KEY_PRESSED && state != KEY_PRESSED) {      
      //puts("pressed");
      mouse_event(MOUSEEVENTF_LEFTDOWN, getX(), getY(), 0, 0);
      state = KEY_PRESSED;
    } else if (GetAsyncKeyState(getASCII('A')) == KEY_RELEASED && state != KEY_RELEASED){      
      //puts("released");
      mouse_event(MOUSEEVENTF_LEFTUP, getX(), getY(), 0, 0);
      state = KEY_RELEASED;
    }
  }
  return 0;
}
 
int getASCII (char ch) {
  return (int) ch;
}

POINT getCursorPos() {
  POINT cursorPos;
  GetCursorPos(&cursorPos);
  return cursorPos;
}

int getX() {
  return getCursorPos().x;
}

int getY() {
  return getCursorPos().y;
}



