#include<iostream>
using namespace std;
#include <stdbool.h>


class WordFinder{
	
	private:
		int r,c;
		char **arr;
		
	public:
	
	WordFinder(char array[5][6],int m,int n){
		
		r = m;
		c = n;
		
		arr = new (nothrow) char *[r];
		
		for(int i=0;i<r;i++){
			
			arr[i] = new (nothrow) char[c];
		}
		
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				arr[i][j] = array[i][j];
			}
		}	
	}
	
bool match(char array1[4][6],int R,int C)
{
    // If we reach at the end of both strings, we are done
     int i=0,j=0;
    if (arr[i][j] == '\0' && array1[i][j] == '\0')
        return true;
 
    // Make sure that the characters after '*' are present
    // in second string. This function assumes that the first
    // string will not contain two consecutive '*'
    if (arr[i][j] == '+' && arr[i][j+1]!= '\0' && array1[i][j]== '\0')
        return false;
 
    // If the first string contains '?', or current characters
    // of both strings match
    if (arr[i][j] == '+' || arr[i][j] == array1[i][j])
        return match(arr[i][j+1], array1[i][j+1]);
 
    // If there is *, then there are two possibilities
    // a) We consider current character of second string
    // b) We ignore current character of second string.
    if (arr[i][j] == '*')
        return match(arr[i][j+1], array1[i][j]) || match(arr[i][j], array1[i][j+1]);
    return false;
}
 
// A function to run test cases
void test(char array1[i][j], char array1[i][j])
{  match(first, second)? puts("Yes"): puts("No"); }
	
		
	
};






int main(){
	
	int m = 5, n = 6;
	
	
	char array[5][6]={"FIVET",
                      "XACPP",
                      "PUS*S",
                      "PU*HP",
                      "LI+HT"};
                      
    char array1[4][6]={"FIVE",
                      "CPP",
                      "PUSH",
                      "PUSP"};               
	
	WordFinder W(array,m,n);
	
	cout<<W.findtheword(array1,4,6);
	
}
