#pragma once

#include <iostream>
#include <array>
#include <algorithm>
#include <cstring>

void message(std::ostream& os, const char* s) {
    os << s;
}

template<typename T, typename... Args>
void message(std::ostream& os, const char* s, const T& value, const Args&... args) {

    if (os.tellp() == 0) {
        if (sizeof...(args) + 1 != std::count(s, s + strlen(s), '%'))
            throw std::invalid_argument("given number of parameters and % doesn't match up");
    }

    while (*s) {
        if (*s == '%') {
            os << value;
            return message(os, ++s, args...);
        }
        os << *s++;
    }
    throw std::invalid_argument("given number of parameters and % doesn't match up");
}

template<typename T, size_t N>
std::array<T, N> cat(std::array<T, N> arr) {
    return arr;
}

template<typename T, size_t N, typename... Args>
auto cat(std::array<T, N> arr, const Args&... args) {
    std::array<T, N * (sizeof...(args)) + N> res;
    std::array<T, N * sizeof...(args)> rest = std::move(cat(args...));
    std::move(arr.begin(), arr.end(), res.begin());
    std::move(rest.begin(), rest.end(), res.begin() + N);
    return res;
}

template <class T, int N, int M>
struct Tie {

    Tie() {
        for (size_t i = 0; i < M; ++i)
            data[i] = nullptr;
    }

    void operator=(std::array<T, N>& value) {
        data[0] = &value;
    }

    void operator=(const std::array<T,N*M>& rhs) {
        for (size_t i = 0; i < rhs.size(); ++i)
            (*data[i / N])[i % N] = rhs[i];
    }

    std::array<T, N>*& operator[](size_t index) {
        return data[index];
    }

    std::array<std::array<T, N>*, M> data;
};

template<typename T, size_t N>
std::array<T, N>& my_tie(std::array<T, N>& value) {
    return value;
}

template<typename T, size_t N, typename... Args>
auto my_tie(std::array<T, N>& value, Args&... args) {
    Tie<T, N, sizeof...(args)> rest;
    Tie<T, N, sizeof...(args) + 1> res;
    rest = my_tie(args...);
    res[0] = &value;
    for (size_t i = 1; i <= sizeof...(args); ++i)
        res[i] = rest[i - 1];
    return res;
}
