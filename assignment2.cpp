#include <iostream>

using namespace std;

template <typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& d) : data(d), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    size_t num_items;
public:
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

    // push_front: Insert an element at the beginning of the list
    void push_front(const Item_Type& item) {
        Node* new_node = new Node(item);
        if (empty()) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
        ++num_items;
    }

    // push_back: Insert an element at the end of the list
    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item);
        if (empty()) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        ++num_items;
    }

    // pop_front: Remove the first element of the list
    void pop_front() {
        if (empty()) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        --num_items;
        if (empty()) tail = nullptr;
    }

    // pop_back: Remove the last element of the list
    void pop_back() {
        if (empty()) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            --num_items;
            return;
        }
        Node* cur = head;
        while (cur->next != tail) {
            cur = cur->next;
        }
        delete tail;
        tail = cur;
        tail->next = nullptr;
        --num_items;
    }

    // front: Return the first element of the list
    const Item_Type& front() const {
        if (empty()) throw std::out_of_range("List is empty");
        return head->data;
    }

    // back: Return the last element of the list
    const Item_Type& back() const {
        if (empty()) throw std::out_of_range("List is empty");
        return tail->data;
    }

    // empty: Return true if the list is empty, false otherwise
    bool empty() const {
        return head == nullptr;
    }

    // insert: Insert an element at a specific position in the list
    void insert(size_t index, const Item_Type& item) {
        if (index >= num_items) {
            push_back(item);
            return;
        }
        Node* new_node = new Node(item);
        if (index == 0) {
            new_node->next = head;
            head = new_node;
        } else {
            Node* cur = head;
            for (size_t i = 0; i < index - 1; ++i) {
                cur = cur->next;
            }
            new_node->next = cur->next;
            cur->next = new_node;
        }
        ++num_items;
    }

    // remove: Remove an element at a specific position in the list
    bool remove(size_t index) {
        if (index >= num_items) {
            return false;
        }
        if (index == 0) {
            pop_front();
        } else if (index == num_items - 1) {
            pop_back();
        } else {
            Node* current_node = head;
            for (size_t i = 1; i < index; ++i) {
                current_node = current_node->next;
            }
            Node* node_to_remove = current_node->next;
            current_node->next = node_to_remove->next;
            delete node_to_remove;
            --num_items;
        }
        return true;
    }

    size_t find(const Item_Type& item) {
        Node* current = head;
        size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;
    }
};

int main() {

    return 0;
}
