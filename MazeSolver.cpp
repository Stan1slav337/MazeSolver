#include "MazeSolver.h"

MazeSolver::MazeSolver(QWidget *parent): QMainWindow(parent)
{
    setFixedSize(QSize(WINDOW_WIDTH, WINDOW_HEIGHT + MENU_HEIGHT));
    ui.setupUi(this);
}
