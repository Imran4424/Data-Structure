#include <iostream>
#include <stack>
using namespace std;

int eva_postfix(char exp[]){
    stack<char> s;
    int op1,op2,res,i;
    
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]>0){
            s.push(exp[i]);
        }
        else if(exp[i]=='+'|| exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
            op2=s.top();
            s.pop();
            op1=s.top();
            s.pop();
            if(exp[i]=='+'){
                res = op1 + op2;
            }
            else if(exp[i]=='-'){
                res = op1 - op2;
            }
            else if(exp[i]=='*'){
                res = op1 * op2;
            }
            else{
                res = op1/op2;
            }  
        }
        s.push(res);
    }
    return s.top();

}

int main()
{
    int result;
	char exp[100];
	cout<<"postfix notation"<<endl;
	cin>>exp;
	cout<<exp<<endl;
	
	result=(int)eva_postfix(exp);
	
	cout<<result<<endl;
	
	return 0;
}
