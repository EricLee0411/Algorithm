# include <iostream>
# include <vector>
# include <queue>

using namespace std;

typedef struct node{
    int map[3][3];
}node;
bool check(queue <node*> &GoMap, vector<node*> &Record ,int TrueMap[3][3],    int WhereIsZeroRow, int WhereIsZeroCol, string command);
int main(){
    queue <node*> GoMap;
    vector<node*> Record;
    node *temp = new node;
    int Map[3][3];
    int TrueMap[3][3];
    int WhereIsZeroRow;
    int WhereIsZeroCol;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin>>Map[i][j];
            temp->map[i][j]=Map[i][j];
        }
    }
    Record.push_back(temp);
    GoMap.push(temp);
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin>>TrueMap[i][j];
        }
    }


    //find path
    bool up;
    bool down;
    bool right;
    bool left;
    while(GoMap.size()>0){
        int checkcount=0;
        //output the map
        node *wow = new node;
        wow=GoMap.front();

        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(j==2)cout<<wow->map[i][j]<<endl;
                else cout<<wow->map[i][j]<<" ";
                if(wow->map[i][j]==TrueMap[i][j]) checkcount++;
            }
            
        }
        //cout<<"----------"<<endl;
        //check whether output map is the answer or not
        if(checkcount == 9){
            break;
        }
        //find where is zero
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(wow->map[i][j]==0){WhereIsZeroRow=i;WhereIsZeroCol=j;}
            }
        }        
        if(WhereIsZeroRow==0){
            if(WhereIsZeroCol==0){
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
            }
            else if(WhereIsZeroCol==1){
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }
            else if(WhereIsZeroCol==2){
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }            
        }
        else if(WhereIsZeroRow==1){
            if(WhereIsZeroCol==0){
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
            }
            else if(WhereIsZeroCol==1){
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }
            else if(WhereIsZeroCol==2){
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                down=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"down");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }  
        }
        else if(WhereIsZeroRow==2){
            if(WhereIsZeroCol==0){
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
            }
            else if(WhereIsZeroCol==1){
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                right=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"right");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }
            else if(WhereIsZeroCol==2){
                up=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"up");
                left=check(GoMap,Record,TrueMap,WhereIsZeroRow,WhereIsZeroCol,"left");
            }  
        }
        GoMap.pop();
    }
}
bool check(queue <node*> &GoMap, vector<node*> &Record ,int TrueMap[3][3],int WhereIsZeroRow, int WhereIsZeroCol , string command){
    int NextMap[3][3];
    bool flag=true;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            NextMap[i][j]=GoMap.front()->map[i][j];
        }
    }        
    if(command == "up"){
        swap(NextMap[WhereIsZeroRow][WhereIsZeroCol],NextMap[WhereIsZeroRow-1][WhereIsZeroCol]);
    }
    else if(command == "down"){
        swap(NextMap[WhereIsZeroRow][WhereIsZeroCol],NextMap[WhereIsZeroRow+1][WhereIsZeroCol]);
    }
    else if(command == "right"){
        swap(NextMap[WhereIsZeroRow][WhereIsZeroCol],NextMap[WhereIsZeroRow][WhereIsZeroCol+1]);
    }
    else if(command == "left"){
        swap(NextMap[WhereIsZeroRow][WhereIsZeroCol],NextMap[WhereIsZeroRow][WhereIsZeroCol-1]);
    }
    node *temp =new node;

    //set node *temp
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            temp->map[i][j]=NextMap[i][j];
        }
    }

    for(int k = 0 ; k < Record.size() ;k++){
        int count = 0;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(NextMap[i][j]==Record[k]->map[i][j]) count++;
            }
        }
        if(count==9){ flag=false; return flag;}
    }    
    //cout<<command<<"-------"<<endl;
    GoMap.push(temp);
    Record.push_back(temp);
    return flag;
}
