#ifndef UTILS_HPP
#define UTILS_HPP

template <typename iterator>
bool equal ( iterator first1, iterator last1, iterator first2 )
{
    while (first1!=last1) {
        if (!(*first1 == *first2)) 
        return false;
        ++first1; ++first2;
    }
    return true;
}

template <typename iterator>
bool equal ( iterator first1, iterator last1, iterator first2, bool (*func)(iterator,iterator))
{
    while (first1!=last1) {
            if (!pred(*first1,*first2))
            return false;
            ++first1; ++first2;
        }
    return true;
}

template <typename iterator>
bool lexicographical_compare (iterator first1, iterator last1, iterator first2, iterator last2)
{
    while (first1!=last1)
    {
        if (first2==last2 || *first2<*first1) return false;
        else if (*first1<*first2) return true;
        ++first1; ++first2;
    }
    return (first2!=last2);
}

#endif