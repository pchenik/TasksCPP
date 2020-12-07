#pragma once

#include <algorithm>
#include <utility>

template <typename T>
class Vector {
public:
    Vector() = default;
    ~Vector();
    explicit Vector(size_t size);

    Vector(const Vector& obj);
    Vector(std::initializer_list<T> init_list);
    Vector(Vector&& obj);

    Vector& operator=(const Vector& obj);
    Vector& operator=(Vector&& obj);

    bool operator==(const Vector& obj) const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
    bool Empty() const;
    size_t Size() const;
    size_t Capacity() const;
    const T& Back() const;

    void PushBack(const T& value);
    void PushBack(T&& value);

    void Swap(Vector& obj);
    void PopBack();
    void Erase(T* iterator);

private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
};

template <typename T>
Vector<T>::Vector(size_t size)
        : data(new T[size])
        , size(size)
        , capacity(size)
{
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return data[index];
}

template <typename T>
size_t Vector<T>::Size() const {
    return size;
}

template <typename T>
size_t Vector<T>::Capacity() const {
    return capacity;
}

template <typename T>
void Vector<T>::PushBack(const T& value) {
    if (size >= capacity) {
        auto new_cap = capacity == 0 ? 1 : 2 * capacity;
        auto new_data = new T[new_cap];
        copy(begin(), end(), new_data);
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }
    data[size++] = value;
}

template <typename T>
void Vector<T>::PushBack(T&& value) {
    if (size >= capacity) {
        auto new_cap = capacity == 0 ? 1 : 2 * capacity;
        auto new_data = new T[new_cap];
        std::move(begin(), end(), new_data);
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }
    data[size++] = std::move(value);
}

template <typename T>
void Vector<T>::PopBack() {
    data[--size].~T();
}

template<class T>
void Vector<T>::Swap(Vector<T> &obj) {
    std::swap(data, obj.data);
    std::swap(size, obj.size);
    std::swap(capacity, obj.capacity);
}

template<class T>
void Vector<T>::Erase(T *iterator) {
    size_t pos = iterator - data;
    iterator->~T();
    for (size_t i = pos; i < --size; ++i)
        data[i] = std::move(data[i + 1]);
}


template<typename T>
Vector<T>::Vector(const Vector& obj) : data(new T[obj.Capacity()]),
size(obj.Size()), capacity(obj.Capacity()) {
    std::copy(obj.begin(), obj.end(), begin());
}

template<typename T>
Vector<T>::Vector(Vector&& obj) {
    Swap(obj);
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> init_list) : size(init_list.size()), capacity(init_list.size()) {
    data = new T[size];
    std::move(init_list.begin(), init_list.end(), data);
}


template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& obj) {
    if (obj.data != data) {
        auto new_data = new T[obj.capacity];
        std::copy(obj.begin(), obj.end(), new_data);
        delete [] data;
        data = new_data;
        size = obj.size;
        capacity = obj.capacity;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& obj) {
    //исправлено
    data = nullptr;
    size = capacity = 0;
    Swap(obj);
    return *this;
}

template<class T>
void swap(Vector<T>& lhs, Vector<T>& rhs) {
   auto temp = std::move(lhs);
   lhs = std::move(rhs);
   rhs = std::move(temp);
}

template<typename T>
bool Vector<T>::operator==(const Vector<T>& obj) const{
    for (size_t i = 0; i < size; ++i)
        if (!(data[i] == obj[i]))
            return false;
    return true;
}


template <typename T>
T* Vector<T>::begin() {
    return data;
}

template <typename T>
T* Vector<T>::end() {
    return data + size;
}

template <typename T>
const T* Vector<T>::begin() const {
    return data;
}

template <typename T>
const T* Vector<T>::end() const {
    return data + size;
}

template<typename T>
bool Vector<T>::Empty() const {
    return size == 0;
}

template<typename T>
const T& Vector<T>::Back() const {
    return data[size - 1];
}
