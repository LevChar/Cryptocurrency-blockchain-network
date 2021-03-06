/* ======================================================== */
/*   definitions.h		        						    */
/* ======================================================== */
#ifndef DEFENITIONS_H
#define DEFENITIONS_H

//---------------------------------------------------------------------------
//----------------------------- Includes ------------------------------------
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------------
//----------------------------- General Defines -----------------------------
//---------------------------------------------------------------------------
#define PRIVATE
#define PUBLIC
#define NONE 0
#define MAX_LEN  255
#define BITCOIN_DB_FILENAME  "bitcoin_db.txt"
#define BITCOIN_DB_LOADER 	 "Requester.sh"

//---------------------------------------------------------------------------
//----------------------------- General Typedefs ----------------------------
//---------------------------------------------------------------------------
typedef enum { FALSE=0, TRUE=1 } EBoolType;
typedef enum { SUCCESS = 0, FAILURE = 1, PARSED = 2 } EExecutionStatus;
typedef void* pVoid;

//---------------------------------------------------------------------------
//----------------------------- Debugging -----------------------------------
//---------------------------------------------------------------------------

#endif // !DEFENITIONS_H