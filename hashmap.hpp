#pragma once
#include <vector> //I really wanted to use my own List datatype but it did not work with the destructor
#include <utility>
#include <memory>
#include <functional>

#define INVALID 0

template<typename one, typename two>
struct pair {
    one first;
    two second;
};

template<class key, class value>
class static_hashmap {
private:
    size_t map_size = 0;
    std::unique_ptr<std::vector<pair<key, value>>[]> map; 
    key empty_key;

    size_t hash(const key k) {
        return std::hash<key>{}(k) % map_size;
    }

public:
    void insert(const key k, const value val) {
        if (k == empty_key) return;

        size_t idx = hash(k);
        auto& vec = map[idx];
        for (auto& p : vec) {
            if (p.first == k) {
                p.second = val;
                return;
            }
        }
        vec.push_back(pair<key, value>{k, val});
    }

    value retrieve(const key k) {
        size_t idx = hash(k);
        const auto& vec = map[idx];
        for (const auto& p : vec) {
            if (p.first == k) {
                return p.second;
            }
        }
        return static_cast<value>(INVALID);
    }

    value remove(const key k) {
        size_t idx = hash(k);
        auto& vec = map[idx];
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            if (it->first == k) {
                value val = it->second;
                vec.erase(it); 
                return val;
            }
        }
        return static_cast<value>(INVALID);
    }

    value remove(const key k, const value val) {
        if (retrieve(k) == val) return remove(k);
        return static_cast<value>(INVALID);
    }

    value operator[](const key k) {
        return retrieve(k);
    }

    explicit static_hashmap(const key emptykey, const size_t size = 1000) {
        this->empty_key = emptykey;
        this->map_size = size;
        this->map = std::make_unique<std::vector<pair<key, value>>[]>(map_size);
    }

    static_hashmap(const static_hashmap& other) {
        this->map_size = other.map_size;
        this->empty_key = other.empty_key;
        this->map = std::make_unique<std::vector<pair<key, value>>[]>(map_size);
        for (size_t i = 0; i < map_size; ++i) {
            this->map[i] = other.map[i];
        }
    }

    ~static_hashmap() = default;
};
