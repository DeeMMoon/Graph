#ifndef GRAPH_QUEUE_H
#define GRAPH_QUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue{
private:
    struct Node
    {
        T data;
        Node *prev;
    };
    Node *root;
public:
    Queue() : root(nullptr){}

    void init()
    {
        Queue<T>();
    }

    bool empty() const
    {return !root;}

    void push (const T& value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        if (!empty()) {
            Node *head = root;
            while (root->prev)
                root = root->prev;
            root->prev = newNode;
            root = head;
        } else
            root = newNode;
    }

    T pop()
    {
        if (empty())
            throw std::length_error("Queue is empty");
        Node *delNode = root;
        T value = delNode->data;
        root = delNode->prev;
        delete delNode;
        return value;
    }

    const T& peek()
    {
        if(empty())
            throw std::length_error("Queue is empty");
        return root->data;
    }
    ~Queue(){
        while (!empty())
            this->pop();
    }
};
#endif
