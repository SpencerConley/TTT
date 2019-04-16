#include <iostream>
using namespace std;
void printBoard(char sqr[]);
bool Checkwin(char sqr[]);
int main();
int main(){
  bool restart = true;
  while(restart = true){
  char sqr[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
  cout << "*-------------------*" << endl;
  cout << "TTT by Spencer Conley" << endl;
  cout << "*-------------------*" << endl;
  bool win = false;
  int z = 0;
  int x = 0;
  int o = 0;
  string play_again;
  while(win == false and z < 8){
    printBoard(sqr);
    cout << endl;
    cout << "Choose your square: X" << endl;
    cin >> x;
     if (sqr[x] != 'X' and sqr[x] != 'O' and x > -1 and x < 9){
      sqr[x] = 'X';
    }
    else{
      cout << "Not valid move, try again" << endl;
      while ((sqr[x] == 'X' or sqr[x] == 'O') or (x < 0 or x > 8)){
        cout << "Choose your square: X" << endl;
        cin >> x;
      }
      sqr[x] = 'X';
    }
    win = Checkwin(sqr);
    if (win == true){
      printBoard(sqr);
      break;
	}
    z++;
    printBoard(sqr);
    cout << "Choose your square: O" << endl;
    cin >> o;
    if (sqr[o] != 'X' and sqr[o] != 'O' and o > -1 and o < 9){
      sqr[o] = 'O';
    }
    else{
      cout << "Not valid move, try again" << endl;
      while ((sqr[o] == 'X' or sqr[o] == 'O') or (o < 0 or o > 8)){
	cout << "Choose your square: O" << endl;
	cin >> o;
      }
      sqr[o] = 'O';
    }
    win = Checkwin(sqr);
    if (win == true){
      printBoard(sqr);
      break;
	}
    z++;
  
  }
  cout << "Would you like to play again? y/n" << endl;
  cin >> play_again;
  cout << endl;
  if (play_again  == "y" or play_again == "yes"){
    restart = true;
	}
  else {
    restart = false;
      break;
  }
  }
}




bool Checkwin(char sqr[]){
  for(int i = 0; i < 4; i++){ //vertical
    if (sqr[i] == sqr[i+3] and sqr[i+3] == sqr[i+6]){
      cout << "**********" << endl;
      cout << sqr[i] << " Wins!" << endl;
      cout << "**********" << endl;
      return true;
    }
  }//diagonal
  if (sqr[0] == sqr[4] and sqr[4] == sqr[8]){
      cout << "**********" << endl;
      cout << sqr[4] << " Wins!" << endl;
      cout << "**********" << endl;
      return true;
  }
  if (sqr[2] == sqr[4] and sqr[4] == sqr[6]){
      cout << "**********" << endl;
      cout << sqr[4] << " Wins!" << endl;
      cout << "**********" << endl;
      return true;
  }

  for(int i = 0; i < 7; i = i+3){ //horizontal
    if (sqr[i] == sqr[i+1] and sqr[i+1] == sqr[i+2]){
	cout << "**********" << endl;
	cout << sqr[i] << " Wins!" << endl;;
	cout << "**********" << endl;
	return true;
	  }
  }
  return false;
}
  
 void printBoard(char sqr[]){
  cout << sqr[0] << "|" << sqr[1] << "|" << sqr[2] << endl;
  cout << "------" << endl;
  cout << sqr[3] << "|"  << sqr[4] << "|" << sqr[5] <<  endl;
  cout << "------" << endl;
  cout << sqr[6] << "|" << sqr[7] << "|" << sqr[8] << endl;
 }
