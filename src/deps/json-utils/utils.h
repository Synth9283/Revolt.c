#ifndef JSON_UTILS_H_
#define JSON_UTILS_H_

#include <stdarg.h>
#include <stdlib.h>

/*
 * A buffer that can hold a string and its length. Used for
 * dynamically sized strings. Should be freed after use.
*/
struct SizedBuffer {
    size_t length;
    char* string;
};

/*
 * Gets how big of a buffer will be required to print a format string.
 *
 * @param format: the format string
 * @param ...: the format specifiers
*/
int getBufferSize(const char* format, va_list args);

/*
 * Count the members of a null-terminated array.
 *
 * @param array: the array to count
 * @return: the number of elements
*/
int countArrayMembers(char* array[]);

/*
 * Counts the total size of a string that could fit a string of each member
 * in a null-terminated array.
 *
 * @param array: the array to count
 * @return: the total size of a string
*/
int countTotalSize(char* array[]);

/*
 * Allocate a buffer large enough to hold the given string, including format specifiers,
 * and return it. The string must be freed manually afterwards.
 *
 * @param format: the format string
 * @param ...: the format specifiers
*/
char* mprintf(const char* format, ...);

/*
 * Calculate the length of an array when converted to a JSON list.
 *
 * @param array: the array to calculate
 * @return: the length of the list
*/
int countListLength(char* array[]);

/*
 * Creates a string that represents a JSON list from an array. The string must be
 * freed from memory afterwards.
 *
 * @param array: the array to convert
 * @return: the array in string-form
*/
char* createJSONList(char* array[]);

/*
 * Internal wrapper for HTTP requests to dynamically write response JSON to
 * a sizeed buffer.
 *
 * @param ptr: the string to write
 * @param size: the size of the string
 * @param nmemb: the length of the string
 * @param userdata: the buffer to write to
 * @return: nothing
 * 
*/
size_t writeResponse(char* ptr, size_t size, size_t nmemb, void* userdata);

/*
 * Wrapper around cURL to send POST requests to a certain URL, with specific
 * headers, returning the retrieved JSON in a sized buffer. The sized buffer
 * should have its string be freed.
 *
 * @param url: the url to send the request to
 * @param json: the json to send in the request
 * @param count: the number of header components
 * @return: a sized buffer that holds the JSON returned from the request
*/
struct SizedBuffer postRequest(const char* url, const char* json, const int count, ...);

/*
 * Wrapper around cURL to send GET requests to a certain URL, with specific
 * headers, returning the retrieved JSON in a sized buffer. The sized buffer
 * should have its string be freed.
 *
 * @param url: the url to send the request to
 * @param count: the number of header components
 * @return: a sized buffer that holds the JSON returned from the request
*/
struct SizedBuffer getRequest(const char* url, const int count, ...);

#endif
