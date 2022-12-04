#include<stdio.h>
#include<string.h>
#define N strlen(g)
int j,e,a;
char t[28],cs[28],g[]="10001000000100001";
void xor(){
    for(j=1;j<N;j++){
        cs[j]=((cs[j]==g[j])?'0':'1');
    }
    
}


void crc(){
    for(e=0;e<N;e++){
        cs[e]=t[e];
    }
    
   do{
    if(cs[0]=='1')
    xor();
    for(j=0;j<N-1;j++){
    cs[j]=cs[j+1];        
    }
    cs[j]=t[e++];
    
   }while(e<=N+a-1);
    
   
}


int main()
{
    printf("enter the data");
    scanf("%s",t);
    printf("\n----------------------------------------"); 
    
printf("\nGeneratng polynomial : %s",g);
int l=strlen(t);
a=l;
for(int i=l;i<l+N-1;i++){
    t[i]='0';
}
 printf("\nModified data is : %s",t);
printf("\n----------------------------------------");
     crc();



printf("\n CRC checksum is : %s",cs);
for (e=a;e<N+a-1;e++)
t[e]=cs[e-a];
printf("\n transmission data is : %s",t);
printf("\n----------------------------------------");

printf("\n  Test error detection 0(yes) 1(no)? :");
scanf("%d",&e);
if(e==0){
do{
printf("\n enter position of error ");
scanf("%d",&e);
}while(e==0 || e>a+N-1);


t[e-1]=(t[e-1]=='0')?'1':'0';
printf("\n----------------------------------------");
printf("\nErroneous data : %s\n",t);
}

crc();
for( e=0;e<N-1 && cs[e]!=1;e++);
if(cs[e-1]){
    printf("\n CRC checksum is : %s",cs);
    printf("\n error detected");

}
else{printf("\n CRC checksum is : %s",cs);
printf("\n no errors ");

}

return 0;
}
