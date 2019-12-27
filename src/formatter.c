#include "../include/formatter.h"

void appendToString(char* origString, const char* partToAppend);
char* convertListToCSV(Singly_Linked_List* blockList);
char* convertToCsvLine(bitcoin_block_data* bitcoinBlockData);
void dumpToFile(char* fileName, char* csvData);

void run_csv_program(){
    Singly_Linked_List* blockList = load_bitcoin_db(BITCOIN_DB_FILENAME);
    char* csvData = convertListToCSV(blockList);
    dumpToFile("a.csv", csvData);
    destroy_List(blockList);
}

char* convertListToCSV(Singly_Linked_List* blockList){
    Singly_Linked_Node* currBlockNode = blockList->head;
    char* newLine;
    const char* fieldsListCSV = "hash_value,height,total,time,received_time,relayed_by,prev_block\n";
    char* csvLines = (char*)malloc(strlen(fieldsListCSV) + 1);
    appendToString(csvLines,fieldsListCSV);

    while(currBlockNode != NULL){
        newLine = convertToCsvLine(currBlockNode->data);
        csvLines = (char*)realloc(csvLines, strlen(csvLines) + strlen(newLine));
        appendToString(csvLines, newLine);
        free(newLine);
        currBlockNode = currBlockNode->next;
    }

    return csvLines;
}

char* convertToCsvLine(bitcoin_block_data* bitcoinBlockData){
    int totalLineMallocSize = strlen(bitcoinBlockData->hash_value) +  strlen(bitcoinBlockData->height) + strlen(bitcoinBlockData->total) +
                                 strlen(bitcoinBlockData->time) + strlen(bitcoinBlockData->received_time) + strlen(bitcoinBlockData->relayed_by) + strlen(bitcoinBlockData->prev_block) + 8;
    char* csvLine = (char*)calloc(totalLineMallocSize, sizeof(char));
    appendToString(csvLine, bitcoinBlockData->hash_value);
    appendToString(csvLine, ",");
    appendToString(csvLine, bitcoinBlockData->height);
    appendToString(csvLine, ",");
    appendToString(csvLine, bitcoinBlockData->total);
    appendToString(csvLine, ",");
    appendToString(csvLine, bitcoinBlockData->time);
    appendToString(csvLine, ",");
    appendToString(csvLine, bitcoinBlockData->received_time);
    appendToString(csvLine, ",");
    appendToString(csvLine, bitcoinBlockData->relayed_by);
    appendToString(csvLine, ",");
    appendToString(csvLine, bitcoinBlockData->prev_block);
    appendToString(csvLine, "\r\n");
    return csvLine;
}

void appendToString(char* origString, const char* partToAppend){
    int partLen = strlen(partToAppend);
    int origStringLen = strlen(origString);
    for (int i = 0; i < partLen; ++i){
        origString[origStringLen + i] = partToAppend[i];
    }
}

void dumpToFile(char* fileName, char* csvData){
    FILE* newCsvFile = fopen(fileName, "w");
    fprintf(newCsvFile, "%s", csvData);
    free(csvData);
    fclose(newCsvFile);
}

int main(){
    run_csv_program();
}
