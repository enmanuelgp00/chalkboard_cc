#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  
  if (argc - 1 != 2){
    printf("Wrong input.\n"); 
    return 1;
  }
  int width = atoi(argv[1]);
  int height = atoi(argv[2]);

  DEVMODE dm;
  ZeroMemory(&dm, sizeof(dm));
  dm.dmSize = sizeof(dm);
  
  if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm) == 0) {
    printf("Error getting the resolution.\n");
    return 1;
  }

  printf("resolution: \"%dx%d\"", dm.dmPelsWidth, dm.dmPelsHeight);

  if (dm.dmPelsWidth == width && dm.dmPelsHeight == height) {
    printf("\nIt's the same resolution, there were no changes.\n");
    return 0;
  }
  
  dm.dmPelsWidth = width;
  dm.dmPelsHeight = height;  
  
  if (ChangeDisplaySettings(&dm, CDS_UPDATEREGISTRY) != DISP_CHANGE_SUCCESSFUL) {
    printf("\nError changing the resolution \"%dx%d\" is not a supported resolution.\n", width, height);
    return 1;
  }
  
  printf(" -> \"%dx%d\"\n", dm.dmPelsWidth, dm.dmPelsHeight); 
  return 0;
}