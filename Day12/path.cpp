#include "puzzle12.h"

void day12::Path::add_dot() {
    if (in_group()) {
    	curr_groups.push_back(curr_group_length);
        curr_group_length = 0;
    }
}

void day12::Path::add_hashtag() {
    if (in_group()) {
        ++curr_group_length;
    }
    else {
        ++curr_group_length;
    }
}

const bool day12::Path::fits_in(const std::vector<int> &expected_groups) {
    if (expected_groups.size() < curr_groups.size()) {
        return false;
    }

    for (int i=0; i<curr_groups.size(); ++i) {
        if (curr_groups[i] != expected_groups[i]){
            return false;
        }
    }

    return true;
}

const bool day12::Path::fits_accuratly(const std::vector<int> &expected_groups) {
    if(!fits_in(expected_groups)){
        return false;
    }

    return curr_groups.size() == expected_groups.size();
}

const bool day12::Path::would_fit_with_dot(const std::vector<int> &expected_groups) {
    if (in_group()) {
        // the dot would finnish a new group
        if (expected_groups.size() < curr_groups.size() + 1) {
            return false;
        }

        if (expected_groups[curr_groups.size()] != curr_group_length) {
            return false;
        }
    }

    return true;
}

const bool day12::Path::would_fit_with_hashtag(const std::vector<int> &expected_groups) {

    if (in_group()) {
        // would increment curr_group_length check if this fits with expected group
        if (expected_groups[curr_groups.size()] <= curr_group_length) {
            return false;
        }
    }
    else {
        // start new group; just check if we do not exceed expected numbers of groups
        if (curr_groups.size() >= expected_groups.size()) {
            return false;
        }
    }

    return true;fits_in(expected_groups);
}

const void day12::Path::print() {
    std::cout << "<";
    for (int &i: curr_groups) {
        std::cout << i;
    }
    std::cout << "> " << " Pending group length: " << curr_group_length;

    std::cout << std::endl;
}
