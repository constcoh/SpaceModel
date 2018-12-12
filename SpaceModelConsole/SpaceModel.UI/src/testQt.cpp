#pragma once


#include "testQt.h"
#include <QtWidgets\qapplication.h>
#include <QtWidgets\qwidget.h>
#include <QtWidgets\qlabel.h>
#include <QtCore\qtimer.h>

#include <iostream>
using namespace std;


unsigned char * CreateBuffer(
	const int w,
	const  int  h,
	const int b,
	const int g,
	const int r,
	const int a)//0 - transparent, 255 - full
{
	int bufferSize = w*h;
	unsigned char * buffer = new unsigned char[4*bufferSize];
	for (int i = 0; i < bufferSize; ++i) {
		buffer[4 * i] = b;
		buffer[4 * i+1] = g;
		buffer[4 * i+2] = r;
		buffer[4 * i+3] = a;
	}

	return buffer;
}

int testQt(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget rootWidget;

	rootWidget.resize(820, 620);

	QLabel *viewPort = new QLabel(&rootWidget);
	viewPort->resize(800, 600);
	viewPort->move(10, 10);

	// Example with qpallete:
	////QPalette pal;
	////pal.setColor(QPalette::Background, QColor(0,0,0));
	////viewPort->setAutoFillBackground(true);
	////viewPort->setPalette(pal);

	// Example with buffer:
	unsigned char * buffer = CreateBuffer(800, 600, 255, 0, 255, 255);
	QImage img(buffer, 800, 600, QImage::Format_ARGB32);
	auto pixmap = QPixmap::fromImage(img);
	viewPort->setPixmap(pixmap);

	rootWidget.show();
	////for (int i = 0; i < 800 * 600; ++i) {
	////	buffer[i] = 0;
	////}
	QImage img2(buffer, 800, 600, QImage::Format_ARGB32);
	pixmap.convertFromImage(img2);
	viewPort->setPixmap(pixmap);
	viewPort->update();

	return app.exec();
}
