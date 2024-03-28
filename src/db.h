#include "memtable.h"
#include "sst.h"
#include <vector>
#include <string>

class DB{
public:
    void create(int capacity);
    void open(std::string name);
    int read(int key);
    void write(int key, int value);
    void close();

private:
    memtable curr_table;
    std::vector<sst> files;

};