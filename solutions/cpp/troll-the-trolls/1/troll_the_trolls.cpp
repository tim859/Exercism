namespace hellmath {

// Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
    enum class AccountStatus {troll, guest, user, mod};

// Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
    enum class Action {read, write, remove};

// Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
    bool display_post(AccountStatus accountStatusPoster, AccountStatus accountStatusViewer) {
        if (accountStatusPoster == AccountStatus::troll)
            return accountStatusViewer == AccountStatus::troll;
        return true;
    }

// Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
    bool permission_check(Action action, AccountStatus accountStatus) {
        switch (action) {
            case Action::read:
                return true;
            case Action::write:
                return accountStatus != AccountStatus::guest;
            case Action::remove:
                return accountStatus == AccountStatus::mod;
        }
        // should never reach here
        return false;
    }

// Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
    bool valid_player_combination(AccountStatus accountStatus1, AccountStatus accountStatus2) {
        if (accountStatus1 == AccountStatus::guest || accountStatus2 == AccountStatus::guest)
            return false;
        if ((accountStatus1 == AccountStatus::troll && accountStatus2 != AccountStatus::troll) || 
            (accountStatus2 == AccountStatus::troll && accountStatus1 != AccountStatus::troll))
            return false;
        return true;
    }

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
    bool has_priority(AccountStatus accountStatus1, AccountStatus accountStatus2) {
        switch (accountStatus1)  {
            case AccountStatus::mod:
                return accountStatus2 != AccountStatus::mod;
            case AccountStatus::user:
                return accountStatus2 != AccountStatus::mod && accountStatus2 != AccountStatus::user;
            case AccountStatus::guest:
                return accountStatus2 != AccountStatus::mod && accountStatus2 != AccountStatus::user && accountStatus2 != AccountStatus::guest;
            case AccountStatus::troll:
                return false;
        }
        // should never reach here
        return false;
    }

}  // namespace hellmath