/* ======================================================== */
/*   printdb.c		        								*/
/* ======================================================== */

//---------------------------------------------------------------------------
//----------------------------- Includes ------------------------------------
//---------------------------------------------------------------------------
#include "../include/printdb.h"
#include "../include/bitcoin.h"

//---------------------------------------------------------------------------
//---------------------- Public Methods Implementations----------------------
//---------------------------------------------------------------------------
PUBLIC 
void 
print_bc_db(char* bc_db_f_name)
{
	Singly_Linked_List *bitcoin_db = load_bitcoin_db(BITCOIN_DB_FILENAME);
	
	if(!(bitcoin_db))
	{
		fprintf(stderr, "Error on attempt to build the parsed linked list, exiting!\n");
		exit(1);
	}
	
	Singly_Linked_Node *current = bitcoin_db->head;

	while (current != NULL) {
		
		print_bitcoin_block_data((bitcoin_block_data*)(current->data));
		current = current->next;
		
		if(current != NULL)
		{
			printf("\t\t\t |\n");
			printf("\t\t\t |\n");
			printf("\t\t\t |\n");
			printf("\t\t\t V\n");
		}
	}
	
	destroy_List(bitcoin_db);
}

int 
main(void)
{
	print_bc_db("bc_db.txt");
	return 0;
}