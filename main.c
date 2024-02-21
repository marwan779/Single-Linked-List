#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

struct node_t
{
    uint32 node_data;
    struct node_t *node_link;
};

void Insert_Node_At_Beginning(struct node_t **list);
void Insert_Node_At_End(struct node_t **list);
void Insert_Node_After(struct node_t *list);
void Delete_Node_At_Beginning(struct node_t **list);
void Delete_Node(struct node_t *list);
void Display_All_Nodes(struct node_t *list);
void swap_2_nodes(struct node_t **list);
void Print_Middle_Of_The_List(struct node_t *list);
void Delete_The_Zero_Sum(struct node_t **list);
uint32 Get_Length(struct node_t *list);

struct node_t *ListHead = NULL;

int main()
{
    uint8 UserChoice = 0;
    uint32 ListLength = 0;

    printf("-> Hello to Single Linked List \n");
    while (1)
    {
        printf("\n");
        printf("===============================\n");
        printf("-> 1) Insert_Node_At_Beginning \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Delete_Node_At_Beginning \n");
        printf("-> 5) Delete_Node \n");
        printf("-> 6) Display_All_Nodes \n");
        printf("-> 7) Get_Length \n");
        printf("-> 8) Swap_Two_Nodes \n");
        printf("-> 9) Print_Middle_Of_The_List \n");
        printf("-> 10) Delete_The_Zero_Sum \n");
        printf("-> 11) Delete_Middle_Of_The_List \n");
        printf("-> 12) Delete_The_List \n");
        printf("-> 13) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);

        switch (UserChoice)
        {
        case 1:
            Insert_Node_At_Beginning(&ListHead);
            break;
        case 2:
            Insert_Node_At_End(&ListHead);
            break;
        case 3:
            Insert_Node_After(ListHead);
            break;
        case 4:
            Delete_Node_At_Beginning(&ListHead);
            break;
        case 5:
            Delete_Node(ListHead);
            break;
        case 6:
            Display_All_Nodes(ListHead);
            break;
        case 7:
            ListLength = Get_Length(ListHead);
            printf("List Length : << %i >> Nodes\n", ListLength);
            break;
        case 8:
            swap_2_nodes(&ListHead);
            break;
        case 9:
            Print_Middle_Of_The_List(ListHead);
            break;
        case 13:
            printf("Quit from application \n");
            exit(1);
            break;
        default:
            printf("User Choice out of range !!\n");
            break;
        }
    }
}

void Insert_Node_At_Beginning(struct node_t **list)
{
    struct node_t *temp_node = NULL;
    temp_node = (struct node_t *)malloc(sizeof(struct node_t));
    if (temp_node == NULL)
    {
        printf("error creating the node :)\n");
    }
    else
    {
        printf("enter node data : ");
        scanf("%i", &(temp_node->node_data));

        if (*list == NULL)
        {
            temp_node->node_link = NULL;
            *list = temp_node;
        }
        else
        {
            temp_node->node_link = *list;
            *list = temp_node;
        }
    }
}
void Insert_Node_At_End(struct node_t **List)
{
    struct node_t *TempNode = NULL;
    struct node_t *LastNode = NULL;

    TempNode = (struct node_t *)malloc(sizeof(struct node_t));
    if (NULL != TempNode)
    {
        printf("Enter Node Data : ");
        scanf("%i", &TempNode->node_data);
        TempNode->node_link = NULL;

        /* Check if linked list is empty */
        if (NULL == *List)
        { /* Linked list is empty */
            *List = TempNode;
        }
        else
        { /* Linked list is not empty */
            LastNode = *List;
            while (LastNode->node_link != NULL)
            {
                LastNode = LastNode->node_link;
            }
            LastNode->node_link = TempNode;
        }
    }
    else
    {
        /* Nothing */
    }
}

void Insert_Node_After(struct node_t *list)
{
    struct node_t *temp_node = NULL, *node_counter = NULL;
    uint32 node_position, list_length, count = 1;

    printf("enter node position : ");
    scanf("%i", &node_position);
    list_length = Get_Length(list);
    if (node_position > list_length)
    {
        printf("error the list consist of %i nodes only :)\n", list_length);
    }
    else
    {
        node_counter = list;
        while (count < node_position)
        {
            count++;
            node_counter = node_counter->node_link;
        }
        temp_node = (struct node_t *)malloc(sizeof(struct node_t));
        if (temp_node == NULL)
        {
            printf("error creating the node :)\n");
        }
        else
        {
            printf("enter node data : ");
            scanf("%i", &(temp_node->node_data));
            temp_node->node_link = node_counter->node_link;
            node_counter->node_link = temp_node;
        }
    }
}

void Delete_Node_At_Beginning(struct node_t **list)
{
    uint32 list_length;
    list_length = Get_Length(*list);
    if (list_length == 0)
    {
        printf("the list is empty , nothing to be deleted :)\n");
    }
    else
    {
        struct node_t *temp_node = *list;
        *list = temp_node->node_link;
        temp_node->node_link = NULL;
        free(temp_node);
    }
}

void Delete_Node(struct node_t *list)
{
    struct node_t *next_node = NULL, *node_counter = NULL;
    uint32 node_position, list_length, count = 1;

    printf("enter node position : ");
    scanf("%i", &node_position);
    list_length = Get_Length(list);
    if (node_position > list_length)
    {
        printf("error the list consist of %i nodes only :)\n", list_length);
    }
    else
    {
        node_counter = list;
        while (count < (node_position - 1))
        {
            count++;
            node_counter = node_counter->node_link;
        }

        next_node = node_counter->node_link;
        node_counter->node_link = next_node->node_link;
        free(next_node);
    }
}

void Display_All_Nodes(struct node_t *list)
{
    struct node_t *node_counter = list;
    if (node_counter == NULL)
    {
        printf("the list is empty , nothing to display :)\n");
    }
    else
    {
        while (node_counter != NULL)
        {
            printf(" -> %i", node_counter->node_data);
            node_counter = node_counter->node_link;
        }
    }
}

void swap_2_nodes(struct node_t **list)
{
    struct node_t *node_1 = *list, *node_1_prev = NULL;
    struct node_t *node_2 = *list, *node_2_prev = NULL;
    struct node_t *node_temp = NULL;
    uint32 list_lenght, node_1_position, node_2_position;
    printf("The List Before Swap : ");
    Display_All_Nodes(*list);
    printf("\nEnter Node One Position : ");
    scanf("%i", &node_1_position);
    printf("Enter Node Two Position : ");
    scanf("%i", &node_2_position);
    list_lenght = Get_Length(*list);
    if (node_1_position > list_lenght || node_2_position > list_lenght)
    {
        printf("Invalid Position :)\n");
    }
    else if (node_2_position <= node_1_position)
    {
        printf("blease make sure that  the first node position is smaller than the seconde node position\n");
    }
    else
    {
        for (uint32 i = 1; i < node_1_position; i++)
        {
            node_1_prev = node_1;
            node_1 = node_1->node_link;
        }

        for (uint32 j = 1; j < node_2_position; j++)
        {
            node_2_prev = node_2;
            node_2 = node_2->node_link;
        }
        if (node_1_position == 1 && node_1_position != (node_2_position - 1))
        {
            node_temp = node_2->node_link;
            node_2->node_link = node_1->node_link;
            node_1->node_link = node_temp;
            node_2_prev->node_link = node_1;
            *list = node_2;
        }
        else if (node_1_position == 1 && node_1_position == (node_2_position - 1))
        {
            node_temp = node_2->node_link;
            node_2->node_link = node_1;
            node_1->node_link = node_temp;
            *list = node_2;
        }
        else if (node_1_position == (node_2_position - 1))
        {
            node_temp = node_2->node_link;
            node_2->node_link = node_1;
            node_1->node_link = node_temp;
            node_1_prev->node_link = node_2;
        }
        else
        {
            node_temp = node_2->node_link;
            node_2->node_link = node_1->node_link;
            node_1->node_link = node_temp;
            node_1_prev->node_link = node_2;
            node_2_prev->node_link = node_1;
        }

        printf("The List After Swap : ");
        Display_All_Nodes(*list);
    }
}

void Print_Middle_Of_The_List(struct node_t *list)
{
    uint32 list_lenght, half;
    struct node_t *counter = list;

    list_lenght = Get_Length(list);
    half = list_lenght / 2;
    for (uint32 i = 1; i <= half; i++)
    {
        counter = counter->node_link;
    }
    printf("the node in the middle => %i\n", counter->node_data);
}

void Delete_The_Zero_Sum(struct node_t **list)
{
    uint32 list_lenght, data1, data2;
    struct node_t *counter1 = *list, *counter2 = *list ;

    for (uint32 i = 1; i < list_lenght; i++)
    {
        data1 = counter1->node_data;
        for (uint32 j = 1; j < list_lenght; j++)
        {
            counter2 = counter2->node_link;
            data2 = counter2->node_data;
            if ((data1 + data2) == 0)
            {
                
            }
        }
    }
}

uint32 Get_Length(struct node_t *list)
{
    struct node_t *node_counter = NULL;
    uint32 count = 0;
    node_counter = list;
    while (node_counter != NULL)
    {
        node_counter = node_counter->node_link;
        count++;
    }
    return count;
}
