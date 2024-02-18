#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <vector>
#include <string>

using std::string;
using std::vector;




struct SST{
    int file_descriptor;
    int db_number;
    off_t offset;
    int size;
    string file_name; 
};

void readPage(SST file, ){
    return;
}

void openFile(SST file){
    file.file_descriptor = open(file.file_name.data(), O_RDONLY);
}

SST writeFile(vector<vector<int>> KV_pairs, int db_number){}



/*
void do_stuff(){
    const char* file_name = "start";
    int the_file;
    the_file = open(file_name, O_RDWR|O_CREAT, S_IRWXU);
    std::cout << "the_file: " << the_file << "\n";
    if(the_file < 0){return;}
    size_t nbytes = 1;
    off_t offset = 0;
    char write_buffer[] = "well life sucks";
    nbytes = std::size(write_buffer);
    char read_buffer[nbytes];
    ssize_t r;

    r = pwrite(the_file, write_buffer, nbytes, offset);

    std::cout << "r: " << r << "\n" << "the_file: " << the_file <<"\n";

        
    r = pread(the_file, read_buffer, nbytes, offset);

    std::cout << "r: " << r << "\n";

    if(std::string(read_buffer) == std::string(write_buffer)){
        std::cout << "IT WORKED \n";
    }
    else{
        std::cout << "IT DIDNT WORK \n";
        std::cout << "read_buffer[0,1]: " << std::string(read_buffer) << "\n" << "write_buffer[0,1]: " << std::string(write_buffer) << "\n";
        
    }
}
*/