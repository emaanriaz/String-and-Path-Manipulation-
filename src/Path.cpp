#include "Path.h" 	  			 	 
#include <cstdlib>
#include <unistd.h>
#include <vector>
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
#include "StringUtils.h"


struct CPath::SImplementation{
    std:: string DPath;
};

CPath::CPath() : DImplementation(std::make_unique< SImplementation >()){}

CPath::CPath(const CPath &path) : DImplementation(std::make_unique< SImplementation >()){
    // copy constructor
    DImplementation->DPath = path.DImplementation->DPath;
    //string Data
    // Data = val.Data
}

CPath::CPath(const std::string &path): DImplementation(std::make_unique< SImplementation >()) {
    // creates a path variable from a string
    DImplementation->DPath = path;
}

CPath::~CPath(){}

CPath &CPath::operator=(const CPath &path){
    if (this != &path){
        DImplementation->DPath = path.DImplementation->DPath;
    }
    return *this;

}

CPath CPath::operator+(const CPath &path) const{
    CPath p;
    if (path.DImplementation->DPath[0] != '/'){
        path.DImplementation->DPath.insert(0, "/");
        p.DImplementation->DPath = DImplementation->DPath + path.DImplementation->DPath;
    }
    else{
        p.DImplementation->DPath = DImplementation->DPath + path.DImplementation->DPath;
    }
    return p;
    
    // /./
    // //
    //
}

bool CPath::operator==(const CPath &path) const{
    CPath p;
    return p.DImplementation->DPath == path.DImplementation->DPath;
}

bool CPath::operator!=(const CPath &path) const{
    CPath p;
    return !(p.DImplementation->DPath == path.DImplementation->DPath);
}

CPath CPath::Directory() const{
    // returns path object
    size_t pos = DImplementation->DPath.find_last_of("/");
    return DImplementation->DPath.substr(0, pos);
}


std::string CPath::BaseName() const{
    // returns the basename component(the "filename") of the path
    // find the last slash and return the substring
    
    size_t pos = DImplementation->DPath.find_last_of("/");
    return DImplementation->DPath.substr(pos+1);
}

std::string CPath::Extension() const{
    // returns the extension of the basename, or empty string if one does not exist
    if (DImplementation->DPath.find(".") != std::string::npos){
        size_t pos = DImplementation->DPath.find_last_of(".");
        return DImplementation->DPath.substr(pos);
    }
    else{
        return "";
    }
}

bool CPath::IsAbsolute() const{
    // Your code goes here
    if (DImplementation->DPath.length() == 0){
        return false;
    }
    return DImplementation->DPath[0] == '/';
    
}

std::string CPath::ToString() const{
    // Your code goes here
    return "";
}

CPath::operator std::string() const{
    return DImplementation ->DPath;
}

CPath CPath::AbsolutePath() const{
    // returns absolute path. absolute path starts with a forward slash /a/b/c
    CPath p;
    p.DImplementation->DPath.insert(0, "/");
    return p;
    
}

CPath CPath::CommonPath(const CPath &path) const{
    // Your code goes here
    return CPath();
}

CPath CPath::NormalizePath() const{
    // removes unnecessary .. in path
    size_t pos = DImplementation->DPath.find_last_of(".");
    size_t end = DImplementation->DPath.substr(pos).length();
    DImplementation->DPath.substr(pos-1);
    DImplementation->DPath.erase(std::remove(DImplementation->DPath.begin(), DImplementation->DPath.end()-end, '.'), DImplementation->DPath.end()-end);
    
    return DImplementation->DPath;
}

CPath CPath::RelativePathTo(const CPath &path) const{
    // Your code goes here
    return CPath();
}

// Helper function provided to get the current working directory
std::string CPath::GetCWD(){
    std::vector< char > CurrentPathName;

    CurrentPathName.resize(1024);
    while(NULL == getcwd(CurrentPathName.data(), CurrentPathName.size())){
        CurrentPathName.resize(CurrentPathName.size() * 2);
    }
    return CurrentPathName.data();
}

// Helper funciton provided to get the home directory
std::string CPath::GetHome(){
    return std::getenv("HOME");
}

CPath CPath::AbsolutePath(const CPath &path){
    // Your code goes here
    return CPath();
}

CPath CPath::CurrentPath(){
    return CPath();
}

CPath CPath::CommonPath(const CPath &path1, const CPath &path2){
    // Your code goes here
    return CPath();
}

CPath CPath::ExpandUserPath(const CPath &path){
    // Your code goes here
    return CPath();
}

CPath CPath::HomePath(){
    // Your code goes here
    return CPath();
}

CPath CPath::NormalizePath(const CPath &path){
    return CPath();}

CPath CPath::RelativePath(const CPath &path, const CPath &startpath){
    // Your code goes here
    return CPath();
}
