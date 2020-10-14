#ifndef __METAL_HEADER_MYDRIVER_MEM0_H
#define __METAL_HEADER_MYDRIVER_MEM0_H
#include <device.h>
#include <regex>
class mydriver_mem0 : public Device {
    public:
        mydriver_mem0(std::ostream &os, const fdt &dtb);
        void create_defines();
        void include_headers();
};
#endif