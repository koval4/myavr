#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

#include <stdint.h>

namespace myavr {

using reg8_t    = volatile uint8_t&;
using reg16_t   = volatile uint16_t&;
using size_t    = unsigned int;
using ptrdiff_t = int;

} // namespace myavr

#endif // TYPES_H_INCLUDED
