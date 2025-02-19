#include "../include/cstrUtil.h"

unsigned int CStrUtil::AllocatedLength(){
    return length;
}

char* CStrUtil::Append(char* charValue){
    unsigned int newCount = Length(charValue);
    if(newCount + count > length){
        Resize(newCount + count);
    }
    std::memcpy(&value[count],charValue,newCount*sizeof(char));
    count += newCount;
    value[count] = '\0';
    return value;
}

char* CStrUtil::Append(const char* charValue){
    unsigned int newCount = Length(charValue);
    if(newCount + count > length){
        Resize(newCount + count);
    }
    std::memcpy(&value[count],charValue,newCount*sizeof(char));
    count += newCount;
    value[count] = '\0';
    return value;
}

char* CStrUtil::Append(double doubleValue){
    return Append(DoubleToCStr(doubleValue,2));
}

char* CStrUtil::Append(double doubleValue,unsigned int precision){
    return Append(DoubleToCStr(doubleValue,precision));
}

char* CStrUtil::Append(int intValue){
    return Append(DoubleToCStr((int)intValue,0));
}

char* CStrUtil::ConstCStrToCStr(const char* staticCStr){
    unsigned int i = Length(staticCStr);
    char* result = new char[i+1];
    strcpy(result,staticCStr);
    return result;
}

CStrUtil::CStrUtil(char* newString){
    unsigned int i = Length(newString);
    Init<char*>(newString, i, i);
}

CStrUtil::CStrUtil(char* newString, unsigned int allocatedLength){
    Init<char*>(newString, Length(newString), allocatedLength);
}

CStrUtil::CStrUtil(const char* newString){
    unsigned int i = Length(newString);
    Init<const char*>(newString, i, i);
}

CStrUtil::CStrUtil(const char* newString, unsigned int allocatedLength){
    Init<const char*>(newString, Length(newString), allocatedLength);
}

CStrUtil::~CStrUtil(){
    delete[] value;
}

char* CStrUtil::DoubleToCStr(double doubleValue,int precision){
    char* buffer = new char[25]; // Make sure the buffer is large enough
    sprintf(buffer, "%f", doubleValue);

    int length = Length(buffer);
    if(precision > 0){
        unsigned int cLength = length - 6 + precision;
        return Substring(buffer, cLength);
    }
    if(precision == 0){
        unsigned int cLength = length - 7;
        return Substring(buffer, cLength);
    }

    //maybe if precision is set to -1, just go as far as it has not padded 
    //zeros on the right.
    int rpIndex = IndexOfRightPad(buffer,'0');
    if(rpIndex == -1) return buffer;
    if(rpIndex < length){
        if(length - rpIndex == 6) rpIndex -= 1;
        return Substring(buffer, rpIndex);
    }
    return buffer;
}

int CStrUtil::IndexOfChar(char* string, char term){
    int index = 0;
    int length = static_cast<int>(Length(string));
    while(index < length){
        if(string[index] == term) return index;
        ++index;
    }
    return -1;
}

int CStrUtil::IndexOfRightPad(char* string, char padChar){
    int length = static_cast<int>(Length(string));
    int index = length;
    while(index-- > 0){
        if(string[index] == padChar) continue;
        if(index == length-1) return -1;
        return ++index;
    }
    return 0;
}

int CStrUtil::IndexOfRightPad(const char* string, char padChar){
    int length = static_cast<int>(Length(string));
    int index = length;
    while(index-- > 0){
        if(string[index] == padChar) continue;
        if(index == length-1) return -1;
        return ++index;
    }
    return 0;
}

char* CStrUtil::Insert(double doubleValue, unsigned int index, int precision){
    char* doubleChar = DoubleToCStr(doubleValue,precision);
    std::memcpy(&value[index],doubleChar,Length(doubleChar)*sizeof(char));
    return value;
}

unsigned int CStrUtil::Length(){
    return count;
}

void CStrUtil::Resize(unsigned int newLength){
    char* newValue = new char[newLength+1];
    std::strcpy(newValue,value);
    delete[] value;
    value = newValue;
    length = newLength;
    Serial.print("Resize CStr buffer to ");
    Serial.println(length);
}

char* CStrUtil::Substring(char* input,unsigned int length){
    char* output = new char[length+1];//add one for the null
    unsigned int inputLength = Length(input)+1;//add one for the null
    if(length > inputLength){
        length = inputLength;
    } 
    output[length] = '\0';
    while(length --> 0){
        output[length] = input[length];
    }
    return output;
}

char* CStrUtil::Value(){
    return value;
}