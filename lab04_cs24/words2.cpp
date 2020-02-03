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

    Words& Words::operator=(const Words &source){
	    std::string *newData;
	    if ( this == &source){
		    return *this;
	    }
	    if (capacity != source.get_capacity()){
		    newData = new std::string[source.get_capacity()];
		    delete [] data;
		    data = newData;
		    capacity = source.get_capacity();
	    }
	    used = source.size();
	    copy(source.data, source.data+used, data);
	    return *this;
    }

   


    void Words::append(string word) {
        if(used == capacity){
		std::string *newArray = new std::string[used*2];
		copy(data, data+used, newArray);
		delete [] data;
		data = newArray;
		capacity = used*2;
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

