#include "shared_ptr_toy.h"

shared_ptr_toy make_shared_toy(const std::string& name) {
    return shared_ptr_toy(name);
}
