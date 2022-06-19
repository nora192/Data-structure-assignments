#include <iostream>
using namespace std;
const int MAX_LENGTH = 100;
class arrayqueue
{
    int rear;
    int front;
    int length;
    int arr[MAX_LENGTH];
public:
    arrayqueue()
    {
        front = 0;
        rear = MAX_LENGTH - 1;
        length = 0;
    }

    bool isempty()
    {
        return length == 0;
    }

    bool isfull()
    {
        return length == MAX_LENGTH;
    }

    void addqueue(int element)
    {
        if (isfull())
        {
            cout << "Que is full van not Enqueue...!";
        }
        else
        {
            rear = (rear + 1)%MAX_LENGTH;
            arr[rear] = element;
            length++;
        }
    }

    void dequeue()
    {
        if(isempty())
        {
            cout << "Empty queue can not dequeue...!";
        }
        else
        {
            front = (front + 1)%MAX_LENGTH;
            length--;
        }
    }

    int frontqueue()
    {
        return arr[front];
    }

};

int timeToBuyTickets(int *tickets, int sz, int k) {
        arrayqueue q;
        int counter = 0;
        for (int i=0; i<sz ; i++)
        {
            q.addqueue(i);
        }
        while(!q.isempty()){

            int temp = q.frontqueue();
            q.dequeue();
            if(tickets[temp] >= 1)
            {
                tickets[temp] --;
                counter++;
            }

            if(tickets[temp] == 0 && temp != k)
                continue;

            if(tickets[temp] == 0 && temp == k)
                break;

            q.addqueue(temp);
        }
        return counter;

    }

int main()
{
    int testcase1[] = {2,3,2};
    int size1 = sizeof(testcase1)/sizeof(testcase1[0]);
    cout << timeToBuyTickets(testcase1, size1, 2) << endl;

    int testcase2[] = {5,1,1,1};
    int size2 = sizeof(testcase2)/sizeof(testcase2[0]);
    cout << timeToBuyTickets(testcase2, size2, 0);

}

