#include<stdio.h>
#include<string.h>
struct address
{
   int house_no;
   int road_no;
   char area[20];
   char city[20];
   int postal_code;
};
typedef struct address address;
struct student
{
    char name[100];
    int id;
    char dob[20];
    int pers_number;
    int mother_number;
    int father_number;
    float ssc_gpa;
    float hsc_gpa;
    char blood_type[5];
    address a;

};
typedef struct student student;
void write(student s[],int n)
{
    FILE *fp1;
    fp1=fopen("student.txt","w");
    fprintf(fp1,"%d\n",n);

    for(int i=1;i<=n;i++)
       {

           fprintf(fp1,"%s\n",s[i].name);
           fprintf(fp1,"%d\n",s[i].id);
           fprintf(fp1,"%s\n",s[i].dob);
           fprintf(fp1,"%d\n",s[i].pers_number);
           fprintf(fp1,"%d\n",s[i].mother_number);
           fprintf(fp1,"%d\n",s[i].father_number);
           fprintf(fp1,"%f\n",s[i].ssc_gpa);
           fprintf(fp1,"%f\n",s[i].hsc_gpa);
           fprintf(fp1,"%s\n",s[i].blood_type);
           fprintf(fp1,"%d\n",s[i].a.house_no);
           fprintf(fp1,"%d\n",s[i].a.road_no);
           fprintf(fp1,"%s\n",s[i].a.area);
           fprintf(fp1,"%s\n",s[i].a.city);
           fprintf(fp1,"%d\n",s[i].a.postal_code);
    }
    fclose(fp1);
}
void print(student s[],int n,int u)
{
    for(int i=u;i<=n;i++)
    {
        printf("%d.\n",i);
        printf("name: %s\n",s[i].name);
        printf("ID: %d\n",s[i].id);
        printf("Date of Birth: %s\n",s[i].dob);
        printf("personal number: %d\n",s[i].pers_number);
        printf("mother's number: %d\n",s[i].mother_number);
        printf("father's number: %d\n",s[i].father_number);
        printf("GPA of SSC: %f\n",s[i].ssc_gpa);
        printf("GPA of HSC: %f\n",s[i].hsc_gpa);
        printf("Blood type: %s\n",s[i].blood_type);
        printf("Address-- \n");
        printf("House no: %d\n",s[i].a.house_no);
        printf("Road no:%d\n",s[i].a.road_no);
        printf("Area: %s\n",s[i].a.area);
        printf("City: %s\n",s[i].a.city);
        printf("Postal Code: %d\n",s[i].a.postal_code);

    }

}
int  read(student s[])
{
    int x;
    FILE *fp1;
    fp1=fopen("student.txt","r");

    fscanf(fp1,"%d",&x);
    for(int i=1;i<=x;i++)
    {
        char v;
       fscanf(fp1,"%c",&v);
       fscanf(fp1,"%[^\n]\n",&s[i].name);
       fscanf(fp1,"%d\n",&s[i].id);

       fscanf(fp1,"%c",&v);
       fscanf(fp1,"%[^\n]\n",&s[i].dob);
       fscanf(fp1,"%d\n",&s[i].pers_number);
       fscanf(fp1,"%d\n",&s[i].mother_number);
       fscanf(fp1,"%d\n",&s[i].father_number);
       fscanf(fp1,"%f\n",&s[i].ssc_gpa);
       fscanf(fp1,"%f\n",&s[i].hsc_gpa);

       //fscanf(fp1,"%c",&v);
       fscanf(fp1,"%[^\n]\n",&s[i].blood_type);
       fscanf(fp1,"%d\n",&s[i].a.house_no);
       fscanf(fp1,"%d\n",&s[i].a.road_no);

       fscanf(fp1,"%c",&v);
       fscanf(fp1,"%[^\n]\n",&s[i].a.area);

       fscanf(fp1,"%c",&v);
       fscanf(fp1,"%s\n",&s[i].a.city);
       fscanf(fp1,"%d\n",&s[i].a.postal_code);
    }
    fclose(fp1);
    return x;

}
int main()
{
   while(1)
  {

   printf("1.Rewrite the whole data base\n2.Add a new individual\n3.exit\n4.View list\n5.View person of a specific roll number\n6.View people of a specific blood group\n");
   printf("ENTER THE INDEX OF YOUR ACTIVITY:   ");
   int index;
   scanf("%d",&index);
   if(index==1)
   {
       int n;
       printf("Enter number of contacts you want to add: ");
       scanf("%d",&n);
       getchar();
       student s[100];
       for(int i=1;i<=n;i++)
       {
           printf("Enter name:");
           scanf("%[^\n]",&s[i].name);
           printf("Enter id:");
           scanf("%d",&s[i].id);
           getchar();
           printf("Enter date of birth:");
           scanf("%[^\n]",&s[i].dob);
           printf("Enter  personal contact number:");
           scanf("%d",&s[i].pers_number);
           printf("Enter mother's number:");
           scanf("%d",&s[i].mother_number);
           printf("Enter father's number:");
           scanf("%d",&s[i].father_number);
           printf("Enter gpa of ssc:");
           scanf("%f",&s[i].ssc_gpa);
           printf("Enter gpa of hsc:");
           scanf("%f",&s[i].hsc_gpa);
           getchar();
           printf("Enter blood type:");
           scanf("%[^\n]",&s[i].blood_type);
           printf("Enter house no:");
           scanf("%d",&s[i].a.house_no);
           getchar();
           printf("Enter road number:");
           scanf("%d",&s[i].a.road_no);
           getchar();
           printf("Enter area:");
           scanf("%[^\n]",&s[i].a.area);
           getchar();
           printf("Enter city name:");
           scanf("%[^\n]",&s[i].a.city);
           printf("Enter postal code:");
           scanf("%d",&s[i].a.postal_code);
           getchar();

    }
       write(s,n);
       print(s,n,1);

   }
   if(index==2)
   {
       printf("Enter the number of individuals you want to add : \n");
       int no;
       scanf("%d",&no);

       student s[100];
       int x=read(s);
       int n=x+no;
       for(int i=x+1;i<=n;i++)
       {
           getchar();
           printf("Enter name:");
           scanf("%[^\n]",&s[i].name);
           printf("Enter id:");
           scanf("%d",&s[i].id);
           getchar();
           printf("Enter date of birth:");
           scanf("%[^\n]",&s[i].dob);
           printf("Enter  personal contact number:");
           scanf("%d",&s[i].pers_number);
           printf("Enter mother's number:");
           scanf("%d",&s[i].mother_number);
           printf("Enter father's number:");
           scanf("%d",&s[i].father_number);
           printf("Enter gpa of ssc:");
           scanf("%f",&s[i].ssc_gpa);
           printf("Enter gpa of hsc:");
           scanf("%f",&s[i].hsc_gpa);
           getchar();
           printf("Enter blood type:");
           scanf("%[^\n]",&s[i].blood_type);
           printf("Enter house no:");
           scanf("%d",&s[i].a.house_no);
           getchar();
           printf("Enter road number:");
           scanf("%d",&s[i].a.road_no);
           getchar();
           printf("Enter area:");
           scanf("%[^\n]",&s[i].a.area);
           getchar();
           printf("Enter city name:");
           scanf("%[^\n]",&s[i].a.city);
           printf("Enter postal code:");
           scanf("%d",&s[i].a.postal_code);

       }
       write(s,n);
       print(s,n,1);

   }
   if (index==3)
   {
       printf("Exiting............\n");
       break;
   }
   if(index==4)
   {
       student s[100];
       int x=read(s);
       print(s,x,1);
   }
   if(index==5)
   {
       student s[100];
       int x=read(s);
       int idd;
       int flag=0;
       printf("Enter the id of the person you are looking for: ");
       scanf("%d",&idd);
       for(int i=1;i<=x;i++)
       {
           if(s[i].id==idd)
           {

               print(s,i,i);
               flag++;
               break;
           }
       }
       if(flag==0)
       {
           printf("Person not found");
       }
   }
   if(index==6)
   {
     student s[100];
     int x=read(s);
     printf("Enter the blood group you want to find: \n->A+\n->B+\n->O+\n->AB+\n->A-\n->B-\n->O-\n->AB-\n");
     char bg[10];
     int flag=0;
     scanf("%s",&bg);
     for(int i=1;i<=x;i++)
     {
         if(strcmp(s[i].blood_type,bg)==0)
         {
             print(s,i,i);
             flag++;
         }
     }
     if(flag==0)
       {
           printf("Person not found");
       }
   }
   printf("\n\n\n\n");
  }
  printf("Programme terminated");


}

