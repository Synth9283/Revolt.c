# 1. Revolt.c
![Revolt.c logo](https://autumn.revolt.chat/icons/E-ASKEsG63ohhrzkEHzSzf8TQ7PzqJGLdPLBQK6EMw?max_side=64)

Revolt.c is the Revolt API library written in C for [Revolt.chat](https://revolt.chat)
Join our official [Server](https://app.revolt.chat/invite/Nw4ZWnxZ)!
View the official documentation of the [API](https://developers.revolt.chat/api/)

## 1.1. Table of contents
- [1. Revolt.c](#1--revolt.c)
  - [1.1. Table of contents](#11-table-of-contents)
  - [1.2. Compiling and install instructions](#12-compiling-and-install-instructions)
  - [1.3. Usage example](#13-usage-example)
  - [1.4. Latest major change](#14-latest-major-change)
  - [1.5. Latest minor change](#15-latest-minor-change)
  - [1.6. To-do](#16-to-do)

## 1.2. Compiling, install, and uninstall instructions
> Compiling
```bash
make -j$(nproc) # or number of threads
```
> Installing
```bash
make install # sudo might be required depending on permissions
```
> Uninstalling
```bash
make uninstall # sudo might be required depending on permissions
```

## 1.3. Usage example
```c
int main() {
    // Example will be available in the future
    return 0;
}
```

## 1.4. Latest major change
> Adapted rAuth v1

## 1.5. Latest minor change
> Re-organized library file structure

## 1.6. To-do
- [x] Chat platform
    - [x] [Core](https://developers.revolt.chat/api/#tag/Core)
        - [x] [Query Node](https://developers.revolt.chat/api/#tag/Core/paths/~1/get)
    - [x] [Onboarding](https://developers.revolt.chat/api/#tag/Onboarding)
        - [x] [Check Onboarding Status](https://developers.revolt.chat/api/#tag/Onboarding/paths/~1onboard~1hello/get)
        - [x] [Complete Onboarding](https://developers.revolt.chat/api/#tag/Onboarding/paths/~1onboard~1complete/post)
- [x] Auth
    - [x] [Account](https://developers.revolt.chat/api/#tag/Account)
        - [x] [Fetch Account](https://developers.revolt.chat/api/#tag/Account/paths/~1account/get)
        - [x] [Create Account](https://developers.revolt.chat/api/#tag/Account/paths/~1account~1create/post)
        - [x] [Resend Verification](https://developers.revolt.chat/api/#tag/Account/paths/~1account~1reverify/post)
        - [x] [Verify Email](https://developers.revolt.chat/api/#tag/Account/paths/~1account~1verify~1:code/post)
        - [x] [Send Password Reset](https://developers.revolt.chat/api/#tag/Account/paths/~1account~1reset_password/post)
        - [x] [Password Request](https://developers.revolt.chat/api/#tag/Account/paths/~1account~1reset_password/patch)
        - [x] [Change Password](https://developers.revolt.chat/api/#tag/Account/paths/~1account~1change~1password/post)
        - [x] [Change Email](https://developers.revolt.chat/api/#tag/Account/paths/~1account~1change~1email/post)
    - [x] [Session](https://developers.revolt.chat/api/#tag/Session)
        - [x] [Login](https://developers.revolt.chat/api/#tag/Session/paths/~1session~1login/post)
        - [x] [Logout](https://developers.revolt.chat/api/#tag/Session/paths/~1session~1logout/delete)
        - [x] [Edit Session](https://developers.revolt.chat/api/#tag/Session/paths/~1session~1:session/patch)
        - [x] [Delete Session](https://developers.revolt.chat/api/#tag/Session/paths/~1session~1:session/delete)
        - [x] [Fetch Sessions](https://developers.revolt.chat/api/#tag/Session/paths/~1session~1all/get)
        - [x] [Delete All Sessions](https://developers.revolt.chat/api/#tag/Session/paths/~1session~1all/delete)
- [ ] Users
    - [ ] [User Information](https://developers.revolt.chat/api/#tag/User-Information)
        - [ ] [Fetch User](https://developers.revolt.chat/api/#tag/User-Information/paths/~1users~1:user/get)
        - [ ] [Edit User](https://developers.revolt.chat/api/#tag/User-Information/paths/~1users~1@\me/patch)
        - [ ] [Change Username](https://developers.revolt.chat/api/#tag/User-Information/paths/~1users~1@\me~1username/patch)
        - [ ] [Fetch User Profile](https://developers.revolt.chat/api/#tag/User-Information/paths/~1users~1:user~1profile/get)
        - [ ] [Fetch Default Avatar](https://developers.revolt.chat/api/#tag/User-Information/paths/~1users~1:user~1default_avatar/get)
        - [ ] [Fetch Mutual Friends](https://developers.revolt.chat/api/#tag/User-Information/paths/~1users~1:user~1mutual/get)
    - [ ] [Direct Messaging](https://developers.revolt.chat/api/#tag/Direct-Messaging)
        - [ ] [Fetch Direct Message Channels](https://developers.revolt.chat/api/#tag/Direct-Messaging/paths/~1users~1dms/get)
        - [ ] [Open Direct Message](https://developers.revolt.chat/api/#tag/Direct-Messaging/paths/~1users~1:user~1dm/get)
    - [ ] [Relationships](https://developers.revolt.chat/api/#tag/Relationships)
        - [ ] [Fetch Relationships](https://developers.revolt.chat/api/#tag/Relationships/paths/~1users~1relationships/get)
        - [ ] [Fetch Relationship](https://developers.revolt.chat/api/#tag/Relationships/paths/~1users~1:user~1relationship/get)
        - [ ] [Send Friend Request / Accept Request](https://developers.revolt.chat/api/#tag/Relationships/paths/~1users~1:username~1friend/put)
        - [ ] [Deny Friend Request / Remove Friend](https://developers.revolt.chat/api/#tag/Relationships/paths/~1users~1:username~1friend/delete)
        - [ ] [Block User](https://developers.revolt.chat/api/#tag/Relationships/paths/~1users~1:user~1block/put)
        - [ ] [Unblock User](https://developers.revolt.chat/api/#tag/Relationships/paths/~1users~1:user~1block/delete)
- [ ] Channels
    - [ ] [Channel Information](https://developers.revolt.chat/api/#tag/Channel-Information)
        - [ ] [Fetch Channel](https://developers.revolt.chat/api/#tag/Channel-Information/paths/~1channels~1:channel/get)
        - [ ] [Edit Channel](https://developers.revolt.chat/api/#tag/Channel-Information/paths/~1channels~1:channel/patch)
        - [ ] [Close Channel](https://developers.revolt.chat/api/#tag/Channel-Information/paths/~1channels~1:channel/delete)
    - [ ] [Channel Invites](https://developers.revolt.chat/api/#tag/Channel-Invites)
        - [ ] [Create Invite](https://developers.revolt.chat/api/#tag/Channel-Invites/paths/~1channels~1:channel~1invites/post)
    - [ ] [Channel Permissions](https://developers.revolt.chat/api/#tag/Channel-Permissions)
        - [ ] [Set Role Permission](https://developers.revolt.chat/api/#tag/Channel-Permissions/paths/~1channels~1:channel~1permissions~1:role/put)
        - [ ] [Set Default Permission](https://developers.revolt.chat/api/#tag/Channel-Permissions/paths/~1channels~1:channel~1permissions~1default/put)
    - [ ] [Messaging](https://developers.revolt.chat/api/#tag/Messaging)
        - [ ] [Send Message](https://developers.revolt.chat/api/#tag/Messaging/paths/~1channels~1:channel~1messages/post)
        - [ ] [Fetch Messages](https://developers.revolt.chat/api/#tag/Messaging/paths/~1channels~1:channel~1messages/get)
        - [ ] [Fetch Message](https://developers.revolt.chat/api/#tag/Messaging/paths/~1channels~1:channel~1messages~1:message/get)
        - [ ] [Edit Message](https://developers.revolt.chat/api/#tag/Messaging/paths/~1channels~1:channel~1messages~1:message/patch)
        - [ ] [Delete Message](https://developers.revolt.chat/api/#tag/Messaging/paths/~1channels~1:channel~1messages~1:message/delete)
        - [ ] [Poll Message Changes](https://developers.revolt.chat/api/#tag/Messaging/paths/~1channels~1:channel~1messages~1stale/post)
        - [ ] [Search For Messages](https://developers.revolt.chat/api/#tag/Messaging/paths/~1channels~1:channel~1messages~1search/post)
        - [ ] [Acknowledge Message](https://developers.revolt.chat/api/#tag/Messaging/paths/~1channels~1:channel~1ack~1:message/put)
    - [ ] [Groups](https://developers.revolt.chat/api/#tag/Groups)
        - [ ] [Create Group](https://developers.revolt.chat/api/#tag/Groups/paths/~1channels~1create/post)
        - [ ] [Fetch Group Members](https://developers.revolt.chat/api/#tag/Groups/paths/~1channels~1:channel~1members/get)
        - [ ] [Add Group Member](https://developers.revolt.chat/api/#tag/Groups/paths/~1channels~1:channel~1members/put)
        - [ ] [Remove Group Member](https://developers.revolt.chat/api/#tag/Groups/paths/~1channels~1:channel~1members/delete)
    - [ ] [Voice](https://developers.revolt.chat/api/#tag/Voice)
        - [ ] [Join Call](https://developers.revolt.chat/api/#tag/Voice/paths/~1channels~1:channel~1join_call/post)
- [ ] Servers
    - [ ] [Server Information](https://developers.revolt.chat/api/#tag/Server-Information)
        - [ ] [Fetch Server](https://developers.revolt.chat/api/#tag/Server-Information/paths/~1servers~1:server/get)
        - [ ] [Edit Server](https://developers.revolt.chat/api/#tag/Server-Information/paths/~1servers~1:server/patch)
        - [ ] [Delete / Leave Server](https://developers.revolt.chat/api/#tag/Server-Information/paths/~1servers~1:server/delete)
        - [ ] [Create Server](https://developers.revolt.chat/api/#tag/Server-Information/paths/~1servers~1create/post)
        - [ ] [Create Channel](https://developers.revolt.chat/api/#tag/Server-Information/paths/~1servers~1:server~1channels/post)
        - [ ] [Fetch Invites](https://developers.revolt.chat/api/#tag/Server-Information/paths/~1servers~1:server~1invites/get)
        - [ ] [Mark Server As Read](https://developers.revolt.chat/api/#tag/Server-Information/paths/~1servers~1:server~1ack/put)
    - [ ] [Server Members](https://developers.revolt.chat/api/#tag/Server-Members)
        - [ ] [Fetch Member](https://developers.revolt.chat/api/#tag/Server-Members/paths/~1servers~1:server~1members~1:member/get)
        - [ ] [Edit Member](https://developers.revolt.chat/api/#tag/Server-Members/paths/~1servers~1:server~1members~1:member/patch)
        - [ ] [Kick Member](https://developers.revolt.chat/api/#tag/Server-Members/paths/~1servers~1:server~1members~1:member/delete)
        - [ ] [Fetch Members](https://developers.revolt.chat/api/#tag/Server-Members/paths/~1servers~1:server~1members/get)
        - [ ] [Ban User](https://developers.revolt.chat/api/#tag/Server-Members/paths/~1servers~1:server~1bans~1:member/put)
        - [ ] [Unban User](https://developers.revolt.chat/api/#tag/Server-Members/paths/~1servers~1:server~1bans~1:member/delete)
        - [ ] [Fetch Bans](https://developers.revolt.chat/api/#tag/Server-Members/paths/~1servers~1:server~1bans/get)
    - [ ] [Server Permissions](https://developers.revolt.chat/api/#tag/Server-Permissions)
        - [ ] [Set Role Permission](https://developers.revolt.chat/api/#tag/Server-Permissions/paths/~1servers~1:server~1permissions~1:role/put)
        - [ ] [Set Default Permission](https://developers.revolt.chat/api/#tag/Server-Permissions/paths/~1servers~1:server~1permissions~1default/put)
        - [ ] [Create Role](https://developers.revolt.chat/api/#tag/Server-Permissions/paths/~1servers~1:server~1roles/post)
        - [ ] [Edit Role](https://developers.revolt.chat/api/#tag/Server-Permissions/paths/~1servers~1:server~1roles~1:role/patch)
        - [ ] [Delete Role](https://developers.revolt.chat/api/#tag/Server-Permissions/paths/~1servers~1:server~1roles~1:role/delete)
- [x] Bots
    - [x] [Bots](https://developers.revolt.chat/api/#tag/Bots)
        - [x] [Create Bot](https://developers.revolt.chat/api/#tag/Bots/paths/~1bots~1create/post)
        - [x] [Fetch Owned Bots](https://developers.revolt.chat/api/#tag/Bots/paths/~1bots~1@me/get)
        - [x] [Fetch Bot](https://developers.revolt.chat/api/#tag/Bots/paths/~1bots~1:bot/get)
        - [x] [Edit Bot](https://developers.revolt.chat/api/#tag/Bots/paths/~1bots~1:bot/patch)
        - [x] [Delete Bot](https://developers.revolt.chat/api/#tag/Bots/paths/~1bots~1:bot/delete)
        - [x] [Fetch Public Bot](https://developers.revolt.chat/api/#tag/Bots/paths/~1bots~1:bot~1invite/get)
        - [x] [Invite Public Bot](https://developers.revolt.chat/api/#tag/Bots/paths/~1bots~1:bot~1invite/post)
- [ ] Miscellaneous
    - [ ] [Invites](https://developers.revolt.chat/api/#tag/Invites)
        - [ ] [Fetch Invite](https://developers.revolt.chat/api/#tag/Invites/paths/~1invites~1:invite/get)
        - [ ] [Join Invite](https://developers.revolt.chat/api/#tag/Invites/paths/~1invites~1:invite/post)
        - [ ] [Delete Invite](https://developers.revolt.chat/api/#tag/Invites/paths/~1invites~1:invite/delete)
    - [ ] [Sync](https://developers.revolt.chat/api/#tag/Sync)
        - [ ] [Fetch Settings](https://developers.revolt.chat/api/#tag/Sync/paths/~1sync~1settings~1fetch/post)
        - [ ] [Set Settings](https://developers.revolt.chat/api/#tag/Sync/paths/~1sync~1settings~1set/post)
        - [ ] [Fetch Unreads](https://developers.revolt.chat/api/#tag/Sync/paths/~1sync~1unreads/post)
	- [ ] [Web Push](https://developers.revolt.chat/api/#tag/Web-Push)
        - [ ] [Subscribe](https://developers.revolt.chat/api/#tag/Web-Push/paths/~1push~1subscribe/post)
        - [ ] [Unsubscribe](https://developers.revolt.chat/api/#tag/Web-Push/paths/~1push~1unsubscribe/post)
