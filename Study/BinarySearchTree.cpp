#include <cassert>
#include <iostream>

class BinarySearchTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int v) : value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        }
        else {
            node->right = insert(node->right, value);
        }
        return node;
    }
    bool contains(Node* node, int value) const {
        if (node == nullptr) {
            return false;
        }
        if (value == node->value) {
            return true;
        }
        if (value < node->value) {
            return contains(node->left, value);
        }
            return contains(node->right, value);
    }

    Node* remove(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->value) {
            node->left = remove(node->left, value);
        }
        else if (value > node->value) {
            node->right = remove(node->right, value);
        }
        else {
            // 1. No children
            if (node->left == nullptr and node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // 2. 1 child, 2 sluchaya
            if (node->right != nullptr) {
                Node* tmp = node->right;
                delete node;
                return tmp;
            }
            if (node->left != nullptr) {
                Node* tmp = node->left;
                delete node;
                return tmp;
            }
            // 3. 2 rebenka
            Node* minNode = findMin(node->right);
            node->value = minNode->value;
            node->right = remove(node->right, minNode->value);
        }
        return node;
    }

    Node* findMin(Node* node) const {
        while (node != nullptr and node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void inorder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        std::cout << node->value << " ";
        inorder(node->right);
    }
    void preorder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        std::cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        std::cout << node->value << " ";
    }

    void destroy(Node* node) {
        if (node == nullptr) {
            return;
        }
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }
    ~BinarySearchTree() {
        destroy(root);
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool contains(int value) const {
        return contains(root, value);
    }

    void remove(int value) {
        root = remove(root, value);
    }

    void printInOrder() const {
        inorder(root);
        std::cout << std::endl;
    }
    void printPreOrder() const {
        preorder(root);
        std::cout << std::endl;
    }
    void printPostOrder() const {
        postorder(root);
        std::cout << std::endl;
    }
};

int main(){
    std::cout << "=== BST TESTS START ===\n";

    BinarySearchTree bst;

    std::cout << "[1] Insert elements\n";
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);
    std::cout << "OK\n";

    std::cout << "[2] Check contains()\n";
    assert(bst.contains(8));
    assert(bst.contains(1));
    assert(bst.contains(14));
    assert(!bst.contains(2));
    std::cout << "OK\n";

    std::cout << "[3] In-order traversal (should be sorted)\n";
    std::cout << "Expected: 1 3 4 6 7 8 10 13 14\n";
    std::cout << "Actual:   ";
    bst.printInOrder();

    std::cout << "[4] Pre-order traversal\n";
    bst.printPreOrder();

    std::cout << "[5] Post-order traversal\n";
    bst.printPostOrder();

    std::cout << "[6] Remove leaf node (1)\n";
    bst.remove(1);
    assert(!bst.contains(1));
    bst.printInOrder();
    std::cout << "OK\n";

    std::cout << "[7] Remove node with one child (14)\n";
    bst.remove(14);
    assert(!bst.contains(14));
    bst.printInOrder();
    std::cout << "OK\n";

    std::cout << "[8] Remove node with two children (3)\n";
    bst.remove(3);
    assert(!bst.contains(3));
    bst.printInOrder();
    std::cout << "OK\n";

    std::cout << "[9] Remove root (8)\n";
    bst.remove(8);
    assert(!bst.contains(8));
    bst.printInOrder();
    std::cout << "OK\n";

    std::cout << "=== ALL TESTS PASSED ===\n";
    return 0;
}