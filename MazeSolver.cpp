#include "MazeSolver.h"

MazeSolver::MazeSolver(QWidget *parent): QMainWindow(parent)
{
    setFixedSize(QSize(WINDOW_WIDTH, WINDOW_HEIGHT + MENU_HEIGHT));
    ui.setupUi(this);

    alg = new SearchAlgo(this);
}

void MazeSolver::paintEvent(QPaintEvent* event)
{
    alg->showMaze();
}
