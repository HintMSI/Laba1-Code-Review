#ifndef LOGIC_EVAL_H
#define LOGIC_EVAL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitRecursive(const string& s, char delimiter);
bool HasValidFormat(const string& expr, const string& prefix);
bool EvaluateAnd(const vector<string>& expressions, size_t index);
bool EvaluateOr(const vector<string>& expressions, size_t index);
bool Evaluate(const string& expr);
void RunLogicalExpressionTask();

bool Evaluate(const std::string& expr);

#endif 