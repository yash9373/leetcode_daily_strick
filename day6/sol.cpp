#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class User {
private:
    std::string userId;
    std::string name;
    std::string email;
    std::unordered_set<std::string> followers;
    std::unordered_set<std::string> following;

public:
    User(const std::string& userId, const std::string& name, const std::string& email) 
        : userId(userId), name(name), email(email) {}

    const std::string& getUserId() const {
        return userId;
    }

    void follow(User& user) {
        if (this != &user && following.insert(user.getUserId()).second) {
            user.followers.insert(this->getUserId());
        }
    }

    void unfollow(User& user) {
        if (following.erase(user.getUserId())) {
            user.followers.erase(this->getUserId());
        }
    }

    std::vector<std::string> getFollowers() const {
        return std::vector<std::string>(followers.begin(), followers.end());
    }

    std::vector<std::string> getFollowing() const {
        return std::vector<std::string>(following.begin(), following.end());
    }
};

class SocialMediaManagementSystem {
private:
    std::unordered_map<std::string, User> users;

    User* findUser(const std::string& userId) {
        auto it = users.find(userId);
        return it != users.end() ? &it->second : nullptr;
    }

    void displayList(const std::vector<std::string>& list) const {
        for (const auto& id : list) {
            std::cout << id << " ";
        }
        std::cout << std::endl;
    }

public:
    void addUser(const std::string& userId, const std::string& name, const std::string& email) {
        if (users.find(userId) == users.end()) {
            users.emplace(userId, User(userId, name, email));
            std::cout << "User added successfully." << std::endl;
        } else {
            std::cout << "User ID already exists." << std::endl;
        }
    }

    void followUser(const std::string& userId, const std::string& followUserId) {
        User* user = findUser(userId);
        User* followUser = findUser(followUserId);

        if (user && followUser) {
            user->follow(*followUser);
            std::cout << userId << " is now following " << followUserId << std::endl;
        } else {
            std::cout << "Invalid user ID(s)." << std::endl;
        }
    }

    void unfollowUser(const std::string& userId, const std::string& unfollowUserId) {
        User* user = findUser(userId);
        User* unfollowUser = findUser(unfollowUserId);

        if (user && unfollowUser) {
            user->unfollow(*unfollowUser);
            std::cout << userId << " has unfollowed " << unfollowUserId << std::endl;
        } else {
            std::cout << "Invalid user ID(s)." << std::endl;
        }
    }

    void retrieveFollowersList(const std::string& userId) const {
        const User* user = findUser(userId);
        if (user) {
            std::cout << "Followers of " << userId << ": ";
            displayList(user->getFollowers());
        } else {
            std::cout << "Invalid user ID." << std::endl;
        }
    }

    void retrieveFollowingList(const std::string& userId) const {
        const User* user = findUser(userId);
        if (user) {
            std::cout << userId << " is following: ";
            displayList(user->getFollowing());
        } else {
            std::cout << "Invalid user ID." << std::endl;
        }
    }
};

int main() {
    SocialMediaManagementSystem system;
    int option;
    std::string userId, name, email, followUserId, unfollowUserId;

    while (true) {
        std::cout << "=====Social Media Management System ======" << std::endl;
        std::cout << "1. Add a user" << std::endl;
        std::cout << "2. Follow a user" << std::endl;
        std::cout << "3. Unfollow a user" << std::endl;
        std::cout << "4. Retrieve followers list" << std::endl;
        std::cout << "5. Retrieve following list" << std::endl;
        std::cout << "Enter option: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
            case 1:
                std::cout << "Enter user ID: ";
                std::getline(std::cin, userId);
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                std::cout << "Enter email: ";
                std::getline(std::cin, email);
                system.addUser(userId, name, email);
                break;
            case 2:
                std::cout << "Enter your user ID: ";
                std::getline(std::cin, userId);
                std::cout << "Enter user ID to follow: ";
                std::getline(std::cin, followUserId);
                system.followUser(userId, followUserId);
                break;
            case 3:
                std::cout << "Enter your user ID: ";
                std::getline(std::cin, userId);
                std::cout << "Enter user ID to unfollow: ";
                std::getline(std::cin, unfollowUserId);
                system.unfollowUser(userId, unfollowUserId);
                break;
            case 4:
                std::cout << "Enter user ID to retrieve followers: ";
                std::getline(std::cin, userId);
                system.retrieveFollowersList(userId);
                break;
            case 5:
                std::cout << "Enter user ID to retrieve following list: ";
                std::getline(std::cin, userId);
                system.retrieveFollowingList(userId);
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}
