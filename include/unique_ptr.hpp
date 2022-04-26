template <typename T>
UniquePtr<T>::UniquePtr()
{
    _p = nullptr;
}
template <typename T>
UniquePtr<T>::UniquePtr(T* stuff)
{
    _p = stuff;
}
template <typename T>
T* make_unique(T N)
{
    return new T { N };
}

template <typename T>
UniquePtr<T>::~UniquePtr()
{
    delete _p;
    _p = nullptr;
}
// template <typename T>
// UniquePtr<T>::UniquePtr(const UniquePtr& ptr)
// {

// }

// template <typename T>
// UniquePtr<T>& UniquePtr<T>::operator=(const UniquePtr<T>& pnt)
// {
//     // if (this == &pnt)
//     //     return *this;
//     // delete this;
//     // _p = pnt._p;
//     // return *this;
//     throw std::logic_error();
// }
template <typename T>
T* UniquePtr<T>::get()
{
    return _p;
}

template <typename T>
T& UniquePtr<T>::operator*()
{
    std::cout << "operator* output" << std::endl;
    // in kar nemikone felan cho operator << hanooz nadarim
    // std::cout << *((*this).get()) << std::endl;
    return *((*this).get());
}
// testing
// template <typename T>
// const T& UniquePtr<T>::operator[](const T& ind) const
// {
//     if (ind < this.size())
//         return this[ind];
//     throw std::out_of_range { "index too large" };
// }
// template <typename T>
// T& UniquePtr<T>::operator[](const T& ind)
// {
//     std::cout << "operator[] output" << *((*this).get()) << std::endl;
//     return const_cast<T&>(std::as_const(*this)[ind]);
// }
template <typename T>
T* UniquePtr<T>::operator->()
{
    return _p;
}
template <typename T>
T* UniquePtr<T>::reset()
{
    delete _p;
    _p = nullptr;
    return _p;
}
template <typename T>
T* UniquePtr<T>::reset(T* pnt_given)
{
    delete _p;
    _p = pnt_given;
    return _p;
}
template <typename T>
T* UniquePtr<T>::release()
{
    T* pnt_hold { _p };
    _p = nullptr;
    return pnt_hold;
}
