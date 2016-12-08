#include "string-low-level-lib.h"

long long int stringLowLevelLib::pushVector(const std::string text){
    long long int key = 0;

    timeb tb;
    ftime(&tb);
    //int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
    //int nCount = (tb.time & 0xfffff) * 1000;
    int nCount = tb.millitm ;

    time_t seconds; 
    time(&seconds);

    //key = (long long int)(seconds * 1000 + nCount);
    //key= nCount;
    
    auto now = std::chrono::system_clock::now();
    auto now_us = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    
    auto epoch = now_us.time_since_epoch();
    auto value = std::chrono::duration_cast<std::chrono::microseconds>(epoch);
    
    key = (long long int) value.count();
    //std::cout << key << '\n';
    

    strVec.insert(std::pair<long long int, std::string>(key, text));
    
    return key;
}

void stringLowLevelLib::appendVector(const long long int index, const std::string text){
    try{
        strVec.at(index).append(text);
    }catch(...){
        throw false;
    }
}

std::string stringLowLevelLib::lookUpVector(const long long int index){
    try{ 
        return strVec.at(index);
    }catch(...){
        throw false;
    }
}

bool stringLowLevelLib::regexVector(const long long int index, const  char regex[]){
    
    try{
        return std::regex_search (strVec.at(index), std::regex(regex) );
    }catch(...){
        throw false;
    }
}

int stringLowLevelLib::removeVector(const long long int index){
    //exception handled by wrapper
    return strVec.erase(index);
}

std::string stringLowLevelLib::chunkData(const long long int index, int start, int end){
   
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

int stringLowLevelLib::sizeAt(const long long int index){
    try{
        return (int) strVec.at(index).size();
    }catch(...){
        throw false;
    }
}

bool stringLowLevelLib::hasAt(const long long int index){
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