#pragma once

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include "ui_MazeSolver.h"
#include "Console.h"
#include "SearchAlgo.h"

class MazeSolver : public QMainWindow
{
    Q_OBJECT

public:
    MazeSolver(QWidget* parent = nullptr);
    void init(const int);
    void printConsole(QString);
    void setShowConsole(bool);
    bool getShowTree() const;

protected:
    void keyPressEvent(QKeyEvent*) override;

private slots:
    void on_actionGenerate_triggered();
    void on_actionDFS_triggered();
    void on_actionBFS_triggered();

    void on_action10_triggered();
    void on_action15_triggered();
    void on_action20_triggered();

    void on_actionShow_Tree_triggered();
    void on_actionShow_Details_triggered();

private:
    void closeEvent(QCloseEvent* bar);
    virtual void paintEvent(QPaintEvent* event);

    Ui::MazeSolverClass ui;
    class SearchAlgo* alg;
    class SearchAlgo *dfs, *bfs;
    class Console* console;

    int currLEN;
};
