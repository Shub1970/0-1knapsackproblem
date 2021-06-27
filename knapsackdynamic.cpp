/* knapsack dynamic problem using recurssion */

/*#include<iostream>
using namespace std;
int max(int a, int b){return (a>b)?a:b;}
int knapsack(int profit[],int weight[],int capacity,int m){
    if (m==0||capacity==0)
        return 0;
    if(weight[m-1]>capacity)
        return knapsack(profit,weight,capacity,m-1);
    else
        return max(
            profit[m-1]+knapsack(profit,weight,capacity-weight[m-1],m-1),
            knapsack(profit,weight,capacity,m-1));
        


    }

int main(){
    int profit[]={60,100,120};
    int weight[]={10,20,30};
    int capacity=50;
    int m=sizeof(profit)/sizeof(profit[0]);
    cout<< knapsack(profit,weight,capacity,m);
    return 0;
}*/  

/* apply dynamic algo. in knapsack problem */
#include<iostream>
using namespace std;
int knapsack(int profit[],int weight[],int capacity, int size){
    int knaptable[size+1][capacity+1];
    int i,w;
    for(i=0;i<=size;i++){
        for(w=0;w<=capacity;w++){
            if(w==0||i==0)
            knaptable[i][w]=0;
            else if (weight[i-1]<=w)
            knaptable[i][w]=max(profit[i-1]+knaptable[i-1][w-weight[i-1]],knaptable[i-1][w]);
            else
                knaptable[i][w]=knaptable[i-1][w];
        }

    }
    return knaptable[size][capacity];

}
int main(){
    int profit[]={60,100,120};
    int weight[]={10,20,30};
    int size=sizeof(profit)/sizeof(profit[0]);
    int capacity=50;
    cout<<knapsack(profit,weight,capacity,size);
    return 0;
}

/* output is 220*/