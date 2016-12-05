#ifndef STRINGLOWLEVELLIB_H
#define STRINGLOWLEVELLIB_H

#include <vector>
#include <regex>

class stringLowLevelLib{

    public:
        std::vector<std::string> strVec;

        int pushVector(const std::string text);
        void appendVector(const int index, const std::string text);

        std::string lookUpVector(const int index);
        bool regexVector(const int index, const  char regex[]);

        void removeVector(const int index);
        std::string chunkData(const int index, int start, int end);

        stringLowLevelLib();
        ~stringLowLevelLib();

};

#endif