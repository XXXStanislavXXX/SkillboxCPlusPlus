#include "train.h"
#include <iostream>
#include <chrono>
#include <thread>

Train::Train(char id, int travel_seconds, Station &station)
    : id_(id), travel_seconds_(travel_seconds), station_(station), started_(false) {}

Train::~Train() {
    if (started_ && thread_.joinable()) thread_.join();
}

void Train::start() {
    started_ = true;
    thread_ = std::thread(&Train::run, this);
}

void Train::join() {
    if (thread_.joinable()) thread_.join();
}

void Train::run() {
    // Simulate travel time
    std::this_thread::sleep_for(std::chrono::seconds(travel_seconds_));

    {
        std::lock_guard<std::mutex> cout_lk(station_.cout_mutex());
        std::cout << "Arrived: " << id_ << std::endl;
    }

    // Try to acquire platform; if not immediately available, report waiting.
    if (!station_.platform_mutex().try_lock()) {
        {
            std::lock_guard<std::mutex> cout_lk(station_.cout_mutex());
            std::cout << "Waiting for platform: " << id_ << std::endl;
        }
        station_.platform_mutex().lock(); // block until available
    }

    // Now on platform
    station_.set_current(id_);
    {
        std::lock_guard<std::mutex> cout_lk(station_.cout_mutex());
        std::cout << "On platform: " << id_ << std::endl;
        std::cout << "Type 'depart' to release platform:" << std::endl;
    }

    // Wait for depart signal (polling with small sleep, protected by mutex inside Station).
    while (!station_.check_depart(id_)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Depart
    {
        std::lock_guard<std::mutex> cout_lk(station_.cout_mutex());
        std::cout << "Departed: " << id_ << std::endl;
    }

    station_.increment_visited();
    station_.clear_current();
    station_.platform_mutex().unlock();
}
