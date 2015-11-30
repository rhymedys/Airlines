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
	        cout<<"       ***************���չ�˾���˶�Ʊϵͳ***************"<<endl;
			cout<<"       *     1������Ա����         2���ͻ���������      *"<<endl;
			cout<<"       *     3���˳�ϵͳ                                *"<<endl;
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
				cout<<"       *********************����Ա����*******************"<<endl;
				cout<<"       *     1�����Ӻ���               2����ѯ����      *"<<endl;
				cout<<"       *     3���޸ĺ���               4��ɾ������      *"<<endl;
				cout<<"       *     5�����ϵͳ               6���������˵�    *"<<endl;
		        cout<<"       *     7���˳�ϵͳ                                *"<<endl;
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
				cout<<"       *********************��������********************"<<endl;
				cout<<"       *     1����ѯ����               2��Ԥ����Ʊ      *"<<endl;
				cout<<"       *     3���˶���Ʊ               4���������˵�    *"<<endl;
				cout<<"       *     5���˳�ϵͳ                                *"<<endl;
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

void FlightInsert()   //�������
{
    Flight *p;
    p=new Flight;
	cout<<"���������վ��"<<endl;
	cin>>p->star;
    cout<<"�������յ�վ��:"<<endl;
    cin>>p->Des;
    cout<<"�����뺽���:"<<endl;
    cin>>p->FlightNum;
    cout<<"������ɻ���:"<<endl;
    cin>>p->PlaneNum;
    cout<<"�������������:"<<endl;
    cin>>p->week;
	cout<<" ���������ʱ�䣺"<<endl;
	cin>>p->StartTime;
	cout<<"�����뵽��ʱ�䣺"<<endl;
	cin>>p->EndTime;
    cout<<"�������Ա����:"<<endl;
    cin>>p->Ration;
    p->FreeTicket=p->Ration;
    cout<<"�������λ�ȼ��ļ۸�:"<<endl;
    cout<<"ͷ�Ȳռ۸�"<<endl;
    cin>>p->Price[0];
    cout<<"��ͨ�ռ۸�"<<endl;
    cin>>p->Price[1];
    cout<<"���òռ۸�"<<endl;
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

void FlightDelete()   //ɾ������
{
	Flight *p,*q;
	char FlightNum[10];
	p=head;
	int i=0;
	while (i!=1)
	{
		cout<<"��������Ҫɾ���ĺ����:"<<endl;
		cin>>FlightNum;
		while (p->next&&strcmp(p->next->FlightNum,FlightNum))
		{
			p=p->next;
		}     
		q=p->next;
		if (q!=NULL)
		{
			if(q->next==NULL)
			{    //��ɾ��rear��ָ��Ľ��
				rear=p;
			}
            p->next=p->next->next;
			delete q;
		}
        else
		{
			cout<<"����Ҫɾ���ĺ��಻����"<<endl;
		}
		cout<<"1���˳�2������"<<endl;
		cin>>i;
	}
}

void adminFlightLookup()   //��ѯ����
{
	Flight *p,*q;
	char FlightNum[10];	
	int i=0;
	p=head;
	while (i!=1)
	{
		
		cout<<"��������Ҫ��ѯ�ĺ����:"<<endl;
		cin>>FlightNum;
		while (p->next&&strcmp(p->next->FlightNum,FlightNum))
		{
			p=p->next;
		}
		q=p->next;
		if (q==NULL)
		{
			cout<<"�Բ��𲻴��ڴ˺���"<<endl;
		}
		else
		{
			cout<<"�����:"<<q->FlightNum<<endl;
			cout<<"�ɻ���:"<<q->PlaneNum<<endl;
			cout<<"�����أ�"<<q->star<<endl;
			cout<<"Ŀ�ĵ�:"<<q->Des<<endl;
			cout<<"��������:"<<q->week<<endl;
			cout<<"����ʱ�䣺"<<q->StartTime<<endl;
			cout<<"����ʱ�䣺"<<q->EndTime<<endl;
			cout<<"��Ա����:"<<q->Ration<<endl;
			cout<<"�򲹳˿���:"<<q->ReplacePas<<endl;
			cout<<"ͷ�Ȳռ۸�:"<<q->Price[0]<<endl;
			cout<<"��ͨ�ռ۸�:"<<q->Price[1]<<endl;
			cout<<"���òռ۸�:"<<q->Price[2]<<endl;
		}
		cout<<"1���������˵� 2������"<<endl;
		cin>>i;
	}
}

void FlightLookup()   //��ѯ����
{
	Flight *p,*q;
	char Des[10];	
	char start[10];
	int i=0;
	p=head;

	while (i!=1)
	{		
		cout<<"��������Ҫ��ѯ�ĺ��������:"<<endl;
		cin>>start;
		cout<<"��������Ҫ��ѯ�ĺ���Ŀ�ĵ�:"<<endl;
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
			cout<<"�Բ��𲻴��ڴ˺���"<<endl;
		}
		else
		{
			cout<<"�����:"<<q->FlightNum<<endl;
			cout<<"�ɻ���:"<<q->PlaneNum<<endl;
			cout<<"�����أ�"<<q->star<<endl;
			cout<<"Ŀ�ĵ�:"<<q->Des<<endl;
			cout<<"��������:"<<q->week<<endl;
			cout<<"����ʱ�䣺"<<q->StartTime<<endl;
			cout<<"����ʱ�䣺"<<q->EndTime<<endl;
			cout<<"��Ա����:"<<q->Ration<<endl;
			cout<<"ʣ��Ʊ��:"<<q->FreeTicket<<endl;
			cout<<"�򲹳˿���:"<<q->ReplacePas<<endl;
			cout<<"ͷ�Ȳռ۸�:"<<q->Price[0]<<endl;
			cout<<"��ͨ�ռ۸�:"<<q->Price[1]<<endl;
			cout<<"���òռ۸�:"<<q->Price[2]<<endl;
		}
		cout<<"1���������˵� 2������"<<endl;
		cin>>i;
	}
}

void FlightRework()   //�޸ĺ�����Ϣ
{
	int Customer_Number ;
	Flight *p,*q;
	char FlightNum[10];
	char i='0';
	p=head;
	cout<<"��������Ҫ�޸ĵĺ����:"<<endl;
	cin>>FlightNum;
	while (p->next&&strcmp(p->next->FlightNum,FlightNum))
	{
		p=p->next;
	}
	q=p->next;
	if (q==NULL)
	{
		cout<<"�Բ��𲻴��ڴ˺���"<<endl;
	}
	else
	{
		while(i!='12')
		{
			cout<<"     *****��������Ҫ�޸ĵ�����*****"<<endl;
			cout<<"     *1�������        2���ɻ���     *"<<endl;
            cout<<"     *3��������        4��Ŀ�ĵ�     *"<<endl;
			cout<<"     *5����������      6������ʱ��   *"<<endl;
			cout<<"     *7������ʱ��      8����Ա����   *"<<endl;
			cout<<"     *9��ͷ�Ȳռ۸�    10����ͨ�ռ۸�*"<<endl;
            cout<<"     *11�����òռ۸�   12���˳�      *"<<endl;
			cout<<"     **********************************"<<endl;
			cin>>i;
			switch(i)
			{
			case '1':cout<<"�����뺽���:"<<endl;
				cin>>q->FlightNum;break;
			case '2':cout<<"������ɻ���:"<<endl;
                   cin>>q->PlaneNum;break;
			case '3':cout<<"����������أ�"<<endl;
				cin>>q->star;break;
			case '4':cout<<"������Ŀ�ĵ�:"<<endl;
                cin>>q->Des;break;
			case '5':cout<<"�������������:"<<endl;
                cin>>q->week;break;
			case '6':cout<<"���������ʱ�䣺"<<endl;
				cin>>q->StartTime;break;
			case '7':cout<<"�����뵽��ʱ�䣺"<<endl;
				cin>>q->EndTime;break;
			case '8':cout<<"�������Ա����:"<<endl;
				Customer_Number=q->Ration-q->FreeTicket; 
				cin>>q->Ration;q->FreeTicket=q->Ration-Customer_Number;break;
			case '9':cout<<"������ͷ�Ȳռ۸�:"<<endl;
                cin>>q->Price[0];break;
			case '10':cout<<"��������ͨ�ռ۸�:"<<endl;
                cin>>q->Price[1];break;
			case '11':cout<<"�����뾭�òռ۸�:"<<endl;
                 cin>>q->Price[2];break;
            case '12':
				break;
            default:cout<<"error\n";break;
			}
		}
	}
}

void FlightBuyticket() //��Ʊ
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
		cout<<"����������㣺"<<endl;
		cin>>start;
		cout<<"������Ŀ�ĵ�:"<<endl;
		cin>>Des;
		cout<<"������������ڣ�"<<endl;
		cout<<"��������ݣ�"<<endl;
		cin>>year;
		cout<<"�·ݣ�"<<endl;
		cin>>mon;
		cout<<"�գ�"<<endl;
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
			cout<<"�Բ��𲻴��ڴ˺���"<<endl;
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
					cout<<"ʣ��Ʊ��С�ڶ�Ʊ�����Ƿ���Ҫ�����������(1���� 2����)"<<endl;
					cin>>n;
					Buyreplace(q,n);
				}
				cout<<"1���������˵� 2������"<<endl;
				cin>>i;
			}
		}
	}
}

void Buyticket(PFlight q)   //��Ʊ
{
 
	
	Customer *Cus2;
	Cus2=new Customer;
	
	time_t t;  //��ʱ��  
	tm* local; //����ʱ��   
	tm* gmt;   //��������ʱ��  
	char buf[128]= {0};  
	t = time(NULL); //��ȡĿǰ��ʱ��  
	local = localtime(&t); //תΪ����ʱ��  
	strftime(buf, 64, "%Y%m%d%H%M%S", local);
	
	strcpy(Cus2->No,buf);

	Cus2->SeatNum=q->Ration-q->FreeTicket+1;
	strcpy(Cus2->FlightNum, q->FlightNum );
	cout<<"����������:"<<endl;
	cin>>Cus2->Name;
	cout<<"����������֤���룺"<<endl;
	cin>>Cus2->ID;
	cout<<"�������λ�ȼ�:"<<endl;
	cin>>Cus2->Level;
	cout<<"�����λ��Ϊ��"<<endl;
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

void Buyreplace(PFlight q,int n)   //����򲹶���
{
	Replace *Rep2;
	Rep2=new Replace;
	if(n==1)
	{
		q->ReplacePas+=1;
		strcpy(Rep2->FlightNum,q->FlightNum);
		cout<<"����������:"<<endl;
		cin>>Rep2->Name;
		cout<<"����������֤���룺"<<endl;
		cin>>Rep2->ID;
		cout<<"�������λ�ȼ�(1-3):"<<endl;
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

void FlightCancelticket()   //��Ʊ
{
 	
	Flight *p,*q;
	Customer *h,*j;
	char FlightNum[6];
	char ID[10];
	int i=0;
	while (i!=1)
	{
		cout<<"��������Ҫ�˶��ĺ����:"<<endl;
		cin>>FlightNum;
		p=head;
		while (p->next&&strcmp(p->next->FlightNum,FlightNum))
		{
			p=p->next;
		}
		q=p->next;
		if (q==NULL)
		{
			cout<<"�Բ��𲻴��ڴ˺���"<<endl;
		}
		else
		{
			while (i!=2)
			{
				cout<<"���������֤����:"<<endl;
				cin>>ID;
				h=q->CustName;

				while (h->next&&strcmp(h->next->ID,ID))
				{
					h=h->next;
				}
				j=h->next;
				if(j==NULL)
				{
					cout<<"���޴���"<<endl;
				}
				else
				{
					if(j->next==NULL){    //��ɾ�����һ�����
						Cusrear=h;
					} 
					h->next=h->next->next;
					q->FreeTicket+=1;
					delete j; 
					cout<<"ɾ���ɹ���"<<endl;
					if(q->ReplName->next!=NULL)
					{
						if (1<=q->FreeTicket)
						{
							Replace *rep;
							rep=q->ReplName->next;
							Customer *Cus2;
							Cus2=new Customer;
							Cus2->SeatNum=q->Ration-q->FreeTicket+1;
							
							//��ˮ��
							time_t t;  //��ʱ��  
						    tm* local; //����ʱ��   
							tm* gmt;   //��������ʱ��  
							char buf[128]= {0};  
							t = time(NULL); //��ȡĿǰ��ʱ��  
							local = localtime(&t); //תΪ����ʱ��  
							strftime(buf, 64, "%Y%m%d%H%M%S", local);
							strcpy(Cus2->No,buf);

							strcpy(Cus2->FlightNum, q->FlightNum );
							strcpy(Cus2->Name, rep->Name );
							strcpy(Cus2->ID,rep->ID);
							
							Cus2->Level=rep->Level;
							cout<<"�˿�"<<rep->Name<<"�Ѿ��ɹ���Ʊ "<<endl;
							cout<<"��ˮ��Ϊ��"<< Cus2->No<<endl;
							cout<<"��λ��Ϊ:";
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
				cout<<"2���˳�����¼��"<<endl;
				cin>>i;
			}
		}
		cout<<"1���������˵�"<<endl;
		cin>>i;
	}
}

void Flightclean()
{
	head->next=rear->next;
	cout<<"ϵͳ�Ѿ���գ�"<<endl;
}


