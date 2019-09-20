#ifndef TYPE_TRAITS_H_INCLUDED
#define TYPE_TRAITS_H_INCLUDED

namespace myavr {

template <typename T, T val>
struct Constant {
    static constexpr T value = val;

    using value_type = T;
    using type       = Constant<T, val>;

    constexpr operator value_type () const noexcept {
        return value;
    }

    constexpr value_type operator () () const noexcept {
        return value;
    }
};

template <typename T, T val>
constexpr T Constant<T, val>::value;

template <bool val>
using BoolConstant = Constant<bool, val>;

using true_type  = BoolConstant<true>;
using false_type = BoolConstant<false>;

template <typename...>
using Void_t = void;

template <bool, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
    using type = T;
};

template <bool cond, typename T = void>
using enable_if_t = typename enable_if<cond, T>::type;

} // namespace myavr

#endif // TYPE_TRAITS_H_INCLUDED
