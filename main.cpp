#include <iostream>
//#include "Snack.h"include "SnackSlot.h"
#include "VendMach.h"


int main() {
	
	setlocale(LC_ALL, "");
	int slotCount(2);	
	Snack* bounty = new Snack("Bounty");
	Snack* snickers = new Snack("Snickers");
	cout << *bounty << "   " << *snickers << endl;
	
	SnackSlot* slot = new SnackSlot(10);
	slot->addSnack(bounty); 
	slot->addSnack(snickers);
	cout << *slot << endl;
	
	VendMach* machine = new VendMach(slotCount); 
	
	machine->addSlot(slot); 
	cout << *machine << endl;
	
	machine->buySnack(bounty);
	
	cout << *machine << endl;

	SnackSlot changeslot (machine->outSlot(machine->numFoolBox()));
	
	cout << "Заправляем изъятый слот снеками....\n";
	if (changeslot.isSlotEmpty())
		changeslot.setAllSnickers();
	else while (!(changeslot.isSlotFull()))
		          changeslot.addSnack(bounty);
	cout << changeslot << endl;
		machine->addSlot(&changeslot);	
	cout << *machine << endl;
	cout << " Количество пустых слотов : " << machine->getEmptySlotsCount() << endl;
	machine->coutBoxSlotEmpty();
	
	changeslot = (machine->outSlot(1));
	
	cout << "Заправляем изъятый слот снеками....\n";
	if (changeslot.isSlotEmpty())
		changeslot.setAllBounty();
	else while (!(changeslot.isSlotFull()))
		changeslot.addSnack(snickers);
	cout << changeslot << endl;
	
	machine->addSlot(&changeslot);
	cout << *machine << endl;
	cout << " Количество пустых слотов : " << machine->getEmptySlotsCount() << endl;
	machine->coutBoxSlotEmpty();
	
	machine->buySnack(bounty);
	cout << *machine << endl;

	changeslot = (machine->outSlot(1));

	cout << "Заправляем изъятый слот снеками....\n";
	if (changeslot.isSlotEmpty())
		changeslot.setAllBounty();
	else while (!(changeslot.isSlotFull()))
		changeslot.addSnack(snickers);
	cout << changeslot << endl;

	machine->addSlot(&changeslot);
	cout << *machine << endl;
	cout << " Количество пустых слотов : " << machine->getEmptySlotsCount() << endl;
	machine->coutBoxSlotEmpty();


	delete machine;
	delete slot;
	delete snickers;
	delete bounty;

	return 0;
// add comment for check access to the ...org depo
		
}
