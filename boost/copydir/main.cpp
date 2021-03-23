#include <iostream>
#include <boost/filesystem.hpp>
#include <string>
#include <fstream>
#include <stdlib.h>


//using bfs = boost::filesystem;

void recursive_copy(const boost::filesystem::path &src, const boost::filesystem::path &dst)
{
  if (boost::filesystem::exists(dst)){
    throw std::runtime_error(dst.generic_string() + " exists - remove the directory");
  }

  if (boost::filesystem::is_directory(src)) {
    boost::filesystem::create_directories(dst);
    for (boost::filesystem::directory_entry& item : boost::filesystem::directory_iterator(src)) {
      recursive_copy(item.path(), dst/item.path().filename());
    }
  } 
  else if (boost::filesystem::is_regular_file(src)) {
    boost::filesystem::copy(src, dst);
  } 
  else {
    throw std::runtime_error(dst.generic_string() + " not dir or file");
  }
}


int main() {

	recursive_copy( boost::filesystem::path{"/tmp/abc"}, boost::filesystem::path{"/tmp/efg"} );
}

