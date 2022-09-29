#include <stdio.h>
#include <string.h>
int stu,*x,temp=0;
struct student{
    char fname[100];
    char lname[100];
    int roll;
    float cgpa;
    char course[100];
};
void add(struct student *s,int *k);
void roll(struct student *s,int);
void delete(struct student *s1,int *k,int);
void list(struct student *s,int);
void count(struct student *s,int *k);
void update(struct student *s,int *k);
void registered(struct student *s1, int k);
void name(struct student *s,int *k);
int k=0;
FILE *fp;
int main()
{
    int p;
     struct student s[stu];
    char f='y';
    while(f=='y'|| f=='Y')
    {
    printf("1.Add student details\n2.Find student by given roll number\n3.Find the student by given first name\n4.Find the student registered in a course\n5.Count a student\n6.Delete a student\n7.Update student details\n8.List top 10 students\n");
    printf("Enter choice: ");
    scanf(" %d",&p);
    if(p==1)
    {
        add(&s,&k);
    }
    if(p==2)
    {
        roll(&s,k);
    }
     if(p==3)
    {
        name(&s,k);
    }
            
    if(p==4)
    {
        registered(&s,k);
    }
    if(p==5)
    {
        count(&s,&k);
    }
    if(p==6)
    {
          delete(&s,&k,k);
    }
    if(p==7)
    {
        update(&s,&k);
    }
    if(p==8)
    {
        list(&s,k);
    }
    printf("\ndo you want to continue y/n");
    scanf(" %c",&f);
    printf("\n");
    }
    return 0;
}
void add(struct student *s,int *k){
   
    int ch=0,r;
    printf("enter the number of students: ");
    scanf(" %d",&stu);
for(int i=*k;i<*k+stu;i++){
    printf("enter the first name of the student %d: ",i+1);
    scanf(" %s",s[i].fname);
    printf("enter the last name of the student %d: ",i+1);
    scanf(" %s",s[i].lname);
    printf("enter the roll number of the student%d: ",i+1);
    scanf(" %d",&s[i].roll);
    r=s[i].roll;
     int ch=1;
   for(int j=0;j<i;j++)
     {
        if(s[j].roll==r)
        {
          ch=0;
        }
    } 
     while(ch==0)
     {
         printf("enter a unique roll no: ");
         scanf(" %d",&s[i].roll);
         r=s[i].roll;
          ch=1;
   for(int j=0;j<i;j++)
     {
        if(s[j].roll==r)
        {
          ch=0;
        }
    } 
     }
    printf("enter the cgpa of the student%d: ",i+1);
    scanf(" %f",&s[i].cgpa);
    printf("enter the course registered by the student%d: ",i+1);
    scanf(" %s",s[i].course);
    
    }
    *k+=stu;
    fp=fopen("student.dat","w+");
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
}
void roll(struct student *s,int k){
    int r,t=0;
    printf("enter the roll number: ");
    scanf(" %d",&r);
    fp=fopen("student.dat","r");
    fread(&s,sizeof(s),1,fp);
    for(int i=0;i<k;i++){
        if(r==s[i].roll){
            printf("first name:%s\nlast name:%s\nroll number:%d\ncgpa:%.2f\ncourse:%s",s[i].fname,s[i].lname,s[i].roll,s[i].cgpa,s[i].course);
            t++;
            break;
        }
    }
    if(t==0)
    printf("roll number not found!");
    fclose(fp);
}

void name(struct student *s,int *k)
{
 char a[50];
printf("Enter the First Name of the student: ");
    scanf("%s", a);
int c = 0;
fp=fopen("student.dat","r");
fread(&s,sizeof(s),1,fp);
  for (int j = 0; j <k; j++) {
 if (!strcmp(s[j].fname, a)) {
  printf("The Students Details are:\n");
  printf("The First name is %s\n",s[j].fname);
  printf("The Last name is %s\n",s[j].lname);
  printf("The Roll Number is %d\n ",s[j].roll);
  printf("The CGPA is %.2f\n",s[j].cgpa);
  printf("The course registered is %s",s[j].course);
   c++;
   break;
     }
  }
if(c==0)
    printf("The First Name not Found");
fclose(fp);
}

void registered(struct student *s1, int k)
{ char crs[50];
    printf("Enter the course: ");
    scanf("%s", crs);
    fp=fopen("student.dat","r");
    fread(&s1,sizeof(s1),1,fp);
printf("The students registered are:");
    int c = 0;
  for (int j = 0; j<k; j++) {
       for (int d = 0; d < k; d++) {
            if (!strcmp(s1[j].course,crs)) {
  printf("\n%s", s1[j].fname);
  c++;
  break;
    }
  }
}
if(c==0)
 printf("Sorry!! The given course not Found");
fclose(fp);
}

void count(struct student *s,int *k)
{
    int c=0;
    fp=fopen("student.dat","r");
    fread(&s,sizeof(s),1,fp);
    for(int i=0;i<*k;i++)
    {
        if(s[i].roll!=0)
            c++;
    }
    printf("\nNumber of students is: %d",c);
    fclose(fp);
}

void delete(struct student *s1,int *k,int m)
{
    int r,ch=0;
printf("enter the roll no of the student that has to be deleted: ");
scanf(" %d",&r);
fp=fopen("student.dat","r");
fread(&s1,sizeof(s1),1,fp);
    for(int i=0;i<m&&ch==0;i++)
    {
      if(s1[i].roll==r)
      {
         
         if(i==m-1)
         {
             ch=1;
         }
         else
         {
         for(int j=i;j>=i&&j<=m-1;j++)
         {
            s1[j].cgpa=s1[j+1].cgpa;
            s1[j].roll=s1[j+1].roll;
           strcpy(s1[j].fname,s1[j+1].fname);
           strcpy(s1[j].lname,s1[j+1].lname);
           strcpy(s1[j].course,s1[j+1].course);
           ch=1;
           continue;
         } 
         }
         if(ch==1)
         {
            *k-=1;
         }
         }
       }
       if(ch==0)
       printf("there is no student with that roll no");
       else
       printf("successfully the details of the student with the eneterd roll no is deleted!!");
       fclose(fp);
}

void update(struct student *s,int *k)
{
    char upd[20];
    int r,j=0;
    printf("Enter roll.no of the student:");
    scanf("%d",&r);
    fp=fopen("student.dat","r");
    fread(&s,sizeof(s),1,fp);
    for(int i=0;i<*k;i++)
    {
        if(s[i].roll==r)
        {
            printf("Enter field to be updated(fname/lname/roll.no/cgpa/course): ");
            scanf("%s",&upd);
            if(strcmp(upd,"fname")==0)
            {
                printf("Enter new first name:");
                scanf("%s",s[i].fname);
                printf("Updation complete");
            }  
            else if(strcmp(upd,"lname")==0)
            {
                printf("Enter new last name: ");
                scanf("%s",s[i].lname);
                printf("Updation complete");
            }
            else if(strcmp(upd,"roll.no")==0)
            {
                printf("Enter new roll.no: ");
                scanf("%d",&s[i].roll);
                printf("Updation complete");
            }  
            else if(strcmp(upd,"cgpa")==0)
            {
                printf("Enter new CGPA: ");
                scanf("%f",&s[i].cgpa);
                printf("Updation complete");
            }  
            else if(strcmp(upd,"course")==0)
            {
                printf("Enter new course: ");
                scanf("%s",s[i].course);
                printf("Updation complete");
            }  
            else
                printf("No such field available!");
            break;
        }
        else
            j++;
    }
    if(j!=0)
        printf("Roll.no not found");
    fclose(fp);
}

void list(struct student *s9,int m)
{
   int max,tmp1,cg[m];
   char fna[100][m],lna[100][m],tmp2[100],tmp3[100];
   fp=fopen("student.dat","r");
    fread(&s9,sizeof(s9),1,fp);
   for(int i=0;i<m;i++)
   {
        cg[i]=s9[i].cgpa;
       strcpy(fna[i],s9[i].fname);
       strcpy(lna[i],s9[i].lname);
   }
    for(int i=0;i<m;i++)
    {
       max=cg[i];
        for(int j=i+1;j<m;j++)
        {
           if(max<cg[j])
           {
               max=cg[j];
               tmp1=cg[j];
               cg[j]=cg[i];
               cg[i]=tmp1;
               strcpy(tmp2,fna[j])  ;                           
               strcpy(fna[j],fna[i]);
               strcpy(fna[i],tmp2);
              strcpy(tmp3,lna[j]) ;                            
               strcpy(lna[j],lna[i]);
               strcpy(lna[i],tmp3);
            }
        }
    }
    if(m>=10)
    {
         printf("\nprinting top 10 students based on their CGPA:");
for(int i=0;i<10;i++)
    {
        printf("\ncgpa of student %d: %d",i+1,cg[i]);
        printf("\nname of student %d: %s%s",i+1,fna[i],lna[i]);
    }
    }
    else if(m>0&&m<10)
     {
          printf("\nprinting top %d students based on their CGPA:",m);
         for(int i=0;i<m;i++)
         {
              printf("\ncgpa of student %d: %d",i+1,cg[i]);
              printf("\nname of student %d: %s %s",i+1,fna[i],lna[i]);
         }
         }
    else
    printf("\nthere are no students details to print!!! ");    
    fclose(fp);
}