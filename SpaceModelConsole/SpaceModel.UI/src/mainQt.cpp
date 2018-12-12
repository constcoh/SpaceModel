
#include <QtWidgets\qapplication.h>

#include "mainWindow.h"
#include "mainQt.h"

int mainQt(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWindow mainWindow;
	mainWindow.Show();
	mainWindow.StartViewPortProcessing();
	app.exec();

	return 0;
}