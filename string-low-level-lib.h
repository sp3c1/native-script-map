#ifndef STRINGLOWLEVELLIB_H
#define STRINGLOWLEVELLIB_H

//#include <vector>
#include <map>
#include <regex>
#include <chrono>
#include <node.h>

using v8::Local;
using v8::String;
using v8::Value;
//using v8::PersistentBase;

class stringLowLevelLib{

    public:
        //std::vector<std::string> strVec;
        std::map< int, Local<String>> strVec;
        int key;

        int pushVector(const Local<String> text);
        
        
        void appendVector(const int index, const Local<String> text);

        Local<String> lookUpVector(const int index);
        bool regexVector(const int index, const  char regex[]);

        int removeVector(const int index);
        std::string chunkData(const int index, int start, int end);
        

        int size();
        int sizeAt(const int index);
        bool hasAt(const int index);

        void clear();
        

        stringLowLevelLib();
        ~stringLowLevelLib();

};

#endif
