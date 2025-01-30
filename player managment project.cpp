#include<iostream>
#include<string>
using namespace std;

class player
{

	public:
		int id;
		string name;
		int age;
		string team;
		int matchesplayed;
		
		
	player(int age,string name, int id,int matchesplayed,string team)
	{
		this->age=age;
		this->name=name;
		this->id=id;
		this->matchesplayed=matchesplayed;
	
		this->team=team;
	}
	void display()
	{
		cout<<" PlayerID :"<<id;
		cout<<" Player Name :"<<name;
		cout<<"Player age :"<<age;
		cout<<"Matchesplayed :"<<matchesplayed;
		cout<<"Player Team :"<<team;
	}
};
class player_management:public player

	
	
		void addplayer()
		{
			cout<<"Eneter a player ID  : ";
			cin>>id;
			cout<<"Enetr a Name :";
			cin.ignore();
			getline.(cin,name);
			cout<<"Enetr age :";
			cin>>age;
			cout<<"Enter a team :"
			cin.ignore();
			getline(cin,team);
			cout<<"Enetr matches played:";
			cin>>matchesplayed;
				
		
	
		}
	};
		
	
