#include "base.h" 

#include "test.h"

template< typename T, typename Alloc = std::allocator<T> >

class myVector : public Base {

    public:

        Alloc al;

        // al.constructor

        myVector():_capacity(0),_size(0){_data=al.allocate(0);}

        myVector(const std::size_t & size, const T & val,

                 Alloc a = Alloc())

        {   _data=al.allocate(size);

            _capacity=_size=size;

            int x;

            for(x=0;x<_size;x++)

                al.construct(_data+x,val);

        }

        template<typename InputIterator>

        myVector(InputIterator begin, InputIterator end,

                     Alloc a = Alloc())

        {   _data=al.allocate(end-begin);

            _capacity=_size=end-begin;

            int x;

            for(x=0;x<_size;x++)

                al.construct(_data+x,*(begin+x));



        }

        myVector(const myVector & other)

        {   _data=al.allocate(other._size);

            _capacity=_size=other._size;

            int x;

            for(x=0;x<_size;x++)

                al.construct(_data+x,other._data[x]);

        }

        ~myVector()

        {   int x;

            for(x=0;x<_size;x++)

                al.destroy(_data+x);

            al.deallocate(_data,_capacity);

        }

         // Copy Operator

        myVector & operator=(const myVector & other)

        {   if(&other==this)

                return *this;

            int x;

            for(x=0;x<_size;x++)

                al.destroy(_data+x);

            al.deallocate(_data,_capacity);

            _data=al.allocate(other._size);

            _capacity=_size=other._size;

            for(x=0;x<_size;x++)

                al.construct(_data+x,other._data[x]);

            return *this;

        }

         // Iterator

        typedef T *         iterator;

        typedef const T *   const_iterator;

        inline iterator begin(){return _data;}

        inline const_iterator begin() const{return _data;}

        inline iterator end(){return _data+_size;}

        inline const_iterator end() const{return _data+_size;}

         // Capacity

        inline std::size_t size(){return _size;}

        void resize(const std::size_t & newSize){resize(newSize,T());}

        void resize(const std::size_t & newSize, const T & val)

        {   int x;

            if(newSize<_size)

            {   for(x=newSize;x<_size;x++)

                    al.destroy(_data+x);

                _size=newSize;



            }

            else if(newSize<=_capacity)

            {   for(x=_size;x<newSize;x++)

                    al.construct(_data+x,val);

                _size=newSize;

            }

            else

            {   int length=_size*2>newSize?_size*2:newSize;



                iterator new_start=al.allocate(length);

                int x;

                for(x=0;x<_size;x++)

                {   al.construct(new_start+x,_data[x]);

                    al.destroy(_data+x);

                }

                al.deallocate(_data,_size);

                for(x=_size;x<newSize;x++)

                    al.construct(new_start+x,val);

                _size=newSize;

                _capacity=length;

                _data=new_start;

            }



        }

        inline std::size_t capacity() const{return _capacity;}

        inline bool empty() const{return !_size;}

        void reserve(const std::size_t & newCapacity)

        {   if(newCapacity>=_capacity)

            {   int newsize=_size>newCapacity?newCapacity:_size;

                iterator new_start=al.allocate(newCapacity);

                int x;

                for(x=0;x<newsize;x++)

                {   al.construct(new_start+x,_data[x]);

                   al.destroy(_data+x);

                }

                for(x=newsize;x<_size;x++)

                al.destroy(_data+x);

                al.deallocate(_data,_capacity);

                _data=new_start;

                _capacity=newCapacity;

                _size=newsize;

            }

        }

         // Element Access

        inline T & operator[](const std::size_t & index){return _data[index];}

        inline const T & operator[](const std::size_t & index) const{return _data[index];}

        inline T & front(){return _data[0];}

        inline const T & front() const{return _data[0];}

        inline T & back(){return _data[_size-1];}

        inline const T & back() const{return _data[_size-1];}

        inline T * data(){return _data;}

        inline const T * data() const{return _data;}

         // Modifiers

        template<typename InputIterator>

        void assign(InputIterator begin, InputIterator end)

        {  

            _size=end-begin;

            int x;

            for(x=0;x<_size;x++)

                al.construct(_data+x,*(begin+x));

        }

        void assign(const std::size_t & newSize, const T & val)

        {   al.deallocate(_data,_capacity);

            _data=al.allocate(size);

            _capacity=_size=size;

            int x;

            for(x=0;x<_size;x++)

                al.construct(_data+x,val);

        }

        void push_back(const T & val)

        {   if(_size<_capacity)

            {   al.construct(_data+_size,val);

                _size++;

            }

            else

            {   int length=_size?2*_size:1;

                iterator new_start=al.allocate(length);

                int x;

                for(x=0;x<_size;x++)

                    al.construct(new_start+x,_data[x]);

                al.construct(new_start+_size,val);

                _size++;

                al.deallocate(_data,_capacity);

                _data=new_start;

                _capacity=length;

            }

                



        }

        void pop_back()

        {   --_size;

            al.destroy(_data+_size);

        }

        void clear()

        {   int x;

            for(x=0;x<_size;x++)

                al.destroy(_data+x);

            _size=0;

        }

     private:

        T * _data;

        std::size_t _size, _capacity;

};

