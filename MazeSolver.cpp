#include "MazeSolver.h"
#include "DFS.h"

MazeSolver::MazeSolver(QWidget *parent): QMainWindow(parent)
{
    setFixedSize(QSize(WINDOW_WIDTH, WINDOW_HEIGHT + MENU_HEIGHT));
    ui.setupUi(this);

    dfs = new DFS(this);
    alg = dfs;
}

void MazeSolver::paintEvent(QPaintEvent* event)
{
    alg->showMaze();
}

void MazeSolver::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Right)
    {
        alg->search();
        update();
    }
}

void MazeSolver::on_actionGenerate_triggered()
{
    alg->initializeMaze(alg->maze->getLen());
}

void MazeSolver::on_action20_triggered()
{
    alg->initializeMaze(20);
}

void MazeSolver::on_action50_triggered()
{
    alg->initializeMaze(50);
}

void MazeSolver::on_action100_triggered()
{
    alg->initializeMaze(100);
}

void MazeSolver::on_actionDFS_triggered()
{
    menuBar()->setEnabled(false);
    setWindowTitle("Depth-first search");
    alg->init();

    menuBar()->setEnabled(true);
}