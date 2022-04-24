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
    T* get();
    ~UniquePtr();
    // UniquePtr(const UniquePtr& ptr);
    T operator*();
    // idk what this is
    const T& operator[](const T& ind) const;
    T& operator[](const T& ind);

private:
    T* _p;
};
template <typename T>
T* make_unique(T& N);
#include "unique_ptr.hpp"
#endif // UNIQUE_PTR