

class memtable{

public:
    const int memtable_size = 30;
    


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
        else{x->p->right = y;}
        x->left = x;
        x->parent = y;
    }

    void rightRotate(BinaryT* x){
        BinaryT* y = x->left;
        x->left = y->right;
        if(y->right == nil){y->right->parent = x;}
        y->parent = x->parent;
        if(x->parent == nil){root = y;}
        else if(x == x->parent->right){x->parent->right = y;}
        else{x->p->left = y;}
        x->right = x;
        x->parent = y;
    }

    void insert(BinaryT* z){
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
                else if(z == z->p->right){
                    z = z->parent;
                    leftRotate(z);
                    z->parent->color = false;
                    z->parent->parent->color = true;
                    rightRotate(z->parent->parent)
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
                else if(z == z->p->left){
                    z = z->parent;
                    rightRotate(z);
                    z->parent->color = false;
                    z->parent->parent->color = true;
                    leftRotate(z->parent->parent)
            }
        }
        root->color = false;
    }




};


struct BinaryT{
    BinaryT* left;
    BinaryT* right;
    BinaryT* parent;
    bool color;
    int key;
    int val;
};