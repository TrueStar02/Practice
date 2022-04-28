#include "Job.h"
#include<sstream>
int Job::number=0;
Job::Job(int p):id(number),priority(p),nextJob(NULL){number++;}
void Job::setId(int i){id=i;}
int Job::getId() const{return id;}
void Job::setPriority(int p){priority=p;}
int Job::getPriority() const{return priority;}
void Job::setNext(Job *job){nextJob=job;}
Job * Job::getNext() const{return nextJob;}
string Job::toString()
{   ostringstream strout;
    strout<<"["<<id<<":"<<priority<<"]";
    return strout.str();
}