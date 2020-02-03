// words2.h - version 1 of class Words
// See Lab04 instructions for details.

#include <string>

#ifndef WORDS2_H
#define WORDS2_H

namespace lab04_1
{
    class Words
    {
    public:
	Words(unsigned int initCapacity = DEFAULT_CAPACITY);
	Words(const Words& source);

        
        void append(std::string word);
        std::string& operator[] (unsigned int index);
        
        unsigned int size() const;
        unsigned int get_capacity() const;
        std::string operator[] (unsigned int index) const;
        
    private:
	std::string *data[]; 
        unsigned int used;
        unsigned int capacity;
    };

}

#endif

