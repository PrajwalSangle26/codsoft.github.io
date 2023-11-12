#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

void AddTask(std::vector<Task>& taskList, const std::string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    taskList.push_back(newTask);
    cout << "Task added successfully.\n";
}

void ViewTasks(const std::vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "No tasks in the list.\n";
    } else {
        cout << "Task List:\n";
        for (size_t i = 0; i < taskList.size(); ++i) {
        cout << "[" << (taskList[i].completed ? "X" : " ") << "] " << taskList[i].description << "\n";
        }
    }
}

void MarkTaskAsCompleted(std::vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList[taskIndex].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

void RemoveTask(std::vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList.erase(taskList.begin() + taskIndex);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

int main() {
    vector<Task> taskList;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();
                getline(std::cin, taskDescription);
                AddTask(taskList, taskDescription);
                break;
            }
            case 2:
                ViewTasks(taskList);
                break;
            case 3: {
                int taskIndex;
                cout << "Enter the task index to mark as completed: ";
                cin >> taskIndex;
                MarkTaskAsCompleted(taskList, taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the task index to remove: ";
                cin >> taskIndex;
                RemoveTask(taskList, taskIndex);
                break;
            }
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
