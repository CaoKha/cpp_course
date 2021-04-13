#include <iostream> 
#include <vector>

void removeElement(std::vector<int> &arr, int index)
{

    for (int i = index; i < arr.size() - 1; i++)
        arr[i] = arr[i+1];
    arr.pop_back();
}
void fusion(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i];
        for (auto j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                removeElement(arr,j);
                arr[i]++;
                j--; // if an element is removed, the next position becomes the current position 
            }
        }
        if (temp != arr[i]) i=-1; // if current position is recently changed, reset the loop
    }
}

int magic(std::vector<int> stones)
{
    fusion(stones);
    return stones.size();
}



int main() {
    std::vector<int> v{1,1,3,2,1,1};
    std::cout << magic(v) <<std::endl;
    v={1,1,5,2,3,4};
    std::cout << magic(v) <<std::endl;
    v={1,1,2,2,3,3};
    std::cout << magic(v) <<std::endl;
}