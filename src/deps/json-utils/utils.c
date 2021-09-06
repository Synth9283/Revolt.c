#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <curl/curl.h>

#include "utils.h"

int getBufferSize(const char* format, va_list args) {
    char buffer[1] = {0};

    return vsnprintf(buffer, 1, format, args) + 1;
}

int countArrayMembers(char* array[]) {
    int index = 0;
    int total = 0;

    while(array[index] != NULL) {
        total++;    
        index++;
    }

    return total;
}


int countTotalSize(char* array[]) {
    int index;
    int length = 0;

    for(index = 0; array[index] != NULL; index++) {
        length += strlen(array[index]); 
    }

    return length;
}

char* mprintf(const char* format, ...) {
    va_list bufferArgs;
    va_list printArgs;
    int bufferSize = 0;
    char* buffer = NULL;

    va_start(bufferArgs, format);
    va_start(printArgs, format);
    bufferSize = getBufferSize(format, bufferArgs);
    buffer = calloc(bufferSize, sizeof(char));

    vsnprintf(buffer, bufferSize, format, printArgs);

    return buffer;
}

int countListLength(char* array[]) {
    int index;
    int length = 3; /* 2 for the [] and 1 for the NULL byte*/

    for(index = 0; array[index] != NULL; index++) {
        /* Adding 2 for the quotes */
        length += strlen(array[index]) + 2;

        /* Whether to add a comma or not to the length */
        if(array[index + 1] == NULL) {
            continue;
        }

        length++;
    }

    return length;
}

char* createJSONList(char* array[]) {
    int index;
    char* buffer = NULL;
    int lengthOfList = 0;

    lengthOfList = countListLength(array);
    buffer = calloc(lengthOfList, sizeof(char));

    strcat(buffer, "[");

    /* Initialize the list */
    for(index = 0; array[index] != NULL; index++) {
        strcat(buffer, "\"");
        strcat(buffer, array[index]);
        strcat(buffer, "\"");

        /* Whether to add a comma or not */
        if(array[index + 1] == NULL) {
            continue;
        }

        strcat(buffer, ",");
    }

    strcat(buffer, "]");

    return buffer;
}

size_t writeResponse(char* ptr, size_t size, size_t nmemb, void* userdata) {
    struct SizedBuffer* buffer = userdata;

    buffer->length += nmemb;

    if(buffer->string == NULL) {
        buffer->string = calloc(nmemb + 1, sizeof(char));
    } else {
        buffer->string = realloc(buffer->string, buffer->length);
    }

    strncat(buffer->string, ptr, nmemb);

    return 0;
}

struct SizedBuffer postRequest(const char* url, const char* json, const int count, ...) {
    int index;
    va_list headers;
    struct curl_slist* chunk;
    struct SizedBuffer buffer;
    CURL* curl;
    
    curl = curl_easy_init();
    chunk = NULL;
    buffer.length = 0;
    buffer.string = NULL;
    va_start(headers, count);

    /* Register headers into the cURL handler */
    for(index = 0; index < count; index++) {
        chunk = curl_slist_append(chunk, va_arg(headers, char*));
    }

    /* Register options */
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeResponse);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
    
    curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl_slist_free_all(chunk);

    return buffer;
}

struct SizedBuffer getRequest(const char* url, const char* json, const int count, ...) {
    int index = 0;
    va_list headers;
    CURL* curl = curl_easy_init();
    struct curl_slist* chunk = NULL;
    struct SizedBuffer buffer = {.string = NULL, .length = 0};

    va_start(headers, count);

    /* Register headers into the cURL handler */
    for(index = 0; index < count; index++) {
        chunk = curl_slist_append(chunk, va_arg(headers, char*));
    }

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeResponse);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(chunk);

    return buffer;
}
