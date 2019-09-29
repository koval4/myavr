#ifndef ITERATORS_H_INCLUDED
#define ITERATORS_H_INCLUDED

#include "type_traits.h"
#include "types.h"

namespace myavr {

template <typename It, typename = Void_t<>>
struct IteratorTraitsImpl {};

template <typename It>
struct IteratorTraitsImpl<It, Void_t<typename It::iterator_category,
                                     typename It::value_type,
                                     typename It::difference_type,
                                     typename It::pointer,
                                     typename It::reference>> {
    using iterator_category = typename It::iterator_category;
    using value_type        = typename It::value_type;
    using difference_type   = typename It::difference_type;
    using pointer           = typename It::pointer;
    using reference         = typename It::reference;
};

template <typename It>
struct IteratorTraits : public IteratorTraitsImpl<It> {};

struct InputIteratorTag { };

struct OutputIteratorTag { };

struct ForwardIteratorTag : public InputIteratorTag { };

struct BidirectionalIteratorTag : public ForwardIteratorTag { };

struct RandomAccessIteratorTag : public BidirectionalIteratorTag { };

template <typename Cat,
          typename T,
          typename Dist = ptrdiff_t,
          typename Ptr = T*,
          typename Ref = T&>
struct Iterator {
    using iterator_category = Cat;
    using value_type = T;
    using difference_type = Dist;
    using pointer = Ptr;
    using reference = Ref;
};

template <typename It>
class ReverseIterator : public Iterator<typename IteratorTraits<It>::iterator_category,
                                        typename IteratorTraits<It>::value_type,
                                        typename IteratorTraits<It>::difference_type,
                                        typename IteratorTraits<It>::pointer,
                                        typename IteratorTraits<It>::reference> {
public:
    using iterator_type   = It;
    using difference_type = typename IteratorTraits<It>::difference_type;
    using pointer         = typename IteratorTraits<It>::pointer;
    using reference       = typename IteratorTraits<It>::reference;

    constexpr ReverseIterator() noexcept
        : curr{} {};

    explicit constexpr ReverseIterator(It curr) noexcept
        : curr{curr} {}

    constexpr ReverseIterator(const ReverseIterator& other) noexcept
        : curr{other.curr} {}

    constexpr ReverseIterator& operator = (const ReverseIterator& other) noexcept = default;

    constexpr iterator_type base() const noexcept {
        return curr;
    }

    constexpr reference operator * () const noexcept {
        It tmp = curr;
        return *--tmp;
    }

    constexpr pointer operator -> () const noexcept {
        It tmp = curr;
        --tmp;
        return it_to_ptr(tmp);
    }

    constexpr ReverseIterator& operator ++ () noexcept {
        --curr;
        return *this;
    }

    constexpr ReverseIterator& operator ++ (int) noexcept {
        ReverseIterator tmp = *this;
        --curr;
        return tmp;
    }

    constexpr ReverseIterator& operator -- () noexcept {
        ++curr;
        return *this;
    }

    constexpr ReverseIterator& operator -- (int) noexcept {
        ReverseIterator tmp = *this;
        ++curr;
        return tmp;
    }

    constexpr ReverseIterator operator + (difference_type n) const noexcept {
        return ReverseIterator{ curr - n };
    }

    constexpr ReverseIterator& operator += (difference_type n) const noexcept {
        curr -= n;
        return *this;
    }

    constexpr ReverseIterator operator - (difference_type n) const noexcept {
        return ReverseIterator{ curr + n };
    }

    constexpr ReverseIterator& operator -= (difference_type n) const noexcept {
        curr += n;
        return *this;
    }

    constexpr reference operator [] (difference_type n) const noexcept {
        return *(*this + n);
    }

private:
    template <typename T>
    static constexpr T* iter_to_ptr(T* it) {
        return it;
    }

    template <typename T>
    static constexpr T* iter_to_ptr(T it) {
        return it.operator->();
    }

    It curr;
};

template <typename It>
inline constexpr bool operator == (const ReverseIterator<It>& lhs, const ReverseIterator<It>& rhs) noexcept {
    return lhs.base() == rhs.base();
}

template <typename It>
inline constexpr bool operator != (const ReverseIterator<It>& lhs, const ReverseIterator<It>& rhs) noexcept {
    return !(lhs == rhs);
}

template <typename It>
inline constexpr bool operator < (const ReverseIterator<It>& lhs, const ReverseIterator<It>& rhs) noexcept {
    return lhs.base() < rhs.base();
}

template <typename It>
inline constexpr bool operator > (const ReverseIterator<It>& lhs, const ReverseIterator<It>& rhs) noexcept {
    return rhs < lhs;
}

template <typename It>
inline constexpr bool operator <= (const ReverseIterator<It>& lhs, const ReverseIterator<It>& rhs) noexcept {
    return !(lhs > rhs);
}

template <typename It>
inline constexpr bool operator >= (const ReverseIterator<It>& lhs, const ReverseIterator<It>& rhs) noexcept {
    return !(lhs < rhs);
}

template <typename ItLhs, typename ItRhs>
inline constexpr bool operator == (const ReverseIterator<ItLhs>& lhs,
                                   const ReverseIterator<ItRhs>& rhs) noexcept {
    return lhs.base() == rhs.base();
}

template <typename ItLhs, typename ItRhs>
inline constexpr bool operator != (const ReverseIterator<ItLhs>& lhs,
                                   const ReverseIterator<ItRhs>& rhs) noexcept {
    return !(lhs == rhs);
}

template <typename ItLhs, typename ItRhs>
inline constexpr bool operator < (const ReverseIterator<ItLhs>& lhs,
                                  const ReverseIterator<ItRhs>& rhs) noexcept {
    return lhs.base() < rhs.base();
}

template <typename ItLhs, typename ItRhs>
inline constexpr bool operator > (const ReverseIterator<ItLhs>& lhs,
                                  const ReverseIterator<ItRhs>& rhs) noexcept {
    return rhs < lhs;
}

template <typename ItLhs, typename ItRhs>
inline constexpr bool operator <= (const ReverseIterator<ItLhs>& lhs,
                                   const ReverseIterator<ItRhs>& rhs) noexcept {
    return !(lhs > rhs);
}

template <typename ItLhs, typename ItRhs>
inline constexpr bool operator >= (const ReverseIterator<ItLhs>& lhs,
                                   const ReverseIterator<ItRhs>& rhs) noexcept {
    return !(lhs < rhs);
}

template <typename ItLhs, typename ItRhs>
inline constexpr auto operator - (const ReverseIterator<ItLhs>& lhs,
                                  const ReverseIterator<ItRhs>& rhs) noexcept ->
    decltype (rhs.base() - lhs.base()) {
    return rhs.base() - lhs.base();
}

template <typename It>
inline constexpr ReverseIterator<It> operator + (typename ReverseIterator<It>::difference_type n,
                                                 const ReverseIterator<It>& it) noexcept {
    return ReverseIterator<It>{ it.base() - n };
}

template <typename It>
inline constexpr ReverseIterator<It> make_reverse_iterator(It it) noexcept {
    return ReverseIterator<It>{ it };
}

}

#endif // ITERATORS_H_INCLUDED
