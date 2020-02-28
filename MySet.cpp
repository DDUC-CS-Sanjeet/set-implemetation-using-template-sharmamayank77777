//SET IMPLEMENTATIONS USING TEMPLATES
//-MAYANK SHARMA(19HCS4034)
#include<iostream>
#include<math.h>
using namespace std;
template<class t>
class MySet
{
	private:
		int size;
		t *arr1;
	public:
		MySet<t>()
		{
			size=0;
		}
			
		MySet<t>(int n)
		{
			size=n;
			arr1=new t[size];
		}
		void input()
		{
			for(int i=0;i<size;i++)
			{
				cin>>arr1[i];
			}
			rem_dupl();
		}
		void rem_dupl()
		{
			for(int i=0;i<size-1;i++)
			{
				for(int j=i+1;j<size;j++)
				{
					if(arr1[i]==arr1[j])
					{
						for(int k=j;k<size;k++)
						arr1[k]=arr1[k+1];
						size--;
						i--;
					}
				}
			}
		}
		int card() const
		{
			return size;
		}

	void power_set()
    {
		int s,j,i,count=0;
		s=pow(2,this->size);
		cout<<"{{";
		for(i=0;i<s;i++)
		{	
			count++;
			cout<<"{";
			for(j=0;j<size;j++)
			{
				if(i &(1<<j))
				cout<<(this->arr1[j])<<",";
			}
				cout<<"\b}";
				if(i<s-1)
				cout<<",";
		}
			cout<<"}";
			cout<<"\nCARDINALITY OF SET is:"<<count;
			cout<<"\n";
	}
		void display()
		{
			cout<<"{ ";
			for(int i=0;i<size;i++)
			{
				cout<<arr1[i];
				if(i<size-1)
				{
					cout<<",";
				}
			}
			cout<<" }";
			cout<<"\nCARDINALITY OF SET is:"<<card();
			cout<<"\n";
		}
		MySet operator +(MySet const &ob);
		MySet operator -(MySet const &ob);
		MySet operator ^(MySet  &ob);
		MySet operator *(MySet const &ob);
	    const MySet& operator =(const MySet& ob);
		bool operator ==(MySet const &ob);	
};
		template<typename t>
		MySet<t> MySet<t>:: operator +(MySet<t> const &ob)
		{
			int s,s1,s2;
			s1=this->card();
			s2=ob.card();
			s=s1+s2;
			MySet temp(s);
			int k=0;
			for(int i=0;i<this->size;i++)
			{
				temp.arr1[k++]=this->arr1[i];
			}
			for(int j=0;j<ob.size;j++)
			{
				temp.arr1[k++]=ob.arr1[j];
			}
			temp.rem_dupl();
			return temp;
		}
		template<typename t> 
	MySet<t> MySet<t>:: operator *(MySet<t> const &ob)
	{
		int s1;
		s1=this->card();
		MySet temp(0);
		int k=0;
		for(int i=0;i<this->size;i++)
		{
			for(int j=0;j<ob.size;j++)
			{
				if(this->arr1[i]==ob.arr1[j])
				{	
					++temp.size;
					temp.arr1[k++]=this->arr1[i];	
				}
			}
		}
		return temp;
	} 
    	template<typename t>
		MySet<t> MySet<t>:: operator -(MySet<t> const &ob)
		{
			int s;
			s=this->card();
			if(s==0)
			return *this;
			MySet<t> temp(s);
			int k=0,flag;
			for(int i=0;i<this->size;i++)
			{
				flag=0;
				for(int j=0;j<ob.size;j++)
				{
					if(this->arr1[i]==ob.arr1[j])
					{	
						flag++;
						temp.size--;	
					}
				}
				if(flag==0)
				{
					temp.arr1[k]=this->arr1[i];
					k++;
				}
			}
			return temp;
		}
		template<typename t>
		MySet<t> MySet<t>:: operator ^(MySet<t> &ob)
		{
			int s1,s2,s,count=0;
			s1=this->card();
			s2=ob.card();
			MySet<t> temp1(s1);
			temp1=*this;
			for(int i=0;i<this->size;i++)
			{
				for(int j=0;j<ob.size;j++)
				{
					if(this->arr1[i]==ob.arr1[j])
					{
						count++;
						break;
					}
				}
			}
			s1=s1-count;
			s2=s2-count;
			s=s1+s2;
			MySet<t> temp(s),temp2(s1),temp3(s2);
			temp2=*this-ob;
			temp3=ob-temp1;
			temp=temp2+temp3;
			return temp;
		}
	template<typename t>
	const MySet<t>& MySet<t>:: operator=(const MySet<t>& ob)
		{
			this->size=ob.size;
			this->arr1=new t[this->size];
			for(int i=0;i<ob.size;i++)
			{
				this->arr1[i]=ob.arr1[i];
			}
			return *this;
		}
		template<typename t>
	 bool MySet<t>:: operator==(MySet<t> const &ob)
		{
			bool isEqual =false;
			int flag=0;
			if(this->size==ob.size)
			{
				for(int i=0;i<this->size;i++)
				{
					for(int j=0;j<ob.size;j++)
					{
						if(this->arr1[i]==ob.arr1[j])
						{
							flag++;
						}
					}
				}
				if(flag==this->size)
				{
					isEqual=true;
				}
			}
			return isEqual;
		}
template<typename t>
void play(t typeVar)
{
	int s1,s2,n;
	char ch;
	cout<<"\nENTER SIZE OF FIRST SET:";
	cin>>s1;
	cout<<"\nENTER SIZE OF SECOND SET:";
	cin>>s2;
	//s=s1+s2;
	MySet<t> ob1(s1),ob2(s2);
	cout<<"\nENTER ELEMENTS OF FIRST SET:";
	ob1.input();
	cout<<"\nENTER ELEMENTS OF SECOND SET:";
	ob2.input();
	cout<<"YOUR FIRST SET IS:\n";
	ob1.display();
	cout<<"YOUR SECOND SET IS:\n";
	ob2.display();
		do{
		cout<<"\t\t***********    MENU    ***********\n"
			<<"\t\t1.UNION OF SETS\n"
			<<"\t\t2.INTERSECTION OF SETS\n"
			<<"\t\t3.SET DIFFERENCE(I SET - II SET)\n"
			<<"\t\t4.SYMMETRIC DIFFERENCE\n"
			<<"\t\t5.ASSIGNMENT OPERATOR\n"
			<<"\t\t6.EQUALITY OF SETS\n"
			<<"\t\t7.PRINT POWERSET OF SETS\n"
			<<"\t\tENTER YOUR CHOICE(1-7):";
			cin>>n;
			cout<<"\n";
		switch(n)
		{
			case 1:			{
								MySet<t> ob3=ob1+ob2;
								cout<<"UNION OF SETS IS:\n";
								ob3.display();
								break;
							}		
			case 2:			{
								MySet<t> ob3=ob1*ob2;
								cout<<"\nINTERSECTION OF SETS IS:\n";
								ob3.display();
								break;		
							}
			case 3:			{
								MySet<t> ob3=ob1-ob2;
								cout<<"\nDIFFERENCE OF SETS IS:\n";
								ob3.display();	
								break;
							}	
			case 4:			{
								MySet<t> ob5=ob1^ob2;
								cout<<"\nSYMMETRIC DIFFERENCE IS:\n";
								ob5.display();
								break;
							}				
			case 5:			{
								MySet<t> ob3=ob1;
								MySet<t> ob4=ob2;
								cout<<"\nASSIGNMENT OF FIRST SET IS:\n";
								ob3.display();
								cout<<"\nASSIGNMENT OF SECOND SET IS:\n";
								ob4.display();
								break;
							}				
			case 6:			{
								if(ob1==ob2)
               					{
                    				cout<<"GIVEN SETS ARE EQUAL\n";
               					}
               					else
               					{
                    				cout<<"GIVEN SETS ARE NOT EQUAL\n";
               					}
								break;
							}
			case 7:			{
								cout<<"POWERSET OF FIRST SET:\n";
								ob1.power_set();
								cout<<"\nPOWERSET OF SECOND SET:\n";
								ob2.power_set();
								break;
							}					
			default:  		cout<<"\nWRONG CHOICE!!";
		}
		cout<<"\nDo you want to continue for more operations(y/n):";
		cin>>ch;
		}while(ch=='y'||ch=='Y');
	
}
int main()
{
	int i,n;
	char c,ch;
	float f;
	double d;
	do{
				cout<<"*****   MENU FOR DATA-TYPE SELECTION   *****\n"
					<<"\t1.INT-TYPE\n"
					<<"\t2.CHAR-TYPE\n"
					<<"\t3.FLOAT-TYPE\n"
					<<"\t4.DOUBLE-TYPE\n"
					<<"\tENTER YOUR CHOICE(1-4):";
				cin>>n;
			switch(n)
			{
				case 1:		play(i);
							break;
				case 2:		play(c);
							break;
				case 3:		play(f);
							break;
				case 4:		play(d);
							break;						
				default: 	cout<<"WRONG CHOICE!!";						
			}
			cout<<"DO YOU WANT TO CONTINUE WITH OTHER DATA-TYPES(y/n):\n";
			cin>>ch;
	}while(ch=='y' ||ch=='Y');

	return 0;
}

