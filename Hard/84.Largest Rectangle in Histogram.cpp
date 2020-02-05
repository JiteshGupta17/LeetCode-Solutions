#include <bits/stdc++.h>
using namespace std;

int MaxAreaInHistogram(vector<int> arr)
{
    // arr.push_back(-1); This can be done to prevent the outer while loop

    //stack will hold the indices
    stack<int> s;

    int maxArea = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            s.push(i);
            continue;
        }

        int top = s.top();
        if (arr[i] >= arr[top])
        {
            s.push(i);
        }
        else {

            //Calculating curArea at each removal
            while (arr[i] < arr[top])
            {
                int curArea = 0;
                s.pop();

                if (s.empty())
                {
                    curArea = arr[top] * i;
                    maxArea = max(curArea, maxArea);
                    break;
                }
                else {
                    curArea = arr[top] * (i - s.top() - 1);
                    maxArea = max(curArea, maxArea);
                }
                top = s.top();
            }

            // pushing the element at each its correct position
            s.push(i);
        }
    }

    // Might be stack is not empty
    while (!s.empty())
    {
        int i = arr.size();
        int top = s.top();
        int curArea = 0;
        s.pop();

        if (s.empty())
        {
            // Smallest element
            curArea = arr[top] * i;
        }
        else {
            curArea = arr[top] * (i - s.top() - 1);
        }

        maxArea = max(curArea, maxArea);
    }

    return maxArea;
}


int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};

    cout << MaxAreaInHistogram(arr);
}
