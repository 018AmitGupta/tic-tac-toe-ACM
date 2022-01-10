#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
using namespace std;
int compare(int x,int y,int z)
{
    if(x==y)
    {
        if(x==z)
            return 1;
        else
            return 0;
    }
    return 0;
}
class player
{
private:
    char name[10];
    char symbol;
public:
    void insert(char* ch,char c)
    {
        strcpy(name,ch);
        symbol=c;
    }
    char getSymbol()
    {
        return symbol;
    }
    char* getName()
    {
        return name;
    }
};
class TicTocToe
{
private:
    int arr[3][3];
    player p1,p2;
    int flag;
    char n[10];
public:
    TicTocToe()
    {
        flag=1;
    }
    void display()
    {
        system("cls");
        //cout<<"\n\n\n\t\t";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(arr[i][j]>=1 && arr[i][j]<=9)
                cout<<" "<<arr[i][j];
                else
                cout<<" "<<(char)arr[i][j];
                if(j!=2)
                    cout<<" |";
            }
            if(i!=2){
            cout<<endl;
            cout<<"----------";}
            cout<<endl;
        }
    }
    void intial()
    {
         flag=1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {arr[i][j]=i*3+j+1;}
        }
    }
    void intro()
    {
        cout<<"Player First :";cin>>n;
        p1.insert(n,'x');
        cout<<"\nPlayer Second :";cin>>n;
        p2.insert(n,'0');
        cout<<"\n\n\t\t\tSymbol '"<<p1.getSymbol()<<"' for Player "<<p1.getName();
        cout<<"\t\t\tSymbol '"<<p2.getSymbol()<<"' for Player "<<p2.getName();
        getch();
    }
    void turn()
    {
        cout<<endl;
        if(flag==1)
            cout<<p1.getName()<<"`s"<<'('<<p1.getSymbol()<<')'<<" turn";
        else
            cout<<p2.getName()<<"`s"<<'('<<p2.getSymbol()<<')'<<" turn";
    }
    void change(int x)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
            if(x==arr[i][j])
            {
               if(flag==1){
                arr[i][j]=p1.getSymbol();
                flag=2;
                }
               else{
               arr[i][j]=p2.getSymbol();
               flag=1;
               }

            }
            }
        }
    }

    int checkWin()
    {
        if(compare(arr[0][0],arr[0][1],arr[0][2]))
            return 1;
        if(compare(arr[1][0],arr[1][1],arr[1][2]))
            return 1;
        if(compare(arr[2][0],arr[2][1],arr[2][2]))
            return 1;
        if(compare(arr[0][0],arr[1][0],arr[2][0]))
            return 1;
        if(compare(arr[0][1],arr[1][1],arr[2][1]))
            return 1;
        if(compare(arr[0][2],arr[1][2],arr[2][2]))
            return 1;
        if(compare(arr[0][0],arr[1][1],arr[2][2]))
            return 1;
        if(compare(arr[0][2],arr[1][1],arr[2][0]))
            return 1;
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                    if(arr[i][j]>=1 && arr[i][j]<=9)
                    return 0;
            }
        return 2;
    }
    void declareWinner()
    {
        if(flag==2)
            cout<<"\n\t\t"<<p1.getName()<<'('<<p1.getSymbol()<<')'<<" is Winner ";
        else
            cout<<"\n\t\t"<<p2.getName()<<'('<<p2.getSymbol()<<')'<<" is Winner ";
            swap();
    }
    void swap()
    {
        player temp;
        temp.insert(p1.getName(),p1.getSymbol());
        p1.insert(p2.getName(),p2.getSymbol());
        p2.insert(temp.getName(),temp.getSymbol());

    }
};
int main()
{
    TicTocToe obj;
    char choice;
    int t=0,x;
    obj.intro();
    while(choice!='n' && choice!='N'){
            t=0;
            obj.intial();
    while(!t)
    {
        obj.display();
        obj.turn();
        x=getch()-48;
        obj.change(x);
        t=obj.checkWin();
    }
    obj.display();
    if(t==2){
        cout<<"\nGameOver!";
        obj.swap();
    }
    if(t==1)
    {
        obj.declareWinner();
    }

    cout<<"\nTryAgain (Y/N) ";cin>>choice;
    }
    cout<<"\nThanks for Enjoy my Game ";
    getch();
    return 0;

}
