#pragma once
#include <cassert>
template<class Item>
class List{
private:
    Item* data;
    size_t size;
    size_t capacity;


    void resize(size_t new_capacity){
        Item* new_data = new Item[new_capacity];
        for(size_t i = 0; i < size; i++){
            new_data[i] = data [i];
        }
        delete[] data;
        capacity = new_capacity;
        data = new_data;
    }
public:
    List(){
        size = 0;
        capacity = 1;
        data = new Item;
    }

    List(size_t capacity){
        size = 0;
        this->capacity = capacity;
        data = new Item[capacity];
    }
    ~List(){
        capacity = 0;
        size = 0;
        delete[] data;
        data = nullptr;
    }
    List(const List& other) {
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new Item[other.capacity];
        for(size_t i = 0; i < this->size;++i){
            this->data[i] = other.data[i];
        }
    }

    Item operator[](size_t idx){
        assert(idx < size);
        return data [idx];
    }
    

    void append(Item item){
        if(size >= capacity){
            resize(capacity + capacity);
        }

        data[size] = item;
        size++;
    }

    Item pop(){
        if(size <= capacity * 0.25f){
            resize(capacity * 0.5f);
        }

        size--;
        return data[size]; //you could optionally return size[data] if you fell like a masochist today
    }

    size_t get_size(){
        return this->size;
    }
    size_t get_capacity(){
        return this->capacity;
    }

    void shrink_to_fit(){
        if(capacity > size){
            resize(size);
        }
    }
};