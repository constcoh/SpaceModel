#pragma once

#include "Core\EventBus\EventBus.h"
#include <iostream>

void eventBusTest(){
	const int TYPE1 = Event::getNotUsedTypeId();
	const int TYPE2 = 2;
	EventBus* bus = EventBus::Get();
	Event* ev1_0 = new Event(TYPE1, 0);
	Event* ev1_1 = new Event(TYPE1, 1);
	Event* ev2_0 = new Event(TYPE2, 0);
	Event* ev2_1 = new Event(TYPE2, 1);
	bus->Add(ev1_1);
	bus->Add(ev1_0);
	bus->Add(ev2_0);
	bus->Add(ev2_1);

	Event* p1 = bus->getFirstAndRemove(TYPE1);
	Event* p2 = bus->getFirstAndRemove(TYPE1);
	Event* p3 = bus->getFirstAndRemove(TYPE2);
	Event* p4 = bus->getFirstAndRemove(TYPE2);
	Event* p5 = bus->getFirstAndRemove(TYPE1);
	Event* p6 = bus->getFirstAndRemove(TYPE2);

	// Expected correct values returned from the bus:
	std::cout << "ev1_0:" << ev1_0 << " found:" << p1 << std::endl;
	std::cout << "ev1_1:" << ev1_1 << " found:" << p2 << std::endl;
	std::cout << "ev2_0:" << ev2_0 << " found:" << p3 << std::endl;
	std::cout << "ev2_1:" << ev2_1 << " found:" << p4 << std::endl;

	// Expected NULL as return value from EventBus:
	std::cout << "type1:" << p5 << std::endl;
	std::cout << "type2:" << p6 << std::endl;

	int i;
}