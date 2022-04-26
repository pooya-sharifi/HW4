template <typename T>
SharedPtr<T>::SharedPtr(T* pnt_in)
{
    _p = pnt_in;
    count = 1;
}
template <typename T>
T* make_shared(T N)
{
    return new T { N };
}
template <typename T>
SharedPtr<T>::SharedPtr()
{
    _p = nullptr;
    count = 0;
}
template <typename T>
SharedPtr<T>::~SharedPtr()
{
    _p = nullptr;
    delete _p;
    _p = nullptr;
    // motmaen nistam count ro
    count = 0;
    std::cout << "a shared pointer was destructed" << std::endl;
}
template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& shared_ptr_right)
{
    std::cout << "sharedptr " << typeid(T).name() << " Copy Constructor" << std::endl;
    // delete _p;
    // _p = (shared_ptr_right._p);
    std::cout << shared_ptr_right._p << std::endl;
    std::cout << _p << std::endl;

    _p = shared_ptr_right._p;
    // *_p = *(shared_ptr_right._p);
    std::cout << shared_ptr_right._p << std::endl;
    std::cout << _p << std::endl;
    this->count = 0;
    this->count = this->count + 2;
    shared_ptr_right.count++;
    std::cout << "&&&&&&" << std::endl;
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>& pnt_right)
{
    if (this == &pnt_right) {
        return *this;
    }
    delete _p;
    // new nabayad mikardim?
    _p = pnt_right._p;
    this->count = this->count + 2;
    pnt_right++;
    return *this;
}

template <typename T>
T* SharedPtr<T>::get()
{
    return _p;
}
template <typename T>
int SharedPtr<T>::use_count()
{
    return count;
}
template <typename T>
T& SharedPtr<T>::operator*()
{
    std::cout << "operator* output" << std::endl;
    // in kar nemikone felan cho operator << hanooz nadarim
    // std::cout << *((*this).get()) << std::endl;
    return *((*this).get());
}