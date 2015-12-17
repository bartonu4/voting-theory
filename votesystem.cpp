#include "votesystem.h"
#include "ui_votesystem.h"

VoteSystem::VoteSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VoteSystem)
{
    ui->setupUi(this);
    setVotes();
    plural();
}

VoteSystem::~VoteSystem()
{
    delete ui;
}

void VoteSystem::setVotes()
{
    QVector<Candidate> candidatesFirst,candidatesSecond,candidatesThird;
    candidatesFirst<<Candidate("c")<<Candidate("a")<<Candidate("b")<<Candidate("d");
    candidatesSecond<<Candidate("a")<<Candidate("b")<<Candidate("c")<<Candidate("d");
    candidatesThird<<Candidate("b")<<Candidate("a")<<Candidate("d")<<Candidate("c");

    votes.append(Section(candidatesFirst,5));
    votes.append(Section(candidatesSecond,4));
    votes.append(Section(candidatesThird,2));

}
bool less(const Candidate &c1,const Candidate &c2)
{
    return c1.vote>c2.vote;
}

void  VoteSystem::plural()
{

    QVector<Candidate> candidates;

    for(int i = 0;i<votes.size();++i)
    {
        auto section = votes.at(i);

        candidates.append(section.candidates.first());

    }
    std::sort(candidates.begin(),candidates.end(),less);
    while(candidates.size()>2)
    {
        candidates.removeLast();
    }
    ui->textBrowser->setText("First tour : "+candidates.at(0).getName()+" "+candidates.at(1).getName());
    QVector<Section> resultSection;
    for(int i = 0;i<votes.size();++i)
    {
        auto section = votes.at(i);
        for(int j = 0;j < section.candidates.size();++j)
        {
            if(section.candidates.at(j).getName()!=candidates.at(0).getName() && section.candidates.at(j).getName()!=candidates.at(1).getName())
            {
                section.candidates.removeAll(section.candidates.at(j));
                j--;
            }
        }


        resultSection.append(section);
    }
    candidates[0].vote=0;
    candidates[1].vote=0;
    for(int i = 0;i<resultSection.size();++i)
    {
        auto first = resultSection.at(i).candidates.first();

        if(first.getName() ==candidates.at(0).getName())
        {
            candidates[0].vote += first.vote;
        }
        else
        {
            candidates[1].vote +=first.vote;
        }

    }
    if(candidates.at(0).vote>candidates.at(1).vote)
    {
        ui->textBrowser->append(QString("Winner "+candidates.at(0).getName()));
    }
    else
    {
        ui->textBrowser->append(QString("Winner "+candidates.at(1).getName()));
    }

}


