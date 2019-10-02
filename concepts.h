#ifndef CONCEPTS_H_INCLUDED
#define CONCEPTS_H_INCLUDED

#include "type_traits.h"

namespace myavr {

namespace detail {
template <typename T, typename U>
concept bool SameHelper = myavr::is_same_v<T, U>;
}

template <typename T, typename U>
concept bool SameAs = detail::SameHelper<T, U> && detail::SameHelper<U, T>;

}

#endif // CONCEPTS_H_INCLUDED
