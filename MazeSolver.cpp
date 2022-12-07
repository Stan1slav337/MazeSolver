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

void MazeSolver::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Right)
        if (!isRunning)
            alg->byStep = !alg->byStep;
        else
            update();
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
    isRunning = true;

    auto searchAlg = static_cast<DFS*>(alg);
    searchAlg->search();
    update();

    menuBar()->setEnabled(true);
}