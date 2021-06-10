//
//  STLWordProcessor.hpp
//  assignment6
//
//  Created by rick gessner on 11/12/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#ifndef ProcessController_hpp
#define ProcessController_hpp

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>

namespace ECE17 {
  
  class ProcessController {
  public:
    // OCF
    ProcessController();
    ProcessController(const ProcessController &aCopy);
    ~ProcessController();
    ProcessController& operator=(const ProcessController &aCopy);

    // Methods
    void showStatistics(std::string &anInput, std::ostream &anOutput);      // runs calculations and shows results

    void calcWordUsage(std::list<std::string> &word_col,                    // count # times each word is found
                       std::list<int> &count_col,                           // case-sensitive, ignore punctuation
                       std::string &anInput);                               // stl containers to store information
                                                                            // returns lists (words, word counts)
                                                                            // list words no space or punctuation

    void calcWordPairs(std::list<std::string> &word_pairs_col,              // scan word pairs in document
                       std::list<int> &count_col,                           // count pairs repeated more than once
                       std::string &anInput);                               // case-sensitive, keep punctuation

    bool compress(std::string &anInput, std::ostream &anOutput);            // dictionary compression
                                                                            // sends compressed input to output stream
    bool decompress(std::string &anInput, std::ostream &anOutput);
    
  protected:
    void showWordUsage(std::string &anInput, std::ostream &anOutput);
    void showWordPairs(std::string &anInput, std::ostream &anOutput);

    void printTable(std::string col1_label, std::string col2_label,
                    std::list<std::string> &col1, std::list<int> &col2,
                    std::ostream &anOutput);

    // Data Members
    std::map<std::string, int> map1;  // compression map
    std::map<int, std::string> map2;  // decompression map

  };
}


#endif /* ProcessController */
