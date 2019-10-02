#ifndef RANGE_ACCESS_H_INCLUDED
#define RANGE_ACCESS_H_INCLUDED

#include "types.h"
#include "iterators.h"

namespace myavr {

template <typename Rng>
inline constexpr auto begin(Rng& rng) noexcept -> decltype(rng.begin()) {
    return rng.begin();
}

template <typename Rng>
inline constexpr auto begin(const Rng& rng) noexcept -> decltype(rng.begin()) {
    return rng.begin();
}

template <typename Rng>
inline constexpr auto end(Rng& rng) noexcept -> decltype(rng.end()) {
    return rng.end();
}

template <typename Rng>
inline constexpr auto end(const Rng& rng) noexcept -> decltype(rng.end()) {
    return rng.end();
}

template <typename Rng>
inline constexpr auto cbegin(const Rng& rng) noexcept -> decltype(myavr::begin(rng)) {
    return myavr::begin(rng);
}

template <typename Rng>
inline constexpr auto cend(const Rng& rng) noexcept -> decltype(myavr::end(rng)) {
    return myavr::end(rng);
}

template <typename Rng>
inline constexpr auto rbegin(Rng& rng) -> decltype(rng.rbegin()) {
    return rng.rbegin();
}

template <typename Rng>
inline constexpr auto rbegin(const Rng& rng) -> decltype(rng.rbegin()) {
    return rng.rbegin();
}

template <typename Rng>
inline constexpr auto rend(Rng& rng) -> decltype(rng.rend()) {
    return rng.rend();
}

template <typename Rng>
inline constexpr auto rend(const Rng& rng) -> decltype(rng.rend()) {
    return rng.rend();
}

template <typename Rng>
inline constexpr auto crbegin(const Rng& rng) -> decltype(myavr::rbegin(rng)) {
    return myavr::rbegin(rng);
}

template <typename Rng>
inline constexpr auto crend(const Rng& rng) -> decltype(myavr::rend(rng)) {
    return myavr::rend(rng);
}

template <typename Rng>
inline constexpr auto data(Rng& rng) noexcept -> decltype(rng.data()) {
    return rng.data();
}

template <typename Rng>
inline constexpr auto data(const Rng& rng) noexcept -> decltype(rng.data()) {
    return rng.data();
}

template <typename Rng>
inline constexpr auto size(const Rng& rng) noexcept -> decltype(rng.size()) {
    return rng.size();
}

template <typename Rng>
inline constexpr auto ssize(const Rng& rng) noexcept -> decltype(rng.ssize()) {
    return rng.ssize();
}

template <typename Rng>
inline constexpr bool empty(const Rng& rng) noexcept {
    return rng.empty();
}

template <typename T, size_t N>
inline constexpr T* begin(T (&arr)[N]) noexcept {
    return arr;
}

template <typename T, size_t N>
inline constexpr T* end(T (&arr)[N]) noexcept {
    return arr + N;
}

template <typename T, size_t N>
inline constexpr T* rbegin(T (&arr)[N]) noexcept {
    return ReverseIterator<T*>{ arr + N };
}

template <typename T, size_t N>
inline constexpr T* rend(T (&arr)[N]) noexcept {
    return ReverseIterator<T*>{ arr };
}

template <typename T, size_t N>
inline constexpr T* data(T (&arr)[N]) noexcept {
    return arr;
}

template <typename T, size_t N>
inline constexpr size_t size(T (&)[N]) noexcept {
    return N;
}

template <typename T, size_t N>
inline constexpr ptrdiff_t ssize(T (&)[N]) noexcept {
    return N;
}

template <typename T, size_t N>
inline constexpr bool empty(T (&)[N]) noexcept {
    return false;
}

} // namespace myavr

#endif // RANGE_ACCESS_H_INCLUDED
