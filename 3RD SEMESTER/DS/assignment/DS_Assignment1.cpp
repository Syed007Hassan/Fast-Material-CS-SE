#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char PlusFunction(char letter){
    return letter;
}

void AsteriskFunction(string searchstring, int *length){
    if((*length)==0){
        (*length) = (*length)+1;
    }
    else{
        (*length) = searchstring.length()-2;
    }
}

char WildCard(char wildCard, char letter,string searchstring,int *length){

    if((*length)==0){
        return letter;
    }
    else{
        if(wildCard == '+'){
            return PlusFunction(letter);
        }       
        else{
            AsteriskFunction(searchstring,length);
        } 

    }
}

char setSearchDirection(int x_dir , int y_dir){
    if(x_dir == 0 && y_dir == 1){
        return 'R';
    }
    else if(x_dir == 0 && y_dir == -1){
        return 'L';
    }
    else if(x_dir == 1 && y_dir == 0){
        return 'D';
    }
    else{
        return 'U';
    }
}

bool SearchWord(char **array,string findWord, int row , int col, int ROW, int COL){

    int dirX[] = {0,0, 1,-1};
    int dirY[] = {1,-1,0,0};

    bool found=false;

    // char variable that is modified upon wild card encounter so that original array is not modified
    char firstChar=array[row][col];

    if(array[row][col] == '+'){
        int len=0;
        firstChar = WildCard(firstChar,findWord[0],findWord,&len);
    }

    if(firstChar != findWord[0] && array[row][col] != findWord[0]){
        return false;
    }

    int wordLength = findWord.length();

    for(int dir=0; dir<4; dir++){
        
        int i;
        // move in a certain coordinates
        int row_dir=row+dirX[dir];
        int col_dir=col+dirY[dir];
          
        for(i=1; i<wordLength; i++){
            
            // bound check
            if(row_dir >= ROW || row_dir < 0 || col_dir >= COL || col_dir<0){
                break;
            }
            
            firstChar = array[row_dir][col_dir];

            // run function that handles wild card * 
            // wild card * should not be matched with last element of search word
            if(array[row_dir][col_dir] == '*' && i!=wordLength-1){
                WildCard(firstChar,findWord[i],findWord,&i);
                row_dir+=dirX[dir];
                col_dir+=dirY[dir];
                continue;
            }

            // run function that handles wild card + 
            if(array[row_dir][col_dir] == '+'){
                firstChar = WildCard(firstChar,findWord[i],findWord,&i);
            }
            
            // if any element of 2d char array and search word does not match then stop the loop
            if(firstChar != findWord[i]){
                break;
            }

            // move the row and col according to the seach direction set in for loop
            row_dir+=dirX[dir];
            col_dir+=dirY[dir];

        }
        // if every element is matched of both char and 2d array then 
        if(i==wordLength && firstChar==findWord[findWord.length()-1]){
            cout<<row<<" "<<col<<" ";
            cout<<setSearchDirection(dirX[dir],dirY[dir]);
            cout<<endl;
            found=true;
        }
    }
    if(found){
        return true;
    }
    return false;
}

bool WordFinder(char **array,string searchword,int ROW, int COL){
    
    bool found=false;
    for(int row=0; row<ROW; row++){
        for(int col=0; col<COL; col++){

            if(SearchWord(array,searchword,row,col,ROW,COL)){
              found=true;
            }

        }
    }
    if(found == false){
        cout<<"N"<<endl;
    }
}

int main(){

    int row_n,col_m;
    int p_words;
    
	// use standard input and output (no file i/o required)

	cin>>row_n;
	cin>>col_m;

	char **Array = new char*[row_n];
	
	for(int row=0;row < row_n; row++){
	    Array[row] = new char[row_n];
	    for(int col=0; col<col_m; col++){
	        cin>>Array[row][col];
	    }
	}	

	cin>>p_words;
	
	cin.ignore();

	string *findWords = new string[p_words];
    
	for(int i=0;i < p_words; i++){
	    getline(cin,findWords[i]);
	    findWords[i].erase(remove(findWords[i].begin(), findWords[i].end(), ' '), findWords[i].end());
	}
	
	// TODO: Your solution here

    for(int i=0; i<p_words; i++){
        WordFinder(Array,findWords[i],row_n,col_m);
    }

	return 0; // always return 0 from here
}