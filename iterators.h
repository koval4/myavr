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

}

#endif // ITERATORS_H_INCLUDED
