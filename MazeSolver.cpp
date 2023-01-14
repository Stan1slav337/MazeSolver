#include "MazeSolver.h"
#include "DFS.h"
#include "BFS.h"

MazeSolver::MazeSolver(QWidget *parent): QMainWindow(parent)
{
    ui.setupUi(this);

    dfs = new DFS(this);
    bfs = new BFS(this);
    alg = dfs;
    init(DEFAULT_N);
}

void MazeSolver::init(const int LEN)
{
    currLEN = LEN;
    setFixedSize(QSize(DELTA * LEN, DELTA * LEN + MENU_HEIGHT));
    alg->initializeMaze(LEN);
    alg->updateTree();
    alg->init();
    update();
}

Ui::MazeSolverClass MazeSolver::getUi() const
{
    return ui;
}

void MazeSolver::closeEvent(QCloseEvent* bar)
{
    if (nullptr != console)
        console->close();
    bar->accept();
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

void MazeSolver::on_action10_triggered()
{
    init(10);
}

void MazeSolver::on_action15_triggered()
{
    init(15);
}

void MazeSolver::on_action20_triggered()
{
    init(20);
}

void MazeSolver::on_actionShow_Tree_triggered()
{
    update();
}

void MazeSolver::on_actionShow_Details_triggered()
{

    if (ui.actionShow_Details->isChecked())
    {
        if(nullptr == console)
            console = new Console(this);
        console->show();
    }
    else
        console->hide();
}

void MazeSolver::on_actionDFS_triggered()
{
    setWindowTitle("Depth First Search");
    alg = dfs;
    init(currLEN);
}

void MazeSolver::on_actionBFS_triggered()
{
    setWindowTitle("Breadth First Search");
    alg = bfs;
    init(currLEN);
}