#include "Logging.h"
#include "Arduino.h"


// default loglevel if nothing is set from user
#define LOGLEVEL LOG_LEVEL_DEBUG


#define CR "\r\n"
#define LOGGING_VERSION 1


void Logging::init(LogLevel level, long baud){
    _level = level;
    Serial.begin(baud);
}

void Logging::error(char* msg, ...){
    if (LOG_LEVEL_ERROR <= _level) {
		print ("ERROR: ",0);
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}


void Logging::warning(char* msg, ...){
    if (LOG_LEVEL_WARNING <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}

void Logging::info(char* msg, ...){
    if (LOG_LEVEL_INFO <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}


void Logging::verbose(char* msg, ...){
    if (Logging::LOG_LEVEL_MEGAVERBOSE <= _level) {
        va_list args;
        va_start(args, msg);
        print(msg,args);
    }
}



 void Logging::print(const char *format, va_list args) {
	if (!Serial) return;
    //
    // loop through format string
    for (; *format != 0; ++format) {
        if (*format == '%') {
            ++format;
            if (*format == '\0') break;
            if (*format == '%') {
                Serial.print(*format);
                continue;
            }
            if( *format == 's' ) {
				register char *s = (char *)va_arg( args, int );
				Serial.print(s);
				continue;
			}
            if( *format == 'd' || *format == 'i') {
				Serial.print(va_arg( args, int ),DEC);
				continue;
			}
            if( *format == 'x' ) {
				Serial.print(va_arg( args, int ),HEX);
				continue;
			}
            if( *format == 'X' ) {
				Serial.print("0x");
				Serial.print(va_arg( args, int ),HEX);
				continue;
			}
            if( *format == 'b' ) {
				Serial.print(va_arg( args, int ),BIN);
				continue;
			}
            if( *format == 'B' ) {
				Serial.print("0b");
				Serial.print(va_arg( args, int ),BIN);
				continue;
			}
            if( *format == 'l' ) {
				Serial.print(va_arg( args, long ),DEC);
				continue;
			}

            if( *format == 'c' ) {
				Serial.print(va_arg( args, int ));
				continue;
			}
            if( *format == 't' ) {
				if (va_arg( args, int ) == 1) {
					Serial.print("T");
				}
				else {
					Serial.print("F");				
				}
				continue;
			}
            if( *format == 'T' ) {
				if (va_arg( args, int ) == 1) {
					Serial.print("true");
				}
				else {
					Serial.print("false");				
				}
				continue;
			}

        }
        Serial.print(*format);
    }
 }
 
 Logging Logging::DEFAULT_LOG;

 
 
  




