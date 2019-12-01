#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    //For Example only //To be used for demo in DS Class
    //struct Graph* graph = createGraph(7);
    //addEdge(graph, 0, 1);
    //addEdge(graph, 1, 3);
    //addEdge(graph, 1, 5);
    //printGraph(graph);
    clrscr();
    
    printf("KMAP & Co. Presents Routing Table Organizer\n\n");

    printf("Enter max number of router:");
    int V; //Max number of Vertices 
    scanf(" %d",&V);
    if(V==0)
    {
        printf("No Graph Created! Exit Successful!"); 
        exit(0);
    }

    //instructions
    printf("Routers are marked from 0 to %d\n",V-1);
    printf("Root Node starts at 0 - Single Connected Component Only!");

    //Memory allocation
    struct Graph* graph = createGraph(V);

    char ch='\0'; //Choice
    printf("\n");

    int root=0; //Stores last known root 

    while(ch!='8') //Menu Driven Program
    {
        printf("\nAvailable Options:\n");
        printf("1.Add Edge\n2.Delete Edge\n3.Find Quick Path from Root Node 0\n4.Print Routing Table Graph\n5.Add Device to Router\n6.Print Devices\n7.Search Device\n8.Exit\n");
        printf("$>");
        scanf(" %c",&ch);

        int s,d; //Source, Destination Edges
        int y; //Stores Router Node Vertex
        char ip[15]; //Stores Device IP Address
        switch(ch) 
        {
            case '1':
                clrscr();
                welcome(V);
                printf("/Add Edge/\n");
                printf("Enter Nodes seperated by a space:");
                scanf("%d %d",&s,&d);
                if(s<V && d<V)
                {

                    if(s==d)
                    {
                        printf("Self referential edges not allowed!");
                    }
                    else
                    {
                        root = addEdge(graph, s, d);
                    }
                }
                else
                {
                    printf("Node out of bound!");
                }
                
            break;
            case '2':
                clrscr();
                welcome(V);
                printf("/Delete Edge/\n");
                printf("Enter Nodes seperated by a space:");
                scanf("%d %d",&s,&d);
                if(s<V && d<V)
                    {

                        if(s==d)
                        {
                            printf("Self referential edges do not exist!");
                        }
                        else
                        {
                            delEdge(graph, s, d);
                            if(s==root || d==root) 
                            {   
                                root=0;
                            }
                        }
                    }
                    else
                    {
                        printf("Node out of bound!");
                    }
            break;
            case '3':
                clrscr();
                welcome(V);
                printf("/Shortest Path from Root Node 0/\n");
                genMat_path(graph,V);
            break;
            case '4':
                clrscr();
                welcome(V);
                printf("/Router Topology/");
                printGraph(graph);
                printf("\n\n/Routing Table/");
                printDevices(graph);
            break;
            case '5':
                clrscr();
                welcome(V);
                printf("/Add Device/\n");
                printf("Enter Router Node:");
                scanf("%d",&y);
                if(y>=V)
                {
                    printf("Invalid Node!");
                    break;
                }
                details(graph->adjLists[y]);
            break;
            case '6':
                clrscr();
                welcome(V);
                printf("/Print Devices/\n");
                printf("Enter Router Node:");
                scanf("%d",&y);
                if(y>=V)
                {
                    printf("Invalid Node!");
                    break;
                }
                printDetails(graph->adjLists[y]);
            break;
            case '7':
                clrscr();
                welcome(V);
                printf("/Search Device/\n");
                printf("Enter IP Address of Device:");
                scanf("%s",&ip);
                DFS(graph,root,ip); //Search for Device in each node
                resetDFS(graph,root); //To reset visited flags on each node
            break;
            case '8':
                clrscr();
                printf("Exit successful!");
            break;
            default:
                clrscr();
                welcome(V);
                printf("Invalid Option!");
            break;
        
        }

    } 

    return 0;
}