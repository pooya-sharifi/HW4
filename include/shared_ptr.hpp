template <typename T>
SharedPtr<T>::SharedPtr(T* pnt_in)
{
    _p = pnt_in;
    count = new int { 1 };
    std::cout << "!!!!!!" << *count << std::endl;
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
    count = new int { 0 };
    std::cout << "!!!!!!" << *count << std::endl;
}
template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if (count != nullptr) {
        if (*count != 0) {
            _p = nullptr;
            delete _p;
            _p = nullptr;
        } else {
            delete _p;
            _p = nullptr;
        }
    }
    if (count != nullptr) {
        *count = *count - 1;
        std::cout << "check to see what count is in its dying days" << *count << std::endl;
        if (*count != 0) {
            count = nullptr;
            delete count;
        } else {
            // count = nullptr;
            delete count;
            // count = new int { 0 };
            count = nullptr;
        }
        // motmaen nistam count ro
    }
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
    std::cout << "!!!!!!" << *shared_ptr_right.count << std::endl;
    *(shared_ptr_right.count) = *(shared_ptr_right.count) + 1;
    this->count = shared_ptr_right.count;
    std::cout << "!!!!!!" << *shared_ptr_right.count << "address::" << shared_ptr_right.count << "    " << count << std::endl;
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

    *(pnt_right) = *(pnt_right.count)++;
    this->count = pnt_right.count;
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

    if (count == nullptr) {
        std::cout << "%%%%%%%%%%%%%%%%%%" << std::endl;
        return 0;
    }
    int count_ret = *count;
    return count_ret;
}
template <typename T>
T& SharedPtr<T>::operator*()
{
    std::cout << "operator* output" << std::endl;
    // in kar nemikone felan cho operator << hanooz nadarim
    // std::cout << *((*this).get()) << std::endl;
    return *((*this).get());
}