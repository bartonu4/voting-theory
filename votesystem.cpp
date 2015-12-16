#include "votesystem.h"
#include "ui_votesystem.h"

VoteSystem::VoteSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VoteSystem)
{
    ui->setupUi(this);
    votes = setVotes();
    plural();
}

VoteSystem::~VoteSystem()
{
    delete ui;
}

QHash<QVector<Candidate>,int> VoteSystem::setVotes()
{
    QVector<Candidate> candidatesFirst,candidatesSecond,candidatesThird;
    candidatesFirst<<Candidate("c")<<Candidate("a")<<Candidate("b")<<Candidate("d");
    candidatesSecond<<Candidate("a")<<Candidate("b")<<Candidate("c")<<Candidate("d");
    candidatesThird<<Candidate("b")<<Candidate("a")<<Candidate("d")<<Candidate("c");
    QHash<QVector<Candidate>,int> votes;
    votes.insert(candidatesFirst,5);
    votes.insert(candidatesSecond,4);
    votes.insert(candidatesThird,2);
    return votes;
}

Candidate VoteSystem::plural()
{
    QHashIterator<QVector<Candidate>,int> i(votes);
    QHash<Candidate, int> voteTable;
    while(i.hasNext())
    {
        auto section = i.key();
        auto vote = i.value();
        voteTable.insert(section.first(),vote);
    }
    qDebug() <<"nu3";

}
