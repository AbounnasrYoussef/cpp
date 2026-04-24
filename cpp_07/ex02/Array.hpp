#ifndef ARRAY_HPP
#define ARRAY_HPP





template <typename T> class Array{
    private:
        T* ptr;
        unsigned int size;

    public:
        Array() : ptr(NULL) , size(0){};
        Array(unsigned int n) : n(size)
        {
            ptr = new T[n]();
        }
        ~Array() {
            if (ptr)
                delete[] ptr;
        };
};



#endif
