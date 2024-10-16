#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isNumber(char *str);
void setResolution(char *str), print(char str[]), printHelp();
char* getResolution();
typedef DEVMODE Devmode; // DEVMODE is defined in Windows api has `typedef (type definition) struct DEVMODE` so you dont use struct to call it again
Devmode getDisplay();

int main(int argsc, char *argsv[]) {
	char* param = argsv[1];
	if (argsc == 3) {
		if (strcmp(param, "-set") == 0) {
			setResolution(argsv[2]);
		} else {
			printHelp();
		}		
	} else if (argsc == 2) {
		if (strcmp(param,"-get") == 0) {
			print(getResolution());
		} else {
			printHelp();
		}
		
	} else {
		printHelp();
	}
	return 0;
}
Devmode getDisplay() {
	Devmode dm; 
	double size = sizeof(dm);
	memset(&dm, 0, sizeof(dm));
	dm.dmSize = sizeof(dm);
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm);
	return dm;
}
int isNumber(char *str) {
	while(*str) { //different of /0 
		if(!isdigit(*str)) {
			return 0;
		}
		str++; // iterator along the *pointer
	}
	return 1;
}
void setResolution(char *str) {
	int width = atoi(strtok(str, "x"));
	int height = atoi(strtok(NULL, ""));
	Devmode dm = getDisplay();
	dm.dmPelsWidth = width;
	dm.dmPelsHeight = height;
	ChangeDisplaySettings(&dm, CDS_UPDATEREGISTRY);
}
char* getResolution(){	
	Devmode dm = getDisplay();
	char* res = (char*) malloc(50 * sizeof(char));	
	int width = dm.dmPelsWidth;
	int height = dm.dmPelsHeight;
	sprintf(res, "%dx%d", width, height); 
	
	return res;	
}
void print(char str[]) {
	printf("%s\n", str);
}
void printHelp(){
	printf("resolution [-get | -set WIDTHxHEIGHT]");
}
/*
You
explain me the params
Copilot
Sure! Here’s a breakdown of the parameters for EnumDisplaySettings:

lpszDeviceName (NULL):

When set to NULL, it refers to the current display device.

iModeNum (ENUM_CURRENT_SETTINGS):

This specifies which settings to retrieve. ENUM_CURRENT_SETTINGS fetches the current settings.

lpDevMode (&dm):

This is a pointer to a DEVMODE structure that will receive the information about the display settings.

So in context:

c

Copy
EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm);
Retrieves the current display settings for the primary display device and stores them in the DEVMODE structure dm. Got it?
*/