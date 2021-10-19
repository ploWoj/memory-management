#pragma once

#include <cstddef>

template <typename T>
class uniqe_ptr
{
public:
    uniqe_ptr() : ptr_(nullptr);
    explicit uniqe_ptr(T* ptr) : ptr_(ptr);

    uniqe_ptr(const uniqe_ptr& other) = delete;     // copy constructor
    uniqe_ptr(uniqe_ptr&& other) noexcept : uniqe_ptr(other.ptr_) {} // move constructor
    ~uniqe_ptr() {
        delete ptr;
    };

    uniqe_ptr &operator=(const uniqe_ptr &);          // copy assigment
    uniqe_ptr &operator=(uniqe_ptr &&other) noexcept; // move assigment

    uniqe_ptr<T> operator*() const noexcept;
    T *operator->() const noexcept;

    T *get();
    T *release() {
        T* tempPtr = ptr_;
        ptr_ = nullptr;
        return temp;
    };
    T *reset();

private:
    T* ptr_;
};