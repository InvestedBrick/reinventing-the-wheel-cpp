#pragma once
#include <stdexcept>
class BST{
private:
    struct node{
        int data;
        node* left;
        node* right;
    };

    node* root = nullptr;

    node* make_node(int data) {
        node* new_node = new node();
        new_node->data = data;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    }
public:
    void add_node(int data){
        if(root == nullptr){
            root = make_node(data);
            return;
        }

        node* current_node = root;

        while(current_node->data != data){
            if(data < current_node->data){
                current_node->left == nullptr ? current_node->left = make_node(data) : current_node = current_node->left;
            }
            else if(data > current_node->data){
                current_node->right == nullptr ? current_node->right = make_node(data) : current_node = current_node->right;
            }
            else{break;}
        }

    }
    node* get_node(int data){
        if(root == nullptr){
            throw std::runtime_error("No Root found");
            return;
        }

        node* current_node = root;

        while(current_node != nullptr){
            if(data < current_node->data){
                if(current_node->left == nullptr){
                    return current_node;
                } 
                current_node = current_node->left;
            }
            else if(data > current_node->data){
                if(current_node->right == nullptr){
                    return current_node;
                } 
                current_node = current_node->right;
            }
            else{
                return current_node;
            }

        }
        return nullptr; //Node was not found

    }


};

