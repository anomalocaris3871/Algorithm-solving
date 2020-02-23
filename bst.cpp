#include <bits/stdc++.h>

using namespace std;

ifstream ifs("bst.inp");
ofstream ofs("bst.out");

class BinaryNode {
    string data;
    BinaryNode *left;
    BinaryNode *right;
public:
    BinaryNode(string val=0, BinaryNode* l=nullptr, BinaryNode *r=nullptr)
        : data(val),left(l), right(r) {}
    void setDate(string val) { data = val; };
    void setLeft(BinaryNode *l) {left = l;}
    void setRight(BinaryNode *r) {right = r; }
    string getData(void) const { return data; }
    BinaryNode* getLeft(void) const { return left; }
    BinaryNode* getRight(void) const { return right; }
    bool isLeaf(void) const { return left== nullptr && right == nullptr; }
};

class BinaryTree {
protected:
    BinaryNode * root;
    void getLeaf(BinaryNode* node) {
        if(node == nullptr)
            return;
        if(node->isLeaf())
            ofs << node->getData() << " ";
        else{
            getLeaf(node->getLeft());
            getLeaf(node->getRight());
        }
    }
    int getHeight(BinaryNode *node) {
        if(node == NULL)
            return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
    }
    void inorder(BinaryNode *node) {
        if(node != NULL) {
            if(node->getLeft()!=NULL )
                inorder(node->getLeft());
            ofs << "[" << node->getData() << "]" << " ";
            if(node->getRight()!=NULL )
                inorder(node->getRight());
        }
    }
public:
    BinaryTree(void): root(nullptr) {}
    void setRoot(BinaryNode *node) { root = node; }
    BinaryNode* getRoot(void) const { return root; }
    bool isEmpty(void) const { return root==nullptr; }

    void getLeaf() {
        if(isEmpty())
            return;
        else
            getLeaf(root);
        ofs << endl;
    }
    void inorder(void) {
        ofs << "\n  preorder: ";
        inorder(root);
    }

    int getHeight(void) {
        return isEmpty() ? 0 : getHeight(root);
    }
};

class BinSrchTree : public BinaryTree {
private:
    void insert(BinaryNode* r, BinaryNode* n) {
        if(n->getData() == r->getData())
            return;
        else if(n->getData() < r->getData())
            if(r->getLeft() == nullptr)
                r->setLeft(n);
            else
                insert(r->getLeft(),n);
        else
            if(r->getRight() == nullptr)
                r->setRight(n);
            else
                insert(r->getRight(),n);
    }
    void remove(BinaryNode* parent, BinaryNode *node){
        if(node->isLeaf()){
            if(parent == nullptr)
                root = nullptr;
            else{
                if(parent->getLeft() == node)
                    parent->setLeft(nullptr);
                else parent->setRight(nullptr);
            }
        } else if(node->getLeft()!=nullptr) {
                BinaryNode* succp = node;
                BinaryNode* succ = node->getLeft();
                while(succ->getRight() != nullptr) {
                    succp = succ;
                    succ = succ->getRight();
                }

                if(succp->getLeft() == succ )
                    succp->setLeft(succ->getLeft());
                else
                    succp->setRight(succ->getLeft());

                node->setDate(succ->getData());
                node = succ;
        } else {
            BinaryNode* succp = node;
            BinaryNode* succ = node->getRight();
            while(succ->getLeft() != nullptr) {
                succp = succ;
                succ = succ->getLeft();
            }

            if(succp->getLeft() == succ )
                succp->setLeft(succ->getRight());
            else
                succp->setRight(succ->getRight());

            node->setDate(succ->getData());
            node = succ;
        }
    }

public:
    size_t level = 1;
    BinSrchTree(){}
    void getDepth(int depth) {
        if(depth > getHeight()){
            ofs << "NO" <<endl;
            return;
        }
        getDepth(root,depth);
        level = 1;
        ofs << endl;
    }

    void getDepth(BinaryNode *n, int depth) {
        if(n==NULL)
            return;
        if(depth == level){
            ofs << n->getData() << " ";
        }
        if(level < depth){
            ++level;
            getDepth(n->getLeft(),depth);
            getDepth(n->getRight(),depth);
            --level;

        }
    }
    void insert(BinaryNode* n) {
        if(n==nullptr)
            return;
        if(isEmpty())
            root = n;
        else
            insert(root,n);
    }

    void remove(string key){
        if(isEmpty())
            return;
        BinaryNode *parent = nullptr;
        BinaryNode *node = root;
        while(node!=nullptr && node->getData() != key){
            parent = node;
            node = (key < node->getData())
                ? node->getLeft() : node->getRight();
        }
        if(node == nullptr) {
            return;
        }
        else
            remove(parent,node);
    }
};

int main(void)
{
    BinSrchTree tree;

    string command;
    size_t cnt = 0, N;
    ifs >> N;

    while(cnt < N) {
        ifs >> command;
        if(command == "+"){
            string new_data;
            ifs >> new_data;
            tree.insert(new BinaryNode(new_data));
        }
        else if(command == "-"){
            string rmv_data;
            ifs >> rmv_data;
            tree.remove(rmv_data);
        }
        else if(command == "leaf"){
            tree.getLeaf();
        }
        else{
            int num;
            ifs >> num;
            tree.getDepth(num);
        }
        cnt++;
    }

    //tree.inorder();

    ifs.close();
    ofs.close();
    return 0;
}
