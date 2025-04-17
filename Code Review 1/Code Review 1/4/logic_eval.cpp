#include "logic_eval.h"

//FIXME было обновлена логика SplitRecursive ,тк она не работала с вложенными выражениями

//FIXME Исправлена табуляция для else в строках:17,25
vector<string> SplitRecursive(const string& s, char delimiter) {
	vector<string> result = {};
	string current="";
	int bracket_depth = 0;

	for (size_t i = 0; i < s.length(); ++i) {
		char ch = s[i];

		if (ch == '(') {
			bracket_depth++;
		}else if (ch == ')') {
			bracket_depth--;
		}

		if (ch == ',' && bracket_depth == 0) {
			result.push_back(current);
			current.clear();
		}else {
			current += ch;
		}
	}

	if (!current.empty()) {
		result.push_back(current);
	}

	return result;
}

bool HasValidFormat(const string& expr, const string& prefix) {
	return expr.substr(0, prefix.length()) == prefix && expr.back() == ')';
}

bool EvaluateAnd(const vector<string>& expressions, size_t index) {
	if (index >= expressions.size()) {
		return true;
	}

	if (!Evaluate(expressions[index])) {
		return false;
	}

	return EvaluateAnd(expressions, index + 1);
}

bool EvaluateOr(const vector<string>& expressions, size_t index) {
	if (index >= expressions.size()) {
		return false;
	}

	if (Evaluate(expressions[index])) {
		return true;
	}

	return EvaluateOr(expressions, index + 1);
}

bool Evaluate(const string& expr) {
	if (expr == "T") {
		return true;
	}
	if (expr == "F") {
		return false;
	}

	if (HasValidFormat(expr, "And(")) {
		string params = expr.substr(4, expr.size() - 5);  // Убираем "And(" и ")"
		vector<string> sub_expressions = SplitRecursive(params, ',');
		return EvaluateAnd(sub_expressions, 0);
	}

	if (HasValidFormat(expr, "Or(")) {
		string params = expr.substr(3, expr.size() - 4);  // Убираем "Or(" и ")"
		vector<string> sub_expressions = SplitRecursive(params, ',');
		return EvaluateOr(sub_expressions, 0);
	}

	cout << "Ошибка: недопустимое логическое выражение: " << expr << endl;
	return false;
}
//FIXME обновлено название,чтобы было понятнее
void RunLogicalExpressionTask() {
	string input = "";
	cin >> input;

	if (input.empty()) {
		cout << "Ошибка: введена пустая строка." << endl;
		return;
	}

	bool result = Evaluate(input);
	cout << (result ? "T" : "F") << endl;
}