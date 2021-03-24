#include <iostream> 

class Algorithm {
    public:
    static int findLargest(int numbers[],int length){
        int max = numbers[0];
        for (int i = 1; i<length;i++)
        {
            if (max < numbers[i])
                max = numbers[i];
        }
        return max;
    }
};

int main() {
    int numbers[] = {1, 2, 3 , -28, 200, 5};
    int result = Algorithm::findLargest(numbers, 6);
    std::cout << result <<std::endl;
}