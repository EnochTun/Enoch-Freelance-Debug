#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

struct Task
{
    int id;
    std::string name;
    int64_t expiresAt;
};

size_t RemoveExpiredTasks(
    std::vector<Task>& tasks,
    int64_t currentTime
)
{
    size_t removed = 0;

    for (auto it = tasks.begin(); it != tasks.end(); ++it)
    {
        if (it->expiresAt <= currentTime)
        {
            tasks.erase(it);
            ++removed;
        }
    }

    return removed;
}

int main()
{
    std::vector<Task> tasks =
    {
        { 1, "Backup", 100 },
        { 2, "Update", 120 },
        { 3, "Cleanup", 90 },
        { 4, "Report", 150 },
        { 5, "Sync", 80 }
    };

    size_t removed = RemoveExpiredTasks(tasks, 100);

    std::cout << "Removed: " << removed << '\n';
    std::cout << "Remaining: " << tasks.size() << '\n';

    return 0;
}