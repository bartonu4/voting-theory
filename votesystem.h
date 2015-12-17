#ifndef VOTESYSTEM_H
#define VOTESYSTEM_H

#include <QMainWindow>
#include <QDebug>
#include <QHash>

class Candidate
{
    public:Candidate(){}
    Candidate(QString _name): name(_name){}

     int vote;
     QString getName() const{  return name;}
        bool operator ==(const Candidate &c) const
     {
         if(this->name ==c.getName() && this->vote ==c.vote)
         {
             return true;
         }
         else
         {
             return false;
         }
     }

private:
     QString name;


};
class Section
{
public:
    Section(){};
    Section(QVector<Candidate> _candidates, int _vote): candidates(_candidates), vote(_vote)
    {
        for (int i = 0; i <candidates.size();i++)
        {
            candidates[i].vote = vote;
        }
    }
    QVector<Candidate> candidates;
    int vote;
//    operator <<(Candidate& c)
//    {
//        candidates.push_back(c);
//    }


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
    void setVotes();
    void plural();
    QList<Section> votes;
    QString text;
};

#endif // VOTESYSTEM_H
