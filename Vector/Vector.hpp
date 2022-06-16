#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include "utils.hpp"

namespace ft
{
    template <typename T, class Alloc = std::allocator<T> >
    class Vector
    {
        private:
            T *arr;
            int mysize;
            int mycapacity;
            std::allocator<T> alloc;
            unsigned int maxsize;
        public:
            typedef T* iterator;
            typedef std::reverse_iterator<iterator> reverse_iterator;

            explicit Vector ()
            {
                arr = alloc.allocate(1);
                mysize = 0;
                mycapacity = 1;
                maxsize = 1073741823;
            }
            
            explicit Vector (int n, const T& val = NULL)
            {
                arr = alloc.allocate(n);
                for (int i = 0; i < n; i++)
                    arr[i] = val;
                mysize = n;
                mycapacity = n;
                maxsize = 1073741823;
            }

            Vector(const Vector<T> &copy)
            {
                arr = alloc.allocate(copy.size());
                for (int i = 0; i < copy.size() ; i++)
                    arr[i] = copy.getArray()[i];
                mysize = copy.size();
                mycapacity = copy.capacity();
            }

            explicit Vector (iterator first, iterator last)
            {
                arr = alloc.allocate(1);
                mycapacity = 1;
                mysize = 0;
                for (iterator i = first; i < last; i++)
                {
                    if (mysize == mycapacity)
                    {
                        T *tmp = alloc.allocate(mycapacity * 2);
                        for (int i = 0; i < mysize; i++)
                            tmp[i] = arr[i];
                        alloc.deallocate(arr, mycapacity);
                        arr = tmp;
                        mycapacity *= 2;
                    }
                    arr[mysize++] = *i;
                } 
            }

            ~Vector()
            {
               alloc.deallocate(arr, mycapacity);
            }
            
            Vector & operator=(const Vector &assign)
            {
               alloc.deallocate(arr, mycapacity);
                arr = alloc.allocate(assign.size());
                for (int i = 0; i < assign.size() ; i++)
                    arr[i] = assign.getArray()[i];
                mysize = assign.size();
                mycapacity = assign.capacity();
                return *this;
            }
            
            int size() const
            {
                return mysize;
            }
            T* getArray() const
            {
                return arr;
            }
            unsigned int max_size()
            {
                return maxsize;
            }
            
            iterator begin()
            {
                return arr;
            }

            iterator end()
            {
                return arr+mysize;
            }

            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }

            reverse_iterator rend()
            {
                return reverse_iterator(begin());
            }

            void resize(int s, T v = NULL)
            {
                if (s < mysize)
                    mysize = s;
                if (mysize < s)
                {
                    T* tmp = alloc.allocate(s);
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                    for (int i = mysize; i < s; i++)
                        tmp[i] = v;
                   alloc.deallocate(arr, mycapacity);
                    arr = tmp;
                    mysize = s;
                }
            }

            int capacity() const
            {
                return mycapacity;
            }

            bool empty()
            {
                if (mysize == 0)
                    return true;
                return false;
            }

            void reserve(int n)
            {
                if (n > mycapacity)
                {
                    T* tmp = alloc.allocate(n);
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                   alloc.deallocate(arr, mycapacity);
                    arr = tmp;
                    mycapacity = n;
                }
            }

            T &operator[](int i)
            {
                return arr[i];
            }

            struct indexOutOfBound : public std::exception
            {
                const char * what () const throw ()
                {
                    return "Index Out Of Bound !";
                }
            };

            T at(int i)
            {
                if (i >= mysize)
                    throw indexOutOfBound();
                return arr[i];
            }

            T front()
            {
                return arr[0];
            } 

            T back()
            {
                return arr[mysize-1];
            }

            void push_back (const T& val)
            {
                if (mysize == mycapacity)
                {
                    T *tmp = alloc.allocate(mycapacity * 2);
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                   alloc.deallocate(arr, mycapacity);
                    arr = tmp;
                    mycapacity *= 2;
                }
                arr[mysize++] = val;
            }


            void pop_back()
            {
                mysize--;
            }

            void assign (int n, const T& val)
            {
                T *tmp = alloc.allocate(n);
                mysize = 0;
                for (int i = 0; i < n; i++)
                    tmp[mysize++] = val;
               alloc.deallocate(arr, mycapacity);
                arr = tmp;
            }

            void assign (iterator first, iterator last)
            {
                mycapacity = 1;
                mysize = 0;
                for (iterator i = first; i < last; i++)
                {
                    if (mysize == mycapacity)
                    {
                        T *tmp = alloc.allocate(mycapacity * 2);
                        for (int i = 0; i < mysize; i++)
                            tmp[i] = arr[i];
                       alloc.deallocate(arr, mycapacity);
                        arr = tmp;
                        mycapacity *= 2;
                    }
                    arr[mysize++] = *i;
                } 
            }

            iterator insert (iterator position, const T& val)
            {
                int pos = position - arr;
                if (mysize + 1 >= mycapacity)
                {
                    T *tmp = alloc.allocate(mycapacity * 2);
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                   alloc.deallocate(arr, mycapacity);
                    arr = tmp;
                    mycapacity *= 2;
                }
                T *tmp2 = alloc.allocate(mycapacity);
                for (int i = 0, j = 0; i <= mysize;i++)
                {
                    if (i == pos)
                    {
                        tmp2[j] = val;
                        j++;
                    }
                    tmp2[j++] = arr[i];
                }
               alloc.deallocate(arr, mycapacity);
                arr = tmp2;
                mysize += 1;
                return begin();
            }

            void insert (iterator position, int n, const T& val)
            {
                int pos = position - arr;
                if (mysize + n >= mycapacity)
                {
                    T *tmp = alloc.allocate(mycapacity + n);
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                   alloc.deallocate(arr, mycapacity);
                    arr = tmp;
                    mycapacity += n;
                }
                T *tmp2 = alloc.allocate(mycapacity);
                for (int i = 0, j = 0; i <= mysize;i++)
                {
                    if (i == pos)
                    {
                        for(int x = 0; x < n; x++)
                            tmp2[j++] = val;
                    }
                    tmp2[j++] = arr[i];
                }
               alloc.deallocate(arr, mycapacity);
                arr = tmp2;
                mysize += n;
            }

            void insert (iterator position, iterator first, iterator last)
            {
                int pos = position - arr;
                if (mysize + last-first >= mycapacity)
                {
                    T *tmp = alloc.allocate(mycapacity * 2 + last-first);
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                   alloc.deallocate(arr, mycapacity);
                    arr = tmp;
                    mycapacity = mycapacity * 2 + last-first;
                }
                T *tmp2 = alloc.allocate(mycapacity);
                for (int i = 0, j = 0; i <= mysize;i++)
                {
                    if (i == pos)
                    {
                        for (iterator x = first; x < last; x++)
                        {
                            tmp2[j] = *x;
                            j++;
                        }
                    }
                    tmp2[j++] = arr[i];
                }
               alloc.deallocate(arr, mycapacity);
                arr = tmp2;
                mysize += last-first;
            }
           
            
            iterator erase (iterator position)
            {
                int pos = position - arr;
                T *tmp = alloc.allocate(mycapacity);
                for (int i = 0, j = 0; i <= mysize;i++)
                {
                    if (i == pos)
                        continue;
                    tmp[j++] = arr[i];
                }
               alloc.deallocate(arr, mycapacity);
                arr = tmp;
                mysize -= 1;
                return position;
            }
            
            iterator erase (iterator first, iterator last)
            {
                int firstpos = first - arr;
                int lastpos = last - arr;
                T *tmp = alloc.allocate(mycapacity);
                for (int i = 0,j = 0; i < mysize;i++)
                {
                    if (i == firstpos)
                        i += lastpos - firstpos;
                    tmp[j++] = arr[i];
                }
               alloc.deallocate(arr, mycapacity);
                arr = tmp;
                mysize -= (lastpos - firstpos);
                return first;
            }

            void swap (Vector& x)
            {
                T* tmpArr = arr;
                int tmpMySize = mysize;
                int tmpMyCapacity = mycapacity;
                arr = x.arr;
                mysize = x.mysize;
                mycapacity = x.mycapacity;
                x.arr = tmpArr;
                x.mysize = tmpMySize;
                x.mycapacity = mycapacity;
            }

            void clear()
            {
               alloc.deallocate(arr, mycapacity);
                arr = alloc.allocate(1);
                mysize = 0;
                mycapacity = 1;
            }

            

            bool operator== (const Vector<T,Alloc>& rhs)
            {
                if (mysize != rhs.size())
                    return false;
                return equal(begin(), end(), rhs.begin());
            }
            bool operator!= (const Vector<T,Alloc>& rhs)
            {
                if (mysize == rhs.size())
                    return false;
                return !equal(begin(), end(), rhs.begin());
            }
            bool operator< (const Vector<T,Alloc>& rhs)
            {
                return lexicographical_compare(begin(), end(), rhs.begin(), rhs.end());
            }
            bool operator> (const Vector<T,Alloc>& rhs)
            {
                return lexicographical_compare(rhs.begin(), rhs.end(), begin(), end());
            }
            bool operator<= (const Vector<T,Alloc>& rhs)
            {
                return equal(begin(), end(), rhs.begin()) || !lexicographical_compare(begin(), end(), rhs.begin(), rhs.end());
            }
             bool operator>= (const Vector<T,Alloc>& rhs)
            {
                return equal(begin(), end(), rhs.begin()) || !lexicographical_compare(rhs.begin(), rhs.end(), begin(), end());
            }
            std::allocator<T> get_allocator() const 
            { 
                return alloc; 
            }
    };
}

#endif