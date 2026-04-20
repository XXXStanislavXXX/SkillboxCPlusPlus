#include "station.h"

Station::Station()
    : current_('\0'), visited_(0) {}

std::mutex &Station::platform_mutex() {
    return platform_mtx_;
}

std::mutex &Station::cout_mutex() {
    return cout_mtx_;
}

void Station::set_current(char id) {
    std::lock_guard<std::mutex> lg(state_mtx_);
    current_ = id;
    depart_flags_[id] = false;
}

void Station::clear_current() {
    std::lock_guard<std::mutex> lg(state_mtx_);
    current_ = '\0';
}

void Station::signal_depart_current() {
    std::lock_guard<std::mutex> lg(state_mtx_);
    if (current_ != '\0') {
        depart_flags_[current_] = true;
    }
}

bool Station::check_depart(char id) {
    std::lock_guard<std::mutex> lg(state_mtx_);
    auto it = depart_flags_.find(id);
    if (it == depart_flags_.end()) return false;
    return it->second;
}

void Station::increment_visited() {
    std::lock_guard<std::mutex> lg(state_mtx_);
    ++visited_;
}

int Station::visited_count() {
    std::lock_guard<std::mutex> lg(state_mtx_);
    return visited_;
}

char Station::current_on_platform() {
    std::lock_guard<std::mutex> lg(state_mtx_);
    return current_;
}
