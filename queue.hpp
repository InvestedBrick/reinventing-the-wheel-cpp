#pragma once

template<class Item>
class Queue{
private:
    Item* data;
    size_t capacity;
    size_t size;
    size_t front_idx;
    size_t back_idx;

    void resize(size_t new_capacity){
        Item* new_data = new Item[new_capacity];
        for(size_t i = 0; i < size; ++i){
            new_data[i] = data[(front_idx + i) % capacity];
        }
        delete[] data;
        capacity = new_capacity;
        data = new_data;
        front_idx = 0;
        back_idx = size;
    }

public:
    void push_back(Item item){ 
        if(size >= capacity){
            resize(capacity + capacity);
        }
        data[back_idx] = item;
        ++size;
        ++back_idx;
    }

    Item front(){
        return data[front_idx];
    }
    Item back(){
        return data[back_idx - 1];
    }

    Item pop_front(){
        if(size <= capacity * 0.25f){
            resize(capacity * 0.5f);
        }

        --size;
        Item item = data[front_idx];
        front_idx = (front_idx + 1) % capacity;
        return item;
    }

    size_t get_capacity(){
        return capacity;
    }

    size_t get_size(){
        return size;
    }

    Queue(size_t capacity = 8){
        this->capacity = capacity;
        this->size = 0;
        this->front_idx = 0;
        this->back_idx = 0;
        data = new Item[capacity];
    }
    ~Queue(){
        delete[] data;
        data = nullptr;
    }
};
