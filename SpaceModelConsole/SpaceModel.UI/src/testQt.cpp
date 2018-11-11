#pragma once


#include "testQt.h"
#include <QtWidgets\qapplication.h>
#include <QtWidgets\qpushbutton.h>

#include <iostream>
using namespace std;

int mainQt(int argc, char **argv)
{
	QApplication a(argc, argv);

	QPushButton hello("Hello world!");
	hello.resize(100, 30);

	hello.show();
	return a.exec();
}