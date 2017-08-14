#include "Logging.h"
#include "asprintf\asprintf.h"
#include <string>
#include <cstdio>
#include <iostream>
#include <BWAPI.h>
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>

using namespace std;
using namespace BWAPI;
using namespace scutil;

Logging& Logging::getInstance() {
	static Logging instance;
	return instance;
}

Logging::Logging() : logLevel(Logging::INFO){
	
}

int Logging::getLogLevel() {
	return logLevel;
}

void Logging::setLogLevel(int level) {
	logLevel = level;
}

void Logging::log(const char * msg, ...) {

    file_ptr = fopen(filename.c_str(), "a");
	char* formatted;
		
    va_list args;
    va_start(args, msg);
	int result = vasprintf(&formatted, msg, args); //credits: http://asprintf.insanecoding.org/
	va_end(args);

	Broodwar->printf(formatted);
	fprintf(file_ptr, "[%d] %s%s", Broodwar->getFrameCount(), formatted, "\n");    
    fclose(file_ptr);

	free(formatted);
}
