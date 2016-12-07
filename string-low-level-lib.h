#ifndef STRINGLOWLEVELLIB_H
#define STRINGLOWLEVELLIB_H

//#include <vector>
#include <map>
#include <regex>


#ifdef TARGET_OS_MAC
  // Mac Includes Here
  #include "sys/timeb.h"
#endif

#ifdef __linux__
  #include "sys/timeb.h"
#endif

#ifdef _WIN32 || _WIN64 
  #include "sys/timeb.h"
#endif


class stringLowLevelLib{

    public:
        //std::vector<std::string> strVec;
        std::map< long long int, std::string> strVec;

        long long int pushVector(const std::string text);
        void appendVector(const long long int index, const std::string text);

        std::string lookUpVector(const long long int index);
        bool regexVector(const long long int index, const  char regex[]);

        void removeVector(const long long int index);
        std::string chunkData(const long long int index, int start, int end);

        int size();

        void clear();

        stringLowLevelLib();
        ~stringLowLevelLib();

};

#endif