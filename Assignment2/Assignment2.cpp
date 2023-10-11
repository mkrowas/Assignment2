#include <iostream>  
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;


public:
    LinkedList() {
        this->head = nullptr;
    }

    void push_front(T data) {
        Node<T>* temp = new Node<T>(data);
        temp->next = head;
        head = temp;
    }

    void push_back(T data) {
        Node<T>* temp1 = new Node<T>(data);
        if (head == nullptr) {
            head = temp1;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = temp1;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void empty() {
        Node<T>* temp = new Node<T>(NULL);

        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void printList() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void remove(int pos) {
        Node<T>* temp;
        Node<T>* prev;
        temp = head;
        prev = head;
        for (int i = 0; i < pos; i++) {
            if (i == 0 && pos == 1) {
                head = head->next;
                free(temp);
            }
            else {
                if (i == pos - 1 && temp) {
                    prev->next = temp->next;
                    free(temp);
                }
                else {
                    prev = temp;

                    if (prev == NULL);
                    temp = temp->next;
                }
            }
        }
    }
};

int main() {
    return 0;
}