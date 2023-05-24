#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include<vector>
#include<queue>
#include<memory> //ʹ��memory���е� ����ָ�� shared_ptr
#include<atomic>  //ԭ������ 
#include<mutex>  //������
#include<condition_variable> //�߳�ͨ����������
enum  class PollMode{
	MODE_FIXED,//�̶��߳���
	MODE_CACHED,//��̬�����߳���
};

class Task {
public:
	virtual void run() = 0;  //���麯��

};
class Thread {

};
class ThreadPool {
public:
private:
	std::vector<Thread*> thread_vector_;//����̵߳ı�
	size_t init_thread_size;//��ʼ�߳�����
	size_t max_thread_size;//�߳���ֵ
	PollMode poll_mode;
	std::queue<std::shared_ptr<Task>> task_queue_;//�������
	std::atomic_int task_size;//ԭ������  �������� 0-n
	int task_queue_max_size;//���������ֵ 
	std::mutex task_queue_mutex;//������е��� ��֤��������̰߳�ȫ
	//����2������������֤ �����
	std::condition_variable task_queue_not_full;//����ز���
	std::condition_variable task_queue_not_empty;//����ز���
};
#endif 
