#ifndef UTILS_CSTR
#define UTILS_CSTR

#include <cstring>
#include <sstream>
#include <Arduino.h>

class CStrUtil {
private:
    char* value;
    /*how many characters, not including terminator are in the string */
    unsigned int count;
    unsigned int length;

    template <typename T>
    void Init(T newString, unsigned int count, unsigned int length){
        this->count = count;
        this->length = length;
        this->value = new char[length+1];
        strcpy(this->value,newString);
    }
    void Resize(unsigned int newLength);

public:
    unsigned int AllocatedLength();
    char* Append(char* charValue);
    char* Append(const char* charValue);
    char* Append(double doubleValue);
    char* Append(double doubleValue, unsigned int precision);
    char* Append(int intValue);
    static char* ConstCStrToCStr(const char* staticCStr);
    CStrUtil(char* newString);
    CStrUtil(char* newString, unsigned int allocatedLength);
    CStrUtil(const char* newString);
    CStrUtil(const char* newString, unsigned int allocatedLength);
    ~CStrUtil();
    /*The precision can range from -whatever up to -6. For some reason
    it seems like the sprintf function only supports up to 6 decimal 
    points by default, so we're going with that. */
    static char* DoubleToCStr(double doubleValue,int precision);
    static int IndexOfChar(char* string, char searchTerm);
    static int IndexOfRightPad(char* string, char padChar);
    static int IndexOfRightPad(const char* string, char padChar);
    template <typename T>
    char* Insert(T charValue, unsigned int index){
        std::memcpy(&value[index],charValue,Length<T>(charValue)*sizeof(char));
        return value;
    }
    char* Insert(double doubleValue, unsigned int index, int precision);
    /*This actually returns the private variable "count" which is the 
    current number of chars with meaning in the array.*/
    unsigned int Length();
    /*The length of the char*, ignoring the termination character \0 */
    template <typename T>
    static unsigned int Length(T input){
        unsigned int index = 0;
        while(input[index] != '\0'){
            ++index;
        }
        return index;
    }
    static char* Substring(char* input,unsigned int length);
    char* Value();
};


#endif




    //testing the CStr util object
/*
    CStrUtil csu = CStrUtil("This is my string. I want to add a number, ",270);
    Serial.println(csu.Value());
    Serial.println(csu.Length());
    csu.Append(1234);
    Serial.println(csu.Value());
    Serial.println(csu.Length());
    csu.Append(". JUST KIDDING, GUY! I can keep making this string as long as I need, friend!");
    Serial.println(csu.Value());
    Serial.println(csu.Length());

    Serial.println(CStrUtil::DoubleToCStr((double)7654321.123456789,4));
    Serial.println(CStrUtil::DoubleToCStr((double)7654321.123456789,0));
    Serial.println(CStrUtil::DoubleToCStr(123,0));
    Serial.println(CStrUtil::DoubleToCStr((double)7654321.1234634,-1));
    Serial.println(CStrUtil::DoubleToCStr((double)7654321.1234,-1));
    Serial.println(CStrUtil::DoubleToCStr((double)7654321.123,-1));
    Serial.println(CStrUtil::DoubleToCStr((double)7654321.,-1));
    Serial.println(CStrUtil::DoubleToCStr((double)7654321,-1));
    Serial.println(CStrUtil::DoubleToCStr((double)7654000,-1));

    CStrUtil instr = CStrUtil("My value for index[  ]:       .");

    instr.Insert((double)53,19,0);
    instr.Insert("583.23",24);
    Serial.println(instr.Value());
*/