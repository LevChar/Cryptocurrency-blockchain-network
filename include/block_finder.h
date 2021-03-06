/* ======================================================== */
/*   block_finder.h				       					    */
/* ======================================================== */
#ifndef BLOCK_FINDER_H
#define BLOCK_FINDER_H

//---------------------------------------------------------------------------
//----------------------------- Includes ------------------------------------
//---------------------------------------------------------------------------
#include "bitcoin.h"

//---------------------------------------------------------------------------
//---------------------- Public Method Prototypes ---------------------------
//---------------------------------------------------------------------------
void
findBlockProgram(const char* arg1, const char* arg2);

bitcoin_block_data*
findBlockData(Singly_Linked_List* blockList, const char* parameter);

#endif // !BLOCK_FINDER_H