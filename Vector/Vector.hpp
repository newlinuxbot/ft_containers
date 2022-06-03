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

            Vector()
            {
                arr = new T[1];
                arr[0] = 0;
                mysize = 0;
                mycapacity = 2;
                maxsize = 1073741823;
            }

            Vector(T n)
            {
                arr = new T[n];
                for (int i = 0; i < n; i++)
                    arr[i] = 0;
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

            ~Vector()
            {
                delete arr;
            }
            
            Vector & operator=(const Vector &assign)
            {
                delete arr;
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

            void resize(int s, int v = 0)
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
                    delete arr;
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
                    delete arr;
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
    };
}

#endif