#pragma once

#include <QWidget>
#include <QCloseEvent>
#include "ui_Console.h"
#include "MazeSolver.h"

class Console : public QWidget
{
	Q_OBJECT

public:
	Console(class MazeSolver*, QWidget *parent = nullptr);

private:
	void closeEvent(QCloseEvent* bar);

	Ui::ConsoleClass ui;
	class MazeSolver* main;
};
