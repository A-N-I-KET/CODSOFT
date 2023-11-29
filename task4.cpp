#include <iostream>
#include <vector>
#include <iomanip>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoListManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task \"" << description << "\" added successfully.\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks found.\n";
        } else {
            std::cout << std::setw(4) << "ID" << std::setw(15) << "Status" << "Description\n";
            std::cout << "--------------------------------------\n";

            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << std::setw(4) << i + 1 << std::setw(15) << (tasks[i].completed ? "Completed" : "Pending") << tasks[i].description << "\n";
            }
        }
    }

    void markTaskAsCompleted(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid task index. Please try again.\n";
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            std::string removedTask = tasks[taskIndex - 1].description;
            tasks.erase(tasks.begin() + taskIndex - 1);
            std::cout << "Task \"" << removedTask << "\" removed successfully.\n";
        } else {
            std::cout << "Invalid task index. Please try again.\n";
        }
    }
};

int main() {
    TodoListManager todoManager;

    while (true) {
        std::cout << "\nOptions:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";

        int choice;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter the task description: ";
                std::cin.ignore(); // Clear buffer
                std::getline(std::cin, taskDescription);
                todoManager.addTask(taskDescription);
                break;
            }
            case 2:
                todoManager.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                std::cout << "Enter the index of the task to mark as completed: ";
                std::cin >> taskIndex;
                todoManager.markTaskAsCompleted(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                std::cout << "Enter the index of the task to remove: ";
                std::cin >> taskIndex;
                todoManager.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting the to-do list manager. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
