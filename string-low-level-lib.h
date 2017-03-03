#ifndef STRINGLOWLEVELLIB_H
#define STRINGLOWLEVELLIB_H

//#include <vector>
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
        //std::vector<std::string> strVec;
        std::map<  int, std::string> strVec;
        int key = 0;

         int pushVector(const std::string text);
        void appendVector(const  int index, const std::string text);

        std::string lookUpVector(const  int index);
        bool regexVector(const  int index, const  char regex[]);

        int removeVector(const  int index);
        std::string chunkData(const  int index, int start, int end);

        int size();
        int sizeAt(const  int index);
        bool hasAt(const  int index);

        void clear();

        stringLowLevelLib();
        ~stringLowLevelLib();

};

#endif