#include<iostream>
using namespace std;

class Stack{
	

	int top;
	
	public: 
	
    int len;  
	char data[];
	
	Stack(int l):len(l){
		
		data[len];
		top = -1;
	}
	
	
	void push(char c){
		
		if(top < len-1){
			
			data[++top] = c;
		}
		else{
			
			cout<<"Stack over flow "<<endl;
		}		
	}
	
	char pop(){
	
	   char val = -1;	
		
		if(!isEmpty()){
			
			val = data[top];
			data[top--] = -1;
			
			return val;
		}
		
		else{
			
			cout<<"Stack under flow "<<endl;
			
		}				
	}
	
	int isEmpty(){
		
       return top < 0;
	}
	
	//brackets checkk
	
   bool bracketscheck(string str){
   	
   	char x;
   	
   	for(int i=0;i<len;i++){
   		
   		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
   			
   			push(str[i]);
   			
   			continue;
   			
		   }
		   
		   
		   if(isEmpty()){
		   	return false;
		   }
		   
		   switch(str[i]){
		   	
		   	case ')':
		   		
		   		x = pop();
		   		
		   		if( x == '[' || x == '{'){
		   			return false;
				   }
				   break;
		   
		   	case ']':
		   		
		   		x = pop();
		   		
		   		if( x == '(' || x == '{'){
		   			return false;
				   }
				   break;
		    
			case '}':
		   		
		   		x = pop();
		   		
		   		if( x == '[' || x == '('){
		   			return false;
				   }
				   break;
		   } 		
	   }
	   
	   if(isEmpty()){
	   	return true;
	   }
   	 	
   }
   
   //precedence check
   
   int prec(char c) {
			if(c =='^') {
				return 3;
			}
			else if(c == '*' || c == '/') {
				return 2;
			}
			else if(c == '+' || c == '-') {
				return 1;
			}
			else {
				return -1;
			}
		}
   
   
   //infix to post fix
   
   void converyyt(string s) {
	
			string result;
	
			for(int i=0;i<len;i++) {
				char c = s[i];
		
				if((c>='a' && c <='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) {
					result +=c;
				}
				else if(c == '(') {
					push(c);
				}
				else if(c== ')') {
					
					while(data[top]!='(') {
						result+=data[top];
						pop();
					}
					pop();
				}
				else {
					while(!isEmpty() && prec(s[i]) <= prec(data[top])){
						result+=data[top];
						pop();
					}
					push(c);
				}
			}
	
			while(top>-1) {
				result+=data[top];
				pop();
			}
			cout << result << " ";
		}
		
		
	 void convert(string s){
	 	
	 	char c;
	 	string post;
	 	
	 	for(int i=0;i<len;i++){
	 		
	 		c = s[i];
	 		if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
	 			
	 			post = post + s[i];
			 }
			 
			 else if(s[i] == '('){
			 	
			 	push(s[i]);
			 }
			 
			 else if(s[i] == ')'){
			 	
			 	while(data[top] != '('){
			 		
			 		post = post + data[top];
			 		 
			 	   pop();			 		
				 }
				pop();	
			 }
			 
			 else{
			 	
			 	while(!isEmpty() && prec(s[i]) <= prec(data[top])){
			 		
			 		post = post + data[top];
			 		 pop();
				 }
				 
				 push(c);			 	
			 }	
	 		
		 }
		 
		 	while(top>-1) {
				post = post + data[top];
				c=pop();
			}
			cout << post << " ";	 	
	 	
	 }
		
	
		
		
};


int main(){
	
   	string a = "([]{})";
   	
   	string b = "(A+B)*(C+D)";
   	
   	int y = b.length();
   	
   	
   	Stack st(y);
   	
   	st.convert(b);
   	
  // 	int x = a.length();
   	
   // Stack s(x);
    
   // cout<<s.bracketscheck(a);
   
   
  
   	
	
	
}
