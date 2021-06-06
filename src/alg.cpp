// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
BST<std::string>Tree;
  char difFromAToa = 'a' - 'A';
  std::string word = "";
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error reading file" << std::endl;
    return Tree;
  }
  while (!file.eof()) {
    char words = file.get();
    if ((words >= 'A' && words <= 'Z') || (words >= 'a' && words <= 'z')) {
      if (words >= 'A' && words <= 'Z')
        words += difFromAToa;
      wcount += words;
    } else if (wcount != "") {
      Tree.add(wcount);
      wcount = "";
    }
  }
  file.close();
  return Tree;
}
