#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h> 
#include <stdio.h>
#include "CustomClass.h" 

using namespace std;

//��ӭ����
void welcome()
{
	system("color f9");//��������̨����ɫ
	
	cout << "                    ***************************************************************************" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    *                           Welcome to                                    *" << endl;
	
	Sleep(1500);//��˯1.5��
	
	cout << "                    *                                       Freedom-Bank                      *" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    ***************************************************************************" << endl;
	
	Sleep(1500);//��˯1.5��
		
	cout << "                    ***************************************************************************" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    *                       @If you fixed the time,                           *" << endl;
	cout << "                    *                       @t cannot be changed!                             *" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    *                       ~if you wanna changed the time,                   *" << endl;
	cout << "                    *                       you can exit the program and restarted.           *" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    ***************************************************************************" << endl;
	
	Sleep(1000);//1��������� 
		
} 
 
//���в˵�
void bankMenu()
{
	system("cls");
	system("color f9");
	cout << "                    ***************************************************************************" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    *                          ------Freedom-Bank------                       *" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    *                         Enter 1 to begin to simulate                    *" << endl;
	cout << "                    *                         Enter 2 to quit system                          *" << endl;
	cout << "                    ***************************************************************************" << endl;
}

//���в˵����� 
void bankStartMenu()
{
	int select = 0;
	
	int open_time;//���п���ʱ�� 
	int closed_time;//���йر�ʱ�� 
	
	const int client_array_length = 100;//�˿�������󳤶� 
	const int window_length = 4;//�������� 
	
	cout << "                                        Please enter the bank open time (h)��";
	cin >> open_time;//�������п�ʼӪҵʱ�� ��Сʱ��
	cout << endl;
	cout << "                                        Please enter the bank close time (h): " ;
	cin >> closed_time;//�������н���Ӫҵʱ�䣨Сʱ��
	
	Bank bank(open_time, closed_time);//�ȳ�ʼ��һ�����У������ṩ���Ź���ʱ�䣩 
	
	while (select != 2)
	{
		bankMenu();//��ʾ���в˵� 
		cout << "                                        Please enter the select��      ";
		cin >> select;//����ѡ��
		
		Client client[client_array_length];//�����˿����� 
		bubbleSortForClientArray(client, client_array_length);//�Կͻ�����ð�����������׼�� 
		
		LinkedQueue client_queue;
		client_queue.joinQueue(client, client_array_length, bank);//���� 
		
		Bank a_window(open_time, closed_time);
		Bank b_window(open_time, closed_time);
		Bank c_window(open_time, closed_time);
		Bank d_window(open_time, closed_time);
		Bank windows[window_length] = {a_window, b_window, c_window, d_window};//�������ཨ��4������ 
		
		switch (select)
		{
			case 1:
				system("cls");//����Ȼ��ʼ����ģ�� 
				startWorking(client_queue, windows, window_length);//��ʼģ�����й���
				
				cout << "Today's data generation is complete :" << endl;
				statisticData(windows, window_length);
				
				break;
			
			case 2:
				system("cls");//����Ȼ����� 
				cout << "                                              Welcome to come next time!                                   " << endl;
				
				break;
			
			default:
				cout << "                                  Invalid input,Please try to enter the 1~3,thank you!" << endl;
				
				break;
		}
	}
	
	return ; 
} 
