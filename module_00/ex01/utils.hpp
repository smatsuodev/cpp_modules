#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

std::string ask_question(const std::string &question, std::string &ans);
void close_dialog_with_ok();
void close_dialog_with_error(const std::string &message);

#endif
