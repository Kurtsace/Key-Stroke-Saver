========================================================================
    CONSOLE APPLICATION : KeySaver Project Overview
========================================================================


This file contains a summary of what you will find in each of the files that
make up your KeySaver application.


Main.cpp

<<<<<<< HEAD
	-- This is the main application source file.
=======
KeySaver.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).
main.cpp
    This is the main application source file.
>>>>>>> 42d425137a7fde38466128b0bac7d9b7f6c87345

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp

	-- These files are used to build a precompiled header (PCH) file 
		named KeySaver.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Change Log: 
	
	Version 1.2:
	-- Updated the method to hide the console, no longer using FreeConsole(). 
	
	-- Updated timeStamp(). 

	Version 1.1:

	-- Created a functional backspace. Instead of just writing [BACKSPACE] to file, it will 
		remove the last byte and truncate the file simulating a backspace. 
		(Might be unstable and most likely dangerous, but works for now). 
	
	-- Caps Lock is now being detected and utilized. It will write lowercase letters to
		file, unless Caps Lock is turned on. 
	
	Version 1:
	-- Added a sleep function to the main while loop to prevent CPU over usage. 

/////////////////////////////////////////////////////////////////////////////