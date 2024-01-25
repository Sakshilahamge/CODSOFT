#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string task;
    bool completed;
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& task) {
        tasks.push_back({task, false});
        std::cout << "Task \"" << task << "\" added to the list." << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "Tasks:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::string status = tasks[i].completed ? "Completed" : "Pending";
                std::cout << i + 1 << ". " << tasks[i].task << " - " << status << std::endl;
            }
        }
    }

    void markCompleted(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task \"" << tasks[taskIndex - 1].task << "\" marked as completed." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            Task removedTask = tasks[taskIndex - 1];
            tasks.erase(tasks.begin() + taskIndex - 1);
            std::cout << "Task \"" << removedTask.task << "\" removed from the list." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList todoList;

    while (true) {
        std::cout << "\nTO-DO LIST MANAGER" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskInput;
                std::cout << "Enter the task: ";
                std::cin.ignore(); 
                std::getline(std::cin, taskInput);
                todoList.addTask(taskInput);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                std::cout << "Enter the task index to mark as completed: ";
                std::cin >> taskIndex;
                todoList.markCompleted(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                std::cout << "Enter the task index to remove: ";
                std::cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting the to-do list manager. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        }
    }

    return 0;
}
