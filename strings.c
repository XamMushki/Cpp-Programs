#include <stdio.h>
#include<string.h>

void main()
{
    int n;
    printf("enter string size: ");
    scanf("%d",&n);
    printf("%d",n);
    char name[n];
    // printf("%d",size_of(name));
    printf("Enter Name: ");
    // scanf("%s", name);
    // printf("Your name is %s\n", name);

    fgets(name, sizeof(name),stdin);
    puts(name);
    // int newSize=strlen(name);
    // printf("%d\n",newSize);
    // char trimmedName[newSize];
    // for (int i = 0; i < newSize-1; i++)
    // {
    //     printf("%c",name[i]);
    //     printf(".");
    //     trimmedName[i]=name[i];
    // }
    
    // printf("%s",name);
    // printf("%lu",sizeof(trimmedName));
    // printf("Trimmed name: %s",trimmedName);
    // // int l = strlen(name);
    printf(".");
}