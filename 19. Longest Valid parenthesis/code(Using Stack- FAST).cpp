/*
	The workflow of the solution is as below.

	Scan the string from beginning to end.
	If current character is '(',
	push its index to the stack. If current character is ')' and the
	character at the index of the top of stack is '(', we just find a
	matching pair so pop from the stack. Otherwise, we push the index of
	')' to the stack.
	After the scan is done, the stack will only
	contain the indices of characters which cannot be matched. Then
	let's use the opposite side - substring between adjacent indices
	should be valid parentheses.
	If the stack is empty, the whole input
	string is valid. Otherwise, we can scan the stack to get longest
	valid substring as described in step 3.
*/

// O(n) solution
int longestValidParentheses(string str) 
{
    int n=str.length();
    if(n<2)
    {
        return 0;
    }
    
    stack<int> s1;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            s1.push(i);
        }
        else if(str[i]==')')
        {
            if(s1.empty()==false && str[s1.top()]=='(')
            {
                s1.pop();
            }
            else
            {
                s1.push(i);
            }
        }
    }
    
    if(s1.empty()==true)
    {
        return n;
    }
    
    stack<int> s2;
    while(s1.empty()==false)
    {
        s2.push(s1.top());
        s1.pop();
    }
    
    int maxLength=0;
    int length=0;
    for(int i=0;i<n;i++)
    {
        if(s2.empty()==true)
        {
            length= (n-1) - i + 1;
            maxLength=max(maxLength,length);
            break;
        }
        else if(i==s2.top())
        {
            s2.pop();
            maxLength=max(maxLength,length);
            length=0;
        }
        else
        {
            length++;
        }
    }
    return maxLength;
}