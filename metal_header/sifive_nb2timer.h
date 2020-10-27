/* Copyright 2020 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#ifndef __METAL_HEADER_SIFIVE_NB2TIMER_H
#define __METAL_HEADER_SIFIVE_NB2TIMER_H

#include <device.h>
#include <regex>

class sifive_nb2timer : public Device{
    public:
        sifive_nb2timer(std::ostream &os, const fdt &dtb);
        void create_defines();
        void include_headers();
};

#endif