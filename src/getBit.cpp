#include <iostream>

class Answer{
    public:
    static int getBit(unsigned int value, int pos){
        int result = value >> pos;
        int LSB = result & 1;
        return LSB;
    }
};

int main(){
    std::cout << Answer::getBit(1005,0) << std::endl;
    std::cout << Answer::getBit(1005,1) << std::endl;
    std::cout << Answer::getBit(1005,9) << std::endl;
}