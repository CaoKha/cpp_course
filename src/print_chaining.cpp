#include <iostream>

struct list_element
{
    int d;
    list_element *next; // pointer next point to the structure itself
    list_element(int n = 0, list_element *ptr = nullptr) : d(n), next(ptr){};
};
class list
{
private:
    list_element *head;
    list_element *cursor;

public:
    list() : head(nullptr), cursor(nullptr) {}
    list(list_element* lst){};
    list(const list& lst);
    void prepend(int n); // insert at front value n
    int get_element() { return cursor->d; }
    void advance() { cursor = cursor->next; }
    void print();
};

void list::prepend(int n)
{
    if (head == nullptr) // empty list case
        cursor = head = new list_element(n, head);
    else
        head = new list_element(n, head);
}

void list::print()
{
    list_element *h = head;
    while (h != nullptr) // nullptr is at the end of the list
    {
        std::cout << h->d << ",";
        h = h->next;
    }
    std::cout << "###" << std::endl;
};

// copy constructor
list::list(const list& lst)
{
    if (lst.head == nullptr)
    {
        head = nullptr;
        cursor = nullptr;
    }
    else
    {
        cursor = lst.head;
        list_element *h = new list_element();
        list_element *previous;
        head = h;
        h->d = lst.head->d;
        previous = h;

        for (cursor = lst.head; cursor != 0;)
        {
            h = new list_element();
            h->d = cursor->d;
            previous->next = h;
            cursor = cursor->next;
            previous = h;
        }
        cursor = head;
    }
}

int main()
{
    list a, b;
    a.prepend(9);
    a.prepend(8);
    std::cout << "list a" << std::endl;
    a.print();
    for (int i = 0; i < 40; ++i)
        b.prepend(i * i);
    std::cout << "list b" << std::endl;
    b.print();
    list c(b);
    std::cout << "list c" << std::endl;
    c.print();
}

/* output:
PS C:\Users\nguye\Documents\code\cpp_course> .\src
\print_chaining.exe
list a 
8,9,###
list b 
1521,1444,1369,1296,1225,1156,1089,1024,
961,900,841,784,729,676,625,576,529,484,
441,400,361,324,289,256,225,196,169,144,
121,100,81,64,49,36,25,16,9,4,1,0,###
*/
