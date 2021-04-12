#include <iostream>
#include <cstring>
typedef struct {
    char a;
    int b;
} mystruct;

int main() {
    mystruct s1;
    s1.a = 'a';
    s1.b = 2;

    mystruct s2;
    s2.a = 'a';
    s2.b = 2;

    int cmp = memcmp(&s1,&s2,sizeof(mystruct));
    std::cout << cmp << std::endl;
}