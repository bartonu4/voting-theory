#include "votesystem.h"
#include "ui_votesystem.h"

VoteSystem::VoteSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VoteSystem)
{
    ui->setupUi(this);
}

VoteSystem::~VoteSystem()
{
    delete ui;
}
