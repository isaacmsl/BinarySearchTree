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

Node * minValueNode(Node * root) {
    if (root == nullptr)
        return nullptr;
    else if (root->m_sub_l == nullptr)
        return root;
    else
        return minValueNode(root->m_sub_l);
}

Node * remove(Node * n, int key) {
    if (n == nullptr)
        return n;
    else if (n->m_key == key) {
        bool no_childs = n->m_sub_l == n->m_sub_r; 
        if (no_childs)
            return nullptr;
        else if (n->m_sub_r == nullptr)
            return n->m_sub_l;
        else if (n->m_sub_l == nullptr)
            return n->m_sub_r;
        else {
            Node * min_of_sub_r = minValueNode(n->m_sub_r);
            n->m_key = min_of_sub_r->m_key;
            n->m_sub_r = remove(n->m_sub_r, n->m_key);
        }
    }
    else if (n->m_key > key)
        n->m_sub_l = remove(n->m_sub_l, key);
    else
        n->m_sub_r = remove(n->m_sub_r, key);

    return n;
}

void printAll(Node * root) {
    if (root == nullptr) return;

    cout << root->m_key << '\n';
    printAll(root->m_sub_l);
    printAll(root->m_sub_r);
}

int main() {
    Node * root = new Node(8);
    insert(root, 11);
    insert(root, 10);
    insert(root, 9);
    insert(root, 6);
    insert(root, 7);
    remove(root, 8);
    printAll(root);
    return 0;
}