#include "Snack.h"
#include <iostream>

Snack::Snack()
{
	name = "No name";	
}

Snack::Snack(string s)
{	
	name = s;
	if (s == "Snickers")
		price = 200;
	else price = 150;
}

void Snack::setname(string s)
{
	name = s;	
}

void Snack::setprice(double x)
{
	price = x;
}

void Snack::setSnickers(double x) 
{
	name = "Snickers";
	price = x;

}
void Snack::setBounty(double x)
{
	name = "Bounty";
	price = x;
}


string Snack::getname() const
{
	return name;
}

double Snack::getprice() const
{
	return price;
}

ostream& operator<<(ostream& co, Snack& snk)
{
	co << snk.name << " by " << snk.price << " ";
	return co;
}