#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node*next;


};
 struct Test{
    int position[1000];
    };

node* insertionTail (node *head)
{
    int val;
    cin>>val;
    node*p=new node();
    p->val=val;
    p->next=NULL;
    node*ptr;
    if(head==NULL)
    {
       head=p;

        return head;
    }
    else
        ptr=head;
        while(ptr->next!=NULL) //2
       {
           ptr=ptr->next;
       }
       ptr->next=p;
         return head;
}

node* insertionHead(node*head)
  {
     int n;
    cin>>n;
    node*p=new node();
    p->val=n;
    p->next=head;
    head=p;
    return head;
}
void reversedListPrint(node* head)
{
    if (head == NULL) //2 3 4 -> 4 3 2
	      return;


	reversedListPrint(head->next);

	cout << head->val << " ";
}

void print(node* n)
{
    while(n!=NULL)
    {
        cout<<n->val<<" ";
        n=n->next;
    }
    cout<<endl;
}
int countlenghth(node*head)

{ int c=0;
node*n=head;
   while(n!=NULL) //1 2 3 4 5 6
    {
        c++;
        n=n->next;
    }

    return c;
}


node* insertposition(node*head,int pos,int val)
{  if(pos>countlenghth(head))
{
     cout<<"not possible bcz pos is big than list"<<endl;
}
else if(pos== 1)
{
    node*p=new node();
    p->val=val;
    p->next=head;
    head=p;
   return head;
}

  else{
    int i=0;
     node*temp=head;
     //pos=pos-2;
    while(i<pos-2)
{     i++;
    temp=temp->next; ///2 3 4 5 --2 4
}
    node*newo=new node();
    newo->val=val;
    //newo->next=NULL;

    newo->next=temp->next; //pos-1,temp->val=val just insert accurate size
    temp->next=newo;
    return head;}

}


int searchuniquevalue(node*head,int key)
{
 int c=1;
 node*temp=head;
 if(temp==NULL)
     {
         return -1;
     }
 while(temp->val!=key)
 {
     if(temp->next==NULL)
     {
         return -1;
     }

     temp=temp->next;
     c++;
 }

return c;
}

void serchduplicate(node*&head,int ke)
{ int c=1;
int size; size=countlenghth(head);
int position[size+1],k=1;
    node*tmp=head;

     int f=0;
    while(tmp!=NULL)
    {
        if(tmp->val==ke)
        {

            position[k]=c;
            k++;
            f=1;
        }
        c++;
        tmp=tmp->next;
    }
    if(f==0)
    {
        cout<<"no found"<<endl;
    }
    else
    {
        position[0]=k;
        cout<<" value found at "<<endl;
    for(int i=1;i<position[0];i++)
    {
        cout<<position[i];
        if(position[0]-2)
            cout<<",";
    }
    }
}
Test serchduplicatereturn(node*&head,int ke)
{
  node*temp=head;
  int k=1,c=1;
  Test t;
  while(temp!=NULL)
    {
        if(temp->val==ke)
        {

            t.position[k]=c;
            k++;

        }
        c++;
        temp=temp->next;
    }
    t.position[0]=k;

  return t;}

node*Head_Deletion(node*head)
{
    node*temp=head;//2 4 5
    if(temp!=NULL)
    {
    head=temp->next;
    delete(temp);
    }
    return head;
}
node*tail_Deletion(node*head){
node*temp=head;
if(temp!=NULL && temp->next!=NULL){
while(temp->next->next!=NULL)//a b c d null
 {
     temp=temp->next;
 }
 //node*delnode=temp->next;
 temp->next=NULL;
 //delete delnode;
 return head;
}
else
    if(temp->next==NULL)
{
   head= Head_Deletion(head);
    return head;
}
else
    cout<<"no value here "<<endl;
}
node*delete_specific_position(node*head,int p)
{ int i=1;
    node*temp=head;

    if(temp!=NULL && p<=countlenghth(head)){
    if(p==1)
    {
        head=Head_Deletion(head);
        return head;
    }
    else if (countlenghth(head)==p)
    {
        head=tail_Deletion(head);
        return head;
    }
    else
    {
    while(i<p-1)
    {
    temp=temp->next;
       i++;            //2 4 6 7
    }

    node*delnode=temp->next;
    temp->next=delnode->next;
    delete delnode;
    return head;}
    }
    else
        if(p>countlenghth(head))
     head->val=-1;
    return head;

}
node*delete_specific_value(node*head,int value)
{
  node*temp=head;
 int position;

  position=searchuniquevalue(temp,value);
  if(position==-1 )
  {
      return head;
  }
  else
  {head=delete_specific_position(temp,position);
  return head;
  }

}

void sorten(node*head)
{ int t;
  node*ptr=head;
  while(ptr->next!=NULL)
 {
    node*temp=ptr->next;
    while(temp!=NULL)
    {
        if(ptr->val>temp->val)
        {
           t= ptr->val;
           ptr->val=temp->val;
           temp->val=t;
        }
        temp=temp->next;
    }
    ptr=ptr->next;
 }
  print(head) ;
}
node*removedupicates(node*head) ///2 3 3 4//p=3,ptr=4,temp=4
{
    node *ptr=head->next;
    node*temp=head;
    while(ptr!=NULL)
    {
        if(temp->val==ptr->val)
        {
            node*p=ptr;

            ptr=ptr->next; ////
            temp->next=ptr;
            delete p;
        }
        else
        {
            temp=ptr;
            ptr=ptr->next;
        }
    }
    return head;
}


//INT_MAIN
int main()
{
    node *head=NULL;
    cout<<"how many numbers add to linked list as tail: ";
   int test;
   cin>>test;
while(test--)
{
   head= insertionTail(head);
}
cout<<"After insertion Tail: ";
print(head) ;
cout<<"how many numbers add to linked list: ";
 int t;
   cin>>t;
while(t--)
{
  head= insertionHead(head);
}
cout<<"After insertion Head: ";
  print(head) ;

  cout<<"After Reverse: ";
reversedListPrint(head);
cout<<endl;
cout<<"enter position and value"<<endl;
int vl,pos;
cin>>pos>>vl;
head=insertposition(head, pos, vl);
print(head);
//int cc;
//cc=countlenghth(head);
//cout<<cc<<endl;
int key;
cout<<endl<<"key value ";
    cin>>key;
    int c;
c=searchuniquevalue(head,key);
if(c!=-1)
{
    cout<<"found at"<<c<<endl;
}
else
    cout<<"not found "<<endl;
    //int ke;
//cout<<endl<<"key value for duplicate ";
    //cin>>ke;
 //serchduplicate(head,ke);


  int k;
 cout<<endl<<"key value for duplicate return "<<endl;
    cin>>k;

Test  p;
p=serchduplicatereturn(head,k);
   if(p.position[0]==1)
  cout<<"not found"<<endl;
 else
   {
    int siz=p.position[0];
    for(int i=1;i<siz;i++)
    cout<<p.position[i]<<" ";}

    cout<<endl;

    cout<<"delete head"<<endl;
    head=Head_Deletion(head);
    print(head) ;
 cout<<"delete tail"<<endl;
 head=tail_Deletion(head);
    print(head) ;

cout<<"deletion specific position"<<endl;
int po;
cin>>po;
head=delete_specific_position(head,po);
if(head->val==-1)
    cout<<"error"<<endl;
 else
    print(head) ;
  cout<<"deletion specific value"<<endl;
int value;
cin>>value;
head=delete_specific_value(head,value);
if(head->val==-1)
    cout<<"error"<<endl;
 else
    print(head) ;
    cout<<"after sort are :";
sorten(head);
 cout<<" remove 1 more values :";
//head=removedupicates(head);
//print(head);
cout<<"Delete_ALL_Specificvalue ";
int m;
cin>>m;
//head=Delete_ALL_Specificvalue(head,m);
print(head);
}
