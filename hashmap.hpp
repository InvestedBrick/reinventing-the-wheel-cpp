#pragma once
#include "dynamic_array.hpp" //no std::vector here
#include <utility>
#define INVALID 0

template<typename one,typename two>
struct pair{
    one first;
    two second;
};
template<class key,class value>
class static_hashmap{
private:
    size_t map_size = 0;
    List<pair<key,value>>* map;
    key empty_key;
    size_t hash(const key k){
        return std::hash<key>{}(k) % map_size; // I really tried to make my own hash function, failed tried again, failed tried again and then gave up because for some reason size_t, which is defined as unsigned long long, gets converted into unsigned int :(
    }
public:
    void insert(const key k, const value val){
        if(k == empty_key) return;
    	
        size_t idx = hash(k);
        auto& lst = map[idx];
        for(size_t i = 0; i < lst.get_size();++i){
            if(lst[i].first == k){
                lst[i].second = val;
                return;
            }
        }
        lst.append(pair<key,value>{k,val});
    }

    value retrieve(const key k){
        size_t idx = hash(k);
        const auto& lst = map[idx];
        for(size_t i = 0; i < lst.get_size();++i){
            if(lst[i].first == k) {return lst[i].second;}
        }
        return static_cast<value>(INVALID);
    }

    value remove(const key k){
        size_t idx = hash(k);
        auto& lst = map[idx];
        for(size_t i = 0; i < lst.get_size();++i){
           if(lst[i].first == k){
            value val = lst[i].second;
            lst.erase(i);
            return val;
           }
        }
        return static_cast<value>(INVALID);
    }
    value remove(const key k, const value val){
        if(retrieve(k) == val) return remove(k);
        return static_cast<value>(INVALID);
    }

    value operator[](const key k){
        return retrieve(k);
    }
    explicit static_hashmap(const key emtpykey, const size_t size = 1000){
        this->empty_key = emtpykey;
        this->map_size = size;
        this->map = new List<pair<key,value>>[map_size];
    }
    static_hashmap(const static_hashmap& other){
        this->map_size = other.map_size;
        this->empty_key = other.empty_key;
        this->map = new List<pair<key,value>>[map_size];
        this->map = other.map;
    }
    ~static_hashmap(){
        delete[] map;
    };
        
};