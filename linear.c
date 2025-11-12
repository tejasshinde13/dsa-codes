#include <stdio.h>
#include <math.h>
//function of linear search
int linear_search(int arr1[],int n,int key1)
{
    for(int i=0;i<n;i++)
    {
        if(arr1[i]==key1)
        {
            return i;
        }

    }
    return -1;
}
// function of binary search
int binary_search(int arr2[],int start,int end,int key2)
{
    while(start<=end)
    {
        int mid =floor((start+end)/2);
        
        if(arr2[mid]==key2)
          return mid;
        else if(arr2[mid]<key2)
             start = mid+1;
        else
            end = mid-1;
    }
    return -1;
      
}

int main()
{
    
    int arr1[15],arr2[15],start,end,key1,key2,ch,result1,result2 ;
    //enter the number of element for linear search
    int n1 ;
    printf("enter the number of element:\n");
    scanf("%d",&n1);
    //enter the roll number in array
    printf("enter the number:\n");
    for(int i=0;i<n1;i++)
    {
        scanf("%d", &arr1[i] );
    }
    //enter search element
    printf("enter the search element for linear search:");
    scanf("%d",&key1);

    //binaryu search
    //enter the number of element for binary search
    int n2 ;
    printf("enter the number of element:\n");
    scanf("%d",&n2);
    //enter the roll number in array
    printf("enter the number in sorted way:\n");
    for(int i=0;i<n2;i++)
    {
        scanf("%d", &arr2[i] );
    }
    //enter search element
    printf("enter the search element for binary search:");
    scanf("%d",&key2);

    do
    {
      printf("***************** MENU **************");
      printf("\n1.linear search.");
      printf("\n2.binary search.");
      printf("\n3.exist:");
      printf("\nchoose:");
      scanf("%d",&ch);

      switch(ch)
      {
        case 1:
            result1=linear_search(arr1,n1,key1);
            if(result1!=-1)
            {
              printf("\nthe %d element is found at %d index\n.",key1,result1);
            }
            else{
                printf("\nthe given element is not found\n.");
            }
            break;
        case 2:
            result2=binary_search(arr2,0,n2-1,key2);
            if(result2!=-1)
            {
                printf("\n the %d element is found at %d index.\n",key2,result2);
            }
            else{
                printf("\n element is not found.\n");
            }
            break;
        case 3:
            printf("\n_________program is exist__________\n");
            break;
        default :
            printf("\nthis choose is invalid.");
            break;
      }
    }
    while(ch!=3);
    return 0;
}