#ifndef UTILS_StaticList
#define UTILS_StaticList

template <typename T>
class StaticList {
    unsigned int count;
    T* items;
    unsigned int length;

public:

    bool Add(T newItem){
        if(count == length) return false;
        items[count++] = newItem;
        return true;
    }

    bool Add(StaticList<T> newItems){
        int i = 0;
        int c = newItems.Count();
        while(i < c){
            Add(newItems[i]);
            ++i;
        }
        return true;
    }

    void Clear(){
        count = 0;
    }

    unsigned int Count(){
        return count;
    }

    unsigned int Length(){
        return length;
    }

    bool RemoveLast(){
        if(!count) return false;
        --count;
        return true;
    }

    StaticList(unsigned int length) : 
            count(0){
        this->length = length;
        items = new T[length];
    }

    T& operator[](unsigned int index){
        //while(index >= count) index -= count;
        return items[index];
    }

};

#endif