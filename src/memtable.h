#include <vector>

class memtable {
    public:
        virtual void insert(int key, int val) = 0;
        virtual int get(int key) = 0;
        virtual std::vector<std::vector<int>> scan(int key1, int key2) = 0;
};