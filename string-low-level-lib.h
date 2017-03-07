#ifndef STRINGLOWLEVELLIB_H
#define STRINGLOWLEVELLIB_H

#include <nan.h>
#include <map>
#include <regex>
#include <iostream>

using std::string;

class stringLowLevelLib{

    public:
        
        std::map<  int,  string> strVec;
        int key = 0;

        int pushVector( string text);
        int pushVector( v8::Local<v8::String> text);
        //int pushVector(const char* text);

        void appendVector(const  int index, string* text);
        void appendVector(const  int index, v8::Local<v8::String> text);

        const string* lookUpVector(const int index);
        //const char* lookUpVector(const  int index);

        bool regexVector(const  int index, const  char regex[]);

        int removeVector(const  int index);

        string chunkData(const  int index, int start, int end);
        //const char* chunkData(const  int index, int start, int end);

        int size();
        int sizeAt(const  int index);
        bool hasAt(const  int index);

        void clear();

        stringLowLevelLib();
        ~stringLowLevelLib();

};

#endif
