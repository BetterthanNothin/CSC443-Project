#include <climits>
#include <vector>

using std::vector;


struct BinaryT{
    BinaryT* left;
    BinaryT* right;
    BinaryT* parent;
    bool color;
    int key;
    int val;
};

struct pair{
    int key;
    int val;
};


class memtable{

public:
    const int memtable_size = 30;
    int current_size = 0;
    
    void insert(int key, int val){
        current_size++;
        if(current_size == memtable_size){flush_memtable(); return;}

        BinaryT* z = new BinaryT;
        z->key = key;
        z->val = val;
        z->parent = nil, z->left = nil, z->right = nil;

        BinaryT* y = nil;
        BinaryT* x = root;
        while(x != nil){
            y = x;
            if(z->key < x->key){x = x->left;}
            else{x = x->right;}
        }
        z->parent = y;
        if(y == nil){root = z;}
        else if(z->key < y->key){y->left = z;}
        else{y->right = z;}
        z->left = nil;
        z->right = nil;
        z->color = true;

        while(z->parent->color){
            if(z->parent == z->parent->parent->left){
                y = z->parent->parent->right;
                if(y->color){
                    z->parent->color = false;
                    y->color = false;
                    z->parent->parent->color = true;
                    z = z->parent->parent;
                }
                else if(z == z->parent->right){
                    z = z->parent;
                    leftRotate(z);
                    z->parent->color = false;
                    z->parent->parent->color = true;
                    rightRotate(z->parent->parent);
                }
            }
            else{
                y = z->parent->parent->left;
                if(y->color){
                    z->parent->color = false;
                    y->color = false;
                    z->parent->parent->color = true;
                    z = z->parent->parent;
                }
                else if(z == z->parent->left){
                    z = z->parent;
                    rightRotate(z);
                    z->parent->color = false;
                    z->parent->parent->color = true;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = false;
    }

    int get(int key){
        BinaryT* x = root;
        while(x != nil){
            if(x->key == key){return x->val;}
            else if(x->key > key){x = x->right;}
            else{x = x->left;}
        }
        return INT_MIN;   //I dont know what the return value should be if the key is not found.
    }

    vector<vector<int>> scan(int begin, int end){
        vector<vector<int>> r;
        return scan(begin, end, r, root);
    }

private:
    BinaryT* root;
    BinaryT* nil;

    void leftRotate(BinaryT* x){
        BinaryT* y = x->right;
        x->right = y->left;
        if(y->left == nil){y->left->parent = x;}
        y->parent = x->parent;
        if(x->parent == nil){root = y;}
        else if(x == x->parent->left){x->parent->left = y;}
        else{x->parent->right = y;}
        x->left = x;
        x->parent = y;
    }

    void flush_memtable(){

    }

    void rightRotate(BinaryT* x){
        BinaryT* y = x->left;
        x->left = y->right;
        if(y->right == nil){y->right->parent = x;}
        y->parent = x->parent;
        if(x->parent == nil){root = y;}
        else if(x == x->parent->right){x->parent->right = y;}
        else{x->parent->left = y;}
        x->right = x;
        x->parent = y;
    }    

    vector<vector<int>> scan(int begin, int end, std::vector<vector<int>> r, BinaryT* x){
        if(x == nil){return r;}

        if(x->key > begin){
            vector<vector<int>> n = scan(begin, end, r, x->left);
            r.insert(r.end(), n.begin(), n.end());
        }
        if(begin < x->key < end ){
            vector<int> p = {x->key, x->val};
            r.push_back(p);
        }
        if(x->key < end){
            vector<vector<int>> n = scan(begin, end, r, x->right);
            r.insert(r.end(), n.begin(), n.end());
        }

        return r;
    }

};


