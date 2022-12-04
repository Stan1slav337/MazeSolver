#include "MazeSolver.h"
#include "DFS.h"

MazeSolver::MazeSolver(QWidget *parent): QMainWindow(parent)
{
    setFixedSize(QSize(WINDOW_WIDTH, WINDOW_HEIGHT + MENU_HEIGHT));
    ui.setupUi(this);

    alg = new SearchAlgo(this);
}

void MazeSolver::delay() noexcept
{
    QApplication::processEvents();
}

void MazeSolver::paintEvent(QPaintEvent* event)
{
    alg->showMaze();
}

void MazeSolver::on_actionDFS_triggered()
{
    menuBar()->setEnabled(false);
    setWindowTitle("Depth-first search");

    auto searchAlg = static_cast<DFS*>(alg);
    searchAlg->search();

    update();

    setWindowTitle("Depth-first search - Finished");
    menuBar()->setEnabled(true);
}