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
using v8::Persistent;

typedef std::map<int, Persistent<String>*> PersistentMap;
typedef std::pair<int, Persistent<String>*> PersistentPair;

class stringLowLevelLib{

    public:
        PersistentMap strVec;
        int key;

        int pushVector(Persistent<String>* textPtr);
        int pushVector();
        
        
        void appendVector(const int index, const Local<String> text);

        Persistent<String>* lookUpVector(const int index);
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
