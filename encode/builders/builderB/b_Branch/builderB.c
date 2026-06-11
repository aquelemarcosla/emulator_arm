#include "builderB.h"
#include "stdint.h"
#include "string.h"

uint32_t builderB(char **saveptr) {
    char *token = strtok_r(NULL, " ", saveptr);
    if (token == NULL) return 0;
}

uint32_t builderBL(char **saveptr) {
    char *token = strtok_r(NULL, " ", saveptr);
    if (token == NULL) return 0;
}

uint32_t builderRET(char **saveptr) {
    char *token = strtok_r(NULL, " ", saveptr);
    if (token == NULL) return 0;
}

uint32_t builderBEQ(char **saveptr) {
    char *token = strtok_r(NULL, " ", saveptr);
    if (token == NULL) return 0;
}

uint32_t builderBNE(char **saveptr) {
    char *token = strtok_r(NULL, " ", saveptr);
    if (token == NULL) return 0;
}