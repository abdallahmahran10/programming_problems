#ifndef EXPRESSIONEVALUATOR_H
#define EXPRESSIONEVALUATOR_H


#include "Common.h"

#define DIGIT(c) ((c) - '0')

class ExpressionEvaluator
{
public:
    ExpressionEvaluator(void);

    double eval(const string &expStr);
    vector<double> eval(const vector<string> &expStr);
private:
    bool isNumber(char ch);
    double getNumber(const string &expStr, int *idx);
    int weight(char op);
    bool isOperator(char ch);
    int hasHigherPrecedence(char op1, char op2);
    double eval(double operand1, double operand2, char op);
    void ecvalLastExp(stack<double> &numbers, stack<char> &ops);
};


#endif // EXPRESSIONEVALUATOR_H
