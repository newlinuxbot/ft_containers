#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>

namespace ft
{
    template <typename T>
    class Vector
    {
        private:
            T *arr;
            int mysize;
            int mycapacity;
            unsigned int maxsize;
        public:
            typedef T* iterator;
            typedef std::reverse_iterator<iterator> reverse_iterator;

            explicit Vector (const std::allocator<T>& alloc = std::allocator<T>())
            {
                arr = new T[1];
                mysize = 0;
                mycapacity = 1;
                maxsize = 1073741823;
            }
            
            explicit Vector (int n, const T& val = NULL,
             const std::allocator<T>& alloc = std::allocator<T>())
            {
                arr = new T[n];
                for (int i = 0; i < n; i++)
                    arr[i] = val;
                mysize = n;
                mycapacity = n;
                maxsize = 1073741823;
            }

            Vector(const Vector<T> &copy)
            {
                arr = new T[copy.size()];
                for (int i = 0; i < copy.size() ; i++)
                    arr[i] = copy.getArray()[i];
                mysize = copy.size();
                mycapacity = copy.capacity();
            }

            explicit Vector (iterator first, iterator last,
            const std::allocator<T>& alloc = std::allocator<T>())
            {
                arr = new T[1];
                mycapacity = 1;
                mysize = 0;
                for (iterator i = first; i < last; i++)
                {
                    if (mysize == mycapacity)
                    {
                        T *tmp = new T[mycapacity * 2];
                        for (int i = 0; i < mysize; i++)
                            tmp[i] = arr[i];
                        delete[] arr;
                        arr = tmp;
                        mycapacity *= 2;
                    }
                    arr[mysize++] = *i;
                } 
            }

            ~Vector()
            {
                delete[] arr;
            }
            
            Vector & operator=(const Vector &assign)
            {
                delete[] arr;
                arr = new T[assign.size()];
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
                    T* tmp = new T[s];
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                    for (int i = mysize; i < s; i++)
                        tmp[i] = v;
                    delete[] arr;
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
                    T* tmp = new T[n];
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                    delete[] arr;
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
                    T *tmp = new T[mycapacity * 2];
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                    delete[] arr;
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
                T *tmp = new T[n];
                mysize = 0;
                for (int i = 0; i < n; i++)
                    tmp[mysize++] = val;
                delete[] arr;
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
                        T *tmp = new T[mycapacity * 2];
                        for (int i = 0; i < mysize; i++)
                            tmp[i] = arr[i];
                        delete[] arr;
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
                    T *tmp = new T[mycapacity * 2];
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                    delete[] arr;
                    arr = tmp;
                    mycapacity *= 2;
                }
                T *tmp2 = new T[mycapacity];
                for (int i = 0, j = 0; i <= mysize;i++)
                {
                    if (i == pos)
                    {
                        tmp2[j] = val;
                        j++;
                    }
                    tmp2[j++] = arr[i];
                }
                delete[] arr;
                arr = tmp2;
                mysize += 1;
                return begin();
            }

            void insert (iterator position, int n, const T& val)
            {
                int pos = position - arr;
                if (mysize + n >= mycapacity)
                {
                    T *tmp = new T[mycapacity + n];
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                    delete[] arr;
                    arr = tmp;
                    mycapacity += n;
                }
                T *tmp2 = new T[mycapacity];
                for (int i = 0, j = 0; i <= mysize;i++)
                {
                    if (i == pos)
                    {
                        for(int x = 0; x < n; x++)
                            tmp2[j++] = val;
                    }
                    tmp2[j++] = arr[i];
                }
                delete[] arr;
                arr = tmp2;
                mysize += n;
            }

            void insert (iterator position, iterator first, iterator last)
            {
                int pos = position - arr;
                if (mysize + last-first >= mycapacity)
                {
                    T *tmp = new T[mycapacity * 2 + last-first];
                    for (int i = 0; i < mysize; i++)
                        tmp[i] = arr[i];
                    delete[] arr;
                    arr = tmp;
                    mycapacity = mycapacity * 2 + last-first;
                }
                T *tmp2 = new T[mycapacity];
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
                delete[] arr;
                arr = tmp2;
                mysize += last-first;
            }
           
            
            iterator erase (iterator position)
            {
                int pos = position - arr;
                T *tmp = new T[mycapacity];
                for (int i = 0, j = 0; i <= mysize;i++)
                {
                    if (i == pos)
                        continue;
                    tmp[j++] = arr[i];
                }
                delete[] arr;
                arr = tmp;
                mysize -= 1;
                return position;
            }
            
            iterator erase (iterator first, iterator last)
            {
                int firstpos = first - arr;
                int lastpos = last - arr;
                T *tmp = new T[mycapacity];
                for (int i = 0,j = 0; i < mysize;i++)
                {
                    if (i == firstpos)
                        i += lastpos - firstpos;
                    tmp[j++] = arr[i];
                }
                delete[] arr;
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
                delete[] arr;
                arr = new T[1];
                mysize = 0;
                mycapacity = 1;
            }
            
            

    };
}

#endif