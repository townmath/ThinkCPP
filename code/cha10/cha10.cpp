#include <iostream>
#include <fstream>
#include <sstream>

int main(){
    std::string fileName="dmv_data.txt";
    std::ifstream inFile(fileName);
    std::string line,data;
    while(!inFile.eof()){
        getline(inFile,line);
        std::istringstream ss(line);
        while(ss >> data){
            std::cout << data << " ";
        }
        std::cout << std::endl;
    }
}
