// call waiting demo
#include <iostream>
#include <string>
#include "queue.hpp"

int main(){
    //this system aim to controlling the system of applying a job and this system will
    //storing candidate ID_card and name will have to interview  
    
    // Create a queue with int ID and string name
    queue<int, std::string> day;
    // Enqueue candidates
    day.push(015557, "heng");
    day.push(148920, "vuthy");
    day.push(890275, "theara");

    std::cout << "All candidates:\n";
    day.display();

    // Process first candidate 
    std::cout << "\nProcessing first candidate...\n";
    day.pop();
    
    std::cout << "\nRemaining candidates:\n";
    day.display();

    return 0;
}
