#ifndef VOTESYSTEM_H
#define VOTESYSTEM_H

#include <QMainWindow>

namespace Ui {
class VoteSystem;
}

class VoteSystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit VoteSystem(QWidget *parent = 0);
    ~VoteSystem();

private:
    Ui::VoteSystem *ui;
};

#endif // VOTESYSTEM_H
