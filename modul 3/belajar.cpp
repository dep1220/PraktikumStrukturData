#include <iostream>

using namespace std;

// definisi struktur data untuk node pada linked list
struct Node {
    int data; // data yang disimpan di dalam node
    Node* next; // pointer ke node berikutnya
};

class LinkedList {
public:
    // konstruktor default
    LinkedList() {
        head = NULL;
    }

    // fungsi untuk menambahkan elemen ke dalam linked list
    void add(int data) {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;

        // jika linked list masih kosong, elemen baru menjadi head
        if (head == NULL) {
            head = new_node;
        }
        // jika tidak kosong, tambahkan elemen baru ke akhir linked list
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    // fungsi untuk menampilkan isi dari linked list
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    Node* head; // pointer ke elemen pertama pada linked list
};

int main() {
    LinkedList myList;

    myList.add(1);
    myList.add(2);
    myList.add(3);
    myList.add(4);
    myList.add(5);

    myList.display(); // output: 1 2 3 4 5

    return 0;
}
