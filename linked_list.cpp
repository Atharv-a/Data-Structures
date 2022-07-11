#include <bits/stdc++.h>
using namespace std;

//*****start******//

template <class t>
class linkedlist
{
private:
   struct node
   {
      struct node *pre;
      t data;
      struct node *next;
   };
   struct node *head = NULL;
   struct node *tail = NULL;

public:
   t first()
   {
      if (head != NULL)
         return head->data;
      return NULL;
   }
   t last()
   {
      if (tail != NULL)
         return tail->data;
      return NULL;
   }
   void addfirst(t a)
   {
      struct node *memb_er = new node;
      memb_er->data = a;
      memb_er->next = head;
      memb_er->pre = NULL;
      if (head != NULL)
         head->pre = memb_er;
      if (head == NULL)
         tail = memb_er;
      head = memb_er;
   }
   void addlast(t a)
   {
      struct node *memb_er = new node;
      memb_er->data = a;
      memb_er->next = NULL;
      memb_er->pre = tail;
      if (tail != NULL)
         tail->next = memb_er;
      if (tail == NULL)
         head = memb_er;
      tail = memb_er;
   }
   void addafter(t after, t value)
   {
      struct node *temp = head;
      while (temp != NULL && temp->data != after)
         temp = temp->next;
      if (temp == NULL)
      {
         cout << "wrong input for addafter check whether element after which insertion has to be performed exist in the list\n";
      }
      if (temp != NULL)
      {
         struct node *f = temp;
         struct node *l = temp->next;
         if (l == NULL)
            addlast(value);
         else
         {
            struct node *memb_er = new node;
            memb_er->data = value;
            memb_er->pre = f;
            memb_er->next = l;
            f->next = memb_er;
            l->pre = memb_er;
         }
      }
   }
   void addbefore(t before, t value)
   {
      struct node *temp = head;
      while (temp != NULL && temp->data != before)
         temp = temp->next;
      if (temp == NULL)
      {
         cout << "wrong input for addbefore check whether element before which insertion has to be performed exist in the list\n";
      }
      if (temp != NULL)
      {
         struct node *l = temp;
         struct node *f = temp->pre;
         if (f == NULL)
            addfirst(value);
         else
         {
            struct node *memb_er = new node;
            memb_er->data = value;
            memb_er->pre = f;
            memb_er->next = l;
            f->next = memb_er;
            l->pre = memb_er;
         }
      }
   }
   void deletefirst()
   {
      if (head != NULL)
      {
         struct node *tem = head;
         head = head->next;
         head->pre=NULL;
         free(tem);
      }
   }
   void deletelast()
   {
      if (tail != NULL)
      {
         struct node *tem = tail;
         tail = tail->pre;
         tail->next=NULL;
         free(tem);
      }
   }
   void deleteafter(t after)
   {
      struct node *temp = head;
      while (temp != NULL && temp->data != after)
         temp = temp->next;
      if (temp == NULL)
      {
         cout << "wrong input for deleteafter check whether element after which deletion has to be performed exist in the list\n";
      }
      else
      {

         struct node *f = temp->next;
         struct node *l = f->next;
         if (f != NULL && l == NULL)
            deletelast();

         else if (f != NULL && l != NULL)
         {
            temp->next = l;
            l->pre = temp;
            free(f);
         }
      }
   }
   void deletebefore(t before)
   {
      struct node *temp = head;
      while (temp != NULL && temp->data != before)
         temp = temp->next;
      if (temp == NULL)
      {
         cout << "wrong input for deletebefore check whether element before which deletion has to be performed exist in the list\n";
      }
      else
      {

         struct node *l = temp->pre->pre;
         struct node *f = temp->pre;
         if (f != NULL && l == NULL)
            deletefirst();

         else if (f != NULL && l != NULL)
         {
            l->next = temp;
            temp->pre = l;
            free(f);
         }
      }
   }
   void print()
   {
      struct node *temp = head;
      while (temp != NULL)
      {
         cout << temp->data << " ";
         temp = temp->next;
      }

      if (temp == NULL)
         cout << "<--end\n";
   }
};

int main()
{
    linkedlist<char> a;
   a.addfirst('a');
   a.addlast('d');
   a.addafter('a','b');
   a.addbefore('d','c');
   a.print();
   a.addlast('e');
   a.addfirst('f');
   a.print();
   a.deleteafter('f');
   a.deletebefore('e');
   a.deletefirst();
   a.deletelast();
   a.print();
   cout<<a.first()<<endl;
   cout<<a.last()<<endl;

}

//*********end*********//
