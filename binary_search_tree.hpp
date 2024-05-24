#pragma once

class BST{
private:
    struct node{
        int data;
        node* left = nullptr;
        node* right = nullptr;
    };

    node* root = nullptr;
    node* make_node(int data){
        node* n = new node;
        n->data = data;
        return n;
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
                continue;
            }
            if(data > current_node->data){
                current_node->right == nullptr ? current_node->right = make_node(data) : current_node = current_node->right;
                continue;
            }
        }

    }


};

