#if !defined (QUEUELINKED_H)
#define QUEUELINKED_H

#include "NextNode.h"

template < class T >
class QueueLinked
{

   private:
      NextNode<T>* back;
      int sze;

   public:
      QueueLinked();
      ~QueueLinked();
      bool isEmpty();
      int size();
      void dequeueAll(); 
      T* peek();
      T* dequeue();
      void enqueue(T* item);

};

template < class T >
QueueLinked<T>::QueueLinked()
{
   back = NULL;
   sze = 0;
}

template < class T >
QueueLinked<T>::~QueueLinked()
{
   dequeueAll();
}

template < class T >
bool QueueLinked<T>::isEmpty()
{
    return sze == 0;
}

template < class T >
int QueueLinked<T>::size()
{
    return sze;
}

template < class T >
void QueueLinked<T>::dequeueAll()
{
   if (sze == 0) return;

   NextNode<T>* prev = NULL;
   NextNode<T>* curr = back->getNext();  //the head
   back->setNext(NULL);  //break the bridge link

   while (curr != NULL)
   {
      prev = curr;
      curr = curr->getNext();
      delete prev;
   }

   sze = 0;
}

template < class T >
T* QueueLinked<T>::peek()
{
    T* item = NULL;
    if (!isEmpty()) 
    {  
      // queue is not empty; retrieve front
      NextNode<T>* head = back->getNext();
      item = head->getItem();
    }
    return item;
}

template < class T >
void QueueLinked<T>::enqueue(T* item)
{
    NextNode<T>* node = new NextNode<T>(item);
	if (sze == 0)
	{
		node->setNext(node);
		back = node;
	}
	else 
	{
		node ->setNext(back->getNext());
		back->setNext(node);
		back = node;
	}
    sze++;
}

template < class T >
T* QueueLinked<T>::dequeue()
{
    T* item = NULL;
    if (sze == 0)
	{
		return NULL;
	}
	else
	{
       if (sze == 1)
	   {
		  item = back ->getItem();
	   }
	   else 
	   {
			NextNode<T>* front = back->getNext();
			back -> setNext(front -> getNext());
			item = front -> getItem();
			delete front;;
	   }
	}
	sze--;
    return item;
}

#endif
