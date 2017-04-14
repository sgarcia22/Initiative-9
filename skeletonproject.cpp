#include "skeletonproject.h"
#include "ui_skeletonproject.h"

SkeletonProject::SkeletonProject(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SkeletonProject)
{
    ui->setupUi(this);
}

SkeletonProject::~SkeletonProject()
{
    delete ui;
}
