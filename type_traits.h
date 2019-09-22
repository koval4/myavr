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

template <bool cond, typename T, typename U>
struct conditional {
    using type = T;
};

template <typename T, typename U>
struct conditional<false, T, U> {
    using type = T;
};

template <bool cond, typename T, typename U>
using conditional_t = typename conditional<cond, T, U>::type;

namespace detail {
template <typename AlwaysVoid, template <typename...> typename Op, typename... Args>
struct detector {
    using value = false_type;
};

template <template <typename...> typename Op, typename... Args>
struct detector<Void_t<Op<Args...>>, Op, Args...> {
    using value = true_type;
};
}

template <template <typename...> typename Op, typename... Args>
using is_detected = typename detail::detector<void, Op, Args...>::value;

template <template <typename...> typename Op, typename... Args>
inline constexpr bool is_detected_v = is_detected<Op, Args...>::value;

template <typename, typename>
struct is_same : public false_type {};

template <typename T>
struct is_same<T, T> : public true_type {};

template <typename T, typename U>
inline constexpr bool is_same_v = is_same<T, U>::value;

} // namespace myavr

#endif // TYPE_TRAITS_H_INCLUDED
