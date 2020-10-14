#include <mydriver_mem0.h>
mydriver_mem0 :: mydriver_mem0(std::ostream &os, const fdt &dtb) : Device(os, dtb, "mydriver,mem0") {
}
void mydriver_mem0 :: include_headers() {
  dtb.match(std::regex(compat_string), [&](node n) {     // dtb.match() is finding the node which has the mydriver_mem0 value as its compatible key.
     emit_include(compat_string); });                    // emit_include will print a string (#include mydriver_mem0) (',' is replaced by '_' in compatible string)
}
void mydriver_mem0 :: create_defines() {
  dtb.match(std::regex(compat_string), [&](node n) {
    uint32_t val = 0;
    if (n.field_exists("init-value")) {
      val = n.get_fields<uint32_t>("init-value")[0];
    }
    emit_def("MY_MEM_DRIVER_INIT_VAL", std::to_string(val));
  }); 
}