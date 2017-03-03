#include "string-low-level-lib.h"

int stringLowLevelLib::pushVector(const std::string text){
    strVec.insert(std::pair<int, std::string>(key, text));
    
    return key++;
}

void stringLowLevelLib::appendVector(const int index, const std::string text){
    try{
        //strVec.at(index).append(text);
    }catch(...){
        throw false;
    }
}

std::string stringLowLevelLib::lookUpVector(const int index){
    try{ 
        return strVec.at(index);
    }catch(...){
        throw false;
    }
}

bool stringLowLevelLib::regexVector(const int index, const  char regex[]){
    
    try{
        return std::regex_search (strVec.at(index), std::regex(regex) );
    }catch(...){
        throw false;
    }
}

int stringLowLevelLib::removeVector(const int index){
    //exception handled by wrapper
    return strVec.erase(index);
}

std::string stringLowLevelLib::chunkData(const int index, int start, int end){
   
    if(end<start){
        throw false;
    }
  
        

    try{ 
        return std::string(strVec.at(index).substr(start,end)); 
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
    strVec.clear();
}

stringLowLevelLib::stringLowLevelLib(){

}

stringLowLevelLib::~stringLowLevelLib(){
    strVec.clear();
}