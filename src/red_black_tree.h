#include <vector>
#include <climits>
#include "memtable.h"

struct BinaryT{
    BinaryT* left;
    BinaryT* right;
    BinaryT* parent;
    bool color;
    int key;
    int val;
};


class red_black_tree : public memtable{
public:
    void insert(int key, int val);
    int get(int key);
    std::vector<std::vector<int>> scan(int begin = INT_MIN, int end = INT_MAX);
    red_black_tree();
    ~red_black_tree();
private:
    BinaryT* root;
    BinaryT* nil;

    void leftRotate(BinaryT* x);
    void rightRotate(BinaryT* x);
    std::vector<std::vector<int>> scan(int begin, int end, std::vector<std::vector<int>> r, BinaryT* x);
    void removeSubtree(BinaryT* node);
};


