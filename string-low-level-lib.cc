#include "string-low-level-lib.h"

int stringLowLevelLib::pushVector( string text){
    strVec.insert(std::pair<int,  string>(key, text));
    return key++;
}

int stringLowLevelLib::pushVector( v8::Local<v8::String> text){
    strVec.insert(std::pair<int,  string>(key, *v8::String::Utf8Value(text)));
    return key++;
}

/*
int stringLowLevelLib::pushVector(const char* text){
    strVec.insert(std::pair<int, const char*>(key, text));
    return key++;
}
*/


void stringLowLevelLib::appendVector(const int index, string* text){
    try{
        strVec.at(index).append(*text);
    }catch(...){
        throw false;
    }
}

void stringLowLevelLib::appendVector(const int index,  v8::Local<v8::String> text){
    try{
        strVec.at(index).append(*v8::String::Utf8Value(text));
    }catch(...){
        throw false;
    }
}


const string* stringLowLevelLib::lookUpVector(const int index){
    try{ 
        return &strVec.at(index);
    }catch(...){
        throw false;
    }
}

/*
const char* stringLowLevelLib::lookUpVector(const int index){
    try{ 
        return strVec.at(index);
    }catch(...){
        throw false;
    }
}
*/

bool stringLowLevelLib::regexVector(const int index, const  char regex[]){
    try{
        return std::regex_search (strVec.at(index), std::regex(regex) );
    }catch(...){
        throw false;
    }

}

int stringLowLevelLib::removeVector(const int index){
    //exception handled by wrapper
    int tmp = 0;

    /* cause err on linux, and there is  no need now frankly
    try{
        strVec.at(index).clear();
        strVec.at(index).~string();
    }catch(...){
        
    }*/

    try{
        tmp = strVec.erase(index);
    }catch(...){

    }
    
    return tmp;
}


string stringLowLevelLib::chunkData(const int index, int start, int end){
    if(end<start){
        throw false;
    }
  
    try{ 
        return std::string(strVec.at(index).substr(start,end)); 
    }catch(...){
        throw false;
    }
}

/*
const char* stringLowLevelLib::chunkData(const int index, int start, int end){
    if(end<start){
        throw false;
    }
  
    try{ 
        return nullptr; 
    }catch(...){
        throw false;
    }
}
*/

int stringLowLevelLib::size(){
    try{
        return (int) strVec.size();
    }catch(...){
        throw false;
    }
} 

int stringLowLevelLib::sizeAt(const int index){
    try{
        return (int) strVec.at(index).size();
    }catch(...){
        throw false;
    }
}

bool stringLowLevelLib::hasAt(const int index){
    try{
        strVec.at(index);
        return true; 
    }catch(...){
        return  false;
    }
}

void stringLowLevelLib::clear(){
    /* cause err on linux, and there is  no need now frankly
    for(auto &ent1 : strVec) {
        ent1.second.clear();
        ent1.second.~string();
    }
    */

    strVec.clear();
}

stringLowLevelLib::stringLowLevelLib(){

}

stringLowLevelLib::~stringLowLevelLib(){
    /* cause err on linux, and there is  no need now frankly
    for(auto &ent1 : strVec) {
        ent1.second.clear();
        ent1.second.~string();
    }
    */

    strVec.clear();
}