#pragma once

#ifndef _TOOL_H_
#define _TOOL_H_


#include <string>
#include <cstdarg>
#include <vector>
#include <cstdio>
#include <stdexcept>
#include <cctype>
#include <cmath>

// 方面测试sql语句
// 辅助函数：转义SQL字符串并添加引号
std::string escapeSqlString(const char* str) {
    if (str == nullptr || *str == '\0') {
        return "''";  // 空字符串用SQL空字符串表示
    }

    std::string result = "'";
    for (; *str; ++str) {
        if (*str == '\'') {
            result += "''";  // 转义单引号
        }
        else {
            result += *str;
        }
    }
    result += '\'';
    return result;
}

std::string formatSql(const std::string& sql, const char* fmt, ...) {
    // 统计SQL中的问号数量
    int placeholderCount = 0;
    for (char c : sql) {
        if (c == '?') placeholderCount++;
    }

    // 准备可变参数列表
    va_list args;
    va_start(args, fmt);

    // 解析格式字符串并格式化参数
    std::vector<std::string> formattedArgs;
    const char* p = fmt;
    while (*p != '\0') {
        if (*p == '%') {
            p++;
            switch (*p) {
            case 's': {
                const char* str_arg = va_arg(args, const char*);
                formattedArgs.push_back(escapeSqlString(str_arg));
                break;
            }
            case 'i': {
                int int_arg = va_arg(args, int);
                formattedArgs.push_back(std::to_string(int_arg));
                break;
            }
            case 'f': {
                double double_arg = va_arg(args, double);
                // 处理浮点数：NaN和无穷大视为0
                if (std::isnan(double_arg) || std::isinf(double_arg)) {
                    formattedArgs.push_back("0");
                }
                else {
                    char buffer[32];
                    snprintf(buffer, sizeof(buffer), "%.2f", double_arg);
                    formattedArgs.push_back(buffer);
                }
                break;
            }
            case '%': {
                // 处理转义的%%
                p++;
                continue;
            }
            default:
                throw std::runtime_error("Unsupported format specifier");
            }
            p++;
        }
        else {
            p++;
        }
    }

    va_end(args);

    // 检查参数数量是否匹配
    if (formattedArgs.size() != placeholderCount) {
        throw std::runtime_error("Number of parameters does not match placeholders");
    }

    // 替换SQL中的占位符
    std::string result;
    size_t lastPos = 0;
    int argIndex = 0;

    for (size_t pos = 0; (pos = sql.find('?', pos)) != std::string::npos; pos++) {
        result.append(sql, lastPos, pos - lastPos);
        result.append(formattedArgs[argIndex++]);
        lastPos = pos + 1;
    }
    result.append(sql.substr(lastPos));

    return result;
}


#endif // !_TOOL_H_
