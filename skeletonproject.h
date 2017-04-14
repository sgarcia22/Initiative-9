#ifndef SKELETONPROJECT_H
#define SKELETONPROJECT_H

#include <QMainWindow>

namespace Ui {
class SkeletonProject;
}

class SkeletonProject : public QMainWindow
{
    Q_OBJECT

public:
    explicit SkeletonProject(QWidget *parent = 0);
    ~SkeletonProject();

private:
    Ui::SkeletonProject *ui;
};

#endif // SKELETONPROJECT_H
