#ifndef ITERATORS_HPP
#define ITERATORS_HPP

template<typename blDataType>
class blRawIterator
{
    public:

        using iterator_category = std::random_access_iterator_tag;
        using value_type = blDataType;
        using difference_type = std::ptrdiff_t;
        using pointer = blDataType*;
        using reference = blDataType&;

    public:

        blRawIterator(blDataType* ptr = nullptr){m_ptr = ptr;}
        blRawIterator(const blRawIterator<blDataType>& rawIterator) = default;
        ~blRawIterator(){}

        blRawIterator<blDataType>&                  operator=(const blRawIterator<blDataType>& rawIterator) = default;
        blRawIterator<blDataType>&                  operator=(blDataType* ptr){m_ptr = ptr;return (*this);}

        operator                                    bool()const
        {
            if(m_ptr)
                return true;
            else
                return false;
        }

        bool                                        operator==(const blRawIterator<blDataType>& rawIterator)const{return (m_ptr == rawIterator.getConstPtr());}
        bool                                        operator!=(const blRawIterator<blDataType>& rawIterator)const{return (m_ptr != rawIterator.getConstPtr());}

        blRawIterator<blDataType>&                  operator+=(const difference_type& movement){m_ptr += movement;return (*this);}
        blRawIterator<blDataType>&                  operator-=(const difference_type& movement){m_ptr -= movement;return (*this);}
        blRawIterator<blDataType>&                  operator++(){++m_ptr;return (*this);}
        blRawIterator<blDataType>&                  operator--(){--m_ptr;return (*this);}
        blRawIterator<blDataType>                   operator++(int){auto temp(*this);++m_ptr;return temp;}
        blRawIterator<blDataType>                   operator--(int){auto temp(*this);--m_ptr;return temp;}
        blRawIterator<blDataType>                   operator+(const difference_type& movement){auto oldPtr = m_ptr;m_ptr+=movement;auto temp(*this);m_ptr = oldPtr;return temp;}
        blRawIterator<blDataType>                   operator-(const difference_type& movement){auto oldPtr = m_ptr;m_ptr-=movement;auto temp(*this);m_ptr = oldPtr;return temp;}

        difference_type                             operator-(const blRawIterator<blDataType>& rawIterator){return std::distance(rawIterator.getPtr(),this->getPtr());}

        blDataType&                                 operator*(){return *m_ptr;}
        const blDataType&                           operator*()const{return *m_ptr;}
        blDataType*                                 operator->(){return m_ptr;}

        blDataType*                                 getPtr()const{return m_ptr;}
        const blDataType*                           getConstPtr()const{return m_ptr;}

    protected:

        blDataType*                                 m_ptr;
};


#endif