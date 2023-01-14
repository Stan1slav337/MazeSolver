#include "Console.h"

Console::Console(class MazeSolver *solver, QWidget *parent): main(solver), QWidget(parent)
{
	ui.setupUi(this);

	setFixedSize(size());
}

void Console::closeEvent(QCloseEvent* bar)
{
	main->getUi().actionShow_Details->setChecked(false);
	bar->accept();
}
