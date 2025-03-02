#include "header.h"

int main()
{
    TaskManager manager;

    
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    manager.registerUser(username, password);

   
    if(manager.login(username, password))
    {
        std::cout << "Login Successful!" << std::endl;
    }
    else
    {
        std::cout << "Login Failed!" << std::endl;
        return 0;
    }

  
    std::string  task_id = "1", user_id = "1";
    int priority = 2;
    std::string title = "Task 1", description = "Task 1 Description", deadline = "2025-03-01", category = "Work";
    manager.add_task(task_id, user_id, title, description, deadline, category, static_cast<PRIO>(priority));

  
    manager.display_task(task_id);

   
    Task updated_task("Updated Task", "Updated Description", "2025-03-05", "Personal", static_cast<PRIO>(1));
    manager.edit_task(title, updated_task);

    
    manager.display_task(task_id);

    
    manager.delete_task(title);
    std::cout << "Task deleted." << std::endl;

   
    manager.display_task(task_id);

   
    manager.logout(username);
    std::cout << "Logged out." << std::endl;

    return 0;
}

