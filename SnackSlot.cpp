#include "SnackSlot.h"

SnackSlot::SnackSlot()
{
	maxnum = 10;
	pss = new Snack[maxnum]();	
	top = 0;
}


SnackSlot::SnackSlot(int sn)
{
	maxnum = sn;
	pss = new Snack[maxnum]();	
	top = 0;
}

SnackSlot::~SnackSlot() { delete[] pss; }

SnackSlot::SnackSlot(const SnackSlot& ss)
{
	maxnum = ss.maxnum;
	pss = new Snack[maxnum]();
	for (int i = 0; i < maxnum; ++i)
	{
		pss[i] = ss.pss[i];
	}
	top = ss.top;
	Slotin = ss.Slotin;
}

SnackSlot::SnackSlot(SnackSlot&& ss) 
{
	maxnum = ss.maxnum;
	pss = ss.pss;
	top = ss.top;
	Slotin = ss.Slotin;
	ss.maxnum = 0;
	ss.pss = nullptr;
	ss.top = 0;
	ss.Slotin = 0;
}

SnackSlot& SnackSlot::operator=(const SnackSlot& ss)
{
	if (this == &ss)
		return *this;
	  delete[] pss;	  
	  maxnum = ss.maxnum;
	  pss = new Snack[maxnum]();
	  for (int i = 0; i < maxnum; ++i)
	  {
		  pss[i] = ss.pss[i];
	  }
	  top = ss.top;
	  Slotin = ss.Slotin;
	  return *this;
}

SnackSlot& SnackSlot::operator=(SnackSlot&& ss)
{
	if (this == &ss)
		return *this;
	delete[] pss;
	maxnum = ss.maxnum;
	pss = ss.pss;
	top = ss.top;
	Slotin = ss.Slotin;
	ss.maxnum = 0;
	ss.pss = nullptr;
	ss.top = 0;
	ss.Slotin = 0;
	return *this;
}


void SnackSlot::addSnack(Snack* snk)
{	
	if (!isSlotFull())
		pss[top++] = *snk;
	else cout << "Лоток был полный!\n";
	
}

void SnackSlot::outSnack(Snack* snk)
{
	if (!isSlotEmpty())	
		cout << "Выдан " << pss[--top] << endl;	
	else cout << "Лоток пустой!\n";
}

string SnackSlot::getSnackname(int i)
{
	return pss[i].getname();
}

int SnackSlot::getmaxnum()
{
	return maxnum;
}

int SnackSlot::gettop()
{
	return top;
}

Snack& SnackSlot::operator[](int i)
{
	if (i < maxnum && i >= 0)
		return pss[i];
	else {
		return pss[0];
		cout << "Мимо массива :) \n";
	}
}

void SnackSlot::setAllSnickers()
{   
	for (int i = 0; i < maxnum; ++i)
		pss[i].setSnickers();
	top = maxnum;

}
void SnackSlot::setAllBounty()
{
	for (int i = 0; i < maxnum; ++i)
		  pss[i].setBounty();
	top = maxnum;
}

bool SnackSlot::isSlotFull() const
{
	return top == maxnum;
}
bool SnackSlot::isSlotEmpty() const
{
	return top == 0;
}

ostream& operator<<(ostream& co, SnackSlot& ss)
{
	co << "В слоте находятся следующие снэки : \n";
	for (int i = 0; i < ss.gettop(); ++i)
	{
		co << ss.pss[i] << endl;
		
	}
	co << "итого " << ss.top << " штук " << endl;
	return co;
}

void SnackSlot::turnSlotin()
{
	Slotin = !Slotin;
}

bool SnackSlot::isSlotIn()
{
	return Slotin;
}