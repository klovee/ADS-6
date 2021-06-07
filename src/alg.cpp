// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
BST<std::string> tree;
  char difFromAToa = 'a' - 'A';
  std::string wcount = "";
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error reading file" << std::endl;
    return tree;
  }
  while (!file.eof()) {
    char words = file.get();
    if ((words >= 'A' && words <= 'Z') || (words >= 'a' && words <= 'z')) {
      if (words >= 'A' && words <= 'Z')
        words += difFromAToa;
      wcount += words;
    } else if (wcount != "") {
      tree.add(wcount);
      wcount = "";
    }
  }
  file.close();
  return tree;
}
