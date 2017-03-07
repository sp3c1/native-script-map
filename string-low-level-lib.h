#ifndef STRINGLOWLEVELLIB_H
#define STRINGLOWLEVELLIB_H

//#include <vector>
#include <map>
#include <regex>
#include <chrono>
#include <node.h>
#include <nan.h>

#include <iostream>

using v8::Local;
using v8::String;
using v8::Value;
using v8::Persistent;
using v8::Isolate;

class wrapper{
    public:
        Nan::Persistent<v8::String> strObj;
    
        wrapper& operator=(wrapper obj);
        wrapper& operator=(wrapper* obj);

        wrapper( wrapper& other );

        wrapper();
};

typedef std::map<int, wrapper> PersistentMap;
typedef std::pair<int, wrapper> PersistentPair;
typedef Nan::Persistent<String> PersistentString;


class stringLowLevelLib{

    public:
        PersistentMap strVec;
        int key;

        //int pushVector(Persistent<String>* textPtr);
        //int pushVector(Isolate* isolate, Local<String> arg); /** +++ **/
        int pushVector(Local<String> arg); /** +++ **/
        
        
        void appendVector(const int index, const Local<String>* text);
        //void appendVector(const int index, const Local<String> text);

        //Persistent<String>* lookUpVector(const int index);
        wrapper lookUpVector(const int index);
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
