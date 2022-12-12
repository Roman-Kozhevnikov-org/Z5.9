#pragma once
#include <string>
using namespace std;


class Snack
{
private:	
	string name;
	double price = 0;

public:	
	Snack();	
	Snack(string);
	void setname(string);	
	void setprice(double);
	void setSnickers(double = 200);
	void setBounty(double = 150);
	string getname() const; 
	double getprice() const;
	friend ostream& operator<<(ostream&, Snack&);



};

