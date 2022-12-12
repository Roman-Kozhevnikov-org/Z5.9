#pragma once
#include "SnackSlot.h"
#include <iostream>
class VendMach
{
private:
	
	
	int numSlot;
	SnackSlot* pss = nullptr;
	

public:

	VendMach();
	VendMach(int); 
	~VendMach();
	VendMach(VendMach&);
	VendMach(VendMach&&);
	VendMach& operator=(VendMach&);
	VendMach& operator=(VendMach&&);
	SnackSlot& operator[](int i);	
	void addSlot(SnackSlot*);		
	SnackSlot outSlot(int);
	void buySnack(Snack*);
	int numFoolBox();
	friend ostream& operator<<(ostream&, VendMach&);
	int getEmptySlotsCount();
	void coutBoxSlotEmpty();


};

