#include <iostream>
using namespace std;

class Hanoi{
    private:
        int count;
    public:
        Hanoi();
        void StartToDest(string s, string d, string A1, string A2, string A3, int n);
        void StartToA3(string s, string d, string A1, string A2, string A3, int n);
        void A3ToDest(string A3, string A2, string A1, string d, int n);
        void oneHop(string A1, string A2, string A3, int n);
        void move(string from, string to, int n);
};

Hanoi::Hanoi(){
    count = 0;
}

void Hanoi::move(string from, string to, int n){
    count++;
    cout << "Move " << count << ": Move disk " << n << " from " << from << " to " << to << endl;
}

void Hanoi::StartToDest(string s, string d, string A1, string A2, string A3, int n){ // starts the algorithm
    if(n == 1){
        move(s, d, n);
    }
    else if(n >= 2){
        StartToA3(s, d, A1, A2, A3, n - 1); // moves n - 1 disks from Start to A3, O(3^n)
        move(s, d, n);
        A3ToDest(A3, A2, A1, d, n - 1); // moves n - 1 disks from A3 to Dest, O(3^n)
    }
} // moves all disks to dest

void Hanoi::StartToA3(string s, string d, string A1, string A2, string A3, int n){
    if(n == 1){
        move(s, d, n);
        move(d, A1, n);
        move(A1, A2, n);
        move(A2, A3, n);
    } // base case
    else if(n >= 2){
        StartToA3(s, d, A1, A2, A3, n - 1); // recursive call
        move(s, d, n);
        move(d, A1, n);
        move(A1, A2, n);
        oneHop(A3, A2, A1, n - 1); // moving n - 1 disks from A3 to A1
        move(A2, A3, n);
        oneHop(A1, A2, A3, n - 1); // moving n - 1 disks from A1 to A3
    }
} // moves all disks from 'start' to 'A3'

void Hanoi::oneHop(string A1, string A2, string A3, int n){
    if(n == 1){
        move(A1, A2, n);
        move(A2, A3, n);
    }
    else if(n >= 2){
        oneHop(A1, A2, A3, n - 1); // moves n - 1 disks from A1 to A3
        move(A1, A2, n);
        oneHop(A3, A2, A1, n - 1); // moves n - 1 disks from A3 to A1
        move(A2, A3, n);
        oneHop(A1, A2, A3, n - 1); // moves n - 1 disks from A1 to A3
    }
} // moves all disks from 'A1' to 'A3', O(3^n)

void Hanoi::A3ToDest(string A3, string A2, string A1, string d, int n){
    if(n == 1){
        
        move(A3, A2, n);
        move(A2, A1, n);
        move(A1, d, n);
    }
    else if(n >= 2){
        A3ToDest(A3, A2, A1, d, n - 1); // moves n - 1 from A3 to Dest
        move(A3, A2, n);
        move(A2, A1, n);
        A3ToDest(d, A1, A2, A3, n - 1); // moves n - 1 from Dest to A3
        move(A1, d, n);
        A3ToDest(A3, A2, A1, d, n - 1); // moves n - 1 from A3 to Dest
    }
} // moves all disks from 'A3' to 'Dest', O(3^n)

int main(){
    Hanoi game;
    int numDisks;
    cout << "Number of Disks: ";
    cin >> numDisks;
    game.StartToDest("Start", "Dest", "A1", "A2", "A3", numDisks);

    return 0;
}