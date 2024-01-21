#include <iostream>
#include <cctype>
using namespace std;

class transaction
{
    private:
        float MoneyTrans;
        float MoneyDeposit;
        float MoneyWithdraw;
        float BalanceMoney;

    public:
        void Transfer(void);
        void Deposit(void);
        void Withdraw(void);
        void Balance(void);
};

void transaction :: Transfer(void)
{
    cout<<"Enter amount to transfer: ";
    cin >> MoneyTrans;
    
    if (BalanceMoney-MoneyTrans<1000)
    {
        cout<<"Insufficient Balance."<<endl;
    }
    else
    {
        BalanceMoney = BalanceMoney - MoneyTrans;
        cout<<"Transaction Complete."<<endl<<"Current Balance: "<<BalanceMoney<<endl;
    }
}

void transaction :: Deposit(void)
{
    cout<<"Enter amount to deposit: ";
    cin>>MoneyDeposit;
    BalanceMoney = BalanceMoney + MoneyDeposit;
    cout<<"Transaction Complete."<<endl<<"Current Balance: "<<BalanceMoney<<endl;
}

void transaction :: Withdraw(void)
{
    cout<<"Enter amount to be withdraw: ";
    cin>>MoneyWithdraw;
    if (BalanceMoney-MoneyWithdraw<1000)
    {
        cout<<"Insufficient Balance."<<endl;
    }

    else if (BalanceMoney<MoneyWithdraw)
    {
        cout<<"Insufficient Balance."<<endl;
    }
    
    else
    {
        BalanceMoney = BalanceMoney - MoneyWithdraw;
        cout<<"Transaction Complete."<<endl<<"Current Balance: "<<BalanceMoney<<endl;
    }
}

void transaction :: Balance(void)
{
    cout<<"Your Balance: "<<BalanceMoney<<endl;
}

void conditions(int options, char loop)
{
    transaction trans;

    cout<<"Welcome to TSR International Bank"<<endl<<"How we can help you today?"<<endl;

    do{
        cout<<"1 : Deposit\t2 : Withdraw\t3 : Balance"<<endl<<"--> ";
        cin>>options;

        switch (options)
        {
        case 1 : trans.Deposit();
            break;
        case 2 : trans.Withdraw();
            break;
        case 3 : trans.Balance();
            break;

        default:
            cout<<"Something went wrong"<<endl;
            break;
        }

        cout<<"Do you have any other query?"<<endl<<"(Y/N) - ";
        cin>>loop;
        
    } while(toupper(loop)=='Y');
}

int main() {

    int options;
    char loop;
    conditions(options, loop);

    return 0;
}