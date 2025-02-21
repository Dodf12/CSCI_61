#include <iostream>
#include <map>

using namespace std;

void scoreRank()
{
  multimap<string,int> studentGrades;
  
  string name;
  int score;

  //Reading in the values that the user puts in util tyeps done
  while (cin>>name)
  {
    if(name=="Finished") {break;}
    cin >> score;
    studentGrades.insert({name,score});
  }

  //Putting values into a map
  map<string,int> combinedGrades;
  for (auto& pair : studentGrades)
  {
    combinedGrades[pair.first]=0;
  }


  //Adding all values up
  for(auto& pair: studentGrades)
  {
    combinedGrades[pair.first]+=pair.second;
  }
  

  //Store in multimap so that scores are ranked from lowest to highest
  multimap<int, string> scoreRanker;

  for (auto& pair: combinedGrades)
  {
    scoreRanker.insert({pair.second,pair.first});
  }

  cout << "" << endl;
  cout << "The scores ranked are: " << endl;

  for(auto& pair: scoreRanker)
  {
    cout << pair.first << "," << pair.second << endl;
  }

}

int main()
{
  scoreRank();
}

