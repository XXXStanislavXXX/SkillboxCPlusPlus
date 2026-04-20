#pragma once
#include "toy.h"

class shared_ptr_toy {
public:
    shared_ptr_toy() noexcept : ptr_(nullptr), count_(nullptr) {}

    explicit shared_ptr_toy(const std::string& name)
        : ptr_(new toy(name)), count_(new int(1)) {}

    shared_ptr_toy(const shared_ptr_toy& other) noexcept
        : ptr_(other.ptr_), count_(other.count_) {
        if (count_) { ++(*count_); }
    }

    shared_ptr_toy(shared_ptr_toy&& other) noexcept
        : ptr_(other.ptr_), count_(other.count_) {
        other.ptr_ = nullptr;
        other.count_ = nullptr;
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other) noexcept {
        if (this == &other || ptr_ == other.ptr_) return *this;
        release_current();
        ptr_ = other.ptr_;
        count_ = other.count_;
        if (count_) { ++(*count_); }
        return *this;
    }

    shared_ptr_toy& operator=(shared_ptr_toy&& other) noexcept {
        if (this == &other) return *this;
        release_current();
        ptr_ = other.ptr_;
        count_ = other.count_;
        other.ptr_ = nullptr;
        other.count_ = nullptr;
        return *this;
    }

    ~shared_ptr_toy() {
        release_current();
    }

    void reset() noexcept {
        release_current();
        ptr_ = nullptr;
        count_ = nullptr;
    }

    toy* get() const noexcept { return ptr_; }

    int use_count() const noexcept { return count_ ? *count_*1 : 0; }

    std::string getToyName() const {
        return ptr_ ? ptr_->getName() : "Nothing";
    }

    toy& operator*() const { return *ptr_; }
    toy* operator->() const { return ptr_; }

private:
    toy* ptr_;
    int* count_;

    void release_current() noexcept {
        if (count_) {
            --(*count_);
            if (*count_ == 0) {
                delete ptr_;
                delete count_;
            }
        }
    }
};

shared_ptr_toy make_shared_toy(const std::string& name);
