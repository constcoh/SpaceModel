#pragma once

#include <ctime>
#include <mutex>

class Event {
private:
	static int _createdEventsCount;
	static std::mutex _createdEventsCount_mutex;
	static int getNewId();

	static int _notUsedTypeId;
	static std::mutex _notUsedTypeId_mutex;

	int _id;
	time_t _createdTime;
	int _index;
	int _typeId;
public:
	static int getNotUsedTypeId();
	static const int MAX_INDEX;

	Event(const int typeId);
	Event(const int typeId, const int index);
	Event(Event &arg);
	int getIndex();
	int getTypeId();
	virtual const char *getEventTypeName() const;
};