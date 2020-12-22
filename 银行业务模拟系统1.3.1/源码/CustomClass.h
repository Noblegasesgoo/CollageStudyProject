#pragma once
#ifndef HACKER_H_//#ifendif��ֹ��ΰ���һ���ļ�
#define HACKER_H_ 

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

//-------------------------------------------------- ������ �������ṩ���� --------------------------------------------------
class Bank
{
	private:
		int bank_open_time;//���п�ʼӪҵʱ�䣨Сʱ�� 
		int bank_closed_time;//���н���Ӫҵʱ�䣨Сʱ�� 
		int bank_all_time;//������Ӫҵʱ�䣨���ӣ� = (���н���Ӫҵʱ�䣨Сʱ��- ���п�ʼӪҵʱ�䣨Сʱ��*60) 
	
		int business_start_time;//��ʼ����ҵ��ʱ�䣨���ӣ� 
		int business_end_time;//��һ��ҵ�����Ľ���ʱ�䣨���ӣ� 
	
		int save_money_num;//���ҵ��������
		int get_money_num;//ȡ��ҵ�������� 
		int report_loss_of_num;//��ʧҵ�������� 
		int refund_num;//����ҵ�����������
	
		int client_stay_bank_time;//�˿Ͷ������е�ʱ�䣨���ӣ�
		bool windows_empty;//�����Ƿ�Ϊ�գ�true���ա�false�����գ� 
	
	public:
		//�޲γ�ʼ�� 
		Bank()
		{
			
		}
		
		//�вγ�ʼ�� 
		Bank(int open_time, int closed_time)
		{
			this->bank_open_time = open_time;
			this->bank_closed_time = closed_time;
			this->bank_all_time = this->bank_closed_time * 60 - this->bank_open_time * 60; //�������н���Ӫҵʱ�䣨���ӣ� 
	
			this->business_start_time = bank_open_time * 60;//��ʼ����ҵ��ʱ���ʱ��ʼ��Ϊ���п���ʱ�䣨���ӣ� 
			this->business_end_time = bank_open_time * 60;//��һ��ҵ�����Ľ���ʱ���ʼ�������ڴ�ʱ��û����ҵ�����Գ�ʼ��Ϊ����ʱ�䣨���ӣ� 
			
			this->save_money_num = 0;//���ҵ��������
			this->get_money_num = 0;//ȡ��ҵ�������� 
			this->report_loss_of_num = 0;//��ʧҵ�������� 
			this->refund_num = 0;//����ҵ�����������
			
			this->windows_empty = false;//��ʼ������Ϊ����Ҳ����δ���ŵ�״̬ 
			
			//�û�����ʱ�� = �û��뿪��ʱ�䣨���ڷ���ǰ�ͻ�����ʱ�䣩- �û������ʱ��
			this->client_stay_bank_time = 0; 
		}
	
		//�����Ե�get����
		int getBankAllTime()//�õ���ʱ�䳣�� 
		{
			return this->bank_all_time;
		}
	
		bool getWindowsEmpty()//�õ������Ƿ�Ϊ�ճ��� 
		{
			return this->windows_empty;
		}
	
		int getClientStayBankTime()//�õ��ͻ��ڸô��ڵĶ�������ʱ�� 
		{
			return this->client_stay_bank_time;
		}
		
		int getSaveMoneyNum()
		{
			return this->save_money_num;
		}
		
		int getGetMoneyNum()
		{
			return this->get_money_num;
		}
		
		int getReportLossOfNum()
		{
			return this->report_loss_of_num;
		}
		
		int getRefundNum()
		{
			return this->refund_num;
		}
		
		int getBankOpenTime()
		{
			return this->bank_open_time;
		}
	
		int getBankClosedTime()
		{
			return this->bank_closed_time;
		}
	
		int getBusinessStartTime()
		{
			return this->business_start_time;
		}
	
		int getbusinessEndTime()
		{
			return this->business_end_time;
		}
	
		//�����Ե�set����
		void setBankAllTime(int time)//������ʱ�䳣�� 
		{
			this->bank_all_time = time;
		}
	
		void setWindowsEmpty(bool status)//���ô����Ƿ�Ϊ�ճ���
		{
			this->windows_empty = status;
		}
	
		void setClientStayBankTime(int time)//���ÿͻ��ڸô��ڶ�������ʱ�� 
		{
			this->client_stay_bank_time += time;
		}
		
		void setSaveMoneyNum()
		{
			this->save_money_num += 1;
		}
		
		void setGetMoneyNum()
		{
			this->get_money_num += 1;
		}
		
		void setReportLossOfNum()
		{
			this->report_loss_of_num += 1;
		}
		
		void setRefundNum()
		{
			this->refund_num += 1;
		}
		
		void setBankOpenTime(int time)
		{
			this->bank_open_time = time;
		}
	
		void setBankClosedTime(int time)
		{
			this->bank_closed_time = time;
		}
	
		void setBusinessStartTime(int time)
		{
			this->business_start_time = time;
		}
	
		void setbusinessEndTime(int time)
		{
			this->business_end_time = time;
		}
};

//--------------------------------------------------�˿��� ��������ʼ�������Ķ��� --------------------------------------------------
class Client
{
	private:
		int client_ID;//�˿ͱ�ţ���������� 
		int client_arrive_time_hour;//�˿͵������е�ʱ�䣨Сʱ�� 
		int client_arrive_time_minutes;//�˿͵������е�ʱ�䣨���ӣ� 
		int client_arrive_time;//�˿͵������е���ʱ�䣨���ӣ� 
		int business_name;//ҵ������
		int business_name_time;//ҵ��������Ҫʱ�� 

	public:
		Client()//���캯�� 
		{
			randomClient();
		}
	
		//���캯�����õ���������˿͵ķ���
		void randomClient()
		{
			this->client_ID = rand() % 10000;//��ʼ���õ�һ����λ���Ĺ˿ͱ�� 
	
			this->business_name = rand() % 4;  //�κ�һ���ͻ��İ���ҵ��Ϊҵ��0~3
			switch (this->business_name)	//�õ��ͻ���business_name�����ô�ʱ�ù˿Ͱ���ҵ���ʱ��
			{
				case 0:
					this->business_name_time = 5;//���ô�ʱ�ù˿Ͱ���ҵ���ʱ��
					break;
		
				case 1:
					this->business_name_time = 15;//���ô�ʱ�ù˿Ͱ���ҵ���ʱ�� 
					break;
		
				case 2:
					this->business_name_time = 30;//���ô�ʱ�ù˿Ͱ���ҵ���ʱ�� 
					break;
		
				case 3:
					this->business_name_time = 60;//���ô�ʱ�ù˿Ͱ���ҵ���ʱ�� 
					break;
		
				default:
					break;
			}
	
			this->client_arrive_time_hour = rand() % 24;//�˿͵������е�ʱ�䣨0~24Сʱ�� 
			this->client_arrive_time_minutes = 1 + rand() % 59;//�˿͵������е�ʱ�䣨1~59���ӣ�
	
			//��ʼ����ʱ�� = ����Сʱ��*60 + ��������� ��λ������ 
			this->client_arrive_time = ((this->client_arrive_time_hour * 60) + this->client_arrive_time_minutes);
		}
	
		//��ӡ�ͻ���Ϣ
		void showClientInfor()
		{
			cout << "----------------------------------------------------------------" << endl;
			cout << " �˿͵�������ǰ�����Ĺ˿���ϢΪ��" << endl;
			cout << "�ͻ�ID:" << this->client_ID << " " << "�ͻ�����ʱ�䣺" << this->client_arrive_time_hour << "ʱ" << this->client_arrive_time_minutes << "��" << endl;
	
			string client_business_name;//����client������ԣ���ʱ�����
	
			switch (this->business_name)
			{
				case 0:
					client_business_name = "���";//���ô�ʱ�ù˿Ͱ���ҵ���ʱ�� 
					break;
		
				case 1:
					client_business_name = "ȡ��";//���ô�ʱ�ù˿Ͱ���ҵ���ʱ�� 
					break;
		
				case 2:
					client_business_name = "��ʧ";//���ô�ʱ�ù˿Ͱ���ҵ���ʱ�� 
					break;
		
				case 3:
					client_business_name = "����";//���ô�ʱ�ù˿Ͱ���ҵ���ʱ�� 
					break;
		
				default:
					break;
			}
	
			cout << "�ÿͻ������ҵ��Ϊ��" << client_business_name << endl;
			cout << "----------------------------------------------------------------" << endl;
		}
	
		//�������Ե�get���� 
		int getClientArriveTime()//���ã��˿͵������е���ʱ�䣨���ӣ���ʼ����ҵ�񣬲�����ҵ�����ʱ�䣩
		{
			return this->client_arrive_time;
		}
	
		int getClientID()
		{
			return this->client_ID;
		}
	
		int getClientArriveTimeHour()
		{
			return this->client_arrive_time_hour;
		}
	
		int getClientArriveTimeMinutes()
		{
			return this->client_arrive_time_minutes;
		}
	
		int getClientBusinessName()
		{
			return this->business_name;
		}
		
		int getClientBusinessNameTime()
		{
			return this->business_name_time;
		}
	
		//�������Ե�set����
		void setClientArriveTime(int _a)//���ã��˿͵������е���ʱ�䣨��ʼ����ҵ�񣬲�����ҵ�����ʱ�䣩 
		{
			this->client_arrive_time = _a;
		}
	
		void setClientID(int _a)
		{
			this->client_ID = _a;
		}
	
		void setClientArriveTimeHour(int _a)
		{
			this->client_arrive_time_hour = _a;
		}
	
		void setClientArriveTimeMinutes(int _a)
		{
			this->client_arrive_time_minutes = _a;
		}
	
		void setClientBusinessName(int _a)
		{
			this->business_name = _a;
		}
		
		void setClientBusinessNameTime(int _a)
		{
			this->business_name_time = _a;
		}
};

//------------------------------------------�ȴ�����-------------------------------------------------- 
struct Person
{
	Client client;//�����򣺹˿���Ķ��� 
	Person* next;//ָ���� 
};

class LinkedQueue
{
	private:
		Person* front;//��ͷָ��
		Person* rear;//��βָ�� 
		int length;//�������� 

	public:
		LinkedQueue()//�����Ĺ��캯�� 
		{
			Person* p = new Person;//�½�һ���ڵ� 
			p->next = NULL;//��˽ڵ����һ���ڵ�Ϊ��
	
			front = p;//���׵��ڸýڵ� 
			rear = p; //��β���ڸýڵ� 
			
			this->length = 0; 
		}
	
		~LinkedQueue()//�������������� 
		{
			Person* p = front;//��ʼ��һ������ָ��Ϊ��ʱ�Ķ���ָ��
	
			while (p != NULL)//����ָ�벻Ϊ�յĻ�����ѭ�� 
			{
				p = p->next;//����ָ����� 
				delete front;//ɾ������ָ�����ǰ�Ľڵ� 
				front = p;//������ָ���ʼ��Ϊ����ָ����ƺ��λ�� 
			}
	
			front = NULL;//�����ÿ� 
			rear = NULL;//��β�ÿ� 
		}
	
		/*
			��Ӳ�������
			����һ��client��Ķ�������
			��������client��Ķ�������ĳ���
			��������Bank��Ķ���������֪���п��Ź���ʱ�� 
		*/
		void joinQueue(Client *client, int client_length, Bank bank)
		{
			int i = 0;//����ѭ�� 
	
			//ѭ�����
			//ע�⣺���д��ڵ�Ӫҵ��ʼʱ��ͽ���ʱ����Сʱ���������ж�תΪ����
					
			for (i = 0; i < client_length; i++)
			{
				//�˿��ܷ�����Ǻ����д��ڵ�Ӫҵ��ʼʱ��ͽ���ʱ���й�
				if ((client[i].getClientArriveTime() >= (bank.getBankOpenTime() * 60)) && (client[i].getClientArriveTime() < (bank.getBankClosedTime() * 60))) 
				{
					Person* p = new Person;//�½�һ������ָ��
	
					p->client = client[i];//��ʼ�������� 
					p->next = NULL; //��ʼ��ָ����
		
					//β�� 
					rear->next = p;
					rear = p;
					
					length++;
				}
			}
		}
	
		/*
			���ӶӲ�������
		*/
		Client deleteQueue()
		{
			Person* p = NULL;//�½�һ������ָ��
			Client client;
	
			if (rear == front)//������׶�βָ����ͬ�Ļ� 
			{
				throw "�ӿ�";
			}
	
			p = front->next;//����ָ��ָҪɾ����λ�� 
			client = p->client;//�洢���Զ��� 
			front->next = p->next;//����ָ�����һ���ڵ���ڳ��ӽڵ����һ���ڵ�
	
			if (p->next == NULL)//����ǰ�ӵĶ�������Ϊ1�Ļ� 
			{
				rear = front;
			}
	
			delete p;//����
	
			return client;
		}
	
		/*
			�����п�
			trueΪ�գ�falseΪ����
		*/
		bool empty()
		{
			bool result = false;
	
			if (front == rear)
			{
				result = true;
			}
	
			return result;
		}
		
		/*
			�õ��������� 
		*/
		int getQueueLength()
		{
			return this->length;
		}
};

//---------------------------------------------���к�������--------------------------------------------
//��ӡ���д��ڵ�ÿ��ҵ��İ������ 
/*
	����һ��Bank�����Ϊ���ڵĶ�������
	���������ö�������ĳ��� 
*/
void showAllWindow(Bank *window, int window_length);

//ð�����������Կͻ����鰴��������
/*
	����һ��Client��Ķ�������
	����������������ĳ��� 
*/
void bubbleSortForClientArray(Client *client, int client_length);

//ͳ��һ��ͻ������е�ƽ������ʱ��
/*
	����һ��Bank��Ķ�������
	����������������ĳ��� 
*/
void statisticData(Bank *window, int window_length);

//�ҵ���ʱ����ʱ�䳬��������Ӫҵʱ��Ĵ��ڣ��������ر� 
/*
	����һ��Bank�����Ϊwindow�Ķ�������
	����������������ĳ��� 
	�����������й���ʱ�� 
*/

//��ӭ����
void welcome();

//���в˵����� 
void bankStartMenu();
	
//���в˵�
void bankMenu(); 

//--------------------���з�����Ϊ�˸���startWorking��������Ƶ�----------------------
//�ҵ���ʱ����ʱ�䳬��������Ӫҵʱ��Ĵ��ڣ��������ر� 
/*
	����һ��Bank�����Ϊwindow�Ķ�������
	����������������ĳ��� 
	�����������й���ʱ�� 
*/ 
void setWindowStatusByBankEndTime(Bank *window, int window_length, int bank_end_time);

//�ҵ�ҵ��������ʱ����С�Ĵ��� 
/*
	����һ��Bank�����Ϊwindow�Ķ�������
	����������������ĳ��� 
*/
int getMinTimeByWindow(Bank *window, int window_length);

//���ڿ�ʼ���� 
/*
	����һ���ͻ�����
	����������������
	�����������ڳ��� 
*/
void startWorking(LinkedQueue client_queue, Bank *window, int window_length);//���ñ���ģ���߳�

#endif//��ֹ�ļ����ظ�����  

