#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


// ������������ ��� ��� ������� ������
enum class TaskStatus {
  NEW,          // �����
  IN_PROGRESS,  // � ����������
  TESTING,      // �� ������������
  DONE          // ���������
};

// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // �������� ���������� �� �������� ����� ����������� ������������
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
	  return tasks.at(person);
  }

  // �������� ����� ������ (� ������� NEW) ��� ����������� �������������
  void AddNewTask(const string& person) {
	  auto& task_info = tasks[person];
	  ++task_info[TaskStatus::NEW];
  }

  // �������� ������� �� ������� ���������� ����� ����������� ������������,
  // ����������� ��. ����
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count) {
	  TasksInfo upgrade;
	  TasksInfo updated;
	  TasksInfo untouched;

	  auto& tasks_info = tasks[person];
	  for(auto& item : tasks_info) {
		  if(item.first == TaskStatus::NEW) {
			  if(item.second > 0) {
				  int status_count = item.second;
				  while(status_count > 0 && task_count) {
					  ++updated[TaskStatus::IN_PROGRESS];
					  ++upgrade[TaskStatus::IN_PROGRESS];
					  --status_count;
					  --task_count;
				  }
				  if(status_count > 0) {
					  untouched[TaskStatus::NEW] += status_count;
					  upgrade[TaskStatus::NEW] += status_count;
				  }
			  }
		  }

		  if(item.first == TaskStatus::IN_PROGRESS) {
			  if(item.second > 0) {
				  int status_count = item.second;
				  while(status_count > 0 && task_count) {
					  ++updated[TaskStatus::TESTING];
					  ++upgrade[TaskStatus::TESTING];
					  --status_count;
					  --task_count;
				  }

				  if(status_count > 0) {
					  untouched[TaskStatus::IN_PROGRESS] += status_count;
					  upgrade[TaskStatus::IN_PROGRESS] += status_count;
				  }
			  }
		  }

		  if(item.first == TaskStatus::TESTING) {
			  if(item.second > 0) {
				  int status_count = item.second;
				  while(status_count > 0 && task_count) {
					  ++updated[TaskStatus::DONE];
					  ++upgrade[TaskStatus::DONE];
					  --status_count;
					  --task_count;
				  }

				  if(status_count > 0) {
					  untouched[TaskStatus::TESTING] += status_count;
					  upgrade[TaskStatus::TESTING] += status_count;
				  }
			  }
		  }

		  if(item.first == TaskStatus::DONE) {
			  if(item.second > 0) {
				upgrade[TaskStatus::DONE] += item.second;
			  }
		  }


	  }

	  tasks[person] = upgrade;
	  return make_tuple(updated, untouched);
  }

private:
  map<string, TasksInfo> tasks;
};

void PrintTasksInfo(TasksInfo tasks_info) {
	cout << tasks_info[TaskStatus::NEW] << " new tasks, "
			<< tasks_info[TaskStatus::IN_PROGRESS]
			<< " tasks in progress, " << tasks_info[TaskStatus::TESTING]
			<< " tasks are being tested, " << tasks_info[TaskStatus::DONE]
			<< " tasks are done" << endl;
}
