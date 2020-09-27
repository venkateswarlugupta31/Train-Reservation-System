#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct pd
{
    int age;
    char gender[10];
    char name[18];
    char berth;
}pd[6];
struct price
{
    int train;
    int fare;
}*p[10];
void main()
{
    FILE *fp;
    char from[15],cancel[50],f[4],class[3],cla,t[4];int x,h=36;
    char option[5],to[15],train[][5][15] = {"delhi","jaipur","kota","ahmedabad","mumbai",
                                            "mumbai","ahmedabad","kota","jaipur","delhi",
                                            "chennai","tirupati","hyderabad","bhopal","delhi",
                                            "vijayawada","vizag","bhopal","delhi","jaipur",
                                            "jaipur","delhi","bhopal","vizag","vijayawada",
                                            "delhi","bhopal","hyderabad","tirupati","chennai",
                                            "mumbai","hyderabad","vizag","bubaneswar","howrah",
                                            "howrah","bubaneswar","vizag","hyderabad","mumbai",
                                            "roorkee","delhi","mumbai","bengaluru","chennai",
                                            "chennai","bengaluru","mumbai","delhi","roorkee",
                                            "chennai","coimbatore","bengaluru","panaji","mumbai",
                                            "mumbai","panaji","bengaluru","coimbatore","chennai",
                                            "kakinada","hyderabad","bhopal","gwalior","delhi",
                                            "delhi","gwalior","bhopal","hyderabad","kakinada",
                                            "hyderabad","pune","mumbai","surat","gandhinagar",
                                            "gandhinagar","surat","mumbai","pune","hyderabad",
                                            "amritsar","jaipur","mumbai","hyderabad","bengaluru",
                                            "bengaluru","hyderabad","mumbai","jaipur","amritsar",
                                            "kakinada","hyderabad","mumbai","delhi","mohali",
                                            "mumbai","pune","bengaluru","chennai","kanyakumari",
                                            "kanyakumari","chennai","bengaluru","pune","mumbai",
                                            "mohali","delhi","mumbai","hyderabad","kakinada",
                                            "kota","jaipur","delhi","howrah","tripura",
                                            "tripura","howrah","delhi","jaipur","kota",
                                            "mysore","bengaluru","tirupati","vijayawada","vizag",
                                            "vizag","vijayawada","tirupati","bengaluru","mysore",
                                            "patna","bubaneswar","hyderabad","bengaluru","trivandrum",
                                            "trivandrum","bengaluru","hyderabad","bubaneswar","patna",
                                            "chennai","vijayawada","vizag","bubaneswar","howrah",
                                            "howrah","bubaneswar","Vizag","vijayawada","chennai",
                                            "lucknow","bubaneswar","vizag","vijayawada","chennai",
                                            "chennai","vijayawada","vizag","bubaneswar","lucknow",
                                            "amaravathi","vizag","bubaneswar","jamshedpur","delhi",
                                            "delhi","jamshedpur","bubaneswar","vizag","amaravathi",
                                            "kanyakumari","kochi","panaji","mumbai","jaipur",
                                            "jaipur","mumbai","panaji","kochi","kanyakumari"};
    int opt,g,o,temp,y=0,i,z,temp1,j,total=0,a,b,k,m,n,count=0;
    printf("available routs\n");
    printf(" train no  train name        From         To                        via\n");        
    for(k=0;k<h;k++)
    {
        if(k<10)         printf("  20190%d  ",k);
        if(k>=10)       printf("  2019%d  ",k);
        for(i=0;i<5;i++)
        {
            for(j=0;j<3;j++)
            {
                f[j]=train[k][0][j];        
                t[j]=train[k][4][j];
            }
            f[j]='\0';t[j]='\0';
            if(i==0)
            printf(" %s-%s exp",f,t);
            if(i==0)
            printf("%12s %12s ",train[k][i],train[k][4]);
            if(i!=0&&i!=4)
            printf("%12s ",train[k][i]);
        }
        if(k==h-1)
            break;
        printf("\n");
    }
    printf("\nchoose ur trip\n");
    scanf("%s%s",from,to);
    for(k=0;k<h;k++)
    {
        for(i=0;i<5;i++)
        {
            a=strcmp(from,train[k][i]);
            if(a==0)
            {
                for(j=i;j<5;j++)
                {
                    b=strcmp(to,train[k][j]);
                    if(b==0)
                    {
                        count++;
                        p[y]=(struct price *)calloc(1,sizeof(struct price));
                        p[y]->train=k;
                        p[y]->fare=(j-i)*550;
                        y++;
                    }
                }
            }
        }
    }
    if(count!=0)
    {    
        printf("number of trains available %d\n",count);
        for(i=0;i<count;i++)
        {
            for(j=i+1;j<count;j++)
            {
                if(p[i]->fare>p[j]->fare)
                {
                    temp=p[i]->train;
                    temp1=p[i]->fare;
                    p[i]->train=p[j]->train;
                    p[i]->fare=p[j]->fare;
                    p[j]->train=temp;
                    p[j]->fare=temp1;
                }
            }
        }
        printf("                        fare   \n");
        printf(" train no     SL      3A      2A      1A    via  \n");
        for(g=0;g<count;g++)
        {
            k=p[g]->train;
            for(i=0;i<5;i++)
            {
                a=strcmp(from,train[k][i]);
                if(a==0)
                {
                    for(j=i;j<5;j++)
                    {
                        b=strcmp(to,train[k][j]);
                        if(b==0)
                        {
                            z=p[g]->fare;
                            if(k<10)
                                printf("  20190%d    %4d    %4d    %4d    %4d ",k,z,z+450,z+850,z+1650);
                            else
                                printf("  2019%d    %4d    %4d    %4d    %4d ",k,z,z+450,z+850,z+1650);
                            y=1;
                            for(o=1;o<j-i;o++)
                                printf(" %s ",train[k][i+y]); y++;
                            if(j-i==1) printf(" direct ");
                            printf("\n");
                        }
                    }
                }
            }
        }
        for(g=0;g<count;g++)
        {
            k=p[g]->train;
            for(i=0;i<5;i++)
            {
                a=strcmp(from,train[k][i]);
                if(a==0)
                {
                    for(j=i;j<5;j++)
                    {
                        b=strcmp(to,train[k][j]);
                        if(b==0)
                        {
                            z=1;
                            if(k<10)
                                printf("train no. 20190%d",k);
                            else
                                printf("train no. 2019%d",k);
                            printf("\ndo you want to book\n");
                            scanf("%s",option);
                            if(strcmp(option,"yes")==0)  opt=1;
                            if(strcmp(option,"no")==0)   opt=0;
                            switch(opt)
                            {
                                case 1:printf("no of passengers\n");
                                scanf("%d",&n);
                                printf("enter class\n");
                                scanf("%s",class);
                                printf("enter name age gender of %d passengers\n",n);                                     
                                for(m=0;m<n;m++)
                                {
                                    scanf("%s%d%s",pd[m].name,&pd[m].age,pd[m].gender);             
                                    if(pd[m].age<=12)
                                    {
                                        pd[m].berth='U';
                                        total=total+((j-i)*300);
                                    }
                                    if(pd[m].age>12&&pd[m].age<58)
                                    {
                                        if(strcmp(pd[m].gender,"male")==0)
                                            pd[m].berth='M';
                                        else
                                            pd[m].berth='L';
                                        total=total+((j-i)*550);
                                    }
                                    if(pd[m].age>=58)
                                    {
                                        pd[m].berth='L';
                                        total=total+((j-i)*400);
                                    }
                                }      
                                printf("                ticket details\n");
                                fp=fopen("history.txt","a");
                                fprintf(fp,"\n%s","                ticket details\n");
                                if(k>9)
                                {
                                    fprintf(fp,"%s%d","  train no.2019",k);
                                    printf("train no.2019%d",k);
                                }
                                else
                                {
                                    fprintf(fp,"%s%d","  train no.20190",k);
                                    printf("train no.20190%d",k);
                                }
                                fprintf(fp,"\t\t%s%d%d%d%d%d\n"," PNR No.IR",i+j+1,k+25,74,i*2,j*2);
                                printf(" PNR No.IR%d%d74%d%d \n",i+j+1,k+25,i*2,j*2);
                                printf("\tFrom:%s\t\tTo:%s\n",from,to);
                                fprintf(fp,"\t%s%s\t\t%s%s\n","From : ",from,"To : ",to);
                                if(strcmp(class,"3A")==0) {total=total+(n*450); cla='B';x=i+3;}
                                if(strcmp(class,"SL")==0) cla='S';x=i+(2*j);
                                if(strcmp(class,"2A")==0) {total=total+(n*850); cla='A';x=i+2;}
                                if(strcmp(class,"1A")==0) {total=total+(n*1650); cla='H';x=i+1;}
                                printf("     name   age   gender  berth  coach  seat no\n");
                                fprintf(fp,"%s","     name   age   gender  berth  coach  seat no\n");
                                for(m=0;m<n;m++)
                                {
                                    fprintf(fp,"%9s%6d%9s",pd[m].name,pd[m].age,pd[m].gender);
                                    fprintf(fp,"%6c    %c%d %6d\n",pd[m].berth,cla,x,k+m);
                                    printf("%9s%6d%9s",pd[m].name,pd[m].age,pd[m].gender);
                                    printf("%6c    %c%d %6d\n",pd[m].berth,cla,x,k+m);
                                }
                                printf("total amount %d",total);
                                fprintf(fp,"%s%d\n","total amount ",total);
                                printf("\ndo you want to cancel\n");
                                scanf("%s",cancel);
                                if(strcmp(cancel,"yes")==0)
                                {
                                    fprintf(fp,"%s\n","status : cancelled ");
                                    printf("status : cancelled \n");
                                }
                                if(strcmp(cancel,"no")==0)
                                {
                                    printf("status : booked\n");
                                    fprintf(fp,"%s\n","status : booked");
                                }
                                fclose(fp);
                                break;
                            } 
                        }
                        if(strcmp(cancel,"no")==0||strcmp(cancel,"yes")==0) 
                            break;
                    }
                }
                if(z==1&&k==count) break;
            }
        }
    }
    if(count==0) printf("NOT AVAILABLE"); 
}
