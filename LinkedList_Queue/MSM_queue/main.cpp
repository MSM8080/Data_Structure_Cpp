#include <iostream>
#include <queue>
using std::queue;
using namespace std;
// -----------------------------------------
template <typename E>
class MSM_queue : public queue<E>
{
public:
    MSM_queue();
    void enqueue(const E& e);
    void dequeue();
    void print();

private:
    //queue<E> q;
};
// -----------------------------------------
template <typename E>
MSM_queue<E>::MSM_queue() {}
// -----------------------------------------
template <typename E>
void MSM_queue<E>::enqueue(const E& e)
{
    queue<E>::push(e);
}
// -----------------------------------------
template <typename E>
void MSM_queue<E>::dequeue()
{
    queue<E>::pop();
}
// -----------------------------------------
template <typename E>
void MSM_queue<E>::print()
{
    if(queue<E>::empty()==1)
        return;
    else
    {
        E elem = queue<E>::front();
        cout<<queue<E>::front()<<" ";
        dequeue();
        print();
        enqueue(elem);
        return;
    }
}
// -----------------------------------------

// -----------------------------------------
int main()
{
    MSM_queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout <<"front: "<< q.front()<< endl;
    cout <<"back: "<< q.back()<< endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<"empty?: "<<q.empty()<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<"The queue: ";
    q.print();
    return 0;
}
