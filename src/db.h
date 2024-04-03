#include "memtable.h"
#include "sst.h"
#include <vector>
#include <string>

const int DEFAULT_MEMTABLE_SIZE = -1;

class DB{
private:
    void create(int capacity);
public:
    void open(std::string name, int memtable_size = DEFAULT_MEMTABLE_SIZE);
    int read(int key);
    void write(int key, int value);
    vector<int> can(int key1, key2);
    void close();
private:
    memtable curr_table;
    std::vector<sst> files;
};