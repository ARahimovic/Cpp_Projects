/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stack>

bool isBalanced(const std::string& str)
{
    
    std::stack<char> myStack;
    
    for(const char& c : str)
    {
        if(c == '(' || c == '{'  || c == '[' )
            myStack.push(c);
        
        else if ( c == ')' || c == '}'  || c == ']')
        {
            //closing bracket with stack is empty
            if(myStack.size() == 0) return false;
            
            char top = myStack.top();
            
            if( (c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[') )
                {
                    myStack.pop();
                    continue;
                }
            
            else
                
                return false;
        }    
      
    }
    
    return myStack.empty() ;
}

int main()
{
    std::cout<<isBalanced("(){}{}[]");
    std::cout<<isBalanced("){}{}[]");
    std::cout<<isBalanced("{");
    std::cout<<isBalanced("({[]})");
    
    
    

    return 0;
}
