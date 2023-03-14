# include <iostream>

using namespace std;

// struktur node
struct Node {
    int data;
    Node *prev;
    Node *next;
};

// class DoubleLinkedList
class DoubleLinkedList {
private:
    Node *head;
    Node *tail;

public:
    // constructor
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // fungsi untuk membuat node baru
    Node *createNode(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
    }

    // fungsi untuk menambahkan node dari depan sesudah simpul
    void addNodeAfter(int data) {
        Node *newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // fungsi untuk menambahkan node dari belakang sesudah simpul
    void addNodeBefore(int data) {
        Node *newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // fungsi untuk menghapus node dari tengah
    void deleteNode(int data) {
        Node *temp = head;

        while (temp != NULL) {
            if (temp->data == data) {
                if (temp == head) {
                    head = head->next;
                    head->prev = NULL;
                    delete temp;
                    return;
                } else if (temp == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                    delete temp;
                    return;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    return;
                }
            }

            temp = temp->next;
        }

        cout << "Data " << data << " tidak ditemukan." << endl;
    }

    // fungsi untuk menampilkan isi linked list
    void displayList() {
        if (head == NULL) {
            cout << "Linked list kosong." << endl;
            return;
        }

        Node *temp = head;
        cout << "Isi linked list: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// fungsi untuk menampilkan menu
void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Tambah data dari belakang" << endl;
    cout << "2. Tambah data dari depan" << endl;
    cout << "3. Hapus data" << endl;
    cout << "4. Tampilkan linked list" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    DoubleLinkedList dll;
    int choice, data;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            dll.addNodeAfter(data);
            break;
        case 2:
            cout << "Masukkan data: "; cin >> data;
            dll.addNodeAfter(data);
            break;
        case 3:
            dll.displayList();
            cout << "Masukkan data yang akan dihkapsu : "; cin >> data;
            dll.deleteNode(data);
            break;
        case 4:
            dll.displayList();
            break;
        case 5:
            cout << "Terimakasi..." << endl;
            break;
        default:
            cout << "Pilihan tidak ada." << endl;
    }
       
    } while(choice != 5);
}