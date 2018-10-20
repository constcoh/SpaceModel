#include "3DEngine.h"

#include <iostream>
using namespace std;

class TestClass {
public:
	static int createdCount;
	int index;
	int value;
	int *p;
	void log() const { cout <<" ("<<index << ":"<<value << ")"; }
	TestClass() {
		index = createdCount++;
		value = index;
		p = new int;
		cout << "created:"; log(); cout<< endl;
	}

	~TestClass() {
		p = NULL;
		cout << "deleted:"; log(); cout << endl;
	}

	TestClass(const TestClass  &arg) {
		index = createdCount++;
		value = arg.value;
		p = new int;
		cout << "created copy of:"; arg.log(); cout << " as"; log(); cout << endl;
	}
	TestClass& operator =(const TestClass& arg) {
		value = arg.value;
		cout << "operator = arg:"; arg.log(); cout << " current:"; log(); cout << endl;
		return *this;
	}
};

TestClass method(TestClass a) {
	cout << "call method arg:"; a.log(); cout << endl;
	TestClass e;
	return TestClass(e);
}

int TestClass::createdCount = 0;

int main() {
	////int q = testFunction(4, 2);
	////{
	////	TestClass a;
 ////		TestClass b = a;
	////	TestClass c = a;
	////	cout << "log a:"; a.log(); cout << " b:"; b.log(); cout << " c:"; c.log(); cout << endl;
	////	c = method(method(method(b)));
	////	cout << "log a:"; a.log(); cout << " b:"; b.log(); cout << " c:"; c.log(); cout << endl;
	////}
	const char* str = "hell";
	std::string buildedstring(str);
	std::cout << "str:" << buildedstring.data()<<std::endl;

	return 0;
}