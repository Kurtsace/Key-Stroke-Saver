========================================================================
    CONSOLE APPLICATION : KeySaver Project Overview
========================================================================


This file contains a summary of what you will find in each of the files that
make up your KeySaver application.


KeySaver.cpp

	-- This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp

	-- These files are used to build a precompiled header (PCH) file 
		named KeySaver.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Change Log: 
	
	Version 1.1:

	-- Created a functional backspace. Instead of just writing [BACKSPACE] to file, it will 
		remove the last byte and truncate the file simulating a backspace. 
		(Might be unstable and most likely dangerous, but works for now). 
	
	-- Caps Lock is now being detected and utilized. It will write lowercase letters to
		file, unless Caps Lock is turned on. 
	
	Version 1:
	-- Added a sleep function to the main while loop to prevent CPU over usage. 

/////////////////////////////////////////////////////////////////////////////