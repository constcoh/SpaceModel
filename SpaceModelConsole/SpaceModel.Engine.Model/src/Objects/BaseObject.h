#pragma once

class BaseObject {
private:
	static int _createdObjectsCount;
	int _id;
public:
	BaseObject();

	int getId() const;
	static int getCreatedObjectsCount();
};