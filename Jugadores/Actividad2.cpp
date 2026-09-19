
#include <iostream>
using namespace std;
int usoapp(int num){
if(num<18){
return 1;
}else if(num>=18&&num<=30){
return 2;
}else if(num>=31&&num<=55){
return 3;
}else{
return 4;
}}
int main(){
int app,edad;
cout<<"Inserte su edad: ";
do{
cin>>edad;
}while(edad<0);
app=usoapp(edad);
switch(app){
case 1:
cout<<"Usted usa probablemente usa TIKTOK"<<endl;
break;
case 2:
cout<<"Usted usa probablemente usa INSTAGRAM"<<endl;
break;
case 3:
cout<<"Usted usa probablemente usa FACEBOOK"<<endl;
break;
case 4:
cout<<"Usted usa probablemente usa WHATSAPP"<<endl;
break;
default:
cout<<"Vuelve a intentarlo"<<endl;
}
return 0;
}