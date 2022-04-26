#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#include <iostream>
template <typename T>
class UniquePtr {
public:
    // moshkel dare
    // UniquePtr() = default;
    UniquePtr();
    UniquePtr(T* stuff);
    // not tested
    ~UniquePtr();
    // UniquePtr(const UniquePtr& ptr);
    // not tested
    UniquePtr(const UniquePtr& v) = delete;
    UniquePtr<T>& operator=(const UniquePtr<T>& v) = delete;
    T* get();
    T& operator*();
    // not tested
    T* operator->();
    T* reset();
    T* reset(T* pnt_given);
    T* release();
    // idk what this is
    // const T& operator[](const T& ind) const;
    // T& operator[](const T& ind);

private:
    T* _p;
};
template <typename T>
T* make_unique(T N);
#include "unique_ptr.hpp"
#endif // UNIQUE_PTR