#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNumber;

void easyGame(){
    cout<<"easy level: thinking a number between 1 and 10..."<<endl;
    randomNumber= rand() % (10) + 1;
    
}
void mediumGame(){
    cout<<"medium game: guess a number between 1 and 50"<<endl;
    randomNumber= rand() % (50) + 1;
    
}
void hardGame(){
    cout<<"hard level: guess a number between 1 and 100"<<endl;
    randomNumber= rand() % (100) + 1;
    
}
void getRandomNumber(int level){
    srand(time(nullptr));
    
    if (level==1){
        easyGame();
    }else if (level==2){
        mediumGame();
    }else if (level==3){
        hardGame();
    } else{
        cout<< "invalid level number"<<endl; 
    }
}

void opening(){
    int level;
    
    cout<<"welcome to the number-guessing game!"<<endl;
    
    do{
        cout<<" choose a level to play: \n 1. EASY \n 2. MEDIUM \n 3. HARD \n enter 1,2 or 3"<< endl;
        cin>> level;
        
        if (level == 1 || level == 2 || level == 3) {
            getRandomNumber(level);  // Valid level, so we can proceed
            break;
        } else {
            cout << "invalid level! please try again.\n";
        }
    } while(true);
}


int main(){
    opening();
    
 
    do {   
        
        int guess;
        cout<< "you can make a guess now: "<<endl;
        cin>>guess;
        
        if (guess< randomNumber) {
            cout << "too low! try again."<<endl;
        } else if (guess>randomNumber) {
            cout << "too high! try again."<<endl;
        } else {
            cout << "congratulations! you guessed the number!"<<endl;
            break;
        }
    
    } while(true); 
    
    return 0;
}