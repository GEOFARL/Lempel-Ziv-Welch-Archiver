#pragma once

#include <string>
#include <filesystem>

class FileValidator
{
public:
  static const std::string validArchiveExt;
  static bool isValidInputFile(const std::string &);
  static bool isValidArchiveExtension(const std::string &);

private:
  static std::string getFileExtension(const std::string &);
};