//BSEF19M009 - Amna Azam-Assignment1
#include<iostream>
#include<string>
#include"stack.cpp"
using namespace std;

//function#01:
void isBalanced(string str)
{
		stack<char> obj(10);
		int lastIndex = str.length() - 1;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '=')             //expression can never include = sign in it.
			{
				obj.push(str[i]);
				break;
			}
			if ((str[i] == '}' && obj.top() == '{') || (str[i] == ']' && obj.top() == '[') || (str[i] == ')' && obj.top() == '('))       //if the respective brackets are ther in stack , pop them
			{
				obj.pop();
				continue;           //move up.
			}
			else if (str[i] == '{' || str[i] == '[' || str[i] == '(' || str[i] == '}' || str[i] == ']' || str[i] == ')')              //else push any closing or opening bracket in stack
				obj.push(str[i]);

			/*after any starting bracket, if there is * or / or %, 
			then expression is invalid and so
			do not make the stack empty and break from loop.*/

			if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			{
				if (str[i + 1] == '*' || str[i + 1] == '/' || str[i] == '%')
				{
					obj.push(str[i]);
					break;
				}
			}

			/*after + or - sign , if there is * or / or %,
			then expression is invalid and so
			do not make the stack empty and break from loop.*/

			if (str[i] == '+' || str[i] == '-')
			{
				if (str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '%')
				{
				obj.push(str[i]);
				break;
				}
			}

			/*after * or / or %, if there is any operator sign,
			then expression is invalid and so
			do not make the stack empty and break from loop.*/

			if (str[i] == '*' || str[i] == '/' || str[i] == '%')
			{
				if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i] == '%')
				{
					obj.push(str[i]);
					break;
				}
			}

			/*if any these conditions given below in 'IF' fulfilled
			then expression is invalid and so
			do not make the stack emptyand break from loop.*/

			if (str[0] == '*' || str[0] == '/' || str[0] == '%' || (str[i] == '+' && str[i + 1] == '+' && str[i + 2] == '+') ||
				(str[i] == '-' && str[i + 1] == '-' && str[i + 2] == '-') || str[lastIndex] == '*' ||
				str[lastIndex] == '/' || str[lastIndex] == '%' || (str[lastIndex] == '+' && str[lastIndex - 1] != '+') ||
				(str[lastIndex] == '-' && str[lastIndex - 1] != '-'))
			{
				obj.push(str[i]);
				break;
			}
			if (i + 2 < str.length())
			{
				if (str[i] >= '0' && str[i] <= '9' && str[i + 1] == '+' && str[i+2] == '+')
				{
					obj.push(str[i]);
					break;
				}
			}
			if (i - 2 >= 0)
			{
				if (str[i] >= '0' && str[i] <= '9' && str[i - 1] == '+' && str[i - 2] == '+')
				{
					obj.push(str[i]);
					break;
				}
			}

		}
		cout << "\n\n\n\t\t\t\t  __________________________ RESULT Announcement __________________________ \n";
		if (obj.isEmpty() == true)               //if all the brackets are poped and we are not here through break jump
			cout << "\n\t\t\t\t\t\t\t       CONGRATS! it is Balanced     " << "\n\n\n";
		else
			cout << "\n\t\t\t\t\t\t\t        ALAS! it is UnBalanced     " << "\n\n\n";
		while (obj.isEmpty() == false)           //if stack is not empty,make this memory free 
			obj.pop();
	}

//function#02:
string infixToPostfix(string str)
	{
		stack<char> obj(10);
		string result = "";
		for (int j = 0; j < str.length(); j++)
		{
			if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z'))       //appending operands
			{
				string s(1, str[j]);
				result += s;
				continue;                               //move up
			}
			else
			{
				if (obj.isEmpty() == true && str[j] != ')')     //pushing *,/,+,-,( in empty stack
				{
					obj.push(str[j]);
					continue;
				}
				else
				{
					if (str[j] == ')')                 //now if we are going to close bracket
					{
						while (obj.top() != '(')       //pop all those operators before starting bracket
						{
							char poped = obj.pop();
							string s(1, poped);
							result += s;
						}
						obj.pop();                    //bracket itself is being poped.
						continue;
					}
					if (str[j] == '(')                   //just like new stack, simply push and continue.
					{
						obj.push(str[j]);
						continue;
					}
					if ((obj.top() == '+'&& str[j]=='+')|| (obj.top() == '+' && str[j] == '-'))
					{
						char poped = obj.pop();
						string s(1, poped);
						result += s;
						obj.push(str[j]);
					}
					else if (obj.top() == '-' && str[j]=='-')
					{
							char poped = obj.pop();
							string s(1, poped);
							result += s;
							obj.push(str[j]);
					}
					else if (obj.top() == '*'&& str[j]!='/')
					{
							char poped = obj.pop();
							string s(1, poped);
							result += s;
							obj.push(str[j]);
					}
					else if ((obj.top() == '/' && str[j] == '-')||(obj.top() == '/' && str[j] == '+')||(obj.top() == '/' && str[j] == '*')||(obj.top() == '/' && str[j] == '-/'))
					{
						//do pop becaues same precedence operators
						char poped = obj.pop();
						string s(1, poped);
						result += s;
						obj.push(str[j]);	
					}
					else if (obj.top() == '(')
						obj.push(str[j]);
					//do push this character (It is allowable w.r.t to logic)
					else
					    obj.push(str[j]);   
			}
		}
		if (j == str.length())             //if all the string is read
			break;
	}
	//expression is stored in result name string. If there is any operator pushed in stack, pop it and append it with resultant string 
	while (obj.isEmpty() == false)
	{
		char poped = obj.pop();
		string s(1, poped);
		result += s;
	}
	return result;           //returning postfix expression
}

//function#03:
int Evaluate(string expression, int key)
{
	/*try catch syntax is used here to avoid risk if user enter any invalid postfix or prefix expression*/
		if (key == 1)                     //for postfix
		{
			stack<int> obj(10);
			string digit = "";
			//for postfix, start implementing logic from start of postfix expression
			for (int i = 0; i < expression.length(); i++)
			{
				if (expression[i] == ' ')  //ignore any space
					continue;
				//if there is any operator,pop two operands from stack and evaluate regarding to operator and push answer in stack. 
				if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
				{
					int temp1 = obj.pop();
					int temp2 = obj.pop();
					if (expression[i] == '+')
						obj.push(temp2 + temp1);
					else if (expression[i] == '-')
						obj.push(temp2 - temp1);
					else if (expression[i] == '*')
						obj.push(temp2 * temp1);
					else if (expression[i] == '/')
						obj.push(temp2 / temp1);
					continue;
				}
				digit = "";
				//reading 2 digit number like 10 11 12 13 14 21 21 34 etc , if any
				while (expression[i] != ' ' && expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/')
				{
					string s(1, expression[i++]);
					digit = digit + s;
					if (i >= expression.length())
						break;
				}
				i--;                              //after loop, 'i' is incremented one extra, so make it i-- 
				obj.push(stoi(digit));            //convert string into integer for implemetation befor pushin it into stack
			}
			int value = obj.pop();      //at the end, resultant after evaluation, is poped from stack   
			return value;             
		}
		if (key == 0)
		{
			//function#03:
			stack<int> obj(10);
			string digit = "";
			//for prefix, start implementing logic from end of infix expression
			for (int i = expression.length() - 1; i >= 0; i--)
			{
				if(i>expression.length())
				throw(1);  //may be garbage value error here in case 
				if (expression[i] == ' ')       //ignore any space
					continue;
				//if there is any operator,pop two operands from stack and evaluate regarding to operator and push answer in stack. 
				if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
				{
					int temp1 = obj.pop();
					int temp2 = obj.pop();
					if (expression[i] == '+')
						obj.push(temp1 + temp2);
					else if (expression[i] == '-')
						obj.push(temp1 - temp2);
					else if (expression[i] == '*')
						obj.push(temp1 * temp2);
					else if (expression[i] == '/')
						obj.push(temp1 / temp2);
					continue;
				}
				digit = "";
				//reading 2 digit number like 10 11 12 13 14 21 21 34 etc , if any
				while (expression[i] != ' ' && expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/')
				{
					string s(1, expression[i++]);
					digit = digit + s;
					if (i > -1)
						break;
				} 
				i--;            //after loop, 'i' is incremented one extra, so make it i-- 
				obj.push(stoi(digit));
			}
			int value = obj.pop();          //at the end, resultant after evaluation, is poped from stack
			return value;
		}
}

int main()
{
	//task1(1):
	cout << "\n\n\n\t\t\t\t\t\t\t______   BALANCING   ______\n\n\n";
	cout << "       Read INSTRUCTIONS :: \n\n";
	cout << "   1)- Make sure you do not enter any space in your expression, otherwise your expression written after the space will be terminated.\n";
	cout << "   2)- Whenever you write any expression including unary operator(++ or --) with any binary operator(+,-,*,%) like a++%b ,\n       Make SURE you PUT it into BRACKETS like (a++)%b  to aviod ambiguity,\n       Otherwise it would be marked unbalanced.\n\n\n";
	cout << "       Enter your expression here to check whether it is balanced or not ::  ";
	string str;
	cin >> str;
	isBalanced(str);

	//task1(2):
	cout << "\n\n\n\t\t\t\t\t\t\t______    INFIX_TO_POSTFIX conversion    ______\n\n\n";
	string str1;
	cout << "   Enter expression in infix notation using alphabets not numbers :: ";
	cin >> str1;
	string result = infixToPostfix(str1);
	cout << "\n\n\n\t\t\t\t  __________________________ RESULT Announcement __________________________ \n";
	cout << "\n\t\t\t\t\t\t  Expression in postfix notation :: " << result << "\n\n\n";

	//task1(3):
	cout << "\n\t\t\t\t\t\t\t_____  POSTFIX or PREFIX Evaluation  _____    \n\n\n";
	cout << "\n\t\t\t\t\t    INSTRUCTIONS::\n";
	cout << "\t\t\t\t\t1)- POSTFIX or INFIX Expression must be valid w.r.t to operators and operands.\n";
	cout << "\t\t\t\t\t2)- Make sure to enter space separated operands to differentiate\n";
	cout<<"\t\t\t\t\t    the digits greater than two like 12 56 34 etc.\n ";
	cout << "\t\t\t\t\t3)- Just >[use SPACE]< to separate one OPERAND from other OPERAND.";
	cout<<"\n\t\t\t\t\t    Otherwise your expression will be marked invalid\n";
	cout << "\t\t\t\t\t4)- keep in mind you do >[NOT]< need to enter space b/w operator and operand or Operator and operator.\n";
	cout << "\n\t\t\t\t        Space separated input format is shown below so that we can differentiate b/w two different operands.\n";
	cout << "\t\t\t\t\tPREFIX EXAMPLES:: \n\t\t\t\t\t\t+1 2\n\t\t\t\t\t\t++1*2 3 4\n\t\t\t\t\t\t*+4 5 6\n\t\t\t\t\t\t*+*+1 2 3 4 5\n\t\t\t\t\t\tetc....\n";
	cout << "\n\n\t\t\t\t\tPOSTFIX EXAMPLES:: \n\t\t\t\t\t\t12 6/1-3 4*+12 1*-\n\t\t\t\t\t\t4 5 6*+\n\t\t\t\t\t\t1 2 3 4 5*+*+\n\t\t\t\t\t\tetc....\n";
	cout << "\n\n\n\t\t\t\t\t\t\t.....   LET'S GO   .....   \n\n\n";
	cout << "\n\n\n   Enter 0 for prefix expression evaluation && 1 for postfix expression evaluation :: ";
	int key;
	cin >> key;
	while (key != 0 && key != 1)
	{
		cout << "\n   INVALID!!\n";
		cout << "   AGAIN, Enter valid input :: ";
		cin >> key;
	}
	string exp;
	cin.ignore();
	if (key == 0)
		cout << "   OKAY! now Enter prefix expression, consisting of digits, for evaluation:: ";
	if (key == 1)
		cout << "   OKAY! now Enter postfix expression, consisting of digits, for evaluation:: ";
	getline(cin, exp);
	int val = Evaluate(exp, key);
	cout << "\n\n\n\t\t\t\t  __________________________ RESULT Announcement __________________________ \n";
	cout << "\n\t\t\t\t\t\t\t   Value after evaluation :: " << val << "\n\n\n";
	return 0;
}