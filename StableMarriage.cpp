#include <iostream>
using namespace std;

void printMatching(int q[]){
    static int sol = 0;
    cout << "Solution #" << ++sol << endl;
    for ( int i = 0; i < 3; i++ ){
        cout << "male: " << i << " and female: " << q[i] << endl;
    }
    cout << endl;
}
  
bool ok(int q[], int col){  

    int mp[3][3] = {{0,2,1},   
                    {0,2,1},
                    {1,2,0}};   

    int wp[3][3] = {{2,1,0},
                    {0,1,2},
                    {2,0,1}};

    //nm = new man
    //nw = new woman
    //cm = a currently assigned man
    //cw = a currently assigned woman
    //nm and nw are the proposed pair to add to the match

    int cm, cw, nm, nw;

    nm = col;
    nw = q[col];

    for (cm = 0; cm < col; cm++){
        if (q[cm] == nw) return false;
    }
    /*
       Check the new pair (new man, new woman) against each existing pair consisting of
       (current man, current woman) to see if the new pair would make the match unstable.
    */
    for (cm = 0; cm < col; cm++) {
        cw = q[cm];
        //Lower value implies a higher preference

        //    if the current man prefers the new woman to his partner and
        //    if the new woman prefers the current man to her partner, reject
        if(mp[cm][nw] < mp[cm][cw] 
        && wp[nw][cm] < wp[nw][nm]) return false;

        //    if the new man prefers the current woman to his partner and
        //    if the current woman prefers the new man to her partner, reject
        if(mp[nm][cw] < mp[nm][nw]
        && wp[cw][nm] < wp[cw][cm]) return false;
    }

    return true; 
}

void move(int q[], int newMan) {
  if(newMan == 3){
    printMatching(q);
    return;
  }
  for(int i = 0; i < 3;i++){
    q[newMan] = i;
    if(ok(q, newMan)){
      move(q, newMan+1);
    }
  }
  return ;
}

int main(){
  int q[3] = {0};
  move(q,0);
}