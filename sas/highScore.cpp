#include "highScore.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int currHi = 0;
string strLine;
string userScoreStr;
string hiScoreWText;


highScore::highScore(int x){

}




void highScore::checkScore(int userScore){

ifstream scoreFile ("scoreList.txt");
if(scoreFile.is_open()){
while(getline (scoreFile, strLine)){
  stringstream toConv(strLine);
  toConv >> currHi;
  if(userScore > currHi){
    userScoreStr = to_string(userScore);
    //scoreFile << userScoreStr;
    ofstream myfile ("scoreList.txt");
    myfile << userScoreStr;
    strLine = userScoreStr;
  }
  hiScoreWText = "Hi Score: " + strLine + " | ";

  }
}
scoreFile.close();

}


string highScore::getScore(){
  return hiScoreWText;
}
