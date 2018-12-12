#include "Event.h"

int Event::_createdEventsCount = 0;
std::mutex Event::_createdEventsCount_mutex;

int Event::_notUsedTypeId = 1;
std::mutex Event::_notUsedTypeId_mutex;

const int Event::MAX_INDEX = INT_MAX - 1;

int Event::getNewId()
{
	int result = 0;
	Event::_createdEventsCount_mutex.lock();
	result = Event::_createdEventsCount++;
	Event::_createdEventsCount_mutex.unlock();
	return result;
}

int Event::getNotUsedTypeId()
{
	int result = 0;
	Event::_notUsedTypeId_mutex.lock();
	result = Event::_notUsedTypeId++;
	Event::_notUsedTypeId_mutex.unlock();
	return result;
}

Event::Event(const int typeId)
{
	this->_id = Event::getNewId();
	this->_createdTime = time(0);
	this->_typeId = typeId;
	this->_index = 0;
}

Event::Event(const int typeId, const int index)
{
	this->_id = Event::getNewId();
	this->_createdTime = time(0);
	this->_typeId = typeId;
	this->_index = index;
}

Event::Event(Event &arg)
{
	this->_id = Event::_id;
	this->_index = arg._index;
	this->_createdTime = Event::_createdTime;
	this->_typeId = arg._typeId;
}

const char * Event::getEventTypeName() const
{
	return "Event";
}

int Event::getTypeId()
{
	return this->_typeId;
}

int Event::getIndex()
{
	return this->_index;
}