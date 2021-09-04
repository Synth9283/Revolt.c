#ifndef REVOLT_API_H
#define REVOLT_API_H

#include <stdio.h>
#include "types.h"

/*
 * Sends a message to the private message, channel, or group with
 * the corresponding id.
 *
 * @param client: the Revolt client
 * @param message: the message to send
 * @param target: id of the location to send the message to
 * @return: HTTP status code
*/
int revoltSendMessage(struct RevoltClient* client, const char* message, const char* target);

/*
 * Retrieves information about a user with the provided id, and
 * writes it to a buffer.
 *
 * @param client: the Revolt client
 * @param target: the id of the user to use
 * @param buffer: the buffer to write the user information to
 * @return: HTTP status code
*/
int revoltGetUserInfo(struct RevoltClient* client, const char* target, struct RevoltUserInfo* buffer);

/*
 * Retrieves information about a user's profile with the provided
 * id, and writes it to a buffer.
 *
 * @param client: the Revolt client
 * @param target: the id of the user to use
 * @param buffer: the buffer to write the user profile information to
 * @return: HTTP status code
*/
int revoltGetUserProfile(struct RevoltClient* client, const char* target, struct RevoltUserProfile* buffer);

/*
 * Retrieves the default avatar of the user requested, and writes the
 * bytes to a stream.
 *
 * @param client: the Revolt client
 * @param target: the id of the user to get the default avatar of
 * @param buffer: the stream to write to
 * @return: HTTP status code
*/
int revoltGetDefaultUserAvatar(struct RevoltClient* client, const char* target, FILE* buffer);

/*
 * Frees the structure containing user information.
 *
 * @param buffer: the buffer to free
*/
void revoltFreeUserInfo(struct RevoltUserInfo* buffer);

/*
 * Frees the structure containing user profile information.
 *
 * @param buffer: the buffer to free
*/
void revoltFreeUserProfile(struct RevoltUserProfile* buffer);

#endif
