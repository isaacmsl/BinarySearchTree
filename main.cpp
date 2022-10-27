#include <iostream>
using namespace std;

struct Node
{
    int m_key;
    Node * m_sub_l;
    Node * m_sub_r;
    Node (int key, Node * sub_l = nullptr, Node * sub_r = nullptr)
    : m_key{ key }, m_sub_l{ sub_l }, m_sub_r{ sub_r }
    {}
};

Node * search(Node * n, int key) {
    if (n == nullptr || n->m_key == key) return n;
    else if (n->m_key > key) return search(n->m_sub_l, key);
    else return search(n->m_sub_r, key);
}

void insert(Node * n, int key) {
    if (n->m_key > key) {
        if (n->m_sub_l == nullptr) {
            n->m_sub_l = new Node(key);
        } else {
            insert(n->m_sub_l, key);
        }
    } else {
        if (n->m_sub_r == nullptr) {
            n->m_sub_r = new Node(key);
        } else {
            insert(n->m_sub_r, key);
        }
    }
}

void printAll(Node * root) {
    if (root == nullptr) return;

    cout << root->m_key << '\n';
    printAll(root->m_sub_l);
    printAll(root->m_sub_r);
}

int main() {
    Node * root = new Node(8);
    insert(root, 6);
    insert(root, 5);
    Node * found = search(root, 6);
    Node * notFound = search(root, 7);
    cout << "Found: " << found->m_key << '\n';
    cout << "Not found: " << (notFound == nullptr) << '\n';
    return 0;
}