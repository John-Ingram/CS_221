#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    char stackChar, queueChar;
    bool b1;
    Stack s1;
    Queue q1;



    return 0;
}



bool isPalindrome()
{
    char stackChar = '*';
    char queueChar = '*';
    bool b1; //Not really nescescary for this program
    Stack s1;
    Queue q1;

    // read the word from cin
    do {
        cin >> stackChar; //Using stackchar because I can't create another variable. This could be any char variable
        s1.push(stackChar);
        q1.enqueue(stackChar);
    } while (stackChar != ' ');

    // pull the individual letters back out and compare

    while (!q1.isEmpty())
    {
        s1.pop(stackChar);
        q1.dequeue(queueChar);
        if (stackChar != queueChar) return false;
    }
    return true;
        
}


class Stack
{
private:
    /* data */
public:
    Stack(/* args */);
    ~Stack();
};

Stack::Stack(/* args */)
{
}

Stack::~Stack()
{
}

class Queue
{
private:
    /* data */
public:
    Queue(/* args */);
    ~Queue();
};

Queue::Queue(/* args */)
{
}

Queue::~Queue()
{
}


