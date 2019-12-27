/* ======================================================== */
/*   block_finder.c		        							*/
/* ======================================================== */

//---------------------------------------------------------------------------
//----------------------------- Includes ------------------------------------
//---------------------------------------------------------------------------
#include "../include/block_finder.h"

//---------------------------------------------------------------------------
//---------------------- Private Methods Prototypes -------------------------
//---------------------------------------------------------------------------
void 
findBlockProgram(const char* search_param, const char* search_arg);

bitcoin_block_data*
findBlockData(Singly_Linked_List* blockList, const char* parameter);

//---------------------------------------------------------------------------
//-----------------------Private Methods Implementations---------------------
//---------------------------------------------------------------------------
PRIVATE
void 
findBlockProgram(const char* search_param, const char* search_arg)
{
    Singly_Linked_List* blockList = load_bitcoin_db("bitcoin_db.txt");
	
    if (strcmp(search_param, "--hash") == 0 || strcmp(search_param, "--height") == 0)
	{
        bitcoin_block_data* blockToPrint = findBlockData(blockList, search_arg);
        if (blockToPrint != NULL)
		{
            print_bitcoin_block_data(blockToPrint);
        }
    }
    else
	{
        printf("Invalid parameter: %s\n", search_param);
    }
	
    destroy_List(blockList);
}

PRIVATE
bitcoin_block_data* 
findBlockData(Singly_Linked_List* blockList, const char* parameter)
{
	char found = 0;
    Singly_Linked_Node* currNode = blockList->head;
    bitcoin_block_data* currBlock = NULL;

    while(currNode!=NULL && !found)
	{
        currBlock = (bitcoin_block_data*)currNode->data;
        if(strcmp(currBlock->hash_value, parameter) == 0 || strcmp(currBlock->height, parameter) == 0)
		{
            found = 1;
            break;
        }
		
        currNode = currNode->next;
        currBlock = NULL;
    }

    return currBlock;
}

//---------------------------------------------------------------------------
//---------------------- Public Methods Implementations----------------------
//---------------------------------------------------------------------------
PUBLIC
int 
main(int argc, char *argv[]) 
{
    if (argc < 3)
	{
        printf("Invlaid input: must enter ./printblock --<field> <value> \n");
        exit(1);
    }
	
    findBlockProgram(argv[1], argv[2]);
}
