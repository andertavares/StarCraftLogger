#ifndef __LOGGING_H__
#define __LOGGING_H__

#include <stdarg.h>
#include <BWAPI.h>
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>

class Logging {

	//sets the log filename to the specified number
	//void setLogFileNumber(string prefix, int number);
	
	
public:
    ~Logging() { }

    static Logging* getInstance();

    void log(const char * msg, ...);

	/** Logging level */
	static const int NONE = 0;

	/** Logs information messages */
	static const int INFO = 1;

	/** Registers debug messages */
	static const int DEBUG = 2;

private:
    FILE* file_ptr;
    string filename;
	int logLevel;
    Logging();
};

#endif