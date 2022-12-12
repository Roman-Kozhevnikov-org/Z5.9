#include "VendMach.h"


VendMach::VendMach()
{
	numSlot = 4;
	pss = new SnackSlot[numSlot]();
	
}

VendMach::VendMach(int sn)
{
    numSlot = sn;
	pss = new SnackSlot[numSlot]();	
}

VendMach::~VendMach() { delete[] pss; }

VendMach::VendMach(VendMach& ss)
{
	numSlot = ss.numSlot;
	pss = new SnackSlot[numSlot]();
	for (int i = 0; i < numSlot; ++i)
	{
		pss[i] = ss.pss[i];
	}	
}

VendMach::VendMach(VendMach&& ss)
{
	numSlot = ss.numSlot;
	pss = ss.pss;	
	ss.pss = nullptr;
	ss.numSlot = 0;
}

VendMach& VendMach::operator=(VendMach& ss)
{
	if (this == &ss)
		return *this;
	delete[] pss;
	numSlot = ss.numSlot;
	pss = new SnackSlot[numSlot]();
	for (int i = 0; i < numSlot; ++i)
	{
		pss[i] = ss.pss[i];
	}	
	return *this;
}

VendMach& VendMach::operator=(VendMach&& ss)
{
	if (this == &ss)
		return *this;
	delete[] pss;
	numSlot = ss.numSlot;
	pss = ss.pss;
	ss.pss = nullptr;
	ss.numSlot = 0;
	
	    return *this;
}

void VendMach::addSlot(SnackSlot* slt)
{
	cout << "������������ ������� ����� � ������....\n";
	int count(0);
	for (int i = 0; i < numSlot; ++i)
	{
		if (pss[i].isSlotIn())
			continue;
		else {
			    if (!(slt->isSlotIn()))
				      slt->turnSlotin();				
				pss[i] = *slt;			
				cout << "���� �������� � ������ N " << i << endl;
			    count++;
			    break;
		      }
	}
	if (!count)
		cout << "��� ����� ������, �������� ����!\n";
}

SnackSlot VendMach::outSlot(int i)
{   
	cout << "������������ ������� ����� �� ������....\n";
	if (i == -1)
	{
		cout << "��� ������ ������, �������� ����� ! \n ";
		return SnackSlot();
	}
	else if (pss[i].isSlotIn())
	{
		pss[i].turnSlotin();
		cout << " C��� ����� �� " << i << " ������ " << endl;
		return pss[i];
	}
	else {
		cout << "������ ������, ��������� ���� �� ������)) \n";		
		return SnackSlot();
	     }
		
}

void VendMach::buySnack(Snack* snk)
{   
	bool _switch = true;
	cout << "���������� ������ ���� : " << *snk << endl;
	for (int i = 0; i < numSlot; ++i)
		if (!(pss[i].isSlotEmpty()))
		{
			for (int j = 0; j < pss[i].getmaxnum(); ++j)
			{
				if (pss[i].getSnackname(j) == snk->getname())
				{
					pss[i].outSnack(snk);
					cout << "���� " << snk->getname() << " ������ ! \n";
					_switch = !_switch;					
					break;
				}
				else continue;
			} 			
		  
		  if (_switch)
		  cout << "� ����� " << i << " ��� " << snk->getname() << endl;
		  continue;
		}
	    else continue;
	    if (_switch)
	    cout << " � ������ ��� ����������� �������� ��� �������! \n";
}

int VendMach::numFoolBox()
{
	for (int i = 0; i < numSlot; ++i)
		if (pss[i].isSlotIn())
			return  i;
		else return -1;
}   

SnackSlot& VendMach::operator[](int i)
{
	if (i < numSlot && i >= 0)
		return pss[i];
	else cout << "���� �������!!!!!!:) \n";
	    return pss[0];
}

	ostream& operator<<(ostream& co, VendMach& vm)
	{
		int count(0);
		co << " � ������ ��������� ��������� ����� : \n";
		for (int i = 0; i < vm.numSlot; ++i)
		{
			cout << "     N " << i << endl;
			co << vm.pss[i];
			count++;
		}
		co << "����� " << count << " ������ " << endl;
		return co;
	}

	int VendMach:: getEmptySlotsCount()
	{   		
		int count(0);
		for (int i = 0; i < numSlot; ++i)
			if (pss[i].isSlotEmpty())
				count++;
		return count;
	}

	void VendMach::coutBoxSlotEmpty()
	{
		for (int i = 0; i < numSlot; ++i)
		{
			if (pss[i].isSlotEmpty())
				cout << "������ ���� � ������ N " << i << " ";
			cout << endl;
		}
	}