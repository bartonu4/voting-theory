#ifndef VOTESYSTEM_H
#define VOTESYSTEM_H

#include <QMainWindow>
#include <QDebug>
#include <QHash>
class Candidate
{
    public:Candidate(){}
    Candidate(QString _name): name(_name){}
    private:
    QString name;
};

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
    QHash<int, QVector<Candidate> > setVotes();
    Candidate plural();
    QHash<int, QVector<Candidate>> votes;
};

#endif // VOTESYSTEM_H
