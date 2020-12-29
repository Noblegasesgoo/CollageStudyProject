/***************************************************
*版权所有 (c)2020,大连民族大学 。
*
*文件名称：银行业务模拟系统。
*内容摘要：无。
*其他说明：课设任务。
*当前版本：1.3.2。
*作    者：赵力民。
*完成日期：2020.12.29。
****************************************************/

/*************************************************** 
*修改记录1：	//修改历史记录，包括修改日期、版本号、修改人及修改内容等
*	修改日期：2020.12.14
*	版本号：1.0
*	修改人：赵力民
*	修改内容：
			完成各个类框架的搭建 ：
				窗口类的初始化及属性和get/set方法
				顾客类的初始化及属性和get/set方法
				队链的初始化及属性及出队入队析构判空

			定义一系列随机数函数（未实现）

*修改记录2：	//修改历史纪录，包括修改日期、版本号、修改人及修改内容等
*	修改日期：2020.12.15
*	版本号：1.1
*	修改人：赵力民
*	修改内容：
			优化整体框架 
			完成Cilent类的随机创建客户,以及测试随机创建客户类完毕,创建面向客户类的对象数组排序方法，并测试排序成功
			下一步准备将队列入队函数写完。

*修改记录3：	//修改历史纪录，包括修改日期、版本号、修改人及修改内容等
*	修改日期：2020.12.16
*	版本号：1.2
*	修改人：赵力民
*	修改内容：
			完成条件入队
			完成主函数中的执行窗口模拟函数之前的所有无法包装逻辑体
			初步完成窗口模拟函数（待测试） 

*修改记录4：	//修改历史纪录，包括修改日期、版本号、修改人及修改内容等
*	修改日期：2020.12.16
*	版本号：1.2.1~1.2.3
*	修改人：赵力民
*	修改内容：	
			完成窗口模拟函数以及优化 
			
*修改记录5：	//修改历史纪录，包括修改日期、版本号、修改人及修改内容等
*	修改日期：2020.12.17
*	版本号：1.2.4
*	修改人：赵力民
*	修改内容：	
			完成窗口模拟函数以及优化 
			完成了针对客户数组的冒泡排序
			完成了窗口模拟函数中的一些代码块的方法封装 
			
*修改记录6：	//修改历史纪录，包括修改日期、版本号、修改人及修改内容等
*	修改日期：2020.12.18
*	版本号：1.2.5 
*	修改人：赵力民
*	修改内容：	
			菜单测试，完成统计模块 
					
*修改记录7：	//修改历史纪录，包括修改日期、版本号、修改人及修改内容等
*	修改日期：2020.12.18
*	版本号：1.2.6 
*	修改人：赵力民
*	修改内容：	
			菜单测试初步完成，现以可反复使用模拟过程。
			现在还剩下一个重构客户问题。 
			
*修改记录8：	//修改历史纪录，包括修改日期、版本号、修改人及修改内容等
*	修改日期：2020.12.19
*	版本号：1.3 
*	修改人：赵力民
*	修改内容：	
			菜单实现重新模拟银行的排队，重构队伍，以及实现题目的基本要求。
			接下来就是就是来制作提高内容，以及优化封装原本代码 

*修改记录9：	//修改历史纪录，包括修改日期、版本号、修改人及修改内容等
*	修改日期：2020.12.22
*	版本号：1.3.1
*	修改人：赵力民
*	修改内容：	
			美化菜单，测试bug 
			
*修改记录10：	//修改历史纪录，包括修改日期、版本号、修改人及修改内容等
*	修改日期：2020.12.29 
*	版本号：1.3.2 
*	修改人：赵力民
*	修改内容：	
			修改了菜单不循环bug,以及去除了throw语句 
**************************************************/

/*************************************************
			头文件引用：
					#include <iostream>
					#include <string>
					#include <ctime>
					#include <windows.h>
					#include "CustomClass.h"自定义头文件存储的是三个类：
												Bank类：
													用来初始化提供银行时间的bank对象， 
													以及用来模拟窗口的Bank的对象数组windows数组 。
												
												Client类：
													用来生成客人，规定长度为100，样本足够0~24小时营业时间
													构造方法中提供随机生成过程
												
												LinkedQueue队链：
													用来创建等待队列，运用Client类对象数组在银行营业时间断内的人入队
													
												以及一些功能函数。	
**************************************************/

/*************************************************
			全局变量定义：无
**************************************************/

#include <string>
#include <iostream>
#include <ctime>
#include <windows.h>
#include "CustomClass.h"

using namespace std;

int main(int argc, char** argv)
{
//---------------------------------	客户数组创建以及排序测试完毕 -------------------------------- 
	//int count = 0;

	//Client c[100];
	//for (int i=0; i<100;i++)
	//{
	//	cout << "客户生成完成" << endl;
	//	c[i].showClientInfor();
	//}
	//
	//sort(c,c+100,cmp);//排序
	//
	//cout << "====================================" << endl;
	//for (int i=0; i<100;i++)
	//{
	//	c[i].showClientInfor();
	//	count++;
	//}

	//cout << count << endl;
	
// -------------------------------- 客户数组创建并规定时间段入队打印测试完毕 ----------------------------

	//先定义银行对象
	//再创建对象数组
	//建队
	//出队 
//	
//	Bank bank;//先初始化一个银行 
//	
//	//创建对象数组 
//	int count = 0;
//	Client c[100];
//	for (int i=0; i<100;i++)
//	{
//		cout << "客户生成完成" << endl;
//		c[i].showClientInfor();
//	}
//	
//	sort(c,c+100,cmp);//排序
//	
//	cout << "====================================" << endl;
//	for (int i=0; i<100;i++)
//	{
//		c[i].showClientInfor();
//		count++;
//	}
//
//	cout << count << endl;
//	
//	//建队
//	cout << "----------------------------------建队中。。。----------------------------------" << endl; 
//	LinkedQueue client_list;
//	client_list.joinQueue(c,100,bank);
//	cout << "----------------------------------建队完成----------------------------------" << endl; 
//	cout << "----------------------------------出队打印----------------------------------" << endl; 
//	
//	for (int i=0; i<client_list.getQueueLength(); i++)
//	{
//		Client cc = client_list.deleteQueue();
//		cc.showClientInfor();	
//	}  

// -------------------------------- 客户数组创建并规定时间段入队打印测试完毕(封装版本) ----------------------------
//	int client_array_length = 100;//顾客数组最大长度 
//	
//	Bank bank;//先初始化一个银行
//	
//	Client client[client_array_length];//创建顾客数组 
//	sort(client,client+client_array_length,cmp);//排序
//	
//	LinkedQueue client_queue = mainCreateClientQueue(client, client_array_length, bank);//建队 

//	srand((int)time(NULL));  //用时间作为种子对随机数进行操作
	
//	int open_time;//银行开门时间 
//	int closed_time;//银行关闭时间 
//	int client_array_length = 100;//顾客数组最大长度 
//	int window_length = 4;//窗口数量 
//	int all_client = 0;//今日到客总量
//	 
//	Bank bank(open_time, closed_time);//先初始化一个银行
//	
//	Client client[client_array_length];//创建顾客数组 
//	bubbleSortForClientArray(client, client_array_length);//对客户数组冒泡排序做入队准备 
//	
//	LinkedQueue client_queue = mainCreateClientQueue(client, client_array_length, bank);//建队 
//	
//	Bank a_window(open_time, closed_time);
//	Bank b_window(open_time, closed_time);
//	Bank c_window(open_time, closed_time);
//	Bank d_window(open_time, closed_time);
//	Bank windows[window_length] = {a_window, b_window, c_window, d_window};//用银行类建立4个窗口 
//	
//	startWorking(client_queue, windows, window_length);//银行开始工作 
//	
//	showAllWindow(windows,window_length);//统计 
//	
//	cout << "今日到客量：" << all_client << endl;
	
// -------------------------------- 菜单版本正式版1.0 ----------------------------
	srand((int)time(NULL));  //用时间作为种子对随机数进行操作
	
	welcome();
	
	bankStartMenu();
	
	return 0;
}
