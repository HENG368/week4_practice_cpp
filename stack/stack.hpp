// Array Stack
#include <iostream>
#include <string>

using namespace std;

class stack
{
private:
    char *arr;
    int size;
    int top;
public:
    stack(int cap) {
        size = cap;
        arr = new char[cap];
        top = -1;
    }

    void insert(string input) {
        for (int i = 0; i < input.size(); i++)
        {
            // Check for overflow 
            if (top == size - 1)
            {
                cout << "Overflow, ignoring input" << endl;
                return;
            }
            
            arr[++top] = input[i];
        }
    }

    bool isBalanced() {
        for (int i = 0; i < size; i++)
        {
            switch (arr[i])
            {
            // For () brackets
            case int(41):
                for (int j = i; j > 0; j--)
                {
                    if (arr[j] == int(40))
                    {
                        arr[i] = arr[j] = '\0';
                    } else if (arr[j] == int(91) || arr[j] == int(123))
                    {
                        return false;
                    }  
                }
                break;
            // For [] brackets
            case int(93):
                for (int j = i; j > 0; j--)
                {
                    if (arr[j] == int(91))
                    {
                        arr[i] = arr[j] = '\0';
                    } else if (arr[j] == int(40) || arr[j] == int(123))
                    {
                        return false;
                    }  
                }
                break;
            // For {} brackets
            case int(125):
                for (int j = i; j > 0; j--)
                {
                    if (arr[j] == int(123))
                    {
                        arr[i] = arr[j] = '\0';
                    } else if (arr[j] == int(40) || arr[j] == int(91))
                    {
                        return false;
                    }  
                }
                break;    
            }
        }
        return true;
    }
};
