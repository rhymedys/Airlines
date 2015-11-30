#include "iostream"
#include <string.h>
#include "struct.h"
#include <time.h>

using namespace std;



void FlightInsert(); 
void FlightDelete();
void FlightLookup();
void FlightRework();
void FlightBuyticket();
void FlightCancelticket();
void Flightclean();
void Buyticket(PFlight  );
void Buyreplace(PFlight  ,int );
void customermenu();
void admin();
void mainmenu();
void adminFlightLookup();


void main()
{
	Cusrear=new Customer;
	Reprear=new Replace;
	head=rear=new Flight;
	head->next=NULL;
	mainmenu();
	
}

void mainmenu()
{
	char i='0';
	while(i!=3)
       {
	        cout<<"       ***************航空公司客运定票系统***************"<<endl;
			cout<<"       *     1、管理员界面         2、客户个人中心      *"<<endl;
			cout<<"       *     3、退出系统                                *"<<endl;
			cout<<"       **************************************************"<<endl;
			cin>>i;
			switch(i)
			{
						case '1':admin();break;
						case '2':customermenu();break;
						case '3':;break;
						default:cout<<"error\n";break;
			}
		}

}

void admin()
		{
			char i='0';
			while (i!='7')
			{
				cout<<"       *********************管理员中心*******************"<<endl;
				cout<<"       *     1、增加航线               2、查询航线      *"<<endl;
				cout<<"       *     3、修改航线               4、删除航线      *"<<endl;
				cout<<"       *     5、清空系统               6、返回主菜单    *"<<endl;
		        cout<<"       *     7、退出系统                                *"<<endl;
				cout<<"       **************************************************"<<endl;
				cin>>i;
				switch(i)
				{
					case '1':FlightInsert();break;
					case '2':adminFlightLookup();break;
					case '3':FlightRework();break;
					case '4':FlightDelete();break;
					case '5':Flightclean();break;
					case '6':mainmenu();break;
					case '7':;break;
					default:cout<<"error\n";break;
				}
			}
		}

void customermenu()
		{
			char i='0';
			while (i!='5')
			{
				cout<<"       *********************个人中心********************"<<endl;
				cout<<"       *     1、查询航线               2、预订机票      *"<<endl;
				cout<<"       *     3、退订机票               4、返回主菜单    *"<<endl;
				cout<<"       *     5、退出系统                                *"<<endl;
		        cout<<"       *                                                *"<<endl;
				cout<<"       **************************************************"<<endl;
				cin>>i;
				switch(i)
				{
					case '1':FlightLookup();break;
					case '2':FlightBuyticket();break;
					case '3':FlightCancelticket();break;
					case '4':mainmenu();break;
					case '5':;break;
					default:cout<<"error\n";break;
				}
			}
}

void FlightInsert()   //航班插入
{
    Flight *p;
    p=new Flight;
	cout<<"请输入出发站名"<<endl;
	cin>>p->star;
    cout<<"请输入终点站名:"<<endl;
    cin>>p->Des;
    cout<<"请输入航班号:"<<endl;
    cin>>p->FlightNum;
    cout<<"请输入飞机号:"<<endl;
    cin>>p->PlaneNum;
    cout<<"请输入飞行周日:"<<endl;
    cin>>p->week;
	cout<<" 请输入出发时间："<<endl;
	cin>>p->StartTime;
	cout<<"请输入到达时间："<<endl;
	cin>>p->EndTime;
    cout<<"请输入乘员定额:"<<endl;
    cin>>p->Ration;
    p->FreeTicket=p->Ration;
    cout<<"请输入舱位等级的价格:"<<endl;
    cout<<"头等舱价格"<<endl;
    cin>>p->Price[0];
    cout<<"普通舱价格"<<endl;
    cin>>p->Price[1];
    cout<<"经济舱价格"<<endl;
    cin>>p->Price[2];
    p->ReplName=new Replace;
    p->CustName=new Customer;
    p->CustName->next=NULL;
    p->ReplName->next=NULL;
    p->ReplacePas=0;
    rear->next=p;
    rear=p;
    rear->next=NULL;
}

void FlightDelete()   //删除航班
{
	Flight *p,*q;
	char FlightNum[10];
	p=head;
	int i=0;
	while (i!=1)
	{
		cout<<"请输入需要删除的航班号:"<<endl;
		cin>>FlightNum;
		while (p->next&&strcmp(p->next->FlightNum,FlightNum))
		{
			p=p->next;
		}     
		q=p->next;
		if (q!=NULL)
		{
			if(q->next==NULL)
			{    //当删除rear所指向的结点
				rear=p;
			}
            p->next=p->next->next;
			delete q;
		}
        else
		{
			cout<<"你所要删除的航班不存在"<<endl;
		}
		cout<<"1、退出2、继续"<<endl;
		cin>>i;
	}
}

void adminFlightLookup()   //查询航班
{
	Flight *p,*q;
	char FlightNum[10];	
	int i=0;
	p=head;
	while (i!=1)
	{
		
		cout<<"请输入需要查询的航班号:"<<endl;
		cin>>FlightNum;
		while (p->next&&strcmp(p->next->FlightNum,FlightNum))
		{
			p=p->next;
		}
		q=p->next;
		if (q==NULL)
		{
			cout<<"对不起不存在此航班"<<endl;
		}
		else
		{
			cout<<"航班号:"<<q->FlightNum<<endl;
			cout<<"飞机号:"<<q->PlaneNum<<endl;
			cout<<"出发地："<<q->star<<endl;
			cout<<"目的地:"<<q->Des<<endl;
			cout<<"飞行周日:"<<q->week<<endl;
			cout<<"出发时间："<<q->StartTime<<endl;
			cout<<"到达时间："<<q->EndTime<<endl;
			cout<<"成员定额:"<<q->Ration<<endl;
			cout<<"候补乘客数:"<<q->ReplacePas<<endl;
			cout<<"头等舱价格:"<<q->Price[0]<<endl;
			cout<<"普通舱价格:"<<q->Price[1]<<endl;
			cout<<"经济舱价格:"<<q->Price[2]<<endl;
		}
		cout<<"1、返回主菜单 2、继续"<<endl;
		cin>>i;
	}
}

void FlightLookup()   //查询航班
{
	Flight *p,*q;
	char Des[10];	
	char start[10];
	int i=0;
	p=head;

	while (i!=1)
	{		
		cout<<"请输入需要查询的航班出发地:"<<endl;
		cin>>start;
		cout<<"请输入需要查询的航班目的地:"<<endl;
		cin>>Des;
		int a=0;
		while (p->next&&a)
		{
			if((!strcmp(p->next->star,start))&&(!(strcmp(p->next->Des,Des))))
			{
				a=1;
			}
			p=p->next;
		}
		q=p->next;
		if (q==NULL)
		{
			cout<<"对不起不存在此航班"<<endl;
		}
		else
		{
			cout<<"航班号:"<<q->FlightNum<<endl;
			cout<<"飞机号:"<<q->PlaneNum<<endl;
			cout<<"出发地："<<q->star<<endl;
			cout<<"目的地:"<<q->Des<<endl;
			cout<<"飞行周日:"<<q->week<<endl;
			cout<<"出发时间："<<q->StartTime<<endl;
			cout<<"到达时间："<<q->EndTime<<endl;
			cout<<"成员定额:"<<q->Ration<<endl;
			cout<<"剩余票数:"<<q->FreeTicket<<endl;
			cout<<"候补乘客数:"<<q->ReplacePas<<endl;
			cout<<"头等舱价格:"<<q->Price[0]<<endl;
			cout<<"普通舱价格:"<<q->Price[1]<<endl;
			cout<<"经济舱价格:"<<q->Price[2]<<endl;
		}
		cout<<"1、返回主菜单 2、继续"<<endl;
		cin>>i;
	}
}

void FlightRework()   //修改航线信息
{
	int Customer_Number ;
	Flight *p,*q;
	char FlightNum[10];
	char i='0';
	p=head;
	cout<<"请输入需要修改的航班号:"<<endl;
	cin>>FlightNum;
	while (p->next&&strcmp(p->next->FlightNum,FlightNum))
	{
		p=p->next;
	}
	q=p->next;
	if (q==NULL)
	{
		cout<<"对不起不存在此航班"<<endl;
	}
	else
	{
		while(i!='12')
		{
			cout<<"     *****请输入需要修改的数据*****"<<endl;
			cout<<"     *1、航班号        2、飞机号     *"<<endl;
            cout<<"     *3、出发地        4、目的地     *"<<endl;
			cout<<"     *5、飞行周日      6、出发时间   *"<<endl;
			cout<<"     *7、到达时间      8、成员定额   *"<<endl;
			cout<<"     *9、头等舱价格    10、普通舱价格*"<<endl;
            cout<<"     *11、经济舱价格   12、退出      *"<<endl;
			cout<<"     **********************************"<<endl;
			cin>>i;
			switch(i)
			{
			case '1':cout<<"请输入航班号:"<<endl;
				cin>>q->FlightNum;break;
			case '2':cout<<"请输入飞机号:"<<endl;
                   cin>>q->PlaneNum;break;
			case '3':cout<<"请输入出发地："<<endl;
				cin>>q->star;break;
			case '4':cout<<"请输入目的地:"<<endl;
                cin>>q->Des;break;
			case '5':cout<<"请输入飞行周日:"<<endl;
                cin>>q->week;break;
			case '6':cout<<"请输入出发时间："<<endl;
				cin>>q->StartTime;break;
			case '7':cout<<"请输入到达时间："<<endl;
				cin>>q->EndTime;break;
			case '8':cout<<"请输入乘员定额:"<<endl;
				Customer_Number=q->Ration-q->FreeTicket; 
				cin>>q->Ration;q->FreeTicket=q->Ration-Customer_Number;break;
			case '9':cout<<"请输入头等舱价格:"<<endl;
                cin>>q->Price[0];break;
			case '10':cout<<"请输入普通舱价格:"<<endl;
                cin>>q->Price[1];break;
			case '11':cout<<"请输入经济舱价格:"<<endl;
                 cin>>q->Price[2];break;
            case '12':
				break;
            default:cout<<"error\n";break;
			}
		}
	}
}

void FlightBuyticket() //订票
{
	int Ticket_Amount;

	Flight *p,*q;
	char Des[10];
	char start[10];
	int year;
	int mon;
	int day;
	int i=2;
	while (i!=1)
	{
		cout<<"请输入出发点："<<endl;
		cin>>start;
		cout<<"请输入目的地:"<<endl;
		cin>>Des;
		cout<<"请输入出发日期："<<endl;
		cout<<"请输入年份："<<endl;
		cin>>year;
		cout<<"月份："<<endl;
		cin>>mon;
		cout<<"日："<<endl;
		cin>>day;
		//char A[3]={0};
		//struct tm t;	
		//	time_t t_of_day;
		//	t.tm_year=year-1900;
		//	t.tm_mon=mon-1;
		//	t.tm_mday=day;
		//	t.tm_hour=0;
		//	t.tm_min=0;
		//	t.tm_sec=0;
		//	t.tm_isdst=0;
		//	t_of_day=mktime(&t);
		//	strftime(A,64,"%a",&t);
        p=head;
		while (p->next&&strcmp(p->next->Des,Des)&&strcmp(p->next->star,start))
		{
			p=p->next;
		}
		q=p->next;
		if (q==NULL)
		{
			cout<<"对不起不存在此航班"<<endl;
		}
		else
		{
			while(i!=1)
			{
				
				if (1<=q->FreeTicket)
				{
					Buyticket(q);
				}
				else
				{
					int n;
					cout<<"剩余票数小于定票数，是否需要列入候补名单？(1、是 2、否)"<<endl;
					cin>>n;
					Buyreplace(q,n);
				}
				cout<<"1、返回主菜单 2、继续"<<endl;
				cin>>i;
			}
		}
	}
}

void Buyticket(PFlight q)   //买票
{
 
	
	Customer *Cus2;
	Cus2=new Customer;
	
	time_t t;  //秒时间  
	tm* local; //本地时间   
	tm* gmt;   //格林威治时间  
	char buf[128]= {0};  
	t = time(NULL); //获取目前秒时间  
	local = localtime(&t); //转为本地时间  
	strftime(buf, 64, "%Y%m%d%H%M%S", local);
	
	strcpy(Cus2->No,buf);

	Cus2->SeatNum=q->Ration-q->FreeTicket+1;
	strcpy(Cus2->FlightNum, q->FlightNum );
	cout<<"请输入姓名:"<<endl;
	cin>>Cus2->Name;
	cout<<"请输入生份证号码："<<endl;
	cin>>Cus2->ID;
	cout<<"请输入舱位等级:"<<endl;
	cin>>Cus2->Level;
	cout<<"你的座位号为："<<endl;
	cout<<Cus2->SeatNum++<<" ";	
	cout<<endl;
	if (q->CustName->next==NULL)
	{
		Cusrear=q->CustName;
		Cusrear->next=Cus2;
		Cusrear=Cus2;
		Cusrear->next=NULL;
 
	}
	else{
		Cusrear->next=Cus2;
		Cusrear=Cus2;
		Cusrear->next=NULL;
	}
    q->FreeTicket-=1;
}

void Buyreplace(PFlight q,int n)   //进入候补队列
{
	Replace *Rep2;
	Rep2=new Replace;
	if(n==1)
	{
		q->ReplacePas+=1;
		strcpy(Rep2->FlightNum,q->FlightNum);
		cout<<"请输入姓名:"<<endl;
		cin>>Rep2->Name;
		cout<<"请输入生份证号码："<<endl;
		cin>>Rep2->ID;
		cout<<"请输入舱位等级(1-3):"<<endl;
        cin>>Rep2->Level;
		if(q->ReplName->next==NULL)
		{
			Reprear=q->ReplName;
			Reprear->next=Rep2;
			Reprear=Rep2;
            Reprear->next=NULL;
		}
		else{
			Reprear->next=Rep2;
            Reprear=Rep2;
			Reprear->next=NULL;
		}
	}
}

void FlightCancelticket()   //退票
{
 	
	Flight *p,*q;
	Customer *h,*j;
	char FlightNum[6];
	char ID[10];
	int i=0;
	while (i!=1)
	{
		cout<<"请输入需要退定的航班号:"<<endl;
		cin>>FlightNum;
		p=head;
		while (p->next&&strcmp(p->next->FlightNum,FlightNum))
		{
			p=p->next;
		}
		q=p->next;
		if (q==NULL)
		{
			cout<<"对不起不存在此航班"<<endl;
		}
		else
		{
			while (i!=2)
			{
				cout<<"请输入身份证号码:"<<endl;
				cin>>ID;
				h=q->CustName;

				while (h->next&&strcmp(h->next->ID,ID))
				{
					h=h->next;
				}
				j=h->next;
				if(j==NULL)
				{
					cout<<"查无此人"<<endl;
				}
				else
				{
					if(j->next==NULL){    //当删除最后一个结点
						Cusrear=h;
					} 
					h->next=h->next->next;
					q->FreeTicket+=1;
					delete j; 
					cout<<"删除成功！"<<endl;
					if(q->ReplName->next!=NULL)
					{
						if (1<=q->FreeTicket)
						{
							Replace *rep;
							rep=q->ReplName->next;
							Customer *Cus2;
							Cus2=new Customer;
							Cus2->SeatNum=q->Ration-q->FreeTicket+1;
							
							//流水号
							time_t t;  //秒时间  
						    tm* local; //本地时间   
							tm* gmt;   //格林威治时间  
							char buf[128]= {0};  
							t = time(NULL); //获取目前秒时间  
							local = localtime(&t); //转为本地时间  
							strftime(buf, 64, "%Y%m%d%H%M%S", local);
							strcpy(Cus2->No,buf);

							strcpy(Cus2->FlightNum, q->FlightNum );
							strcpy(Cus2->Name, rep->Name );
							strcpy(Cus2->ID,rep->ID);
							
							Cus2->Level=rep->Level;
							cout<<"乘客"<<rep->Name<<"已经成功买票 "<<endl;
							cout<<"流水号为："<< Cus2->No<<endl;
							cout<<"座位号为:";
							cout<<Cus2->SeatNum++<<" ";
							cout<<endl;
							if (q->CustName->next==NULL)
							{
								Cusrear=q->CustName;
								Cusrear->next=Cus2;
								Cusrear=Cus2;
								Cusrear->next=NULL;
							}
							else
							{
								Cusrear->next=Cus2;
								Cusrear=Cus2;
								Cusrear->next=NULL;
							}
							q->FreeTicket-=1;
							q->ReplName->next=q->ReplName->next->next;
							q->ReplacePas--;
							delete rep;
						}
					}
				}
				cout<<"2、退出姓名录入"<<endl;
				cin>>i;
			}
		}
		cout<<"1、返回主菜单"<<endl;
		cin>>i;
	}
}

void Flightclean()
{
	head->next=rear->next;
	cout<<"系统已经清空！"<<endl;
}


