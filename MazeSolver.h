#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MazeSolver.h"
#include "SearchAlgo.h"

class MazeSolver : public QMainWindow
{
    Q_OBJECT

public:
    MazeSolver(QWidget* parent = nullptr);

    static void delay() noexcept;

private slots:
    void on_actionGenerate_triggered();
    void on_actionDFS_triggered();

private:
    virtual void paintEvent(QPaintEvent* event);

    Ui::MazeSolverClass ui;
    class SearchAlgo* alg;

};
