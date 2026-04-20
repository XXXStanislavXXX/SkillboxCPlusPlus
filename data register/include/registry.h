#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "entry.h"

template<typename K, typename V>
class Registry {
public:
    void add(const K& key, const V& value) {
        items.push_back(Entry<K,V>{key, value});
    }

    // remove all entries with given key, return number removed
    size_t remove(const K& key) {
        auto old_size = items.size();
        items.erase(std::remove_if(items.begin(), items.end(),
                   [&](const Entry<K,V>& e){ return e.key == key; }),
                   items.end());
        return old_size - items.size();
    }

    // find returns vector of values matching key
    std::vector<V> find(const K& key) const {
        std::vector<V> res;
        for (const auto& e : items) {
            if (e.key == key) res.push_back(e.value);
        }
        return res;
    }

    void printAll() const {
        for (const auto& e : items) {
            std::cout << e.key << " -> " << e.value << '\n';
        }
    }

private:
    std::vector<Entry<K,V>> items;
};