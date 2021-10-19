#pragma once

#include <cstddef>

template <typename T>
class uniqe_ptr
{
public:
    uniqe_ptr() : ptr_(nullptr);

    explicit uniqe_ptr(T* ptr) : ptr_(ptr);

    // copy constructor
    uniqe_ptr(const uniqe_ptr& other) = delete;  

    // move constructor
    uniqe_ptr(uniqe_ptr&& other) noexcept  {
        ptr_ = other.release();
    } 

    ~uniqe_ptr() {
        if(ptr_) {
            delete ptr;
        }
    };
    // copy assigment
    uniqe_ptr& operator=(const uniqe_ptr &) = delete; 

    // move assigment
    uniqe_ptr& operator=(uniqe_ptr &&other) noexcept {
        if(this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    uniqe_ptr<T> operator*() const noexcept { return *ptr; };
    T *operator->() const noexcept { return ptr; };

    T* get() const noexcept {
        return ptr_;
    }

    T* release() {
        T* tempPtr = ptr_;
        ptr_ = nullptr;
        return temp;
    };
    T* reset(T* newPtr) noexcept {
        delete ptr_;
        ptr_ = newPtr;
    }

private:
    T* ptr_;
};