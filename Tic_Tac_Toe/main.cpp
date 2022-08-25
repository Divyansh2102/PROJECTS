#include<bits/stdc++.h>
using namespace std;
int r=3,c=3; 
char turn;
bool draw=false;
string p1,p2,f_player;
char grid[3][3]={{'*','-','.'},{'@','#','$'},{'*','-','.'}}; 
    //Making a 3 X 3 array so that it can be represented as a grid like 
                    /*    __|__|__
                          __|__|__
                            |  |          */
void display(){
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout<<grid[i][j]<<"   ";
    //     }
    //     cout<<endl;
    // }
    cout<<grid[0][0]<<" | "<<grid[0][1]<<" | "<<grid[0][2];
    cout<<"\n__ "<<" __ "<< " __"<<endl;
    cout<<grid[1][0]<<" | "<<grid[1][1]<<" | "<<grid[1][2];
    cout<<"\n__ "<<" __ "<< " __"<<endl;
    cout<<grid[2][0]<<" | "<<grid[2][1]<<" | "<<grid[2][2];
}
void insert(){
    int x,y;
    if(turn=='X')
        cout<<"\nEnter for "<<p1<<endl;
    else    
        cout<<"\nEnter for "<<p2<<endl;
    while(true){
        cout<<"Enter the row(0-2)  ";
        cin>>x;
        if(x>=0 &&x<3)
            break;
        else
            cout<<"\nEnter valid position  ";
    }
    while(true){
        cout<<"Enter the column(0-2)  ";
        cin>>y;
        if(y>=0 &&y<3)
            break;
        else
            cout<<"\nEnter valid position  ";
    }
    if(turn=='X' && grid[x][y]!='X' && grid[x][y]!='O'){
        grid[x][y]='X';
        turn='O';
    }
    else if(turn=='O' && grid[x][y]!='X' && grid[x][y]!='O'){
        grid[x][y]='O';
        turn='X';
    }
    else{
        cout<<"\nColumn is already filled please enter different position ";
        insert();
    }
    display();
}
bool gameover(){
    //checking row and column
    for(int i=0;i<3;i++){
        if((grid[i][0]==grid[i][1] && grid[i][0]==grid[i][2]) || (grid[0][i]==grid[1][i] && grid[0][i]==grid[2][i]))
            return false;
    }
    //checking both diagonals
    if((grid[0][0]==grid[1][1] && grid[0][0]==grid[2][2]) || (grid[0][2]==grid[1][1] && grid[0][2]==grid[2][2]))
        return false;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]!='X' && grid[i][j]!='O')
                return true;
        }
    }
    draw=true;
    return false;
} 
int main(){
    cout<<"__________________________________________________________________________\n";
    cout<<"\n\t\t\tTIC TAC TOE\n";
    cout<<"__________________________________________________________________________\n";
    cout<<"\nEnter the name for 'X' :   ";
    cin>>p1;
    cout<<"\nEnter the name for 'O' :   ";
    cin>>p2;

    while(true){
        cout<<"\nWho's going to go first "<<p1<<" or "<<p2<<" :   ";
        cin>>f_player;
        if(f_player==p1 || f_player==p2)
            break;
        else 
            cout<<"\nInvalid choice please enter again";
    }
    cout<<"\nOk then let's start here's how the grid looks like \n";
    display();
    if(f_player==p1)
        turn='X';
    else
        turn ='O';
    while(gameover()){
        insert();
        gameover();
    }
    if(turn=='X' && draw==false)
        cout<<endl<<p2<<" Wins";
    else if(turn=='O' && draw==false)
        cout<<endl<<p1<<" Wins";
    else
        cout<<"Game Draw";
    return 0;
}