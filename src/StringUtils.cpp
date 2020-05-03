#include "StringUtils.h" 	  			 	 
#include <algorithm> 
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>

namespace StringUtils{
    
std::string Slice(const std::string &str, ssize_t start, ssize_t end){
    
    std::string ReturnString = str;
    try{
        if ((start > 0) && (start > ReturnString.length())){
            throw start;
        }
    }
    catch (ssize_t start){
        return "";
    }
    
    if (end > 0){
        return ReturnString.substr(start, end);
    }
    
    if (end == 0){
        return ReturnString.substr(start);
    }
    
    else if (end < 0) {
        if (start >= 0){
            ReturnString = ReturnString.substr(start);
            return ReturnString.erase(ReturnString.length() - abs(end));
        }
        if (start < 0){
            ReturnString = ReturnString.substr(ReturnString.length() - abs(start));
            return ReturnString.erase(ReturnString.length() - abs(end));
        }
        
    }
    return 0;
    
}

std::string Capitalize(const std::string &str){
    // Capitalizes only first letter of sentence --> Hello world
    std::string ReturnString;
    
    for (auto Ch : str){
        ReturnString += tolower(Ch); // turn whole string into lowercase
    }
    ReturnString[0] = toupper(ReturnString[0]); // turn only first character into uppercase
    return ReturnString;
}

std::string Title(const std::string &str){
    // Capitalizes first letter of each word --> Hello World
    
    std::string ReturnString;
    for (auto Ch : str){
        ReturnString += tolower(Ch);
    }
    
    // if string has character in it that is not a letter, then the next character should be capitalized
    
    ReturnString[0] = toupper(ReturnString[0]);
    for (size_t index = 0; index < ReturnString.length(); index++){
        if (!isalpha(ReturnString[index])){
            ReturnString[index + 1] = toupper(ReturnString[index+1]);
        }
    }
    return ReturnString;
}

std::string LStrip(const std::string &str){
    std::string ReturnString = str;
    
    size_t start = ReturnString.find_first_not_of(' ');
    return  ReturnString.substr(start);
    
    /*
    find_first_not_of -> The return type is the position of the first character that does not match any of the character specified in its arguments.  So, ReturnString is searched for the first instance of anything that is not a blank space. So start refers to the start of the word Test.
    
    substr -> returns a newly constructed string with its value initialized to a copy of a substring. ReturnString.substr(start) returns the rest of the string after the blank spaces.
    
    https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
    */
}

std::string RStrip(const std::string &str){
    // Remove spaces to the right of string
    
    std::string ReturnString = str;
    size_t end = ReturnString.find_last_not_of(' ');
    return  ReturnString.substr(0, end+1);
    
    /*
     find_last_not_of -> Searches the string for the last character that does not match any of the characters specified in its arguments.
    
    in "    Test   " the variable end refers to t because it is the last character that doesn't match with ' '
    https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
    */
}

std::string Strip(const std::string &str){
    
    std::string ReturnString = str;
    return RStrip(LStrip(ReturnString));
    
    // https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
}

std::string Center(const std::string &str, int width, char fill){
    std::string ReturnString = str;
    float Width = width;
    
    // 16 spaces in total. length of string is 11. 16-11 = 5. 2 spaces on left and 3 spaces on right
    float Space = (Width - ReturnString.length()) /2 ;
    
    ReturnString.insert(0, Space, fill);
    return ReturnString.append(ceil(Space), fill);
}

std::string LJust(const std::string &str, int width, char fill){
    // number of empty spaces to right of string = newLength - oldLength
    
    std::string ReturnString = str;
    int Width = width;
    
    int SpaceLength = Width - ReturnString.length();
    return ReturnString.append(SpaceLength, fill);
}

std::string RJust(const std::string &str, int width, char fill){
    std::string ReturnString = str;
    int Width = width;
    
    int SpaceLength = Width - ReturnString.length();
    return ReturnString.insert(0, SpaceLength, fill);
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep){
    // Pass in string, what to replace, and what to replace it with
    std::string ReturnString = str;
    std::string FindString = old;
    std::string Replacement = rep;
    
    // need to find FindString within ReturnString
    
    size_t foundPos = ReturnString.find(FindString);
    
    // foundPos is the position FindString was found at
    // npos means "until the end of the string"
    // replace(position to start at, length of what to replace, replacement)
    
    while (foundPos != std::string::npos){ // loop continues until the last time FindString is found within ReturnString
        
        ReturnString.replace(foundPos, FindString.size(), Replacement);
        foundPos = ReturnString.find(FindString, foundPos + Replacement.size());
        
        // need to update the position of foundPos. When position is specified, the search only includes characters at or after the position. position = foundPos + Replacement.size()
    }
    return ReturnString;
    
    // https://thispointer.com/find-and-replace-all-occurrences-of-a-sub-string-in-c/
}

std::vector< std::string > Split(const std::string &str, const std::string &splt){
    // Split sentence into individual words and put each word into vector
    std:: string ReturnString = str;
    std:: string delimiters("\t, \n, ' ', /");
    std::vector<std::string> v;
    boost::split(v, str, boost::is_any_of(delimiters));
    
    return v;
    
    // https://stackoverflow.com/questions/7621727/split-a-string-into-words-by-multiple-delimiters
    
}

std::string Join(const std::string &str, const std::vector< std::string > &vect){
    // Recombine words to form sentence again
    std::string joinedString = boost::algorithm::join(vect, str);
    return joinedString;
    
    // for every component of the vector, if the string is empty then you add the delimeter to the string.
    
    // https://stackoverflow.com/questions/5689003/how-to-implode-a-vector-of-strings-into-a-string-the-elegant-way/6334153
}

std::string ExpandTabs(const std::string &str, int tabsize){
    //after every \t there should
    std::string result = "";
    int pos = 0;
    std:: string ReturnString = str;
    for(char c: ReturnString)
    {
        if(c == '\t')
        {
            if (tabsize == 0){
                ReturnString.erase(std::remove(ReturnString.begin(), ReturnString.end(), '\t'), ReturnString.end());
                return ReturnString;
            }
            // append the spaces here.
            result.append(tabsize - pos % tabsize, ' ');
            pos = 0;
        } else
        {
            result += c;
            pos = (c == '\n') ? 0: pos + 1;
        }
    }
    
    return result;
    
    // https://stackoverflow.com/questions/58295089/c-equivalent-of-pythons-expandtabs-function/58295435#58295435
}

    int EditDistance(const std::string &left, const std::string &right, bool ignorecase)
    {
        // variables for length of each string
        const size_t m(left.size());
        const size_t n(right.size());
        
        // if first string is empty, then distance is just length of second string
        if( m==0 ) return n;
        if( n==0 ) return m;
        
        std::string returnLeft;
        std:: string returnRight;
        
        if (ignorecase == true){
            for (auto Ch : left){
                returnLeft += tolower(Ch);
            }
            for (auto Ch : right){
                returnRight += tolower(Ch);
            }
            size_t *costs = new size_t[n + 1];
            
            // fills first row of matrix
            for( size_t k=0; k<=n; k++ ) {
                costs[k] = k;
            }
            
            size_t i = 0;
            // iterate through left string
            for ( std::string::const_iterator it1 = returnLeft.begin(); it1 != returnLeft.end(); ++it1, ++i )
            {
                costs[0] = i+1; // if strings are not the same then cost starts at 1 and goes up with every difference between strings
                size_t corner = i; // starts at 0
                
                // the first element of cost is 1.
                size_t j = 0;
                // iterate through right string
                for ( std::string::const_iterator it2 = returnRight.begin(); it2 != returnRight.end(); ++it2, ++j )
                {
                    size_t upper = costs[j+1]; //  value of 2nd element is copied to upper.
                    if( *it1 == *it2 ){
                        costs[j+1] = corner; // if characters are the same then value of corner is stored in costs. first iteration: 0 becomes 2nd element
                    }
                    else{
                        size_t t(upper<corner ? upper : corner); // condition ? result1 : result2 If condition is true, the entire expression evaluates to result1, and otherwise to result2.
                        costs[j+1] = (costs[j]<t?costs[j]:t)+1;
                    }
                    
                    corner = upper;
                }
            }
            
            size_t result = costs[n];
            delete [] costs;
            
            return result;
        }
        // dynamically allocating array of size of right string
        
        else{
            
            size_t *costs = new size_t[n + 1];
            
            // fills first row of matrix
            for( size_t k=0; k<=n; k++ ) {
                costs[k] = k;
            }
            
            size_t i = 0;
            // iterate through left string
            for ( std::string::const_iterator it1 = left.begin(); it1 != left.end(); ++it1, ++i )
            {
                costs[0] = i+1; // if strings are not the same then cost starts at 1 and goes up with every difference between strings
                size_t corner = i; // starts at 0
                
                // the first element of cost is 1.
                size_t j = 0;
                // iterate through right string
                for ( std::string::const_iterator it2 = right.begin(); it2 != right.end(); ++it2, ++j )
                {
                    size_t upper = costs[j+1]; //  value of 2nd element is copied to upper.
                    if( *it1 == *it2 ){
                        costs[j+1] = corner; // if characters are the same then value of corner is stored in costs. first iteration: 0 becomes 2nd element
                    }
                    else{
                        size_t t(upper<corner ? upper : corner); // condition ? result1 : result2 If condition is true, the entire expression evaluates to result1, and otherwise to result2.
                        costs[j+1] = (costs[j]<t?costs[j]:t)+1;
                    }
                    
                    corner = upper;
                }
            }
            
            size_t result = costs[n];
            delete [] costs;
            
            return result;
        }
        
    }
    
    // https://rosettacode.org/wiki/Levenshtein_distance#C.2B.2B
}
