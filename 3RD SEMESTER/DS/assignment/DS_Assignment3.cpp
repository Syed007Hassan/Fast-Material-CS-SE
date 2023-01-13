#include <iostream>
using namespace std;

class Dynamic2dSafeArray {
	private:
		int n;
		int row,col;
		int **arr2;
	public:
		Dynamic2dSafeArray(int arr[9][9],int r,int c){
			
			row = 0;
			col = 0;
			n = 9;
			
			arr2 = new (nothrow) int *[n];
			
			for(int i=0;i<n;i++){
				arr2[i] = new (nothrow) int [n];
			}
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					arr2[i][j]=arr[i][j];
				}
			}
			
		}
			
		bool isSafe(int num) {
			
			for (int j = 0; j <= 8; j++) {   //checking the 1-9 no in the same row
				if (arr2[row][j] == num)
					return false;
			}

			for (int i = 0; i <= 8; i++) {   //checking the 1-9 no in the same column
				if (arr2[i][col] == num)
					return false;
			}
             
            cout<<"value of row is: "<<row<<endl; 
			int s_Row = row - row % 3,
			
			s_Col = col - col % 3;

			for (int i = 0; i < 3; i++) {         //checking each 3x3 matrix for 1-9 numbers
				for (int j = 0; j < 3; j++) {
					if (arr2[i + s_Row][j + s_Col] == num)
						return false;	
				}
			}

			return true;
}
		
		bool solved_sudoku() {
			if (row == n - 1 && col == n)
				return true;

			if (col == n) {   //if any columns moves to the last place increment the row
				row++;        //and move to another row
				col = 0;
			}

			if (arr2[row][col] > 0) {    //if in the same row and have not reached to the end
				col+=1;                  //moves the column to the next place
				return solved_sudoku();
			}

			for (int no = 1; no <= n; no++) {   //checking every element for each row and column individually
				if (isSafe(no)) {
					arr2[row][col] = no;
		
				if (solved_sudoku())
					return true;
				}
	
				arr2[row][col] = 0;
			}
			return false;
		}
		
		
			void print() {
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++)
					cout << arr2[i][j] << " ";
					
				cout << endl;	
			}
		}
};

main() {
	
	int r,c;
	int arr[9][9] ={{ 5, 3, 4, 6, 7, 8, 9, 1, 0 },
					{ 6, 7, 2, 1, 9, 5, 3, 4, 0 },
					{ 1, 9, 8, 3, 4, 2, 5, 6, 0 },
					{ 8, 5, 9, 7, 6, 1, 4, 2, 0 },
					{ 4, 2, 6, 8, 5, 3, 7, 9, 0 },
					{ 7, 1, 3, 9, 2, 4, 8, 5, 0 },
					{ 9, 6, 1, 5, 3, 7, 2, 8, 0 },
					{ 2, 8, 7, 4, 1, 9, 6, 3, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

	Dynamic2dSafeArray obj(arr,r,c);
	
	if(obj.solved_sudoku()){
			
			obj.print();
        }
	
	else{
	cout << "No Solution present!!" << endl;
	
    }
}
