#include <iostream>
#include <vector>
#include <algorithm>

class TodoList {
private:
    std::vector<std::string> tasks;

public:
    // Function to add a task
    void addTask(const std::string& task) {
        tasks.push_back(task);
        std::cout << "Task added successfully!\n";
    }

    // Function to view all tasks
    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks to display!\n";
        } else {
            std::cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i] << std::endl;
            }
        }
    }

    // Function to delete a task
    void deleteTask(int index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task index!\n";
        } else {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task deleted successfully!\n";
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    std::string task;
    
    std::cout << "Simple Todo List Manager\n";

    while (true){
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cin.ignore();
                std::cout << "Enter task: ";
                std::getline(std::cin, task);
                todoList.addTask(task);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                int index;
                std::cout << "Enter task index to delete: ";
                std::cin >> index;
                todoList.deleteTask(index);
                break;
            case 4:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}

