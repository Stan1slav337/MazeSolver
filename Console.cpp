#include "Console.h"

Console::Console(class MazeSolver *solver, QWidget *parent): main(solver), QWidget(parent)
{
	ui.setupUi(this);

	QFont f = ui.textEdit->font();
	f.setPointSizeF(16);
	ui.textEdit->setFont(f);

	setFixedSize(size());
}

void Console::print(QString str)
{
	ui.textEdit->moveCursor(QTextCursor::End);
	ui.textEdit->insertPlainText(str);
	ui.textEdit->moveCursor(QTextCursor::End);
}

void Console::clear()
{
	ui.textEdit->clear();
}

void Console::closeEvent(QCloseEvent* bar)
{
	main->setShowConsole(false);
	bar->accept();
}
