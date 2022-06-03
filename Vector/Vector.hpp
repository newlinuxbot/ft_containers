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
            int size;
            int index;
            unsigned int maxsize;
        public:
            typedef T* iterator;

            Vector()
            {
                arr = new T[1];
                size = 1;
                index = 0;
                maxsize = 1073741823;
            }

            Vector(T n)
            {
                arr = new T[n];
                size = 1;
                index = 0;
                maxsize = 1073741823;
            }

            Vector(const Vector<T> &copy)
            {
                arr = new T[copy.getSize()];
                for (int i = 0; i < copy.getSize() ; i++)
                    arr[i] = copy.getArray()[i];
                size = copy.getSize();
                index = getIndex();
            }

            ~Vector()
            {
                delete arr;
            }
            
            Vector & operator=(const Vector &assign)
            {
                delete arr;
                arr = new T[assign.getSize()];
                for (int i = 0; i < assign.getSize() ; i++)
                    arr[i] = assign.getArray()[i];
                return *this;
            }
            
            int getSize() const
            {
                return size;
            }
            T* getArray() const
            {
                return arr;
            }
            int getIndex() const
            {
                return index;
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
                return arr+size;
            }

            
    };
}

#endif