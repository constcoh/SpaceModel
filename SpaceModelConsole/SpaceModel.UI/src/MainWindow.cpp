#include "mainWindow.h"

#include <iostream>
using namespace std;

int updatedCount = 0;

const int MainWindow::BORDER = 10;
const int MainWindow::HEIGHT = 600;
const int MainWindow::TIMER_INTERVAL = 10; // in milisecond
										   // value: 10 - 60fps - 7%proc
										   // value: 20 - 15fps

const int MainWindow::WIDTH = 800;

#pragma region Public Methods

MainWindow::MainWindow()
{
	// Create root widget:
	this->rootWidget = new QWidget();
	this->rootWidget->resize(
		WIDTH + 2 * BORDER,
		HEIGHT + 2 * BORDER);

	// Create view port:
	this->viewPort = new QLabel(this->rootWidget);
	this->viewPort->resize(WIDTH, HEIGHT);
	this->viewPort->move(BORDER, BORDER);

	// Create view buffer:
	this->viewPortBuffer = this->CreateBuffer(WIDTH, HEIGHT, 0, 0, 0, 255);
	QImage img(this->viewPortBuffer, WIDTH, HEIGHT, QImage::Format_ARGB32);
	auto pixmap = QPixmap::fromImage(img);
	viewPort->setPixmap(pixmap);

	// Create timer:
	this->timer = new QTimer(this->rootWidget);
	this->timer->setInterval(TIMER_INTERVAL);
	QObject::connect(this->timer,&QTimer::timeout, this, &MainWindow::ViewPortProcess);
}

MainWindow::~MainWindow()
{
	delete rootWidget;
}

void MainWindow::Show()
{
	this->rootWidget->show();
}

void MainWindow::StartViewPortProcessing()
{
	this->timer->start();
}

void MainWindow::StopViewPortProcessing()
{
	this->timer->stop();
}

#pragma endregion Public Methods

#pragma region Private Methods

unsigned char * MainWindow::CreateBuffer(
	const int w,
	const  int  h,
	const int b,
	const int g,
	const int r,
	const int a)//0 - transparent, 255 - full
{
	int bufferSize = w*h;
	unsigned char * buffer = new unsigned char[4 * bufferSize];
	for (int i = 0; i < bufferSize; ++i) {
		buffer[4 * i] = b;
		buffer[4 * i + 1] = g;
		buffer[4 * i + 2] = r;
		buffer[4 * i + 3] = a;
	}

	return buffer;
}

#pragma endregion Private Methods

#pragma region Private Slots

void MainWindow::ViewPortProcess()
{
	// set random greycolor:
	unsigned char color = (unsigned char)(rand() % 256);
	int bufferSize = WIDTH*HEIGHT;
	for (int i = 0; i < bufferSize; ++i) {
		this->viewPortBuffer[4 * i] = color;
		//this->viewPortBuffer[4 * i + 1] = color;
		//this->viewPortBuffer[4 * i + 2] = color;
		this->viewPortBuffer[4 * i + 3] = 255;
	}

	this->viewPortBuffer[100 * 4] = 255;
	this->viewPortBuffer[100 * 4 + 1] = 255;
	this->viewPortBuffer[100 * 4 + 2] = 255;
	this->viewPortBuffer[100 * 4 + 3] = 255;

	++updatedCount;
	if (updatedCount % 300 == 0) {
		cout << updatedCount << endl;
	}

	this->UpdateViewPort();
}

void MainWindow::UpdateViewPort()
{
	static QImage img(this->viewPortBuffer, WIDTH, HEIGHT, QImage::Format_ARGB32);
	this->viewPort->setPixmap(QPixmap::fromImage(img));
	this->viewPort->update();
}

#pragma endregion Private Slots
