#include <string>
#include <vector>


/// @brief Splits a string at a delimiter string and return the parts as vector.
/// @param input String that should be split.
/// @param delimiter Delimiter at which the string is split. 
/// @return Parts of the string
std::vector<std::string> split (const std::string &input, std::string const &delimiter);

/// @brief Get numbers from string delimited by spaces, e.g. "45 7 90 1".
/// @param numbers_string
/// @return Integer values of the numbers from the string.
///
///     Get numbers from string delimited by spaces, e.g. "45 7 90 1". For strings containing other characters the behaviour is undefined.
///
std::vector<int> get_numbers_from_string(std::string &numbers_string, std::string const &delimiter);
