#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MazeSolver.h"

constexpr auto MENU_HEIGHT = 25;
constexpr auto WINDOW_WIDTH = 500;
constexpr auto WINDOW_HEIGHT = 500;
constexpr auto DEFAULT_N = 100;
constexpr auto BLOCK_COLOR = Qt::darkCyan;

class MazeSolver : public QMainWindow
{
    Q_OBJECT

public:
    MazeSolver(QWidget* parent = nullptr);

private:
    Ui::MazeSolverClass ui;
};
