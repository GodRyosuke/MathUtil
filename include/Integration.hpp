#pragma once

#include <vector>

namespace mtu {
void Integration (std::vector<double> input, 
    double a,   // a, b: 積分区間
    double b,  
    int n,      // 分割数
    std::vector<double>& output);
}