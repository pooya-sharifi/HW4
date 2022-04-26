template <typename T>
SharedPtr<T>::SharedPtr(T* pnt_in)
{
    _p = pnt_in;
}