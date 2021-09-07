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
 * @param target: ID of the location to send the message to
 * @return: HTTP status code
*/
int revoltSendMessage(struct RevoltClient* client, const char* message, const char* target);

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
 * @param target: The ID of the user to get the default avatar of
 * @param buffer: The stream to write to
 * @return: HTTP status code
*/
int revoltFetchDefaultUserAvatar(struct RevoltClient* client, const char* target, FILE* buffer);

/*
 * Retrieves lists of mutual servers and friends that the authenticated
 * user has with another user of a given id, and writes it to a buffer.
 *
 * @param client: The Revolt client
 * @param user: The ID of the user to get mutuals with
 * @param users: The buffer to write mutual friends and servers to
 * @return: HTTP status code
*/
int revoltFetchMutualFriends(struct RevoltClient* client, const char* user, const char* users);

/*
 * Retrieves information about a user with the provided id, and
 * writes it to a buffer.
 *
 * @param client: The Revolt client
 * @param target: The ID of the user to use
 * @param buffer: The buffer to write the user information to
 * @return: HTTP status code
*/
int revoltFetchUserInfo(struct RevoltClient* client, const char* target, struct RevoltUserInfo* buffer);

/*
 * Retrieves information about a user's profile with the provided
 * id, and writes it to a buffer.
 *
 * @param client: The Revolt client
 * @param target: The ID of the user to use
 * @param buffer: The buffer to write the user profile information to
 * @return: HTTP status code
*/
int revoltFetchUserProfile(struct RevoltClient* client, const char* target, struct RevoltUserProfile* buffer);

/*
 * Frees the structure containing user information.
 *
 * @param buffer: The buffer to free
*/
void revoltFreeUserInfo(struct RevoltUserInfo* buffer);

/*
 * Frees the structure containing user profile information.
 *
 * @param buffer: The buffer to free
*/
void revoltFreeUserProfile(struct RevoltUserProfile* buffer);

void attachmentFromJSON(char* json, size_t length, void* attachmentPtr);

void attachmentsFromJSON(char* json, size_t length, NTL_T(struct RevoltAttachment)* attachments);

void relationFromJSON(char* json, size_t length, void* relationPtr);

#endif
