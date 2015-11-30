#include<iostream>
#include <string.h>


typedef struct Customer   //已定票乘客信息
{
	char No[128];  //流水号
	char Name[10];   //姓名
	char ID[14];	//身份证
	int Level;   //舱位等级
	int SeatNum;   //座位号
	char FlightNum[10];   //所定航班号
	struct Customer *next;
}Customer;

typedef struct Replace   //等待乘客
{
	char Name[10];    //姓名
	char ID[14];
	int Level;   //舱位等级
	char FlightNum[10];   //所定航班号
	struct Replace *next;  
}Replace;   

typedef struct Flight   //航线信息
{
	char star[10];  //出发地
	char Des[10];   //终点站名
	char FlightNum[10];   //航班号
	char PlaneNum[10];   //飞机号
	char week[3];   //飞行周日
	char StartTime[5]; //出发时间
	char EndTime[5];   //到达时间
	int Ration;   //乘员定额
	int FreeTicket;   //剩余票数
	float Price[3];   //舱位等级的价格
	int ReplacePas;   //候补乘客数
	Replace *ReplName;   //该航班的等待乘客名单      
	Customer *CustName;   //该航班的已定票乘客名单
	struct Flight *next;   //指示下一航线结点
}Flight,*PFlight;



Flight *head;   //建立航线头结点
Flight *rear;   //建立航线尾结点   
Customer *Cusrear; //乘客尾结点
Replace *Reprear;