/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#ifndef __BARE_HEADER_SIFIVE_NB2TIMER__H
#define __BARE_HEADER_SIFIVE_NB2TIMER__H

#include "bare_header/device.h"

#include <regex>

class sifive_nb2timer : public Device{
    public:
        sifive_nb2timer(std::ostream &os, const fdt &dtb)
            : Device(os, dtb, "sifive,nb2timer") {}
        void emit_defines() {
            dtb.match(std::regex(compat_string), [&](node n){
                
                emit_comment(n);

                emit_base(n);
                emit_size(n);

                os << std::endl;
            });
        }

        void emit_offsets() {
            if(dtb.match(std::regex(compat_string), [](const node n) {}) != 0){
                emit_compat();

                emit_offset("TIMER_N_LOAD_COUNT", 0x00);
                emit_offset("TIMER_N_CURRENT_VALUE", 0x04);
                emit_offset("TIMER_N_CONTROL_REG", 0x08);
                emit_offset("TIMER_N_EOI", 0x0C);
                emit_offset("TIMER_N_INT_STATUS", 0x10);
                emit_offset("TIMERS_INT_STATUS", 0xa0);
                emit_offset("TIMERS_EOI", 0xa4);
                emit_offset("TIMERS_RAW_INT_STATUS", 0xa8);
                emit_offset("TIMERS_COMP_VERSION", 0xac);
                emit_offset("TIMER_N_LOAD_COUNT2", 0xb0);
                emit_offset("TIMER_N_PROT_LEVEL", 0xd0);
            }
        }
};

#endif