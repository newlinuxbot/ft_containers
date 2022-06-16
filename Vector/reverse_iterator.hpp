#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterators.hpp"

template<typename blDataType>
class blRawReverseIterator : public blRawIterator<blDataType>
{
public:
    using difference_type = std::ptrdiff_t;
    blRawReverseIterator(blDataType* ptr = nullptr):blRawIterator<blDataType>(ptr){}
    blRawReverseIterator(const blRawIterator<blDataType>& rawIterator){this->m_ptr = rawIterator.getPtr();}
    blRawReverseIterator(const blRawReverseIterator<blDataType>& rawReverseIterator) = default;
    ~blRawReverseIterator(){}

    blRawReverseIterator<blDataType>&           operator=(const blRawReverseIterator<blDataType>& rawReverseIterator) = default;
    blRawReverseIterator<blDataType>&           operator=(const blRawIterator<blDataType>& rawIterator){this->m_ptr = rawIterator.getPtr();return (*this);}
    blRawReverseIterator<blDataType>&           operator=(blDataType* ptr){this->setPtr(ptr);return (*this);}

    blRawReverseIterator<blDataType>&           operator+=(const difference_type& movement){this->m_ptr -= movement;return (*this);}
    blRawReverseIterator<blDataType>&           operator-=(const difference_type& movement){this->m_ptr += movement;return (*this);}
    blRawReverseIterator<blDataType>&           operator++(){--this->m_ptr;return (*this);}
    blRawReverseIterator<blDataType>&           operator--(){++this->m_ptr;return (*this);}
    blRawReverseIterator<blDataType>            operator++(int){auto temp(*this);--this->m_ptr;return temp;}
    blRawReverseIterator<blDataType>            operator--(int){auto temp(*this);++this->m_ptr;return temp;}
    blRawReverseIterator<blDataType>            operator+(const int& movement){auto oldPtr = this->m_ptr;this->m_ptr-=movement;auto temp(*this);this->m_ptr = oldPtr;return temp;}
    blRawReverseIterator<blDataType>            operator-(const int& movement){auto oldPtr = this->m_ptr;this->m_ptr+=movement;auto temp(*this);this->m_ptr = oldPtr;return temp;}

    difference_type                             operator-(const blRawReverseIterator<blDataType>& rawReverseIterator){return std::distance(this->getPtr(),rawReverseIterator.getPtr());}

    blRawIterator<blDataType>                   base(){blRawIterator<blDataType> forwardIterator(this->m_ptr); ++forwardIterator; return forwardIterator;}
};

#endif