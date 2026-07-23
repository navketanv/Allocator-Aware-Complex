#pragma once
#include <cstddef>
#include <limits>
#include <stdexcept>

template<typename T>
class Allocator {
public:
    Allocator() = default;
    [[nodiscard]] T* allocate(std::size_t count) const;
    void deallocate(T* ptr, std::size_t count) const noexcept;
    template<typename... Args>
    void construct(T* ptr, Args&&... args) const;
    void destroy(T* ptr) const noexcept;
    std::size_t max_size() const noexcept;
};

template<typename T>
T* Allocator<T>::allocate(std::size_t count) const {
    if (count == 0) {
        return nullptr;
    }

    if (count > Allocator<T>::max_size()) {
        throw std::runtime_error("Requested Memory Block Size Can't Be Allocated");
    }
    return static_cast<T*>(::operator new(count * sizeof(T)));
}

template<typename T>
std::size_t Allocator<T>::max_size() const noexcept {
    return std::numeric_limits<T>::max() / sizeof(T);
}

template<typename T>
void Allocator<T>::deallocate(T* ptr, std::size_t count) const noexcept {
    if (ptr != nullptr) {
        ::operator delete(ptr, (sizeof(T) * count));
        ptr = nullptr;
    }
}

template<typename T>
template<typename... Args>
void Allocator<T>::construct(T* ptr, Args&&... args) const {
    if (ptr != nullptr) {
        ::new (static_cast<void*>(ptr)) T(std::forward<Args>(args)...);
    }
}

template<typename T>
void Allocator<T>::destroy(T* ptr) const noexcept {
    if (ptr != nullptr) {
        ptr->~T();
    }
}
