#pragma once
#include "Snack.h"
#include <iostream>


class SnackSlot
{
private:
	
	int maxnum;	
	Snack* pss = nullptr;
	int top;			
	bool Slotin = true;

public:
	SnackSlot();
	SnackSlot(int); 
	~SnackSlot();
	SnackSlot(const SnackSlot&);
	SnackSlot(SnackSlot&&);
	SnackSlot& operator=(const SnackSlot&);
	SnackSlot& operator=(SnackSlot&&);
	Snack& operator[](int i);	
	void setAllSnickers();
	void setAllBounty();
	void addSnack(Snack*);	
	void outSnack(Snack*);
	string getSnackname(int);
	int getmaxnum();
	int gettop();
	friend ostream& operator<<(ostream&, SnackSlot&);
	void turnSlotin();
	bool isSlotIn();
	bool isSlotEmpty() const;
	bool isSlotFull() const;	
};

