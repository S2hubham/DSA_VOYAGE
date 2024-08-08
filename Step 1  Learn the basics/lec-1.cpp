#include<bits/stdc++.h>
using namespace std;


//int main(){
    //step1
    // int x;
    // cout<<"Enter value\n";
    // cin>>x;
    // cout<<x;


    ////step 2
    // string str;
    // getline(cin, str);
    // cout<<str;


    ////step 3
    /*int age;
    cin>>age;
    if(age>=18){
        cout<<"Adult";
    }
    else{
        cout<<"Teen";
    }*/

    /*A school has following rules for grading system:
    a. Below 25 - F
    b. 25 to 44-E
    c. 45 to 49 - D
    d. 50 to 59 C
    e. 60 to 79-B
    f. 80 to 100 - A
    Ask user to enter marks and print the corresponding grade.*/
    /*int marks;
    cin>>marks;
    if(marks < 25){
        cout<<"F";
    }
    else if(marks <= 44){
        cout<<"E";
    }
    else if(marks <= 49){
        cout<<"D";
    }
    else if(marks <= 59){
        cout<<"C";
    }
    else if(marks <= 79){
        cout<<"B";
    }
    else if(marks <= 100){
        cout<<"A";
    }*/

    /*Take the age from the user and then decide accordingly
    1. If ag <18,
    print not eligible for job
    2. If age >18,
    print-> "eligble for job"
    3. If age>= 55 and age <= 57,
    print-> "eligible for job, but retirement soon."
    4. If age > 57
    print-> "retirement time"*/
    /*int age;
    cin>>age;
    if(age < 18){
        cout<<"print not eligible for job";
    }
    else if(age <= 57){
        cout<<"eligble for job";
        if(age >= 55){
            cout<<", but retirement soon.";
        }
        
    }
    else{
        cout<<"retirement time";
    }*/


    ////step 3
    //take a day number and print corresponding day
    /*int day;
    cin>>day;
    switch(day){
        case 1:
            cout<<"Monday";
            break;

        case 2:
            cout<<"Tuesday";
            break;

        case 3:
            cout<<"wednesday";
            break;

        case 4:
            cout<<"Thursday";
            break;

        case 5:
            cout<<"Friday";
            break;

        case 6:
            cout<<"Saturday";
            break;

        case 7:
            cout<<"Sunday";
            break;
        
        default:
            cout<<"Wrong Input";
            break;  
    }*/
    

    ////step 4
    /*int arr[5];
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4];
    cout<<arr[4]<<"\n";
    cout<<arr[3]<<"\n";
    arr[3] = 20;
    cout<<arr[3];*/

    //2d array = arr[row][col]

    //string as array
    /*string s = "Shubham";
    cout<<s[2];
    cout<<s.size();*/

//    return 0;
//}

//pass by value - give a copy of original value
/*void dosomethingval(int num){
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
}

//pass by reference - original value is sent
void dosomethingref(int &num){
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
    num += 5;
    cout<<num<<endl;
}

int main(){
    ////step 5
    int num = 10;
    dosomethingval(num);
    cout<<endl<<num; 



    return 0;
}*/



//patterns
//1.
void pat1(int n){
    for(int i= 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
//2.
void pat2(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout<<"* ";
        }
        cout<<endl;
    } 
}
//3.
void pat3(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    } 
}
//4.
void pat4(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<i<<" ";
        }
        cout<<endl;
    } 
}
//5.
void pat5(int n){
    for(int i = 0; i < n; i++){
        for(int j = n; j > i; j--){
            cout<<"* ";
        }
        cout<<endl;
    } 
}
//6.
void pat6(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i+1; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    } 
}
//7.
void pat7(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            cout<<"  ";
        }
        for(int j = 0; j < 2*i+1; j++){
            cout<<"* ";
        }
        for(int j = 0; j < n-i-1; j++){
            cout<<"  ";
        }
        cout<<endl;
    } 
}
//8
void pat8(int n){
    for(int i = n; i > 0; i--){
        for(int j = 0; j < n-i; j++){
            cout<<"  ";
        }
        for(int j = 0; j < 2*i-1; j++){
            cout<<"* ";
        }
        for(int j = 0; j < n-i; j++){
            cout<<"  ";
        }
        cout<<endl;
    }
}
//9
void pat9(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            cout<<"  ";
        }
        for(int j = 0; j < 2*i+1; j++){
            cout<<"* ";
        }
        for(int j = 0; j < n-i-1; j++){
            cout<<"  ";
        }
        cout<<endl;
    }
    for(int i = n; i > 0; i--){
        for(int j = 0; j < n-i; j++){
            cout<<"  ";
        }
        for(int j = 0; j < 2*i-1; j++){
            cout<<"* ";
        }
        for(int j = 0; j < n-i; j++){
            cout<<"  ";
        }
        cout<<endl;
    }
}
//10
void pat10(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//11
void pat11(int n){
    int start;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            start = 1;
        }
        else{
            start = 0;
        }
        for(int j = 0; j <= i; j++){
            cout<<start<<" ";
            start = 1 - start;
        }
        cout<<endl;
    }
}
//12
void pat12(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<j<<" "; 
        }
        for(int j = 1; j <= 2*(n-i); j++){
           cout<<"  "; 
        }
        for(int j = i; j > 0; j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
//13
void pat13(int n){
    int num = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<num<<" ";
            num += 1;
        }
        cout<<endl;
    }
}
//14
void pat14(int n){
    for(int i = 0; i < n; i++){
        for(char ch = 'A'; ch <= 'A'+i; ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
//15
void pat15(int n){
    for(int i = 0; i < n; i++){
        for(char ch = 'A'; ch < 'A'+n-i; ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
//16
void pat16(int n){
    char ch;
    for(int i = 0; i < n; i++){
        for(char j = 'A'; j <= 'A'+i; j++){
            ch = 'A' + i;
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
//17
void pat17(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            cout<<"  ";
        }
        char ch = 'A';
        int breakpoints = (2*i + 1) / 2;
        for(int j = 1; j <= 2*i+1; j++){
            cout<<ch<<" ";
            if(j <= breakpoints){
                ch++;
            }
            else{
                ch--;
            }
        }
        for(int j = 0; j < n-i-1; j++){
            cout<<"  ";
        }
        cout<<endl;
    }
}
//18
void pat18(int n){
    for(int i = 0; i < n; i++){
        for(char j = 'E' - i; j <= 'E'; j++){
            cout<<j;
        }
        cout<<endl;
    }
}
void pat18n(int n){
    for(int i = 1; i <= n; i++){
        for(char j = 'A'+n-1; j >= 'A'+n-i; j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
//19
void pat19(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (n - i); j++){
            cout<<"* ";
        }
        for(int j = 0; j < 2*i; j++){
            cout<<"  ";
        }
        for(int j = 0; j < (n - i); j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout<<"* ";
        }
        for(int j = 0; j < 2*(n - i -1); j++){
            cout<<"  ";
        }
        for(int j = 0; j <= i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
//20 
void pat20(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<"* ";
        }
        for(int j = 1; j <= 2*(n-i); j++){
            cout<<"  ";
        }
        for(int j = 1; j <= i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i; j++){
            cout<<"* ";
        }
        for(int j = 1; j <= 2*i; j++){
            cout<<"  ";
        }
        for(int j = 1; j <= n-i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
//21
void pat21(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 || i == n || j == 1 || j == n){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
//22 rows:i, clos:j
void pat22(int n){  
    for(int i = 0; i < 2*n - 1; i++){
        for(int j = 0; j < 2*n - 1; j++){
            int top = i;
            int bottom = (2*n - 2) - i;
            int left = j;
            int right = (2*n - 2) - j;
            cout<<(4 - min(min(top, bottom), min(left, right)))<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int x;
    cin>>x;
    pat22(x);
}



//clt+shift+b    to run the code
//shift+alt+f    to format code 
//window+shift+s to take ss
//clt+shift+t    to select text 