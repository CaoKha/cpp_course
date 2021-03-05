#include <iostream>

int sum_int(int a, int b);

int sum_int(int a, int b){
    int c = a+b;
    return c;
};
int main() {
   
   std::cout<< "1 + 2 = "<< sum_int(1,2) << std::endl;
}
