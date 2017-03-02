#include "string-low-level-lib.h"

// view  https://github.com/nodejs/nan/blob/137bd5ae2d47064d44791a094582d97ca0e1b8bb/test/cpp/persistent.cpp
// https://nodeaddons.com/c-processing-from-node-js/
// 

wrapper::wrapper(){ //constructor
    this->strObj.Reset();
}

wrapper& wrapper::operator=(wrapper obj){ // assign operator
  this->strObj.Reset(obj.strObj);
  return *this;
}

wrapper::wrapper( wrapper& other ){ // copying object over
    this->strObj.Reset(other.strObj);
}

int stringLowLevelLib::pushVector(Local<String> arg){
    wrapper persistentWrapper;
    persistentWrapper.strObj.Reset(arg);
    strVec.insert(PersistentPair(key, persistentWrapper));
    
    return key++;
}


void stringLowLevelLib::appendVector(const int index, const Local<String> text){    
    try{
        Local<String> tmp = Nan::New(strVec.at(index).strObj);
        tmp = String::Concat(tmp,text);
        strVec.at(index).strObj.Reset(tmp);
    }catch(...){
        throw false;
    }
    
}

wrapper stringLowLevelLib::lookUpVector(const int index){
    try{ 
        return strVec.at(index);
    }catch(...){
        throw false;
    }
}

bool stringLowLevelLib::regexVector(const int index, const  char regex[]){

    try{
        //would rather use node native regex
        return std::regex_search (*String::Utf8Value(Nan::New(strVec.at(index).strObj)), std::regex(regex) );
    }catch(...){
        throw false;
    }
    
}

int stringLowLevelLib::removeVector(const int index){
    //exception handled by wrapper
    strVec.at(index).strObj.Reset();
    return strVec.erase(index);
}

std::string  stringLowLevelLib::chunkData(const int index, int start, int end){
    if(end<start){
        throw false;
    }

    try{
        //return String::Utf8Value(Nan::New(strVec.at(index)).strObj)
        //return std::string(*String::Utf8Value(strVec.at(index).strObj)).substr(start,end);
        return std::string("");
    }catch(...){
        throw false;
    }
}


int stringLowLevelLib::size(){
    try{
        return (int) strVec.size();
    }catch(...){
        throw false;
    }
} 

int stringLowLevelLib::sizeAt(const int index){
    try{
        //dont want to copy this really unless its not a copy
        Local<String> tmp = Nan::New(strVec.at(index).strObj);
        return (int) tmp->Utf8Length();
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
    for(auto &ent1 : strVec) { //const?
        ent1.second.strObj.Reset();
    }

    strVec.clear();
}

stringLowLevelLib::stringLowLevelLib(){
    key = 0;
}

stringLowLevelLib::~stringLowLevelLib(){
    for(auto &ent1 : strVec) { //const?
        ent1.second.strObj.Reset();
    }

    strVec.clear();
}