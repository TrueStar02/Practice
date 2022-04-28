template<class T>
class Queue {
 private:
    struct Node {
      T element;
      Node* next;
      Node(T ele, Node* n = NULL) {
        element = ele;
        next = n;
      }
    };
    Node* front_node;
    Node* back_node;
    int node_num; 
    public:
    Queue(){front_node=back_node=NULL;node_num=0;}

    Queue(const Queue & another)
    {   node_num=another.node_num;
        if(node_num)
        {   front_node=new Node(another.front_node->element,NULL);
            Node * nptr=front_node;
            Node * ptr=another.front_node;
            while(ptr->next!=NULL)
            {   nptr->next=new Node(ptr->next->element,NULL);
                ptr=ptr->next;
                nptr=nptr->next;
            }
            back_node=nptr;
        }
        else
            front_node=back_node=NULL;
    }
    ~Queue()
    {   if(node_num)
        {   Node * temp=front_node;
            while(temp!=NULL)
            {   temp=temp->next;
                delete front_node;
                front_node=temp;
            }

        }

    }
    bool empty(){return !node_num;}
    int size(){return node_num;}
    T front() const{return front_node->element;}
    T back() const{return back_node->element;}
    void push(T element)
    {   if(node_num)
        {   back_node->next=new Node(element,NULL); 
            back_node=back_node->next;
        }
        else
        {   front_node=new Node(element,NULL);
            back_node=front_node;
        }
        node_num++;
    }
    void pop()
    {   if(node_num>1)
        {   Node * temp=front_node;
            front_node=front_node->next;
            delete temp;
             node_num--;
        }
        else if(node_num==1)
        {   delete front_node;
            front_node=back_node=NULL;
             node_num--;
        }
    }
    void swap(Queue & queue)
    {   int numtemp;
        Node * ftemp,*btemp;
        numtemp=node_num;
        ftemp=front_node;
        btemp=back_node;
        node_num=queue.node_num;
        front_node=queue.front_node;
        back_node=queue.back_node;
        queue.node_num=numtemp;
        queue.front_node=ftemp;
        queue.back_node=btemp;
    }

  
};