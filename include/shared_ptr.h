#ifndef SHARED_PTR
#define SHARED_PTR
#include <iostream>
template <typename T>
class SharedPtr {
public:
    SharedPtr(T*);
    SharedPtr();
    ~SharedPtr();
    SharedPtr(SharedPtr<T>&);
    SharedPtr<T>& operator=(SharedPtr<T>&);
    int use_count();
    T* get();
    T& operator*();

private:
    T* _p;
    int count;
};
template <typename T>
T* make_shared(T N);
#include "shared_ptr.hpp"
#endif // SHARED_PTR