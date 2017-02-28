#include "string-low-level-lib.h"

int stringLowLevelLib::pushVector(Persistent<String>* textPtr){
    
    //strVec.insert(std::pair<int, Local<String>>(key, text));
    strVec.insert(PersistentPair(this->key, textPtr));
    
    return key++;
}


void stringLowLevelLib::appendVector(const int index, const Local<String> text){    
    try{       
        //strVec[index] = String::Concat(strVec[index],text);
    }catch(...){
        throw false;
    }
    
}

Persistent<String>* stringLowLevelLib::lookUpVector(const int index){
//void stringLowLevelLib::lookUpVector(const int index){
  
    try{ 
        return strVec.at(index);
    }catch(...){
        //throw false;
        return nullptr;
    }
}

bool stringLowLevelLib::regexVector(const int index, const  char regex[]){
    return true;
    /*
    try{
        return std::regex_search (strVec.at(index), std::regex(regex) );
    }catch(...){
        throw false;
    }
    */
}

int stringLowLevelLib::removeVector(const int index){
    //exception handled by wrapper
    //todo clear persistent
    return strVec.erase(index);
}

std::string  stringLowLevelLib::chunkData(const int index, int start, int end){
    if(end<start){
        throw false;
    }

    try{
        //return std::string(*String::Utf8Value(strVec.at(index))).substr(start,end);
        return std::string("oi");
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
        //return strVec.at(index)->Length();
        return 0;
    }catch(...){
        throw false;
    }
}

bool stringLowLevelLib::hasAt(const int index){
    return true;
    try{
        strVec.at(index);
        return true; 
    }catch(...){
        return  false;
    }

}

void stringLowLevelLib::clear(){
    //todo clear persistent
    strVec.clear();
}

stringLowLevelLib::stringLowLevelLib(){
    key = 0;
}

stringLowLevelLib::~stringLowLevelLib(){
    //todo clear persistent
    strVec.clear();
}