#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "type_traits.h"

namespace myavr {

template <typename T>
constexpr remove_reference_t<T>&& move(T&& value) noexcept {
    return static_cast<remove_reference_t<T>&&>(value);
}

} // namespace myavr

#endif // UTILITY_H_INCLUDED
