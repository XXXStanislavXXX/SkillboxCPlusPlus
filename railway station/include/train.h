/**
* \file train.h
 * \brief Train class representing a moving train (threaded).
 *
 * All descriptions are in English as required.
 */

#ifndef TRAIN_H
#define TRAIN_H

#include <thread>
#include "station.h"

class Train {
public:
    Train(char id, int travel_seconds, Station &station);
    ~Train();

    // Start thread.
    void start();

    // Join thread.
    void join();

private:
    void run();

    char id_;
    int travel_seconds_;
    Station &station_;
    std::thread thread_;
    bool started_;
};

#endif // TRAIN_H
