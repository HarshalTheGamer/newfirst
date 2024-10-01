/*
Harshal Narendra Patil
Div.A SY PRN.123B1B055
Stack
*/
#include <iostream>
using namespace std;

struct Node{
    string strWebsite;
    Node *next;
};
class Stack{
    Node *top;  
    public:
        Stack(){
            top == NULL;
        }
        bool IsEmpty(){
            if(top){
                return 1;
            }
            return 0;
        }
        void Push(string strWeb){
            Node *NN = new Node;
            NN->strWebsite = strWeb;
            NN->next = top;
            top = NN;
        }
        string Pop(){
            if(IsEmpty()){
                return NULL;
            }
            Node *temp = top;
            string strData = top->strWebsite;
            top = top->next;
            delete temp;
            return strData;
        }
        string Peek(){
            if(IsEmpty()){
                return NULL;
            }
            return top->strWebsite;
        }
};

class Browser{
    Stack History, Backup;
    public
        void NewWeb(string strWeb){
            History.Push(strWeb);
        }
        void Forward(string strWeb){
            if(Backup.IsEmpty()){
                Histor.Push(strWeb);
            }
            History.Push(Backup.Pop());
        }
        string Backward(){
            string strData = History.Pop();
            Backup.Push(strData);
            return strData;
        }
        string Current(){
            return History.Peek();
        }
};
int main() {
    Browser Brave;
    string strSite;
    int choice;
    cout << "MENU\n1.New Website\n2.Forward in history\n3.Backward in history\n4.quit\n";
    while(1){
        cout << "Enter choice ";
        cin >> choice;
        if(choice == 1){
            cout << "Enter new website\n";
            cin >> strSite;
            Brave.NewWeb(strSite);
        }
        else if(choice == 2){
            Brave.Forward();
            cout << "Current Website is " << Brave.Current();
        }
        else if(choice == 3){
            Brave.Backward();
            cout << "Current website is " << Brave.Current();
        }
        else if(choice == 4){
            break;
        }
        else{
            cout << "Enter Valid choices \n\n";
        }
    }
    return 0;
}