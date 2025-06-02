class Solution {
public:
    string solveEquation(string equation) {
        int x_coeff = 0; 
        int const_sum = 0; 
        int sign = 1;  
        int side = 1;  
        int n = equation.length();
        for (int i = 0; i < n;) {
            if (equation[i] == '+') {
                sign = 1;
                i++;
            } else if (equation[i] == '-') {
                sign = -1;
                i++;
            } else if (equation[i] == '=') {
                side = -1;
                sign = 1;
                i++;
            } else {
                int num = 0;
                bool is_number = false;
                while (i < n && isdigit(equation[i])) {
                    num = num * 10 + (equation[i] - '0');
                    i++;
                    is_number = true;
                }

                if (i < n && equation[i] == 'x') {
                    if (!is_number) num = 1; 
                    x_coeff += side * sign * num;
                    i++;
                } else {
                    const_sum += side * sign * num;
                }
            }
        }

        if (x_coeff == 0) {
            if (const_sum == 0) return "Infinite solutions";
            else return "No solution";
        }

        int result = -const_sum / x_coeff;
        return "x=" + to_string(result);
    }
};
