/*sorting a list of names received from the keyboard, with options using callback functions.
1 :  sort with case sensitivity (strcmp)
2 : sort without case sensitivity (stricmp)
*/


//Function pointer 6th assignment

#include<stdio.h>
#include<string.h>

void mystrlwr(char str[]);
void sort_with_case_sen(int n, int m, char name[n][m]);
void sort_without_case_sen(int n, int m, char name[n][m]);
void callbackfun(int r, int c, void (*fp)(int, int, char [r][c]), char [r][c]);

int main()
{
        int r, c, i, j;
        printf("Enter no of rows(names): ");
        scanf("%d", &r);
        printf("Enter no of columns(string size): ");
        scanf("%d", &c);
        char name[r][c];
        void (*fp[2]) (int r, int c, char [r][c]) = {sort_with_case_sen, sort_without_case_sen};
        for(i=0;i<r;i++)
        {
                printf("Enter name as string %d: ", i);
                scanf(" %[^\n]s", name[i]);
        }
        int choice;
        printf("choose below choice\n1.  sort names with case senstivity\n2. sort names with out case sensitivity\n");
        printf("choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
                case 1: callbackfun(r, c, fp[0], name);break;
                case 2: callbackfun(r, c, fp[1], name);break;
        }
        printf("sorted names\n");
        for(i=0;i<r;i++)
                printf("%s\n", name[i]);
        return 0;
}

void callbackfun(int r, int c, void (*fp)(int, int, char [r][c]), char name[r][c])
{

        fp(r, c, name);
}

void sort_with_case_sen(int n, int m, char name[n][m])
{
        int i, j;
        char temp[m];
        for(i=0;i<n;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        if(strcmp(name[i], name[j])>0)
                                        strcpy(temp, name[i]); strcpy(name[i],name[j]); strcpy(name[j],temp);


                }
        }
}
void sort_without_case_sen(int n, int m, char name[n][m])
{
        int i, j;
        char temp1[m], temp2[m], temp[m];
        for(i=0;i<n;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        mystrlwr(strcpy(temp2, name[j]));
                        mystrlwr(strcpy(temp1, name[i]));
                        if(strcmp(temp1, temp2)>0)
                                        strcpy(temp, name[i]), strcpy(name[i],name[j]), strcpy(name[j],temp);
                }
        }
}

void mystrlwr(char str[])
{
        int i, len;
        for(i=0;str[i];i++)
                if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
}

