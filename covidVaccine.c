//Brianna Hill bhill28@student.gsu.edu 

#include <stdio.h>
#include <string.h>
#include <time.h>

//name a structure to obtain user related data
struct user
{  
  char fne[30];
  char lne[30];
  
  int dd,mm,yy;
  char sex[6];
  
  int pdd,pmm,pyy;
  int dosenumber;
  
  char vaccinetype[30];
  char zip[6];
};

// get user age between two dates
int getUserage(int pdate, int pmonth, int pyear, int bdate, int bmonth, int byear) {
   int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   if (bdate > pdate) {
      pdate = pdate + month[bmonth - 1];
      pmonth = pmonth - 1;
   }
   if (bmonth > pmonth) {
      pyear = pyear - 1;
      pmonth = pmonth + 12;
   }
   int final_date = pdate - bdate;
   int final_month = pmonth - bmonth;
   int final_year = pyear - byear;

   return final_year;
}
int main(void) {
  struct user u1[10];
  int choice;
  char id[8];
  char age[2];
  int i;

for(i = 0;i<10;i++){
    printf("Enter detail for %d person : \n",i+1); //print message 

  //prompt the user to enter first name
printf("Enter First Name : ");
    scanf("%s", u1[i].fne);

//prompt the user to enter last name
printf("Enter Last Name : ");
    scanf("%s", u1[i].lne);

    //prompt the user to enter birthdate
    printf("Enter Birth Date(mm/dd/yyyy) : ");
    scanf("%d/%d/%d",&u1[i].dd,&u1[i].mm,&u1[i].yy);

    //prompt the user to choose sex 
   printf("Choose sex : \n");
    printf("\t1. Male\n");
    printf("\t2. Female\n\tEnter choice : ");
    scanf("%d", &choice);

    //check choice is valid or not
    if(choice == 1)
      strcpy(u1[i].sex, "Male");
    else if(choice == 2)
      strcpy(u1[i].sex, "Female");
    else{
      printf("Please choose valid sex.\n");
      return 1;
    }


    //prompt the user to enter dose number 
     printf("Enter Dose Number : ");
    scanf("%d", &u1[i].dosenumber);
    if(!(u1[i].dosenumber == 1 || u1[i].dosenumber == 2)){
      //print message if entered input is not valid
        printf("Please enter valid dose number.\n");
      return 1;
    }

    //if second dose is chosen by user  then prompt the user for previous dose date
    if(u1[i].dosenumber == 2){
      printf("Enter Previous Dose Date(mm/dd/yyyy) : ");
      scanf("%d/%d/%d",&u1[i].dd,&u1[i].mm,&u1[i].yy);
    }

    //prompt the user to choose vaccine type -most common types
    printf("Choose type of vaccine : \n");
    printf("\t1. Pfizer\n");
    printf("\t2. Moderna\n");
    printf("\t3. Johnson&Johnson\n\tEnter choice : ");
    scanf("%d", &choice);

    //check that choosen type is valid or not
    if(choice == 1)
      strcpy(u1[i].vaccinetype, "Pfizer");
    else if(choice == 2)
strcpy(u1[i].vaccinetype, "Moderna");
    else if(choice == 3)
      strcpy(u1[i].vaccinetype, "Johnson&Johnson");
    else{
     //print message if entered input is invalid
         printf("Please choose valid type of vaccine.\n");
      return 1;
    }

    //prompt the user to enter zip 
    printf("Enter Zip : ");
    scanf("%s", u1[i].zip);

//to copy first letter of first name and last name
    id[0] = u1[i].fne[0];
    id[1] = u1[i].lne[0];
// to get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
//to calculate age by calling function getUserage()
    int ageTemp = getUserage( tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1900,u1[i].dd,u1[i].mm,u1[i].yy);

    //copy entered age
    id[2] = (char)(ageTemp/10+ '0');
    id[3] = (char)(ageTemp%10+ '0');
    //copy entered first letter of vaccinetype
    id[4] = u1[i].vaccinetype[0];
    //copy entered last 3 digit or zip
    id[5] = u1[i].zip[3];
    id[6] = u1[i].zip[4];
    id[7] = u1[i].zip[5];
	//display user  details
    printf("\nFirst Name : %s\n",u1[i].fne);
    printf("Last Name : %s\n",u1[i].lne);
    printf("Birthdate : %d/%d/%d\n",u1[i].mm,u1[i].dd,u1[i].yy);
    printf("Sex : %s\n",u1[i].sex);
    printf("Dose Number : %d\n",u1[i].dosenumber);
    if(u1[i].dosenumber == 2){
      printf("Previous Dose Date : %d/%d/%d\n",u1[i].pmm,u1[i].pdd,u1[i].pyy);
    }
    printf("Vaccine type : %s\n",u1[i].vaccinetype);
    printf("Zip : %s\n",u1[i].zip);

    printf("Code : %s\n\n",id);
  }

  return 0;
}
