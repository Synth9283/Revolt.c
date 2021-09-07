#ifndef REVOLT_API_H
#define REVOLT_API_H

#include <stdio.h>
#include "types.h"

/*
 * Acknowledges a message from a channel
 *
 * @param client: the Revolt client
 * @param channel: the Revolt channel
 * @param message: the Revolt message
 * @return: HTTP status code
*/
int revoltAcknowledgeMessage(struct RevoltClient* client, const char* channel, const char* message);

/*
 * Deletes a message
 *
 * @param client: the Revolt client
 * @param message: the Revolt message to delete
 * @return: HTTP stauts code
*/
int revoltDeleteMessage(struct RevoltClient* client, struct RevoltMessage* message);

/*
 * Edits a message
 *
 * @param client: the Revolt client
 * @param message: the message to edit
 * @param content: the new content to change into
 * @return: HTTP status code
*/
int revoltEditMessage(struct RevoltClient* client, struct RevoltMessage* message, const char* content);

/*
 * Fetches a message
 *
 * @param client: the Revolt client
 * @param params: the parameters to fetch the message
 * @return: HTTP status code
*/
int revoltFetchMessage(struct RevoltClient* client, struct RevoltFetchMessageParams* params);

/*
 * Fetches messages from a channel
 *
 * @param client: the Revolt client
 * @param channel: the targetted channel
 * @param params: the parameters for fetching messages
 * @return: HTTP status code
*/
int revoltFetchMessages(struct RevoltClient* client, struct RevoltMessage* message, const char* target, struct RevoltFetchMessagesParams* params);

/*
 * Polls message changes from a channel
 *
 * @param client: the Revolt client
 * @param messageChange: the buffer to write the message changes into
 * @param ids: the ids of messages to poll
 * @param channel: the channel to poll the message from
 * @return: HTTP status code
*/
int revoltPollMessageChanges(struct RevoltClient* client, struct RevoltMessageChange *messageChange, const char** ids, const char* channel);

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
 * Changes the username of a revolt user
 *
 * @param client: the Revolt Client
 * @param username: the new username to change into
 * @param password: the current password to authenticate action
 * @return: HTTP status code
*/ 
int revoltChangeUsername(struct RevoltClient* client, const char* username, const char* password);

/*
 * Edits the current user status of a Revolt user
 * 
 * @param client: the Revolt client
 * @param status: the new Revolt status to change into
 * @return: HTTP status code
*/
int revoltEditUserStatus(struct RevoltClient* client, struct RevoltUserStatus* status);

/*
 * Edits the current user profile of a Revolt user
 *
 * @param client: the Revolt client
 * @param profile: the new Revolt profile to change into
 * @return: HTTP status code
*/
int revoltEditUserProfile(struct revoltclient* client, struct revoltuserprofile* profile);

/*
 * Edits the current user avatar of a Revolt user
 *
 * @param client: the Revolt client
 * @param avatar: the new avatar to change into
 * @return: HTTP status code
*/
int revoltEditUserAvatar(struct RevoltClient* client, const char* avatar);

/*
 * Removes and object of a Revolt user
 * 
 * @param client: the Revolt client
 * @param object: The object to remove (STATUS, PROFILE, AVATAR)
 * @return: HTTP status code
*/
int revoltEditUserRemove(struct RevoltClient* client, enum RevoltUserEditObject object);

/*
 * Retrieves the default avatar of the user requested, and writes the
 * bytes to a stream.
 *
 * @param client: the Revolt client
 * @param target: the id of the user to get the default avatar of
 * @param buffer: the stream to write to
 * @return: HTTP status code
*/
int revoltFetchDefaultUserAvatar(struct RevoltClient* client, const char* target, FILE* buffer);

/*
 * Retrieves lists of mutual servers and friends that the authenticated
 * user has with another user of a given id, and writes it to a buffer.
 *
 * @param client: the Revolt client
 * @param target: the id of the user to get mutuals with
 * @param buffer: the buffer to write mutual friends and servers to
 * @return: HTTP status code
*/
int revoltFetchUserMutalFriends(struct RevoltClient* client, const char* target, struct RevoltMutuals* buffer);

/*
 * Retrieves information about a user with the provided id, and
 * writes it to a buffer.
 *
 * @param client: the Revolt client
 * @param target: the id of the user to use
 * @param buffer: the buffer to write the user information to
 * @return: HTTP status code
*/
int revoltFetchUserInfo(struct RevoltClient* client, const char* target, struct RevoltUserInfo* buffer);

/*
 * Retrieves information about a user's profile with the provided
 * id, and writes it to a buffer.
 *
 * @param client: the Revolt client
 * @param target: the id of the user to use
 * @param buffer: the buffer to write the user profile information to
 * @return: HTTP status code
*/
int revoltFetchUserProfile(struct RevoltClient* client, const char* target, struct RevoltUserProfile* buffer);

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
