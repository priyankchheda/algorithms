#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace LinkedList {
    template<typename T>
    struct Node {
        T data;
        Node<T>* next;

        Node(T _data) { data = _data; next = nullptr; }
    };

    template <typename T>
    class LinkedList {
    private:
        Node<T>* head;

    public:
        LinkedList() { head = nullptr; }
        Node<T>* getHead() { return head; }
        int getLength();
        int getLengthRecursive(Node<T>* node);

        /* Insertion Method */
        void insertHead(T data);
        void insertEnd(T data);
        void insertAt(T data, int position);

        /* Deletion Method */
        T deleteHead();
        T deleteEnd();
        T deleteAt(int position);
        T deleteKey(T key);
        void deleteList();

        /* Data */
        T dataAt(int position);
        int indexOf(T key);

        /* Recursive Method */
        void Reverse();
        void ReverseRecursive(Node<T>* node);

        /* Print Method */
        void printList();
        void printListRecursive(Node<T>* node);
        void printReverseListRecursive(Node<T>* node);
    };

    /**
     * Returns the number of node currently present in the linked list.
     * @return count of node, or 0 if the list is empty.
    */
    template <typename T>
    int LinkedList<T>::getLength() {
        Node<T>* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    /**
     * Returns the number of node currently present in the linked list.
     * It uses recursive approach.
     * @param node starting node from where counting is start.
     * @return count of node, or 0 if the list is empty.
    */
    template <typename T>
    int LinkedList<T>::getLengthRecursive(Node<T>* node) {
        if (node == nullptr) return 0;
        return 1 + getLengthRecursive(node->next);
    }

    /**
     * Inserts new node with value 'data' at the start of linked list.
     * @param data new data element that needs to be added at the start
    */
    template <typename T>
    void LinkedList<T>::insertHead(T data) {
        Node<T>* temp = new Node<T>(data);
        temp->next = head;
        head = temp;
    }

    /**
     * Inserts new node with value 'data' at the end of linked list.
     * @param data new data element that needs to be append at the end
    */
    template <typename T>
    void LinkedList<T>::insertEnd(T data) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* temp = head;
        if (temp == nullptr) {
            head = newNode;
            return;
        }
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    /**
     * Insert new node with value 'data' at given position in linked list.
     * @param data new data element that needs to be added at given position.
     * @param position position where new node will enter.
     *      Position is 1-based.
    */
    template <typename T>
    void LinkedList<T>::insertAt(T data, int position) {
        int linkedlist_len = getLength();
        if (position <= 1) {
            insertHead(data);
            return;
        } else if (position >= linkedlist_len) {
            insertEnd(data);
            return;
        } else {
            Node<T>* newNode = new Node<T>(data);
            Node<T>* previous = head;
            Node<T>* current = head;
            for (int i = 1; i < position; i++) {
                previous = current;
                current = current->next;
            }
            previous->next = newNode;
            newNode->next = current;
        }
    }

    /**
     * Delete head node from linked list
     * @return removedData value of deleted node
    */
    template <typename T>
    T LinkedList<T>::deleteHead() {
        if (head == nullptr) return -1;
        Node<T>* temp = head;
        T removedData = temp->data;
        head = head->next;
        delete temp;
        return removedData;
    }

    /**
     * Delete end node from linked list
     * @return removedData value of deleted node
    */
    template <typename T>
    T LinkedList<T>::deleteEnd() {
        if (head == nullptr) return -1;
        Node<T>* current = head;
        if (head->next == nullptr) head = nullptr;
        else {
            Node<T>* previous = head;
            while (current->next != nullptr) {
                previous = current;
                current = current->next;
            }
            previous->next = nullptr;
        }
        T removedData = current->data;
        delete current;
        return removedData;
    }

    /**
     * Delete node present at given position from linked list
     * @param position position at which node needs to be deleted.
     *      Position is 1-based.
     * @return removedData value of deleted node
    */
    template <typename T>
    T LinkedList<T>::deleteAt(int position) {
        int ll_length = getLength();
        if (position < 1 || position > ll_length)
            return -1;

        if (position == 1)
            return deleteHead();
        else if (position == ll_length)
            return deleteEnd();
        else {
            Node<T>* previous = head;
            Node<T>* current = head;
            for (int i = 1; i < position; i++) {
                previous = current;
                current = current->next;
            }
            T removedData = current->data;
            previous->next = current->next;
            current->next = nullptr;
            delete current;
            return removedData;
        }
    }

    /**
     * Delete first occurance of node from linked list with value 'key'
     * @param key node value that needs to be deleted
     * @return removedData value of deleted node
    */
    template <typename T>
    T LinkedList<T>::deleteKey(T key) {
        return deleteAt(indexOf(key));
    }

    /**
     * Deletes entire linked list. Cleans up the memory.
     * head node pointer is pointing to null.
    */
    template <typename T>
    void LinkedList<T>::deleteList() {
        Node<T>* current = head;
        Node<T>* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    /**
     * Get node value present at given position in the linked list
     * @param position position at which node value is needed. Position is 1-based.
     * @return node value at position
    */
    template <typename T>
    T LinkedList<T>::dataAt(int position) {
        int ll_length = getLength();
        if (position < 1 || position > ll_length)
            return -1;

        Node<T>* current = head;
        for (int i = 1; i < position; i++)
            current = current->next;

        return current->data;
    }

    /**
     * Returns index of node in linked list with node value 'key'.
     * Returns -1, if the key is not present.
     * @param count index of node with value 'key'
    */
    template <typename T>
    int LinkedList<T>::indexOf(T key) {
        Node<T>* node = head;
        int count = 1;
        while (node != nullptr) {
            if (node->data == key)
                return count;
            node = node->next;
            count++;
        }
        return -1;
    }

    /**
     * Reverse the original linked list using iterative approach.
    */
    template <typename T>
    void LinkedList<T>::Reverse() {
        Node<T>* previous = nullptr;
        Node<T>* following = nullptr;
        Node<T>* current = head;

        while (current != nullptr) {
            following = current->next;
            current->next = previous;
            previous = current;
            current = following;
        }
        head = previous;
    }

    /**
     * Reverse the original linked list using recursive approach.
    */
    template <typename T>
    void LinkedList<T>::ReverseRecursive(Node<T>* node) {
        if (node == nullptr)
            return;
        if (node->next == nullptr) {
            head = node;
            return;
        }
        ReverseRecursive(node->next);
        Node<T>* prev = node->next;
        prev->next = node;
        node->next = nullptr;
    }

    /**
     * printList simply prints the node value from head to end.
    */
    template <typename T>
    void LinkedList<T>::printList() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << " -> " << temp->data;
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    /**
     * printListRecursive simply prints the node value from head to end.
     * It uses recursive approach.
    */
    template <typename T>
    void LinkedList<T>::printListRecursive(Node<T>* node) {
        if (node == nullptr) return;
        std::cout << " -> " << node->data;
        printListRecursive(node->next);
    }

    /**
     * printReverseListRecursive simply prints the node value in reverse order,
     * from tail to head. It uses recursive approach.
    */
    template <typename T>
    void LinkedList<T>::printReverseListRecursive(Node<T>* node) {
        if (node == nullptr) return;
        printReverseListRecursive(node->next);
        std::cout << " -> " << node->data;
    }
}
#endif
