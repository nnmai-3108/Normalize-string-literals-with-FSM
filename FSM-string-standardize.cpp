#include<iostream>
using namespace std;

char upper(char c){
	if (c>=97 && c<=122)     // if c is a lowercase
		c-=32;				 // capitalize c
	return c;
}

char lower(char c){
	if (c>=65 && c<=90)       // if c is a uppercase
		c+=32;				  // decapitalize c
	return c;
}

string del_last(string res){
	string r="";                           
	for (int i=0; i<res.size()-1; i++){   // add all char of res to r except the last one
		r+=res[i];
	}
	return r;
}

int make_move(string &res, int state, char input){
	/*
	Function to make a change of state.
	INPUT: string res, current state, input char
	OUTPUT: modify string res and return the next state
	*/
	switch(state){
		case 0:                           // if state=0 (start state)
			if (input==' '){			  // and next char is <space>
				return 0;				  // nothing changes, state still = 0
			}
			if (isalpha(input)){		  // if next char is <alpha>
				res+=upper(input);	      // captialize it and add to res
				return 1;				  // state changes to 1
			}
			break;
		case 1: 						  // if state=1
			if (input==' '){              // and next char is <space>
				res+=" ";				  // add that char to res
				return 3;				  // state changes to 3
			}
			if (isalpha(input)){		  // if next char is <alpha>
				res+=lower(input);	      // decapitalize it and add to res
				return 2;				  // state changes to 2
			}
			break;
		case 2:							  // if state=2
			if (input==' '){              // and next char is <space>
				res+=" ";				  // add that char to res
				return 3;				  // state changes to 3
			}
			if (isalpha(input)){		  // if next char is <alpha>
				res+=lower(input);	      // decapitalize it and add to res
				return 2;				  // state changes to 2
			}
			break;	
		case 3:							  // if state=3					
			if (input==' '){        	  // and next char is <space>
				return 4;                 // do nothing, state changes to 4
			}
			if (isalpha(input)){		  // if next char is <alpha>
				res+=upper(input);        // captialize it and add to res
				return 1;                 // state changes to 1
			}
			break;
		case 4:							  // if state=4
			if (input==' '){			  // and next char is <space>
				return 4;				  // do nothing, state changes to 4
			}
			if (isalpha(input)){          // if next char is <alpha>
				res+=upper(input);        // captialize it and add to res
				return 1;			      // state changes to 1
			}
			break;
	}
}

int main(){
	int state=0;                          // start state denoted by 0
	string s, res;
	getline(cin,s);
	res="";                               // res="" at its start state
	                                      // 5 states: 0 (start), 1, 2, 3, 4
	for (int i=0;i<s.size();i++){
		if (!isalpha(s[i]) && s[i]!=' '){  
			cout<<"Invalid character found in input string!"<<endl;
			return -1;
		}
		state=make_move(res,state,s[i]);  // at each step, read the next input char, then make a change to state and modify res 
	}
	if (state==4) 						  
		res=del_last(res);	              // if in the end, res is in state 4, it ends with ' '. We will delete it.
	cout<<res<<" "<<res.size();
}

