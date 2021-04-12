#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int find_network_endpoint(int startNodeId, std::vector<int> &fromIds, std::vector<int> &toIds)
{
    int current_position = startNodeId;
    int next_position;
    std::vector<int> route;
    route.push_back(current_position);
    bool at_the_end = false;
    while (at_the_end == false)
    {
        // search for starting node
        for (int i = 0; i < fromIds.size(); i++)
        {
            if (fromIds[i] == current_position) // if found
            {
                next_position = toIds[i]; // go to next node
                //check the next position if it is already on the route (loop detect)
                for (std::vector<int>::iterator it = route.begin(); it != route.end(); it++)
                {
                    if (*it == next_position)
                        return current_position;
                }
                std::cout << "curr= " << current_position << ", next= " << next_position << std::endl;
                // if check is success go to that position
                current_position = next_position;
                route.push_back(current_position); // register the position

                break; // break the for loop, researching from the beginning
            }
            else if ((fromIds[i] != current_position) && (i == (fromIds.size() - 1))) // in case we did not find the node, we are at the ending node
            {
                at_the_end = true;
            }
        }
    }
    return current_position;
}

int main()
{ 
    int startNodeId = 5;
    std::vector<int> fromIds{1, 7, 3, 4, 6, 2, 9};
    std::vector<int> toIds{3, 3, 4, 6, 9, 6, 5};
    // int std_out_fd = dup(1); // 0: stdin, 1: stdout, 2: stderr
    // dup2(2,1);
    int endPointId = find_network_endpoint(startNodeId, fromIds, toIds);
    // dup2(std_out_fd,1);
    std::cout << endPointId << std::endl;
}
