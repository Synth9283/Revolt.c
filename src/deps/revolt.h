#ifndef REVOLT_API_H
#define REVOLT_API_H

#include <stdio.h>
#include "types.h"
#include "cee-utils/ntl.h"

/*
 * Changes a Revolt user email
 *
 * @param client: The Revolt client
 * @param data: The email change data
 * @return: HTTP status code
*/
int revoltChangeEmail(struct RevoltClient* client, struct RevoltChangeEmailData* data);

/*
 * Changes a Revolt user password
 *
 * @param client: The Revolt client
 * @param data: The password change data
 * @return: HTTP status code
*/
int revoltChangePassword(struct RevoltClient* client, struct RevoltChangePasswordData* data);

/*
 * Checks if a Revolt user is authenticated
 *
 * @param client: The Revolt client
 * @return: HTTP status code
*/
int revoltCheckAuth(struct RevoltClient* client);

/*
 * Creates a Revolt account
 *
 * @param data: The data to create the account with
 * @param userId: The user ID of the newly created user
 * @return: HTTP status code
*/
int revoltCreateAccount(struct RevoltCreateData* data, const char* userId);

/*
 * Deletes a existing Revolt session
 *
 * @param client: The Revolt client
 * @param session: The session to delete
 * @return: HTTP status code
*/
int revoltDeleteSession(struct RevoltClient* client, const char* session);

/*
 * Fetches info from a Revolt account
 *
 * @param client: The Revolt client
 * @param accountInfo: The buffer to write the account info retrieved into
 * @return: HTTP status code
*/
int revoltFetchAccount(struct RevoltClient* client, struct RevoltAccountInfo* accountInfo);

/*
 * Fetches all Revolt sessions
 *
 * @param client: The Revolt client
 * @param sessions: The buffer to write the sessions into
 * @return: HTTP status code
*/
int revoltFetchSessions(struct RevoltClient* client, struct RevoltSession** sessions);

/*
 * Logins to a Revolt account
 *
 * @param data: The login data
 * @param session: The login session recieved after logging in
 * @return: HTTP status code
*/
int revoltLogin(struct RevoltLoginData* data, struct RevoltLoginSession* session);

/*
 * Deletes current Revolt session
 *
 * @param client: The Revolt client
 * @return: HTTP status code
*/
int revoltLogout(struct RevoltClient* client);

/*
 * Confirms a password reset for a Revolt account
 *
 * @param data: The account password reset confirmation data required for confirming a password reset
 * @return: HTTP status code
*/
int revoltPasswordReset(struct RevoltConfirmPasswordResetData* data);

/*
 * Resends Revolt account creation verification email
 *
 * @param data: The account data to resend the verification email to
 * @return: HTTP status code
*/
int revoltResendVerification(struct RevoltCreateData* data);

/*
 * Requests for a Revolt account password reset email
 *
 * @param data: The account password reset data required for sending the email
 * @return: HTTP status code
*/
int revoltSendPasswordReset(struct RevoltPasswordResetData* data);

/*
 * Acknowledges a message from a channel
 *
 * @param client: The Revolt client
 * @param channel: The Revolt channel
 * @param message: The Revolt message
 * @return: HTTP status code
*/
int revoltAcknowledgeMessage(struct RevoltClient* client, const char* channel, const char* message);

/*
 * Deletes a message
 *
 * @param client: The Revolt client
 * @param message: The Revolt message to delete
 * @return: HTTP stauts code
*/
int revoltDeleteMessage(struct RevoltClient* client, struct RevoltMessage* message);

/*
 * Edits a message
 *
 * @param client: The Revolt client
 * @param message: The message to edit
 * @param content: The new content to change into
 * @return: HTTP status code
*/
int revoltEditMessage(struct RevoltClient* client, struct RevoltMessage* message, const char* content);

/*
 * Fetches a message
 *
 * @param client: The Revolt client
 * @param params: The parameters to fetch the message
 * @return: HTTP status code
*/
int revoltFetchMessage(struct RevoltClient* client, struct RevoltFetchMessageParams* params);

/*
 * Fetches messages from a channel
 *
 * @param client: The Revolt client
 * @param channel: The targetted channel
 * @param params: The parameters for fetching messages
 * @return: HTTP status code
*/
int revoltFetchMessages(struct RevoltClient* client, struct RevoltMessage* message, const char* target, struct RevoltFetchMessagesParams* params);

/*
 * Polls message changes from a channel
 *
 * @param client: The Revolt client
 * @param messageChange: The buffer to write the message changes into
 * @param ids: The ids of messages to poll
 * @param channel: The channel to poll the message from
 * @return: HTTP status code
*/
int revoltPollMessageChanges(struct RevoltClient* client, struct RevoltMessageChange *messageChange, const char** ids, const char* channel);

/*
 * Sends a message to the private message, channel, or group with
 * the corresponding id.
 *
 * @param client: The Revolt client
 * @param message: The message to send
 * @param channel: ID of the location to send the message to
 * @return: HTTP status code
*/
int revoltSendMessage(struct RevoltClient* client, const char* message, const char* channel);

/*
 * Changes the username of a revolt user
 *
 * @param client: The Revolt Client
 * @param username: The new username to change into
 * @param password: The current password to authenticate action
 * @return: HTTP status code
*/ 
int revoltChangeUsername(struct RevoltClient* client, const char* username, const char* password);

/*
 * Edits the current user status of a Revolt user
 * 
 * @param client: The Revolt client
 * @param status: The new Revolt status to change into
 * @return: HTTP status code
*/
int revoltEditUserStatus(struct RevoltClient* client, struct RevoltUserStatus* status);

/*
 * Edits the current user profile of a Revolt user
 *
 * @param client: The Revolt client
 * @param profile: The new Revolt profile to change into
 * @return: HTTP status code
*/
int revoltEditUserProfile(struct RevoltClient* client, struct RevoltUserProfile* profile);

/*
 * Edits the current user avatar of a Revolt user
 *
 * @param client: The Revolt client
 * @param avatar: The new avatar to change into
 * @return: HTTP status code
*/
int revoltEditUserAvatar(struct RevoltClient* client, const char* avatar);

/*
 * Removes and object of a Revolt user
 * 
 * @param client: The Revolt client
 * @param object: The object to remove (STATUS, PROFILE, AVATAR)
 * @return: HTTP status code
*/
int revoltEditUserRemove(struct RevoltClient* client, enum RevoltUserEditObject object);

/*
 * Retrieves the default avatar of the user requested, and writes the
 * bytes to a stream.
 *
 * @param client: The Revolt client
 * @param fp: The stream to write to
 * @param user: The ID of the user to get the default avatar of
 * @return: HTTP status code
*/
int revoltFetchDefaultUserAvatar(struct RevoltClient* client, FILE* fp, const char* user);

/*
 * Retrieves lists of mutual servers and friends that the authenticated
 * user has with another user of a given id, and writes it to a buffer.
 *
 * @param client: The Revolt client
 * @param users: The buffer to write mutual friends and servers to
 * @param user: The ID of the user to get mutuals with
 * @return: HTTP status code
*/
int revoltFetchMutualFriends(struct RevoltClient* client, struct RevoltUsers* users, const char* user);

/*
 * Retrieves information about a user with the provided id, and
 * writes it to a buffer.
 *
 * @param client: The Revolt client
 * @param userInfo: The buffer to write the user information to
 * @param user: The ID of the user to use
 * @return: HTTP status code
*/
int revoltFetchUserInfo(struct RevoltClient* client, struct RevoltUserInfo* userInfo, const char* user);

/*
 * Retrieves information about a user's profile with the provided
 * id, and writes it to a buffer.
 *
 * @param client: The Revolt client
 * @param userProfile: The buffer to write the user profile information to
 * @param user: The ID of the user to use
 * @return: HTTP status code
*/
int revoltFetchUserProfile(struct RevoltClient* client, struct RevoltUserProfile* userProfile, const char* user);

/*
 * Frees the structure containing user information.
 *
 * @param userInfo: The buffer to free
*/
void revoltFreeUserInfo(struct RevoltUserInfo* userInfo);

/*
 * Frees the structure containing user profile information.
 *
 * @param userProfile: The buffer to free
*/
void revoltFreeUserProfile(struct RevoltUserProfile* userProfile);

/*
 * Converts an attachment in JSON form into an attachment structure.
 *
 * @param json: the relation in JSON form
 * @param length: the length of the JSON
 * @param attachmentPtr: pointer to the structure to hold the data
*/
void attachmentFromJSON(char* json, size_t length, void* attachmentPtr);

/*
 * Converts a JSON list of attachments into a null-terminated list
 * of attachment structures.
 *
 * @param json: the list in JSON form
 * @param length: the length of the JSON
 * @param relations: the null-terminated list to put the attachments in
*/
void attachmentsFromJSON(char* json, size_t length, NTL_T(struct RevoltAttachment)* attachments);

/*
 * Converts a relation in JSON form into a relation structure.
 *
 * @param json: the relation in JSON form
 * @param length: the length of the JSON
 * @param relationPtr: pointer to the structure to hold the data
*/
void relationFromJSON(char* json, size_t length, void* relationPtr);

/*
 * Converts a JSON list of relations into a null-terminated list
 * of relation structures.
 *
 * @param json: the list in JSON form
 * @param length: the length of the JSON
 * @param relations: the null-terminated list to put the relations in
*/
void relationsFromJSON(char* json, size_t length, NTL_T(struct RevoltUserRelation)* relations);

/*
 * Converts a session in JSON form into a session structure
 *
 * @param json: The session in JSON form
 * @param length: The length of the JSON
 * @param sessionPtr: Pointer to the structure to hold the data
*/
void sessionFromJSON(char* json, size_t length, void* sessionPtr);

/*
 * Converts a JSON list of sessions into a null-terminated list of session structures
 *
 * @param json: The list in JSON form
 * @param length: The length of the JSON
 * @param sessions: The null-terminated list to put the sessions in
*/
void sessionsFromJSON(char* json, size_t length, NTL_T(struct RevoltSession)* sessions);

/*
 * Converts a JSON list of strings into a char**
 *
 * @param strArr: The buffer to write the data into. Do not allocate memory since the function does that for you
 * @param buffer: The null-terminated list to extract the strings from
*/
void stringsFromListJSON(char** strArr, NTL_T(struct sized_buffer) buffer);

/*
 * Converts a string in JSON form into a string structure.
 *
 * @param json: the relation in JSON form
 * @param length: the length of the JSON
 * @param stringPtr: pointer to the structure to hold the data
*/
void stringFromJSON(char* json, size_t length, void* stringPtr);

/*
 * Converts a JSON list of attachments into a null-terminated list
 * of string structures.
 *
 * @param json: the list in JSON form
 * @param length: the length of the JSON
 * @param strings: the null-terminated list to put the strings in
*/
void stringsFromJSON(char* json, size_t length, NTL_T(struct RevoltString)* strings);

#endif
