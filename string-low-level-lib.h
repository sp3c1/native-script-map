#ifndef STRINGLOWLEVELLIB_H
#define STRINGLOWLEVELLIB_H

#include <nan.h>
#include <map>
#include <regex>
#include "sys/timeb.h"
#include <chrono>

#include <iostream>

#ifdef TARGET_OS_MAC
    #include "sys/types.h" //for time
#endif

class stringLowLevelLib{

    public:
        
        std::map<  int, const std::string*> strVec;
        //std::map<  int, const char*> strVec;
        int key = 0;

        int pushVector(const std::string* text);
        //int pushVector(const char* text);

        void appendVector(const  int index, const std::string* text);
        //void appendVector(const  int index, const char* text);

        const std::string* lookUpVector(const int index);
        //const char* lookUpVector(const  int index);

        bool regexVector(const  int index, const  char regex[]);

        int removeVector(const  int index);

        std::string* chunkData(const  int index, int start, int end);
        //const char* chunkData(const  int index, int start, int end);

        int size();
        int sizeAt(const  int index);
        bool hasAt(const  int index);

        void clear();

        stringLowLevelLib();
        ~stringLowLevelLib();

};

#endif
