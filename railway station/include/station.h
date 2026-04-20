/**
* \file station.h
 * \brief Station interface for platform control (mutex-based synchronization).
 *
 * All descriptions are in English as required.
 */

#ifndef STATION_H
#define STATION_H

#include <mutex>
#include <map>

class Station {
public:
    Station();

    // Access to platform mutex (train threads use try_lock/lock/unlock).
    std::mutex &platform_mutex();

    // Console output mutex.
    std::mutex &cout_mutex();

    // Set current train id that occupies the platform.
    void set_current(char id);

    // Clear current platform occupant.
    void clear_current();

    // Mark that current train should depart (called by main thread on 'depart').
    void signal_depart_current();

    // Check whether depart flag is set for given train id.
    bool check_depart(char id);

    // Increment visited counter and get current visited count.
    void increment_visited();
    int visited_count();

    // Get id of current train on platform ('\0' if none).
    char current_on_platform();

private:
    std::mutex platform_mtx_;
    std::mutex state_mtx_;
    std::mutex cout_mtx_;
    char current_;
    std::map<char, bool> depart_flags_;
    int visited_;
};

#endif // STATION_H
