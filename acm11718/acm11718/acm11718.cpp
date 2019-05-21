//
//  main.cpp
//  acm11718
//
//  Created by Shabre on 2018. 10. 9..
//  Copyright © 2018년 Shabre. All rights reserved.
//

#include <iostream>
#include <cstring>
int main(int argc, const char * argv[]) {
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::cout << line << std::endl;
        if(line.size() == 0)
           break;
    }
    return 0;
}
