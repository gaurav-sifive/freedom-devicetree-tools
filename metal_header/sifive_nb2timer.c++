/* Copyright 2020 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <sifive_nb2timer.h>

sifive_nb2timer::sifive_nb2timer(std :: ostream &os, const fdt &dtb) 
    : Device(os, dtb, "sifive,nb2timer"){}

void sifive_nb2timer::create_defines(){
    uint32_t count = 0, index = 0;

    dtb.match(std::regex(compat_string), [&](node n) {
        uint32_t val = 0;
        if(n.field_exists("sifive,num-timers")){
            val = n.get_fields<uint32_t>("sifive,num-timers")[0];
        }
        emit_def("NUM_TIMER_COUNT", std::to_string(val));
    });
}

void sifive_nb2timer::include_headers() {
  dtb.match(std::regex(compat_string),
            [&](node n) { emit_include(compat_string); });
}
