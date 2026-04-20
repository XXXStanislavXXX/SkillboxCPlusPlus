#include <iostream>
#include <string>
#include <vector>
#include "train.h"
#include "station.h"

int main() {
    Station station;

    int tA, tB, tC;
    {
        std::lock_guard<std::mutex> lk(station.cout_mutex());
        std::cout << "Enter travel time (seconds) for train A:" << std::endl;
    }
    std::cin >> tA;
    {
        std::lock_guard<std::mutex> lk(station.cout_mutex());
        std::cout << "Enter travel time (seconds) for train B:" << std::endl;
    }
    std::cin >> tB;
    {
        std::lock_guard<std::mutex> lk(station.cout_mutex());
        std::cout << "Enter travel time (seconds) for train C:" << std::endl;
    }
    std::cin >> tC;

    // create trains
    Train trainA('A', tA, station);
    Train trainB('B', tB, station);
    Train trainC('C', tC, station);

    // start trains
    trainA.start();
    trainB.start();
    trainC.start();

    // consume the leftover newline before getline loop
    std::string dummy;
    std::getline(std::cin, dummy);

    // Main loop: accept 'depart' commands until all 3 visited
    while (station.visited_count() < 3) {
        std::string cmd;
        {
            // prompt is printed by trains when on platform; still allow manual prompt
            std::getline(std::cin, cmd);
        }

        if (cmd == "depart") {
            char cur = station.current_on_platform();
            if (cur == '\0') {
                std::lock_guard<std::mutex> lk(station.cout_mutex());
                std::cout << "No train on platform to depart. Waiting..." << std::endl;
            } else {
                station.signal_depart_current();
            }
        } else if (cmd.empty()) {
            // ignore empty lines
            continue;
        } else {
            std::lock_guard<std::mutex> lk(station.cout_mutex());
            std::cout << "Unknown command. Type 'depart' to release platform." << std::endl;
        }
    }

    // join threads
    trainA.join();
    trainB.join();
    trainC.join();

    {
        std::lock_guard<std::mutex> lk(station.cout_mutex());
        std::cout << "All trains have visited the station. Exiting." << std::endl;
    }

    return 0;
}
