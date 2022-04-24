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
T* UniquePtr<T>::get()
{
    return _p;
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

template <typename T>
T UniquePtr<T>::operator*()
{
    std::cout << "operator* output" << *((*this).get()) << std::endl;
    return *((*this).get());
}
// testing
template <typename T>
const T& UniquePtr<T>::operator[](const T& ind) const
{
    if (ind < this.size())
        return this[ind];
    throw std::out_of_range { "index too large" };
}
template <typename T>
T& UniquePtr<T>::operator[](const T& ind)
{
    std::cout << "operator[] output" << *((*this).get()) << std::endl;
    return const_cast<T&>(std::as_const(*this)[ind]);
}
