#ifndef __LOGGING_H__
#define __LOGGING_H__

#include <stdarg.h>
#include <BWAPI.h>
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>

namespace scutil {
	class Logging {

	private:
		FILE* file_ptr;
		string filename;
		int logLevel;
		Logging();


	public:
		~Logging() {}

		static Logging& getInstance();

		int getLogLevel();

		void setLogLevel(int level);


		void info(const char * msg, ...);
		void debug(const char * msg, ...);

		void log(const char * msg, ...);

		/** Logging level */
		static const int NONE = 0;

		/** Logs information messages */
		static const int INFO = 1;

		/** Registers debug messages */
		static const int DEBUG = 2;
	};
}
#endif