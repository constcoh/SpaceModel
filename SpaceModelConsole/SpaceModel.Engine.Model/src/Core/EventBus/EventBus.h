#include <list>
#include <mutex>

#include "Event.h"

class EventBus
{
private:
	static EventBus* _entity;
	std::list<Event*> _events;
	std::mutex _events_mutex;
public:
	EventBus();
	static EventBus* Get();
	void Add(Event * const event);
	Event* getFirstAndRemove(const int eventTypeId);
	void Remove(Event * const event);
};