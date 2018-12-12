#include "Core\Condition.h"
#include "EventBus.h"

EventBus* EventBus::_entity = new EventBus();

EventBus::EventBus()
{
}

EventBus* EventBus::Get()
{
	return EventBus::_entity;
}

void EventBus::Add(Event*const event)
{
	Condition::IsNotNull(event, nameof(event));
	this->_events_mutex.lock();
	this->_events.push_back(event);
	this->_events_mutex.unlock();
}

Event* EventBus::getFirstAndRemove(const int eventTypeId)
{
	Event* result = NULL;
	this->_events_mutex.lock();

	std::list<Event*>::iterator iterWithMinIndex = this->_events.begin();
	int firstInvalidIndex = Event::MAX_INDEX + 1;
	int minIndex = firstInvalidIndex;
	for (auto i = this->_events.begin(); i != this->_events.end(); ++i) 
	{
		if ((*i)->getTypeId() == eventTypeId) {
			if (minIndex > (*i)->getIndex()) {
				minIndex = (*i)->getIndex();
				iterWithMinIndex = i;
			}
		}
	}

	if (minIndex < firstInvalidIndex)
	{
		result = *iterWithMinIndex;
		this->_events.remove(*iterWithMinIndex);
	}

	this->_events_mutex.unlock();
	return result;
}

void EventBus::Remove(Event * const event)
{
	Condition::IsNotNull(event, nameof(event));
	this->_events_mutex.lock();
	this->_events.remove(event);
	this->_events_mutex.unlock();
}