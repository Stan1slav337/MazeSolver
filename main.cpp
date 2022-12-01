#include "MazeSolver.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    MazeSolver w;
    w.show();

    return a.exec();
}
