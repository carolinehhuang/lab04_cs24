// words2.cpp - implements class Words
// Caroline Huang Feb1

#include <cassert>
#include <string>
#include "words2.h"

using std::string;

namespace lab04_2
{
    Words::Words(unsigned int initCapacity) {
        used = 0;
        capacity = initCapacity;
	data = new std::string[capacity];
    }

    Words::Words(const Words& source){
	    data = new std::string[source.get_capacity()];
	    capacity = source.get_capacity();
	    used = source.size();
	    copy(source.data, source.data+used, data);
    }

    Words::~Words(){
	    delete [] data;
    }
    
    void Words:: reserve(unsigned int newCapacity){
	    std::string *newArray;
	    if(newCapacity == capacity){
		    return;
	    }
	    if(newCapacity < used){
		    newCapacity = used;
	    }
	    newArray = new std::string[newCapacity];
	    copy(data, data+used, newArray);
	    delete [] data;
	    data = newArray;
	    capacity = newCapacity;
    }


    void Words::append(string word) {
        if(used == capacity){
		reserve(used*2);
	}
	data[used] = word;
        ++used;

    }
    
    string& Words::operator[] (unsigned int index) {
        assert(index < used);
        return data[index];
    }
    
    unsigned int Words::size() const {
        return used;
    }
    
    unsigned int Words::get_capacity() const {
        return capacity;
    }
    
    string Words::operator[] (unsigned int index) const {
        assert(index < used);
        return data[index];
    }
    
}

