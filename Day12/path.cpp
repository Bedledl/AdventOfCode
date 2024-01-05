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

bool day12::Path::fits_in(const std::vector<int> &expected_groups) const {
    if (expected_groups.size() < curr_groups.size()) {
        return false;
    }

    for (size_t i=0; i<curr_groups.size(); ++i) {
        if (curr_groups[i] != expected_groups[i]){
            return false;
        }
    }

    return true;
}

bool day12::Path::fits_accuratly(const std::vector<int> &expected_groups) const {
    if(!fits_in(expected_groups)){
        return false;
    }

    return curr_groups.size() == expected_groups.size();
}

bool day12::Path::would_fit_with_dot(const std::vector<int> &expected_groups) const {
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

bool day12::Path::would_fit_with_hashtag(const std::vector<int> &expected_groups) const {

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

void day12::Path::print() const {
    std::cout << "<";
    for (const int &i: curr_groups) {
        std::cout << i;
    }
    std::cout << "> " << " Pending group length: " << curr_group_length;

    std::cout << std::endl;
}
