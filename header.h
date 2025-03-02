#include <iostream>
#include <vector>
#include <string>

enum PRIO{
        LOW = 0,
	MID = 1,
	HIGH = 2,
	URG = 99,

};
enum STATUS
{
	NOT_STARTED = 0,
	IN_PROGRESS = 1,
	COMPLETED = 2,
};

class Task
{

	private:
		std::string m_task_id;
		std::string m_user_id;
		std::string m_title;
		std::string m_description;
		std::string m_deadline;
		std::string m_category;
		PRIO prio;
		STATUS status;

	public:
		Task(); 
		Task( const std::string& title, const std::string& description, const std::string& deadline,const std::string& category, int priority);
		Task(const Task& other);
		Task(Task&& other) noexcept;
		~Task();
		Task& operator=(Task& other);
		Task& operator=(Task&& other);
		Task& operator ==(Task& b);
		Task& operator !=(Task& c);


		void editTask(const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, 
                              const std::string& newCategory, int newPriority);

		void set_status(STATUS n_status);
		void set_prio(PRIO n_prio);
		void display_info() const;
		std::string get_task_id() const;
		std::string get_title() const;
	
};
class User
{
        private:
                std::string m_id;
                std::string m_name;
                std::string m_password;
                std::vector<Task*> m_tasks;
                bool is_logged;

        public:
                
		User(const std::string& username, const std::string& password);
		User(const User& other); 
		User(User&& other) noexcept;
		~User();
		User& operator= (const User& other);
		User& operator=(const User&& other);
		void add_task(Task*task);
		void deleteTask(const std::string& title);
		void editTask(const std::string& title, const Task& updatedTask);
		void listTasks() const;
		Task* searchTask(const std::string& title); 
		void login();
		void logout();
		bool v_pas(const std::string& password);
		std::string get_name() const;
		void set_logged_in(bool logged_in); 
		 std::string get_user_id() const;


};
class TaskManager
{
	private:
		std::vector <User*> m_users;
		std::vector <Task*> m_all_tasks;
	public:

		TaskManager(); 
		TaskManager(const TaskManager& other);
		TaskManager(TaskManager&& other) noexcept;
		~TaskManager(); 
		void registerUser(const std::string& username, const std::string& password);
		bool login(const std::string& username, const std::string& password);
		void logout(const std::string& username);
		
		void display_task(const std::string& task_id);
		void edit_task(const std::string& title, const Task& updatedTask);
		void delete_task(const std::string& title); 
		void add_task(std::string task_id, std::string user_id,std::string title ,std::string description,std::string deadline,  std::string category,PRIO prio);
		
};
