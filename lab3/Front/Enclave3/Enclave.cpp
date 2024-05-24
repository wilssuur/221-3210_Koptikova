#include "Enclave3_t.h"

#include "sgx_trts.h"
#include "string.h"
//#include "memory.h"

const char* PersonalData[] = {
 "Diane Davis U99857184",
 "Caleb White 316363937",
 "Nicole Rogers 982688406",
 "Jonathan Young J15917635",
 "Richard Lopez 015975175",
 "Scott Stevens 704245295",
 "Rebecca Jackson 696123513",
 "Erin Marshall I61724538",
 "Jessica Franklin F48074190",
 "Katie Farley S20774514"
};


void getPD(char* outbuffer, size_t len, int i) {
    size_t array_size = sizeof(PersonalData) / sizeof(char*);
    if (i < 0 || i >= array_size) {
        memset(outbuffer, 0, len);
        return;
    }
    else {
        memcpy(outbuffer, PersonalData[i], len);
        return;
    }
}