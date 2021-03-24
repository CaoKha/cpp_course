 #include <string>
 #include <cctype>
 #include <algorithm>
 #include <iostream>

 using namespace std;

 class Answer
 {
     public:
     static bool isTwin(string a, string b)
     {
         transform(a.begin(),a.end(),a.begin(),[](unsigned char c){ return tolower(c);});
         transform(b.begin(),b.end(),b.begin(),[](unsigned char c){ return tolower(c);});
         sort(a.begin(),a.end());
         sort(b.begin(),b.end());
         if (a.compare(b) == 0) return true;
         else return false;
     }
 };

 int main() {
     cout << boolalpha << Answer::isTwin("abc","cba") << endl;
     cout << boolalpha <<Answer::isTwin("Hello", "World") << endl;
     cout << boolalpha <<Answer::isTwin("LookOut", "OutLook") << endl;
 }