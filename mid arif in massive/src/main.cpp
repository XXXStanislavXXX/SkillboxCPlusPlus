#include <iostream>
#include "array_utils.h"

int main() {
    std::cout << "Choose type: i (int), f (float), d (double). Default d: ";
    char choice = 'd';
    if (!(std::cin >> choice)) return 0;

    if (choice == 'i') {
        int arr[SIZE];
        input<int>(arr);
        std::cout << "Average: " << static_cast<double>(average<int>(arr)) << std::endl;
    } else if (choice == 'f') {
        float arr[SIZE];
        input<float>(arr);
        std::cout << "Average: " << static_cast<double>(average<float>(arr)) << std::endl;
    } else {
        double arr[SIZE];
        input<double>(arr);
        std::cout << "Average: " << static_cast<double>(average<double>(arr)) << std::endl;
    }

    return 0;
}
