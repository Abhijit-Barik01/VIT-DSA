#include <iostream>
#include <string>

using namespace std;

class DVD {

private:
    const static int MAX = 1000;
    char dvdData[MAX];
    int front;
    int rear;

    bool isEmpty(){
        return front == -1 && rear == -1;
    }

    bool isFull(){
        return (rear + 1) % MAX == front;
    }

public: 
    DVD(){
        front = rear = -1;
    }

    void writeData(char data){

        if(isEmpty()){
            front = rear = 0;
            dvdData[rear] = data;
        } else if(isFull()){
            cout << "Error: DVD overflow!" << endl;
        }
        else {
            rear = (rear+1) % MAX;
            dvdData[rear] = data;
        }
    }

    char deleteData(){
        if(isEmpty()){
            cout << "Error: DVD is empty!" << endl;
            return '\0';
        }
        else if(front == rear){
            int temp = front;
            front = rear = -1;
            return dvdData[temp];           
        }
        else {
            int temp = front;
            front = (front+1) % MAX;
            return dvdData[temp];
        }
    }

    void play(){
        if(isEmpty()){
            cout << "DVD is empty" << endl;
            return;
        }

        for(int i = front; i <= rear; i = (i+1)%MAX){
            cout << dvdData[i];
        }
        cout << endl;
    }
 
    int getFront(){
        return front;
    }

    int getRear(){
        return rear;
    }
};


void showMenu(){
    cout << "ENTER 1 TO WRITE DATA IN DVD:" << endl;
    cout << "ENTER 2 TO READING DVD:" << endl;
    cout << "ENTER 3 TO  PRINT FRONT AND REAR INDEX:" << endl;
    cout << "ENTER 4 TO EXIT:" << endl;
}


int main(){
    
    DVD dvdPlayer;
    string data;
    int choice; 

    showMenu();

    do{
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1: {
                cout << "Enter data to be written in DVD: ";
                getline(cin, data);

                for(int i = 0; i < data.size(); i++){
                    dvdPlayer.writeData(data[i]);
                }
                break;
            }

            case 2: {
                dvdPlayer.play();
                break;
            }

            case 3: {
                cout << "Front index: " << dvdPlayer.getFront() << endl;
                cout << "Rear index: " << dvdPlayer.getRear() << endl;
                break;
            }

            case 4: {
                return 0;
            }
        }



    }while(choice != 4);


    return 0;
}
