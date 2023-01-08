#include "MazeSolver.h"
#include "DFS.h"

MazeSolver::MazeSolver(QWidget *parent): QMainWindow(parent)
{
    setFixedSize(QSize(WINDOW_WIDTH, WINDOW_HEIGHT + MENU_HEIGHT));
    ui.setupUi(this);

    dfs = new DFS(this);
    alg = dfs;
    init(DEFAULT_N);
}

void MazeSolver::init(const int LEN)
{
    alg->initializeMaze(LEN);
    alg->updateTree();
    alg->init();
    update();
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
    init(alg->maze->getLen());
}

void MazeSolver::on_action20_triggered()
{
    init(20);
}

void MazeSolver::on_action50_triggered()
{
    init(50);
}

void MazeSolver::on_action100_triggered()
{
    init(100);
}

void MazeSolver::on_actionDFS_triggered()
{
    setWindowTitle("Depth-first search");
    alg = dfs;
}