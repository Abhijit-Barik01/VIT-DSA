#include <iostream>

using namespace std;

class ThreeStack{

private:
    int size_st;
    const static int MYMAXIMUMSIZE = 100;
    int arr[MYMAXIMUMSIZE];
    
    int stackOnesize_st, stackTwosize_st, stackThreesize_st;
    int topOnest, topTwost, topThreest;



public:
    ThreeStack(int size_st){
        if(size_st > MYMAXIMUMSIZE){
            cout << "size_st cannot be greater than " << MYMAXIMUMSIZE << endl;
            return;
        }

        this->size_st = size_st;
        stackOnesize_st = size_st/3;
        stackTwosize_st = size_st/3;
        stackThreesize_st = size_st - (stackOnesize_st + stackTwosize_st);
        topOnest = stackOnesize_st;
        topTwost = stackOnesize_st-1;
        topThreest = stackOnesize_st+stackTwosize_st-1;        
    }

    bool isEmpty(int stackNumber){
        if(stackNumber == 1)
            return topOnest == stackOnesize_st;
        else if(stackNumber == 2)
            return topTwost == stackOnesize_st + stackTwosize_st;
        else 
            return topThreest == stackOnesize_st + stackTwosize_st - 1;
    }

    bool isFull(int stackNumber){
        if(stackNumber == 1)
            return topOnest == 0;
        else if(stackNumber == 2)
            return topTwost == stackOnesize_st+stackTwosize_st-1;
        else 
            return topThreest == size_st-1;
    }

    void push(int data, int stackNumber){
        if(!isFull(stackNumber)){
            if(stackNumber == 1){
                arr[--topOnest] = data;
            }
            else if(stackNumber == 2){
                arr[++topTwost] = data;
            }
            else {
                arr[++topThreest] = data;
            }
        }
        else {
            cout << "Stack " << stackNumber << " is Full" << endl;
        }
    }

    int pop(int stackNumber){
        if(!isEmpty(stackNumber)){
            if(stackNumber == 1){
                return arr[topOnest++];
            }
            else if(stackNumber == 2){
                return arr[topTwost--];
            }
            else return arr[topThreest--];
        }
        else {
            cout << "Stack " << stackNumber << " is Empty" << endl;
        }
    }

    int getsize_st(int stackNumber){
        if(stackNumber == 1) return stackOnesize_st;
        if(stackNumber == 2) return stackTwosize_st;
        return stackThreesize_st;
    }

    void display(){
        cout << "<-*****###STACK ONE###*****->" << endl;

        for(int i = topOnest; i < stackOnesize_st; i++){
            cout << arr[i] << endl;
        }


        cout << "<-*****###STACK TWO###*****->" << endl;

        for(int i = stackOnesize_st; i <= topTwost; i++){
            cout << arr[i] << endl;
        }

        cout << "<-*****###STACK THREE###*****->" << endl;

        for(int i = stackOnesize_st + stackTwosize_st; i <= topThreest; i++){
            cout << arr[i] << endl;
        }
    }
};



bool isStackNumberValid(int stackNumber){
    if(stackNumber >= 1 && stackNumber <= 3)
        return true;
    return false;
}

int main()
{
    

    int size, choice, data, stackNumber;
    cout << "Enter stack size: ";
    cin >> size;

    ThreeStack threeStack(size);
while(1){
      cout<<"\n"<<"***** MENU *****"<<"\n"<<endl;
      cout<<"1. Push\n2. Pop\n3. check if stack is empty\n4. Check if stack is full\n5. Display values\n6. Exit"<<endl;
      cout<<"\nEnter your choice:" <<endl;
      cin>>choice;
      switch(choice){
			case 1:
				cout << "Enter stack number: ";
            	cin >> stackNumber;

            		if(isStackNumberValid(stackNumber)){
                		cout << "Enter number to be inserted in stack: ";
                		cin >> data;
                		threeStack.push( data, stackNumber);
            		}
            	break;
            case 2:
            	cout << "Enter stack number: ";
	            cin >> stackNumber;
	
	            if(isStackNumberValid(stackNumber)){
	                cout << threeStack.pop(stackNumber) << endl;
	            }
	            break;
			case 3:
				cout << "Enter stack number: ";
                cin >> stackNumber;
		        if(isStackNumberValid(stackNumber)){
		                if(threeStack.isEmpty(stackNumber))
		                    cout << "Stack " << stackNumber << " is empty" << endl;
		                else
		                    cout << "Stack " << stackNumber << " is not empty" << endl;
		            }
		        break;
			case 4:
				cout << "Enter stack number: ";
            	cin >> stackNumber;

            	if(isStackNumberValid(stackNumber)){
                	if(threeStack.isFull(stackNumber))
                    	cout << "Stack " << stackNumber << " is full" << endl;
                	else
                    	cout << "Stack " << stackNumber << " is not full" << endl;
            	} 
            	break;
			case 5:
            		
				threeStack.display();
				break;
			case 6:
				exit(0);
			default: cout<<"\nWrong selection!!! Try again!!!"<<endl;
        	            
}
   
} 
return 0;
}


