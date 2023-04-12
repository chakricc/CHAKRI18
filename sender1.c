#include<stdio.h>
#include<string.h>
void reciever();
char frames[1024];
int main()
{
int n,len,i;
char buffer[256],length[10];
printf("How many frames you want to send: ");
bzero(buffer,256);
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter frame\n");
scanf("%s",buffer);
printf("String length of buffer is %d\n",strlen(buffer));
len=strlen(buffer);
len=len+1;
sprintf(length,"%d",len);
strcat(frames,length);
strcat(frames,buffer);
}
for(i=0;frames[i]!='\0';i++)
printf("%c",frames[i]);
reciever();
return 0;
}
void reciever()
{
int i=0,framelen,lpvar;
char leninchar;
printf("\n\nThis is the reciever\n");
printf("\nData recieved is %s",frames);
while(frames[i]!='\0')
{
leninchar=frames[i];
framelen=(int)leninchar-(int)'0';
printf("\nLength of this frame is %d\n",framelen);
printf("\nFrame ----->");
lpvar=i+framelen;
i=i+1;
while(i<lpvar)
{
printf("%c",frames[i++]);
}
printf("\n");
}
}
