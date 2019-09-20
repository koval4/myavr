#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

#include "types.h"

namespace myavr::io {

inline void set_pins_output_low(myavr::reg8_t port, uint8_t pins) noexcept {
    port &= ~pins;
}

inline void set_pins_output_high(myavr::reg8_t port, uint8_t pins) noexcept {
    port |= pins;
}

inline void set_pins_as_input(myavr::reg8_t portdir, uint8_t pins) noexcept {
    portdir &= ~pins;
}

inline void set_pins_as_output(myavr::reg8_t portdir, uint8_t pins) noexcept {
    portdir |= pins;
}

inline void set_pin_output_low(myavr::reg8_t port, int pin) noexcept {
    set_pins_output_low(port, 1 << pin);
}

inline void set_pin_output_high(myavr::reg8_t port, int pin) noexcept {
    set_pins_output_high(port, 1 << pin);
}

inline void set_pin_as_input(myavr::reg8_t portdir, int pin) noexcept {
    set_pins_as_input(portdir, 1 << pin);
}

inline void set_pin_as_output(myavr::reg8_t portdir, int pin) noexcept {
    set_pins_as_output(portdir, 1 << pin);
}

struct Port {
    Port(reg8_t ddr_reg, reg8_t port_reg)
        : ddr_reg{ddr_reg}
        , port_reg{port_reg} {}

    void set_as_input(uint8_t pins) const noexcept {
        set_pins_as_input(ddr_reg, pins);
    }

    void set_as_output(uint8_t pins) const noexcept {
        set_pins_as_output(ddr_reg, pins);
    }

    void set_output_low(uint8_t pins) const noexcept {
        set_pins_output_low(port_reg, pins);
    }

    void set_output_high(uint8_t pins) const noexcept {
        set_pins_output_high(port_reg, pins);
    }

    reg8_t ddr_reg;
    reg8_t port_reg;
};

struct Pin {
    Pin(const Port& port, const int pin_num)
        : port{port}
        , pin_num{pin_num} {}

    void set_as_input() const noexcept {
        port.set_as_input(1 << pin_num);
    }

    void set_as_output() const noexcept {
        port.set_as_output(1 << pin_num);
    }

    void set_output_high() const noexcept {
        port.set_output_high(1 << pin_num);
    }

    void set_output_low() const noexcept {
        port.set_output_low(1 << pin_num);
    }

    const Port& port;
    const int pin_num;
};

} // namespace myavr::io

#endif // IO_H_INCLUDED
