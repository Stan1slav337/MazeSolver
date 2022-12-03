#pragma once

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include "ui_MazeSolver.h"
#include "SearchAlgo.h"

constexpr auto MENU_HEIGHT = 25;
constexpr auto WINDOW_WIDTH = 500;
constexpr auto WINDOW_HEIGHT = 500;
constexpr auto DEFAULT_N = 10;
constexpr auto BLOCK_COLOR = Qt::darkCyan;
constexpr auto VISITED_BLOCK = Qt::cyan;

class MazeSolver : public QMainWindow
{
    Q_OBJECT

public:
    MazeSolver(QWidget* parent = nullptr);

private:
    Ui::MazeSolverClass ui;
    class SearchAlgo* alg;

    virtual void paintEvent(QPaintEvent* event);
};
