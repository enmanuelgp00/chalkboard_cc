#include <Windows.h>

int main(){
   SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
   return 0;
}