#include "FileValidator.hpp"

const std::string FileValidator::validArchiveExt = ".lz78";

bool FileValidator::isValidInputFile(const std::string &filename)
{
  std::filesystem::path filePath(filename);
  return std::filesystem::exists(filePath);
}

bool FileValidator::isValidArchiveExtension(const std::string &filename)
{
  std::string extension = getFileExtension(filename);
  return (extension == FileValidator::validArchiveExt);
}

std::string FileValidator::getFileExtension(const std::string &filename)
{
  std::size_t dotPos = filename.find_last_of(".");
  if (dotPos != std::string::npos)
  {
    return filename.substr(dotPos);
  }
  return "";
}