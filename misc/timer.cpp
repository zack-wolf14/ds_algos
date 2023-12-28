#include <iostream>
#include <chrono>
#include <memory>
#include <thread>

using namespace std;

int main()
{   
    bool shutdown = true;
    int endless_counter=0;
    while(shutdown)
    {   
        
        this_thread::sleep_for(chrono::milliseconds(300));
        ++endless_counter;
        // shutdown=false;
        cout << "Counter: " << endless_counter << "\n";
    }    
    return 0;
}