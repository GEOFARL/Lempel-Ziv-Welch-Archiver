#include "FileValidator.hpp"

const std::string validArchiveExt = "lz78";

bool FileValidator::isValidInputFile(const std::string &filename)
{
  std::filesystem::path filePath(filename);
  return std::filesystem::exists(filePath);
}