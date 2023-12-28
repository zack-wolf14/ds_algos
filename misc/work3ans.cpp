#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
class WorkerTask
{
public:
    void Run()
    {
        while (!shutdown_)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            ++endless_counter;
            std::cout << "Counter: " << WorkerTask::GetCounter() << "\n";
        }
    }
    void RequestShutdown()
    {
        shutdown_ = true;
    }
    static unsigned int GetCounter()
    {
        return endless_counter;
    }

    bool shutdown(){return shutdown_;}
private:
    bool shutdown_ = false;
    static unsigned int endless_counter;
};
unsigned int WorkerTask::endless_counter = 0;
class Worker
{
public:
    Worker()
    {
        auto x = std::make_unique<WorkerTask>();
        worker_thread_ = std::thread([&]() { x->Run(); });
        std::this_thread::sleep_for(std::chrono::seconds(5));
    
    }
    ~Worker()
    {   if (worker_thread_.joinable())
        {
            worker_thread_.join();
    }   }

private:
    std::thread worker_thread_;
};
int main()
{
    Worker worker;
    WorkerTask task;
    
    return 0;
}