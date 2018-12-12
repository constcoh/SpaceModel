#pragma once

#include <QtCore\qobject.h>
#include <QtCore\qtimer.h>
#include <QtWidgets\qapplication.h>
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qwidget.h>

#include "settings.h"

class MainWindow : public QObject {
private: 
	static const int BORDER;
	static const int HEIGHT;
	static const int TIMER_INTERVAL;
	static const int WIDTH;

	QWidget *rootWidget;
	QTimer *timer;
	QLabel *viewPort;
	unsigned char * viewPortBuffer;
public:
	MainWindow();
	~MainWindow();
	void Show();
	void StartViewPortProcessing();
	void StopViewPortProcessing();
private:
	unsigned char * CreateBuffer(
		const int w,
		const  int  h,
		const int b,
		const int g,
		const int r,
		const int a);//0 - transparent, 255 - full

	void ViewPortProcess();
	void UpdateViewPort();
};