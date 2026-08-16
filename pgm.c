#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    int id;
    char name[50];
    char artist[50];
    struct Song *next;
    struct Song *prev;
};

struct Song *head = NULL;
struct Song *current = NULL;

struct Song* createNode()
{
    struct Song *newNode = malloc(sizeof *newNode);
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter Song ID: ");
    scanf("%d",&newNode->id);

    printf("Enter Song Name: ");
    scanf(" %[^\n]",newNode->name);

    printf("Enter Artist Name: ");
    scanf(" %[^\n]",newNode->artist);

    newNode->next = newNode;
    newNode->prev = newNode;

    return newNode;
}

void addBeginning()
{
    struct Song *newNode = createNode();

    if(head==NULL)
    {
        head=newNode;
        current=head;
    }
    else
    {
        struct Song *last=head->prev;

        newNode->next=head;
        newNode->prev=last;

        last->next=newNode;
        head->prev=newNode;

        head=newNode;
    }

    printf("Song added at beginning.\n");
}

void addEnd()
{
    struct Song *newNode=createNode();

    if(head==NULL)
    {
        head=newNode;
        current=head;
    }
    else
    {
        struct Song *last=head->prev;

        last->next=newNode;
        newNode->prev=last;

        newNode->next=head;
        head->prev=newNode;
    }

    printf("Song added at end.\n");
}

void deleteSong()
{
    if(head==NULL)
    {
        printf("Playlist Empty.\n");
        return;
    }

    int id;
    printf("Enter Song ID to delete: ");
    scanf("%d",&id);

    struct Song *temp=head;

    do
    {
        if(temp->id==id)
        {
            if(temp->next==temp)
            {
                head=NULL;
                current=NULL;
            }
            else
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;

                if(temp==head)
                    head=temp->next;

                if(temp==current)
                    current=temp->next;
            }

            free(temp);
            printf("Song deleted.\n");
            return;
        }

        temp=temp->next;

    }while(temp!=head);

    printf("Song not found.\n");
}

void searchSong()
{
    if(head==NULL)
    {
        printf("Playlist Empty.\n");
        return;
    }

    int id;
    printf("Enter Song ID: ");
    scanf("%d",&id);

    struct Song *temp=head;

    do
    {
        if(temp->id==id)
        {
            printf("\nSong Found\n");
            printf("ID : %d\n",temp->id);
            printf("Name : %s\n",temp->name);
            printf("Artist : %s\n",temp->artist);
            return;
        }

        temp=temp->next;

    }while(temp!=head);

    printf("Song not found.\n");
}

void displayForward()
{
    if(head==NULL)
    {
        printf("Playlist Empty.\n");
        return;
    }

    struct Song *temp=head;

    printf("\nPlaylist (Forward)\n");

    do
    {
        printf("%d | %s | %s\n",temp->id,temp->name,temp->artist);
        temp=temp->next;
    }
    while(temp!=head);
}

void displayBackward()
{
    if(head==NULL)
    {
        printf("Playlist Empty.\n");
        return;
    }

    struct Song *temp=head->prev;

    printf("\nPlaylist (Backward)\n");

    do
    {
        printf("%d | %s | %s\n",temp->id,temp->name,temp->artist);
        temp=temp->prev;
    }
    while(temp!=head->prev);
}

void nextSong()
{
    if(current==NULL)
    {
        printf("Playlist Empty.\n");
        return;
    }

    current=current->next;

    printf("Current Song:\n");
    printf("%d | %s | %s\n",current->id,current->name,current->artist);
}

void previousSong()
{
    if(current==NULL)
    {
        printf("Playlist Empty.\n");
        return;
    }

    current=current->prev;

    printf("Current Song:\n");
    printf("%d | %s | %s\n",current->id,current->name,current->artist);
}

void totalSongs()
{
    if(head==NULL)
    {
        printf("Total Songs = 0\n");
        return;
    }

    int count=0;

    struct Song *temp=head;

    do
    {
        count++;
        temp=temp->next;
    }
    while(temp!=head);

    printf("Total Songs = %d\n",count);
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== MUSIC PLAYLIST MENU =====\n");
        printf("1. Add Song at Beginning\n");
        printf("2. Add Song at End\n");
        printf("3. Delete Song\n");
        printf("4. Search Song\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Next Song\n");
        printf("8. Previous Song\n");
        printf("9. Total Songs\n");
        printf("10. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: addBeginning(); break;
            case 2: addEnd(); break;
            case 3: deleteSong(); break;
            case 4: searchSong(); break;
            case 5: displayForward(); break;
            case 6: displayBackward(); break;
            case 7: nextSong(); break;
            case 8: previousSong(); break;
            case 9: totalSongs(); break;
            case 10: exit(0);
            default: printf("Invalid Choice\n");
        }
    }

    return 0;
}