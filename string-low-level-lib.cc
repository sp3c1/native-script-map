#include "string-low-level-lib.h"

int stringLowLevelLib::pushVector(const std::string text){
    strVec.push_back(text);
    return (int)strVec.size();
}

void stringLowLevelLib::appendVector(const int index, const std::string text){
    strVec.at(index).append(text);
}

std::string stringLowLevelLib::lookUpVector(const int index){
    try{ 
        return strVec.at(index);
    }catch(...){
        return "";
    }
}

bool stringLowLevelLib::regexVector(const int index, const  char regex[]){
    try{
        return std::regex_match (strVec.at(index), std::regex("(sub)(.*)") );
    }catch(...){
        return false;
    }
}

void stringLowLevelLib::removeVector(const int index){
    strVec.erase(strVec.begin()+index);
}

std::string stringLowLevelLib::chunkData(const int index, int start, int end){    
    try{ 
        std::string strToChunk = strVec.at(index).substr(start,end); 
        return strVec.at(index);
    }catch(...){
        return "";
    }
}

stringLowLevelLib::stringLowLevelLib(){

}

stringLowLevelLib::~stringLowLevelLib(){
    strVec.clear();
}