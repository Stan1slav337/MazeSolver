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
	void print(QString);
	void clear();

private:
	void closeEvent(QCloseEvent* bar);

	Ui::ConsoleClass ui;
	class MazeSolver* main;
};
