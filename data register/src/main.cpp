#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include "../include/registry.h"

// parsing helpers
template<typename T>
bool parseValue(const std::string& s, T& out);

template<>
bool parseValue<int>(const std::string& s, int& out) {
    try {
        size_t pos;
        long v = std::stol(s, &pos);
        if (pos != s.size()) return false;
        out = static_cast<int>(v);
        return true;
    } catch(...) { return false; }
}

template<>
bool parseValue<double>(const std::string& s, double& out) {
    try {
        size_t pos;
        double v = std::stod(s, &pos);
        if (pos != s.size()) return false;
        out = v;
        return true;
    } catch(...) { return false; }
}

template<>
bool parseValue<std::string>(const std::string& s, std::string& out) {
    out = s;
    return true;
}

template<typename K, typename V>
void runRegistry() {
    Registry<K,V> reg;
    std::string cmd;
    while (true) {
        if(!(std::cin >> cmd)) break;
        if (cmd == "exit") break;
        if (cmd == "add") {
            std::string ks, vs;
            if(!(std::cin >> ks >> vs)) {
                std::cout << "invalid input\n";
                continue;
            }
            K k; V v;
            if (!parseValue<K>(ks, k) || !parseValue<V>(vs, v)) {
                std::cout << "parse error\n";
                continue;
            }
            reg.add(k, v);
        } else if (cmd == "remove") {
            std::string ks; if(!(std::cin >> ks)) { std::cout << "invalid\n"; continue; }
            K k;
            if (!parseValue<K>(ks, k)) { std::cout << "parse error\n"; continue; }
            size_t n = reg.remove(k);
            std::cout << n << " removed\n";
        } else if (cmd == "find") {
            std::string ks; if(!(std::cin >> ks)) { std::cout << "invalid\n"; continue; }
            K k;
            if (!parseValue<K>(ks, k)) { std::cout << "parse error\n"; continue; }
            auto vals = reg.find(k);
            for (const auto& x : vals) std::cout << x << '\n';
        } else if (cmd == "print") {
            reg.printAll();
        } else {
            std::cout << "unknown command\n";
        }
    }
}

int main() {
    std::cout << "Select key type: 1-int 2-double 3-string\n";
    int kt=0, vt=0;
    if (!(std::cin >> kt)) return 0;
    std::cout << "Select value type: 1-int 2-double 3-string\n";
    if (!(std::cin >> vt)) return 0;

    if (kt==1 && vt==1) runRegistry<int,int>();
    else if (kt==1 && vt==2) runRegistry<int,double>();
    else if (kt==1 && vt==3) runRegistry<int,std::string>();
    else if (kt==2 && vt==1) runRegistry<double,int>();
    else if (kt==2 && vt==2) runRegistry<double,double>();
    else if (kt==2 && vt==3) runRegistry<double,std::string>();
    else if (kt==3 && vt==1) runRegistry<std::string,int>();
    else if (kt==3 && vt==2) runRegistry<std::string,double>();
    else if (kt==3 && vt==3) runRegistry<std::string,std::string>();
    else std::cout << "invalid types\n";

    return 0;
}