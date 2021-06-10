//
//  STLWordProcessor.cpp
//  assignment6
//
//  Created by rick gessner on 11/12/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#include "ProcessController.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <iterator>

namespace ECE17 {

    std::string columnPad(std::string str, int column_width) {
      if(str.length() < column_width) str = str + std::string(column_width - str.length(), ' ');
      return str;
    }

    bool isPunct(char aChar) {
      static std::string punct(".;?!:,'-()");
      return std::string::npos != punct.find(aChar);
    }

    void removePunct(std::string &str) {
      std::string str_orig = str;
      str.clear();

      for(char c: str_orig) {
        if(!isPunct(c)) str.push_back(c);
      }
    }

    // OCF
    ProcessController::ProcessController() = default;

    ProcessController::ProcessController(const ProcessController &aCopy) {}

    ProcessController::~ProcessController() = default;

    ProcessController &ProcessController::operator=(const ProcessController &aCopy) {
      return *this;
    }

    // this drives the statistical functions
    void ProcessController::showStatistics(std::string &anInput, std::ostream &anOutput) {

      anOutput << "\nWord Counts: \n";
      showWordUsage(anInput, anOutput);
      anOutput << "\nWord Pairs: \n";
      showWordPairs(anInput, anOutput);
    }

    void ProcessController::showWordUsage(std::string &anInput, std::ostream &anOutput) {
      std::list<std::string> word_col;
      std::list<int> count_col;

      calcWordUsage(word_col, count_col, anInput);
      printTable("Word", "Count", word_col, count_col, anOutput);
    }

    void ProcessController::showWordPairs(std::string &anInput, std::ostream &anOutput) {
      std::list<std::string> word_pairs_col;
      std::list<int> count_col;

      calcWordPairs(word_pairs_col, count_col, anInput);
      printTable("Word Pairs", "Count", word_pairs_col, count_col, anOutput);
    }

    void ProcessController::printTable(std::string col1_label, std::string col2_label,
                                       std::list<std::string> &col1, std::list<int> &col2,
                                       std::ostream &anOutput) {
      std::cout << "| " << columnPad(col1_label, 30);
      std::cout << "| " << columnPad(col2_label, 10) << " |" << std::endl;
      std::cout << std::string(46, '-') << std::endl;

      std::list<std::string>::iterator col1_it = col1.begin();
      std::list<int>::iterator col2_it = col2.begin();

      while(col1_it != col1.end() && col2_it != col2.end()) {
        std::cout << "| "  << columnPad(*col1_it++, 30);
        std::cout << "| " << columnPad(std::to_string(*col2_it++), 10) << " |" << std::endl;
      }
    }

    void ProcessController::calcWordUsage(std::list<std::string> &word_col, std::list<int> &count_col,
                                          std::string &anInput) {
        word_col.clear();
        count_col.clear();

        std::string word;
        std::istringstream iss(anInput);
        int n, m;
        bool alreadyFound;

        while (iss >> word) {
            n=0;
            m=0;
            alreadyFound = false;

            // remove punctuation and whitespace
            removePunct(word);
            word.erase(remove_if(word.begin(), word.end(), isspace), word.end());

            // iterate words found list
            for (auto i = word_col.begin(); i != word_col.end(); ++i) {
                // word already found
                if (*i == word) {
                    alreadyFound = true;
                    for (auto j = count_col.begin(); j != count_col.end(); ++j) {
                        if (m==n) {
                            *j = *j + 1;
                            break;
                        }
                        m++;
                    }
                    break;
                }
                n++;
            }
            // else word not yet found
            if (!alreadyFound) {
                word_col.push_back(word);
                count_col.push_back(1);
            }
        }
    }

    void ProcessController::calcWordPairs(std::list<std::string> &word_pairs_col, std::list<int> &count_col,
                                          std::string &anInput) {
      word_pairs_col.clear();
      count_col.clear();

      std::vector<std::string> wordsPunct;
      std::string word, pair;
      std::istringstream iss(anInput);
      int n, m;
      bool alreadyFound;

      // store words with punctuation in vector
      while (iss >> word) {
          word.erase(remove_if(word.begin(), word.end(), isspace), word.end());
          wordsPunct.push_back(word);
      }

      for (int k = 0; k < wordsPunct.size()-1; ++k) {
          pair = wordsPunct[k] + " " + wordsPunct[k+1];
          n=0;
          m=0;
          alreadyFound = false;
          for (auto i = word_pairs_col.begin(); i != word_pairs_col.end(); ++i) {
              // pair already found
              if (*i == pair) {
                  alreadyFound = true;
                  for (auto j = count_col.begin(); j != count_col.end(); ++j) {
                      if (m == n) {
                          *j = *j + 1;
                          break;
                      }
                      m++;
                  }
                  break;
              }
              n++;
          }
          // else word not yet found
          if (!alreadyFound) {
              word_pairs_col.push_back(pair);
              count_col.push_back(1);
          }
        }
    }

    // output compressed version input to the anOutput stream
    bool ProcessController::compress(std::string &anInput, std::ostream &anOutput) {

        // create vector that contains each word from input
        std::istringstream iss(anInput);
        std::vector<std::string> v((std::istream_iterator<std::string>(iss)),
                                   std::istream_iterator<std::string>());

        // sort vector, find set of unique elements
        std::vector<std::string> v_temp = v;
        std::sort(v_temp.begin(), v_temp.end());

        // erase indeterminate elements
        auto last = std::unique(v_temp.begin(), v_temp.end());
        v_temp.erase(last, v_temp.end());

        // create map that maps unique words to unique integers
        int index = 0;
        for (auto const& i : v_temp) {
            map1[i] = index;
            index++;
        }

        // create vector for the encrypted message
        std::vector<int> cipher;
        for (auto const& i : v) {
            cipher.push_back(map1.find(i)->second);
        }

        // output compressed message
        for (auto i = cipher.begin(); i != cipher.end(); ++i) {
            anOutput << *i << " ";
        }
        return true;
    }

    // de-compress given string back to original form and write to anOutput...
    bool ProcessController::decompress(std::string &aBuffer, std::ostream &anOutput) {

        // read encrypted message and store each word in vector
        std::istringstream iss(aBuffer);
        std::vector<std::string> vv((std::istream_iterator<std::string>(iss)),
                                    std::istream_iterator<std::string>());

        // create reverse map that maps every unique id/integer to its unique word
        std::vector<std::string> decipher;

        for (auto const& i : map1) {
            map2[i.second] = i.first;
        }

        // create vector that holds decrypted message
        for (auto const& i : vv) {
            auto x = map2.find(stoi(i))->second;
            decipher.push_back(x);
        }

        // output decrypted message
        for (auto i = decipher.begin(); i != decipher.end(); ++i) {
            anOutput << *i << " ";
        }
        return true;
    }

}
