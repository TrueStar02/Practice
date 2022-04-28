#include "JobManager.h"
JobManager* JobManager::instance=new JobManager();
JobManager* JobManager::getInstance(){return instance;}
        bool JobManager::deleteInstance()
        {   if(JobManager::instance==NULL)
                return 0;
            delete JobManager::instance;
            JobManager::instance=NULL;
            return 1;
        }
        void JobManager::addJob(int priority)
        {   if(jobFrontPointer==NULL)
                jobFrontPointer=new Job(priority);
            else
            {   Job * temp=jobFrontPointer;
                while(temp->getNext()!=NULL)
                    temp=temp->getNext();
                temp->setNext(new Job(priority));
            }
        }
        void JobManager::finishOneJob()
        {   Job *temp=jobFrontPointer;
            jobFrontPointer=jobFrontPointer->getNext();
            delete temp;
        }
        void JobManager::sortJob()
        {   if(jobFrontPointer==NULL)return;
            Job *temp=jobFrontPointer;
            jobFrontPointer=jobFrontPointer->getNext();
            Job * newlist=temp;
            temp->setNext(NULL);
            temp=jobFrontPointer;
            Job *temp2;
            while(temp!=NULL)
            {   jobFrontPointer=jobFrontPointer->getNext();
                if(temp->getPriority()>newlist->getPriority())
                {   temp->setNext(newlist);
                    newlist=temp;
                }
                else
                {    
                    for(temp2=newlist;temp2->getNext()!=NULL&&temp2->getNext()->getPriority()>=temp->getPriority();temp2=temp2->getNext())continue;
                    temp->setNext(temp2->getNext());
                    temp2->setNext(temp);
                }
                temp=jobFrontPointer;
            }
           jobFrontPointer=newlist; 
        }
        void JobManager::printJob()
        {  
            bool first=1;
            Job * temp=jobFrontPointer;
            if(temp==NULL)
            {   cout<<"empty!\n";
                return;

            }
            while(temp!=NULL)
            {   if(!first)
                    cout<<"->";
                first=0;
                cout<<temp->toString();
                temp=temp->getNext();
            }
            cout<<endl;
        }
        int JobManager::getNumOfJob()
        {    if(jobFrontPointer==NULL)
                return 0;
            int count=0;
            Job * temp=jobFrontPointer;
            while(temp!=NULL)
            {   count++;
                temp=temp->getNext();
            }
            return count;
        }
        void JobManager::clear()
        {   Job * temp=jobFrontPointer;
            while(temp!=NULL)
            {   temp=temp->getNext();
                delete jobFrontPointer;
                jobFrontPointer=temp; 
            }

        }
        JobManager::~JobManager(){clear();}
        JobManager::JobManager()
        {   jobFrontPointer=NULL;
        }
        
