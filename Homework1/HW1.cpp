//Question Number 1: STACK CODING QUESTION LIBRARIES
#include <stack>
#include <iostream>
#include <cctype>
#include <sstream>

//Question3: QUEUE CODING QUESTION LIBRARIES
#include <queue>
#include <chrono>
#include <cstdlib>
#include <thread>
using namespace std;

//QUestion Number 1: Self-made helper functions

int precedence(string oprtr) {
    if (oprtr == "+" || oprtr == "-") {
        return 1;
    }
    else if (oprtr == "*" || oprtr == "/") {
        return 2;
    }
    return 0; 
}


//Question Number 1: STACK CODING QUESTION 


void problem1()
{
  string infix = "";

  cout << "Enter your infix. PLEASE MAKE SURE TO PUT SPACES BETWEEN EVERYTHING!  " << endl;
  getline(cin, infix);

  istringstream stream(infix);

  stack<string> postfixer;

  string token;
  while (stream >> token )
  {
    //cout << "hi" << endl;
    if (isdigit(token[0]) || isalpha(token[0])) { cout << token; }
    if (token == "(")
    {
      postfixer.push(token);
    }

     else if (token == ")")
     {
        while (!postfixer.empty() && postfixer.top() != "(")
        {
          cout << postfixer.top();
          postfixer.pop();
        }
        postfixer.pop();
     }

      else if (token == "+" || token == "-" || token == "*" || token == "/")
       {
          while (!postfixer.empty() && precedence(postfixer.top()) >= precedence(token)) 
          {
              cout << postfixer.top();
              postfixer.pop();
          }
          postfixer.push(token);
        }
  }
      while (!postfixer.empty()) 
    {
      cout << postfixer.top();
      postfixer.pop();
    }

};

void problem3()
{
  queue<string> questionQueue;

  for (int i = 0; i < 5; i++)
  {
    string question;
    cout << "Enter your " << i + 1 << "th(st/nd/rd) question" << endl;
    getline(cin, question);
    questionQueue.push(question);
  }

  cout << endl;
  cout << "Professor's Queue of Sample Questions:" << endl;
  while (!questionQueue.empty())
  {
    cout << "Question: ";
    cout << questionQueue.front() << endl;
    questionQueue.pop();

    int random_num = rand() % 3 + 1;
    std::this_thread::sleep_for(std::chrono::seconds(random_num));

    cout << "Professor: That's a great question!" << endl;
  }

  cout << "All questions answered!" << endl;
};


int main()
{
  problem1();
  //"( ( ( A + B ) * C ) - ( ( D - E ) * ( F + G ) ) ) "
  cout << "" << endl;
  //"A * B + C * D"
  cout << "" << endl;
  cout << "Problem3: Queue question" << endl;
  problem3();
  return 0;
}