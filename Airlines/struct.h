#include<iostream>
#include <string.h>


typedef struct Customer   //�Ѷ�Ʊ�˿���Ϣ
{
	char No[128];  //��ˮ��
	char Name[10];   //����
	char ID[14];	//���֤
	int Level;   //��λ�ȼ�
	int SeatNum;   //��λ��
	char FlightNum[10];   //���������
	struct Customer *next;
}Customer;

typedef struct Replace   //�ȴ��˿�
{
	char Name[10];    //����
	char ID[14];
	int Level;   //��λ�ȼ�
	char FlightNum[10];   //���������
	struct Replace *next;  
}Replace;   

typedef struct Flight   //������Ϣ
{
	char star[10];  //������
	char Des[10];   //�յ�վ��
	char FlightNum[10];   //�����
	char PlaneNum[10];   //�ɻ���
	char week[3];   //��������
	char StartTime[5]; //����ʱ��
	char EndTime[5];   //����ʱ��
	int Ration;   //��Ա����
	int FreeTicket;   //ʣ��Ʊ��
	float Price[3];   //��λ�ȼ��ļ۸�
	int ReplacePas;   //�򲹳˿���
	Replace *ReplName;   //�ú���ĵȴ��˿�����      
	Customer *CustName;   //�ú�����Ѷ�Ʊ�˿�����
	struct Flight *next;   //ָʾ��һ���߽��
}Flight,*PFlight;



Flight *head;   //��������ͷ���
Flight *rear;   //��������β���   
Customer *Cusrear; //�˿�β���
Replace *Reprear;