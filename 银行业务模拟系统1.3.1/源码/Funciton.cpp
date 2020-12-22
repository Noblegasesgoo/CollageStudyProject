#include <iostream>
#include <string>
#include <windows.h>
#include "CustomClass.h" 

using namespace std;

//------------------------------------------����Ҫ�Ĺ��ܺ���-------------------------------------------------- 
//��ӡ���д��ڵ�ÿ��ҵ��İ������ 
/*
	����һ��Bank�����Ϊ���ڵĶ�������
	���������ö�������ĳ��� 
*/
void showAllWindow(Bank *window, int window_length) 
{
	int i = 0;
	int count = 0;
	 
	for (i = 0; i < window_length; i++)
	{
		cout << "���ڣ�" << ++count << "�Ĵ����������" << window[i].getSaveMoneyNum() << " " << "ȡ����������" << window[i].getGetMoneyNum() << " " << "��ʧ���������" << window[i].getReportLossOfNum() << " " << "������������" << window[i].getRefundNum() << " " << endl;
		cout << "�ô����ܼƽ���������" << (window[i].getSaveMoneyNum() + window[i].getGetMoneyNum() + window[i].getReportLossOfNum() + window[i].getRefundNum()) << endl;
		cout << endl;
	}
}

//ð�����������Կͻ����鰴��������
/*
	����һ��Client��Ķ�������
	����������������ĳ��� 
*/
void bubbleSortForClientArray(Client *client, int client_length)
{
	int j;
	int exchange;//����λ�ü�¼ 
	int bound;//�������� 
	Client temp_client;//��ʱ�洢
	
	exchange = client_length - 1;//����λ�ó�ʼ������һ��ð����������0~client_length-1 
	
	while (exchange != 0)
	{
		bound = exchange;
		exchange = 0;
		
		for (j = 0; j < bound; j++)//������ÿ��ð������������0~bound
		{
			if (client[j].getClientArriveTime() > client[j+1].getClientArriveTime())
			{
				temp_client = client[j];
				client[j] = client[j+1];
				client[j+1] = temp_client;	
			}				
			
			exchange = j;
		}	
	} 
} 

//ͳ��һ��ͻ������е�ƽ������ʱ��
/*
	����һ��Bank��Ķ�������
	����������������ĳ��� 
*/
void statisticData(Bank *window, int window_length)
{
	int i = 0;//��������ѭ�� 
	int select = 0;//������¼�Ƿ��뿪�˴�ģ��
	
	int client_all_stay_time = 0;//�ͻ��ܵĶ���ʱ�� 
	int all_client_num = 0;//�����ܵ����� 
	double client_average_time;//�ͻ�����ƽ������ʱ�� 
	
	for (i = 0; i < window_length; i++)
	{
		//�˿Ͷ�����ʱ��Ϊ�����д��ڵĿͻ�����ʱ���ۼ� 
		client_all_stay_time += window[i].getClientStayBankTime();
		
		//�����ܵ�����Ϊ�����д��ڵ�����ҵ����������ۼ�
		all_client_num += (window[i].getGetMoneyNum() + window[i].getSaveMoneyNum() + window[i].getReportLossOfNum() + window[i].getRefundNum());
	}
	
	//������ڵ���Ϣ:
	showAllWindow(window,window_length);//ͳ��
	
	client_average_time = ((double)client_all_stay_time / (double)all_client_num);//�ͻ�һ��ƽ������ʱ�� = �ͻ������ܶ���ʱ�� / ���յ������� 
	cout << "���տͻ�ƽ������ʱ�䣺" << client_average_time << endl; 
	
	//�Ƿ�׼����ʼ��һ��ģ�⣡ 
   	cout << "Ready to leave and get another data��If you ready to leave please inputed the ��1 ����";

	while (select != 1)
	{
		cin >> select;
		if (select == 1)
		{
			return ;//�˳��ɹ������ҿ��Կ�ʼ��һ�ֵ�ģ�� 
		}else 
			{
				cout << "input error,please input again��you need to inputed the  ��1 ����������" << endl;
			}
	}
}

 
//-------------------------------------------------------------------------���з����Ǹ���startWorking�������ӷ���-----------------------------------------------------------------
//�ҵ���ʱ����ʱ�䳬��������Ӫҵʱ��Ĵ��ڣ��������ر� 
/*
	����һ��Bank�����Ϊwindow�Ķ�������
	����������������ĳ��� 
	�����������й���ʱ�� 
*/
void setWindowStatusByBankEndTime(Bank *window, int window_length, int bank_end_time)
{
	int i = 0;
	for	(i = 0; i< window_length; i++)
	{
		if (window[i].getBusinessStartTime() >= bank_end_time)
		{
			window[i].setWindowsEmpty(false);	
		} 
	}
} 
					
//�ҵ�ҵ��������ʱ����С�Ĵ��� 
/*
	����һ��Bank�����Ϊwindow�Ķ�������
	����������������ĳ��� 
*/
int getMinTimeByWindow(Bank *window, int window_length)
{
	int i;
	int index;
	
	int min = window[0].getbusinessEndTime();
	
	for (i = 0; i < window_length; i++)
	{
	    if (min >= window[i].getbusinessEndTime())
	    {
	        min = window[i].getbusinessEndTime();
	        index = i;//��¼����ʱ����С�Ĵ����±� 
	    }
	}
	
	return index;//�Żش��������а���ʱ����̵��Ǹ����ڵ��±� 
} 

//-------------------------------------------------------------------------���з�����ģ�����еĺ��ķ���������--------------------------------------------------------------------

//���ڿ�ʼ���� 
/*
	����һ���ͻ�����
	����������������
	�����������ڳ��� 
*/
void startWorking(LinkedQueue client_queue, Bank *windows, int window_length)//���ñ���ģ���߳� 
{
	int i;//�������Ʊ����մ��ڵ�ѭ�� 
	int j;//�������Ʊ���ҵ�����ʱ����С���ڵ�ѭ�� 
	int count = 0;//������¼�˿����ڴ��� 
	 
	int index_for_min = 0;//��¼����ʱ����С�Ĵ����±�
	
	int bank_end_time = 0;//��¼���н���Ӫҵʱ�� 
	int now_temp_all_time_min = 0;//��¼��ǰ����ʱ����̵��Ǹ����ڵĽ�������ʱ�� 
	
	bank_end_time = windows[0].getBankClosedTime() * 60;//�����н���Ӫҵʱ��洢��ת��Ϊ���ӱ�
		
	if(client_queue.empty() == true)
	{
		//����ȴ�����һ��ʼ��Ϊ�յĻ��Ǿ��˳� 
	} else
	    {
	        while (client_queue.empty() != true && now_temp_all_time_min <= bank_end_time)//ֻҪ���л���Ԫ�ػ��ߴ�ʱ����ʱ����С�Ĵ��ڵ���ʱ�䳬��������Ӫҵ����ʱ�� 
	        {
	        	//������ڶ���Ϊ�� 
	           	if(!windows[0].getWindowsEmpty() && !windows[1].getWindowsEmpty() 
	           		&& !windows[2].getWindowsEmpty() &&! windows[3].getWindowsEmpty())
	            {
	         		index_for_min = getMinTimeByWindow(windows, window_length);//��������С�±���ҵ�ҵ��������ʱ����С�Ĵ���
	         		
	                windows[index_for_min].setWindowsEmpty(true);//ʱ����С�Ĵ�������Ϊû��״̬ 
	                windows[index_for_min].setBusinessStartTime(windows[index_for_min].getbusinessEndTime());//����������ϵĴ��ڵ���һ��ҵ��ʼ����ʱ������Ϊ����һ��ҵ�����Ľ���ʱ�� 
	                now_temp_all_time_min = windows[index_for_min].getbusinessEndTime();//����ʱ����ʱ����̵Ĵ��ڵ�ʱ������Ϊ��ʱ��
					
					setWindowStatusByBankEndTime(windows, window_length, bank_end_time);//�ҵ���ʱ����ʱ�䳬��������Ӫҵʱ��Ĵ��ڣ��������رգ���ζ�������ٽ��ܿ��� 
					
	            } else//����ִ��ҵ����� 
	            	{
	            		//ִ�г��Ӳ���
	            		Client client = client_queue.deleteQueue();//��һ����ʱ�������洢��ǰ���Ӷ��� 
	            		
						//�����ҵ���ǰ�յĴ��� 
	               		for (i = 0; i < window_length; i++)
	               		{
							count = i;//�õ���ǰ�˿����ڴ��� 
							
	                  		if (windows[i].getWindowsEmpty() == true)//�ҵ���ǰ�յĴ��ڲ������ӡ 
	                  		{
	                  			cout << "���ڹ˿��ڵ� " << count+1 << " ���ڰ���ҵ��" << endl;
	                  			client.showClientInfor();//��ӡ��ǰ����ҵ��Ŀͻ���Ʊ����Ϣ
								cout << endl;
	            				cout << endl;  
	                  			
	                  			//�����ʱ����ô��ڵ��û���ʱ��Զ���ڴ�����һ��ҵ�������ϵ�ʱ�䣨Ҳ���Ǹô���ҵ����һ��ҵ��ʼʱ�䣩 
	                  			//��ô�ͽ���ҵ����һ��ҵ��ʼʱ�� = ��һ���˿͵�����ʱ�� 
 	                  			if (client.getClientArriveTime() > windows[i].getBusinessStartTime())
	                  			{
	                  				windows[i].setBusinessStartTime(client.getClientArriveTime());	
								}
								  
	                    		windows[i].setWindowsEmpty(false);//���ô�������Ϊ����״̬ 

	                    		switch (client.getClientBusinessName())//���õ�ǰ���Ӷ���ĵõ������ҵ�񷽷����õ���ǰ�����û��ڸô��ڰ����ҵ�������Լ�����ʱ��͵�ǰ���ڸ�ҵ��������ʱ�䡣 
	                     		{
	                     		    case 0:
	                     		    		//���õ�ǰ���ڰ������ʱ��Ϊ��������һ���˰�����ϵ�ʱ�� + ��ǰ�����˿���Ҫ�����ʱ�� 
	                     		    		windows[i].setbusinessEndTime(windows[i].getBusinessStartTime() + client.getClientBusinessNameTime());
	                     		    		//������ʱ�� = �û��뿪��ʱ�䣨���ڷ���ǰ�ͻ�����ʱ�䣩- �û������ʱ��
	                     		    		windows[i].setClientStayBankTime((windows[i].getbusinessEndTime() - client.getClientArriveTime()));//��ǰ���ڹ˿Ͷ���ʱ���ۼ�

	                     		    		windows[i].setSaveMoneyNum();//��ǰ���ڵĴ��������+1

	                               			break;
	
	                          		case 1:
	                          			  	//���õ�ǰ���ڰ������ʱ��Ϊ��������һ���˰�����ϵ�ʱ�� + ��ǰ�����˿���Ҫ�����ʱ�� 
	                     		    		windows[i].setbusinessEndTime(windows[i].getBusinessStartTime() + client.getClientBusinessNameTime());
	                     		    		//������ʱ�� = �û��뿪��ʱ�䣨���ڷ���ǰ�ͻ�����ʱ�䣩- �û������ʱ��
	                     		    		windows[i].setClientStayBankTime((windows[i].getbusinessEndTime() - client.getClientArriveTime()));//��ǰ���ڹ˿Ͷ���ʱ���ۼ�
	                     		    		
											windows[i].setGetMoneyNum();//��ǰ���ڵ�ȡ��������+1 

	                     		    		break;
	                     		    		
	                          		case 2:
	                          			 	//���õ�ǰ���ڰ������ʱ��Ϊ��������һ���˰�����ϵ�ʱ�� + ��ǰ�����˿���Ҫ�����ʱ�� 
	                     		    		windows[i].setbusinessEndTime(windows[i].getBusinessStartTime() + client.getClientBusinessNameTime());
	                     		    		//������ʱ�� = �û��뿪��ʱ�䣨���ڷ���ǰ�ͻ�����ʱ�䣩- �û������ʱ��
	                     		    		windows[i].setClientStayBankTime((windows[i].getbusinessEndTime() - client.getClientArriveTime()));//��ǰ���ڹ˿Ͷ���ʱ���ۼ�
	                     		    		
	                     		    		windows[i].setReportLossOfNum();//��ǰ���ڵĹ�ʧ�������+1 
	                     		    		break;
	                     		    		
	                           		case 3:
											//���õ�ǰ���ڰ������ʱ��Ϊ��������һ���˰�����ϵ�ʱ�� + ��ǰ�����˿���Ҫ�����ʱ�� 
	                     		    		windows[i].setbusinessEndTime(windows[i].getBusinessStartTime() + client.getClientBusinessNameTime());
	                     		    		//������ʱ�� = �û��뿪��ʱ�䣨���ڷ���ǰ�ͻ�����ʱ�䣩- �û������ʱ��
	                     		    		windows[i].setClientStayBankTime((windows[i].getbusinessEndTime() - client.getClientArriveTime()));//��ǰ���ڹ˿Ͷ���ʱ���ۼ�
	                     		    		
	                     		    		windows[i].setRefundNum();//��ǰ���ڵĴ���������+1 
	                     		    		break;
	                     		    		
	                       			default:
	                       					cout << "error��" << endl;
	                       					break; 
	                       		}
							}
	                        
	                   	}
	                }
	                
	            Sleep(500);//ÿִ��һ��ѭ����˯��0.5��ģ��˿ͻ������� 
	            
	    	}
		}
}
