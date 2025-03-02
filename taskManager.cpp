#include "header.h"

TaskManager::TaskManager(){}

TaskManager::TaskManager(const TaskManager& other)
	                 :m_users(other.m_users),m_all_tasks(other.m_all_tasks){}

TaskManager::TaskManager(TaskManager&& other) noexcept
			:m_users(std::move(other.m_users)),m_all_tasks(std::move(other.m_all_tasks)){}

TaskManager::~TaskManager()
{
	for(int i =0; i< m_users.size();i++)
	{
		delete m_users[i];
	}
	for(int i =0; i< m_all_tasks.size();i++)
        {
                delete m_all_tasks[i];
        }

}

void TaskManager::registerUser(const std::string& username, const std::string& password)
{
	for(int i =0; i<m_users.size();i++)
	{
		 if(m_users[i]->get_name()==username)
		 {
			 std::cout<<"USER EXIST"<<std::endl;
			 return;
		 }
	}
		 m_users.push_back(new User(username,password));

	
}
bool TaskManager::login(const std::string& username, const std::string& password)
{
	for(int i = 0; i<m_users.size();i++)
	{
		if(m_users[i]->get_name()==username && m_users[i]->v_pas(password))
		{
			std::cout<<"LOGIN"<<std::endl;
			return true;
		}
	}
		
	return false;

}
void TaskManager::logout(const std::string& username)
{
	 for(int i = 0; i<m_users.size();i++)
        {
                if(m_users[i]->get_name()==username)
		{
			m_users[i]->set_logged_in(false);
			std::cout<<"LOGOUT"<<std::endl;
			return;

		}
	}
}
void TaskManager::display_task(const std::string& task_id)
{
	for(int i =0;i<m_all_tasks.size();i++)
	{
		if(m_all_tasks[i]->get_task_id()==task_id)
		{
			m_all_tasks[i]->display_info();
			return;
		}
	}

}
void TaskManager::edit_task(const std::string& title, const Task& updatedTask)
{
	for(int i=0;i< m_all_tasks.size();i++)
	{
		if(m_all_tasks[i]->get_title()==title)
		{
			m_all_tasks[i]=new Task(updatedTask);
			return;
		}
	}

}
void TaskManager::delete_task(const std::string& title)
{
	for(int i =0;i<m_all_tasks.size();i++)
	{
		if(m_all_tasks[i]->get_title()==title)
		{
			delete m_all_tasks[i];
			m_all_tasks.erase(m_all_tasks.begin()+i);
			return;

		}
	}

}
void TaskManager::add_task(std::string task_id, std::string user_id,std::string title ,std::string description,std::string deadline,std::string category,PRIO prio)
{
	Task* nTask = new Task(title,description,deadline,category,prio);
	m_all_tasks.push_back(nTask);
	for(int i = 0; i< m_users.size();i++)
	{
		if(m_users[i]->get_user_id()==user_id)
		{
			m_users[i]->add_task(nTask);
			break;
		}
	}
}
