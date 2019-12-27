/* ======================================================== */
/*   bitcoin.h				       						    */
/* ======================================================== */
#ifndef BITCOIN_H
#define BITCOIN_H

//---------------------------------------------------------------------------
//----------------------------- Includes ------------------------------------
//---------------------------------------------------------------------------

#include "../include/file_handler.h"
#include "linked_list.h"

//----------------------------------	-----------------------------------------
//---------------------- Bitcoin Block Data Defines -------------------------
//---------------------------------------------------------------------------
typedef enum _BITCOIN_FIELDS 
{    
	HASH,
	HEIGHT,
	TOTAL,
	TIME,
	RECEIVED_TIME,
	RELAYED_BY,
	PREV_BLOCK,
} EBITCOIN_FIELDS;

#define TOTAL_AMOUNT_OF_FIELDS_TO_PARSE 7
#define BAD_FIELD_INPUT -1

typedef struct _field_type_struct
{ 
	char *key; 
	int val; 
} field_type_struct;

//---------------------------------------------------------------------------
//---------------------- Bitcoin Block Data Structure -----------------------
//---------------------------------------------------------------------------
typedef struct _bitcoin_block_data
{
    char *hash_value;
	char *height;
	char *total;
	char *time;
	char *received_time;
	char *relayed_by;
	char *prev_block;
	size_t amount_of_parsed_fields;
	size_t total_amount_of_fields;
} bitcoin_block_data;

//---------------------------------------------------------------------------
//---------------------- Public Method Prototypes ---------------------------
//---------------------------------------------------------------------------
Singly_Linked_List*
load_bitcoin_db(char* bc_db_f_name);

void
print_bitcoin_block_data(bitcoin_block_data* block_to_print);

void 
release_bitcoin_block_data(pVoid block_to_release);

#endif // !BITCOIN_H