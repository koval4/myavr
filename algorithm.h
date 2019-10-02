#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED

#include "types.h"
#include "utility.h"

namespace myavr {

template <typename T>
constexpr void swap(T& lhs, T& rhs) noexcept {
    T tmp = move(lhs);
    lhs = move(rhs);
    rhs = move(tmp);
}

template <typename FwdIt1, typename FwdIt2>
constexpr void iter_swap(FwdIt1 lhs, FwdIt2 rhs) noexcept {
    using myavr::swap;
    swap(*lhs, *rhs);
}

} // namespace myavr

#endif // ALGORITHM_H_INCLUDED
