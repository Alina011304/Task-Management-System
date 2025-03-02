#include "header.h"
User::User(const std::string& username, const std::string& password)
	   :m_name(username),m_password(password){} 

User::User(const User& other)
	   :m_id(other.m_id),m_name(other.m_name),m_password(other.m_password),
	    m_tasks(other.m_tasks),is_logged(other.is_logged){}

User::User(User&&other)noexcept
	   :m_id(std::move(other.m_id)),m_name(std::move(other.m_name)),
	    m_password(std::move(other.m_password)),is_logged(std::move(other.is_logged)){}
User::User& operator=(const User& other)
{
	if(this != &other)
	{
		m_id = other.m_id;
		m_name = other.m_name;
		m_password = other.m_password;
		is_logged = other.is_logged;
	}
	return *this;
}
User::User& operator=(const User&& other)
{
        if(this != &other)
        {
                m_id =std::move( other.m_id);
                m_name = std::move(other.m_name);
                m_password = std::move(other.m_password);
                is_logged = std::move(other.is_logged);
        }
        return *this;
}


User::~User(){}

void User::add_task(Task*task)
{
	m_tasks.push_back(task);
}
void User::deleteTask(const std::string& title)
{
	for(int i = 0; i < m_tasks.size();i++)
	{
		if(m_tasks[i]->get_title()==title)
		{
			delete m_tasks[i];
			m_tasks.erase(m_tasks.begin()+i);
			std::cout<<title<<std::endl;
			return;
		}
	}
}
void User::editTask(const std::string &title, const Task& updatedTask)
{
	for(int i =0; i<m_tasks.size();i++)
	{
		if(m_tasks[i]->get_title()==title)
		{
			delete m_tasks[i];
			m_tasks[i]=new Task(updatedTask);
		}
	}

}

void User::listTasks() const
{
	std::cout<<m_name<<std::endl;
	for(int i = 0; i<m_tasks.size();i++)
	{
		m_tasks[i]->display_info();
	}
}
Task* User:: searchTask(const std::string& title)
{
	for(int i =0; i< m_tasks.size();i++)
	{
		if(m_tasks[i]->get_title()==title)
		{
			return m_tasks[i];
		}
	}
	return nullptr;
}
void User::login()
{
	is_logged=true;	
}
void User::logout()
{
	is_logged = false;
}
bool User::v_pas(const std::string& password)
{
	if(password.length()<8)
	{
		std::cout<<"ERROR"<<std::endl;
		return false;
	}
	bool u = false;
	bool l = false;
	bool d = false;
	for(int i =0; i<password.length();i++)
	{
		if(std::isupper(password[i]))
		{
			u = true;
		}
		if(std::islower(password[i]))
                {
                        l = true;
                }
	       if(std::isdigit(password[i]))
                {
                        d = true;
                }
	}
	if(!u)
	{
		std::cout<<"ERROR"<<std::endl;
		return false;
	}
	  if(!l)
        {
                std::cout<<"ERROR"<<std::endl;
                return false;
        }  if(!d)
        {
                std::cout<<"ERROR"<<std::endl;
                return false;
        }
	return true;
}
 std::string User::get_name() const
{
	return m_name;
}
void User::set_logged_in(bool logged_in) {
    is_logged = logged_in;
}
std::string User::get_user_id()const
{
        return m_id;
}

