#include "header.h"


Task::Task(){}

Task:: Task(const std::string& title, const std::string& description,
	    const std::string& deadline,const std::string& category, int priority)
           :m_title(title), m_description(description), m_deadline(deadline),
            m_category(category), prio(static_cast<PRIO>(priority)){}

Task::Task(const Task& other)
	  : m_task_id(other.m_task_id), m_user_id(other.m_user_id), m_title(other.m_title),
	    m_description(other.m_description),m_deadline(other.m_deadline),
	    m_category(other.m_category), prio(other.prio),status(other.status){}

Task::Task(Task&&other)noexcept
       	  :m_task_id(std::move(other.m_task_id)), m_user_id(std::move(other.m_user_id)),
           m_title(std::move(other.m_title)),m_description(std::move(other.m_description)),
	   m_deadline(std::move(other.m_deadline)),m_category(std::move(other.m_category)),
           prio(std::move(other.prio)),status(std::move(other.status)){}

Task::~Task(){}
	
Task::Task& operator=(Task& other)
{	
	if(this != &other)
	{
		title = other.title;
		description = other.description;
		deadline = other.deadline;
		category = other.category;
		priority = other.priority;
	}
	return *this;
}
Task::Task& operator=(Task&& other)
{
	if(this != &other)
	{
		title = std::move(other.title);
		description = std::move(other.description);
		deadline = std::move( other.deadline);
                category = std::move(other.category);
                priority = std::move(other.priority);

	}
	return *this;

}

void Task:: editTask(const std::string& newTitle, const std::string& newDescription,
	const std::string& newDeadline,const std::string& newCategory, int newPriority)
{
	m_title = newTitle;
	m_description = newDescription;
       	m_deadline = newDeadline;
	m_category = newCategory;
	prio = static_cast<PRIO>(newPriority);
}

void Task::set_status(STATUS n_status)
{	
     status = n_status;

}
void Task::set_prio(PRIO n_prio)
{
	prio = n_prio;
}
void Task:: display_info()const
{

	std::cout<<"title"<<m_title<<std::endl;
	std::cout<<"description"<<m_description<<std::endl; 
	std::cout<<"deadline"<<m_deadline<<std::endl; 
	std::cout<<"category"<<m_category<<std::endl; 
	std::cout<<"prio"<<prio<<std::endl; 
	std::cout<<"status"<<status<<std::endl; 
}
std::string Task::get_task_id()const
{
	return m_task_id;
}
std::string Task::get_title() const
{
	return m_title;
}


