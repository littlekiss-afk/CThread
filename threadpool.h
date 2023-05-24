#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include<vector>
#include<queue>
#include<memory> //使用memory库中的 智能指针 shared_ptr
#include<atomic>  //原子类型 
#include<mutex>  //互斥锁
#include<condition_variable> //线程通信条件变量
enum  class PollMode{
	MODE_FIXED,//固定线程数
	MODE_CACHED,//动态增长线程数
};

class Task {
public:
	virtual void run() = 0;  //纯虚函数

};
class Thread {

};
class ThreadPool {
public:
private:
	std::vector<Thread*> thread_vector_;//存放线程的表
	size_t init_thread_size;//初始线程数量
	size_t max_thread_size;//线程阈值
	PollMode poll_mode;
	std::queue<std::shared_ptr<Task>> task_queue_;//任务队列
	std::atomic_int task_size;//原子类型  任务数量 0-n
	int task_queue_max_size;//任务队列阈值 
	std::mutex task_queue_mutex;//任务队列的锁 保证任务队列线程安全
	//定义2个条件变量保证 任务池
	std::condition_variable task_queue_not_full;//任务池不满
	std::condition_variable task_queue_not_empty;//任务池不空
};
#endif 
