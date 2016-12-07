#include "string-low-level-lib.h"

long long int stringLowLevelLib::pushVector(const std::string text){
    long long int key = 0;

    #ifdef _WIN32 || _WIN64
        timeb tb;
        ftime(&tb);
        int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;

        time_t seconds; 
        time(&seconds);

        key = (long long int)(seconds * 1000 + nCount);
     #endif

    strVec.insert(std::pair<long long int, std::string>(key, text));
    return key;
}

void stringLowLevelLib::appendVector(const long long int index, const std::string text){
    strVec.at(index).append(text);
}

std::string stringLowLevelLib::lookUpVector(const long long int index){
    try{ 
        return strVec.at(index);
    }catch(...){
        return "";
    }
}

bool stringLowLevelLib::regexVector(const long long int index, const  char regex[]){
    try{
        return std::regex_match (strVec.at(index), std::regex(regex) );
    }catch(...){
        return false;
    }
}

void stringLowLevelLib::removeVector(const long long int index){
    strVec.erase(index);
}

std::string stringLowLevelLib::chunkData(const long long int index, int start, int end){    
    try{ 
        std::string strToChunk = strVec.at(index).substr(start,end); 
        return strToChunk;
    }catch(...){
        return "";
    }
}

int stringLowLevelLib::size(){
    return (int) strVec.size();
} 

void stringLowLevelLib::clear(){
    strVec.clear();
}

stringLowLevelLib::stringLowLevelLib(){

}

stringLowLevelLib::~stringLowLevelLib(){
    strVec.clear();
}