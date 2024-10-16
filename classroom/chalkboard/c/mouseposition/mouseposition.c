#include <Windows.h>
#include <cstdio>
int main()
{
    POINT cursorPosition;
    if (GetCursorPos(&cursorPosition))
    {
        printf("La posición actual del cursor del mouse es (%d, %d)\n", cursorPosition.x, cursorPosition.y);
    }
    else
    {
        printf("No se pudo obtener la posición actual del cursor del mouse\n");
    }

    return 0;
}