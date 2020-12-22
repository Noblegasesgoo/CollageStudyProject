#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h> 
#include <stdio.h>
#include "CustomClass.h" 

using namespace std;

//欢迎方法
void welcome()
{
	system("color f9");//调整控制台背景色
	
	cout << "                    ***************************************************************************" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    *                           Welcome to                                    *" << endl;
	
	Sleep(1500);//沉睡1.5秒
	
	cout << "                    *                                       Freedom-Bank                      *" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    ***************************************************************************" << endl;
	
	Sleep(1500);//沉睡1.5秒
		
	cout << "                    ***************************************************************************" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    *                       @If you fixed the time,                           *" << endl;
	cout << "                    *                       @t cannot be changed!                             *" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    *                       ~if you wanna changed the time,                   *" << endl;
	cout << "                    *                       you can exit the program and restarted.           *" << endl;
	cout << "                    *                                                                         *" << endl;
	cout << "                    ***************************************************************************" << endl;
	
	Sleep(1000);//1秒后进入程序 
		
} 
 
//银行菜单
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

//银行菜单方法 
void bankStartMenu()
{
	int select = 0;
	
	int open_time;//银行开门时间 
	int closed_time;//银行关闭时间 
	
	const int client_array_length = 100;//顾客数组最大长度 
	const int window_length = 4;//窗口数量 
	
	cout << "                                        Please enter the bank open time (h)：";
	cin >> open_time;//设置银行开始营业时间 （小时）
	cout << endl;
	cout << "                                        Please enter the bank close time (h): " ;
	cin >> closed_time;//设置银行结束营业时间（小时）
	
	Bank bank(open_time, closed_time);//先初始化一个银行（用来提供开门关门时间） 
	
	while (select != 2)
	{
		bankMenu();//显示银行菜单 
		cout << "                                        Please enter the select：      ";
		cin >> select;//输入选择
		
		Client client[client_array_length];//创建顾客数组 
		bubbleSortForClientArray(client, client_array_length);//对客户数组冒泡排序做入队准备 
		
		LinkedQueue client_queue;
		client_queue.joinQueue(client, client_array_length, bank);//建队 
		
		Bank a_window(open_time, closed_time);
		Bank b_window(open_time, closed_time);
		Bank c_window(open_time, closed_time);
		Bank d_window(open_time, closed_time);
		Bank windows[window_length] = {a_window, b_window, c_window, d_window};//用银行类建立4个窗口 
		
		switch (select)
		{
			case 1:
				system("cls");//清屏然后开始银行模拟 
				startWorking(client_queue, windows, window_length);//开始模拟银行工作
				
				cout << "Today's data generation is complete :" << endl;
				statisticData(windows, window_length);
				
				break;
			
			case 2:
				system("cls");//清屏然后结束 
				cout << "                                              Welcome to come next time!                                   " << endl;
				
				break;
			
			default:
				cout << "                                  Invalid input,Please try to enter the 1~3,thank you!" << endl;
				
				break;
		}
	}
	
	return ; 
} 
