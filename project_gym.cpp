#include <iostream>
#include <conio.h>
using namespace std;

struct Member{
 int id;
 float height;
 float weight;
 bool exist;
};


int total=-1;
struct Member mx[5000];

// the below function is to display menu options

int menu(){
 int option;
 system("cls");
 cout<<"******* Main Menu ******"<<endl;
 cout<<"1. Add Member"<<endl;
 cout<<"2. Remove Member"<<endl;
 cout<<"3. Update Member"<<endl;
 cout<<"4. Max Height & Weight"<<endl;
 cout<<"5. Min Height and Weight"<<endl;
 cout<<"6. Average Height and Weight"<<endl;
 cout<<"7. BMI Classification"<<endl;
 cout<<"8. Display All"<<endl;
 cout<<"0. Exit"<<endl;
 cout<<"   Enter Your option(1-8):";
 cin>>option;
 return(option);

}

// this function is to searching a member.

int searchMember(int y){
 int i;
 int flag=-1;
 for(i=0;i<=total;i++)
    if(mx[i].id==y)
      flag=i;
 return(flag);
}

// this function is to add a member.

void addMember(){
 int x;
 cout<<"Inside addMember()"<<endl;
 total++;
 cout<<"Enter Member ID:";
 cin>>x;
 if(searchMember(x)==-1){
   mx[total].id=x;
   cout<<"Enter Height:";
   cin>>mx[total].height;
   cout<<"Enter Weight:";
   cin>>mx[total].weight;
   mx[total].exist=true;
   cout<<"Add Member Successful"<<endl;
 }
 else{
    cout<<"Sorry Member ID already exists...try again"<<endl;
    total--;
  }
}

// this function is to remove a member.

void removeMember(){
 int x,tid;
 cout<<"Enter Member ID:";
 cin>>x;
 tid=searchMember(x);
 if(tid==-1)
    cout<<"Sorry Member NOT exists...."<<endl;
 else{
    mx[tid].exist=false;
    cout<<"Remove Member Successful"<<endl;
 }
}

// this function is to update a members information

void updateMember(){
 int x;
 int tid;
 cout<<"Enter Member ID:";
 cin>>x;
 tid=searchMember(x);
 if(tid!=-1){
   cout<<"Old Height:"<<mx[tid].height;
   cout<<"\nEnter new height:";
   cin>>mx[tid].height;
   cout<<"Old Weight:"<<mx[tid].weight;
   cout<<"\nEnter new weight:";
   cin>>mx[tid].weight;

   cout<<"Update Member Successful"<<endl;
 }
 else
    cout<<"Sorry Member ID NOT exists...try again"<<endl;

}

// this function is to calculate the maximum height and weight.

void maxHeightWeight(){
 int i;
 float maxh=0, maxw=0;
 for(i=0;i<total; i++){
  if(maxh<mx[i].height){
  maxh = mx[i].height;
 }
 if(maxw<mx[i].weight)
 maxw = mx[i].weight;
 }

 cout<<"maximum height is "<< maxh<<endl;
 cout<<"maximum weight is "<< maxw<<endl;

}

// this function is to calculate the minimum height and weight.

void minHeightWeight(){
 int i;
 float minh=1000, minw=1000;
 for(i=0; i<total; i++){
  if(minh>mx[i].height){
    minh=mx[i].height;
  }
  if(minw>mx[i].weight){
    minw=mx[i].weight;
  }
 }
 cout<<"minimum height is "<<minh<<endl;
 cout<<"minimum weight is "<<minw<<endl; 
}

//  this code is to calculate the average Height and Weight.

void avgHeightWeight(){
  float sum = 0, b = 0 ;
 float avgheight, avgweight;
 int i;
 for( i=0; i<total; i++){
  sum = sum + mx[i].height;
  b = b + mx[i].weight;
 }
 avgheight = (float)sum/i;
 avgweight = (float)b/i;
 cout<<"avg height is "<<avgheight<<endl;
 cout<<"avg weight is "<<avgweight<<endl;
}

// this function is for classification of BMI

void bmi(){
    int  idt, i=0;
    float bmi;
    cout<<"Enter your id : ";
    cin>>idt;
    for(;i<=total; i++){
        if(idt==mx[i].id){
            bmi = mx[i].weight/(mx[i].height*mx[i].height);
            cout<<"BMI is "<<bmi<<endl;
            break;
        }
    }
    

    //  cout<<"BMI is "<<bmi<<endl;

    if (bmi < 16)
        cout<< "Severe Thinness"<<endl;
    else if (bmi < 17)
        cout<< "Moderate Thinness"<<endl;
    else if (bmi < 18.5)
        cout<< "Mild Thinness"<<endl;
    else if (bmi < 25)
        cout<< "Normal"<<endl;
    else if (bmi < 30)
        cout<< "Overweight"<<endl;
    else if (bmi < 35)
        cout<< "Obese Class I"<<endl;
    else if (bmi < 40)
        cout<< "Obese Class II"<<endl;
    else
        cout<< "Obese Class III"<<endl;

}

// This function to display the all data

void displayAll(){
 int i,y=0;
 cout<<"----------------"<<endl;
 cout<<"ID Height Weight"<<endl;
 for(i=0;i<=total;i++)
 if(mx[i].exist){
    cout<<mx[i].id<<" "<<mx[i].height<<" "<<mx[i].weight<<endl;
    y++;
 }
 cout<<"Total Members:"<<y<<endl;
 cout<<"----------------"<<endl;
}

int main()
{
  int op;
  for(;;){
   op=menu();
   //cout<<"In main() option="<<op<<endl;

   if(op==0){
    cout<<"End of Program run....";
    break;
   }
   switch(op){
     case 1:addMember();break;
     case 2:removeMember();break;
     case 3:updateMember();break;
     case 4:maxHeightWeight();break;
     case 5:minHeightWeight();break;
     case 6:avgHeightWeight();break;
     case 7:bmi();break;
     case 8:displayAll();break;
   }
   cout<<"Press enter to main menu....";
   getch();
  }
}
