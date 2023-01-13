#pragma once

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include "ui_MazeSolver.h"
#include "SearchAlgo.h"

class MazeSolver : public QMainWindow
{
    Q_OBJECT

public:
    MazeSolver(QWidget* parent = nullptr);
    void init(const int);

protected:
    void keyPressEvent(QKeyEvent*) override;

private slots:
    void on_actionGenerate_triggered();
    void on_actionDFS_triggered();
    void on_actionBFS_triggered();

    void on_action10_triggered();
    void on_action15_triggered();
    void on_action20_triggered();

private:
    virtual void paintEvent(QPaintEvent* event);

    Ui::MazeSolverClass ui;
    class SearchAlgo* alg;
    class SearchAlgo *dfs, *bfs;
    int currLEN;
};
